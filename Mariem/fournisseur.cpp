#include "fournisseur.h"
#include <QDebug>
#include <QSqlError>
#include <QTableView>
Fournisseur::Fournisseur()
{
num=0;
nom="-";
rating=0;
mail="--";
}
Fournisseur::Fournisseur(int num,int rating,QString nom, QString mail  )
{
  this->num=num;
  this->nom=nom;
  this->rating=rating;
  this->mail=mail;

}
QString Fournisseur::get_nom(){return  nom;}
int Fournisseur::get_num(){return num;}
int Fournisseur::get_rating(){return  rating;}
QString Fournisseur::get_mail(){return  mail;}

bool Fournisseur::ajouter()
{
QSqlQuery query;
QString res= QString::number(num);
QString res1= QString::number(rating);

query.prepare("INSERT INTO fournisseur (NUM,RATING,NOM,MAIL) "
                    "VALUES (:num, :rating, :nom, :mail)");

query.bindValue(":num", res);
query.bindValue(":rating", res1);
query.bindValue(":nom",nom);
query.bindValue(":mail",mail);
qDebug()<<query.lastError().text();
return    query.exec();
}

QSqlQueryModel * Fournisseur::afficher()
{QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select * from fournisseur");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("num"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("rating "));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("nom"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("mail"));
qDebug()<<model->lastError().text();
    return model;
}

bool Fournisseur::supprimer(int num)
{
    QSqlQuery query;
query.prepare("Delete from fournisseur where num = :num ");
query.bindValue(":num", num);
return    query.exec();
}
bool Fournisseur::Modifier(int num,int rating,QString nom, QString mail){
    QSqlQuery query;
    QString res= QString::number(num);
    QString res1= QString::number(rating);

    query.prepare("update fournisseur set RATING=:rating ,NOM=:nom ,MAIL=:mail  where NUM=:num;");
    query.bindValue(":num",res);
    query.bindValue(":rating",res1);
    query.bindValue(":nom",nom);
    query.bindValue(":mail",mail);
    return query.exec();
}

bool Fournisseur::rech(int num)
{
    QSqlQuery query;
    query.prepare("select * from fournisseur where num = :num;");
    query.bindValue(":num", num);
    return query.exec();
}
QSqlQueryModel * Fournisseur::trier()
{
    QSqlQueryModel * model= new QSqlQueryModel();

    model->setQuery("select * from FOURNISSEUR ORDER BY RATING");

    model->setHeaderData(0, Qt::Horizontal, QObject::tr("Num "));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("rating"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("nom"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("mail"));
        return model;
}

void Fournisseur::clearTable(QTableView *table){
    QSqlQueryModel *model=new QSqlQueryModel();
    model->clear();
    table->setModel(model);}

void Fournisseur::searchRegexp(QTableView *table, int x){
   QSqlQueryModel *model=new QSqlQueryModel();
   QSqlQuery *query =new QSqlQuery;
   query->prepare("select * from FOURNISSEUR where regexp_like(num,:num);");
   query->bindValue(":num",x);

   if(x==0){qDebug("tawa 0");

   query->prepare("select * from FOURNISSEUR;");   }
   query->exec();
   model->setQuery(*query);
   table->setModel(model);
   table->show();
}
