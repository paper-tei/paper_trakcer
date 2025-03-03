//
// Created by Paper-tei on 2025/2/26.
//

#pragma once

#include "serial.hpp"
#include <regex>
#include <windows.h>
#include <setupapi.h>
#include <devguid.h>    // 包含 GUID_DEVCLASS_PORTS
#include <regstr.h>     // 包含注册表相关定义
#include <iostream>
#include <string>
#include <cstring>      // for strstr()
#include <vector>
#include <locale>
#include <codecvt>
#include <thread>
#define COM_PORT L"COM101"  // 指定要打开的串口号

// 修改SerialPortManager的构造函数
SerialPortManager::SerialPortManager()
    : hSerial(INVALID_HANDLE_VALUE), running(false) {
    m_status = SerialStatus::CLOSED;
    init();
}

void SerialPortManager::init()
{
    LOG_INFO("正在搜索ESP32-S3设备...");
    std::string portName = FindEsp32S3Port();

    if (portName.empty()) {
        LOG_WARN("无法找到ESP32-S3设备，尝试使用默认端口COM101");
        hSerial = initSerialPort(COM_PORT);
    } else {
        // portName = "COM5";
        currentPort = portName;
        // 转换为宽字符串
        std::wstring wPortName(L"\\\\.\\");
        wPortName += std::wstring(portName.begin(), portName.end());

        LOG_INFO("尝试连接到端口:" + QString(portName.c_str()));

        // 使用FILE_FLAG_OVERLAPPED打开串口以启用异步I/O
        hSerial = CreateFileW(
            wPortName.c_str(),
            GENERIC_READ | GENERIC_WRITE,
            0,
            NULL,
            OPEN_EXISTING,
            FILE_FLAG_OVERLAPPED,  // 关键修改：启用非阻塞I/O
            NULL
        );

        if (hSerial != INVALID_HANDLE_VALUE) {
            // 配置串口参数
            DCB dcbSerialParams = {0};
            dcbSerialParams.DCBlength = sizeof(dcbSerialParams);

            if (GetCommState(hSerial, &dcbSerialParams)) {
                dcbSerialParams.BaudRate = CBR_115200;
                dcbSerialParams.ByteSize = 8;
                dcbSerialParams.StopBits = ONESTOPBIT;
                dcbSerialParams.Parity   = NOPARITY;

                // 禁用所有流控制
                dcbSerialParams.fOutxCtsFlow = FALSE;
                dcbSerialParams.fRtsControl = RTS_CONTROL_DISABLE;
                dcbSerialParams.fDtrControl = DTR_CONTROL_DISABLE;
                dcbSerialParams.fOutX = FALSE;
                dcbSerialParams.fInX = FALSE;

                if (!SetCommState(hSerial, &dcbSerialParams)) {
                    LOG_ERROR("配置串口失败，错误码: " + GetLastError());
                    CloseHandle(hSerial);
                    hSerial = INVALID_HANDLE_VALUE;
                }
            } else {
                LOG_ERROR("获取串口状态失败，错误码: " + GetLastError());
                CloseHandle(hSerial);
                hSerial = INVALID_HANDLE_VALUE;
            }

            // 设置串口超时参数
            COMMTIMEOUTS timeouts;
            timeouts.ReadIntervalTimeout = 50;          // 字符间超时
            timeouts.ReadTotalTimeoutConstant = 100;    // 读取操作固定超时
            timeouts.ReadTotalTimeoutMultiplier = 10;   // 读取每字节的附加超时
            timeouts.WriteTotalTimeoutConstant = 100;   // 写入操作固定超时
            timeouts.WriteTotalTimeoutMultiplier = 10;  // 写入每字节的附加超时

            if (!SetCommTimeouts(hSerial, &timeouts)) {
                LOG_ERROR("设置串口超时参数失败，错误码: " + GetLastError());
            }

            // 清空串口缓冲区
            PurgeComm(hSerial, PURGE_RXCLEAR | PURGE_TXCLEAR);
        }
    }

    if (hSerial != INVALID_HANDLE_VALUE) {
        LOG_INFO("串口打开成功！");
        running = true;
    } else {
        LOG_ERROR("串口打开失败，错误码: " + GetLastError());
        m_status = SerialStatus::FAILED;
    }

}

