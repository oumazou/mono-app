#include "mainwindow.h"
#include "connexion.h"
#include <QMessageBox>
#include <QApplication>
#include <QtDebug>

int main(int argc, char *argv[])
{
    connexion c;

        bool test=c.ouvrirConnexion();
        QApplication a(argc, argv);
        MainWindow w;

        if(test)
        {w.show();



        }
        else
            QMessageBox::critical(nullptr, QObject::tr("database is not open"),
                        QObject::tr("connection failed.\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);

          return a.exec();
}
