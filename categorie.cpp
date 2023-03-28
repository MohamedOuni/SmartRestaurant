#include "categorie.h"

#include "categorie_impl.h"
#include "mainwindow.h"
#include <QMessageBox>
#include <QMediaPlayer>
#include "mainwindow.h"
#include "ui_mainwindow.h"

/*Categorie::Categorie(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Categorie)
{
    ui->setupUi(this);
    Categorie_Impl cat ;
    ui->tableView->setModel(cat.afficher());
}

Categorie::~Categorie()
{
    delete ui;
}
*/
void MainWindow::on_Ajouter_categorie_clicked()
{
    QString nom = ui->txt_Nom_categorie->text();

    if(nom == "")
    {
        QMessageBox::critical(nullptr, QObject::tr("problem nom"),
                                       QObject::tr("verifier nom\n"
                                                   "Click Cancel to exit."), QMessageBox::Cancel);
    }
    else
    {
        Categorie_Impl cat ;
        cat.ajouter(nom);
           ui->tableView_categorie->setModel(cat.afficher());
           QMediaPlayer * music = new QMediaPlayer();
           music->setMedia(QUrl("qrc:/sounds/ajout.mp3"));
           music->play();
    }


}

void MainWindow::on_Supprimer_categorie_clicked()
{
    Categorie_Impl cat ;
    cat.supprimer()->removeRow(ui->tableView_categorie->currentIndex().row());
      ui->tableView_categorie->setModel(cat.afficher());
      QMediaPlayer * music = new QMediaPlayer();
      music->setMedia(QUrl("qrc:/sounds/supprime.mp3"));
      music->play();

}

void MainWindow::on_txt_Search_categorie_textChanged(const QString &arg1)
{
    Categorie_Impl c;

    c.cleartable(ui->tableView_categorie);
QString nom = ui->txt_Search_categorie->text();
c.recherche(ui->tableView_categorie,nom);
if (ui->txt_Search_categorie->text().isEmpty())
{
    ui->tableView_categorie->setModel(c.afficher());
}
}





void MainWindow::on_pushButton_categorie_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}
