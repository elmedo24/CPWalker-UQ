#ifndef CPWALKER_H
#define CPWALKER_H

#include <QMainWindow>
#include <QtSerialPort/QSerialPort>
#include <QNetworkAccessManager>
#include <QUrl>
#include <QNetworkReply>
#include <QNetworkRequest>
#include <math.h>

class QPushButton;

namespace Ui {
class CPWalker;
}

class CPWalker : public QMainWindow
{
    Q_OBJECT

public:
    explicit CPWalker(QWidget *parent = 0);
    ~CPWalker();
    void visibilidad_manual();
    void visibilidad_exo();
    void visibilidad_sw();
    void visibilidad_start();
    void visibilidad_stop();
    void invisibilidad();

private slots:
    void on_pushButton_3_clicked();

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_4_clicked();

    void on_horizontalSlider_valueChanged(int value);

    void on_horizontalSlider_2_valueChanged(int value);

    void on_pushButton_6_pressed();

    void on_pushButton_6_released();

    void on_pushButton_9_pressed();

    void on_pushButton_9_released();

    void on_pushButton_8_pressed();

    void on_pushButton_8_released();

    void on_pushButton_7_pressed();

    void on_pushButton_7_released();

    void on_checkBox_3_clicked(bool checked);

    void on_checkBox_clicked(bool checked);

    void on_checkBox_4_clicked(bool checked);

    void on_checkBox_2_clicked(bool checked);

private:
    Ui::CPWalker *ui;

    QSerialPort *puerto;
    QByteArray imprimir;
    QNetworkAccessManager *tx;
    QNetworkReply *reply;
    QString ip;
    QString datos;
    int modo;


};

#endif // CPWALKER_H
