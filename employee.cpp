#include "employee.h"
#include <QSqlQuery>
#include <QTableView>

Employee::Employee()
{
    id=0;
    nom="";
    prenom="";
    num=0;
    adresse="";
    cnss=0;
}
Employee::Employee(int id,QString nom,QString prenom,int num,QString adresse,int cnss)
{
  this->id=id;
  this->nom=nom;
  this->prenom=prenom;
  this->num=num;
  this->adresse=adresse;
  this->cnss=cnss;
}

int Employee::get_id(){return  id;}
QString Employee::get_nom(){return  nom;}
QString Employee::get_prenom(){return prenom;}
int Employee::get_num(){return  num;}
QString Employee::get_adresse(){return adresse;}
int Employee::get_cnss(){return  cnss;}



bool Employee::ajouter()
{
QSqlQuery query;
QString res= QString::number(id);
query.prepare("INSERT INTO employee (ID,NOM,PRENOM,NUM,ADRESSE,CNSS) "
                    "VALUES (:id,:nom,:prenom,:num,:adresse,:cnss)");
query.bindValue(":id", res);
query.bindValue(":nom", nom);
query.bindValue(":prenom", prenom);
query.bindValue(":num", num);
query.bindValue(":adresse", adresse);
query.bindValue(":cnss", cnss);

return    query.exec();
}

QSqlQueryModel * Employee::afficher()
{
QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select * from employee");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOM "));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("PRENOM"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("NUM"));
model->setHeaderData(4, Qt::Horizontal, QObject::tr("ADRESSE"));
model->setHeaderData(5, Qt::Horizontal, QObject::tr("CNSS"));
    return model;
}

bool Employee::supprimer(int idd)
{
QSqlQuery query;
QString res= QString::number(idd);
if(recherche(idd))
{
query.prepare("Delete from employee where ID = :id ");
query.bindValue(":id", res);
}
else{}
return    query.exec();
}


bool Employee::recherche(int x){
    QSqlQuery query;
    query.prepare("select * from employee where ID = :id;");
    query.bindValue(":id",x);
    query.exec();
     if(query.first()){return true;}
     else{return false;}
}

bool Employee::modifier(int a,QString b,QString c,int d,QString e,int f){
    QSqlQuery query;
    query.prepare("update employee set NOM=:nom ,PRENOM=:prenom ,NUM=:num ,ADRESSE=:adresse ,CNSS=:cnss where ID = :id");
    query.bindValue(":id", a);
    query.bindValue(":nom", b);
    query.bindValue(":prenom", c);
    query.bindValue(":num", d);
    query.bindValue(":adresse", e);
    query.bindValue(":cnss", f);
    return query.exec();
}

void Employee::clearTable(QTableView *table){
    QSqlQueryModel *model=new QSqlQueryModel();
    model->clear();
    table->setModel(model);}

void Employee::searchRegexp(QTableView *table, int x){
   QSqlQueryModel *model=new QSqlQueryModel();
   QSqlQuery *query =new QSqlQuery;
   query->prepare("select * from employee where regexp_like(id,:id);");
   query->bindValue(":id",x);

   if(x==0){qDebug("tawa 0");

   query->prepare("select * from employee;");   }
   query->exec();
   model->setQuery(*query);
   table->setModel(model);
   table->show();
}
QSqlQueryModel * Employee :: trier()
{
    QSqlQueryModel * model= new QSqlQueryModel();
    model->setQuery("select * from employee ORDER BY ID");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOM "));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("PRENOM"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("NUM"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("ADRESSE"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("CNSS"));
        return model;
}
