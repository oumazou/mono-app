#include "commandeachat.h"
#include <QDebug>
#include <QSqlError>
#include <QDate>
commandeachat::commandeachat()
{
num=0;
weight=0;
price=0;

}
commandeachat::commandeachat(int num,float weight,float price,QDate datee)
{
  this->num=num;
  this->weight=weight;
  this->price=price;
  this->datee=datee;
}
int commandeachat::get_num(){return  num;}
float commandeachat::get_weight(){return weight;}
float commandeachat::get_price(){return  price;}
QDate commandeachat::get_datee(){return  datee;}

bool commandeachat::ajouter()
{
QSqlQuery query;
QString res= QString::number(num);
QString res2= QString::number(weight);
QString res3= QString::number(price);

query.prepare("INSERT INTO CA (NUM, WEIGHT, PRICE, DATEE) "
                    "VALUES (:num, :weight, :price, :datee)");
query.bindValue(":num",res);
query.bindValue(":weight", res2);
query.bindValue(":price", res3);
query.bindValue(":datee", datee);
qDebug()<<query.lastError().text();
return    query.exec();
}

QSqlQueryModel * commandeachat::afficher()
{QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select * from CA");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("num"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("weight "));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("price"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("datee"));
qDebug()<<model->lastError().text();
    return model;
}

bool commandeachat::supprimer(int numm)
{
QSqlQuery query;
QString res= QString::number(num);

query.prepare("Delete from CA where NUM = :num ");
query.bindValue(":num", res);
return    query.exec();
}
bool commandeachat::Modifier(int num,float weight,float price,QDate datee)
{
    QSqlQuery query;
    QString res= QString::number(weight);
    QString res1= QString::number(price);
    QString res2= QString::number(num);

    query.prepare("update CA set WEIGHT=:weight ,PRICE=:price ,DATEE=:datee  where NUM = :num;");
    query.bindValue(":num", res2);
    query.bindValue(":weight", res);
    query.bindValue(":price", res1);
    query.bindValue(":datee",datee);
    return query.exec();
}

bool commandeachat::rech(int num)
{
    QSqlQuery query;
    query.prepare("select * from CA where NUM = :num;");
    query.bindValue(":num", num);
    return query.exec();
}
QSqlQueryModel * commandeachat::trier()
{
    QSqlQueryModel * model= new QSqlQueryModel();

    model->setQuery("select * from CA ORDER BY NUM");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("num"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("weight "));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("price"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("datee"));
        return model;
}
QSqlQueryModel *commandeachat :: affecter (int num, int ref)
{


    QSqlQuery query;
    QString res=QString::number(num);
    QString res1=QString::number(ref);
    query.prepare("INSERT INTO AF(num, ref) "
                  "VALUES (:num, :ref)");
    query.bindValue(":num",res);
    query.bindValue(":ref",res1);
    query.exec();
    QSqlQueryModel * model= new QSqlQueryModel();
    model->setQuery("Select * from AF");
    model->setHeaderData(0, Qt::Horizontal,QObject::tr("num"));
    model->setHeaderData(1, Qt::Horizontal,QObject::tr("ref"));
    return model;



}
void commandeachat::cleartable(QTableView *table )
{
    QSqlQueryModel *model=new QSqlQueryModel();
    model->clear();
    table->setModel(model);
}
void commandeachat::searchRegexp(QTableView *table, int x){
   QSqlQueryModel *model=new QSqlQueryModel();
   QSqlQuery *query =new QSqlQuery;
   query->prepare("select * from CA where regexp_like(num,:num);");
   query->bindValue(":num",x);

   if(x==0){qDebug("tawa 0");

   query->prepare("select * from CA;");   }
   query->exec();
   model->setQuery(*query);
   table->setModel(model);
   table->show();
}
void commandeachat::searchRegexp2(QTableView *table, int x){
   QSqlQueryModel *model=new QSqlQueryModel();
   QSqlQuery *query =new QSqlQuery;
   query->prepare("select * from AF where regexp_like(num,:num);");
   query->bindValue(":num",x);

   if(x==0){qDebug("tawa 0");

   query->prepare("select * from AF;");   }
   query->exec();
   model->setQuery(*query);
   table->setModel(model);
   table->show();
}
/*QSqlQueryModel * commandeachat::afficherArticles()
{   QSqlQueryModel * model= new QSqlQueryModel(); //tekhou el view mel table ou takra menha

    model->setQuery("select weight,price,datee,num from comm JOIN arti ON comm.num=arti.num");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("weight"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("price"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("datee"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("num"));

        return model;

}*/


