#include "fournisseur.h"
#include "categorie_impl.h"
#include "fournisseur_impl.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMediaPlayer>
#include <QMessageBox>
/*Fournisseur::Fournisseur(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Fournisseur)
{
    ui->setupUi(this);
    Categorie_Impl c;
     ui->comboBox->addItems(c.getNames());
}

Fournisseur::~Fournisseur()
{
    delete ui;
}
*/
void MainWindow::on_pushButton_fournisseur_clicked()
{
    QString nom_f = ui->lineEdit_fournisseur->text();
    int tel = ui->lineEdit_2_fournisseur->text().toInt();
    QString categorie = ui->comboBox_fournisseur->currentText();



    if(nom_f == "")
    {
        QMessageBox::critical(nullptr, QObject::tr("problem nom_f"),
                                       QObject::tr("verifier nom_f\n"
                                                   "Click Cancel to exit."), QMessageBox::Cancel);
    }

else if (tel<8){
        QMessageBox::critical(nullptr, QObject::tr("problem tel"),
                                       QObject::tr("verifier tel\n"
                                                   "Click Cancel to exit."), QMessageBox::Cancel);
    }
    else if (categorie == ""){
            QMessageBox::critical(nullptr, QObject::tr("problem categorie"),
                                           QObject::tr("verifier categorie\n"
                                                       "Click Cancel to exit."), QMessageBox::Cancel);
        }
    else
    {
        fournisseur_impl art ;
        art.ajouter(nom_f,categorie,tel);
           ui->tableView_fournisseur->setModel(art.afficher());
           QMediaPlayer * music = new QMediaPlayer();
           music->setMedia(QUrl("qrc:/sounds/ajout.mp3"));
           music->play();
    }
}


void MainWindow::on_pushButton_2_fournisseur_clicked()
{
    fournisseur_impl art ;
    art.supprimer()->removeRow(ui->tableView_fournisseur->currentIndex().row());
      ui->tableView_fournisseur->setModel(art.afficher());
      QMediaPlayer * music = new QMediaPlayer();
      music->setMedia(QUrl("qrc:/sounds/supprime.mp3"));
      music->play();
}

void MainWindow::on_pushButton_3_fournisseur_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}



void MainWindow::on_recherche_fournisseur_textChanged(const QString &arg1)
{
    fournisseur_impl c;

    c.cleartable(ui->tableView_fournisseur);
QString nom = ui->recherche_fournisseur->text();
c.recherche(ui->tableView_fournisseur,nom);
if (ui->recherche_fournisseur->text().isEmpty())
{
    ui->tableView_fournisseur->setModel(c.afficher());
}
}
