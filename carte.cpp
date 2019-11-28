#include "carte.h"

Carte::Carte()
{
    ID = 0;
    ID_Client = 0;
    Points = "";
}

Carte::Carte(int id,int id_client, QString points)
{
    ID = id;
    ID_Client = id_client;
    Points = points;
}

int Carte::getID()
{
    return ID;
}

void Carte::setID(int id)
{
    ID = id;
}

int Carte::getID_Client()
{
    return ID_Client;
}

void Carte::setID_Client(int id_client)
{
    ID_Client = id_client;
}

QString Carte::getPoints()
{
    return Points;
}

void Carte::setPoints(QString points)
{
    Points = points;
}

QSqlQueryModel* Carte::Afficher()
{
    QSqlQuery query;
    QSqlQueryModel *model = new QSqlQueryModel();
    model->setQuery("select * from system.carte order by id");

    return model;
}

QSqlQueryModel* Carte::Trier_points()
{
    QSqlQuery query;
    QSqlQueryModel *model = new QSqlQueryModel();
    model->setQuery("select * from system.carte order by points");

    return model;
}

bool Carte::Ajouter()
{
    QSqlQuery query;
    query.prepare("insert into system.carte (id, id_client, points) values (:id, :id_client, :points)");
    query.bindValue(":id",QString::number(ID));
    query.bindValue(":id_client",QString::number(ID_Client));
    query.bindValue(":points",Points);

    return query.exec();
}

bool Carte::Supprimer()
{
    QSqlQuery query;
    query.prepare("delete from system.carte where id = ?");
    query.addBindValue(ID);

    return query.exec();
}

bool Carte::Modifier(QString points)
{
    QSqlQuery query;
    query.prepare("update system.carte set points = ? where id = ?");
    query.addBindValue(points);
    query.addBindValue(ID);

    return query.exec();
}

bool Carte::verif()
{
    QSqlQuery query;
    query.prepare("select * from system.carte where id = ?");
    query.addBindValue(ID);
    if(query.exec())
    {
        int count = 0;
        while(query.next())
        {
            count++;
        }
        if(count == 0)
        {
            return true;
        }
        return false;
    }

    return query.exec();
}

bool Carte::verif_cl()
{
    QSqlQuery query;
    query.prepare("select * from system.client where id = ?");
    query.addBindValue(ID_Client);
    if(query.exec())
    {
        int count = 0;
        while(query.next())
        {
            count++;
        }
        if(count == 0)
        {
            return true;
        }
        return false;
    }

    return query.exec();
}
