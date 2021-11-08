#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <turing.cpp>
#include <turing_1.cpp>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);


//    qTime.start();


}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    QByteArray tmp = this->ui->inputEdit->text().toLatin1();
    QByteArrayList listtmp=tmp.split('+');
    QByteArrayList list;
    for(int i=0;i<listtmp.length();i++){
//        qDebug()<<tmp[i] ;
//        QByteArrayList ttmp=listtmp[i].split('*');
        list.append(listtmp[i].split('*'));
    }
    for(int i=0;i<list.length();i++){
        if(list[i].contains('^')){
            list[i]=list[i].split('^')[0];
        }
    }
//    qDebug()<<list;
//    Turing* tur = new Turing();
//    tur->initialize(list);
    Turing_1* tur = new Turing_1();
    qTime.start();
    tur->initialize(list);

    ui->outputtextEdit->setText(tur->tape);
    ui->result->setText(QString::number(tur->result));
    double ctime=qTime.elapsed()/1000.0;
//    qDebug()<<qTime.elapsed();
    QString runtimecount=QString::number(ctime, 'f', 3)+"s";

    ui->runtime->setText(runtimecount);

//    2*3^2+3*4
//    11*23^2+34*45
//    23*34^2+45*56




}
