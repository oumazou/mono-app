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
    reclamations(int,QDate,int,int);
   int get_num()
    {return num;}
    bool ajouter();
    QSqlQueryModel * afficher();
    bool supprimer(int);
    bool reche(int);
    bool modifier(int,QDate,int,int);
    void setNum(int num)
    {this->num=num;}
    QSqlQueryModel * trierReclamation();
    void clearTable(QTableView*);
       void searchRegexp(QTableView*,int);
    ~reclamations(){}
private:

    int num;
    QDate d;
    int ref;
    int cin;



};
#endif // RECLAMATIONS_H
