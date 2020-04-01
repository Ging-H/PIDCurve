#include "inc/pidcurve.h"


PIDCurve::PIDCurve(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::PIDCurve)
{
    ui->setupUi(this);
    currentPort = new BaseSerialComm();
    this->initComboBox_Config();
    /* 串口错误信息处理 */
    connect(currentPort,SIGNAL(errorOccurred(QSerialPort::SerialPortError)),this, SLOT(slots_errorHandler(QSerialPort::SerialPortError)  ));

    // 限定 QlineEdit 只能输入数字
    QRegExp regx("[0-9]+$");
    QValidator* validator = new QRegExpValidator(regx, ui->txtCurve1Tartget);
    ui->txtCurve2Tartget->setValidator(validator);
    ui->txtCurve3Tartget->setValidator(validator);

    this->initPlot();// 初始化绘图框架
    if(graph1Enable){
        ui->gpbGraph1->setChecked(true);
    }
    if(graph2Enable){
        ui->gpbGraph2->setChecked(true);
    }
    if(graph3Enable){
        ui->gpbGraph3->setChecked(true);
    }
}

PIDCurve::~PIDCurve()
{
    delete ui;
}

/* 初始化自定义绘图曲线 */
void PIDCurve::initPlot()
{
    // set line style
    QPen pen;
    pen.setWidth(1);//线宽
    pen.setStyle(Qt::PenStyle::SolidLine);// a plain line
    pen.setColor(Qt::blue);// blue

    // add new graphs and set their look:
    ui->customPlot->addGraph();
    ui->customPlot->graph(0)->setPen(pen); // line color blue for first graph
    ui->customPlot->graph(0)->setName("曲线1");

    pen.setColor(Qt::red);// red
    ui->customPlot->addGraph();
    ui->customPlot->graph(1)->setPen(pen); // line color red for second graph
    ui->customPlot->graph(1)->setName("曲线2");

    pen.setColor(Qt::green);// green
    ui->customPlot->addGraph();
    ui->customPlot->graph(2)->setPen(pen); // line color red for second graph
    ui->customPlot->graph(2)->setName("曲线3");

    pen.setStyle(Qt::PenStyle::DashLine);// Dashs separated by a few pixels
    pen.setColor(Qt::black);// black

    // 添加Graph，1条曲线使用一个Graph
    ui->customPlot->addGraph();
    ui->customPlot->graph(3)->setPen(pen);
    ui->customPlot->graph(3)->setName("目标1");
    // 添加Graph，1条曲线使用一个Graph
    ui->customPlot->addGraph();
    ui->customPlot->graph(4)->setPen(pen); //
    ui->customPlot->graph(4)->setName("目标2");
    // 添加Graph，1条曲线使用一个Graph
    ui->customPlot->addGraph();
    ui->customPlot->graph(5)->setPen(pen);
    ui->customPlot->graph(5)->setName("目标3");

    //设定右上角图形标注和字体
    ui->customPlot->legend->setVisible(true);
    ui->customPlot->legend->setFont(QFont("Helvetica", 9));
    ui->customPlot->legend->removeItem(5);// remove一个,后面会向前补上
    ui->customPlot->legend->removeItem(4);
    ui->customPlot->legend->removeItem(3);

//    ui->customPlot->setBackground(QBrush(Qt::black));
//    ui->customPlot->setBackground(QBrush(QColor(46, 47, 48)));

    // configure right and top axis to show ticks but no labels:
    // (see QCPAxisRect::setupFullAxesBox for a quicker method to do this)
    ui->customPlot->xAxis2->setVisible(true);
//    ui->customPlot->xAxis2->setTickLabels(true);
    ui->customPlot->yAxis2->setVisible(true);
//    ui->customPlot->yAxis2->setTickLabels(true);

    // make left and bottom axes always transfer their ranges to right and top axes:
    connect(ui->customPlot->xAxis, SIGNAL(rangeChanged(QCPRange)), ui->customPlot->xAxis2, SLOT(setRange(QCPRange)));
    connect(ui->customPlot->yAxis, SIGNAL(rangeChanged(QCPRange)), ui->customPlot->yAxis2, SLOT(setRange(QCPRange)));


//    ui->customPlot->graph(2)->rescaleAxes(true);
    // Note: we could have also just called ui->customPlot->rescaleAxes(); instead
    // Allow user to drag axis ranges with mouse, zoom with mouse wheel and select graphs by clicking:
    ui->customPlot->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom | QCP::iSelectPlottables);
}

