#include "connection.h"

Connection::Connection()
{

}

bool Connection::createconnect()
{
    bool test = false;

    db = QSqlDatabase::addDatabase("QODBC");
    db.setDatabaseName("Source_Projet2A");
    db.setUserName("system");
    db.setPassword("bounour25445438");
    if(db.open())
    {
        test = true;
    }
    return test;
}

void Connection::close()
{
    db.close();
}
