#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "stat_commande.h"
#include "stat_article.h"
#include<QPropertyAnimation>
#include "QSystemTrayIcon"
#include <QMainWindow>
#include "absence.h"
#include "personnel.h"
#include "menu_impl.h"
#include "commande_impl.h"
#include "livraison.h"
#include "livreur.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    //login
    void on_pushButton_2_login_clicked();
    //acceuil
    void on_gestio_tables_clicked();
    void on_pushButton_acceuil_clicked();
    void on_menu_clicked();
    void on_gestion_personnel_clicked();
    void on_gestion_livraison_clicked();
    void on_gestion_article_clicked();
    void on_gestion_fournisseur_clicked();
    void on_gestion_categorie_clicked();
    void on_pushButton_4_clicked();
//menu
    void on_Ajouter_menu_clicked();
    void on_Supprimer_menu_clicked();
    void on_Supprimer2_commande_clicked();
    void on_Supprimer3_commande_clicked();
    void on_txt_Search_menu_textChanged(const QString &arg1);
    void on_Valider_menu_clicked();
    void on_Actualiser_menu_clicked();
    void on_imprimer_commande_clicked();
    void on_Trier_menu_clicked();
    void on_statistique_commande_clicked();
    void on_Retour_menu_clicked();
    void on_Retour_2_commande_clicked();
//article
    void on_pushButton_article_clicked();
    void on_pushButton_2_article_clicked();
    void on_pushButton_3_article_clicked();
    void on_imprimer_article_clicked();
//fournisseur
    void on_pushButton_fournisseur_clicked();
    void on_pushButton_2_fournisseur_clicked();
    void on_pushButton_3_fournisseur_clicked();
    void on_recherche_fournisseur_textChanged(const QString &arg1);
//categorie
    void on_Ajouter_categorie_clicked();
    void on_Supprimer_categorie_clicked();
    void on_txt_Search_categorie_textChanged(const QString &arg1);
    void on_pushButton_categorie_clicked();
//personnel
    void on_pb_ajouter_clicked();
    //void on_pb_supprimer_clicked();
    void on_pushButton_2_clicked();
    void on_lineEdit_textChanged(const QString &arg1);
    //void on_pushButton_3_clicked();
    //void on_pushButton_clicked();
    void on_supprimer_pb_clicked();
    void on_Ajouter_absence_clicked();
    //void on_Modifier_absence_clicked();
    void on_Supprimer_absence_clicked();
    void on_triernom_clicked();
    void on_triermotif_clicked();
    void on_trierdate_clicked();
    void on_Retour_clicked();
    void on_Retour_2_clicked();
    void on_pushButton_6_clicked();
    void on_pdf_absence_clicked();

//livraison
    void on_ajouter_livreur_clicked();
    void on_pushButton_12_clicked();
    void on_lineEdit_recherche_textChanged(const QString &arg1);
    void on_pushButton_5_clicked();
    void on_pushButton_8_clicked();
    void on_pushButton_7_clicked();
    void on_pushButton_11_clicked();
    void on_Retour_5_clicked();
    void on_Retour_6_clicked();

    void on_ajouter_table_clicked();
    void on_supprimer_table_clicked();
    void on_tableView_doubleClicked();
    void on_reset_3_table_clicked();
    void on_modifier_table_clicked();
    void on_radioButton_table_clicked();
    void on_radioButton_2_table_clicked();
    void on_radioButton_3_table_clicked();
    void on_retour_table_clicked();
    void myfunction();
    void on_ajouter_reservation_clicked();
    void on_modifier_reservation_clicked();
    void on_supprimer_reservation_clicked();
    void on_tableView_reservation_doubleClicked();
    void on_reset_3_reservation_clicked();
    void on_recherche_reservation_textChanged(const QString &arg1);
    void on_retour_reservation_clicked();
    void myfunction_reservation();

private slots:
    void on_retour_2_table_clicked();
    void on_retour_3_table_clicked();
    void on_pushButton_13_table_clicked();
    void on_retour_2_reservation_clicked();
    void on_retour_3_reservation_clicked();
    void on_retour_4_reservation_clicked();
    void on_pushButton_13_reservation_clicked();
    /*void on_label_linkActivated(const QString &link);*/




    void on_statistique_article_clicked();

    void on_pushButton_13_reservation_2_clicked();

private:
    Ui::MainWindow *ui;
    stat_commande *s;
    stat_article *a;
    QSystemTrayIcon *mysystem;
    Personnel P;
    Absence A;
    livreur L ;
    livraison liv;
    QPropertyAnimation *animation;
    QTimer *timer;
    QSystemTrayIcon *notifyicon;

};

#endif // MAINWINDOW_H
