#include "pgae4.h"
#include "ui_pgae4.h"

pgae4::pgae4(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::pgae4)
{
    ui->setupUi(this);
}

pgae4::~pgae4()
{
    delete ui;
}
