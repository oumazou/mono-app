#include "conge.h"
#include <QSqlQuery>
#include <QTableView>
#include "employee.h"

Conge::Conge()
{
    num=0;

}

Conge:: Conge (int num,QDate debutconge,QDate finconge,int idemp)
{
  this->num=num;
  this->debutconge=debutconge;
  this->finconge=finconge;
    this->idemp=idemp;
}



bool Conge::ajouter()
{
    QSqlQuery query;
    QSqlQuery query1;
 QString res=QString::number(num);
    QString res1=QString::number(idemp);
    query.prepare("INSERT INTO conge (numero,DEBUTCONGE,FINCONGE,idemp) VALUES (:numero,:debutconge,:finconge,:idemp);");
    query.bindValue(":numero", res);
    query.bindValue(":debutconge", debutconge);
    query.bindValue(":finconge", finconge);
     query.bindValue(":idemp", res1);
   return query.exec();

}

QSqlQueryModel * Conge::afficher()
{
    QSqlQueryModel * model= new QSqlQueryModel();

    model->setQuery("select * from conge");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("NUM"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("DEBUTCONGE "));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("FINCONGE"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("IDUSER"));
        return model;
}


bool Conge::supprimer(int numm)
{
QSqlQuery query;
QString res= QString::number(numm); //
if(recherche(numm))
{
query.prepare("Delete from conge where numero = :num ");
query.bindValue(":num", res);
}
else{}
return    query.exec();
}

bool Conge::recherche(int x){
    QSqlQuery query;
    query.prepare("select * from conge where numero = :numero;");
    query.bindValue(":numero", x);
    return query.exec();
}

bool Conge::modifier(int numero,QDate debutconge,QDate finconge,int idemp){
    QSqlQuery query;
    QString res=QString::number(numero);
    QString res1=QString::number(idemp);
    query.prepare("update conge set debutconge=:debutconge, finconge=:finconge, idemp=:idemp  where numero = :numero");
    query.bindValue(":numero",res);
    query.bindValue(":debutconge",debutconge);
    query.bindValue(":finconge",finconge);
    query.bindValue(":idemp",res1);

   return query.exec();
}

void Conge::clearTable(QTableView *table){
    QSqlQueryModel *model=new QSqlQueryModel();
    model->clear();
    table->setModel(model);}

void Conge::searchRegexp(QTableView *table, int x){
   QSqlQueryModel *model=new QSqlQueryModel();
   QSqlQuery *query =new QSqlQuery;
   query->prepare("select * from conge where regexp_like(numero,:numero);");
   query->bindValue(":numero",x);

   if(x==0){qDebug("tawa 0");
   query->prepare("select * from conge;");   }
   query->exec();
   model->setQuery(*query);
   table->setModel(model);
   table->show();
}

QSqlQueryModel * Conge :: trierConge()
{
    QSqlQueryModel * model= new QSqlQueryModel();

    model->setQuery("select * from conge ORDER BY numero");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("numero"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("debutconge"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("finconge"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("idemp"));

    return model;
}
