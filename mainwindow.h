#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();

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

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
