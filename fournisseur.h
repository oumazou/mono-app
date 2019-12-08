#ifndef FOURNISSEUR_H
#define FOURNISSEUR_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
class Fournisseur
{public:
    Fournisseur();
    Fournisseur(long,QString,int,QString);
    QString get_nom();
    QString get_mail();
    int get_rating();
    long get_num();
    bool ajouter();
    QSqlQueryModel * afficher();
    bool supprimer(QString);
    bool Modifier(long,QString,int,QString);
    bool rech(QString);
    QSqlQueryModel * trier();
private:
    long num;
    QString nom;
    int rating;
    QString mail;

};

#endif // FOURNISSEUR_H