SerialPortManager::~SerialPortManager()
{
    stop();
    if (read_thread.joinable()) {
        read_thread.join();
    }
    if (write_thread.joinable()) {
        write_thread.join();
    }
    if (write_junk_thread.joinable()) {
        write_junk_thread.join();
    }
}

std::string SerialPortManager::FindEsp32S3Port() {
    std::string targetPort = "";

    // 设备标识符 - 支持两种可能的ID格式
    const char* targetDeviceIds[] = {
        "USB\\VID_303A&PID_1001&REV_0101&MI_00",
        "USB\\VID_303A&PID_1001&MI_00"
    };

    // 获取设备信息集句柄
    HDEVINFO hDevInfo = SetupDiGetClassDevs(
        &GUID_DEVCLASS_PORTS,  // 过滤为串口设备类
        NULL,                  // 不指定枚举器字符串
        NULL,                  // 父窗口句柄
        DIGCF_PRESENT          // 仅获取当前存在的设备
    );

    if (hDevInfo == INVALID_HANDLE_VALUE) {
        LOG_ERROR("获取设备信息集失败，错误码: " + GetLastError());
        return "";
    }

    // 枚举设备
    SP_DEVINFO_DATA devInfoData;
    devInfoData.cbSize = sizeof(SP_DEVINFO_DATA);

    for (DWORD i = 0; SetupDiEnumDeviceInfo(hDevInfo, i, &devInfoData); i++) {
        // 获取设备实例ID
        char instanceId[256] = {0};
        if (!SetupDiGetDeviceInstanceIdA(hDevInfo, &devInfoData, instanceId, sizeof(instanceId), NULL)) {
            continue;
        }
        LOG_INFO("检查设备: " + QString(instanceId));
        // 检查是否是目标设备 - 尝试所有可能的ID
        bool isTargetDevice = false;
        for (const char* targetDeviceId : targetDeviceIds) {
            if (strstr(instanceId, targetDeviceId) != NULL) {
                isTargetDevice = true;
                LOG_INFO("匹配成功，找到目标设备: " + QString(targetDeviceId));
                break;
            }
        }

        if (isTargetDevice) {
            // 获取串口名称
            HKEY hKey = SetupDiOpenDevRegKey(
                hDevInfo,
                &devInfoData,
                DICS_FLAG_GLOBAL,
                0,
                DIREG_DEV,
                KEY_READ
            );

            if (hKey != INVALID_HANDLE_VALUE) {
                char portName[16] = {0};
                DWORD dwSize = sizeof(portName);
                DWORD dwType = 0;

                if (RegQueryValueExA(hKey, "PortName", NULL, &dwType, (LPBYTE)portName, &dwSize) == ERROR_SUCCESS) {
                    targetPort = portName;
                    LOG_INFO("找到ESP32-S3设备的COM端口: " + QString(targetPort.c_str()));
                }

                RegCloseKey(hKey);
                break;
            }
        }
    }

    // 调试：遍历所有可用的COM端口
    SP_DEVINFO_DATA devInfoData2;
    devInfoData2.cbSize = sizeof(SP_DEVINFO_DATA);
    LOG_INFO("系统中所有可用的COM端口: ");
    for (DWORD i = 0; SetupDiEnumDeviceInfo(hDevInfo, i, &devInfoData2); i++) {
        HKEY hKey = SetupDiOpenDevRegKey(
            hDevInfo,
            &devInfoData2,
            DICS_FLAG_GLOBAL,
            0,
            DIREG_DEV,
            KEY_READ
        );

        if (hKey != INVALID_HANDLE_VALUE) {
            char portName[16] = {0};
            DWORD dwSize = sizeof(portName);
            DWORD dwType = 0;

            if (RegQueryValueExA(hKey, "PortName", NULL, &dwType, (LPBYTE)portName, &dwSize) == ERROR_SUCCESS) {
                // 获取友好名称
                char friendlyName[256] = {0};
                DWORD nameSize = sizeof(friendlyName);
                if (SetupDiGetDeviceRegistryPropertyA(
                    hDevInfo,
                    &devInfoData2,
                    SPDRP_FRIENDLYNAME,
                    NULL,
                    (PBYTE)friendlyName,
                    nameSize,
                    NULL)) {
                    LOG_INFO(" - " + QString(portName) + " (" + QString(friendlyName) + ")");
                } else {
                    LOG_INFO(" - " + QString(portName));
                }
            }

            RegCloseKey(hKey);
        }
    }

    SetupDiDestroyDeviceInfoList(hDevInfo);

    if (targetPort.empty()) {
        LOG_ERROR("未找到ESP32-S3设备的COM端口");
    }

    return targetPort;
}
void SerialPortManager::start() {
    // 读取线程实现
    read_thread = std::thread(
        [this]
        {
            char buffer[256];
            DWORD bytesRead;
            std::string receivedData;

            // 为异步读取创建OVERLAPPED结构
            OVERLAPPED osReader = {0};
            osReader.hEvent = CreateEvent(NULL, TRUE, FALSE, NULL);

            if (osReader.hEvent == NULL) {
                LOG_ERROR("创建读取事件失败，错误码: " + GetLastError());
                return;
            }

            while (running) {
                // 开始异步读取
                BOOL readResult = ReadFile(
                    hSerial,
                    buffer,
                    sizeof(buffer) - 1,
                    &bytesRead,
                    &osReader
                );

                // 检查读取结果
                if (!readResult) {
                    DWORD dwError = GetLastError();

                    if (dwError == ERROR_IO_PENDING) {
                        // 等待读取完成，设置超时
                        DWORD dwWait = WaitForSingleObject(osReader.hEvent, 3000); // 1秒超时

                        if (dwWait == WAIT_OBJECT_0) {
                            // 读取完成，获取结果
                            if (GetOverlappedResult(hSerial, &osReader, &bytesRead, FALSE)) {
                                if (bytesRead > 0) {
                                    buffer[bytesRead] = '\0';
                                    receivedData += buffer;

                                    // 处理接收到的数据
                                    processReceivedData(receivedData);
                                }
                            }
                            else {
                                LOG_ERROR("GetOverlappedResult失败，错误码: " + GetLastError());
                            }
                        }
                        else if (dwWait == WAIT_TIMEOUT) {
                            // 读取超时，取消I/O操作
                            CancelIo(hSerial);
                        }
                        else {
                            LOG_ERROR("等待读取事件失败，错误码: " + GetLastError());
                        }
                    }
                    else {
                        // 其他错误
                        LOG_ERROR("串口读取失败，错误码: " + GetLastError());
                        if (dwError == ERROR_ACCESS_DENIED || dwError == ERROR_INVALID_HANDLE) {
                            // 严重错误，退出线程
                            break;
                        }
                    }
                }
                else {
                    // 同步读取成功
                    if (bytesRead > 0) {
                        buffer[bytesRead] = '\0';
                        receivedData += buffer;

                        // 处理接收到的数据
                        processReceivedData(receivedData);
                    }
                }

                // 延时一小段时间避免过度占用CPU
                Sleep(10);
            }
            m_status = SerialStatus::FAILED;
            // 清理资源
            CloseHandle(osReader.hEvent);
        }
    );

    // 写入线程实现
    write_junk_thread = std::thread(
        [this]
        {
            while (running) {
                std::string junk = " junk data ";
                write_data(junk);
                std::this_thread::sleep_for(std::chrono::milliseconds(1000));
            }
        }
    );
    write_thread = std::thread(
        [this]
        {
            // 为异步写入创建OVERLAPPED结构
            OVERLAPPED osWriter = {0};
            osWriter.hEvent = CreateEvent(NULL, TRUE, FALSE, NULL);

            if (osWriter.hEvent == NULL) {
                LOG_ERROR("创建写入事件失败，错误码: " + GetLastError());
                return;
            }

            while (running) {
                std::unique_lock<std::mutex> lock(writeQueueMutex);
                writeQueueCV.wait_for(lock, std::chrono::milliseconds(100), [this] { return !writeQueue.empty(); });

                if (!writeQueue.empty()) {
                    std::string data = writeQueue.front();
                    writeQueue.pop();
                    lock.unlock();  // 释放锁

                    DWORD bytesWritten = 0;

                    // 分块发送数据，每次最多发送64字节
                    const size_t CHUNK_SIZE = 64;
                    for (size_t i = 0; i < data.size() && running; i += CHUNK_SIZE) {
                        size_t chunkLen = std::min(CHUNK_SIZE, data.size() - i);

                        // 确保osWriter结构的成员被清零
                        ResetEvent(osWriter.hEvent);
                        osWriter.Offset = 0;
                        osWriter.OffsetHigh = 0;

                        // 异步写入
                        BOOL writeResult = WriteFile(
                            hSerial,
                            data.c_str() + i,
                            chunkLen,
                            &bytesWritten,
                            &osWriter
                        );

                        if (!writeResult) {
                            DWORD dwError = GetLastError();

                            if (dwError == ERROR_IO_PENDING) {
                                // 等待写入完成，设置超时
                                DWORD dwWait = WaitForSingleObject(osWriter.hEvent, 1000); // 1秒超时

                                if (dwWait == WAIT_OBJECT_0) {
                                    // 写入完成，获取结果
                                    if (!GetOverlappedResult(hSerial, &osWriter, &bytesWritten, FALSE)) {
                                        LOG_ERROR("GetOverlappedResult失败，错误码: " + GetLastError());
                                    }
                                    else if (bytesWritten != chunkLen) {
                                        LOG_WARN("警告：只写入了部分数据 " + QString(std::to_string(bytesWritten).c_str()) +
                                                "/" + QString(std::to_string(chunkLen).c_str()) + " 字节");
                                    }
                                }
                                else if (dwWait == WAIT_TIMEOUT) {
                                    // 写入超时，取消I/O操作
                                    LOG_ERROR("写入超时");
                                    CancelIo(hSerial);
                                }
                                else {
                                    // 其他错误
                                    LOG_ERROR("等待写入事件失败，错误码: " + GetLastError());
                                }
                            }
                            else {
                                // 处理其他错误
                                LOG_ERROR("串口写入失败，错误码: " + dwError);
                                m_status = SerialStatus::FAILED;
                                break;  // 退出当前数据的发送循环
                            }
                        }
                        else {
                            // 写入成功（同步完成）
                            if (bytesWritten != chunkLen) {
                                LOG_WARN("警告：只写入了部分数据 " + QString(std::to_string(bytesWritten).c_str()) +
                                            "/" + QString(std::to_string(chunkLen).c_str()) + " 字节");
                            }
                        }

                        // 添加小延时，避免连续写入过快
                        std::this_thread::sleep_for(std::chrono::milliseconds(10));
                    }
                    if (m_status == SerialStatus::FAILED)
                    {
                        break;
                    }
                    LOG_DEBUG("已发送数据: " + QString(data.c_str()));
                    // std::cout <<  << data << std::endl;
                }
            }
            m_status = SerialStatus::FAILED;

            // 清理资源
            CloseHandle(osWriter.hEvent);
        }
    );
    m_status = SerialStatus::OPENED;
    running = true;
}
void SerialPortManager::stop()
{
    running = false;
    read_thread.join();
    write_thread.join();
    write_junk_thread.join();
    if (hSerial != INVALID_HANDLE_VALUE) {
        CloseHandle(hSerial);
        hSerial = INVALID_HANDLE_VALUE;
    }
}
// 处理接收到的数据
void SerialPortManager::processReceivedData(std::string& receivedData) {
    // 处理粘包问题 - 循环处理所有可能的完整数据包
    while (true) {
        // 查找包起始字符 'A'
        size_t startPos = receivedData.find('A');
        if (startPos == std::string::npos) {
            // 没有找到起始符，清空缓冲区
            receivedData.clear();
            break;
        }

        // 如果起始符不在第一个位置，移除前面的无效数据
        if (startPos > 0) {
            receivedData = receivedData.substr(startPos);
        }

        // 查找包结束字符 'B'
        size_t endPos = receivedData.find('B', 1); // 从A后面开始查找
        if (endPos == std::string::npos) {
            // 没有找到完整的数据包，等待更多数据
            break;
        }

        // 确保在B后面有至少一个字符作为包类型
        if (endPos + 1 >= receivedData.length()) {
            // 包不完整，等待更多数据
            break;
        }

        // 提取完整的数据包，确保包括起始A和结束B及其后的类型字符
        std::string packet = receivedData.substr(0, endPos + 2);

        // 从缓冲区中移除已处理的数据包
        receivedData = receivedData.substr(endPos + 2);

        // 处理提取出的数据包

        LOG_DEBUG("接收到数据包: " + QString(packet.c_str()));
        PacketType type = parsePacket(packet);

        // 根据类型执行不同操作
        switch (type) {
        case PACKET_WIFI_SETUP:
            LOG_INFO("[WiFi 配置提示] 请配置 WiFi");
            break;
        case PACKET_WIFI_SSID_PWD:
            LOG_INFO("[WiFi 配置] 发送 SSID/PWD...");
            break;
        case PACKET_WIFI_CONFIRM:
            LOG_INFO("[WiFi 配置成功]");
            break;
        case PACKET_WIFI_ERROR:
            LOG_INFO("[WiFi 配置错误] SSID 或密码错误");
            break;
        case PACKET_DEVICE_STATUS:
            LOG_INFO("[设备状态] 更新设备信息...");
            break;
        case PACKET_LIGHT_CONTROL:
            LOG_INFO("[补光灯设置] 调整亮度");
            break;
        default:
            LOG_WARN("[未知数据包]: " + QString(packet.c_str()));
        }
    }
}
void SerialPortManager::write_data(const std::string& data)
{
    {
        std::lock_guard<std::mutex> lock(writeQueueMutex);
        writeQueue.push(data);
    }
    writeQueueCV.notify_one();
}
static std::string trim(const std::string& str) {
    const std::string whitespace = " \t\n\r";
    size_t start = str.find_first_not_of(whitespace);
    if (start == std::string::npos)
        return ""; // 全部为空白
    size_t end = str.find_last_not_of(whitespace);
    return str.substr(start, end - start + 1);
}

