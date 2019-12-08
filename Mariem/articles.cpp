#include "articles.h"
#include <QMessageBox>
#include <QString>
#include <QSqlQuery>
#include <QVariant>
#include <QSqlQueryModel>
Articles::Articles()
{
    ref="";
    prix = 0.0;
    type="";
    quant=0;
    marque="";
}
Articles::Articles(QString ref,QString prix,QString type, int quant, QDate d, QString marque)
{
    this->ref=ref;
    this->prix=prix;
    this->type=type;
    this->quant=quant;
    this->d=d;
    this->marque=marque;
}

bool Articles :: ajouter()
{
    QSqlQuery query;

    QString res1=QString::number(quant);
    query.prepare("INSERT INTO articles(ref, prix, type, quant, d, marque) "
                  "VALUES (:ref, :prix, :type,:quant,:d,:marque)");
    query.bindValue(":ref",ref);
    query.bindValue(":prix",prix);
    query.bindValue(":type", type);
    query.bindValue(":quant", res1);
    query.bindValue(":d",d);
    query.bindValue(":marque",marque);
    return query.exec();

}
QSqlQueryModel * Articles :: afficher()
{
    QSqlQueryModel * model= new QSqlQueryModel();
    model->setQuery("Select * from articles where type = 'Alimentaire' ; ");
    model->setHeaderData(0, Qt::Horizontal,QObject::tr("ref"));
    model->setHeaderData(1, Qt::Horizontal,QObject::tr("prix"));
    model->setHeaderData(2, Qt::Horizontal,QObject::tr("type"));
    model->setHeaderData(3, Qt::Horizontal,QObject::tr("quant"));
    model->setHeaderData(4, Qt::Horizontal,QObject::tr("d"));
    model->setHeaderData(5, Qt::Horizontal,QObject::tr("marque"));
    return model;
}
QSqlQueryModel * Articles :: afficher1()
{
    QSqlQueryModel * model= new QSqlQueryModel();
    model->setQuery("Select * from articles where type = 'Congele' ; ");
    model->setHeaderData(0, Qt::Horizontal,QObject::tr("ref"));
    model->setHeaderData(1, Qt::Horizontal,QObject::tr("prix"));
    model->setHeaderData(2, Qt::Horizontal,QObject::tr("type"));
    model->setHeaderData(3, Qt::Horizontal,QObject::tr("quant"));
    model->setHeaderData(4, Qt::Horizontal,QObject::tr("d"));
    model->setHeaderData(5, Qt::Horizontal,QObject::tr("marque"));
    return model;
}
QSqlQueryModel * Articles :: afficher2()
{
    QSqlQueryModel * model= new QSqlQueryModel();
    model->setQuery("Select * from articles where type = 'Electronique' ; ");
    model->setHeaderData(0, Qt::Horizontal,QObject::tr("ref"));
    model->setHeaderData(1, Qt::Horizontal,QObject::tr("prix"));
    model->setHeaderData(2, Qt::Horizontal,QObject::tr("type"));
    model->setHeaderData(3, Qt::Horizontal,QObject::tr("quant"));
    model->setHeaderData(4, Qt::Horizontal,QObject::tr("d"));
    model->setHeaderData(5, Qt::Horizontal,QObject::tr("marque"));
    return model;
}
bool Articles :: supprimer(QString ref)
{
    QSqlQuery query;
    if(recherche(ref))
    {
        query.prepare("Delete from articles where ref = :ref ");
        query.bindValue(":ref", ref);
    }
    else{}
    return    query.exec();


}

bool Articles :: modifier(QString ref, QString prix, QString type, int quant, QDate d, QString marque)
{
    QSqlQuery query;
    QString res1=QString::number(quant);
    query.prepare("UPDATE articles SET prix=:modifPrix, type=:modifType, quant=:modifQuant, d=:modifDate, marque=:modifMarque WHERE ref =:modifRef");
    query.bindValue(":modifRef",ref);
    query.bindValue(":modifPrix",prix);
    query.bindValue(":modifType",type);
    query.bindValue(":modifQuant",res1);
    query.bindValue(":modifDate",d);
    query.bindValue(":modifMarque",marque);
    return query.exec();
}


bool Articles:: recherche(QString ref)
{
    QSqlQuery query;
    query.prepare("select * from articles where ref=:ref");
    query.bindValue(":ref",ref);
    return query.exec() ;
}
QSqlQuery Articles ::sortie(QString ref)
 {
     QSqlQuery query;
     query.prepare("select * from articles where (ref:=ref)");
     query.bindValue(":ref",ref);
     return query;
 }
