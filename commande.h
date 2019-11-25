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

    void clearTable(QTableView*);
       void searchRegexp(QTableView*,int);
    ~commande(){}

private:
    int num;
    QDate dates;
    double montant;
};

#endif // COMMANDE_H
