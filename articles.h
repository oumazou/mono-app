#ifndef ARTICLES_H
#define ARTICLES_H
#include <QString>
#include <QObject>
#include <QSqlQueryModel>
#include <QWidget>
#include "connection.h"
#include <QDate>
#include <QTableView>

class Articles
{
    QString ref;
    QString prix;
    QString type;
    int quant;
    QDate d;
    QString marque;

public:
    Articles();
    Articles (QString ref,QString prix,QString type, int quant, QDate d, QString marque);
    bool ajouter();
    QSqlQueryModel * afficher();
    QSqlQueryModel * afficher1();
    QSqlQueryModel * afficher2();
    QSqlQueryModel * afficherRef();
    void searchRegexp0(QTableView *table, QString x);
    bool supprimer(QString ref);
    QSqlQuery sortie(QString ref);
    bool  modifier(QString ref, QString prix, QString type, int quant, QDate d, QString marque);
    void setRef(QString Ref) {this->ref=Ref;}
    void clearTable(QTableView*);
    void searchRegexp(QTableView*,QString);
    void searchRegexp1(QTableView *table, QString x);
     void searchRegexp2(QTableView *table, QString x);
    bool  recherche(QString);
    QSqlQueryModel *  trierarticles();
      QSqlQueryModel *  trierarticles1();
            QSqlQueryModel *  trierarticles2();
    QSqlQueryModel *  trierprix();
    QSqlQueryModel *  trierprix1();
    QSqlQueryModel *  trierprix2();
    QString nombreArticle();
    QString prixHaut();
    QString prixBas();
    QString* listeType();
    int nombreCategorie1();
    int nombreCategorie2();
    int nombreCategorie3();

    QString nombre(QString typ);
    ~Articles(){}
};
#endif // ARTICLES_H
