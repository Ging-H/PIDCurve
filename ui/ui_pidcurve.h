/********************************************************************************
** Form generated from reading UI file 'pidcurve.ui'
**
** Created by: Qt User Interface Compiler version 5.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PIDCURVE_H
#define UI_PIDCURVE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSplitter>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QWidget>
#include "qcustomplot.h"

QT_BEGIN_NAMESPACE

class Ui_PIDCurve
{
public:
    QGridLayout *gridLayout_7;
    QSplitter *splitter;
    QWidget *layoutWidget;
    QGridLayout *gridLayout;
    QGroupBox *QGBSerialConfig;
    QGridLayout *gridLayout_4;
    QGridLayout *gridLayout_3;
    QLabel *lblVerify;
    QComboBox *cbbDataBit;
    QLabel *lblPortNum;
    QLabel *lblStopBit;
    QLabel *lblBaudRate;
    QComboBox *cbbPortNum;
    QComboBox *cbbVerify;
    QComboBox *cbbStopBit;
    QComboBox *cbbBaud;
    QLabel *lblDataBit;
    QPushButton *btnRefresh;
    QPushButton *btnOpenPort;
    QGroupBox *gpbGraph1;
    QGridLayout *gridLayout_2;
    QLabel *lblCurve11D;
    QDoubleSpinBox *spbCurve1D;
    QLineEdit *txtCurve1Tartget;
    QLabel *lblCurve1Target;
    QLabel *lblCurve11P;
    QDoubleSpinBox *spbCurve1I;
    QLabel *lblCurve11I;
    QPushButton *btnCurve1;
    QPushButton *btnCurve1PID;
    QDoubleSpinBox *spbCurve1P;
    QGroupBox *gpbGraph2;
    QGridLayout *gridLayout_5;
    QDoubleSpinBox *spbCurve2P;
    QLabel *label_6;
    QDoubleSpinBox *spbCurve2I;
    QLabel *label_7;
    QDoubleSpinBox *spbCurve2D;
    QLabel *label_8;
    QLineEdit *txtCurve2Tartget;
    QPushButton *btnCurve2PID;
    QPushButton *btnCurve2;
    QLabel *label_5;
    QGroupBox *gpbGraph3;
    QGridLayout *gridLayout_6;
    QLabel *label_9;
    QDoubleSpinBox *spbCurve3P;
    QLabel *label_10;
    QDoubleSpinBox *spbCurve3I;
    QLabel *label_11;
    QDoubleSpinBox *spbCurve3D;
    QLabel *label_12;
    QLineEdit *txtCurve3Tartget;
    QPushButton *btnCurve3PID;
    QPushButton *btnCurve3;
    QTextBrowser *textBrowser;
    QHBoxLayout *horizontalLayout;
    QPushButton *btnStartMotor;
    QPushButton *btnReset;
    QPushButton *btnClearChart;
    QPushButton *btnSaveCurve;
    QPushButton *btnProtocol;
    QPushButton *btnCurveBG;
    QCustomPlot *customPlot;

    void setupUi(QWidget *PIDCurve)
    {
        if (PIDCurve->objectName().isEmpty())
            PIDCurve->setObjectName(QStringLiteral("PIDCurve"));
        PIDCurve->resize(798, 515);
        gridLayout_7 = new QGridLayout(PIDCurve);
        gridLayout_7->setSpacing(6);
        gridLayout_7->setContentsMargins(11, 11, 11, 11);
        gridLayout_7->setObjectName(QStringLiteral("gridLayout_7"));
        splitter = new QSplitter(PIDCurve);
        splitter->setObjectName(QStringLiteral("splitter"));
        splitter->setOrientation(Qt::Vertical);
        splitter->setChildrenCollapsible(false);
        layoutWidget = new QWidget(splitter);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        gridLayout = new QGridLayout(layoutWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        QGBSerialConfig = new QGroupBox(layoutWidget);
        QGBSerialConfig->setObjectName(QStringLiteral("QGBSerialConfig"));
        QGBSerialConfig->setEnabled(true);
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(QGBSerialConfig->sizePolicy().hasHeightForWidth());
        QGBSerialConfig->setSizePolicy(sizePolicy);
        QGBSerialConfig->setMinimumSize(QSize(171, 0));
        QGBSerialConfig->setMaximumSize(QSize(171, 16777215));
        QGBSerialConfig->setStyleSheet(QStringLiteral(""));
        QGBSerialConfig->setFlat(false);
        QGBSerialConfig->setCheckable(false);
        gridLayout_4 = new QGridLayout(QGBSerialConfig);
        gridLayout_4->setSpacing(6);
        gridLayout_4->setContentsMargins(11, 11, 11, 11);
        gridLayout_4->setObjectName(QStringLiteral("gridLayout_4"));
        gridLayout_4->setHorizontalSpacing(2);
        gridLayout_4->setVerticalSpacing(6);
        gridLayout_4->setContentsMargins(3, 3, 3, 3);
        gridLayout_3 = new QGridLayout();
        gridLayout_3->setSpacing(6);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        gridLayout_3->setHorizontalSpacing(3);
        gridLayout_3->setVerticalSpacing(6);
        lblVerify = new QLabel(QGBSerialConfig);
        lblVerify->setObjectName(QStringLiteral("lblVerify"));

        gridLayout_3->addWidget(lblVerify, 3, 0, 1, 1);

        cbbDataBit = new QComboBox(QGBSerialConfig);
        cbbDataBit->setObjectName(QStringLiteral("cbbDataBit"));
        cbbDataBit->setSizeAdjustPolicy(QComboBox::AdjustToContents);

        gridLayout_3->addWidget(cbbDataBit, 2, 1, 1, 1);

        lblPortNum = new QLabel(QGBSerialConfig);
        lblPortNum->setObjectName(QStringLiteral("lblPortNum"));

        gridLayout_3->addWidget(lblPortNum, 0, 0, 1, 1);

        lblStopBit = new QLabel(QGBSerialConfig);
        lblStopBit->setObjectName(QStringLiteral("lblStopBit"));

        gridLayout_3->addWidget(lblStopBit, 4, 0, 1, 1);

        lblBaudRate = new QLabel(QGBSerialConfig);
        lblBaudRate->setObjectName(QStringLiteral("lblBaudRate"));

        gridLayout_3->addWidget(lblBaudRate, 1, 0, 1, 1);

        cbbPortNum = new QComboBox(QGBSerialConfig);
        cbbPortNum->setObjectName(QStringLiteral("cbbPortNum"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(cbbPortNum->sizePolicy().hasHeightForWidth());
        cbbPortNum->setSizePolicy(sizePolicy1);
        cbbPortNum->setMaxVisibleItems(20);
        cbbPortNum->setSizeAdjustPolicy(QComboBox::AdjustToContents);
        cbbPortNum->setMinimumContentsLength(0);

        gridLayout_3->addWidget(cbbPortNum, 0, 1, 1, 1);

        cbbVerify = new QComboBox(QGBSerialConfig);
        cbbVerify->setObjectName(QStringLiteral("cbbVerify"));
        cbbVerify->setSizeAdjustPolicy(QComboBox::AdjustToContents);

        gridLayout_3->addWidget(cbbVerify, 3, 1, 1, 1);

        cbbStopBit = new QComboBox(QGBSerialConfig);
        cbbStopBit->setObjectName(QStringLiteral("cbbStopBit"));
        cbbStopBit->setSizeAdjustPolicy(QComboBox::AdjustToContents);

        gridLayout_3->addWidget(cbbStopBit, 4, 1, 1, 1);

        cbbBaud = new QComboBox(QGBSerialConfig);
        cbbBaud->setObjectName(QStringLiteral("cbbBaud"));
        cbbBaud->setSizeAdjustPolicy(QComboBox::AdjustToContents);

        gridLayout_3->addWidget(cbbBaud, 1, 1, 1, 1);

        lblDataBit = new QLabel(QGBSerialConfig);
        lblDataBit->setObjectName(QStringLiteral("lblDataBit"));

        gridLayout_3->addWidget(lblDataBit, 2, 0, 1, 1);


        gridLayout_4->addLayout(gridLayout_3, 0, 0, 1, 2);

        btnRefresh = new QPushButton(QGBSerialConfig);
        btnRefresh->setObjectName(QStringLiteral("btnRefresh"));
        QSizePolicy sizePolicy2(QSizePolicy::Expanding, QSizePolicy::Minimum);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(btnRefresh->sizePolicy().hasHeightForWidth());
        btnRefresh->setSizePolicy(sizePolicy2);
        btnRefresh->setMaximumSize(QSize(57, 16777215));
        QIcon icon;
        icon.addFile(QStringLiteral(":/action/action/refresh.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnRefresh->setIcon(icon);
        btnRefresh->setIconSize(QSize(32, 32));

        gridLayout_4->addWidget(btnRefresh, 1, 0, 1, 1);

        btnOpenPort = new QPushButton(QGBSerialConfig);
        btnOpenPort->setObjectName(QStringLiteral("btnOpenPort"));
        btnOpenPort->setEnabled(true);
        QSizePolicy sizePolicy3(QSizePolicy::Expanding, QSizePolicy::Minimum);
        sizePolicy3.setHorizontalStretch(2);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(btnOpenPort->sizePolicy().hasHeightForWidth());
        btnOpenPort->setSizePolicy(sizePolicy3);
        btnOpenPort->setStyleSheet(QStringLiteral(""));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/general/general/com_disconnect.png"), QSize(), QIcon::Normal, QIcon::Off);
        icon1.addFile(QStringLiteral(":/general/general/com_connect.png"), QSize(), QIcon::Normal, QIcon::On);
        btnOpenPort->setIcon(icon1);
        btnOpenPort->setIconSize(QSize(32, 32));
        btnOpenPort->setCheckable(true);
        btnOpenPort->setChecked(false);
        btnOpenPort->setAutoDefault(false);
        btnOpenPort->setFlat(false);

        gridLayout_4->addWidget(btnOpenPort, 1, 1, 1, 1);


        gridLayout->addWidget(QGBSerialConfig, 0, 0, 1, 1);

        gpbGraph1 = new QGroupBox(layoutWidget);
        gpbGraph1->setObjectName(QStringLiteral("gpbGraph1"));
        gpbGraph1->setEnabled(true);
        sizePolicy.setHeightForWidth(gpbGraph1->sizePolicy().hasHeightForWidth());
        gpbGraph1->setSizePolicy(sizePolicy);
        gpbGraph1->setMinimumSize(QSize(0, 0));
        gpbGraph1->setMaximumSize(QSize(171, 16777215));
        gpbGraph1->setCheckable(true);
        gridLayout_2 = new QGridLayout(gpbGraph1);
        gridLayout_2->setSpacing(2);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        gridLayout_2->setContentsMargins(3, 3, 3, 3);
        lblCurve11D = new QLabel(gpbGraph1);
        lblCurve11D->setObjectName(QStringLiteral("lblCurve11D"));
        QFont font;
        font.setPointSize(10);
        lblCurve11D->setFont(font);
        lblCurve11D->setAlignment(Qt::AlignCenter);

        gridLayout_2->addWidget(lblCurve11D, 2, 0, 1, 1);

        spbCurve1D = new QDoubleSpinBox(gpbGraph1);
        spbCurve1D->setObjectName(QStringLiteral("spbCurve1D"));
        QFont font1;
        font1.setPointSize(11);
        spbCurve1D->setFont(font1);
        spbCurve1D->setButtonSymbols(QAbstractSpinBox::NoButtons);

        gridLayout_2->addWidget(spbCurve1D, 2, 1, 1, 2);

        txtCurve1Tartget = new QLineEdit(gpbGraph1);
        txtCurve1Tartget->setObjectName(QStringLiteral("txtCurve1Tartget"));
        txtCurve1Tartget->setFont(font1);
        txtCurve1Tartget->setMaxLength(999999999);
        txtCurve1Tartget->setClearButtonEnabled(false);

        gridLayout_2->addWidget(txtCurve1Tartget, 3, 1, 1, 2);

        lblCurve1Target = new QLabel(gpbGraph1);
        lblCurve1Target->setObjectName(QStringLiteral("lblCurve1Target"));
        lblCurve1Target->setFont(font);
        lblCurve1Target->setAlignment(Qt::AlignCenter);

        gridLayout_2->addWidget(lblCurve1Target, 3, 0, 1, 1);

        lblCurve11P = new QLabel(gpbGraph1);
        lblCurve11P->setObjectName(QStringLiteral("lblCurve11P"));
        lblCurve11P->setFont(font);
        lblCurve11P->setAlignment(Qt::AlignCenter);

        gridLayout_2->addWidget(lblCurve11P, 0, 0, 1, 1);

        spbCurve1I = new QDoubleSpinBox(gpbGraph1);
        spbCurve1I->setObjectName(QStringLiteral("spbCurve1I"));
        spbCurve1I->setFont(font1);
        spbCurve1I->setButtonSymbols(QAbstractSpinBox::NoButtons);

        gridLayout_2->addWidget(spbCurve1I, 1, 1, 1, 2);

        lblCurve11I = new QLabel(gpbGraph1);
        lblCurve11I->setObjectName(QStringLiteral("lblCurve11I"));
        lblCurve11I->setFont(font);
        lblCurve11I->setAlignment(Qt::AlignCenter);

        gridLayout_2->addWidget(lblCurve11I, 1, 0, 1, 1);

        btnCurve1 = new QPushButton(gpbGraph1);
        btnCurve1->setObjectName(QStringLiteral("btnCurve1"));
        btnCurve1->setFont(font);

        gridLayout_2->addWidget(btnCurve1, 4, 2, 1, 1);

        btnCurve1PID = new QPushButton(gpbGraph1);
        btnCurve1PID->setObjectName(QStringLiteral("btnCurve1PID"));
        btnCurve1PID->setFont(font);

        gridLayout_2->addWidget(btnCurve1PID, 4, 0, 1, 2);

        spbCurve1P = new QDoubleSpinBox(gpbGraph1);
        spbCurve1P->setObjectName(QStringLiteral("spbCurve1P"));
        spbCurve1P->setFont(font1);
        spbCurve1P->setButtonSymbols(QAbstractSpinBox::NoButtons);
        spbCurve1P->setMaximum(999999);
        spbCurve1P->setSingleStep(0.01);

        gridLayout_2->addWidget(spbCurve1P, 0, 1, 1, 2);

        lblCurve11P->raise();
        lblCurve11I->raise();
        lblCurve11D->raise();
        lblCurve1Target->raise();
        btnCurve1->raise();
        txtCurve1Tartget->raise();
        spbCurve1D->raise();
        spbCurve1P->raise();
        spbCurve1I->raise();
        btnCurve1PID->raise();

        gridLayout->addWidget(gpbGraph1, 0, 1, 1, 1);

        gpbGraph2 = new QGroupBox(layoutWidget);
        gpbGraph2->setObjectName(QStringLiteral("gpbGraph2"));
        gpbGraph2->setEnabled(true);
        sizePolicy.setHeightForWidth(gpbGraph2->sizePolicy().hasHeightForWidth());
        gpbGraph2->setSizePolicy(sizePolicy);
        gpbGraph2->setMinimumSize(QSize(0, 0));
        gpbGraph2->setMaximumSize(QSize(171, 16777215));
        QFont font2;
        font2.setPointSize(9);
        gpbGraph2->setFont(font2);
        gpbGraph2->setCheckable(true);
        gpbGraph2->setChecked(false);
        gridLayout_5 = new QGridLayout(gpbGraph2);
        gridLayout_5->setSpacing(2);
        gridLayout_5->setContentsMargins(11, 11, 11, 11);
        gridLayout_5->setObjectName(QStringLiteral("gridLayout_5"));
        gridLayout_5->setContentsMargins(3, 3, 3, 3);
        spbCurve2P = new QDoubleSpinBox(gpbGraph2);
        spbCurve2P->setObjectName(QStringLiteral("spbCurve2P"));
        spbCurve2P->setFont(font1);
        spbCurve2P->setButtonSymbols(QAbstractSpinBox::NoButtons);

        gridLayout_5->addWidget(spbCurve2P, 0, 1, 1, 2);

        label_6 = new QLabel(gpbGraph2);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setFont(font);
        label_6->setAlignment(Qt::AlignCenter);

        gridLayout_5->addWidget(label_6, 1, 0, 1, 1);

        spbCurve2I = new QDoubleSpinBox(gpbGraph2);
        spbCurve2I->setObjectName(QStringLiteral("spbCurve2I"));
        spbCurve2I->setFont(font1);
        spbCurve2I->setButtonSymbols(QAbstractSpinBox::NoButtons);

        gridLayout_5->addWidget(spbCurve2I, 1, 1, 1, 2);

        label_7 = new QLabel(gpbGraph2);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setFont(font);
        label_7->setAlignment(Qt::AlignCenter);

        gridLayout_5->addWidget(label_7, 2, 0, 1, 1);

        spbCurve2D = new QDoubleSpinBox(gpbGraph2);
        spbCurve2D->setObjectName(QStringLiteral("spbCurve2D"));
        spbCurve2D->setFont(font1);
        spbCurve2D->setButtonSymbols(QAbstractSpinBox::NoButtons);

        gridLayout_5->addWidget(spbCurve2D, 2, 1, 1, 2);

        label_8 = new QLabel(gpbGraph2);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setFont(font);
        label_8->setAlignment(Qt::AlignCenter);

        gridLayout_5->addWidget(label_8, 3, 0, 1, 1);

        txtCurve2Tartget = new QLineEdit(gpbGraph2);
        txtCurve2Tartget->setObjectName(QStringLiteral("txtCurve2Tartget"));
        txtCurve2Tartget->setFont(font1);

        gridLayout_5->addWidget(txtCurve2Tartget, 3, 1, 1, 2);

        btnCurve2PID = new QPushButton(gpbGraph2);
        btnCurve2PID->setObjectName(QStringLiteral("btnCurve2PID"));
        btnCurve2PID->setFont(font);

        gridLayout_5->addWidget(btnCurve2PID, 4, 0, 1, 2);

        btnCurve2 = new QPushButton(gpbGraph2);
        btnCurve2->setObjectName(QStringLiteral("btnCurve2"));
        btnCurve2->setFont(font);

        gridLayout_5->addWidget(btnCurve2, 4, 2, 1, 1);

        label_5 = new QLabel(gpbGraph2);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setFont(font);
        label_5->setAlignment(Qt::AlignCenter);

        gridLayout_5->addWidget(label_5, 0, 0, 1, 1);

        label_5->raise();
        label_6->raise();
        label_7->raise();
        label_8->raise();
        btnCurve2->raise();
        spbCurve2I->raise();
        spbCurve2P->raise();
        txtCurve2Tartget->raise();
        spbCurve2D->raise();
        btnCurve2PID->raise();

        gridLayout->addWidget(gpbGraph2, 0, 2, 1, 1);

        gpbGraph3 = new QGroupBox(layoutWidget);
        gpbGraph3->setObjectName(QStringLiteral("gpbGraph3"));
        gpbGraph3->setEnabled(true);
        sizePolicy.setHeightForWidth(gpbGraph3->sizePolicy().hasHeightForWidth());
        gpbGraph3->setSizePolicy(sizePolicy);
        gpbGraph3->setMinimumSize(QSize(0, 0));
        gpbGraph3->setMaximumSize(QSize(171, 16777215));
        gpbGraph3->setFont(font2);
        gpbGraph3->setCheckable(true);
        gpbGraph3->setChecked(false);
        gridLayout_6 = new QGridLayout(gpbGraph3);
        gridLayout_6->setSpacing(2);
        gridLayout_6->setContentsMargins(11, 11, 11, 11);
        gridLayout_6->setObjectName(QStringLiteral("gridLayout_6"));
        gridLayout_6->setContentsMargins(3, 3, 3, 3);
        label_9 = new QLabel(gpbGraph3);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setFont(font);
        label_9->setAlignment(Qt::AlignCenter);

        gridLayout_6->addWidget(label_9, 0, 0, 1, 1);

        spbCurve3P = new QDoubleSpinBox(gpbGraph3);
        spbCurve3P->setObjectName(QStringLiteral("spbCurve3P"));
        spbCurve3P->setMinimumSize(QSize(0, 0));
        spbCurve3P->setMaximumSize(QSize(16777215, 16777215));
        spbCurve3P->setFont(font1);
        spbCurve3P->setButtonSymbols(QAbstractSpinBox::NoButtons);

        gridLayout_6->addWidget(spbCurve3P, 0, 1, 1, 2);

        label_10 = new QLabel(gpbGraph3);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setFont(font);
        label_10->setAlignment(Qt::AlignCenter);

        gridLayout_6->addWidget(label_10, 1, 0, 1, 1);

        spbCurve3I = new QDoubleSpinBox(gpbGraph3);
        spbCurve3I->setObjectName(QStringLiteral("spbCurve3I"));
        spbCurve3I->setMinimumSize(QSize(0, 0));
        spbCurve3I->setMaximumSize(QSize(16777215, 16777215));
        spbCurve3I->setFont(font1);
        spbCurve3I->setButtonSymbols(QAbstractSpinBox::NoButtons);

        gridLayout_6->addWidget(spbCurve3I, 1, 1, 1, 2);

        label_11 = new QLabel(gpbGraph3);
        label_11->setObjectName(QStringLiteral("label_11"));
        label_11->setFont(font);
        label_11->setAlignment(Qt::AlignCenter);

        gridLayout_6->addWidget(label_11, 2, 0, 1, 1);

        spbCurve3D = new QDoubleSpinBox(gpbGraph3);
        spbCurve3D->setObjectName(QStringLiteral("spbCurve3D"));
        spbCurve3D->setMinimumSize(QSize(0, 0));
        spbCurve3D->setMaximumSize(QSize(16777215, 16777215));
        spbCurve3D->setFont(font1);
        spbCurve3D->setButtonSymbols(QAbstractSpinBox::NoButtons);

        gridLayout_6->addWidget(spbCurve3D, 2, 1, 1, 2);

        label_12 = new QLabel(gpbGraph3);
        label_12->setObjectName(QStringLiteral("label_12"));
        label_12->setFont(font);
        label_12->setAlignment(Qt::AlignCenter);

        gridLayout_6->addWidget(label_12, 3, 0, 1, 1);

        txtCurve3Tartget = new QLineEdit(gpbGraph3);
        txtCurve3Tartget->setObjectName(QStringLiteral("txtCurve3Tartget"));
        txtCurve3Tartget->setMinimumSize(QSize(0, 0));
        txtCurve3Tartget->setMaximumSize(QSize(16777215, 16777215));
        txtCurve3Tartget->setFont(font1);

        gridLayout_6->addWidget(txtCurve3Tartget, 3, 1, 1, 2);

        btnCurve3PID = new QPushButton(gpbGraph3);
        btnCurve3PID->setObjectName(QStringLiteral("btnCurve3PID"));
        btnCurve3PID->setFont(font);

        gridLayout_6->addWidget(btnCurve3PID, 4, 0, 1, 2);

        btnCurve3 = new QPushButton(gpbGraph3);
        btnCurve3->setObjectName(QStringLiteral("btnCurve3"));
        btnCurve3->setFont(font);

        gridLayout_6->addWidget(btnCurve3, 4, 2, 1, 1);

        label_9->raise();
        label_10->raise();
        label_11->raise();
        label_12->raise();
        btnCurve3->raise();
        txtCurve3Tartget->raise();
        spbCurve3P->raise();
        spbCurve3D->raise();
        spbCurve3I->raise();
        btnCurve3PID->raise();

        gridLayout->addWidget(gpbGraph3, 0, 3, 1, 1);

        textBrowser = new QTextBrowser(layoutWidget);
        textBrowser->setObjectName(QStringLiteral("textBrowser"));
        QSizePolicy sizePolicy4(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(textBrowser->sizePolicy().hasHeightForWidth());
        textBrowser->setSizePolicy(sizePolicy4);
        textBrowser->setMinimumSize(QSize(0, 20));
        textBrowser->setMaximumSize(QSize(16777215, 16777215));
        textBrowser->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);

        gridLayout->addWidget(textBrowser, 0, 4, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        btnStartMotor = new QPushButton(layoutWidget);
        btnStartMotor->setObjectName(QStringLiteral("btnStartMotor"));
        btnStartMotor->setFont(font);

        horizontalLayout->addWidget(btnStartMotor);

        btnReset = new QPushButton(layoutWidget);
        btnReset->setObjectName(QStringLiteral("btnReset"));
        btnReset->setFont(font);

        horizontalLayout->addWidget(btnReset);

        btnClearChart = new QPushButton(layoutWidget);
        btnClearChart->setObjectName(QStringLiteral("btnClearChart"));
        btnClearChart->setFont(font);

        horizontalLayout->addWidget(btnClearChart);

        btnSaveCurve = new QPushButton(layoutWidget);
        btnSaveCurve->setObjectName(QStringLiteral("btnSaveCurve"));

        horizontalLayout->addWidget(btnSaveCurve);

        btnProtocol = new QPushButton(layoutWidget);
        btnProtocol->setObjectName(QStringLiteral("btnProtocol"));

        horizontalLayout->addWidget(btnProtocol);

        btnCurveBG = new QPushButton(layoutWidget);
        btnCurveBG->setObjectName(QStringLiteral("btnCurveBG"));
        btnCurveBG->setCheckable(true);

        horizontalLayout->addWidget(btnCurveBG);


        gridLayout->addLayout(horizontalLayout, 1, 0, 1, 3);

        splitter->addWidget(layoutWidget);
        customPlot = new QCustomPlot(splitter);
        customPlot->setObjectName(QStringLiteral("customPlot"));
        QSizePolicy sizePolicy5(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy5.setHorizontalStretch(0);
        sizePolicy5.setVerticalStretch(15);
        sizePolicy5.setHeightForWidth(customPlot->sizePolicy().hasHeightForWidth());
        customPlot->setSizePolicy(sizePolicy5);
        customPlot->setCursor(QCursor(Qt::UpArrowCursor));
        splitter->addWidget(customPlot);

        gridLayout_7->addWidget(splitter, 0, 0, 1, 1);


        retranslateUi(PIDCurve);

        btnOpenPort->setDefault(false);


        QMetaObject::connectSlotsByName(PIDCurve);
    } // setupUi

    void retranslateUi(QWidget *PIDCurve)
    {
        PIDCurve->setWindowTitle(QApplication::translate("PIDCurve", "PidDebugger", Q_NULLPTR));
        QGBSerialConfig->setTitle(QApplication::translate("PIDCurve", "\344\270\262\345\217\243\350\256\276\347\275\256", Q_NULLPTR));
        lblVerify->setText(QApplication::translate("PIDCurve", "\346\240\241\351\252\214", Q_NULLPTR));
        lblPortNum->setText(QApplication::translate("PIDCurve", "\347\253\257\345\217\243\345\217\267", Q_NULLPTR));
        lblStopBit->setText(QApplication::translate("PIDCurve", "\345\201\234\346\255\242\344\275\215", Q_NULLPTR));
        lblBaudRate->setText(QApplication::translate("PIDCurve", "\346\263\242\347\211\271\347\216\207", Q_NULLPTR));
        lblDataBit->setText(QApplication::translate("PIDCurve", "\346\225\260\346\215\256\344\275\215", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        btnRefresh->setToolTip(QApplication::translate("PIDCurve", "\345\210\267\346\226\260\347\253\257\345\217\243\345\217\267", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        btnRefresh->setText(QApplication::translate("PIDCurve", "\345\210\267\346\226\260", Q_NULLPTR));
        btnOpenPort->setText(QApplication::translate("PIDCurve", "\346\211\223\345\274\200\344\270\262\345\217\243", Q_NULLPTR));
        gpbGraph1->setTitle(QApplication::translate("PIDCurve", "\346\233\262\347\272\2771", Q_NULLPTR));
        lblCurve11D->setText(QApplication::translate("PIDCurve", "D", Q_NULLPTR));
        txtCurve1Tartget->setText(QApplication::translate("PIDCurve", "0", Q_NULLPTR));
        lblCurve1Target->setText(QApplication::translate("PIDCurve", "\347\233\256\346\240\207\345\200\274", Q_NULLPTR));
        lblCurve11P->setText(QApplication::translate("PIDCurve", "P", Q_NULLPTR));
        lblCurve11I->setText(QApplication::translate("PIDCurve", "I", Q_NULLPTR));
        btnCurve1->setText(QApplication::translate("PIDCurve", "\347\233\256\346\240\207\345\200\274", Q_NULLPTR));
        btnCurve1PID->setText(QApplication::translate("PIDCurve", "PID", Q_NULLPTR));
        gpbGraph2->setTitle(QApplication::translate("PIDCurve", "\346\233\262\347\272\2772", Q_NULLPTR));
        label_6->setText(QApplication::translate("PIDCurve", "I", Q_NULLPTR));
        label_7->setText(QApplication::translate("PIDCurve", "D", Q_NULLPTR));
        label_8->setText(QApplication::translate("PIDCurve", "\347\233\256\346\240\207\345\200\274", Q_NULLPTR));
        txtCurve2Tartget->setText(QApplication::translate("PIDCurve", "0", Q_NULLPTR));
        btnCurve2PID->setText(QApplication::translate("PIDCurve", "PID", Q_NULLPTR));
        btnCurve2->setText(QApplication::translate("PIDCurve", "\347\233\256\346\240\207\345\200\274", Q_NULLPTR));
        label_5->setText(QApplication::translate("PIDCurve", "P", Q_NULLPTR));
        gpbGraph3->setTitle(QApplication::translate("PIDCurve", "\346\233\262\347\272\2773", Q_NULLPTR));
        label_9->setText(QApplication::translate("PIDCurve", "P", Q_NULLPTR));
        label_10->setText(QApplication::translate("PIDCurve", "I", Q_NULLPTR));
        label_11->setText(QApplication::translate("PIDCurve", "D", Q_NULLPTR));
        label_12->setText(QApplication::translate("PIDCurve", "\347\233\256\346\240\207\345\200\274", Q_NULLPTR));
        txtCurve3Tartget->setText(QApplication::translate("PIDCurve", "0", Q_NULLPTR));
        btnCurve3PID->setText(QApplication::translate("PIDCurve", "PID", Q_NULLPTR));
        btnCurve3->setText(QApplication::translate("PIDCurve", "\347\233\256\346\240\207\345\200\274", Q_NULLPTR));
        textBrowser->setHtml(QApplication::translate("PIDCurve", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'SimSun'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-weight:600;\">PID\345\217\202\346\225\260\350\260\203\350\257\225\345\212\251\346\211\213</span></p>\n"
"<p style=\" margin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">    \347\224\250\344\272\216\346\225\264\345\256\232PID\347\256\227\346\263\225\347\232\204\345\217\202\346\225\260\357\274\214\346\234\200\345\244\232\345\217\257\344\273\245\345\220\214\346\227\266\346\230\276\347\244\2723\346\235\241\346\233\262\347\272\277\357\274\214\345\217\257\344\273\245\345\220\214\346\227\266\350"
                        "\247\202\345\257\237\344\270\211\344\270\252\346\216\247\345\210\266\351\207\217\347\232\204\345\217\230\345\214\226\343\200\202</p>\n"
"<p style=\" margin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-weight:600;\">\344\275\277\347\224\250\346\226\271\346\263\225</span></p>\n"
"<p style=\" margin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">    \345\234\250\345\267\246\344\276\247\347\232\204\346\233\262\347\272\277\345\217\202\346\225\260\350\256\276\345\256\232\351\207\214\350\256\276\345\256\232\345\245\275PID\345\217\202\346\225\260\345\200\274\357\274\214\345\222\214\347\233\256\346\240\207\345\200\274\357\274\214\347\204\266\345\220\216\347\202\271\345\207\273\344\270\213\351\235\242\344\270\244\344\270\252\346\214\211\351\222\256\342\200\234PID\342\200\235\342\200\234\347\233\256\346\240\207\345\200\274\342\200\235\345\260\206\345\210\206\345\210\253\345\217\221\351\200"
                        "\201PID\345\217\202\346\225\260\345\222\214\347\233\256\346\240\207\345\200\274\345\210\260\346\216\247\345\210\266\346\235\277\343\200\202PID\345\217\202\346\225\260\346\230\257\346\265\256\347\202\271\346\225\260\357\274\214\347\233\256\346\240\207\345\200\274\346\230\257\346\225\264\345\275\242\346\225\260\346\215\256\343\200\202\345\217\257\344\273\245\351\200\232\350\277\207\345\213\276\351\200\211\344\270\215\345\220\214\347\232\204\346\233\262\347\272\277\346\235\245\346\230\276\347\244\272\344\270\200\346\235\241\346\210\226\345\244\232\346\235\241\346\233\262\347\272\277\343\200\202</p>\n"
"<p style=\" margin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">    \344\270\213\346\226\271\347\232\204\346\214\211\351\222\256\346\230\257\345\212\237\350\203\275\346\216\247\345\210\266\346\214\211\351\222\256\357\274\214\350\275\257\344\273\266\345\244\215\344\275\215\346\230\257\346\214\207\346\216\247\345\210\266\346\235\277\345\244\215\344\275\215\357"
                        "\274\214\347\233\270\345\275\223\344\272\216\346\214\211\344\270\213\345\244\215\344\275\215\351\224\256\343\200\202\346\270\205\347\251\272\345\233\276\350\241\250\345\260\206\344\274\232\346\270\205\347\251\272\346\211\200\346\234\211\346\233\262\347\272\277\346\225\260\346\215\256\343\200\202\344\277\235\345\255\230\345\233\276\345\203\217\345\217\257\344\273\245\345\260\206\346\233\262\347\272\277\344\273\245\346\226\207\344\273\266\345\275\242\345\274\217\344\277\235\345\255\230\345\234\250\347\224\265\350\204\221\344\270\212\357\274\214\345\217\257\351\200\211png/jpg/bmp/pdf\346\240\274\345\274\217\343\200\202</p>\n"
"<p style=\" margin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-weight:600;\">\347\233\256\345\211\215\351\200\202\347\224\250\347\232\204\344\276\213\347\250\213</span></p>\n"
"<p style=\" margin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\""
                        " color:#00aaff;\">    YS-F4Pro\347\232\204\346\234\211\345\210\267\345\222\214\346\227\240\345\210\267\347\233\270\345\205\263\344\276\213\347\250\213</span></p>\n"
"<p style=\" margin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" color:#00aaff;\">    YS-H7Multi\347\232\204\346\255\245\350\277\233\347\224\265\346\234\272\347\233\270\345\205\263\344\276\213\347\250\213</span></p>\n"
"<p style=\" margin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" color:#00aaff;\">    YS-H7Multi\347\232\204\346\234\211\345\210\267\347\233\270\345\205\263\344\276\213\347\250\213</span></p>\n"
"<p style=\" margin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">\344\276\213\347\250\213\345\217\252\350\203\275\346\230\276\347\244\272\344\270\200\346\235\241\346\233\262\347\272\277\357\274\214\345\246\202\346\236\234\351\234\200\350\246"
                        "\201\346\230\276\347\244\272\345\244\232\346\235\241\346\233\262\347\272\277\345\217\257\344\273\245\345\217\202\350\200\203\351\200\232\344\277\241\345\215\217\350\256\256\350\277\233\350\241\214\347\274\226\347\250\213\343\200\202</p></body></html>", Q_NULLPTR));
        btnStartMotor->setText(QApplication::translate("PIDCurve", "\345\220\257\345\212\250\347\224\265\346\234\272", Q_NULLPTR));
        btnReset->setText(QApplication::translate("PIDCurve", "\350\275\257\344\273\266\345\244\215\344\275\215", Q_NULLPTR));
        btnClearChart->setText(QApplication::translate("PIDCurve", "\346\270\205\347\251\272\345\233\276\350\241\250", Q_NULLPTR));
        btnSaveCurve->setText(QApplication::translate("PIDCurve", "\344\277\235\345\255\230\345\233\276\345\203\217", Q_NULLPTR));
        btnProtocol->setText(QApplication::translate("PIDCurve", "\351\200\232\344\277\241\345\215\217\350\256\256", Q_NULLPTR));
        btnCurveBG->setText(QApplication::translate("PIDCurve", "\350\275\254\346\215\242\350\203\214\346\231\257\350\211\262", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class PIDCurve: public Ui_PIDCurve {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PIDCURVE_H
