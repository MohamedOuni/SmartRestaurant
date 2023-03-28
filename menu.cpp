#include "menu.h"
#include "commande.h"
#include "menu_impl.h"
#include "commande_impl.h"
#include <QMessageBox>
#include <QMediaPlayer>
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "gestion_reservation.h"
#include "reservation.h"
#include "table.h"

#include<QIntValidator>
/*Menu::Menu(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Menu)
{
    ui->setupUi(this);
    Menu_Impl cat ;
    Commande_Impl com ;
     ui->txt_Prix->setValidator(new QIntValidator(0,999999,this));
  //  com.cleartable(ui->tableView2);
    com.platsstatut(ui->tableView2);
  //  ui->tableView2->setModel(com.afficher());
    ui->tableView->setModel(cat.afficher());
    ui->tableView3->setModel(com.affichercommande());
}

Menu::~Menu()
{
    delete ui;
}
*/
void MainWindow::on_Ajouter_menu_clicked()
{ float prixcheck;
    QString nom = ui->txt_Nom_menu->text();
    QString prix = ui->txt_Prix_menu->text();

    if(nom == "")
    {
        QMessageBox::critical(nullptr, QObject::tr("Probleme"),
                                       QObject::tr("Case obligatoire\nverifier le nom\n"), QMessageBox::Cancel);
    }
    if(prix == "")
    {
        QMessageBox::critical(nullptr, QObject::tr("Probleme"),
                                       QObject::tr("Case obligatoire\nverifier le prix\n"), QMessageBox::Cancel);
    }


    else
    {
        Menu_Impl cat ;
        cat.ajouter(nom,prix);
           ui->tableView_menu->setModel(cat.afficher());
           QMediaPlayer * music = new QMediaPlayer();
           music->setMedia(QUrl("qrc:/sounds/ajout.mp3"));
           music->play();
    }


}

void MainWindow::on_Supprimer_menu_clicked()
{
    Menu_Impl cat ;
    cat.supprimer()->removeRow(ui->tableView_menu->currentIndex().row());
      ui->tableView_menu->setModel(cat.afficher());
      QMediaPlayer * music = new QMediaPlayer();
      music->setMedia(QUrl("qrc:/sounds/supprime.mp3"));
      music->play();

}

void MainWindow::on_txt_Search_menu_textChanged(const QString &arg1)
{
    Menu_Impl c;

    c.cleartable(ui->tableView_menu);
QString nom = ui->txt_Search_menu->text();
c.recherche(ui->tableView_menu,nom);
if (ui->txt_Search_menu->text().isEmpty())
{
    ui->tableView_menu->setModel(c.afficher());
}
}
void MainWindow::on_Actualiser_menu_clicked()
{
    Commande_Impl com ;
    Menu_Impl men;
   com.cleartable(ui->tableView2_menu);
    com.platsstatut(ui->tableView2_menu);
    com.cleartable(ui->tableView3_commande);
     ui->tableView3_commande->setModel(com.affichercommande());
    men.cleartable(ui->tableView_menu);
      ui->tableView_menu->setModel(men.afficher());
}


void MainWindow::on_Trier_menu_clicked()
{
    Menu_Impl men;
    QSqlQueryModel *model= new QSqlQueryModel();
    QSqlQuery *query=new QSqlQuery;

    query->prepare("select * from MENU ORDER BY NOM ASC ;");
    query->exec();
    model->setQuery(*query);
     men.cleartable(ui->tableView_menu);
    ui->tableView_menu->setModel(model);
    ui->tableView_menu->show();


}


void MainWindow::on_Retour_menu_clicked()
{
    /*MainWindow *w = new MainWindow;
    hide();
    w->show();*/
    ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::on_Retour_2_commande_clicked()
{

ui->stackedWidget->setCurrentIndex(0);
}
