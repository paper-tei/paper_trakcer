/********************************************************************************
** Form generated from reading UI file 'main_window.ui'
**
** Created by: Qt User Interface Compiler version 6.8.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAIN_WINDOW_H
#define UI_MAIN_WINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QScrollBar>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_PaperTrackMainWindow
{
public:
    QStackedWidget *stackedWidget;
    QWidget *page;
    QCheckBox *VerticalFlipBox;
    QPushButton *TrackModeButton;
    QLabel *label;
    QLabel *ModeLabel;
    QCheckBox *EnableCalibrationBox;
    QLabel *label_2;
    QComboBox *CameraAddressList;
    QPushButton *StartCalibrationButton;
    QCheckBox *HorizontalFlipBox;
    QPushButton *CutOffModeButton;
    QLabel *label_3;
    QPushButton *SaveAndRestartButton;
    QScrollBar *ImageRotationBar;
    QPushButton *RefreshCameraListButton;
    QPushButton *StopCalibrationButton;
    QWidget *page_2;
    QLabel *label_5;
    QCheckBox *CheckUpdateBox;
    QLabel *label_6;
    QLabel *label_7;
    QLabel *label_8;
    QLabel *label_9;
    QCheckBox *StartReceiveBox;
    QLabel *label_10;
    QLabel *label_11;
    QCheckBox *CloseCameraOutputBox;
    QCheckBox *StartOSCBox;
    QLabel *label_12;
    QLabel *label_13;
    QCheckBox *checkBox_8;
    QLabel *label_14;
    QLabel *label_15;
    QLabel *label_16;
    QPlainTextEdit *XResolutionInput;
    QPlainTextEdit *YResolutionInput;
    QPlainTextEdit *FPSInput;
    QPlainTextEdit *OSCDelayInput;
    QPlainTextEdit *ReCalibrateAddressInput;
    QPlainTextEdit *IPInput;
    QPlainTextEdit *PortInput;
    QPlainTextEdit *LocationPrefixInput;
    QLabel *label_25;
    QLabel *label_26;
    QPlainTextEdit *ModelPathInput;
    QPushButton *ModelPathFindButton;
    QLabel *label_27;
    QPlainTextEdit *InferenceThreadsInput;
    QLabel *label_28;
    QPlainTextEdit *GPUInput;
    QCheckBox *UseGPUBox;
    QLabel *label_29;
    QPlainTextEdit *ModelOutputMultiplierInput;
    QLabel *label_30;
    QPlainTextEdit *CalibrationDeadZoneInput;
    QLabel *label_31;
    QLabel *label_32;
    QPlainTextEdit *MinFreqCutOffInput;
    QLabel *label_33;
    QPlainTextEdit *SpeedCoeffInput;
    QPlainTextEdit *ReceiveFunctionInput;
    QWidget *page_3;
    QLabel *label_17;
    QLabel *label_18;
    QComboBox *CalibrationModeList;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QLabel *label_24;
    QPlainTextEdit *plainTextEdit_16;
    QPlainTextEdit *plainTextEdit_17;
    QPlainTextEdit *plainTextEdit_18;
    QPlainTextEdit *plainTextEdit_19;
    QPlainTextEdit *plainTextEdit_20;
    QPlainTextEdit *plainTextEdit_21;
    QPlainTextEdit *plainTextEdit_22;
    QPlainTextEdit *plainTextEdit_23;
    QPlainTextEdit *plainTextEdit_24;
    QPlainTextEdit *plainTextEdit_25;
    QPlainTextEdit *plainTextEdit_26;
    QPlainTextEdit *plainTextEdit_27;
    QPlainTextEdit *plainTextEdit_28;
    QPlainTextEdit *plainTextEdit_29;
    QPlainTextEdit *plainTextEdit_30;
    QPlainTextEdit *plainTextEdit_31;
    QPlainTextEdit *plainTextEdit_32;
    QPlainTextEdit *plainTextEdit_33;
    QPlainTextEdit *plainTextEdit_34;
    QPlainTextEdit *plainTextEdit_35;
    QPlainTextEdit *plainTextEdit_36;
    QPlainTextEdit *plainTextEdit_37;
    QPlainTextEdit *plainTextEdit_38;
    QPlainTextEdit *plainTextEdit_39;
    QPlainTextEdit *plainTextEdit_40;
    QPlainTextEdit *plainTextEdit_41;
    QPlainTextEdit *plainTextEdit_42;
    QPlainTextEdit *plainTextEdit_43;
    QPlainTextEdit *plainTextEdit_44;
    QPlainTextEdit *plainTextEdit_45;
    QPlainTextEdit *plainTextEdit_46;
    QPlainTextEdit *plainTextEdit_47;
    QPlainTextEdit *plainTextEdit_48;
    QPlainTextEdit *plainTextEdit_49;
    QPlainTextEdit *plainTextEdit_50;
    QPlainTextEdit *plainTextEdit_51;
    QPlainTextEdit *plainTextEdit_52;
    QPlainTextEdit *plainTextEdit_53;
    QPlainTextEdit *plainTextEdit_54;
    QPlainTextEdit *plainTextEdit_55;
    QLabel *label_19;
    QLabel *label_20;
    QLabel *label_21;
    QLabel *label_22;
    QLabel *label_23;
    QPushButton *CameraZoneButton;
    QPushButton *SettingsZoneButton;
    QPushButton *CalibrationZoneButton;

    void setupUi(QWidget *PaperTrackMainWindow)
    {
        if (PaperTrackMainWindow->objectName().isEmpty())
            PaperTrackMainWindow->setObjectName("PaperTrackMainWindow");
        PaperTrackMainWindow->resize(552, 629);
        stackedWidget = new QStackedWidget(PaperTrackMainWindow);
        stackedWidget->setObjectName("stackedWidget");
        stackedWidget->setGeometry(QRect(0, 50, 541, 571));
        page = new QWidget();
        page->setObjectName("page");
        VerticalFlipBox = new QCheckBox(page);
        VerticalFlipBox->setObjectName("VerticalFlipBox");
        VerticalFlipBox->setGeometry(QRect(320, 310, 83, 19));
        TrackModeButton = new QPushButton(page);
        TrackModeButton->setObjectName("TrackModeButton");
        TrackModeButton->setGeometry(QRect(40, 160, 211, 31));
        label = new QLabel(page);
        label->setObjectName("label");
        label->setGeometry(QRect(50, 60, 61, 31));
        ModeLabel = new QLabel(page);
        ModeLabel->setObjectName("ModeLabel");
        ModeLabel->setGeometry(QRect(120, 350, 171, 31));
        EnableCalibrationBox = new QCheckBox(page);
        EnableCalibrationBox->setObjectName("EnableCalibrationBox");
        EnableCalibrationBox->setGeometry(QRect(50, 310, 83, 19));
        label_2 = new QLabel(page);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(50, 210, 81, 31));
        CameraAddressList = new QComboBox(page);
        CameraAddressList->setObjectName("CameraAddressList");
        CameraAddressList->setGeometry(QRect(130, 60, 231, 31));
        StartCalibrationButton = new QPushButton(page);
        StartCalibrationButton->setObjectName("StartCalibrationButton");
        StartCalibrationButton->setGeometry(QRect(40, 260, 211, 31));
        HorizontalFlipBox = new QCheckBox(page);
        HorizontalFlipBox->setObjectName("HorizontalFlipBox");
        HorizontalFlipBox->setGeometry(QRect(180, 310, 83, 19));
        CutOffModeButton = new QPushButton(page);
        CutOffModeButton->setObjectName("CutOffModeButton");
        CutOffModeButton->setGeometry(QRect(290, 160, 211, 31));
        label_3 = new QLabel(page);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(50, 350, 71, 31));
        SaveAndRestartButton = new QPushButton(page);
        SaveAndRestartButton->setObjectName("SaveAndRestartButton");
        SaveAndRestartButton->setGeometry(QRect(40, 110, 461, 31));
        ImageRotationBar = new QScrollBar(page);
        ImageRotationBar->setObjectName("ImageRotationBar");
        ImageRotationBar->setGeometry(QRect(170, 210, 321, 31));
        ImageRotationBar->setOrientation(Qt::Orientation::Horizontal);
        RefreshCameraListButton = new QPushButton(page);
        RefreshCameraListButton->setObjectName("RefreshCameraListButton");
        RefreshCameraListButton->setGeometry(QRect(390, 60, 101, 31));
        StopCalibrationButton = new QPushButton(page);
        StopCalibrationButton->setObjectName("StopCalibrationButton");
        StopCalibrationButton->setGeometry(QRect(290, 260, 211, 31));
        stackedWidget->addWidget(page);
        page_2 = new QWidget();
        page_2->setObjectName("page_2");
        label_5 = new QLabel(page_2);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(20, 10, 61, 31));
        CheckUpdateBox = new QCheckBox(page_2);
        CheckUpdateBox->setObjectName("CheckUpdateBox");
        CheckUpdateBox->setGeometry(QRect(40, 40, 81, 31));
        label_6 = new QLabel(page_2);
        label_6->setObjectName("label_6");
        label_6->setGeometry(QRect(20, 70, 61, 31));
        label_7 = new QLabel(page_2);
        label_7->setObjectName("label_7");
        label_7->setGeometry(QRect(40, 90, 61, 31));
        label_8 = new QLabel(page_2);
        label_8->setObjectName("label_8");
        label_8->setGeometry(QRect(40, 130, 61, 31));
        label_9 = new QLabel(page_2);
        label_9->setObjectName("label_9");
        label_9->setGeometry(QRect(270, 130, 61, 31));
        StartReceiveBox = new QCheckBox(page_2);
        StartReceiveBox->setObjectName("StartReceiveBox");
        StartReceiveBox->setGeometry(QRect(40, 160, 121, 31));
        label_10 = new QLabel(page_2);
        label_10->setObjectName("label_10");
        label_10->setGeometry(QRect(170, 160, 91, 31));
        label_11 = new QLabel(page_2);
        label_11->setObjectName("label_11");
        label_11->setGeometry(QRect(40, 190, 81, 31));
        CloseCameraOutputBox = new QCheckBox(page_2);
        CloseCameraOutputBox->setObjectName("CloseCameraOutputBox");
        CloseCameraOutputBox->setGeometry(QRect(40, 220, 211, 31));
        StartOSCBox = new QCheckBox(page_2);
        StartOSCBox->setObjectName("StartOSCBox");
        StartOSCBox->setGeometry(QRect(40, 250, 121, 31));
        label_12 = new QLabel(page_2);
        label_12->setObjectName("label_12");
        label_12->setGeometry(QRect(40, 280, 151, 31));
        label_13 = new QLabel(page_2);
        label_13->setObjectName("label_13");
        label_13->setGeometry(QRect(20, 310, 91, 31));
        checkBox_8 = new QCheckBox(page_2);
        checkBox_8->setObjectName("checkBox_8");
        checkBox_8->setGeometry(QRect(40, 340, 121, 31));
        label_14 = new QLabel(page_2);
        label_14->setObjectName("label_14");
        label_14->setGeometry(QRect(150, 340, 71, 31));
        label_15 = new QLabel(page_2);
        label_15->setObjectName("label_15");
        label_15->setGeometry(QRect(270, 340, 81, 31));
        label_16 = new QLabel(page_2);
        label_16->setObjectName("label_16");
        label_16->setGeometry(QRect(390, 340, 31, 31));
        XResolutionInput = new QPlainTextEdit(page_2);
        XResolutionInput->setObjectName("XResolutionInput");
        XResolutionInput->setGeometry(QRect(220, 340, 41, 31));
        YResolutionInput = new QPlainTextEdit(page_2);
        YResolutionInput->setObjectName("YResolutionInput");
        YResolutionInput->setGeometry(QRect(340, 340, 41, 31));
        FPSInput = new QPlainTextEdit(page_2);
        FPSInput->setObjectName("FPSInput");
        FPSInput->setGeometry(QRect(420, 340, 41, 31));
        OSCDelayInput = new QPlainTextEdit(page_2);
        OSCDelayInput->setObjectName("OSCDelayInput");
        OSCDelayInput->setGeometry(QRect(190, 280, 41, 31));
        ReCalibrateAddressInput = new QPlainTextEdit(page_2);
        ReCalibrateAddressInput->setObjectName("ReCalibrateAddressInput");
        ReCalibrateAddressInput->setGeometry(QRect(110, 190, 271, 31));
        IPInput = new QPlainTextEdit(page_2);
        IPInput->setObjectName("IPInput");
        IPInput->setGeometry(QRect(90, 130, 161, 31));
        PortInput = new QPlainTextEdit(page_2);
        PortInput->setObjectName("PortInput");
        PortInput->setGeometry(QRect(320, 130, 161, 31));
        LocationPrefixInput = new QPlainTextEdit(page_2);
        LocationPrefixInput->setObjectName("LocationPrefixInput");
        LocationPrefixInput->setGeometry(QRect(100, 90, 221, 31));
        label_25 = new QLabel(page_2);
        label_25->setObjectName("label_25");
        label_25->setGeometry(QRect(20, 370, 91, 31));
        label_26 = new QLabel(page_2);
        label_26->setObjectName("label_26");
        label_26->setGeometry(QRect(40, 400, 91, 31));
        ModelPathInput = new QPlainTextEdit(page_2);
        ModelPathInput->setObjectName("ModelPathInput");
        ModelPathInput->setGeometry(QRect(130, 400, 271, 31));
        ModelPathFindButton = new QPushButton(page_2);
        ModelPathFindButton->setObjectName("ModelPathFindButton");
        ModelPathFindButton->setGeometry(QRect(410, 400, 101, 31));
        label_27 = new QLabel(page_2);
        label_27->setObjectName("label_27");
        label_27->setGeometry(QRect(40, 440, 91, 31));
        InferenceThreadsInput = new QPlainTextEdit(page_2);
        InferenceThreadsInput->setObjectName("InferenceThreadsInput");
        InferenceThreadsInput->setGeometry(QRect(120, 440, 41, 31));
        label_28 = new QLabel(page_2);
        label_28->setObjectName("label_28");
        label_28->setGeometry(QRect(190, 440, 61, 31));
        GPUInput = new QPlainTextEdit(page_2);
        GPUInput->setObjectName("GPUInput");
        GPUInput->setGeometry(QRect(250, 440, 41, 31));
        UseGPUBox = new QCheckBox(page_2);
        UseGPUBox->setObjectName("UseGPUBox");
        UseGPUBox->setGeometry(QRect(310, 440, 121, 31));
        label_29 = new QLabel(page_2);
        label_29->setObjectName("label_29");
        label_29->setGeometry(QRect(40, 480, 111, 31));
        ModelOutputMultiplierInput = new QPlainTextEdit(page_2);
        ModelOutputMultiplierInput->setObjectName("ModelOutputMultiplierInput");
        ModelOutputMultiplierInput->setGeometry(QRect(160, 480, 41, 31));
        label_30 = new QLabel(page_2);
        label_30->setObjectName("label_30");
        label_30->setGeometry(QRect(220, 480, 61, 31));
        CalibrationDeadZoneInput = new QPlainTextEdit(page_2);
        CalibrationDeadZoneInput->setObjectName("CalibrationDeadZoneInput");
        CalibrationDeadZoneInput->setGeometry(QRect(280, 480, 41, 31));
        label_31 = new QLabel(page_2);
        label_31->setObjectName("label_31");
        label_31->setGeometry(QRect(20, 510, 111, 31));
        label_32 = new QLabel(page_2);
        label_32->setObjectName("label_32");
        label_32->setGeometry(QRect(40, 540, 111, 31));
        MinFreqCutOffInput = new QPlainTextEdit(page_2);
        MinFreqCutOffInput->setObjectName("MinFreqCutOffInput");
        MinFreqCutOffInput->setGeometry(QRect(130, 540, 41, 31));
        label_33 = new QLabel(page_2);
        label_33->setObjectName("label_33");
        label_33->setGeometry(QRect(220, 540, 111, 31));
        SpeedCoeffInput = new QPlainTextEdit(page_2);
        SpeedCoeffInput->setObjectName("SpeedCoeffInput");
        SpeedCoeffInput->setGeometry(QRect(280, 540, 41, 31));
        ReceiveFunctionInput = new QPlainTextEdit(page_2);
        ReceiveFunctionInput->setObjectName("ReceiveFunctionInput");
        ReceiveFunctionInput->setGeometry(QRect(260, 170, 81, 21));
        stackedWidget->addWidget(page_2);
        page_3 = new QWidget();
        page_3->setObjectName("page_3");
        label_17 = new QLabel(page_3);
        label_17->setObjectName("label_17");
        label_17->setGeometry(QRect(10, 10, 61, 31));
        label_18 = new QLabel(page_3);
        label_18->setObjectName("label_18");
        label_18->setGeometry(QRect(150, 10, 61, 31));
        CalibrationModeList = new QComboBox(page_3);
        CalibrationModeList->setObjectName("CalibrationModeList");
        CalibrationModeList->setGeometry(QRect(220, 10, 151, 31));
        scrollArea = new QScrollArea(page_3);
        scrollArea->setObjectName("scrollArea");
        scrollArea->setGeometry(QRect(0, 70, 511, 461));
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName("scrollAreaWidgetContents");
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 509, 459));
        label_24 = new QLabel(scrollAreaWidgetContents);
        label_24->setObjectName("label_24");
        label_24->setGeometry(QRect(210, 10, 41, 31));
        plainTextEdit_16 = new QPlainTextEdit(scrollAreaWidgetContents);
        plainTextEdit_16->setObjectName("plainTextEdit_16");
        plainTextEdit_16->setGeometry(QRect(10, 10, 41, 31));
        plainTextEdit_17 = new QPlainTextEdit(scrollAreaWidgetContents);
        plainTextEdit_17->setObjectName("plainTextEdit_17");
        plainTextEdit_17->setGeometry(QRect(70, 10, 41, 31));
        plainTextEdit_18 = new QPlainTextEdit(scrollAreaWidgetContents);
        plainTextEdit_18->setObjectName("plainTextEdit_18");
        plainTextEdit_18->setGeometry(QRect(10, 50, 41, 31));
        plainTextEdit_19 = new QPlainTextEdit(scrollAreaWidgetContents);
        plainTextEdit_19->setObjectName("plainTextEdit_19");
        plainTextEdit_19->setGeometry(QRect(70, 50, 41, 31));
        plainTextEdit_20 = new QPlainTextEdit(scrollAreaWidgetContents);
        plainTextEdit_20->setObjectName("plainTextEdit_20");
        plainTextEdit_20->setGeometry(QRect(10, 90, 41, 31));
        plainTextEdit_21 = new QPlainTextEdit(scrollAreaWidgetContents);
        plainTextEdit_21->setObjectName("plainTextEdit_21");
        plainTextEdit_21->setGeometry(QRect(70, 90, 41, 31));
        plainTextEdit_22 = new QPlainTextEdit(scrollAreaWidgetContents);
        plainTextEdit_22->setObjectName("plainTextEdit_22");
        plainTextEdit_22->setGeometry(QRect(10, 130, 41, 31));
        plainTextEdit_23 = new QPlainTextEdit(scrollAreaWidgetContents);
        plainTextEdit_23->setObjectName("plainTextEdit_23");
        plainTextEdit_23->setGeometry(QRect(70, 130, 41, 31));
        plainTextEdit_24 = new QPlainTextEdit(scrollAreaWidgetContents);
        plainTextEdit_24->setObjectName("plainTextEdit_24");
        plainTextEdit_24->setGeometry(QRect(10, 170, 41, 31));
        plainTextEdit_25 = new QPlainTextEdit(scrollAreaWidgetContents);
        plainTextEdit_25->setObjectName("plainTextEdit_25");
        plainTextEdit_25->setGeometry(QRect(70, 170, 41, 31));
        plainTextEdit_26 = new QPlainTextEdit(scrollAreaWidgetContents);
        plainTextEdit_26->setObjectName("plainTextEdit_26");
        plainTextEdit_26->setGeometry(QRect(70, 290, 41, 31));
        plainTextEdit_27 = new QPlainTextEdit(scrollAreaWidgetContents);
        plainTextEdit_27->setObjectName("plainTextEdit_27");
        plainTextEdit_27->setGeometry(QRect(70, 210, 41, 31));
        plainTextEdit_28 = new QPlainTextEdit(scrollAreaWidgetContents);
        plainTextEdit_28->setObjectName("plainTextEdit_28");
        plainTextEdit_28->setGeometry(QRect(70, 330, 41, 31));
        plainTextEdit_29 = new QPlainTextEdit(scrollAreaWidgetContents);
        plainTextEdit_29->setObjectName("plainTextEdit_29");
        plainTextEdit_29->setGeometry(QRect(70, 370, 41, 31));
        plainTextEdit_30 = new QPlainTextEdit(scrollAreaWidgetContents);
        plainTextEdit_30->setObjectName("plainTextEdit_30");
        plainTextEdit_30->setGeometry(QRect(10, 290, 41, 31));
        plainTextEdit_31 = new QPlainTextEdit(scrollAreaWidgetContents);
        plainTextEdit_31->setObjectName("plainTextEdit_31");
        plainTextEdit_31->setGeometry(QRect(10, 370, 41, 31));
        plainTextEdit_32 = new QPlainTextEdit(scrollAreaWidgetContents);
        plainTextEdit_32->setObjectName("plainTextEdit_32");
        plainTextEdit_32->setGeometry(QRect(10, 250, 41, 31));
        plainTextEdit_33 = new QPlainTextEdit(scrollAreaWidgetContents);
        plainTextEdit_33->setObjectName("plainTextEdit_33");
        plainTextEdit_33->setGeometry(QRect(70, 250, 41, 31));
        plainTextEdit_34 = new QPlainTextEdit(scrollAreaWidgetContents);
        plainTextEdit_34->setObjectName("plainTextEdit_34");
        plainTextEdit_34->setGeometry(QRect(10, 210, 41, 31));
        plainTextEdit_35 = new QPlainTextEdit(scrollAreaWidgetContents);
        plainTextEdit_35->setObjectName("plainTextEdit_35");
        plainTextEdit_35->setGeometry(QRect(10, 330, 41, 31));
        plainTextEdit_36 = new QPlainTextEdit(scrollAreaWidgetContents);
        plainTextEdit_36->setObjectName("plainTextEdit_36");
        plainTextEdit_36->setGeometry(QRect(460, 90, 41, 31));
        plainTextEdit_37 = new QPlainTextEdit(scrollAreaWidgetContents);
        plainTextEdit_37->setObjectName("plainTextEdit_37");
        plainTextEdit_37->setGeometry(QRect(460, 10, 41, 31));
        plainTextEdit_38 = new QPlainTextEdit(scrollAreaWidgetContents);
        plainTextEdit_38->setObjectName("plainTextEdit_38");
        plainTextEdit_38->setGeometry(QRect(400, 250, 41, 31));
        plainTextEdit_39 = new QPlainTextEdit(scrollAreaWidgetContents);
        plainTextEdit_39->setObjectName("plainTextEdit_39");
        plainTextEdit_39->setGeometry(QRect(460, 130, 41, 31));
        plainTextEdit_40 = new QPlainTextEdit(scrollAreaWidgetContents);
        plainTextEdit_40->setObjectName("plainTextEdit_40");
        plainTextEdit_40->setGeometry(QRect(460, 330, 41, 31));
        plainTextEdit_41 = new QPlainTextEdit(scrollAreaWidgetContents);
        plainTextEdit_41->setObjectName("plainTextEdit_41");
        plainTextEdit_41->setGeometry(QRect(460, 170, 41, 31));
        plainTextEdit_42 = new QPlainTextEdit(scrollAreaWidgetContents);
        plainTextEdit_42->setObjectName("plainTextEdit_42");
        plainTextEdit_42->setGeometry(QRect(460, 250, 41, 31));
        plainTextEdit_43 = new QPlainTextEdit(scrollAreaWidgetContents);
        plainTextEdit_43->setObjectName("plainTextEdit_43");
        plainTextEdit_43->setGeometry(QRect(400, 330, 41, 31));
        plainTextEdit_44 = new QPlainTextEdit(scrollAreaWidgetContents);
        plainTextEdit_44->setObjectName("plainTextEdit_44");
        plainTextEdit_44->setGeometry(QRect(460, 210, 41, 31));
        plainTextEdit_45 = new QPlainTextEdit(scrollAreaWidgetContents);
        plainTextEdit_45->setObjectName("plainTextEdit_45");
        plainTextEdit_45->setGeometry(QRect(460, 290, 41, 31));
        plainTextEdit_46 = new QPlainTextEdit(scrollAreaWidgetContents);
        plainTextEdit_46->setObjectName("plainTextEdit_46");
        plainTextEdit_46->setGeometry(QRect(400, 290, 41, 31));
        plainTextEdit_47 = new QPlainTextEdit(scrollAreaWidgetContents);
        plainTextEdit_47->setObjectName("plainTextEdit_47");
        plainTextEdit_47->setGeometry(QRect(400, 90, 41, 31));
        plainTextEdit_48 = new QPlainTextEdit(scrollAreaWidgetContents);
        plainTextEdit_48->setObjectName("plainTextEdit_48");
        plainTextEdit_48->setGeometry(QRect(400, 170, 41, 31));
        plainTextEdit_49 = new QPlainTextEdit(scrollAreaWidgetContents);
        plainTextEdit_49->setObjectName("plainTextEdit_49");
        plainTextEdit_49->setGeometry(QRect(400, 50, 41, 31));
        plainTextEdit_50 = new QPlainTextEdit(scrollAreaWidgetContents);
        plainTextEdit_50->setObjectName("plainTextEdit_50");
        plainTextEdit_50->setGeometry(QRect(460, 370, 41, 31));
        plainTextEdit_51 = new QPlainTextEdit(scrollAreaWidgetContents);
        plainTextEdit_51->setObjectName("plainTextEdit_51");
        plainTextEdit_51->setGeometry(QRect(460, 50, 41, 31));
        plainTextEdit_52 = new QPlainTextEdit(scrollAreaWidgetContents);
        plainTextEdit_52->setObjectName("plainTextEdit_52");
        plainTextEdit_52->setGeometry(QRect(400, 210, 41, 31));
        plainTextEdit_53 = new QPlainTextEdit(scrollAreaWidgetContents);
        plainTextEdit_53->setObjectName("plainTextEdit_53");
        plainTextEdit_53->setGeometry(QRect(400, 10, 41, 31));
        plainTextEdit_54 = new QPlainTextEdit(scrollAreaWidgetContents);
        plainTextEdit_54->setObjectName("plainTextEdit_54");
        plainTextEdit_54->setGeometry(QRect(400, 130, 41, 31));
        plainTextEdit_55 = new QPlainTextEdit(scrollAreaWidgetContents);
        plainTextEdit_55->setObjectName("plainTextEdit_55");
        plainTextEdit_55->setGeometry(QRect(400, 370, 41, 31));
        scrollArea->setWidget(scrollAreaWidgetContents);
        label_19 = new QLabel(page_3);
        label_19->setObjectName("label_19");
        label_19->setGeometry(QRect(10, 40, 61, 31));
        label_20 = new QLabel(page_3);
        label_20->setObjectName("label_20");
        label_20->setGeometry(QRect(70, 40, 61, 31));
        label_21 = new QLabel(page_3);
        label_21->setObjectName("label_21");
        label_21->setGeometry(QRect(400, 40, 61, 31));
        label_22 = new QLabel(page_3);
        label_22->setObjectName("label_22");
        label_22->setGeometry(QRect(450, 40, 61, 31));
        label_23 = new QLabel(page_3);
        label_23->setObjectName("label_23");
        label_23->setGeometry(QRect(230, 40, 41, 31));
        stackedWidget->addWidget(page_3);
        CameraZoneButton = new QPushButton(PaperTrackMainWindow);
        CameraZoneButton->setObjectName("CameraZoneButton");
        CameraZoneButton->setGeometry(QRect(30, 20, 75, 23));
        SettingsZoneButton = new QPushButton(PaperTrackMainWindow);
        SettingsZoneButton->setObjectName("SettingsZoneButton");
        SettingsZoneButton->setGeometry(QRect(160, 20, 75, 23));
        CalibrationZoneButton = new QPushButton(PaperTrackMainWindow);
        CalibrationZoneButton->setObjectName("CalibrationZoneButton");
        CalibrationZoneButton->setGeometry(QRect(290, 20, 91, 23));

        retranslateUi(PaperTrackMainWindow);

        stackedWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(PaperTrackMainWindow);
    } // setupUi

    void retranslateUi(QWidget *PaperTrackMainWindow)
    {
        PaperTrackMainWindow->setWindowTitle(QCoreApplication::translate("PaperTrackMainWindow", "PaperTrack", nullptr));
        VerticalFlipBox->setText(QCoreApplication::translate("PaperTrackMainWindow", "\347\253\226\347\233\264\345\217\215\350\275\254", nullptr));
        TrackModeButton->setText(QCoreApplication::translate("PaperTrackMainWindow", "\350\267\237\350\270\252\346\250\241\345\274\217", nullptr));
        label->setText(QCoreApplication::translate("PaperTrackMainWindow", "\347\233\270\346\234\272\345\234\260\345\235\200", nullptr));
        ModeLabel->setText(QCoreApplication::translate("PaperTrackMainWindow", "\346\227\240", nullptr));
        EnableCalibrationBox->setText(QCoreApplication::translate("PaperTrackMainWindow", "\345\220\257\345\212\250\346\240\207\345\256\232", nullptr));
        label_2->setText(QCoreApplication::translate("PaperTrackMainWindow", "\345\233\276\345\203\217\346\227\213\350\275\254\350\247\222\345\272\246", nullptr));
        StartCalibrationButton->setText(QCoreApplication::translate("PaperTrackMainWindow", "\345\274\200\345\247\213\346\240\207\345\256\232", nullptr));
        HorizontalFlipBox->setText(QCoreApplication::translate("PaperTrackMainWindow", "\346\260\264\345\271\263\345\217\215\350\275\254", nullptr));
        CutOffModeButton->setText(QCoreApplication::translate("PaperTrackMainWindow", "\345\211\252\350\243\201\346\250\241\345\274\217", nullptr));
        label_3->setText(QCoreApplication::translate("PaperTrackMainWindow", "\345\275\223\345\211\215\346\250\241\345\274\217\357\274\232", nullptr));
        SaveAndRestartButton->setText(QCoreApplication::translate("PaperTrackMainWindow", "\344\277\235\345\255\230\345\271\266\351\207\215\345\220\257", nullptr));
        RefreshCameraListButton->setText(QCoreApplication::translate("PaperTrackMainWindow", "\345\210\267\346\226\260\347\233\270\346\234\272\345\210\227\350\241\250", nullptr));
        StopCalibrationButton->setText(QCoreApplication::translate("PaperTrackMainWindow", "\345\201\234\346\255\242\346\240\207\345\256\232", nullptr));
        label_5->setText(QCoreApplication::translate("PaperTrackMainWindow", "\351\200\232\347\224\250\350\256\276\347\275\256", nullptr));
        CheckUpdateBox->setText(QCoreApplication::translate("PaperTrackMainWindow", "\346\243\200\346\237\245\346\233\264\346\226\260", nullptr));
        label_6->setText(QCoreApplication::translate("PaperTrackMainWindow", "OSC\350\256\276\347\275\256", nullptr));
        label_7->setText(QCoreApplication::translate("PaperTrackMainWindow", "\344\275\215\347\275\256\345\211\215\347\274\200\357\274\232", nullptr));
        label_8->setText(QCoreApplication::translate("PaperTrackMainWindow", "ip\345\234\260\345\235\200\357\274\232", nullptr));
        label_9->setText(QCoreApplication::translate("PaperTrackMainWindow", "\347\253\257\345\217\243\357\274\232", nullptr));
        StartReceiveBox->setText(QCoreApplication::translate("PaperTrackMainWindow", "\345\220\257\345\212\250\346\216\245\346\224\266\345\207\275\346\225\260", nullptr));
        label_10->setText(QCoreApplication::translate("PaperTrackMainWindow", "\346\216\245\346\224\266\345\207\275\346\225\260\350\256\276\347\275\256\357\274\232", nullptr));
        label_11->setText(QCoreApplication::translate("PaperTrackMainWindow", "\351\207\215\346\240\207\345\256\232\345\234\260\345\235\200\357\274\232", nullptr));
        CloseCameraOutputBox->setText(QCoreApplication::translate("PaperTrackMainWindow", "\345\205\263\351\227\255\347\233\270\346\234\272\345\233\276\345\203\217\346\230\276\347\244\272\357\274\210\345\234\250\346\211\200\346\234\211\347\225\214\351\235\242\357\274\211", nullptr));
        StartOSCBox->setText(QCoreApplication::translate("PaperTrackMainWindow", "\345\220\257\345\212\250OSC\345\273\266\350\277\237", nullptr));
        label_12->setText(QCoreApplication::translate("PaperTrackMainWindow", "OSC\345\273\266\346\227\266\345\200\274\357\274\210\345\215\225\344\275\215\344\270\272\347\247\222\357\274\211\357\274\232", nullptr));
        label_13->setText(QCoreApplication::translate("PaperTrackMainWindow", "UVC\347\233\270\346\234\272\350\256\276\347\275\256\357\274\232", nullptr));
        checkBox_8->setText(QCoreApplication::translate("PaperTrackMainWindow", "\344\275\277\347\224\250\347\272\242\350\211\262\351\200\232\351\201\223", nullptr));
        label_14->setText(QCoreApplication::translate("PaperTrackMainWindow", "\346\260\264\345\271\263\345\210\206\350\276\250\347\216\207\357\274\232", nullptr));
        label_15->setText(QCoreApplication::translate("PaperTrackMainWindow", "\345\236\202\347\233\264\345\210\206\350\276\250\347\216\207\357\274\232", nullptr));
        label_16->setText(QCoreApplication::translate("PaperTrackMainWindow", "FPS\357\274\232", nullptr));
        XResolutionInput->setPlainText(QCoreApplication::translate("PaperTrackMainWindow", "0", nullptr));
        YResolutionInput->setPlainText(QCoreApplication::translate("PaperTrackMainWindow", "0", nullptr));
        FPSInput->setPlainText(QCoreApplication::translate("PaperTrackMainWindow", "0", nullptr));
        OSCDelayInput->setPlainText(QCoreApplication::translate("PaperTrackMainWindow", "0", nullptr));
        ReCalibrateAddressInput->setPlainText(QString());
        IPInput->setPlainText(QString());
        PortInput->setPlainText(QString());
        LocationPrefixInput->setPlainText(QString());
        label_25->setText(QCoreApplication::translate("PaperTrackMainWindow", "\346\250\241\345\236\213\350\256\276\347\275\256", nullptr));
        label_26->setText(QCoreApplication::translate("PaperTrackMainWindow", "\346\250\241\345\236\213\346\226\207\344\273\266\350\267\257\345\276\204\357\274\232", nullptr));
        ModelPathInput->setPlainText(QString());
        ModelPathFindButton->setText(QCoreApplication::translate("PaperTrackMainWindow", "\346\237\245\346\211\276\346\226\207\344\273\266", nullptr));
        label_27->setText(QCoreApplication::translate("PaperTrackMainWindow", "\346\216\250\347\220\206\347\272\277\347\250\213\346\225\260\357\274\232", nullptr));
        InferenceThreadsInput->setPlainText(QCoreApplication::translate("PaperTrackMainWindow", "0", nullptr));
        label_28->setText(QCoreApplication::translate("PaperTrackMainWindow", "GPU\347\274\226\345\217\267\357\274\232", nullptr));
        GPUInput->setPlainText(QCoreApplication::translate("PaperTrackMainWindow", "0", nullptr));
        UseGPUBox->setText(QCoreApplication::translate("PaperTrackMainWindow", "\344\275\277\347\224\250GPU\346\216\250\347\220\206", nullptr));
        label_29->setText(QCoreApplication::translate("PaperTrackMainWindow", "\346\250\241\345\236\213\350\276\223\345\207\272\345\242\236\347\233\212\357\274\210X\357\274\211\357\274\232", nullptr));
        ModelOutputMultiplierInput->setPlainText(QCoreApplication::translate("PaperTrackMainWindow", "1.0\n"
"", nullptr));
        label_30->setText(QCoreApplication::translate("PaperTrackMainWindow", "\346\240\207\345\256\232\346\255\273\345\214\272\357\274\232", nullptr));
        CalibrationDeadZoneInput->setPlainText(QCoreApplication::translate("PaperTrackMainWindow", "-0.1", nullptr));
        label_31->setText(QCoreApplication::translate("PaperTrackMainWindow", "\346\273\244\346\263\242\345\217\202\346\225\260", nullptr));
        label_32->setText(QCoreApplication::translate("PaperTrackMainWindow", "\346\234\200\345\260\217\351\242\221\347\216\207\346\210\252\346\226\255\357\274\232", nullptr));
        MinFreqCutOffInput->setPlainText(QCoreApplication::translate("PaperTrackMainWindow", "0.9\n"
"", nullptr));
        label_33->setText(QCoreApplication::translate("PaperTrackMainWindow", "\351\200\237\345\272\246\347\263\273\346\225\260\357\274\232", nullptr));
        SpeedCoeffInput->setPlainText(QCoreApplication::translate("PaperTrackMainWindow", "0.9\n"
"", nullptr));
        ReceiveFunctionInput->setPlainText(QCoreApplication::translate("PaperTrackMainWindow", "0", nullptr));
        label_17->setText(QCoreApplication::translate("PaperTrackMainWindow", "\346\240\207\345\256\232\350\256\276\347\275\256\357\274\232", nullptr));
        label_18->setText(QCoreApplication::translate("PaperTrackMainWindow", "\346\240\207\345\256\232\346\250\241\345\274\217\357\274\232", nullptr));
        label_24->setText(QCoreApplication::translate("PaperTrackMainWindow", "\346\217\217\350\277\260", nullptr));
        plainTextEdit_16->setPlainText(QCoreApplication::translate("PaperTrackMainWindow", "0", nullptr));
        plainTextEdit_17->setPlainText(QCoreApplication::translate("PaperTrackMainWindow", "0", nullptr));
        plainTextEdit_18->setPlainText(QCoreApplication::translate("PaperTrackMainWindow", "0", nullptr));
        plainTextEdit_19->setPlainText(QCoreApplication::translate("PaperTrackMainWindow", "0", nullptr));
        plainTextEdit_20->setPlainText(QCoreApplication::translate("PaperTrackMainWindow", "0", nullptr));
        plainTextEdit_21->setPlainText(QCoreApplication::translate("PaperTrackMainWindow", "0", nullptr));
        plainTextEdit_22->setPlainText(QCoreApplication::translate("PaperTrackMainWindow", "0", nullptr));
        plainTextEdit_23->setPlainText(QCoreApplication::translate("PaperTrackMainWindow", "0", nullptr));
        plainTextEdit_24->setPlainText(QCoreApplication::translate("PaperTrackMainWindow", "0", nullptr));
        plainTextEdit_25->setPlainText(QCoreApplication::translate("PaperTrackMainWindow", "0", nullptr));
        plainTextEdit_26->setPlainText(QCoreApplication::translate("PaperTrackMainWindow", "0", nullptr));
        plainTextEdit_27->setPlainText(QCoreApplication::translate("PaperTrackMainWindow", "0", nullptr));
        plainTextEdit_28->setPlainText(QCoreApplication::translate("PaperTrackMainWindow", "0", nullptr));
        plainTextEdit_29->setPlainText(QCoreApplication::translate("PaperTrackMainWindow", "0", nullptr));
        plainTextEdit_30->setPlainText(QCoreApplication::translate("PaperTrackMainWindow", "0", nullptr));
        plainTextEdit_31->setPlainText(QCoreApplication::translate("PaperTrackMainWindow", "0", nullptr));
        plainTextEdit_32->setPlainText(QCoreApplication::translate("PaperTrackMainWindow", "0", nullptr));
        plainTextEdit_33->setPlainText(QCoreApplication::translate("PaperTrackMainWindow", "0", nullptr));
        plainTextEdit_34->setPlainText(QCoreApplication::translate("PaperTrackMainWindow", "0", nullptr));
        plainTextEdit_35->setPlainText(QCoreApplication::translate("PaperTrackMainWindow", "0", nullptr));
        plainTextEdit_36->setPlainText(QCoreApplication::translate("PaperTrackMainWindow", "0", nullptr));
        plainTextEdit_37->setPlainText(QCoreApplication::translate("PaperTrackMainWindow", "0", nullptr));
        plainTextEdit_38->setPlainText(QCoreApplication::translate("PaperTrackMainWindow", "0", nullptr));
        plainTextEdit_39->setPlainText(QCoreApplication::translate("PaperTrackMainWindow", "0", nullptr));
        plainTextEdit_40->setPlainText(QCoreApplication::translate("PaperTrackMainWindow", "0", nullptr));
        plainTextEdit_41->setPlainText(QCoreApplication::translate("PaperTrackMainWindow", "0", nullptr));
        plainTextEdit_42->setPlainText(QCoreApplication::translate("PaperTrackMainWindow", "0", nullptr));
        plainTextEdit_43->setPlainText(QCoreApplication::translate("PaperTrackMainWindow", "0", nullptr));
        plainTextEdit_44->setPlainText(QCoreApplication::translate("PaperTrackMainWindow", "0", nullptr));
        plainTextEdit_45->setPlainText(QCoreApplication::translate("PaperTrackMainWindow", "0", nullptr));
        plainTextEdit_46->setPlainText(QCoreApplication::translate("PaperTrackMainWindow", "0", nullptr));
        plainTextEdit_47->setPlainText(QCoreApplication::translate("PaperTrackMainWindow", "0", nullptr));
        plainTextEdit_48->setPlainText(QCoreApplication::translate("PaperTrackMainWindow", "0", nullptr));
        plainTextEdit_49->setPlainText(QCoreApplication::translate("PaperTrackMainWindow", "0", nullptr));
        plainTextEdit_50->setPlainText(QCoreApplication::translate("PaperTrackMainWindow", "0", nullptr));
        plainTextEdit_51->setPlainText(QCoreApplication::translate("PaperTrackMainWindow", "0", nullptr));
        plainTextEdit_52->setPlainText(QCoreApplication::translate("PaperTrackMainWindow", "0", nullptr));
        plainTextEdit_53->setPlainText(QCoreApplication::translate("PaperTrackMainWindow", "0", nullptr));
        plainTextEdit_54->setPlainText(QCoreApplication::translate("PaperTrackMainWindow", "0", nullptr));
        plainTextEdit_55->setPlainText(QCoreApplication::translate("PaperTrackMainWindow", "0", nullptr));
        label_19->setText(QCoreApplication::translate("PaperTrackMainWindow", "\346\234\200\345\260\217\345\200\274", nullptr));
        label_20->setText(QCoreApplication::translate("PaperTrackMainWindow", "\346\234\200\345\244\247\345\200\274", nullptr));
        label_21->setText(QCoreApplication::translate("PaperTrackMainWindow", "\346\234\200\345\260\217\345\200\274", nullptr));
        label_22->setText(QCoreApplication::translate("PaperTrackMainWindow", "\346\234\200\345\244\247\345\200\274", nullptr));
        label_23->setText(QCoreApplication::translate("PaperTrackMainWindow", "\346\217\217\350\277\260", nullptr));
        CameraZoneButton->setText(QCoreApplication::translate("PaperTrackMainWindow", "\347\233\270\346\234\272", nullptr));
        SettingsZoneButton->setText(QCoreApplication::translate("PaperTrackMainWindow", "\350\256\276\347\275\256", nullptr));
        CalibrationZoneButton->setText(QCoreApplication::translate("PaperTrackMainWindow", "\346\240\207\345\256\232", nullptr));
    } // retranslateUi

};

namespace Ui {
    class PaperTrackMainWindow: public Ui_PaperTrackMainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAIN_WINDOW_H
