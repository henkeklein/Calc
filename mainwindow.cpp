#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QtCore/QCoreApplication>

QString value= "", total="";
int fNum, sNum;
bool addBool = false, subtractBool=false, multiplyBool=false, divideBool=false;
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent)
{
    label = new QLabel("0", this);
    label->setGeometry(QRect(QPoint(75,25), QSize(50, 200)));

    clear_button = new QPushButton("C", this);
    clear_button ->setGeometry(QRect(QPoint(125, 300), QSize(50,50)));
    connect(clear_button, SIGNAL(released()), this, SLOT(clear()));

    equals_button = new QPushButton("=", this);
    equals_button ->setGeometry(QRect(QPoint(175, 300), QSize(50,50)));
    connect(equals_button, SIGNAL(released()), this, SLOT(equals()));

    add_button = new QPushButton("+", this);
    add_button ->setGeometry(QRect(QPoint(225, 150), QSize(50,50)));
    connect(add_button, SIGNAL(released()), this, SLOT(add()));

    subtract_button = new QPushButton("-", this);
    subtract_button ->setGeometry(QRect(QPoint(225, 200), QSize(50,50)));
    connect(subtract_button, SIGNAL(released()), this, SLOT(subtract()));

    multiply_button = new QPushButton("*", this);
    multiply_button ->setGeometry(QRect(QPoint(225, 250), QSize(50,50)));
    connect(multiply_button, SIGNAL(released()), this, SLOT(multiply()));

    divide_button = new QPushButton("/", this);
    divide_button ->setGeometry(QRect(QPoint(225, 300), QSize(50,50)));
    connect(divide_button, SIGNAL(released()), this, SLOT(divide()));

    for (int i=0;i<10; i++){
        QString digit= QString::number(i);
        buttons[i]= new QPushButton(digit, this);
        connect(buttons[i], SIGNAL(released()), this, SLOT(buttonPushed()));
    }
    setGeo();
}

void MainWindow::buttonPushed(){
    QPushButton *button = (QPushButton *)sender();
    emit numberEmitted(button->text()[0].digitValue());
    value += QString::number(button->text()[0].digitValue());
    label->setText(value);
}

void MainWindow::setGeo(){
    for (int i=0; i<1; i++){
        buttons[i]->setGeometry(QRect(QPoint(50, 300), QSize(50,50)));
    }

    for (int i=1; i<4; i++){
        buttons[i]->setGeometry(QRect(QPoint(50*i, 250), QSize(50,50)));
    }

    for (int i=4; i<7; i++){
        buttons[i]->setGeometry(QRect(QPoint(50*(i-3), 200), QSize(50,50)));
    }

    for (int i=7; i<10; i++){
        buttons[i]->setGeometry(QRect(QPoint(50*(i-6), 150), QSize(50,50)));
    }


}

void MainWindow::clear(){
    value="";
    label->setText(value);

}

void MainWindow::equals(){
    sNum= value.toInt();
    if(addBool){
        total=QString::number(fNum+sNum);
        label->setText(total);
    }
    if(subtractBool){
        total=QString::number(fNum-sNum);
        label->setText(total);

    }
    if(multiplyBool){
        total=QString::number(fNum*sNum);
        label->setText(total);

    }
    if(divideBool){
        total=QString::number(fNum/sNum);
        label->setText(total);

    }

}

void MainWindow::add(){
    fNum = value.toInt();
    value = "";
    label->setText(value);
    addBool=true;

}

void MainWindow::subtract(){
    fNum = value.toInt();
    value = "";
    label->setText(value);
    subtractBool=true;

}

void MainWindow::multiply(){
    fNum = value.toInt();
    value = "";
    label->setText(value);
    multiplyBool=true;

}

void MainWindow::divide(){
    fNum = value.toInt();
    value = "";
    label->setText(value);
    divideBool=true;

}


MainWindow::~MainWindow()
{

}
