#include "fournisseur.h"
#include <QDebug>
#include <QSqlError>
Fournisseur::Fournisseur()
{
num=0;
nom="";
rating=0;
mail="";
}
Fournisseur::Fournisseur(long num,QString nom,int rating, QString mail  )
{
  this->num=num;
  this->nom=nom;
  this->rating=rating;
  this->mail=mail;

}
QString Fournisseur::get_nom(){return  nom;}
long Fournisseur::get_num(){return num;}
int Fournisseur::get_rating(){return  rating;}
QString Fournisseur::get_mail(){return  mail;}

bool Fournisseur::ajouter()
{
QSqlQuery query;
QString res= QString::number(num);
QString res1= QString::number(rating);

query.prepare("INSERT INTO fournisseur (NOM, NUM, RATING,MAIL) "
                    "VALUES (:nom, :num, :rating, :mail)");
query.bindValue(":nom",nom);
query.bindValue(":num", res);
query.bindValue(":rating", res1);
query.bindValue(":mail",mail);
qDebug()<<query.lastError().text();
return    query.exec();
}

QSqlQueryModel * Fournisseur::afficher()
{QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select * from fournisseur");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("nom"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("Num "));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("rating"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("mail"));
qDebug()<<model->lastError().text();
    return model;
}

bool Fournisseur::supprimer(QString nomm)
{
    QSqlQuery query;
query.prepare("Delete from fournisseur where NOM = :nom ");
query.bindValue(":nom", nomm);
return    query.exec();
}
bool Fournisseur::Modifier(long num,QString nom,int rating, QString mail){
    QSqlQuery query;
    QString res= QString::number(num);
    QString res1= QString::number(rating);

    query.prepare("update FOURNISSEUR set NUM=:num ,RATING=:rating ,MAIL=:mail  where NOM = :nom;");
    query.bindValue(":nom", nom);
    query.bindValue(":num", res);
    query.bindValue(":rating", res1);
    query.bindValue(":mail", mail);
    return query.exec();
}

bool Fournisseur::rech(QString nomm)
{
    QSqlQuery query;
    query.prepare("select * from fournisseur where NOM = :nom;");
    query.bindValue(":nom", nomm);
    return query.exec();
}
QSqlQueryModel * Fournisseur::trier()
{
    QSqlQueryModel * model= new QSqlQueryModel();

    model->setQuery("select * from FOURNISSEUR ORDER BY RATING");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("nom"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Num "));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("rating"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("mail"));
        return model;
}


