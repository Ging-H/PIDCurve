#include "pidcurve.h"

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

    /* ui初始化 */
    QApplication::setStyle(QStyleFactory::create("fusion"));// fusion 风格
    QFile file(":/theme/blackOrange.css");              // QSS文件
    if (!file.open(QFile::ReadOnly)){  // 打开文件
        return;
    }
    QTextStream in(&file);
    in.setCodec("UTF-8");
    QString qss = in.readAll();        // 读取数据
    qApp->setStyleSheet(qss);          // 应用
    this->setWindowTitle("硬石电子-PID调试助手 v1.0");
}

PIDCurve::~PIDCurve()
{
    delete ui;
}

/**
 * @brief PIDCurve::initPlot 初始化曲线
 */
void PIDCurve::initPlot()
{
    // set line style
    QPen pen;
    pen.setWidth(1);//线宽
    pen.setStyle(Qt::PenStyle::SolidLine);// a plain line
    pen.setColor(Qt::cyan);// blue

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
    pen.setColor(Qt::white);// white

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

    // set some pens, brushes and backgrounds:
    ui->customPlot->xAxis->setBasePen(QPen(Qt::white, 1));
    ui->customPlot->yAxis->setBasePen(QPen(Qt::white, 1));
    ui->customPlot->xAxis->setTickPen(QPen(Qt::white, 1));
    ui->customPlot->yAxis->setTickPen(QPen(Qt::white, 1));
    ui->customPlot->xAxis->setSubTickPen(QPen(Qt::white, 1));
    ui->customPlot->yAxis->setSubTickPen(QPen(Qt::white, 1));
    ui->customPlot->xAxis->setTickLabelColor(Qt::white);
    ui->customPlot->yAxis->setTickLabelColor(Qt::white);
    ui->customPlot->xAxis->grid()->setPen(QPen(QColor(140, 140, 140), 1, Qt::DotLine));
    ui->customPlot->yAxis->grid()->setPen(QPen(QColor(140, 140, 140), 1, Qt::DotLine));
    ui->customPlot->xAxis->grid()->setSubGridPen(QPen(QColor(80, 80, 80), 1, Qt::DotLine));
    ui->customPlot->yAxis->grid()->setSubGridPen(QPen(QColor(80, 80, 80), 1, Qt::DotLine));
    ui->customPlot->xAxis->grid()->setSubGridVisible(true);
    ui->customPlot->yAxis->grid()->setSubGridVisible(true);
    ui->customPlot->xAxis->grid()->setZeroLinePen(Qt::NoPen);
    ui->customPlot->yAxis->grid()->setZeroLinePen(Qt::NoPen);
    ui->customPlot->xAxis->setUpperEnding(QCPLineEnding::esSpikeArrow);
    ui->customPlot->yAxis->setUpperEnding(QCPLineEnding::esSpikeArrow);
    QLinearGradient plotGradient;
    plotGradient.setStart(0, 0);
    plotGradient.setFinalStop(0, 350);
    plotGradient.setColorAt(0, QColor(80, 80, 80));
    plotGradient.setColorAt(1, QColor(50, 50, 50));
    ui->customPlot->setBackground(plotGradient);
    QLinearGradient axisRectGradient;
    axisRectGradient.setStart(0, 0);
    axisRectGradient.setFinalStop(0, 350);
    axisRectGradient.setColorAt(0, QColor(80, 80, 80));
    axisRectGradient.setColorAt(1, QColor(30, 30, 30));
    ui->customPlot->axisRect()->setBackground(axisRectGradient);

    //    ui->customPlot->graph(2)->rescaleAxes(true);
    // Note: we could have also just called ui->customPlot->rescaleAxes(); instead
    // Allow user to drag axis ranges with mouse, zoom with mouse wheel and select graphs by clicking:
    ui->customPlot->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom | QCP::iSelectPlottables);
}

/**
 * @brief PIDCurve::initComboBox_Config 初始化串口设置当中的下拉列表
 */
