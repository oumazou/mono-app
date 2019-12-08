#ifndef LOGIN2_H
#define LOGIN2_H

#include <QString>
#include <QObject>
#include <QSqlQueryModel>
#include <QWidget>
#include "connection.h"
#include <QDate>
#include <QTableView>

class login2
{
    QString utilisateur,password;
    int type;
public:
    login2(QString,QString);
        int getType(){
            return type;
        }
        void setType(int type){
            this->type = type;
        }
       int seconnect(QString,QString);
        bool checkuser();
        ~login2(){}

};

#endif // LOGIN2_H
