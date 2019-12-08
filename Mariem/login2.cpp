#include "login2.h"
#include <QMessageBox>
login2::login2(QString utilisateur,QString password)
{
    this->utilisateur = utilisateur;
    this->password = password;
}


int login2::seconnect(QString utilisateur,QString password){
    QSqlQuery query;
    query.prepare("SELECT type FROM personnel WHERE utilisateur = :utilisateur AND password = :password;");
    query.bindValue(":utilisateur",utilisateur);
    query.bindValue(":password",password);
    query.exec();
    while(query.next()){
        return query.value(0).toInt();
    }
}

bool login2::checkuser(){
    QSqlQuery query;
    query.prepare("SELECT type FROM personnel WHERE utilisateur = :utilisateur;");
    query.bindValue(":utilisateur",utilisateur);
    query.exec();
    return query.first();
};
