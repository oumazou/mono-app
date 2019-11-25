#include "reclamations.h"
#include <QDebug>
#include <QMessageBox>
#include<QDate>
#include <QSqlQuery>
#include<QTableView>
reclamations::reclamations()
{
num=0;

ref=00;

cin=000;


}
reclamations::reclamations(int num,QDate d,int ref,int cin)
{
  this->num=num;
    this->d=d;

  this->ref=ref;

   this->cin=cin;

}


bool reclamations::ajouter()
{
QSqlQuery query;
QString N=QString::number(num);
QString R=QString::number(ref);
QString C=QString::number(cin);

query.prepare("INSERT INTO recl (NUM,D,REF,CIN) "
                    "VALUES (:num, :d, :ref, :cin)");
query.bindValue(":num",N);
query.bindValue(":d",d);
query.bindValue(":ref",R);
query.bindValue(":cin", C);




return    query.exec();
}

QSqlQueryModel * reclamations::afficher()
{QSqlQueryModel * model= new QSqlQueryModel(); //tekhou el view mel table ou takra menha

model->setQuery("select * from recl");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("num"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("d"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("ref"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("cin"));


    return model;
}

bool reclamations::supprimer(int numr)
{
QSqlQuery query;

query.prepare("Delete from recl where NUM = :num ");
query.bindValue(":num", numr);
return    query.exec();
}
bool reclamations::reche(int num){
    QSqlQuery query;
    QString res=QString::number(num);
    query.prepare("select * from recl where num = :num");
    query.bindValue(":num", res);
    return query.exec();
}

bool reclamations::modifier(int num,QDate d,int ref,int cin)
{
    QSqlQuery query;
    QString res=QString::number(num);
    QString res1=QString::number(ref);
    QString res2=QString::number(cin);
    query.prepare("update recl set d=:d ,ref=:ref ,cin=:cin  where num = :num");
    query.bindValue(":num", res);
    query.bindValue(":d", d);
    query.bindValue(":ref", res1);
    query.bindValue(":cin", res2);

    return query.exec();
}

QSqlQueryModel * reclamations::trierReclamation()
{
    QSqlQueryModel * model= new QSqlQueryModel();

    model->setQuery("select * from recl ORDER BY num");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("num"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("d"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("ref"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("cin"));

        return model;
}
void reclamations::clearTable(QTableView *table){
    QSqlQueryModel *model=new QSqlQueryModel();
    model->clear();
    table->setModel(model);}

void reclamations::searchRegexp(QTableView *table, int x){
   QSqlQueryModel *model=new QSqlQueryModel();
   QSqlQuery *query =new QSqlQuery;
   query->prepare("select * from recl where regexp_like(num,:num);");
   query->bindValue(":num",x);

   if(x==0){qDebug("tawa 0");

   query->prepare("select * from recl;");   }
   query->exec();
   model->setQuery(*query);
   table->setModel(model);
   table->show();

}
