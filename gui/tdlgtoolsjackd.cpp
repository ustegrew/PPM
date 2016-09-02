#include "tdlgtoolsjackd.h"
#include "ui_tdlgtoolsjackd.h"

TDlgToolsJackD::TDlgToolsJackD(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::TDlgToolsJackD)
{
    ui->setupUi(this);
}

TDlgToolsJackD::~TDlgToolsJackD()
{
    delete ui;
}