/*   初始化了串口设置当中的下拉列表(ComboBox) */
void PIDCurve::initComboBox_Config()
{
    /* 更新下拉列表 */
    BaseSerialComm::listBaudRate( ui -> cbbBaud    );
    BaseSerialComm::listDataBit ( ui -> cbbDataBit );
    BaseSerialComm::listVerify  ( ui -> cbbVerify  );
    BaseSerialComm::listStopBit ( ui -> cbbStopBit );
    BaseSerialComm::listPortNum ( ui -> cbbPortNum );
}

/* 刷新按钮点击 槽函数 */
void PIDCurve::on_btnRefresh_clicked()
{
    if( !ui->btnOpenPort->isChecked()){  // 关闭串口才能刷新端口号
        ui -> cbbPortNum ->clear();
        BaseSerialComm::listPortNum ( ui -> cbbPortNum );
    }
}

/* 打开串口 槽函数*/
void PIDCurve::on_btnOpenPort_clicked(bool checked)
{
    QString tmp = ui->cbbPortNum->currentText();
    tmp = tmp.split(" ").first();//  Item的 text 由 <COM1 "描述"> 组成,使用空格作为分隔符取第一段就是端口名
    if(checked){
        // 当前串口处于关闭状态
        currentPort->setPortName( tmp );              // 设置端口号
        if( currentPort->open(QIODevice::ReadWrite)){ // 打开串口
            currentPort -> setDTRState(false);
            currentPort -> setRTSState(false);
            /* 配置端口的波特率等参数 */
                this->configPort();
                connect(currentPort ,SIGNAL(readyRead()),this,SLOT( slots_serialRxCallback()));// 有数据就直接接收显示
            ui->btnOpenPort->setText(tr("关闭串口"));
        }else{
            ui->btnOpenPort->setChecked(false);
        }

    }
    else{
        currentPort->close();
        ui->btnOpenPort->setText(tr("打开串口"));
    }
}

/* 配置端口的波特率\数据位\奇偶校验\停止位 */
void PIDCurve::configPort()
{
    QVariant tmpVariant;
    /* 设置波特率 */
    tmpVariant = ui->cbbBaud->currentData();  // 读取控件的当前项的值
    currentPort->setBaudRate(tmpVariant.value < BaseSerialComm::BaudRate > ()  );

    /* 设置数据位 */
    tmpVariant = ui->cbbDataBit->currentData();
    currentPort->setDataBits( tmpVariant.value <BaseSerialComm::DataBits > () );

    /* 设置校验位 */
    tmpVariant = ui->cbbVerify->currentData();
    currentPort->setParity (tmpVariant.value < BaseSerialComm::Parity > () );

    /* 设置停止位 */
    tmpVariant = ui->cbbStopBit->currentData();// 某些情况不支持1.5停止位
    if(currentPort->setStopBits (tmpVariant.value < BaseSerialComm::StopBits > () ) == false ){
        ui -> cbbStopBit->clear();
        BaseSerialComm::listStopBit ( ui -> cbbStopBit );
        QMessageBox::information(NULL, tr("不支持的设置"),  tr("该串口设备不支持当前停止位设置,已修改为默认的设置"), 0, 0);
    }
}

