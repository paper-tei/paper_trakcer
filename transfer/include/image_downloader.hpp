#pragma once

#include <string>
#include <vector>
#include <thread>
#include <atomic>
#include <queue>
#include <opencv2/core.hpp>
#include <QWebSocket>
#include <QObject>
#include <QByteArray>
#include <QImage>
#include <QMutex>
#include "logger.hpp"

class ESP32VideoStream : public QObject {


public:
    // 构造函数和析构函数
    ESP32VideoStream(QObject *parent = nullptr);
    ~ESP32VideoStream();

    // 初始化视频流，设置ESP32的URL
    bool init(const std::string& url);

    // 开始接收视频流
    bool start();

    // 停止视频流
    void stop();

    // 获取最新的帧
    cv::Mat getLatestFrame() const;

    // 检查流是否正在运行
    bool isStreaming() const { return isRunning; }

    private slots:
        // WebSocket连接成功的槽函数
        void onConnected();

    // WebSocket连接关闭的槽函数
    void onDisconnected();

    // WebSocket错误的槽函数
    void onError(QAbstractSocket::SocketError error);

    // 处理接收到的二进制消息(JPEG图片)
    void onBinaryMessageReceived(const QByteArray &message);

private:
    // 将QImage转换为cv::Mat
    cv::Mat QImageToCvMat(const QImage &image) const;

    // 辅助函数：将字节数组转换为十六进制字符串（用于调试）
    std::string bytesToHexString(const QByteArray &bytes) const;

    // 成员变量
    std::atomic<bool> isRunning;
    std::string currentStreamUrl;
    QWebSocket webSocket;
    mutable QMutex mutex;
    std::queue<cv::Mat> image_buffer_queue;
};