PacketType SerialPortManager::parsePacket(const std::string& packet)
{
    // 先将收到的字符串去除首尾空白（例如换行符、空格）
    std::string trimmedPacket = trim(packet);
    LOG_DEBUG("Parsing packet: [" + QString(trimmedPacket.c_str()) + "]");

    // 基本验证：检查包格式是否有效（A开头，B结尾加数字）
    if (trimmedPacket.length() < 3 || trimmedPacket[0] != 'A' ||
        trimmedPacket[trimmedPacket.length() - 2] != 'B') {
        LOG_DEBUG("无效包格式");
        return PACKET_UNKNOWN;
    }

    // 获取包类型（B后面的数字）
    char packetType = trimmedPacket[trimmedPacket.length() - 1];

    std::smatch match;

    // 根据包类型选择正则表达式
    switch (packetType) {
        case '1': // 数据包1：A101B1
            if (std::regex_match(trimmedPacket, std::regex("^A1(01)B1$"))) {
                LOG_DEBUG("匹配到包类型1 (WiFi 配置提示)");
                return PACKET_WIFI_SETUP;
            }
            break;

        case '2': // 数据包2：A2SSID[SSID内容]PWD[PWD]B2
            if (std::regex_match(trimmedPacket, match, std::regex("^A2SSID(.*?)PWD(.*?)B2$"))) {
                LOG_DEBUG("匹配到包类型2 (WiFi 配置数据): SSID = " +
                          QString(match[1].str().c_str()) + ", PWD = " + QString(match[2].str().c_str()));
                return PACKET_WIFI_SSID_PWD;
            }
            break;

        case '3': // 数据包3：A303B3
            if (std::regex_match(trimmedPacket, std::regex("^A303B3$"))) {
                LOG_DEBUG("匹配到包类型3 (WiFi 配置成功确认)");
                return PACKET_WIFI_CONFIRM;
            }
            break;

        case '4': // 数据包4：A4SSID[SSID内容]PWD[PWD]B4
            if (std::regex_match(trimmedPacket, match, std::regex("^A4SSID(.*?)PWD(.*?)B4$"))) {
                LOG_DEBUG("匹配到包类型4 (WiFi 配置错误): SSID = " +
                          QString(match[1].str().c_str()) + ", PWD = " + QString(match[2].str().c_str()));
                return PACKET_WIFI_ERROR;
            }
            break;

    case '5': // 数据包5：A5[亮度][IP地址]POWER[电量]VERSION[固件版本]B5
        if (std::regex_match(trimmedPacket, match,
            std::regex("^A5(\\d{1,3})(\\d+)POWER(\\d{1,3})VERSION(\\d{1,3})B5$"))) {
            // 获取数字形式的IP地址
            std::string rawIp = match[2];

            // 格式化为标准IPv4地址 (169031168192 -> 169.031.168.192)
            std::string formattedIp;
            try {
                // 确保IP长度足够，如果不够则前面补0
                std::string paddedIp = rawIp;
                while (paddedIp.length() < 12) {
                    paddedIp = "0" + paddedIp;
                }

                // 以3位一组分割，然后转换为标准IPv4格式
                // 修改IP格式化逻辑，反转四组数字的顺序
                formattedIp =
                    std::to_string(std::stoi(paddedIp.substr(9, 3))) + "." +
                    std::to_string(std::stoi(paddedIp.substr(6, 3))) + "." +
                    std::to_string(std::stoi(paddedIp.substr(3, 3))) + "." +
                    std::to_string(std::stoi(paddedIp.substr(0, 3)));
                // 调用回调函数
                if (deviceStatusCallback) {
                    int brightness = std::stoi(match[1]);
                    int power = std::stoi(match[3]);
                    int version = std::stoi(match[4]);
                    deviceStatusCallback(formattedIp, brightness, power, version);
                }
            } catch (const std::exception& e) {
                LOG_ERROR("IP格式转换失败: " + QString(e.what()));
                formattedIp = rawIp; // 转换失败时使用原始IP
            }
            LOG_DEBUG("匹配到包类型5 (设备状态): 亮度 = " + QString(match[1].str().c_str()) +
                      ", IP = " + QString(formattedIp.c_str()) + ", 电量 = " + QString(match[3].str().c_str()) +
                      ", 固件版本 = " + QString(match[4].str().c_str()));
            return PACKET_DEVICE_STATUS;
            }
        break;

        case '6': // 数据包6：A6[亮度]B6
            if (std::regex_match(trimmedPacket, match, std::regex("^A6(\\d{1,3})B6$"))) {
                LOG_DEBUG("匹配到包类型6 (补光灯控制): 亮度 = " + QString(match[1].str().c_str()));
                return PACKET_LIGHT_CONTROL;
            }
            break;

        default:
            break;
    }
    LOG_DEBUG("未匹配任何数据包类型: " + QString(packetType));
    return PACKET_UNKNOWN;
}
void SerialPortManager::sendWiFiConfig(HANDLE hSerial, const std::string& ssid, const std::string& pwd)
{
    std::string packet = "A2SSID" + ssid + "PWD" + pwd + "B2";
    DWORD bytesWritten;
    WriteFile(hSerial, packet.c_str(), packet.size(), &bytesWritten, NULL);
    LOG_INFO("发送 WiFi 配置: " + QString(packet.c_str()));
}
std::string formatIpAddress(const std::string& ipRaw) {
    // 假设输入格式为类似"169031168192"
    // 如果长度不足，前面补0
    std::string paddedIp = ipRaw;
    while (paddedIp.length() < 12) {
        paddedIp = "0" + paddedIp;
    }

    // 以3位一组分割，然后转换为点分十进制
    std::string formattedIp =
        std::to_string(std::stoi(paddedIp.substr(0, 3))) + "." +
        std::to_string(std::stoi(paddedIp.substr(3, 3))) + "." +
        std::to_string(std::stoi(paddedIp.substr(6, 3))) + "." +
        std::to_string(std::stoi(paddedIp.substr(9, 3)));

    return formattedIp;
}
void SerialPortManager::sendLightControl(HANDLE hSerial, int brightness)
{
    std::string packet = "A6" + std::to_string(brightness) + "B6";
    DWORD bytesWritten;
    WriteFile(hSerial, packet.c_str(), packet.size(), &bytesWritten, NULL);
    LOG_INFO("发送补光灯亮度: " + QString(std::to_string(brightness).c_str()));
}

