#include "livreur.h"
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
livreur::livreur()
{
cin="";
tel="";
nom="";
disponibilite="";
}


livreur::livreur(QString cin,QString tel, QString nom, QString disponbilite)
{
    this->cin=cin; this->nom=nom;  this->tel=tel; this->disponibilite=disponbilite;
}
QString livreur::getcin(){return cin;}
QString livreur:: getnom(){return nom;}
QString livreur::gettel(){return tel;}
QString livreur:: getdisponibilite(){return disponibilite;}


void livreur::setcin(QString cin){this->cin=cin;}
void livreur::setnom(QString nom){this->nom=nom;}
void livreur::settel(QString tel){this->tel=tel;}
void livreur::setdisponibilite(QString disponibilite){this->disponibilite=disponibilite;}


bool livreur::ajouter(){

    QSqlQuery query;

    query.prepare("INSERT INTO LIVREUR (CIN, NOM,  TEL, DISPONIBILITE) "
                  "VALUES (:CIN, :NOM, :TEL, :DISPONIBILITE)");
    query.bindValue(0, cin);
    query.bindValue(1, nom);
    query.bindValue(2, tel);
    query.bindValue(3, disponibilite);



    return query.exec();

}

QSqlTableModel * livreur::afficher()
{
   QSqlTableModel *mmodel = new QSqlTableModel();
    mmodel->setTable("livreur");
    mmodel->select();
    return mmodel;

}

bool livreur::supprimer(QString cin)
{

        QSqlQuery query;
             query.prepare(" Delete from livreur where cin=:cin");
             query.bindValue(":cin", cin);

            return query.exec();


}

bool livreur::modifier(){


            QSqlQuery query ;

            query.prepare("update livreur set cin=:cin,nom=:nom, tel=:tel, disponibilite=:disponibilite where cin=:cin");

            query.bindValue(":cin", cin);
            query.bindValue(":nom", nom);
            query.bindValue(":tel", tel);
            query.bindValue(":disponibilite", disponibilite);
            return query.exec();

        }

void livreur :: recherche(QTableView * table ,QString nom )
{
    QSqlQueryModel *model= new QSqlQueryModel();

    QSqlQuery *query=new QSqlQuery;
    query->prepare("select * from livreur where NOM like '%"+nom+"%' or CIN like '%"+nom+"%' or disponibilite like '%"+nom+"%' ;");


    query->exec();
    model->setQuery(*query);
    table->setModel(model);
    table->show();

}
void livreur::cleartable(QTableView * table)
{
    QSqlQueryModel *model= new QSqlQueryModel();
    model->clear();
    table->setModel(model);
}
