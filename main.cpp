#include "login.h"
#include <QApplication>
#include <QString>
#include <QObject>
#include <QDebug>
int main(int argc, char *argv[])
{

    QApplication a(argc, argv);
    login W;
    W.show();
    return a.exec();
}
