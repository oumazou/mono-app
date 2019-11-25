#ifndef CHOOSE_H
#define CHOOSE_H
#include <QDialog>
#include "commande.h"
#include "reclamations.h"
#include "clients.h"
#include "articles.h"
namespace Ui {
class choose;
}

class choose : public QDialog
{
    Q_OBJECT

public:
    explicit choose(QWidget *parent = nullptr);
    ~choose();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_12_clicked();

    void on_retour_commande_clicked();

    void on_retour_reclamations_clicked();

    void on_retour_paiement_clicked();

    void on_ajoutCommande_clicked();

    void on_ajoutReclamations_clicked();

    void on_suprimerReclamations_clicked();

    void on_suprimerCommande_clicked();

    void on_modifierCommande_clicked();

    void on_retourConnexion_clicked();

    void on_modifierReclamations_clicked();

    void on_modifierR_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_15_clicked();

    void on_pushButton_14_clicked();

    void on_pushButton_13_clicked();

    void on_trierCommande_clicked();

    void on_trierReclamations_clicked();

    void on_pushButton_17_clicked();

    void on_pushButton_8_clicked();

    void on_ajoutClient_clicked();

    void on_ajouterArticle_clicked();

    void on_rechercheC_textChanged(const QString &arg1);

    void on_liste_commande_activated(const QModelIndex &index);

    void on_modifC_clicked();

    void on_annuC_clicked();

    void on_tableClient_activated(const QModelIndex &index);


    
    void on_pushButton_19_clicked();

    void on_comboBox_currentIndexChanged(const QString &arg1);

    void on_pushButton_11_clicked();

    void on_modifiercommande_clicked();

    void on_comboBox_3_activated(const QString &arg1);

    void on_comboBox_3_currentIndexChanged(const QString &arg1);

    void on_comboBox_2_currentIndexChanged(const QString &arg1);

    void on_ajoutReclamations_5_clicked();

    void on_lineEdit_7_textChanged(const QString &arg1);

private:
    Ui::choose *ui;
    commande tmpcommande;
    reclamations tmpreclamations;
    clients tmpclients;
    Articles tmparticles;
};

#endif // CHOOSE_H
