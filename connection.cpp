#include "connection.h"
#include <QDebug>
Connection::Connection()
{

}

bool Connection::createconnect()

{
    bool test=false;
    QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
    db.setDatabaseName("test-bd");
    db.setUserName("mariem");//inserer nom de l'utilisateur
    db.setPassword("mariem");//inserer mot de passe de cet utilisateur
    if (db.open())
        test=true;
    else
        throw QString(db.lastError().text());
    return  test;
}
