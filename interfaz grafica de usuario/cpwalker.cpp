#include "cpwalker.h"
#include "ui_cpwalker.h"

CPWalker::CPWalker(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::CPWalker)
{
    ui->setupUi(this);
    imprimir[0]='0';
    imprimir[1]='0';
    imprimir[2]='0';
    imprimir[3]='0';
    imprimir[4]='0';
    imprimir[5]='0';
    imprimir[6]='0';
    modo=0;
    invisibilidad();

    tx=new QNetworkAccessManager(this);
    ip="http://192.168.43.54/";
}

CPWalker::~CPWalker()
{
    delete ui;
}

void CPWalker::visibilidad_manual(){

        ui->pushButton_6->show();
        ui->pushButton_7->show();
        ui->pushButton_8->show();
        ui->pushButton_9->show();
        ui->label_5->show();
        ui->verticalLayoutWidget_2->show();
        ui->pushButton_5->show();

}

void CPWalker::visibilidad_exo(){

        ui->verticalLayoutWidget_3->show();
        ui->pushButton_4->show();
        ui->pushButton_5->show();
        ui->label_3->show();
        ui->checkBox->show();
        ui->checkBox_2->show();
        ui->checkBox_3->show();
        ui->checkBox_4->show();


}

void CPWalker::visibilidad_sw(){

        ui->verticalLayoutWidget_2->show();
        ui->pushButton_4->show();
        ui->pushButton_5->show();
        ui->label_3->show();
        ui->checkBox->show();
        ui->checkBox_2->show();
        ui->checkBox_3->show();
        ui->checkBox_4->show();
        ui->verticalLayoutWidget_3->show();


}

void CPWalker::visibilidad_start(){

        ui->verticalLayoutWidget->hide();
        ui->pushButton_4->hide();

}

void CPWalker::visibilidad_stop(){

        ui->verticalLayoutWidget->show();

}

void CPWalker::invisibilidad(){


        ui->pushButton_6->hide();
        ui->pushButton_7->hide();
        ui->pushButton_8->hide();
        ui->pushButton_9->hide();
        ui->label_5->hide();
        ui->checkBox->hide();
        ui->checkBox_2->hide();
        ui->checkBox_3->hide();
        ui->checkBox_4->hide();
        ui->verticalLayoutWidget_2->hide();
        ui->verticalLayoutWidget_3->hide();
        ui->label_3->hide();
        ui->pushButton_4->hide();
        ui->pushButton_5->hide();

}

void CPWalker::on_pushButton_clicked() // exo-solo
{
    invisibilidad();
    visibilidad_exo();
    ui->pushButton->setStyleSheet("background-color: rgb(11, 98, 227)");
    ui->pushButton_2->setStyleSheet("background-color: none");
    ui->pushButton_3->setStyleSheet("background-color: none");
    ui->checkBox->setChecked(false);
    ui->checkBox_2->setChecked(false);
    ui->checkBox_3->setChecked(false);
    ui->checkBox_4->setChecked(false);

    imprimir[0]='1';
    imprimir[1]='5';
    imprimir[2]='0';
    imprimir[3]='0';
    imprimir[4]='0';
    imprimir[5]='0';
    imprimir[6]='0';
    ui->lcdNumber_2->display(0);
    ui->horizontalSlider_2->setValue(0);
}

void CPWalker::on_pushButton_2_clicked() // exo-sw
{
    invisibilidad();
    visibilidad_sw();
    ui->pushButton_2->setStyleSheet("background-color: rgb(11, 98, 227)");
    ui->pushButton->setStyleSheet("background-color: none");
    ui->pushButton_3->setStyleSheet("background-color: none");
    ui->checkBox->setChecked(false);
    ui->checkBox_2->setChecked(false);
    ui->checkBox_3->setChecked(false);
    ui->checkBox_4->setChecked(false);
    imprimir[0]='2';
    imprimir[1]='5';
    imprimir[2]='0';
    imprimir[3]='0';
    imprimir[4]='0';
    imprimir[5]='0';
    imprimir[6]='0';
    ui->lcdNumber->display(5);
    ui->horizontalSlider->setValue(5);
    ui->lcdNumber_2->display(0);
    ui->horizontalSlider_2->setValue(0);
}

void CPWalker::on_pushButton_3_clicked() // exo-manual
{
    invisibilidad();
    visibilidad_manual();
    ui->pushButton_3->setStyleSheet("background-color: rgb(11, 98, 227)");
    ui->pushButton_2->setStyleSheet("background-color: none");
    ui->pushButton->setStyleSheet("background-color: none");
    imprimir[0]='3';
    imprimir[1]='5';
    imprimir[2]='0';
    imprimir[3]='0';
    imprimir[4]='0';
    imprimir[5]='0';
    imprimir[6]='0';
    ui->lcdNumber->display(5);
    ui->horizontalSlider->setValue(5);

}

void CPWalker::on_pushButton_4_clicked()  // start
{
    visibilidad_start();
    datos=(QString)imprimir;
    reply=tx->get(QNetworkRequest(QUrl(ip+datos)));
    connect(reply,SIGNAL(readyRead()),this,SLOT(slotReadyRead()));
    ui->lineEdit->setText(datos);

}

