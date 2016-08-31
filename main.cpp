#include "twndmain.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    TWndMain w;
    w.show();

    return a.exec();
}