QSqlQueryModel * Articles :: trierarticles()
{
    QSqlQueryModel * model= new QSqlQueryModel();

    model->setQuery("select * from articles where type = 'Alimentaire' ORDER BY quant");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ref"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("prix"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("type"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("quant"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("date"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("marque"));
    return model;
}
QSqlQueryModel * Articles :: trierarticles1()
{
    QSqlQueryModel * model= new QSqlQueryModel();

    model->setQuery("select * from articles where type = 'Congele' ORDER BY quant ;");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ref"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("prix"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("type"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("quant"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("date"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("marque"));
    return model;
}
QSqlQueryModel * Articles :: trierarticles2()
{
    QSqlQueryModel * model= new QSqlQueryModel();

    model->setQuery("select * from articles where type = 'Electronique' ORDER BY quant ;");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ref"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("prix"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("type"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("quant"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("date"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("marque"));
    return model;
}
QSqlQueryModel * Articles :: trierprix()
{
    QSqlQueryModel * model= new QSqlQueryModel();

    model->setQuery("select * from articles where type = 'Alimentaire' ORDER BY prix");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ref"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("prix"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("type"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("quant"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("date"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("marque"));
    return model;
}
QSqlQueryModel * Articles :: trierprix1()
{
    QSqlQueryModel * model= new QSqlQueryModel();

    model->setQuery("select * from articles where type = 'Congele' ORDER BY prix");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ref"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("prix"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("type"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("quant"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("date"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("marque"));
    return model;
}
QSqlQueryModel * Articles :: trierprix2()
{
    QSqlQueryModel * model= new QSqlQueryModel();

    model->setQuery("select * from articles where type = 'Electronique' ORDER BY prix");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ref"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("prix"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("type"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("quant"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("date"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("marque"));
    return model;
}
QString Articles:: nombreArticle()
{
    QSqlQuery query;
    query.prepare("SELECT COUNT(*) cnt FROM articles");
    query.exec();
    while(query.next()){
        return query.value(0).toString();
    }
}
QString Articles:: prixHaut()
{
    QSqlQuery query;
    query.prepare("SELECT MAX(prix) FROM articles");
    query.exec();
    while(query.next()){
        return query.value(0).toString();
    }
}
QString Articles:: prixBas()
{
    QSqlQuery query;
    query.prepare("SELECT MIN(prix) FROM articles");
    query.exec();
    while(query.next()){
        return query.value(0).toString();
    }
}
void Articles::clearTable(QTableView *table){
    QSqlQueryModel *model=new QSqlQueryModel();
    model->clear();
    table->setModel(model);}
void Articles::searchRegexp0(QTableView *table, QString x){
    QSqlQueryModel *model=new QSqlQueryModel();
    QSqlQuery *query =new QSqlQuery;
    query->prepare("select * from articles where regexp_like(ref,:ref) ;");
    query->bindValue(":ref",x);

    if(x==0){qDebug("tawa 0");

        query->prepare("select * from articles ;");   }
    query->exec();
    model->setQuery(*query);
    table->setModel(model);
    table->show();

}

void Articles::searchRegexp(QTableView *table, QString x){
    QSqlQueryModel *model=new QSqlQueryModel();
    QSqlQuery *query =new QSqlQuery;
    query->prepare("select * from articles where regexp_like(ref,:ref) and type = 'Alimentaire';");
    query->bindValue(":ref",x);

    if(x==0){qDebug("tawa 0");

        query->prepare("select * from articles where type = 'Alimentaire';");   }
    query->exec();
    model->setQuery(*query);
    table->setModel(model);
    table->show();

}
void Articles::searchRegexp1(QTableView *table, QString x){
    QSqlQueryModel *model=new QSqlQueryModel();
    QSqlQuery *query =new QSqlQuery;
    query->prepare("select * from articles where regexp_like(ref,:ref) and type = 'Congele';");
    query->bindValue(":ref",x);

    if(x==0){qDebug("tawa 0");

        query->prepare("select * from articles where type = 'Congele';");   }
    query->exec();
    model->setQuery(*query);
    table->setModel(model);
    table->show();

}
void Articles::searchRegexp2(QTableView *table, QString x){
    QSqlQueryModel *model=new QSqlQueryModel();
    QSqlQuery *query =new QSqlQuery;
    query->prepare("select * from articles where regexp_like(ref,:ref) and type = 'Electronique';");
    query->bindValue(":ref",x);

    if(x==0){qDebug("tawa 0");

        query->prepare("select * from articles where type = 'Electronique';");   }
    query->exec();
    model->setQuery(*query);
    table->setModel(model);
    table->show();

}
int Articles :: nombreCategorie1()
{
    QSqlQuery query;
    query.prepare("select COUNT(*) from articles where type='Alimentaire'");
    query.exec();
    while(query.next()){
        return query.value(0).toInt();
    }
}

int Articles :: nombreCategorie2()
{
    QSqlQuery query;
    query.prepare("select COUNT(*) from articles where type='Congele'");
    query.exec();
    while(query.next()){
        return query.value(0).toInt();
    }
}

int Articles :: nombreCategorie3()
{
    QSqlQuery query;
    query.prepare("select COUNT(*) from articles where type='Vetements'");
    query.exec();
    while(query.next()){
        return query.value(0).toInt();
    }
}

QSqlQueryModel * Articles :: afficherRef()
{
    QSqlQueryModel * model= new QSqlQueryModel();
    model->setQuery("Select ref from articles");
    model->setHeaderData(0, Qt::Horizontal,QObject::tr("ref"));

    return model;
}
