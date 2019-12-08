#ifndef PROMOTIONS_H
#define PROMOTIONS_H
#include <QString>
#include <QObject>
#include <QSqlQueryModel>
#include <QWidget>
#include "connection.h"
#include <QDate>
#include <QTableView>

class Promotions
{
    int num;
    int pourcentage;
    QDate d;
    int jours;

public:
    Promotions();
    Promotions(int,int,QDate,int);
    bool ajouter();
    QSqlQueryModel * trierpourcentage();
    QSqlQueryModel *  trierduree();
    QSqlQueryModel * afficher();
    QSqlQueryModel * afficherAffectation();
    bool supprimer(int num);
    bool  modifier(int num,int pourcentage ,QDate d,int jours);
    QString upcoming();
    QString highPromotion();
    QString lowPromotion();
    bool recherche(int num);
    void clearTable(QTableView*);
    void searchRegexp(QTableView*,QString);
    void affecter(QString num, QString ref);
    void supprimerAffect(QString num, QString ref);
};
#endif // PROMOTIONS_H
