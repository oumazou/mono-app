#ifndef CONNECTION_H
#define CONNECTION_H

#include <QsqlDatabase>
#include <QsqlError>
#include <QsqlQuery>

class Connection
{
private:
    QSqlDatabase db;
public:
    Connection();
    bool createconnect();
    void close();
};

#endif // CONNECTION_H
