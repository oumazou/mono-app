#ifndef EMPLOYEE_H
#define EMPLOYEE_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QTableView>
//#include<QPropertyAnimation>
class Employee
{
public:
    Employee();
    Employee(int,QString,QString,int,QString,int);
    QString get_nom();
    QString get_prenom();
    int get_id();
    int get_num();
    QString get_adresse();
    int get_cnss();
    bool ajouter();
    bool supprimer(int);
    QSqlQueryModel * afficher();
    bool recherche(int);
    bool modifier(int,QString,QString,int,QString,int);

    void clearTable(QTableView*);
    void searchRegexp(QTableView*,int);
    QSqlQueryModel * trier();
private:
    QString nom,prenom,adresse;
    int id,num,cnss;
    //QPropertyAnimation *animation;
};

#endif // EMPLOYEE_H
