#ifndef PGAE4_H
#define PGAE4_H

#include <QMainWindow>

namespace Ui {
class pgae4;
}

class pgae4 : public QMainWindow
{
    Q_OBJECT

public:
    explicit pgae4(QWidget *parent = nullptr);
    ~pgae4();

private:
    Ui::pgae4 *ui;
};

#endif // PGAE4_H
