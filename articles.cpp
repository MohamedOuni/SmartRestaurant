#include "articles.h"
#include "articles_impl.h"
#include <QMessageBox>
#include <QMediaPlayer>
#include "mainwindow.h"
#include "ui_mainwindow.h"
/*articles::articles(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::articles)

{
    ui->setupUi(this);

    articles_impl art;
    ui->tableView->setModel(art.afficher());
    art.verifier();
}

articles::~articles()
{
    delete ui;
}
*/
void MainWindow::on_pushButton_article_clicked()
{

    QString nom = ui->txt_Nom_article->text();
    int quantite = ui->spinBox_article->text().toInt();


    if(nom == "")
    {
        QMessageBox::critical(nullptr, QObject::tr("problem nom"),
                                       QObject::tr("verifier nom\n"
                                                   "Click Cancel to exit."), QMessageBox::Cancel);
    }

else if (quantite<=0){
        QMessageBox::critical(nullptr, QObject::tr("problem quantite"),
                                       QObject::tr("verifier quantite\n"
                                                   "Click Cancel to exit."), QMessageBox::Cancel);
    }
    else
    {
        articles_impl art ;
        art.ajouter(nom,quantite);
           ui->tableView_article->setModel(art.afficher());

          art.verifier();
          QMediaPlayer * music = new QMediaPlayer();
          music->setMedia(QUrl("qrc:/sounds/ajout.mp3"));
          music->play();
    }

}

void MainWindow::on_pushButton_2_article_clicked()
{
    articles_impl art ;
    art.supprimer()->removeRow(ui->tableView_article->currentIndex().row());
      ui->tableView_article->setModel(art.afficher());
      QMediaPlayer * music = new QMediaPlayer();
      music->setMedia(QUrl("qrc:/sounds/supprime.mp3"));
      music->play();
}

void MainWindow::on_pushButton_3_article_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::on_imprimer_article_clicked()
{    articles_impl art ;
  art.telecharger();

    QMessageBox::information(nullptr,QObject::tr("OK"),
               QObject::tr("Téléchargement terminé"), QMessageBox::Cancel);



}
void MainWindow::on_statistique_article_clicked()
{
    a=new stat_article(this);
    a->show();
}

