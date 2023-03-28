#include "menu.h"
#include "menu_impl.h"
#include "commande_impl.h"
#include <QMessageBox>
#include <QMediaPlayer>
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "stat_commande.h"


void MainWindow::on_Supprimer2_commande_clicked()
{
    Commande_Impl cat ;
    cat.supprimer()->removeRow(ui->tableView3_commande->currentIndex().row());
      ui->tableView3_commande->setModel(cat.affichercommande());
      QMediaPlayer * music = new QMediaPlayer();
      music->setMedia(QUrl("qrc:/sounds/supprime.mp3"));
      music->play();

}
void MainWindow::on_Supprimer3_commande_clicked()
{
    Commande_Impl cat ;
    QSqlQuery qry;
    qry.prepare("DELETE FROM COMMANDE");

       qry.exec();
      ui->tableView3_commande->setModel(cat.affichercommande());
      QMediaPlayer * music = new QMediaPlayer();
      music->setMedia(QUrl("qrc:/sounds/supprime.mp3"));
      music->play();

}


void MainWindow::on_Valider_menu_clicked()
{
    QString nom,prix,plats,prixtotale;
    Commande_Impl com ;

    QSqlQuery *query=new QSqlQuery;
    query->prepare("INSERT INTO COMMANDE (PLATS,PRIX,QUANTITE) select NOM,PRIX,QUANTITE from MENU WHERE QUANTITE > 0 ;");
    query->exec();
    query->prepare("update MENU SET QUANTITE = 0 ;");
    query->exec();
    QMediaPlayer * music = new QMediaPlayer();
    music->setMedia(QUrl("qrc:/sounds/ajout.mp3"));
    music->play();

   // query->prepare("insert into COMMANDE (PLATS,PRIXTOTALE) select NOM,PRIX from MENU where QUANTITE > 0;");
   /*   query->bindValue(":NOM",nom);
    query->bindValue(":PRIX",prix);
    query->exec();
    plats=nom;
    prixtotale=prix;
    com.ajouter(plats,prixtotale);*/


  /*
  *
  *
  *  QString plats = ui->txt_Nom->text();
     QString prixtotale = ui->txt_Nom->text();
  if(plats == "")
    {
        QMessageBox::critical(nullptr, QObject::tr("Probleme"),
                                       QObject::tr("Case obligatoire\nverifier le nom\n"), QMessageBox::Cancel);
    }
    else
    {
        Commande_Impl cat ;
        cat.ajouter(plats,prixtotale);
           ui->tableView->setModel(cat.afficher());
    }
*/

}

void MainWindow::on_imprimer_commande_clicked()
{    Commande_Impl cat ;
  cat.telecharger();

    QMessageBox::information(nullptr,QObject::tr("OK"),
               QObject::tr("Téléchargement terminé"), QMessageBox::Cancel);



}
void MainWindow::on_statistique_commande_clicked()
{
    s=new stat_commande(this);
    s->show();
}



