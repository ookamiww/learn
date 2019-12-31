#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    btn = new QPushButton("test",this);
    circleBtn();

}

Widget::~Widget()
{
    delete ui;
}


void Widget::circleBtn()
{
    QFile *file = new QFile("./redCircleBtn.qss");
    file->open(QFile::ReadOnly);
    QString str = file->readAll();
    this->setStyleSheet(str);
}

