#ifndef CARTE_H
#define CARTE_H

#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>

class Carte
{
private:
    int ID;
    int ID_Client;
    QString Points;
public:
    Carte();
    Carte(int,int,QString);

    int getID();
    void setID(int);
    int getID_Client();
    void setID_Client(int);
    QString getPoints();
    void setPoints(QString);

    QSqlQueryModel *Afficher();
    QSqlQueryModel *Trier_points();
    bool Ajouter();
    bool Supprimer();
    bool Modifier(QString);
    bool verif();
    bool verif_cl();
};

#endif // CARTE_H
