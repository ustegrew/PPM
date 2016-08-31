#ifndef TWNDMAIN_H
#define TWNDMAIN_H

#include <QMainWindow>

namespace Ui {
class TWndMain;
}

class TWndMain : public QMainWindow
{
    Q_OBJECT

public:
    explicit TWndMain(QWidget *parent = 0);
    ~TWndMain();

private:
    Ui::TWndMain *ui;
};

#endif // TWNDMAIN_H
