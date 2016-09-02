#ifndef TDLGTOOLSJACKD_H
#define TDLGTOOLSJACKD_H

#include <QDialog>

namespace Ui {
class TDlgToolsJackD;
}

class TDlgToolsJackD : public QDialog
{
    Q_OBJECT

public:
    explicit TDlgToolsJackD(QWidget *parent = 0);
    ~TDlgToolsJackD ();

private:
    Ui::TDlgToolsJackD *ui;
};

#endif // TDLGTOOLSJACKD_H
