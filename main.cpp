#include "mainwindow.h"
#include "connection.h"
#include <QApplication>
#include "login.h"

int main(int argc, char *argv[])
{
    Connection c;

    QApplication a(argc, argv);
    login l;
    c.createconnect();
    l.show();

    return a.exec();
}
