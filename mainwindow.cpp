#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)  //constructor
{
    ui->setupUi(this);
//    btnSend = ui->btnSend;

//   //digunakan untuk ketika ingin di klik sesuatu langsung berinteraksi
    //object, signal, receive, slot

    btnRescan = ui->btnRescan;
    btnConnect = ui->btnConnect;
    btnSend = ui->btnSend;
    btnClear = ui->btnClear;

    connect(btnSend,&QPushButton::clicked,this, &MainWindow::slotSend);
    connect(btnConnect,&QPushButton::clicked,this, &MainWindow::slotConnect);
    connect(btnRescan,&QPushButton::clicked,this, &MainWindow::slotRescan);
    connect(btnClear,&QPushButton::clicked,this, &MainWindow::slotClear);

    cbPort = ui->cbPort;
    cbBaudrate = ui->cbBaudrate;
    cbParity = ui->cbParity;
    cbDataBits = ui->cbDataBits;
    cbStopBits = ui->cbStopBits;

    textBrowser = ui->textBrowser;
    teSend = ui->teSend;

    checkBoxCR = ui->checkBoxCR;

    serial = new QSerialPort();
    serialInfo = new QSerialPortInfo();

    connect(serial, &QSerialPort::readyRead,this, &MainWindow::slotSerialReceiveData);
}

MainWindow::~MainWindow()
{
    delete ui;
}

//void MainWindow::closeWindow() //method or function
//{
//    this->close(); //this adalah nama class saat ini atau
////    MainWindow::close();
//}

void MainWindow::slotRescan() {
    cbPort->clear();

    QList<QSerialPortInfo> listPort = serialInfo->availablePorts();

    for ( int i; i < listPort.length() ; i++ ) {
        cbPort->addItem(listPort.at(i).portName());
    }
}

void MainWindow::slotSend() {

}

void MainWindow::slotConnect() {
    serial->setBaudRate(QSerialPort::Baud115200);
    serial->setParity(QSerialPort::NoParity);
    serial->setDataBits(QSerialPort::Data8);
    serial->setStopBits(QSerialPort::OneStop);

    serial->setPortName(cbPort->currentText());

    serial->open(QIODevice::ReadWrite);

}

void MainWindow::slotClear() {

}

void MainWindow::slotSerialReceiveData() {
    QString currentText = textBrowser->toPlainText();
    textBrowser->setText(currentText + serial->readAll());

}
