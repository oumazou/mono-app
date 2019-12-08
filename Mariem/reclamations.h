#ifndef RECLAMATIONS_H
#define RECLAMATIONS_H
#include <QString>
#include <QSqlQuery> //sécurité (injection)
#include <QSqlQueryModel>
#include <QDate>
#include<QTableView>
class reclamations
{public:
    reclamations();
    reclamations(int,QDate,QString,int,QString);
   int get_num()
    {return num;}
    bool ajouter();
    QSqlQueryModel * afficher();
    bool supprimer(int);
    bool reche(int);
    bool modifier(int,QDate,QString,int,QString);
    void setNum(int num)
    {this->num=num;}
    QSqlQueryModel * trierReclamation();
    QSqlQueryModel * trierReclamation2();
    void clearTable(QTableView*);
       void searchRegexp(QTableView*,int);
       int nombreReclamation();
       int nombrehomme();
    ~reclamations(){}
private:

    int num;
    QDate d;
    QString ref;
    int cin;
    QString type;


};
#endif // RECLAMATIONS_H

