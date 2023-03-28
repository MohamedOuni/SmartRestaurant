#include "gestion_livraison.h"

#include <livreur.h>
#include <livraison.h>
#include <QMessageBox>
#include "mainwindow.h"
#include "ui_mainwindow.h"

/*gestion_livraison::gestion_livraison(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::gestion_livraison)
{
    ui->setupUi(this);
    ui->tab_livreur->setModel(L.afficher());
    ui->tab_livraison->setModel(liv.afficher());

}

gestion_livraison::~gestion_livraison()
{
    delete ui;
}


void gestion_livraison::on_pushButton_clicked()
{
    QString cin=ui->cin->text();
    QString nom=ui->le_nom->text();
    QString tel=ui->le_tel->text();
    QString disponibilite=ui->le_disponibilite->text();


        livreur L(cin,nom,tel,disponibilite);
        if(nom == "")
            {
                QMessageBox::critical(nullptr, QObject::tr("Problem "),
                                               QObject::tr("Champ vide !\n"
                                                           "Click Cancel to exit."), QMessageBox::Cancel);
            }
       else{ bool test=L.ajouter();
    if(test)
    { QMessageBox::information(nullptr,QObject::tr("OK"),
                QObject::tr("Ajout effectué"), QMessageBox::Cancel);
        ui->tab_livreur->setModel(L.afficher());
    }
    else
        QMessageBox::critical(nullptr,QObject::tr("Not OK"),
                              QObject::tr("Ajout non effectué"), QMessageBox::Cancel);
}
}

void gestion_livraison::on_pushButton_4_clicked()
{
    livreur l;
            QString x=ui->suppline->text();
            bool test=l.supprimer(x);
            QMessageBox msgBox;

            if(test)
               {
                msgBox.setText("Suppression avec succes.");
                ui->tab_livreur->setModel(L.afficher());
                }
            else
               { msgBox.setText("Echec de suppression");
                msgBox.exec();}
}

void gestion_livraison::on_pushButton_3_clicked()
{
    QString cin=ui->cin_modifier->text();
    QString disponibilite= ui->disponibilite_modifier->text();
    QString nom= ui->nom_modifier->text();
    QString tel= ui->tel_modifier->text();


         livreur L(cin,nom,tel,disponibilite);
         bool test=L.modifier();
         QMessageBox msgBox;
        if(test)
          {  msgBox.setText("Modifier avec succes.");
             ui->tab_livreur->setModel(L.afficher());
          }
        else
           { msgBox.setText("Echec de modification");
            msgBox.exec();}
}

void gestion_livraison::on_lineEdit_recherche_textChanged(const QString &arg1)
{
    livreur l;

        l.cleartable(ui->tab_livreur);
    QString nom = ui->lineEdit_recherche->text();
    l.recherche(ui->tab_livreur,nom);
    if (ui->lineEdit_recherche->text().isEmpty())
    {
        ui->tab_livreur->setModel(l.afficher());
    }
}

void gestion_livraison::on_pushButton_5_clicked()
{QString commande=ui->numcommande->text();
    QString nom=ui->nomclient->text();
    QString tel=ui->tel->text();
    QString region=ui->region->text();
    QString ville=ui->ville->text();
    QString adresse=ui->adresse->text();



        livraison L(commande,nom,tel,region,ville,adresse);
        if(nom == "")
            {
                QMessageBox::critical(nullptr, QObject::tr("Problem "),
                                               QObject::tr("Champ vide !\n"
                                                           "Click Cancel to exit."), QMessageBox::Cancel);
            }
       else{ bool test=L.ajouter();
    if(test)
    { QMessageBox::information(nullptr,QObject::tr("OK"),
                QObject::tr("Ajout effectué"), QMessageBox::Cancel);
        ui->tab_livraison->setModel(L.afficher());
    }
    else
        QMessageBox::critical(nullptr,QObject::tr("Not OK"),
                              QObject::tr("Ajout non effectué"), QMessageBox::Cancel);
}

}

void gestion_livraison::on_pushButton_6_clicked()
{QString commande=ui->numcommande1->text();
    QString region= ui->region1->text();
    QString nom= ui->nomclient1->text();
    QString tel= ui->tel1->text();
    QString ville= ui->ville1->text();
    QString adresse= ui->adresse1->text();



         livraison L(commande,nom,tel,region,ville,adresse);
         bool test=L.modifier();
         QMessageBox msgBox;
        if(test)
          {  msgBox.setText("Modifier avec succes.");
             ui->tab_livraison->setModel(L.afficher());
          }
        else
           { msgBox.setText("Echec de modification");
            msgBox.exec();}

}



void gestion_livraison::on_pushButton_7_clicked()
{
    livraison liv;
            QString x=ui->lineEdit_7->text();
            bool test=liv.supprimer(x);
            QMessageBox msgBox;

            if(test)
               {
                msgBox.setText("Suppression avec succes.");
                ui->tab_livraison->setModel(liv.afficher());
                }
            else
               { msgBox.setText("Echec de suppression");
                msgBox.exec();}
}

void gestion_livraison::on_Retour_clicked()
{
    MainWindow *w = new MainWindow;
    hide();
    w->show();
}

void gestion_livraison::on_Retour_2_clicked()
{

    MainWindow *w = new MainWindow;
    hide();
    w->show();
}
*/
