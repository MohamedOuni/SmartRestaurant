#include "fournisseur_impl.h"
#include <QSqlQuery>
#include <QSqlTableModel>
#include <QDate>
#include <QTableView>

fournisseur_impl::fournisseur_impl()
{
    this->nom_f = "";
    this->categorie = "";
     this->tel = 0;
}

fournisseur_impl::fournisseur_impl(QString nom,QString categorie, int tel)
{
    this->nom_f = nom;
    this->categorie = categorie;
     this->tel = tel;
}
bool fournisseur_impl::ajouter(QString nom,QString categorie, int tel)
{
    QSqlQuery qry;
                qry.prepare("INSERT INTO FOURNISSEUR ( NOM_F,TEL,CATEGORIE) "
                                    "VALUES (:NOM_F,:TEL,:CATEGORIE)");


        qry.bindValue(":NOM_F",nom);
        qry.bindValue(":TEL",tel);
        qry.bindValue(":CATEGORIE",categorie);
        return qry.exec();
}
QSqlTableModel *fournisseur_impl::afficher()
{
   QSqlTableModel *mmodel = new QSqlTableModel();
    mmodel->setTable("FOURNISSEUR");
    mmodel->select();
    return mmodel;

}
 QSqlTableModel *fournisseur_impl::supprimer ()
{
    QSqlTableModel *mmodel = new QSqlTableModel();
     mmodel->setTable("FOURNISSEUR");
     mmodel->select();
     return mmodel;

}


 void fournisseur_impl :: recherche(QTableView * table ,QString nom)
 {
     QSqlQueryModel *model= new QSqlQueryModel();

     QSqlQuery *query=new QSqlQuery;
     query->prepare("select * from FOURNISSEUR where NOM_F like '%"+nom+"%'or ID like  '%"+nom+"%'or CATEGORIE like '%"+nom+"%';");


     query->exec();
     model->setQuery(*query);
     table->setModel(model);
     table->show();

 }
 void fournisseur_impl::cleartable(QTableView * table)
 {
     QSqlQueryModel *model= new QSqlQueryModel();
     model->clear();
     table->setModel(model);
 }

