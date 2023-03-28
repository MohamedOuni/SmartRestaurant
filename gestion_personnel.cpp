#include "gestion_personnel.h"
#include"personnel.h"
#include"absence.h"
#include <QMessageBox>
#include <QIntValidator>
#include<QPrinter>
#include<QPrintDialog>
#include<QFileSystemModel>
#include "login.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"
/*gestion_personnel::gestion_personnel(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::gestion_personnel)
{
    ui->setupUi(this);
    ui->le_id->setValidator( new QIntValidator(0, 99999999, this));
    ui->le_tel->setValidator( new QIntValidator(0, 99999999, this));
    ui->tab_personnel->setModel(P.afficher());
    ui->tab_absence->setModel((A.afficher()));
   ui->comboBox_supp->setModel(P.afficher_CIN());
   ui->comboBox_nom->setModel(P.afficher_NOM());
   ui->comboBox_id3->setModel(A.afficher_ID());
   mysystem = new QSystemTrayIcon(this);
   mysystem->setVisible(true);
}

gestion_personnel::~gestion_personnel()
{
    delete ui;
}

void gestion_personnel::on_pb_ajouter_clicked()
{
    QString cin=ui->le_id->text();
    QString tel=ui->le_tel->text();
    QString service=ui->le_service->currentText();
    QString nom=ui->le_nom->text();
    QString mail=ui->le_prenom->text();
    QString mot_de_passe=ui->le_mdp->text();
    Personnel P(cin,tel,service,nom,mail,mot_de_passe);

    if(nom == ""||service==""||mail==""||mot_de_passe=="")
        {
            QMessageBox::critical(nullptr, QObject::tr("Problem "),
                                           QObject::tr("Champ vide !\n"
                                                       "Click Cancel to exit."), QMessageBox::Cancel);
        }
   else{ bool test=P.ajouter();
if(test)
{ QMessageBox::information(nullptr,QObject::tr("OK"),
            QObject::tr("Ajout effectué"), QMessageBox::Cancel);
    ui->tab_personnel->setModel(P.afficher());
    ui->comboBox_supp->setModel(P.afficher_CIN());
    ui->comboBox_nom->setModel(P.afficher_NOM());
    ui->le_id->setText("");
    ui->le_tel->setText("");
    ui->le_nom->setText("");
    ui->le_prenom->setText("");
    ui->le_mdp->setText("");
    mysystem->show();
    mysystem->showMessage(tr("notification"),tr("Ajout effectué avec succés"));
}
else
    QMessageBox::critical(nullptr,QObject::tr("Not OK"),
                          QObject::tr("Ajout non effectué"), QMessageBox::Cancel);
}

}


void gestion_personnel::on_lineEdit_textChanged(const QString &arg1)
{
    Personnel P;

    P.cleartable(ui->tab_personnel);
QString nom = ui->lineEdit->text();
P.recherche(ui->tab_personnel,nom);
if (ui->lineEdit->text().isEmpty())
{
    ui->tab_personnel->setModel(P.afficher());
}
}

void gestion_personnel::on_supprimer_pb_clicked()
{

        bool test=P.supprimer(ui->comboBox_supp->currentText());
        if(test)
        {ui->tab_personnel->setModel(P.afficher());
                QMessageBox::information(nullptr,QObject::tr("OK"),
                                         QObject::tr("suppression succful .\n"),
                        QMessageBox::Cancel);
            }

            else
                QMessageBox::critical(nullptr,QObject::tr("ERROR"),
                                        QObject::tr("click cancel to exist"),
                                        QMessageBox::Cancel);
        ui->comboBox_supp->setModel(P.afficher_CIN());
        ui->comboBox_nom->setModel(P.afficher_NOM());
        mysystem->show();
        mysystem->showMessage(tr("notification"),tr("suppression effectuée avec succés"));

}

void gestion_personnel::on_Ajouter_absence_clicked()
{
    Absence A(ui->id_absence->text().toInt(),ui->comboBox_nom->currentText(),ui->comboBox_motif->currentText(),ui->date->text());
   bool test= A.ajouterAB();
   if(test)
   { QMessageBox::information(nullptr,QObject::tr("OK"),
               QObject::tr("Ajout effectué"), QMessageBox::Cancel);
       ui->tab_absence->setModel(A.afficher());
       ui->comboBox_id3->setModel(A.afficher_ID());
       //ui->id_absence->setText("");
       mysystem->show();
       mysystem->showMessage(tr("notification"),tr("Ajout effectué avec succés"));
   }
   else
       QMessageBox::critical(nullptr,QObject::tr("Not OK"),
                             QObject::tr("Ajout non effectué"), QMessageBox::Cancel);
   }


void gestion_personnel::on_Supprimer_absence_clicked()
{
    bool test=A.supprimerAB(ui->comboBox_id3->currentText().toInt());
    if(test)
    {ui->tab_absence->setModel(A.afficher());
            QMessageBox::information(nullptr,QObject::tr("ok"),
                                     QObject::tr("suppression succful .\n"),
                    QMessageBox::Cancel);
              ui->comboBox_id3->setModel(A.afficher_ID());
              mysystem->show();
              mysystem->showMessage(tr("notification"),tr("suppression effectuée avec succés"));
        }

        else
            QMessageBox::critical(nullptr,QObject::tr("ERROR"),
                                    QObject::tr("click cancel to exist"),
                                    QMessageBox::Cancel);

}

void gestion_personnel::on_pushButton_2_clicked()
{
   A.telechargerPDF();

    QMessageBox::information(nullptr,QObject::tr("OK"),
               QObject::tr("Téléchargement terminé"), QMessageBox::Cancel);



}

void gestion_personnel::on_pushButton_clicked()
{

    QPrinter printer;
     printer.setPrinterName("imprimer");
     QPrintDialog dialog(&printer, this);
     if (dialog.exec() == QDialog::Rejected) return;
     ui->tab_personnel->render(&printer);

}

void gestion_personnel::on_triernom_clicked()
{
    ui->tab_absence->setModel(A.triernom());
}

void gestion_personnel::on_triermotif_clicked()
{
    ui->tab_absence->setModel(A.triermotif());
}

void gestion_personnel::on_trierdate_clicked()
{
    ui->tab_absence->setModel(A.trierdate());
}



void gestion_personnel::on_Retour_clicked()
{
    MainWindow *w = new MainWindow;
    hide();
    w->show();
}

void gestion_personnel::on_Retour_2_clicked()
{
    MainWindow *w = new MainWindow;
    hide();
    w->show();

}
*/
