#include "mainwindow.h"
#include "connection.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    Connection c;

    QApplication a(argc, argv);
    MainWindow w;
    c.createconnect();
    w.show();

    return a.exec();
}
