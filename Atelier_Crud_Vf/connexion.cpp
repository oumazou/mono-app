#include "connexion.h"
#include <QSqlError>
Connexion::Connexion(){ db = QSqlDatabase::addDatabase("QODBC");
                        db.setDatabaseName("Source_Projet2A");
                        db.setUserName("hichri");//inserer nom de l'utilisateur
                        db.setPassword("123456789");//inserer mot de passe de cet utilisateur
                      }
bool Connexion::ouvrirConnexion()
{bool test=false;


if (db.open())
    test=true;


return  test;
}
void Connexion::fermerConnexion()
{db.close();}
