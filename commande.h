#ifndef COMMANDE_H
#define COMMANDE_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include<QDate>
#include<QTableView>
class commande
{public:
    commande();
    commande(int,QDate,double);
   int get_num()
    {return num;}
    bool ajouter();
    QSqlQueryModel * afficher();
    QSqlQueryModel * afficherArticles();
    QSqlQueryModel * afficherNum();
    bool supprimer(int);
    bool rech(int);
    bool modifier(int,QDate,double);
    void setNum(int num)
    {this->num=num;}
    int getNum()
    { return num;}
    QDate getDates()
    { return dates;}
    double getMontant()
    { return montant;}
    QSqlQueryModel * triercommande();
    QSqlQueryModel * triercommande2();
    int montantHaut();
    int montantBas();
    int nombrecommande();
    void clearTable(QTableView*); /**/
    QSqlQueryModel * affecter(int,QString); /**/
    bool supprimerAffect(int);
    QSqlQueryModel * afficherAffectation();
       void searchRegexp(QTableView*,int); /**/
        void searchRegexp2(QTableView*,int); /**/
    ~commande(){}

private:
    int num;
    QDate dates;
    double montant;
};

#endif // COMMANDE_H
