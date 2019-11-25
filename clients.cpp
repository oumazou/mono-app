#include "clients.h"
#include <QString>
#include <QSqlQuery>
#include <QVariant>
#include <QSqlQueryModel>
#include <QTableView>
clients::clients()
{
    cin=0;
    nom="-";
    prenom="--";
    sexe="---";
    tel =00;
}
clients::clients(int cin,QString nom,QString prenom,QString sexe,int tel)
{
    this->cin=cin;
    this->nom=nom;
    this->prenom=prenom;
    this->sexe=sexe;
    this->tel=tel;
}

bool clients :: ajouter()
{
    QSqlQuery query;
    QString res=QString::number(cin);
    QString res1=QString::number(tel);
         query.prepare("INSERT INTO clients(cin, nom, prenom, sexe, tel) "
                       "VALUES (:cin, :nom, :prenom, :sexe, :tel)");
         query.bindValue(":cin",res);
         query.bindValue(":nom", nom);
         query.bindValue(":prenom",prenom);
         query.bindValue(":sexe", sexe);
         query.bindValue(":tel",res1);

         return query.exec();

}
QSqlQueryModel * clients :: afficher()
{
    QSqlQueryModel * model= new QSqlQueryModel();
    model->setQuery("Select * from clients");
    model->setHeaderData(0, Qt::Horizontal,QObject::tr("cin"));
    model->setHeaderData(1, Qt::Horizontal,QObject::tr("nom"));
    model->setHeaderData(2, Qt::Horizontal,QObject::tr("prenom"));
    model->setHeaderData(3, Qt::Horizontal,QObject::tr("sexe"));
    model->setHeaderData(4, Qt::Horizontal,QObject::tr("tel"));
    return model;
}

QSqlQueryModel * clients :: afficherCin()
{
    QSqlQueryModel * model= new QSqlQueryModel();
    model->setQuery("Select cin from clients");
    model->setHeaderData(0, Qt::Horizontal,QObject::tr("cin"));

    return model;
}
void clients :: supprimer(int cin)
{
    QSqlQuery query;
    query.prepare("DELETE FROM clients WHERE cin=:cin");
    query.bindValue(":cin",cin);
    query.exec();

}

bool clients :: modifier()
{
    QSqlQuery query;
    QString res=QString::number(cin);
    QString res1=QString::number(tel);
    query.prepare("UPDATE clients SET nom=:nom, prenom=:prenom, sexe=:sexe, tel=:tel WHERE cin =:cin");
    query.bindValue(":cin",res);
    query.bindValue(":nom", nom);
    query.bindValue(":prenom",prenom);
    query.bindValue(":sexe", sexe);
    query.bindValue(":tel",res1);
    return query.exec();
}


bool clients:: rechC()
{
    QSqlQuery query;
    query.prepare("select * from clients where cin=:cin");
    query.bindValue(":cin",cin);
    return query.nextResult() ;
}

QSqlQueryModel * clients::afficherclientchercher(int cin)
{
    QSqlQueryModel * model= new QSqlQueryModel();
    QString res=QString::number(cin);
    model->setQuery("select * from clients where cin=:cin");
    model->setHeaderData(0, Qt::Horizontal,QObject::tr("cin"));
    model->setHeaderData(1, Qt::Horizontal,QObject::tr("nom"));
    model->setHeaderData(2, Qt::Horizontal,QObject::tr("prenom"));
    model->setHeaderData(3, Qt::Horizontal,QObject::tr("sexe"));
    model->setHeaderData(4, Qt::Horizontal,QObject::tr("tel"));
    return model;
}

QSqlQueryModel * clients :: afficherNom()
{
    QSqlQueryModel * model= new QSqlQueryModel();
    model->setQuery("Select nom from clients");
    model->setHeaderData(1, Qt::Horizontal,QObject::tr("nom"));

    return model;
}
QSqlQueryModel * clients :: afficherPrenom()
{
    QSqlQueryModel * model= new QSqlQueryModel();
    model->setQuery("Select prenom from clients");
    model->setHeaderData(2, Qt::Horizontal,QObject::tr("prenom"));

    return model;
}
QSqlQueryModel * clients :: afficherSexe()
{
    QSqlQueryModel * model= new QSqlQueryModel();
    model->setQuery("Select sexe from clients");
    model->setHeaderData(3, Qt::Horizontal,QObject::tr("sexe"));

    return model;
}
QSqlQueryModel * clients :: afficherTel()
{
    QSqlQueryModel * model= new QSqlQueryModel();
    model->setQuery("Select tel from clients");
    model->setHeaderData(4, Qt::Horizontal,QObject::tr("tel"));

    return model;
}

void clients::clearTable(QTableView *table){
    QSqlQueryModel *model=new QSqlQueryModel();
    model->clear();
    table->setModel(model);}

void clients::searchRegexp(QTableView *table, int x){
   QSqlQueryModel *model=new QSqlQueryModel();
   QSqlQuery *query =new QSqlQuery;
   query->prepare("select * from clients where regexp_like(cin,:cin);");
   query->bindValue(":cin",x);

   if(x==0){qDebug("tawa 0");

   query->prepare("select * from clients;");   }
   query->exec();
   model->setQuery(*query);
   table->setModel(model);
   table->show();

}
