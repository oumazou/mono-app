#ifndef CONGE_H
#define CONGE_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QTableView>

class Conge
{
public:
    Conge();
    Conge(int,QString,QString,int);
    Conge(QString,QString,int);
    QString get_debutconge();
    QString get_finconge();
    int get_num();
    int get_iduser();

    bool ajouter();
    bool supprimer(int);
    QSqlQueryModel * afficher();
    bool recherche(int);
    bool modifier(QString,QString,int);

    void clearTable(QTableView*);
    void searchRegexp(QTableView*,int);

private:
    QString debutconge,finconge;
    int num,iduser;
};

#endif // CONGE_H
