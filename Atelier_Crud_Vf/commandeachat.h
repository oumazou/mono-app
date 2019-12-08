#ifndef COMMANDEACHAT_H
#define COMMANDEACHAT_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QDate>
#include <QTableView>

class commandeachat
{
public:
    commandeachat();
    commandeachat(int,float,float,QDate);
    int get_num();
    float get_weight();
    float get_price();
    QDate get_datee();
    bool ajouter();
    QSqlQueryModel * afficher();
    bool supprimer(int);
    bool Modifier(int,float,float,QDate);
    QSqlQueryModel * trier();
    bool rech(int);
    void cleartable(QTableView*);
    QSqlQueryModel * affecter(int,int);
    void searchRegexp(QTableView *,int);
    void searchRegexp2(QTableView *,int);
    QSqlQueryModel * afficherArticles();

private:
    int num;
    float weight;
    float price;
    QDate datee;
};

#endif // COMMANDEACHAT_H
