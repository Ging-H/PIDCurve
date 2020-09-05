#ifndef PIDDEBUGGER_H
#define PIDDEBUGGER_H

#include <QWidget>
#include "baseserialcomm.h"
#include "ui_pidcurve.h"
#include "QMessageBox"
#include "qcustomplot.h"
#include <QtEndian>
#include "ui_untitled.h"

namespace Ui {
class PIDCurve;
}

class PIDCurve : public QWidget
{
    Q_OBJECT

public:
    explicit PIDCurve(QWidget *parent = 0);
    ~PIDCurve();

    enum CtrlCmd {
        SetPid1      = 0x07, // 曲线1 PID参数设置
        SetTarget1   = 0x08, // 曲线1 设置目标值
        Reset        = 0x09, // 系统软件复位
        StartMotor   = 0x0A, // 启动电机
        SetPid2      = 0x0B, // 曲线1 PID参数设置
        SetTarget2   = 0x0C, // 曲线1 PID参数设置
        SetPid3      = 0x0D, // 曲线2 PID参数设置
        SetTarget3   = 0x0E, // 曲线2 PID参数设置
    };
    Q_ENUM(CtrlCmd)

    BaseSerialComm *currentPort;   // 端口号
    quint32 posX  = 0;
    quint32 target1  = 0;
    quint32 target2  = 0;
    quint32 target3  = 0;
    bool graph1Enable  = true;
    bool graph2Enable  = false;
    bool graph3Enable  = false;

    void initComboBox_Config();
    void configPort();
    void sendFrame(CtrlCmd cmd, quint32 param1, quint32 param2, quint32 param3);
    void addHeaderTrailer(QByteArray &rxbuf);
    void Delay_MSec(quint32 msec);
    bool isDataEffective(QByteArray &rxbuf);
    void flashChart(qint32 y1, qint32 y2, qint32 y3 );
    void initPlot();


public slots:
    void slots_serialRxCallback();

    void slots_errorHandler(QSerialPort::SerialPortError error);
private slots:
    void on_btnRefresh_clicked();

    void on_btnOpenPort_clicked(bool checked);

    void on_btnCurve1_clicked();

    void on_btnStartMotor_clicked();

    void on_btnReset_clicked();

    void on_btnCurve2_clicked();

    void on_btnCurve3_clicked();

    void on_btnClearChart_clicked();

    void on_gpbGraph1_clicked(bool checked);

    void on_gpbGraph2_clicked(bool checked);

    void on_gpbGraph3_clicked(bool checked);

    void on_btnSaveCurve_clicked();

    void on_btnCurve1PID_clicked();

    void on_btnCurve2PID_clicked();

    void on_btnCurve3PID_clicked();

    void on_btnProtocol_clicked();

    void on_btnCurveBG_clicked(bool checked);

private:
    Ui::PIDCurve *ui;
};

#endif // PIDDEBUGGER_H
