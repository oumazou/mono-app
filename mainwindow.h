#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "employee.h"
#include "conge.h"
#include <QMainWindow>

//QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
//QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
   explicit  MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:

    void on_pushButton_clicked();

    void on_pushButton_remplirconge_clicked();

    void on_tabcong_activated(const QModelIndex &index);

    void on_pushButton_annulerconge_clicked();

    void on_pushButton__modifier_emp_clicked();

    void on_pushButton_supprimer_emp_clicked();

    void on_tabemp_activated(const QModelIndex &index);

    void on_pushButton_modifiercong_clicked();

    void on_rechlineedit_textChanged(const QString &arg1);

    void on_rechlineedit_2_textChanged(const QString &arg1);

    void on_pushButton_Activer_Modifier_clicked();

    void on_pushButton_annuler_clicked();

    void on_rechlineedit_2_cursorPositionChanged(int arg1, int arg2);

    void on_pushButton_trier_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::MainWindow *ui;
    Employee tmpemp;
    Conge tmpcong;
};
#endif // MAINWINDOW_H
