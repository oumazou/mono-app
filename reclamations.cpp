#include "reclamations.h"
#include <QDebug>
#include <QMessageBox>
#include<QDate>
#include <QSqlQuery>
#include<QTableView>
#include<QString>
reclamations::reclamations()
{
num=0;

ref="-";

cin=000;

type="--";


}
reclamations::reclamations(int num,QDate d,QString ref,int cin,QString type)
{
  this->num=num;
    this->d=d;

  this->ref=ref;

   this->cin=cin;
    this->type=type;

}


bool reclamations::ajouter()
{
QSqlQuery query;
QString N=QString::number(num);

QString C=QString::number(cin);

query.prepare("INSERT INTO recl (NUM,D,REF,CIN,TYPE) "
                    "VALUES (:num, :d, :ref, :cin, :type)");
query.bindValue(":num",N);
query.bindValue(":d",d);
query.bindValue(":ref",ref);
query.bindValue(":cin", C);
query.bindValue(":type", type);




return    query.exec();
}

QSqlQueryModel * reclamations::afficher()
{QSqlQueryModel * model= new QSqlQueryModel(); //tekhou el view mel table ou takra menha

model->setQuery("select * from recl");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("num"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("d"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("ref"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("cin"));
model->setHeaderData(4, Qt::Horizontal, QObject::tr("type"));

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

bool reclamations::modifier(int num,QDate d,QString ref,int cin,QString type)
{
    QSqlQuery query;
    QString res=QString::number(num);

    QString res2=QString::number(cin);
    query.prepare("update recl set d=:d ,ref=:ref ,cin=:cin ,type=:type  where num = :num");
    query.bindValue(":num", res);
    query.bindValue(":d", d);
    query.bindValue(":ref", ref);
    query.bindValue(":cin", res2);
    query.bindValue(":type", type);

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
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("type"));

        return model;
}

QSqlQueryModel * reclamations::trierReclamation2()
{
    QSqlQueryModel * model= new QSqlQueryModel();

    model->setQuery("select * from recl ORDER BY d");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("num"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("d"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("ref"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("cin"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("type"));

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

int reclamations :: nombreReclamation()
{
    QSqlQuery query;
    query.prepare("select COUNT(*) from recl");
    query.exec();
    query.next();
    return query.value(0).toInt();
}

/*int reclamations :: nombrehomme()
{
    QSqlQuery query;
    query.prepare("select COUNT(*) from recl where sexe='homme'");
    query.exec();
    query.next();
    return query.value(0).toInt();

}*/
