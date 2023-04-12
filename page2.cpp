#include "page2.h"
#include "ui_page2.h"

#include <QSqlDatabase>
#include "QSqlDriver"
#include "QSqlQuery"
#include "QSqlQueryModel"
#include "qdebug.h"
#include "qstackedlayout.h"
#include "qmessagebox.h"

QString s;



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

int Page2::checkusername(QString s)
{
    int i;
    for(i=0;i<s.length();i++){

    }
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
    if(ui->lineEdit_checkCapcha->text()!=s){
            QMessageBox::information(this,"","wrong capha");
    }
    else
    {
        QString username2,password2;
        username2=ui->lineEdit_username_2->text();
        password2=ui->lineEdit_password_2->text();

       if(!database.isOpen()){
            qDebug()<<  "failed to open the database";
            return ;
        }

        QSqlQuery qry;
        qry.prepare("insert into messangerDatabase(name,password)values('"+username2+"','"+password2+"' ) ");
        if(qry.exec()){
            QMessageBox::information(this,"","done!");
        }
    }
}



void Page2::on_pushButton_2_clicked()
{
    ui->groupBox_2->show();
    ui->groupBox->hide();

        s = generateCaptcha();
        ui->label_capcha->setText(s);

        }
void Page2::on_pushButton_generate_capcha_clicked()
{
    s = generateCaptcha();
    ui->label_capcha->setText(s);
    ui->label_capcha->setEnabled(false);

}


void Page2::on_pushButton_back_clicked()
{   ui->pushButton_back->show();
    ui->groupBox->show();
    ui->groupBox_2->hide();

}