HANDLE SerialPortManager::initSerialPort(const wchar_t* portName)
{
    HANDLE hSerial = CreateFile(portName, GENERIC_READ | GENERIC_WRITE, 0, NULL, OPEN_EXISTING, 0, NULL);

    if (hSerial == INVALID_HANDLE_VALUE) {
        LOG_ERROR("打开串口失败: " + GetLastError());
        return INVALID_HANDLE_VALUE;
    }

    DCB dcbSerialParams = {0};
    dcbSerialParams.DCBlength = sizeof(dcbSerialParams);

    if (!GetCommState(hSerial, &dcbSerialParams)) {
        LOG_ERROR("获取串口状态失败");
        CloseHandle(hSerial);
        return INVALID_HANDLE_VALUE;
    }

    // 修改配置
    dcbSerialParams.BaudRate = CBR_115200;        // 设置波特率
    dcbSerialParams.ByteSize = 8;                 // 数据位
    dcbSerialParams.StopBits = ONESTOPBIT;        // 停止位
    dcbSerialParams.Parity = NOPARITY;            // 无校验
    dcbSerialParams.fDtrControl = DTR_CONTROL_ENABLE;  // 启用DTR

    // 禁用流控制
    // dcbSerialParams.fOutxCtsFlow = FALSE;         // 禁用CTS流控
    // dcbSerialParams.fRtsControl = DTR_CONTROL_ENABLE;  // 启用RTS但不用于流控
    // dcbSerialParams.fOutX = FALSE;                // 禁用XON/XOFF
    // dcbSerialParams.fInX = FALSE;                 // 禁用XON/XOFF

    if (!SetCommState(hSerial, &dcbSerialParams)) {
        LOG_ERROR("配置串口失败");
        CloseHandle(hSerial);
        return INVALID_HANDLE_VALUE;
    }

    // 清空串口缓冲区
    PurgeComm(hSerial, PURGE_RXCLEAR | PURGE_TXCLEAR);
    return hSerial;
}


SerialStatus SerialPortManager::status() const
{
    return m_status;
}


