
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "eleve.h"
#include "activite.h"



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
    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_to_eleve_clicked();

    void on_pushButton_to_act_clicked();

    void on_pushButton_to_part_clicked();

    void on_pushButton_ajout_el_clicked();

    void on_pushButton_del_el_clicked();

    void on_tableView_eleve_doubleClicked(const QModelIndex &index);

    void on_pushButton_mod_eleve_clicked();

    void on_pushButton_ajout_act_clicked();

    void on_pushButton_del_act_clicked();

    void on_tableView_act_doubleClicked(const QModelIndex &index);

    void on_pushButton_mod_act_clicked();

    void on_pushButton_eleve_triID_clicked();

    void on_pushButton_eleve_tri_class_clicked();

    void on_pushButton_eleve_tri_sexe_clicked();

    void on_pushButton_act_triID_clicked();

    void on_pushButton_act_trinom_clicked();

    void on_pushButton_act_tri_nbrP_clicked();

    void on_lineEdit_eleve_sea_id_textChanged(const QString &arg1);

    void on_lineEdit_eleve_sea_nom_textChanged(const QString &arg1);

    void on_lineEdit_eleve_sea_classe_textChanged(const QString &arg1);

    void on_lineEdit_act_sea_id_textChanged(const QString &arg1);

    void on_lineEdit_act_sea_nom_textChanged(const QString &arg1);

    void on_lineEdit_act_sea_type_textChanged(const QString &arg1);

    void on_pushButton_act_pdf_clicked();

    void on_pushButton_eleve_pdf_clicked();

private:
    Ui::MainWindow *ui;
    eleve ptmp;
    activite ptmp1;
};

#endif // MAINWINDOW_H