/* 串口错误信息处理 */
void PIDCurve::slots_errorHandler(QSerialPort::SerialPortError error)
{
    switch(error){
    case QSerialPort::DeviceNotFoundError:QMessageBox::information(NULL, tr("未找到设备"),  tr("检查设备是否已经连接,或者是否正常供电"), 0, 0);
        break;
    case QSerialPort::OpenError:
    case QSerialPort::PermissionError:QMessageBox::information(NULL, tr("打开失败"),  tr("检查设备是否已被其他软件占用"), 0, 0);
        break;
    default:
        break;
    }
}

void PIDCurve::on_gpbGraph1_clicked(bool checked)
{
    if(!checked){
        ui->customPlot->graph(0)->data().data()->clear();
        ui->customPlot->graph(3)->data().data()->clear();
        graph1Enable = false;
    }else{
        graph1Enable = true;
    }
}
void PIDCurve::on_gpbGraph2_clicked(bool checked)
{
    if(!checked){
        ui->customPlot->graph(1)->data().data()->clear();
        ui->customPlot->graph(4)->data().data()->clear();
        graph1Enable = false;
    }else{
        graph2Enable = true;
    }
}
void PIDCurve::on_gpbGraph3_clicked(bool checked)
{
    if(!checked){
        ui->customPlot->graph(2)->data().data()->clear();
        ui->customPlot->graph(5)->data().data()->clear();
        graph3Enable = false;
    }else{
        graph3Enable = true;
    }
}

/* 清除图像曲线 */
void PIDCurve::on_btnClearChart_clicked()
{
    ui->customPlot->graph(0)->data().data()->clear();
    ui->customPlot->graph(1)->data().data()->clear();
    ui->customPlot->graph(2)->data().data()->clear();
    ui->customPlot->graph(3)->data().data()->clear();
    ui->customPlot->graph(4)->data().data()->clear();
    ui->customPlot->graph(5)->data().data()->clear();
    posX = 0;
    ui->customPlot->xAxis->setRange(0, 250, Qt::AlignLeft);
    ui->customPlot->yAxis->setRange(0, 250, Qt::AlignBottom);
}


/* 串口数据接收回调函数 */
void PIDCurve::slots_serialRxCallback()
{
    QByteArray rxbuf;
    rxbuf = currentPort->readAll();
    if(this->isDataEffective(rxbuf)){
        switch( (quint8)rxbuf.at(1) ){
        /* PID only have 1 feedback cmd*/
        case 0x88:
            quint8 tmp1 = rxbuf.at(2);
            quint8 tmp2 = rxbuf.at(3);
            quint8 tmp3 = rxbuf.at(4);
            quint8 tmp4 = rxbuf.at(5);
            qint32 y1 = (qint32)((tmp4<<24) | (tmp3<<16) | (tmp2<<8) |(tmp1<<0));
            tmp1 = rxbuf.at(6);
            tmp2 = rxbuf.at(7);
            tmp3 = rxbuf.at(8);
            tmp4 = rxbuf.at(9);
            qint32 y2 = (qint32)((tmp4<<24) | (tmp3<<16) | (tmp2<<8) |(tmp1<<0));
            tmp1 = rxbuf.at(10);
            tmp2 = rxbuf.at(11);
            tmp3 = rxbuf.at(12);
            tmp4 = rxbuf.at(13);
            qint32 y3 = (qint32)((tmp4<<24) | (tmp3<<16) | (tmp2<<8) |(tmp1<<0));
            this->flashChart(y1, y2, y3);
        break;
        }
    }
}

