#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "fournisseur.h"
#include "arduino.h"
#include "articles.h"
#include "commandeachat.h"
#include <QMainWindow>
#include <QPropertyAnimation>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pb_ajouter_clicked();
    void on_pushButton_3_clicked();
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();
    void on_tabWidget_currentChanged(int index);
    void on_pb_supprimer_clicked();
    void on_pushButton_9_clicked();
    void on_trierfournisseur_clicked();
    void on_pushButton_6_clicked();
    void on_pushButton_4_clicked();
    void on_pushButton_7_clicked();


    void on_tableview_activated(const QModelIndex &index);

    void on_lineEdit_4_textChanged(const QString &arg1);

    void on_recherche_textChanged(const QString &arg1);

    void on_pushButton_5_clicked();

    void on_pushButton_8_clicked();

private:
    Ui::MainWindow *ui;
    QPropertyAnimation *animation;
    Fournisseur tmpFournisseur;
    commandeachat tmpc;
    Articles tmparticles;
    QByteArray data;
    arduino A;
};

#endif // MAINWINDOW_H
