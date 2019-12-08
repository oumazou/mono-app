#ifndef CONGE_H
#define CONGE_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QTableView>
#include <QDate>
class Conge
{
public:
    Conge();
    Conge(int,QDate,QDate,int);
    QString get_debutconge();
    QString get_finconge();
    int get_num();
    int get_iduser();

    bool ajouter();
    bool supprimer(int);
    QSqlQueryModel * afficher();
    bool recherche(int);
    bool modifier(int numero,QDate debutconge,QDate finconge,int idemp);

    void clearTable(QTableView*);
    void searchRegexp(QTableView*,int);
QSqlQueryModel *  trierConge();
private:
    QDate debutconge;
    QDate finconge;
    int num,idemp;
};

#endif // CONGE_H
