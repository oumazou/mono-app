#ifndef ARTICLES_H
#define ARTICLES_H
#include <QString>
#include <QObject>
#include <QSqlQueryModel>
#include <QWidget>
#include<QTableView>


class Articles
{
    int ref;
    QString type;
    QString marque;
    double prix;



    public:
        Articles();
        Articles (int ref,QString type,QString marque,double prix);
         bool ajouter();
         QSqlQueryModel * afficher();
         QSqlQueryModel * afficherRef();
         void  supprimer(int ref);
         bool  modifier();
         void setRef(int ref) {this->ref=ref;}
         bool  rechA();
         QSqlQueryModel * afficherarticlechercher(int);
         void clearTable(QTableView*);
            void searchRegexp(QTableView*,int);
            int nombreArticles();
        ~Articles(){}
};
#endif // ARTICLES_H
