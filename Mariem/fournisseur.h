#ifndef FOURNISSEUR_H
#define FOURNISSEUR_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QTableView>
class Fournisseur
{public:
    Fournisseur();
    Fournisseur(int,int,QString,QString);
    QString get_nom();
    QString get_mail();
    int get_rating();
    int get_num();
    bool ajouter();
    QSqlQueryModel * afficher();
    bool supprimer(int);
    bool Modifier(int,int,QString,QString);
    bool rech(int);
    QSqlQueryModel * trier();
    void clearTable(QTableView*);
     void searchRegexp(QTableView*,int);
private:
    int num;
    QString nom;
    int rating;
    QString mail;

};

#endif // FOURNISSEUR_H