/* 更新图像 */
void PIDCurve::flashChart(qint32 y1, qint32 y2, qint32 y3 )
{
    ++posX;
    // 更新实时曲线// 更新目标值
    if(graph1Enable){
        ui->customPlot->graph(0)->addData(posX, y1);
        ui->customPlot->graph(3)->addData(posX, target1);
        // let the ranges scale themselves so graph 0 fits perfectly in the visible area:
        ui->customPlot->graph(0)->rescaleAxes(true);
    }
    if(graph2Enable){
        ui->customPlot->graph(1)->addData(posX, y2);
        ui->customPlot->graph(4)->addData(posX, target2);
        // same thing for graph 1, but only enlarge ranges (in case graph 1 is smaller than graph 0):
        ui->customPlot->graph(1)->rescaleAxes(true);
    }

    if(graph3Enable){
        ui->customPlot->graph(2)->addData(posX, y3);
        ui->customPlot->graph(5)->addData(posX, target3);
        ui->customPlot->graph(2)->rescaleAxes(true);
    }
    ui->customPlot->replot(QCustomPlot::rpQueuedReplot);
}

/* 判断是否有效,检查帧头,帧尾和校验码 */
bool PIDCurve::isDataEffective(QByteArray &rxbuf)
{
    bool isEffentive = false;
    if(rxbuf.startsWith(0xAA) && rxbuf.endsWith('/')){
        if( 16 == rxbuf.size() ){
            qint32 indexOfAA = rxbuf.indexOf(0xAA);
            qint32 indexOf2F = rxbuf.indexOf('/');
            qint32 indexOfCS = indexOf2F - 1 ;
            quint8 cs = rxbuf.at( indexOfCS ); // 记录校验码
            currentPort->insertVerify(rxbuf, indexOfAA+2, 2, BaseSerialComm::ADD8);// 计算校验码
            quint8 csNew = (rxbuf.at( indexOfCS) );
            if( csNew == cs){ // 校验码核对
                rxbuf.remove(indexOfCS,1);
                isEffentive = true;
            }
        }
    }
    return isEffentive;
}

/* 短暂延时函数,不宜延时太长时间 */
void PIDCurve::Delay_MSec(quint32 msec)
{
    QTime _Timer = QTime::currentTime().addMSecs(msec);
    while( QTime::currentTime() < _Timer )
        QCoreApplication::processEvents(QEventLoop::AllEvents, 10);
}

/* 数据帧添加帧头帧尾 */
void PIDCurve::addHeaderTrailer(QByteArray &rxbuf)
{
    rxbuf.append('/');
    rxbuf.prepend(0xAA);
}

/* 设置曲线1的PID参数和目标值 */
void PIDCurve::on_btnCurve1_clicked()
{
    typedef union {
        float   floatNum;
        quint32 intNum;
    }floattoint_Typedef;
    floattoint_Typedef ftiPID[3];
    ftiPID[0].floatNum = ui->spbCurve1P->value();
    ftiPID[1].floatNum = ui->spbCurve1I->value();
    ftiPID[2].floatNum = ui->spbCurve1D->value();
    sendFrame(SetPid1, ftiPID[0].intNum, ftiPID[1].intNum, ftiPID[2].intNum);
    this->Delay_MSec(10);
    qint32 tmpParam = ui->txtCurve1Tartget->text().toInt(NULL,10);
    sendFrame(SetTarget1, tmpParam, 0, 0);
    target1 = tmpParam;
}

/* 设置曲线2的PID参数和目标值 */
void PIDCurve::on_btnCurve2_clicked()
{
    typedef union {
        float   floatNum;
        quint32 intNum;
    }floattoint_Typedef;
    floattoint_Typedef ftiPID[3];
    ftiPID[0].floatNum = ui->spbCurve2P->value();
    ftiPID[1].floatNum = ui->spbCurve2I->value();
    ftiPID[2].floatNum = ui->spbCurve2D->value();
    sendFrame(SetPid2, ftiPID[0].intNum, ftiPID[1].intNum, ftiPID[2].intNum);
    this->Delay_MSec(10);
    qint32 tmpParam = ui->txtCurve2Tartget->text().toInt(NULL,10);
    sendFrame(SetTarget2, tmpParam, 0, 0);
    target2 = tmpParam;
}

