#include "livraison.h"
#include <QSqlQuery>
#include <QtDebug>
#include <QObject>
#include <QTableView>
#include <QSqlTableModel>
#include <QDate>
#include <livraison.h>
#include <QMessageBox>
#include "mainwindow.h"
#include "ui_mainwindow.h"

livraison::livraison()
{
commande="";
tel="";
nom="";
region="";
ville="";
adresse="";

}


livraison::livraison(QString commande,QString tel, QString nom, QString region, QString adresse, QString ville)
{
    this->commande=commande; this->nom=nom;  this->tel=tel; this->region=region; this->ville=ville; this->adresse=adresse;
}
QString livraison::getcommande(){return commande;}
QString livraison:: getnom(){return nom;}
QString livraison::gettel(){return tel;}
QString livraison:: getregion(){return region;}
QString livraison:: getville(){return ville;}
QString livraison:: getadresse(){return adresse;}





void livraison::setcommande(QString commande){this->commande=commande;}
void livraison::setnom(QString nom){this->nom=nom;}
void livraison::settel(QString tel){this->tel=tel;}
void livraison::setregion(QString region){this->region=region;}
void livraison::setville(QString ville){this->ville=ville;}
void livraison::setadresse(QString adresse){this->adresse=adresse;}




bool livraison::ajouter(){

    QSqlQuery query;

    query.prepare("INSERT INTO livraison (commande, NOM,  TEL, region, ville, adresse) "
                  "VALUES (:commande, :NOM, :TEL, :region, :ville, :adresse)");
    query.bindValue(0, commande);
    query.bindValue(1, nom);
    query.bindValue(2, tel);
    query.bindValue(3, region);
    query.bindValue(4, ville);
    query.bindValue(5, adresse);




    return query.exec();

}

QSqlTableModel * livraison::afficher()
{
   QSqlTableModel *mmodel = new QSqlTableModel();
    mmodel->setTable("livraison");
    mmodel->select();
    return mmodel;

}

bool livraison::supprimer(QString commande)
{

        QSqlQuery query;
             query.prepare(" Delete from livraison where commande=:commande");
             query.bindValue(":commande", commande);

            return query.exec();


}

bool livraison::modifier(){


            QSqlQuery query ;

            query.prepare("update livraison set commande=:commande,nom=:nom, tel=:tel, region=:region,ville=:ville, adresse=:adresse where commande=:commande");

            query.bindValue(":commande", commande);
            query.bindValue(":nom", nom);
            query.bindValue(":tel", tel);
            query.bindValue(":region", region);
            query.bindValue(":ville", ville);
            query.bindValue(":adresse", adresse);

            return query.exec();

        }

void livraison :: recherche(QTableView * table ,QString nom )
{
    QSqlQueryModel *model= new QSqlQueryModel();

    QSqlQuery *query=new QSqlQuery;
    query->prepare("select * from livraison where NOM like '%"+nom+"%' or commande like '%"+nom+"%' or region like '%"+nom+"%' or commande like '%"+ville+"%' or commande like '%"+adresse+"%' ;");


    query->exec();
    model->setQuery(*query);
    table->setModel(model);
    table->show();

}
void livraison::cleartable(QTableView * table)
{
    QSqlQueryModel *model= new QSqlQueryModel();
    model->clear();
    table->setModel(model);
}
