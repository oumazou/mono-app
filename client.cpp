#include "client.h"

Client::Client()
{
    ID = 0;
    Nom = "";
    Prenom = "";
    Sexe = "";
    Adresse = "";
    Etat = 0;
    Num = "";
}

Client::Client(int id,QString nom,QString prenom,QString sexe,QString adresse,int etat,QString num)
{
    ID = id;
    Nom = nom;
    Prenom = prenom;
    Sexe = sexe;
    Adresse = adresse;
    Etat = etat;
    Num = num;
}

int Client::getID()
{
    return ID;
}

void Client::setID(int id)
{
    ID = id;
}

QString Client::getNom()
{
    return Nom;
}

void Client::setNom(QString nom)
{
    Nom = nom;
}

QString Client::getPrenom()
{
    return Prenom;
}

void Client::setPrenom(QString prenom)
{
    Prenom = prenom;
}

QString Client::getSexe()
{
    return Sexe;
}

void Client::setSexe(QString sexe)
{
    Sexe = sexe;
}

QString Client::getAdresse()
{
    return Adresse;
}

void Client::setAdresse(QString adresse)
{
    Adresse = adresse;
}

int Client::getEtat()
{
    return Etat;
}

void Client::setEtat(int etat)
{
    Etat = etat;
}

QString Client::getNum()
{
    return Num;
}

void Client::setNum(QString num)
{
    Num = num;
}

QSqlQueryModel* Client::Afficher()
{
    QSqlQuery query;
    QSqlQueryModel *model = new QSqlQueryModel();
    model->setQuery("select * from system.client order by id");

    return model;
}

QSqlQueryModel* Client::Afficher_ID()
{
    QSqlQuery query;
    QSqlQueryModel *model = new QSqlQueryModel();
    model->setQuery("select id from system.client order by id");

    return model;
}

QSqlQueryModel* Client::recheche(QString x)
{
    QSqlQuery query;
    QSqlQueryModel *model = new QSqlQueryModel();
    query.prepare("select * from system.client where nom like :nom" );
    query.bindValue(":nom*", QString("%%1%").arg(x));
    query.exec();
    model->setQuery(query);

    return model;
}

bool Client::Ajouter()
{
    QSqlQuery query;
    query.prepare("insert into system.client (id, nom, prenom, sexe, adresse, etat, num) values (:id, :nom, :prenom, :sexe, :adresse, 1, :num)");
    query.bindValue(":id",QString::number(ID));
    query.bindValue(":nom",Nom);
    query.bindValue(":prenom",Prenom);
    query.bindValue(":sexe",Sexe);
    query.bindValue(":adresse",Adresse);
    query.bindValue(":num",Num);

    return query.exec();
}

bool Client::Supprimer()
{
    QSqlQuery query;
    query.prepare("delete from system.client where id = ?");
    query.addBindValue(ID);

    return query.exec();
}

bool Client::Modifier(int x)
{
    QSqlQuery query;
    query.prepare("update system.client set etat = ? where id = ?");
    query.addBindValue(x);
    query.addBindValue(ID);

    return query.exec();
}

bool Client::Modifier_Adr(QString x)
{
    QSqlQuery query;
    query.prepare("update system.client set adresse = ? where id = ?");
    query.addBindValue(x);
    query.addBindValue(ID);

    return query.exec();
}

bool Client::Modifier_Num(QString x)
{
    QSqlQuery query;
    query.prepare("update system.client set num = ? where id = ?");
    query.addBindValue(x);
    query.addBindValue(ID);

    return query.exec();
}

bool Client::verif()
{
    QSqlQuery query;
    query.prepare("select * from system.client where id = ?");
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
