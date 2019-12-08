#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "commande.h"
#include <QMainWindow>
#include"client.h"
#include "reclamations.h"
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr,int type=0);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();
    void  load();


    void on_pushButton_10_clicked();

    void on_pushButton_11_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_7_clicked();

    void on_pushButton_9_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_8_clicked();

    void on_pushButton_14_clicked();

    void on_pushButton_13_clicked();

    void on_pushButton_34_clicked();

    void on_pushButton_33_clicked();

    void on_pushButton_16_clicked();

    void on_pushButton_35_clicked();

    void on_pushButton_37_clicked();

    void on_pushButton_15_clicked();

    void on_pushButton_12_clicked();

    void on_pushButton_36_clicked();

    void on_pushButton_17_clicked();

    void on_pushButton_38_clicked();

    void on_pushButton_18_clicked();

    void on_pushButton_19_clicked();

    void on_pushButton_20_clicked();

    void on_pushButton_23_clicked();

    void on_pushButton_22_clicked();

    void on_pushButton_21_clicked();

    void on_tableView_activated(const QModelIndex &index);

    void on_pushButton_24_clicked();

    void on_lineEdit_textChanged(const QString &arg1);

    void on_pushButton_ajout_clicked();

    void on_pushButton_article_clicked();

    void on_pushButton_stock_clicked();

    void on_a1_linkActivated(const QString &link);

    void on_piechart_clicked();

    void on_ar_clicked();

    void on_sto_clicked();

    void on_ok_clicked();

    void on_affichage_clicked();

    void on_prom_clicked();

    void on_pushButton_28_clicked();

    void on_label_50_windowIconTextChanged(const QString &iconText);

    void on_recherche_textChanged(const QString &arg1);

    void on_tableView_3_activated(const QModelIndex &index);

    void on_modif_clicked();

    void on_suppp_clicked();

    void on_pushButton_26_clicked();

    void on_stooock_clicked();

    void on_promoooo_clicked();

    void on_affecter_clicked();

    void on_valide_clicked();

    void on_suppppp_clicked();

    void on_tableView_4_activated(const QModelIndex &index);

    void on_aaa_clicked();

    void on_bbb_clicked();

    void on_ccc_clicked();

    void on_modiffff_clicked();

    void on_suprimmm_clicked();

    void on_prommm_clicked();

    void on_ajoutemploy_clicked();

    void on_aa_clicked();

    void on_abab_clicked();

    void on_emp_activated(const QModelIndex &index);

    void on_supppp_clicked();

    void on_trieeeee_clicked();

    void on_recherchee_cursorPositionChanged(int arg1, int arg2);

    void on_emppp_clicked();

    void on_congeee_clicked();

    void on_ajoutconge_clicked();

    void on_tableView_5_activated(const QModelIndex &index);

    void on_push_clicked();

    void on_abab_2_clicked();
    void  load2();

    void on_supppp_2_clicked();

    void on_recherchee_2_cursorPositionChanged(int arg1, int arg2);

    void on_recherchee_2_textChanged(const QString &arg1);

    void on_trieeeee_2_clicked();

    void on_arrt_clicked();

    void on_pushButton_109_clicked();

    void on_pushButton_ajout_4_clicked();

    void on_pushButton_116_clicked();

    void on_modiffff_4_clicked();

    void on_tableView_14_activated(const QModelIndex &index);

    void on_pushButton_555_clicked();

    void on_pushButton_121_clicked();

    void on_pushButton_115_clicked();

    void on_suprimmm_4_clicked();

    void on_lineEdit_2_textChanged(const QString &arg1);

    void on_lineEdit_3_textChanged(const QString &arg1);

    void on_pushButton_888_clicked();

    void on_pushButton_123_clicked();

    void on_pushButton_ajout_5_clicked();

    void on_modiffff_5_clicked();

    void on_tableView_15_activated(const QModelIndex &index);

    void on_suprimmm_5_clicked();

    void on_pushButton_12111_clicked();

    void on_pushButton_111_clicked();

    void on_pushButton_110_clicked();

    void on_pushButton_114_clicked();

    void on_pushButton_117_clicked();

    void on_pushButton_118_clicked();

    void on_pushButton_122_clicked();

    void on_pushButton_444444_clicked();

    void on_pushButton_24444_clicked();

    void on_pushButton_106_clicked();

    void on_pushButton_stock1_clicked();

    void on_pushButton_1077_clicked();

    void on_pushButton_113_clicked();

    void on_pushButton_stock_4_clicked();

    void on_pushButton_119_clicked();

    void on_pushButton_stock_5_clicked();

    void on_ajoutCommande_clicked();

    void on_pushButton_128_clicked();

    void on_pushButton_ajout_6_clicked();

    void on_suprimmm_6_clicked();

    void on_liste_commande_activated(const QModelIndex &index);

    void on_comboBox_3_currentIndexChanged(const QString &arg1);

    void on_affect_clicked();

    void on_pushButton_127_clicked();

    void on_affecter1_clicked();

    void on_rechercheC_textChanged(const QString &arg1);

    void on_modifierCommande_clicked();

    void on_trier_clicked();

    void on_pushButton_129_clicked();

    void on_pushButton_130_clicked();

    void on_pushButton_131_clicked();

    void on_pushButton_30_clicked();

    void on_client_clicked();

    void on_articleees_clicked();

    void on_ajoutReclamations_7_clicked();

    void on_ajoutReclamations_5_clicked();

    void on_comboBox_currentIndexChanged(const QString &arg1);

    void on_comboBox_2_currentIndexChanged(const QString &arg1);

    void on_modiferReclamations_clicked();

    void on_liste_reclamation_activated(const QModelIndex &index);

    void on_lineEdit_7_textChanged(const QString &arg1);

    void on_suprimerReclamations_clicked();

    void on_pushButton_12222_clicked();

    void on_pb_ajouter_clicked();

private:
    Ui::MainWindow *ui;
    commande tmpcommande;
    Client tmpclient;
    reclamations tmpreclamations;
};
#endif // MAINWINDOW_H
