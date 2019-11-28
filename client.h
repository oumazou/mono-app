#ifndef CLIENT_H
#define CLIENT_H

#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>

class Client
{
private:
    int ID;
    QString Nom;
    QString Prenom;
    QString Sexe;
    QString Adresse;
    int Etat;
    QString Num;

public:
    Client();
    Client(int,QString,QString,QString,QString,int,QString);

    int getID();
    void setID(int);
    QString getNom();
    void setNom(QString);
    QString getPrenom();
    void setPrenom(QString);
    QString getSexe();
    void setSexe(QString);
    QString getAdresse();
    void setAdresse(QString);
    int getEtat();
    void setEtat(int);
    QString getNum();
    void setNum(QString);

    QSqlQueryModel *Afficher();
    QSqlQueryModel *Afficher_ID();
    QSqlQueryModel *recheche(QString);
    bool Ajouter();
    bool Supprimer();
    bool Modifier(int);
    bool Modifier_Adr(QString);
    bool Modifier_Num(QString);
    bool verif();
};

#endif // CLIENT_H
