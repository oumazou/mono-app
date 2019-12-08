#include "client.h"

Client::Client()
{
    cin = 0;
    Nom = "";
    Prenom = "";
    Sexe = "";
    Adresse = "";

    tel = "";
}

Client::Client(int cin,QString nom,QString prenom,QString sexe,QString adresse,QString tel)
{
    this->cin = cin;
    this->Nom = nom;
    this->Prenom = prenom;
    this->Sexe = sexe;
    this->Adresse = adresse;

    this->tel = tel;
}

bool Client::Ajouter()
{
    QSqlQuery query;
    query.prepare("insert into client (cin, nom, prenom, sexe, adresse, tel) values (:cin, :nom, :prenom, :sexe, :adresse, :tel)");
    query.bindValue(":cin",QString::number(cin));
    query.bindValue(":nom",Nom);
    query.bindValue(":prenom",Prenom);
    query.bindValue(":sexe",Sexe);
    query.bindValue(":adresse",Adresse);
    query.bindValue(":tel",tel);

    return query.exec();
}
QSqlQueryModel* Client::Afficher()
{
    QSqlQuery query;
    QSqlQueryModel *model = new QSqlQueryModel();
    model->setQuery("select * from client order by cin");
    model->setHeaderData(0, Qt::Horizontal,QObject::tr("cin"));
    model->setHeaderData(1, Qt::Horizontal,QObject::tr("nom"));
    model->setHeaderData(2, Qt::Horizontal,QObject::tr("prenom"));
    model->setHeaderData(3, Qt::Horizontal,QObject::tr("sexe"));
    model->setHeaderData(4, Qt::Horizontal,QObject::tr("adresse"));
    model->setHeaderData(5, Qt::Horizontal,QObject::tr("tel"));
    return model;
}
QSqlQueryModel* Client::AfficherCin()
{
    QSqlQuery query;
    QSqlQueryModel *model = new QSqlQueryModel();
    model->setQuery("select cin from client order by cin");

    return model;
}
