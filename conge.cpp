#include "conge.h"
#include <QSqlQuery>
#include <QTableView>

Conge::Conge()
{
    num=0;
    debutconge="";
    finconge="";
    iduser=0;
}

Conge::Conge(int num,QString debutconge,QString finconge,int iduser)
{
  this->num=num;
  this->debutconge=debutconge;
  this->finconge=finconge;
  this->iduser=iduser;
}

Conge::Conge(QString debutconge,QString finconge,int iduser)
{
  this->debutconge=debutconge;
  this->finconge=finconge;
  this->iduser=iduser;
}

int Conge::get_num(){return  num;}
QString Conge::get_debutconge(){return  debutconge;}
QString Conge::get_finconge(){return finconge;}
int Conge::get_iduser(){return  iduser;}

bool Conge::ajouter()
{
    QSqlQuery query;
    QString res= QString::number(num);
    query.prepare("INSERT INTO conge (NUM,DEBUTCONGE,FINCONGE,IDUSER) "
                        "VALUES (:num,:debutconge,:finconge,:iduser)");
    query.bindValue(":num", res);
    query.bindValue(":debutconge", debutconge);
    query.bindValue(":finconge", finconge);
    query.bindValue(":iduser", iduser);

    return    query.exec();
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
QString res= QString::number(numm);
if(recherche(numm))
{
query.prepare("Delete from conge where NUM = :num ");
query.bindValue(":num", res);
}
else{}
return    query.exec();
}

bool Conge::recherche(int x){
    QSqlQuery query;
    query.prepare("select * from conge where NUM = :num;");
    query.bindValue(":num", x);
    return query.exec();
}

bool Conge::modifier(QString b,QString c,int d){
    QSqlQuery query;
    query.prepare("update conge set DEBUTCONGE=:debutconge ,FINCONGE=:finconge where NUM = :num");
    query.bindValue(":debutconge", b);
    query.bindValue(":finconge", c);
    query.bindValue(":num", d);

   return query.exec();
}

void Conge::clearTable(QTableView *table){
    QSqlQueryModel *model=new QSqlQueryModel();
    model->clear();
    table->setModel(model);}

void Conge::searchRegexp(QTableView *table, int x){
   QSqlQueryModel *model=new QSqlQueryModel();
   QSqlQuery *query =new QSqlQuery;
   query->prepare("select * from conge where regexp_like(num,:num);");
   query->bindValue(":num",x);

   if(x==0){qDebug("tawa 0");
   query->prepare("select * from conge;");   }
   query->exec();
   model->setQuery(*query);
   table->setModel(model);
   table->show();
}

