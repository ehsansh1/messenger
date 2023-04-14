#include "page3.h"
#include "ui_page3.h"

#include "page4.h"
#include "qstring.h"
#include "qmessagebox.h"
<<<<<<< HEAD

#include "confirmationcode.h"
=======
<<<<<<< HEAD
>>>>>>> b810aeec8e7c09d68e7ca96bf5104e924d5fa0b9

#include "confirmationcode.h"

=======
int r;
>>>>>>> 1ff2400dd384783fc2575d3afe0aaf9bbf95c6b4
page3::page3(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::page3)
{
    ui->setupUi(this);

<<<<<<< HEAD
=======
<<<<<<< HEAD
=======
    r=rand()%10000;
    QMessageBox::warning(this,"","your confirmation code is"+QString::number(r));
>>>>>>> 1ff2400dd384783fc2575d3afe0aaf9bbf95c6b4
>>>>>>> b810aeec8e7c09d68e7ca96bf5104e924d5fa0b9
}

page3::~page3()
{
    delete ui;
}





void page3::on_pushButton_checkcinfirmation_clicked()
{
    int s;
    s=ui->lineEdit_confirmation->text().toInt();
<<<<<<< HEAD
    int r_value = r_global;

    if(r_value==s){
=======
<<<<<<< HEAD
    int r_value = r_global;

    if(r_value==s){
=======

    if(r==s){
>>>>>>> 1ff2400dd384783fc2575d3afe0aaf9bbf95c6b4
>>>>>>> b810aeec8e7c09d68e7ca96bf5104e924d5fa0b9
        QMessageBox::information(this,"","confirmation done!");
        page4 *w4 = new page4;
        this->hide();
        w4->show();
    }
    else {
        QMessageBox::information(this,"","wrong code");
    }

}


