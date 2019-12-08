#include "promotions.h"
#include <QString>
#include <QSqlQuery>
#include <QVariant>
#include <QDate>
#include <QSqlQueryModel>
Promotions::Promotions()
{
    num=0;
    pourcentage=0;
    jours=0;

}
Promotions :: Promotions(int num,int pourcentage ,QDate d,int jours)
{
    this->num=num;
    this->pourcentage=pourcentage;
    this->d=d;
    this->jours=jours;

}
bool Promotions :: ajouter()
{
    QSqlQuery query;

    QString res1=QString::number(num);
    QString res2=QString::number(pourcentage);
    QString res3=QString::number(jours);
    query.prepare("INSERT INTO promotions(num, pourcentage, d, jours) "
                  "VALUES (:num, :pourcentage, :d, :jours)");
    query.bindValue(":num",res1);
    query.bindValue(":pourcentage",res2);
    query.bindValue(":d",d);
    query.bindValue(":jours",res3);

    return query.exec();

}
QSqlQueryModel * Promotions :: afficher()
{
    QSqlQueryModel * model= new QSqlQueryModel();
    model->setQuery("Select * from promotions");
    model->setHeaderData(0, Qt::Horizontal,QObject::tr("num"));
    model->setHeaderData(1, Qt::Horizontal,QObject::tr("pourcentage"));
    model->setHeaderData(2, Qt::Horizontal,QObject::tr("d"));
    model->setHeaderData(3, Qt::Horizontal,QObject::tr("jours"));
    return model;
}
bool Promotions :: supprimer(int num)
{
    QSqlQuery query;
    query.prepare("DELETE FROM promotions WHERE num=:num");
    query.bindValue(":num",num);
    query.exec();

}
bool Promotions :: modifier(int num,int pourcentage ,QDate d,int jours)
{
    QSqlQuery query;
    QString res1=QString::number(num);
    QString res2=QString::number(pourcentage);
    QString res3=QString::number(jours);
    query.prepare("UPDATE promotions SET pourcentage=:modifPourcentage, d=:modifDate, jours=:modifJours WHERE num =:modifNum;");
    query.bindValue(":modifNum",res1);
    query.bindValue(":modifPourcentage",res2);
    query.bindValue(":modifDate",d);
    query.bindValue(":modifJours",res3);
    return query.exec();
}
QString Promotions:: upcoming()
{
    QSqlQuery query;
    query.prepare("SELECT MAX(d) cnt FROM promotions");
    query.exec();
    while(query.next()){
        return query.value(0).toString();
    }
}
QString Promotions::  highPromotion()
{
    QSqlQuery query;
    query.prepare("SELECT MAX(pourcentage) FROM promotions");
    query.exec();
    while(query.next()){
        return query.value(0).toString();
    }
}
QString Promotions:: lowPromotion()
{
    QSqlQuery query;
    query.prepare("SELECT MIN(pourcentage) FROM promotions");
    query.exec();
    while(query.next()){
        return query.value(0).toString();
    }
}

void Promotions::clearTable(QTableView *table){
    QSqlQueryModel *model=new QSqlQueryModel();
    model->clear();
    table->setModel(model);}

void Promotions::searchRegexp(QTableView *table, QString x){
    QSqlQueryModel *model=new QSqlQueryModel();
    QSqlQuery *query =new QSqlQuery;
    query->prepare("select * from promotions where regexp_like(num,:num);");
    query->bindValue(":num",x);

    if(x==0){qDebug("tawa 0");

        query->prepare("select * from promotions;");   }
    query->exec();
    model->setQuery(*query);
    table->setModel(model);
    table->show();

}
bool Promotions:: recherche(int num)
{
    QSqlQuery query;
    query.prepare("select * from promotions where num=:num");
    query.bindValue(":num",num);
    return query.exec() ;
}

QSqlQueryModel * Promotions :: trierduree()
{
    QSqlQueryModel * model= new QSqlQueryModel();

    model->setQuery("select * from promotions ORDER BY jours");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("num"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("pourcentage"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("date"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("jours"));

    return model;
}
QSqlQueryModel * Promotions :: trierpourcentage()
{
    QSqlQueryModel * model= new QSqlQueryModel();

    model->setQuery("select * from promotions ORDER BY pourcentage");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("num"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("pourcentage"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("date"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("jours"));

    return model;
}
void Promotions :: affecter (QString num, QString ref)
{


    QSqlQuery query;
    query.prepare("INSERT INTO affectation(num, ref) "
                  "VALUES (:num, :ref)");
    query.bindValue(":num",num);
    query.bindValue(":ref",ref);
    query.exec();

    int pourcentage ;
    QSqlQuery query3;
    query3.prepare("SELECT pourcentage FROM promotions where num = :num");
    query3.bindValue(":num",num);
    query3.exec();
    while(query.next()){
        pourcentage = query3.value(0).toInt();
    }


    QSqlQuery query1;

    query1.prepare("UPDATE articles SET prix=prix - ((prix * :pourcentage)/100) WHERE ref =:ref;");
    query1.bindValue(":ref",ref);
    query1.bindValue(":pourcentage",23);
    query1.exec();

}
void Promotions :: supprimerAffect(QString num, QString ref)
{
    QSqlQuery query;
    query.prepare("DELETE FROM affectation WHERE num=:num and ref=:ref");
    query.bindValue(":num",num);
    query.bindValue(":ref",ref);
    query.exec();
}
QSqlQueryModel * Promotions :: afficherAffectation()
{
    QSqlQueryModel * model= new QSqlQueryModel();
    model->setQuery("Select * from affectation");
    model->setHeaderData(0, Qt::Horizontal,QObject::tr("num"));
    model->setHeaderData(1, Qt::Horizontal,QObject::tr("ref"));
    return model;

}
