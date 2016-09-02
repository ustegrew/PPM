#include "twndmain.h"
#include "ui_twndmain.h"

TWndMain::TWndMain(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::TWndMain)
{
    ui->setupUi(this);
}

TWndMain::~TWndMain()
{
    delete ui;
}
