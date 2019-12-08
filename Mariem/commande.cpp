#include "commande.h"
#include <QDebug>
#include <QMessageBox>
#include <QSqlQuery>
#include <QVariant>
#include<QDate>
#include<QTableView>
#include<QString>
commande::commande()
{
num=0;
montant=00;

}
commande::commande(int num,QDate dates,double montant)
{
  this->num=num;
  this->dates=dates;
    this->montant=montant;

}


bool commande::ajouter()
{
QSqlQuery query;
QString N=QString::number(num);
QString M=QString::number(montant);
query.prepare("INSERT INTO comm (NUM, DATES, MONTANT) "
                    "VALUES (:numero, :date, :montant)");
query.bindValue(":numero", N);
query.bindValue(":date", dates);
query.bindValue(":montant", M);


return    query.exec();
}

QSqlQueryModel * commande::afficher()
{QSqlQueryModel * model= new QSqlQueryModel(); //tekhou el view mel table ou takra menha

model->setQuery("select * from comm");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("numero"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("date"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("montant"));

    return model;
}

bool commande::supprimer(int numc)
{
QSqlQuery query;
query.prepare("Delete from comm where NUM = :num ");
query.bindValue(":num", numc);


return    query.exec();
}



bool commande::rech(int num){
    QSqlQuery query;
    QString res=QString::number(num);
    query.prepare("select * from comm where num = :num");
    query.bindValue(":num", res);
   return query.exec();

}

bool commande::modifier(int num,QDate dates,double montant)
{
    QSqlQuery query;
    QString res=QString::number(num);
    QString res1=QString::number(montant);
    query.prepare("update comm set dates=:dates ,montant=:montant  where num = :num");
    query.bindValue(":num", res);
    query.bindValue(":dates", dates);
    query.bindValue(":montant", res1);
    return query.exec();
}

QSqlQueryModel * commande::triercommande()
{
    QSqlQueryModel * model= new QSqlQueryModel();

    model->setQuery("select * from comm ORDER BY num");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("num"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("dates"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("montant"));
        return model;
}
QSqlQueryModel * commande::triercommande2()
{
    QSqlQueryModel * model= new QSqlQueryModel();

    model->setQuery("select * from comm ORDER BY montant");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("num"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("dates"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("montant"));
        return model;
}
void commande::clearTable(QTableView *table){
    QSqlQueryModel *model=new QSqlQueryModel();
    model->clear();
    table->setModel(model);}

void commande::searchRegexp(QTableView *table, int x){
   QSqlQueryModel *model=new QSqlQueryModel();
   QSqlQuery *query =new QSqlQuery;
   query->prepare("select * from comm where regexp_like(num,:num);");
   query->bindValue(":num",x);

   if(x==0){qDebug("tawa 0");

   query->prepare("select * from comm;");   }
   query->exec();
   model->setQuery(*query);
   table->setModel(model);
   table->show();
}
void commande::searchRegexp2(QTableView *table, int x){
   QSqlQueryModel *model=new QSqlQueryModel();
   QSqlQuery *query =new QSqlQuery;
   query->prepare("select * from affect where regexp_like(num,:num);");
   query->bindValue(":num",x);

   if(x==0){qDebug("tawa 0");

   query->prepare("select * from affect;");   }
   query->exec();
   model->setQuery(*query);
   table->setModel(model);
   table->show();
}
/*QSqlQueryModel * commande::afficherArticles()
{   QSqlQueryModel * model= new QSqlQueryModel(); //tekhou el view mel table ou takra menha

    model->setQuery("select ref,type,marque,prix,num from comm JOIN arti ON comm.num=arti.num");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ref"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("type"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("marque"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("prix"));


        return model;

}*/

int commande:: montantHaut()
{
    QSqlQuery query;
    query.prepare("SELECT MAX(montant) FROM comm");
    query.exec();
    query.next();
       return query.value(0).toInt();

}

int commande:: montantBas()
{
    QSqlQuery query;
    query.prepare("SELECT MIN(montant) FROM comm");
    query.exec();
    query.next();
       return query.value(0).toInt();

}
int commande :: nombrecommande()
{
    QSqlQuery query;
    query.prepare("select COUNT(*) from comm");
    query.exec();
    query.next();
    return query.value(0).toInt();
}

QSqlQueryModel *commande :: affecter (int num, QString ref)
{


    QSqlQuery query;
    QString res=QString::number(num);

    query.prepare("INSERT INTO affect(num, ref) "
                  "VALUES (:num, :ref)");
    query.bindValue(":num",res);
    query.bindValue(":ref",ref);
    query.exec();
    QSqlQueryModel * model= new QSqlQueryModel();
    model->setQuery("Select * from affect");
    model->setHeaderData(0, Qt::Horizontal,QObject::tr("num"));
    model->setHeaderData(1, Qt::Horizontal,QObject::tr("ref"));
    return model;



}
bool commande :: supprimerAffect(int num)
{
    QSqlQuery query;


    query.prepare("DELETE FROM affect WHERE num=:num ");
    query.bindValue(":num",num);

   return    query.exec();
}
QSqlQueryModel * commande :: afficherAffectation()
{
    QSqlQueryModel * model= new QSqlQueryModel();
    model->setQuery("Select * from affect where num:=num");
    model->setHeaderData(0, Qt::Horizontal,QObject::tr("num"));
    model->setHeaderData(1, Qt::Horizontal,QObject::tr("ref"));
    return model;

}

QSqlQueryModel * commande :: afficherNum()
{
    QSqlQueryModel * model= new QSqlQueryModel();
    model->setQuery("Select num from comm");
    model->setHeaderData(0, Qt::Horizontal,QObject::tr("num"));

    return model;
}

