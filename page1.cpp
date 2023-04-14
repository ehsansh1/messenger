#include "page1.h"
#include "ui_page1.h"
#include "page2.h"


Page1::Page1(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Page1)
{
    ui->setupUi(this);

}

Page1::~Page1()
{
    delete ui;

}


void Page1::on_pushButton_clicked()
{
    this->hide();
    page2 *p2 = new page2;
    p2->show();



}