/* 设置曲线3的PID参数和目标值 */
void PIDCurve::on_btnCurve3_clicked()
{
    typedef union {
        float   floatNum;
        quint32 intNum;
    }floattoint_Typedef;
    floattoint_Typedef ftiPID[3];
    ftiPID[0].floatNum = ui->spbCurve3P->value();
    ftiPID[1].floatNum = ui->spbCurve3I->value();
    ftiPID[2].floatNum = ui->spbCurve3D->value();
    sendFrame(SetPid3, ftiPID[0].intNum, ftiPID[1].intNum, ftiPID[2].intNum);
    this->Delay_MSec(10);
    qint32 tmpParam = ui->txtCurve3Tartget->text().toInt(NULL,10);
    sendFrame(SetTarget3, tmpParam, 0, 0);
    target3 = tmpParam;
}

/* 启动电机 */
void PIDCurve::on_btnStartMotor_clicked()
{
    sendFrame(StartMotor, StartMotor, 0, 0);
}

/* 软件复位 */
void PIDCurve::on_btnReset_clicked()
{
    sendFrame(Reset, Reset, 0, 0);
}

/* 发送数据帧 */
void PIDCurve::sendFrame(CtrlCmd cmd, quint32 param1, quint32 param2, quint32 param3)
{
    QByteArray txBuf(12,0x55);
    txBuf.prepend(cmd); //  cmd在缓存的头部
    quint32 tmpParam;
    switch(cmd){
    case SetPid1:
    case SetPid2:
    case SetPid3:
        tmpParam = qToBigEndian(param1);// 传输数据是高位字节在前
        txBuf.replace(1, 4, (const char*)&tmpParam, sizeof(tmpParam));     // 4个字节
        tmpParam = qToBigEndian(param2);
        txBuf.replace(5, 4, (const char*)&tmpParam, sizeof(tmpParam));     // 4个字节
        tmpParam = qToBigEndian(param3);
        txBuf.replace(9, 4, (const char*)&tmpParam, sizeof(tmpParam));     // 4个字节
        currentPort->insertVerify(txBuf, 1, 0, BaseSerialComm::ADD8 ); // 从第一个字节开始,在尾部添加校验码
        this->addHeaderTrailer(txBuf);
        currentPort->write(txBuf);
        break;
    case SetTarget1:
    case SetTarget2:
    case SetTarget3:
        tmpParam = param1;
        txBuf.replace(1, 4, (const char*)&tmpParam, sizeof(tmpParam));     // 4个字节
        currentPort->insertVerify(txBuf, 1, 0, BaseSerialComm::ADD8 ); //
        this->addHeaderTrailer(txBuf);
        currentPort->write(txBuf);
        break;
    case Reset:
    case StartMotor:
        tmpParam = param1;
        txBuf[1] = (quint8)tmpParam;
        currentPort->insertVerify(txBuf, 1, 0, BaseSerialComm::ADD8 ); //
        this->addHeaderTrailer(txBuf);
        currentPort->write(txBuf);
        break;
    default:break;
    }
}


void PIDCurve::on_btnSaveCurve_clicked()
{
  QString fileName = QFileDialog::getSaveFileName(this, "保存图像...",
                                                  qApp->applicationDirPath(),
                                                  "png(*.png);;jpg(*.jpg);;bmp(*.bmp);;pdf(*.pdf)");

  if (!fileName.isEmpty())
  {
      if(fileName.endsWith(".png")){
          ui->customPlot->savePng(fileName);
      }else if(fileName.endsWith(".jpg")){
          ui->customPlot->saveJpg(fileName);
      }else if(fileName.endsWith(".bmp")){
          ui->customPlot->saveBmp(fileName);
      }else if(fileName.endsWith(".pdf")){
          ui->customPlot->savePdf(fileName,0,0,QCP::epAllowCosmetic,"ing10 PID","Curve");
      }
  }
}
