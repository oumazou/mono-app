#include "articles.h"
#include <QString>
#include <QSqlQuery>
#include <QVariant>
#include <QSqlQueryModel>
#include <QTableView>
Articles::Articles()
{
    ref=0;
    type="-";
    marque="--";
    prix =00;

}
Articles::Articles(int ref,QString type,QString marque,double prix)
{
    this->ref=ref;
    this->type=type;
    this->marque=marque;
    this->prix=prix;

}

bool Articles :: ajouter()
{
    QSqlQuery query;

    QString res=QString::number(ref);
    QString res1=QString::number(prix);

         query.prepare("INSERT INTO arti(ref, type, marque, prix) "
                       "VALUES (:ref, :type, :marque, :prix)");
         query.bindValue(":ref",ref);
         query.bindValue(":type",type);
         query.bindValue(":marque",marque);
         query.bindValue(":prix", res1);


         return query.exec();

}
QSqlQueryModel * Articles :: afficher()
{
    QSqlQueryModel * model= new QSqlQueryModel();
    model->setQuery("Select * from arti");
    model->setHeaderData(0, Qt::Horizontal,QObject::tr("ref"));
    model->setHeaderData(1, Qt::Horizontal,QObject::tr("type"));
    model->setHeaderData(2, Qt::Horizontal,QObject::tr("marque"));
    model->setHeaderData(3, Qt::Horizontal,QObject::tr("prix"));

    return model;
}
void Articles :: supprimer(int ref)
{
    QSqlQuery query;
    query.prepare("DELETE FROM arti WHERE ref=:ref");
    query.bindValue(":ref",ref);
    query.exec();

}

bool Articles :: modifier()
{
    QSqlQuery query;
    QString res=QString::number(ref);
    QString res1=QString::number(prix);

    query.prepare("UPDATE arti SET type=:type, marque=:marque, prix=:prix  WHERE ref =:ref");
    query.bindValue(":ref",res);
    query.bindValue(":type",type);
    query.bindValue(":marque",marque);
    query.bindValue(":prix",res1);

    return query.exec();
}
QSqlQueryModel * Articles::afficherarticlechercher(int ref)
{
    QSqlQueryModel * model= new QSqlQueryModel();
    QString res=QString::number(ref);
    model->setQuery("select * from arti where ref=:ref");
    model->setHeaderData(0, Qt::Horizontal,QObject::tr("ref"));
    model->setHeaderData(1, Qt::Horizontal,QObject::tr("type"));
    model->setHeaderData(2, Qt::Horizontal,QObject::tr("marque"));
    model->setHeaderData(3, Qt::Horizontal,QObject::tr("prix"));

    return model;
}


bool Articles:: rechA()
{
    QSqlQuery query;
    query.prepare("select * from arti where ref=:ref");
    query.bindValue(":ref",ref);
    return query.nextResult() ;
}

QSqlQueryModel * Articles :: afficherRef()
{
    QSqlQueryModel * model= new QSqlQueryModel();
    model->setQuery("Select ref from arti");
    model->setHeaderData(0, Qt::Horizontal,QObject::tr("ref"));

    return model;
}
void Articles::clearTable(QTableView *table){
    QSqlQueryModel *model=new QSqlQueryModel();
    model->clear();
    table->setModel(model);}

void Articles::searchRegexp(QTableView *table, int x){
   QSqlQueryModel *model=new QSqlQueryModel();
   QSqlQuery *query =new QSqlQuery;
   query->prepare("select * from arti where ref=:ref");
   query->bindValue(":ref",x);

   if(x==0)
   {
       qDebug("tawa 0");
       query->prepare("select * from arti;");
   }
   query->exec();
   model->setQuery(*query);
   table->setModel(model);
   table->show();

}


int Articles :: nombreArticles()
{
    QSqlQuery query;
    query.prepare("select COUNT(*) from arti");
    query.exec();
    query.next();
    return query.value(0).toInt();
}
