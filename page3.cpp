#include "page3.h"
#include "ui_page3.h"

#include "page4.h"
#include "qstring.h"
#include "qmessagebox.h"

#include "confirmationcode.h"

page3::page3(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::page3)
{
    ui->setupUi(this);

}

page3::~page3()
{
    delete ui;
}





void page3::on_pushButton_checkcinfirmation_clicked()
{
    int s;
    s=ui->lineEdit_confirmation->text().toInt();
    int r_value = r_global;

    if(r_value==s){
        QMessageBox::information(this,"","confirmation done!");
        page4 *w4 = new page4;
        this->hide();
        w4->show();
    }
    else {
        QMessageBox::information(this,"","wrong code");
    }

}


