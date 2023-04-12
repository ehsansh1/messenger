#include "page2.h"
#include "ui_page2.h"

#include <QSqlDatabase>
#include "QSqlDriver"
#include "QSqlQuery"
#include "QSqlQueryModel"
#include "qdebug.h"
#include "qstackedlayout.h"
#include "qmessagebox.h"

int r;



Page2::Page2(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Page2)
{
    ui->setupUi(this);
    ui->groupBox_2->hide();

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
    if(r==0){
        if(ui->lineEdit_checkCapcha->text()!="a2we"){
            QMessageBox::information(this,"","wrong capha");
        }
    }
    if(r==1){
        if(ui->lineEdit_checkCapcha->text()!="a2we"){
            QMessageBox::information(this,"","wrong capha");
        }
    }
    if(r==2){
        if(ui->lineEdit_checkCapcha->text()!="8u3j"){
            QMessageBox::information(this,"","wrong capha");
        }
    }
    if(r==3){
        if(ui->lineEdit_checkCapcha->text()!="dqrt"){
            QMessageBox::information(this,"","wrong capha");
        }
    }
    if(r==4){
        if(ui->lineEdit_checkCapcha->text()!="rtfh"){
            QMessageBox::information(this,"","wrong capha");
        }
    }
    if(r==5){
        if(ui->lineEdit_checkCapcha->text()!="yocf"){
            QMessageBox::information(this,"","wrong capha");
        }
    }
    if(r==6){
        if(ui->lineEdit_checkCapcha->text()!="zmnc"){
            QMessageBox::information(this,"","wrong capha");
        }
    }
    if(r==7){
        if(ui->lineEdit_checkCapcha->text()!="pkdw"){
            QMessageBox::information(this,"","wrong capha");
        }
    }
    if(r==8){
        if(ui->lineEdit_checkCapcha->text()!="spef"){
            QMessageBox::information(this,"","wrong capha");
        }
    }





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



void Page2::on_pushButton_2_clicked()
{
    ui->groupBox_2->show();
    ui->groupBox->hide();



        r= rand()%9;


            ui->label_capcha->setStyleSheet("border-image: url(:/new/prefix1/Capture1.JPG);");
        }
void Page2::on_pushButton_generate_capcha_clicked()
{
    ui->statusbar->showMessage("clicked");
    r= rand()%9;
    switch(r){
    case 0:
        ui->label_capcha->setStyleSheet("border-image: url(:/new/prefix1/Capture1.JPG);");
        break;
    case 1:
        ui->label_capcha->setStyleSheet("border-image: url(:/new/prefix1/Capture2.JPG);");
        break;
    case 2:
        ui->label_capcha->setStyleSheet("border-image: url(:/new/prefix1/Capture3.JPG);");
        break;
    case 3:
        ui->label_capcha->setStyleSheet("border-image: url(:/new/prefix1/Capture4.JPG);");
        break;
    case 4:
        ui->label_capcha->setStyleSheet("border-image: url(:/new/prefix1/Capture5.JPG);");
        break;
    case 5:
        ui->label_capcha->setStyleSheet("border-image: url(:/new/prefix1/Capture6.JPG);");
        break;
    case 6:
        ui->label_capcha->setStyleSheet("border-image: url(:/new/prefix1/Capture7.JPG);");
        break;
    case 7:
        ui->label_capcha->setStyleSheet("border-image: url(:/new/prefix1/Capture8.JPG);");
        break;
    case 8:
        ui->label_capcha->setStyleSheet("border-image: url(:/new/prefix1/Captur9.JPG);");
        break;
    }
}

