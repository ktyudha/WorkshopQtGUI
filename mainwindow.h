#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <QComboBox>
#include <QCheckBox>
#include <QTextBrowser>
#include <QTextEdit>

#include <QSerialPort>
#include <QSerialPortInfo>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

    /*QPushButton *btnSend; *///pointer
    QPushButton *btnRescan, *btnConnect, *btnSend, *btnClear;
    QComboBox *cbPort, *cbBaudrate, *cbDataBits, *cbParity, *cbStopBits;
    QTextBrowser *textBrowser;
    QTextEdit *teSend;
    QCheckBox *checkBoxCR;

    QSerialPort *serial;
    QSerialPortInfo *serialInfo;

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

public slots:
//    void closeWindow();
    void slotRescan();
    void slotConnect();
    void slotClear();
    void slotSend();

    void slotSerialReceiveData();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
