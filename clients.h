#ifndef CLIENTS_H
#define CLIENTS_H
#include <QString>
#include <QObject>
#include <QSqlQueryModel>
#include <QWidget>
#include <QTableView>



class clients
{
    int cin;
    QString nom;
    QString prenom;
    QString sexe;
    int tel;


    public:
        clients();
        clients (int cin,QString nom,QString prenom,QString sexe,int tel);
         bool ajouter();
         QSqlQueryModel * afficher();
         QSqlQueryModel * afficherCin();
         void  supprimer(int cin);
         bool  modifier();
         void setRef(int cin) {this->cin=cin;}
         void clearTable(QTableView*);
            void searchRegexp(QTableView*,int);
         bool  rechC();


         QSqlQueryModel * afficherNom();
         QSqlQueryModel * afficherPrenom();
         QSqlQueryModel * afficherSexe();
         QSqlQueryModel * afficherTel();
         QSqlQueryModel * afficherclientchercher(int);
        ~clients(){}
};

#endif // CLIENTS_H