void CPWalker::on_pushButton_5_clicked() // stop
{
    invisibilidad();
    visibilidad_stop();

    if(imprimir[0]=='1'){
        visibilidad_exo();

    }
    else{
        if(imprimir[0]=='2'){
            visibilidad_sw();
        }
        else{
            visibilidad_manual();
        }
    }
    modo=imprimir[0];
    imprimir[0]='0';
    datos=(QString)imprimir;
    reply=tx->get(QNetworkRequest(QUrl(ip+datos)));
    connect(reply,SIGNAL(readyRead()),this,SLOT(slotReadyRead()));
    imprimir[0]=modo;
    ui->lineEdit->setText(datos);

}

void CPWalker::on_pushButton_6_pressed() // adelante presionado
{
    imprimir[2]='1';
    datos=QString(imprimir);
    reply=tx->get(QNetworkRequest(QUrl(ip+datos)));
    connect(reply,SIGNAL(readyRead()),this,SLOT(slotReadyRead()));
    ui->lineEdit->setText(datos);
    ui->pushButton_6->setStyleSheet("border-image: url(:/arriba.png)");

}

void CPWalker::on_pushButton_6_released()  // adelante soltar
{
    imprimir[2]='0';
    datos=QString(imprimir);
    reply=tx->get(QNetworkRequest(QUrl(ip+datos)));
    connect(reply,SIGNAL(readyRead()),this,SLOT(slotReadyRead()));
    ui->lineEdit->setText(datos);
    ui->pushButton_6->setStyleSheet("border-image: url(:/flecha_ar.png)");
}

void CPWalker::on_pushButton_7_pressed() // derecha presionado
{
    imprimir[5]='1';
    datos=QString(imprimir);
    reply=tx->get(QNetworkRequest(QUrl(ip+datos)));
    connect(reply,SIGNAL(readyRead()),this,SLOT(slotReadyRead()));
    ui->lineEdit->setText(datos);
    ui->pushButton_7->setStyleSheet("border-image: url(:/derecha.png)");
}

void CPWalker::on_pushButton_7_released() // derecha soltar
{
    imprimir[5]='0';
    datos=QString(imprimir);
    reply=tx->get(QNetworkRequest(QUrl(ip+datos)));
    connect(reply,SIGNAL(readyRead()),this,SLOT(slotReadyRead()));
    ui->lineEdit->setText(datos);
    ui->pushButton_7->setStyleSheet("border-image: url(:/flecha_d.png)");

}

void CPWalker::on_pushButton_8_pressed()  // izquierda presionado
{
    imprimir[4]='1';
    datos=QString(imprimir);
    reply=tx->get(QNetworkRequest(QUrl(ip+datos)));
    connect(reply,SIGNAL(readyRead()),this,SLOT(slotReadyRead()));
    ui->lineEdit->setText(datos);
    ui->pushButton_8->setStyleSheet("border-image: url(:/izquierda.png)");
}


void CPWalker::on_pushButton_8_released()  // izquierda soltar
{
    imprimir[4]='0';
    datos=QString(imprimir);
    reply=tx->get(QNetworkRequest(QUrl(ip+imprimir)));
    connect(reply,SIGNAL(readyRead()),this,SLOT(slotReadyRead()));
    ui->lineEdit->setText(datos);
    ui->pushButton_8->setStyleSheet("border-image: url(:/flecha_i.png)");
}

void CPWalker::on_pushButton_9_pressed()  // abajo presionado
{
    imprimir[3]='1';
    datos=QString(imprimir);
    reply=tx->get(QNetworkRequest(QUrl(ip+imprimir)));
    connect(reply,SIGNAL(readyRead()),this,SLOT(slotReadyRead()));
    ui->lineEdit->setText(datos);
    ui->pushButton_9->setStyleSheet("border-image: url(:/abajo.png)");
}

void CPWalker::on_pushButton_9_released()  // abajo soltar
{
    imprimir[3]='0';
    datos=(QString)imprimir;
    reply=tx->get(QNetworkRequest(QUrl(ip+datos)));
    connect(reply,SIGNAL(readyRead()),this,SLOT(slotReadyRead()));
    ui->lineEdit->setText(datos);
    ui->pushButton_9->setStyleSheet("border-image: url(:/flecha_ab.png)");
}

void CPWalker::on_horizontalSlider_valueChanged(int value) // velocidad
{
    ui->lcdNumber->display(value);
    if(value==12||value==14){
        imprimir[1]=(value+1)+48;}
    else{
    imprimir[1]=value+48;}
}

void CPWalker::on_horizontalSlider_2_valueChanged(int value) // apertura
{
    ui->lcdNumber_2->display(value);
    if(value==16 || value==60||value==57||value==62 || value==19){
        imprimir[2]=((value+1)*0.78)+48;}
    else{
        if(value==59||value==97||value==98||value==99||value==18){
            imprimir[2]=((value-3)*0.78)+48;}
        else{
            imprimir[2]=(value*0.78)+48;}
   }

}

void CPWalker::on_checkBox_clicked(bool checked)  // cadera derecha
{
    imprimir[4]=checked+48;
}

void CPWalker::on_checkBox_2_clicked(bool checked)  // rodilla derecha
{
    imprimir[6]=checked+48;
}

void CPWalker::on_checkBox_3_clicked(bool checked)  // cadera izquierda
{
    imprimir[3]=checked+48;
}

void CPWalker::on_checkBox_4_clicked(bool checked)  // rodilla izquierda
{
    imprimir[5]=checked+48;
}


