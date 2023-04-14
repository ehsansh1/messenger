#include "page2.h"
#include "ui_page2.h"

#include "PublicAttributes.h"
#include "page3.h"
#include <QSqlDatabase>
#include "QSqlDriver"
#include "QSqlQuery"
#include "QSqlQueryModel"
#include "qdebug.h"
#include "qstackedlayout.h"
#include "qmessagebox.h"
#include "confirmationcode.h"
QString string_captcha;


int r_global = 0;

Page2::Page2(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Page2)
{
    ui->setupUi(this);
    ui->groupBox_2->hide();
    ui->pushButton_back->hide();
    ui->label_capcha->setEnabled(false);

    QFont font;

    // Set the font size to 14
    font.setPointSize(14);

    // Apply the font to the label
    ui->label_capcha->setFont(font);

        database=QSqlDatabase::addDatabase("QSQLITE");
        database.setDatabaseName("C:\\mydb\\messangerProject.db");
        database.open();

        if(!database.open()){
            ui->label_satus->setText("1failed to open database");
        }
       else{
            ui->label_satus->setText("connected...");
        }
}

Page2::~Page2()
{
    delete ui;
}

QString Page2::generateCaptcha()
{
    {int length = 4;
        // Define the characters that can be used in the CAPTCHA
        const QString chars = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";

        // Initialize the random number generator
        srand(time(0));

        // Generate the random string of the specified length
        QString captcha = "";
        for (int i = 0; i < length; i++) {
            captcha += chars[rand() % chars.length()];
        }

        return captcha;
    }
}

bool Page2::checkusername(QString s)
{
        if(s[0]>=48 && s[0]<=57){
            QMessageBox::warning(this,"","username shoudn't start with number");
            return false ;
        }
        if(s.length()<5){
            QMessageBox::warning(this,"","username shoudn't be smaller less than 5 charcter");
            return false;
        }
        return true;
}

bool Page2::checkchar(QString s)
{
    int i;
    for(i=0;i<s.length();i++){
         if((s[i]>=35 && s[i]<=38) || s[i]== 42 || s[i]== 94)
         {
            return true;
         }
    }
    return false;
}

bool Page2::checkpassword(QString s)
{
    if(s.length()<7){
        QMessageBox::warning(this,"","password should be more than 6 charecter");
        return false;
    }
    if (checkchar(s)==0){
         QMessageBox::warning(this,"","password must include this charecters ($ # % ^ & *)");
        return false;
    }
    return true;
}








void Page2::on_pushButtonlogin_clicked()
{

        QString username,password;
        username=ui->lineEdit_username->text();
        password=ui->lineEdit_password->text();

        if(!database.isOpen()){
            qDebug()<<  "failed to open the database";
            return ;
        }


        QSqlQuery qry;
        if(qry.exec("SELECT name FROM messangerDatabase  where name = '"+username+"'  and password = '"+password+"' " )){
        int count=0;
        while(qry.next()){
            count++;
        }
            if(count==1){
                ui->label_satus->setText("username and password is correct");


                confirmation_r ob;
                ob.r=rand()%10000;
                r_global = ob.r;



                page3 *newW3 = new page3;
                this->hide();
                newW3->show();

                 QMessageBox::warning(this,"","your confirmation code is"+QString::number(ob.r));






            }
            if(count>1){
                ui->label_satus->setText("dupliate username and password ");
            }
            if(count<1){
                ui->label_satus->setText("username and password is not correct");
            }
        }
        else {
            qDebug()<< "database not loaded";
        }
}


void Page2::on_pushButton_singin_clicked()

{
    QString username2,password2;
    username2=ui->lineEdit_username_2->text();

    if(!database.isOpen()){
        qDebug()<<  "failed to open the database";
        return ;
    }


    QSqlQuery qry;
    qry.exec("SELECT name FROM messangerDatabase  where name = '"+username2+"' " );
    if(qry.first()){
         QMessageBox::warning(this,"","duplicat username");
         return;
    }



    QString s2;
    s2=ui->lineEdit_username_2->text();
    if(checkusername(s2)==0){
        return;
    }
    s2=ui->lineEdit_password_2->text();
    if(checkpassword(s2)==0){
        return;
    }
    if(ui->lineEdit_checkCapcha->text()!=string_captcha){
            QMessageBox::information(this,"","wrong capha");
            return;
    }

        username2=ui->lineEdit_username_2->text();
        password2=ui->lineEdit_password_2->text();

        if(!database.isOpen()){
             qDebug()<<  "failed to open the database";
             return ;
         }

             qry.prepare("INSERT INTO messangerDatabase(name,password)values('"+username2+"','"+password2+"' ) ");
             if(qry.exec()){
                 QMessageBox::information(this,"","done!");
             }


         confirmation_r ob;
         ob.r=rand()%10000;
         r_global = ob.r;



         page3 *w3 = new page3;
         this->hide();
         w3->show();

          QMessageBox::warning(this,"","your confirmation code is"+QString::number(ob.r));




    }




void Page2::on_pushButton_2_clicked()
{   ui->pushButton_back->show();
    ui->groupBox_2->show();
    ui->groupBox->hide();

        string_captcha = generateCaptcha();
        ui->label_capcha->setText(string_captcha);

        }
void Page2::on_pushButton_generate_capcha_clicked()
{
    string_captcha = generateCaptcha();
    ui->label_capcha->setText(string_captcha);
    ui->label_capcha->setEnabled(false);

}


void Page2::on_pushButton_back_clicked()
{   ui->pushButton_back->hide();
    ui->groupBox->show();
    ui->groupBox_2->hide();

}


int sw=0;



void Page2::on_pushButton_showpass_clicked()
{
    if(sw==0){
        ui->lineEdit_password_2->setEchoMode(QLineEdit::Normal);
        ui->pushButton_showpass->setStyleSheet("border-image: url(:/new/prefix1/hide pass.jpg);");
        sw=1;
        return;
        }
    ui->pushButton_showpass->setStyleSheet("border-image: url(:/new/prefix1/show pass.jpg);");
          ui->lineEdit_password_2->setEchoMode(QLineEdit::Password);
    sw=0;

}

