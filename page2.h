#ifndef PAGE2_H
#define PAGE2_H

#include <QMainWindow>

#include <QSqlDatabase>
#include "QSqlDriver"
#include "QSqlQuery"
#include "QSqlQueryModel"

namespace Ui {
class Page2;
}

class Page2 : public QMainWindow
{
    Q_OBJECT

public:
    explicit Page2(QWidget *parent = nullptr);
    ~Page2();
public slots:
    QString generateCaptcha();
    int checkusername(QString s);
private slots:


    void on_pushButtonlogin_clicked();

    void on_pushButton_singin_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_generate_capcha_clicked();



    void on_pushButton_back_clicked();

private:
    Ui::Page2 *ui;
     QSqlDatabase  database;

};

#endif // PAGE2_H