void PIDCurve::initComboBox_Config()
{
    /* 更新下拉列表 */
    BaseSerialComm::listBaudRate( ui -> cbbBaud    );
    BaseSerialComm::listDataBit ( ui -> cbbDataBit );
    BaseSerialComm::listVerify  ( ui -> cbbVerify  );
    BaseSerialComm::listStopBit ( ui -> cbbStopBit );
    BaseSerialComm::listPortNum ( ui -> cbbPortNum );
}

/**
 * @brief PIDCurve::on_btnRefresh_clicked 刷新端口号
 */
void PIDCurve::on_btnRefresh_clicked()
{
    if( !ui->btnOpenPort->isChecked()){  // 关闭串口才能刷新端口号
        ui -> cbbPortNum ->clear();
        BaseSerialComm::listPortNum ( ui -> cbbPortNum );
    }
}

/**
 * @brief PIDCurve::on_btnOpenPort_clicked 打开端口
 * @param checked
 */
void PIDCurve::on_btnOpenPort_clicked(bool checked)
{
    QString tmp = ui->cbbPortNum->currentText();
    tmp = tmp.split(" ").first();//  Item的 text 由 <COM1 "描述"> 组成,使用空格作为分隔符取第一段就是端口名
    if(checked){
        // 当前串口处于关闭状态
        currentPort->setPortName( tmp );              // 设置端口号
        if( currentPort->open(QIODevice::ReadWrite)){ // 打开串口
            currentPort->setDataTerminalReady(false);
            currentPort ->setRequestToSend(false);
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

/**
 * @brief PIDCurve::configPort 配置端口的波特率等参数
 */
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

/**
 * @brief PIDCurve::slots_errorHandler 串口错误信息提示
 * @param error
 */
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

/**
 * @brief PIDCurve::on_gpbGraph1_clicked 选择要显示的曲线
 * @param checked
 */
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
        graph2Enable = false;
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

/**
 * @brief PIDCurve::on_btnClearChart_clicked 清除图像曲线
 */
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

/**
 * @brief PIDCurve::slots_serialRxCallback 接收并先更新曲线
 */
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

/**
 * @brief PIDCurve::flashChart 曲线填充数据
 * @param y1  曲线1的数值
 * @param y2
 * @param y3
 */
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

/**
 * @brief PIDCurve::isDataEffective 检查校验码，验证数据是否有效
 * @param rxbuf
 * @return
 */
bool PIDCurve::isDataEffective(QByteArray &rxbuf)
{
    if(rxbuf.startsWith(0xAA) && rxbuf.endsWith('/')){
        if( 16 == rxbuf.size() ){
            QByteArray tmp = rxbuf.mid(1, 13);
            quint8 cs = rxbuf.at( rxbuf.length() - 2 ); // 记录校验码
            quint8 csVerify = currentPort->verifyADD8( tmp );
            if( csVerify == cs){ // 校验码核对
                return true;
            }
        }
    }
    return false;
}

/**
 * @brief PIDCurve::Delay_MSec 延时，不能延时太长时间
 * @param msec
 */
void PIDCurve::Delay_MSec(quint32 msec)
{
    QTime _Timer = QTime::currentTime().addMSecs( msec );
    while( QTime::currentTime() < _Timer )
        QCoreApplication::processEvents(QEventLoop::AllEvents, 10);
}

/**
 * @brief PIDCurve::addHeaderTrailer 发送数据帧添加帧头帧尾
 * @param rxbuf
 */
void PIDCurve::addHeaderTrailer(QByteArray &rxbuf)
{
    rxbuf.append( '/' );
    rxbuf.prepend( 0xAA );
}

/**
 * @brief PIDCurve::on_btnCurve1_clicked 发送曲线的目标值
 */
void PIDCurve::on_btnCurve1_clicked()
{
    qint32 tmpParam = ui->txtCurve1Tartget->text().toInt(NULL,10);
    sendFrame(SetTarget1, tmpParam, 0, 0);
    target1 = tmpParam;
}

void PIDCurve::on_btnCurve2_clicked()
{
    qint32 tmpParam = ui->txtCurve2Tartget->text().toInt(NULL,10);
    sendFrame(SetTarget2, tmpParam, 0, 0);
    target2 = tmpParam;
}

void PIDCurve::on_btnCurve3_clicked()
{
    qint32 tmpParam = ui->txtCurve3Tartget->text().toInt(NULL,10);
    sendFrame(SetTarget3, tmpParam, 0, 0);
    target3 = tmpParam;
}

/**
 * @brief PIDCurve::on_btnStartMotor_clicked 启动电机
 */
void PIDCurve::on_btnStartMotor_clicked()
{
    sendFrame(StartMotor, StartMotor, 0, 0);
}

/**
 * @brief PIDCurve::on_btnReset_clicked 软件复位
 */
void PIDCurve::on_btnReset_clicked()
{
    sendFrame(Reset, Reset, 0, 0);
}

/**
 * @brief PIDCurve::sendFrame 发送数据帧
 * @param cmd      指令
 * @param param1   数据帧参数1
 * @param param2   数据帧参数1
 * @param param3   数据帧参数1
 */
void PIDCurve::sendFrame(CtrlCmd cmd, quint32 param1, quint32 param2, quint32 param3)
{
    QByteArray txBuf(12,0x55);
    txBuf.prepend(cmd); //  cmd在缓存的头部
    quint32 tmpParam;
    switch(cmd){
    case SetPid1:
    case SetPid2:
    case SetPid3:{
        tmpParam = qToLittleEndian(param1);// 传输数据是高位字节在前
        txBuf.replace(1, 4, (const char*)&tmpParam, sizeof(tmpParam));     // 4个字节
        tmpParam = qToLittleEndian(param2);
        txBuf.replace(5, 4, (const char*)&tmpParam, sizeof(tmpParam));     // 4个字节
        tmpParam = qToLittleEndian(param3);
        txBuf.replace(9, 4, (const char*)&tmpParam, sizeof(tmpParam));     // 4个字节
        qint8 verify = currentPort->verifyADD8(txBuf);
        txBuf.append(verify);
        this->addHeaderTrailer(txBuf);
        currentPort->write(txBuf);
    }break;

    case SetTarget1:
    case SetTarget2:
    case SetTarget3:{
        tmpParam = param1;
        txBuf.replace(1, 4, (const char*)&tmpParam, sizeof(tmpParam));     // 4个字节
        qint8 verify = currentPort->verifyADD8(txBuf);
        txBuf.append(verify);
        this->addHeaderTrailer(txBuf);
        currentPort->write(txBuf);
    }break;

    case Reset:
    case StartMotor:{
        tmpParam = param1;
        txBuf[1] = (quint8)tmpParam;
        qint8 verify = currentPort->verifyADD8(txBuf);
        txBuf.append(verify);
        this->addHeaderTrailer(txBuf);
        currentPort->write(txBuf);
    }break;

    default:break;
    }
}

/**
 * @brief PIDCurve::on_btnSaveCurve_clicked 保存图像
 */
void PIDCurve::on_btnSaveCurve_clicked()
{
    QString fileName = QFileDialog::getSaveFileName(this, "保存图像...",
                                                    qApp->applicationDirPath(),
                                                    "png(*.png);;jpg(*.jpg);;bmp(*.bmp);;pdf(*.pdf)");

    if (!fileName.isEmpty()){
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

/**
 * @brief PIDCurve::on_btnCurve1PID_clicked 发送曲线1的PID参数
 */
void PIDCurve::on_btnCurve1PID_clicked()
{
    typedef union {
        float   floatNum;
        quint32 intNum;
    }FloatToInt_Typedef;
    FloatToInt_Typedef ftiPID[3];
    ftiPID[0].floatNum = ui->spbCurve1P->value();
    ftiPID[1].floatNum = ui->spbCurve1I->value();
    ftiPID[2].floatNum = ui->spbCurve1D->value();
    sendFrame(SetPid1, ftiPID[0].intNum, ftiPID[1].intNum, ftiPID[2].intNum);
}

void PIDCurve::on_btnCurve2PID_clicked()
{
    typedef union {
        float   floatNum;
        quint32 intNum;
    }FloatToInt_Typedef;
    FloatToInt_Typedef ftiPID[3];
    ftiPID[0].floatNum = ui->spbCurve2P->value();
    ftiPID[1].floatNum = ui->spbCurve2I->value();
    ftiPID[2].floatNum = ui->spbCurve2D->value();
    sendFrame(SetPid2, ftiPID[0].intNum, ftiPID[1].intNum, ftiPID[2].intNum);
}

void PIDCurve::on_btnCurve3PID_clicked()
{
    typedef union {
        float   floatNum;
        quint32 intNum;
    }FloatToInt_Typedef;
    FloatToInt_Typedef ftiPID[3];
    ftiPID[0].floatNum = ui->spbCurve3P->value();
    ftiPID[1].floatNum = ui->spbCurve3I->value();
    ftiPID[2].floatNum = ui->spbCurve3D->value();
    sendFrame(SetPid3, ftiPID[0].intNum, ftiPID[1].intNum, ftiPID[2].intNum);
}

/**
 * @brief PIDCurve::on_btnProtocol_clicked 显示通信协议
 */
void PIDCurve::on_btnProtocol_clicked()
{
    QDialog *dialog = new QDialog();
    Ui::Dialog ui;
    ui.setupUi(dialog);

    dialog->setAttribute(Qt::WA_DeleteOnClose); // 关闭的时候delete
    dialog->setWindowTitle("通信协议");
    ui.tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch );// 自适应列宽
    ui.tableWidget->horizontalHeader()->setSectionResizeMode(2,QHeaderView::ResizeToContents );// 适应单元格内容
    ui.tableWidget->horizontalHeader()->setSectionResizeMode(3,QHeaderView::ResizeToContents );// 适应单元格内容
    ui.tableWidget->horizontalHeader()->setSectionResizeMode(4,QHeaderView::ResizeToContents );// 适应单元格内容
    dialog->show();
}

void PIDCurve::on_btnCurveBG_clicked(bool checked)
{
    if( checked ){
        // set some pens, brushes and backgrounds:
        ui->customPlot->xAxis->setBasePen(QPen(Qt::black, 1));
        ui->customPlot->yAxis->setBasePen(QPen(Qt::black, 1));
        ui->customPlot->xAxis->setTickPen(QPen(Qt::black, 1));
        ui->customPlot->yAxis->setTickPen(QPen(Qt::black, 1));
        ui->customPlot->xAxis->setSubTickPen(QPen(Qt::black, 1));
        ui->customPlot->yAxis->setSubTickPen(QPen(Qt::black, 1));
        ui->customPlot->xAxis->setTickLabelColor(Qt::black);
        ui->customPlot->yAxis->setTickLabelColor(Qt::black);
        ui->customPlot->xAxis->grid()->setPen(QPen(QColor(115, 115, 115), 1, Qt::DotLine));
        ui->customPlot->yAxis->grid()->setPen(QPen(QColor(115, 115, 115), 1, Qt::DotLine));
        ui->customPlot->xAxis->grid()->setSubGridPen(QPen(QColor(175, 175, 175), 1, Qt::DotLine));
        ui->customPlot->yAxis->grid()->setSubGridPen(QPen(QColor(175, 175, 175), 1, Qt::DotLine));
        ui->customPlot->xAxis->grid()->setSubGridVisible(true);
        ui->customPlot->yAxis->grid()->setSubGridVisible(true);
        ui->customPlot->xAxis->grid()->setZeroLinePen(Qt::NoPen);
        ui->customPlot->yAxis->grid()->setZeroLinePen(Qt::NoPen);
        ui->customPlot->xAxis->setUpperEnding(QCPLineEnding::esSpikeArrow);
        ui->customPlot->yAxis->setUpperEnding(QCPLineEnding::esSpikeArrow);
        QLinearGradient plotGradient;
        plotGradient.setStart(0, 0);
        plotGradient.setFinalStop(0, 350);
        plotGradient.setColorAt(0, QColor(255, 255, 255));
        plotGradient.setColorAt(1, QColor(255, 255, 255));
        ui->customPlot->setBackground(plotGradient);
        QLinearGradient axisRectGradient;
        axisRectGradient.setStart(0, 0);
        axisRectGradient.setFinalStop(0, 350);
        axisRectGradient.setColorAt(0, QColor(255, 255, 255));
        axisRectGradient.setColorAt(1, QColor(255, 255, 255));
        ui->customPlot->axisRect()->setBackground(axisRectGradient);

        // set line style
        QPen pen = ui->customPlot->graph(0)->pen();
        pen.setColor(Qt::blue);// blue
        ui->customPlot->graph(0)->setPen(pen);

        pen.setStyle(Qt::PenStyle::DashLine);// Dashs separated by a few pixels
        pen.setColor(Qt::black);// white
        ui->customPlot->graph(3)->setPen(pen);
        ui->customPlot->graph(4)->setPen(pen);
        ui->customPlot->graph(5)->setPen(pen);

    }else{
        // set some pens, brushes and backgrounds:
        ui->customPlot->xAxis->setBasePen(QPen(Qt::white, 1));
        ui->customPlot->yAxis->setBasePen(QPen(Qt::white, 1));
        ui->customPlot->xAxis->setTickPen(QPen(Qt::white, 1));
        ui->customPlot->yAxis->setTickPen(QPen(Qt::white, 1));
        ui->customPlot->xAxis->setSubTickPen(QPen(Qt::white, 1));
        ui->customPlot->yAxis->setSubTickPen(QPen(Qt::white, 1));
        ui->customPlot->xAxis->setTickLabelColor(Qt::white);
        ui->customPlot->yAxis->setTickLabelColor(Qt::white);
        ui->customPlot->xAxis->grid()->setPen(QPen(QColor(140, 140, 140), 1, Qt::DotLine));
        ui->customPlot->yAxis->grid()->setPen(QPen(QColor(140, 140, 140), 1, Qt::DotLine));
        ui->customPlot->xAxis->grid()->setSubGridPen(QPen(QColor(80, 80, 80), 1, Qt::DotLine));
        ui->customPlot->yAxis->grid()->setSubGridPen(QPen(QColor(80, 80, 80), 1, Qt::DotLine));
        ui->customPlot->xAxis->grid()->setSubGridVisible(true);
        ui->customPlot->yAxis->grid()->setSubGridVisible(true);
        ui->customPlot->xAxis->grid()->setZeroLinePen(Qt::NoPen);
        ui->customPlot->yAxis->grid()->setZeroLinePen(Qt::NoPen);
        ui->customPlot->xAxis->setUpperEnding(QCPLineEnding::esSpikeArrow);
        ui->customPlot->yAxis->setUpperEnding(QCPLineEnding::esSpikeArrow);
        QLinearGradient plotGradient;
        plotGradient.setStart(0, 0);
        plotGradient.setFinalStop(0, 350);
        plotGradient.setColorAt(0, QColor(80, 80, 80));
        plotGradient.setColorAt(1, QColor(50, 50, 50));
        ui->customPlot->setBackground(plotGradient);
        QLinearGradient axisRectGradient;
        axisRectGradient.setStart(0, 0);
        axisRectGradient.setFinalStop(0, 350);
        axisRectGradient.setColorAt(0, QColor(80, 80, 80));
        axisRectGradient.setColorAt(1, QColor(30, 30, 30));
        ui->customPlot->axisRect()->setBackground(axisRectGradient);

        // set line style
        QPen pen = ui->customPlot->graph(0)->pen();
        pen.setColor(Qt::cyan);// cyan
        ui->customPlot->graph(0)->setPen(pen);

        pen.setStyle(Qt::PenStyle::DashLine);// Dashs separated by a few pixels
        pen.setColor(Qt::white);// white
        ui->customPlot->graph(3)->setPen(pen);
        ui->customPlot->graph(4)->setPen(pen);
        ui->customPlot->graph(5)->setPen(pen);
    }
    ui->customPlot->replot(QCustomPlot::rpQueuedReplot);
}
