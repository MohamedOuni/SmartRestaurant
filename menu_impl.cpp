#include "menu_impl.h"
#include <QSqlQuery>
#include <QSqlTableModel>
#include <QDate>
#include <QTableView>
Menu_Impl::Menu_Impl()
    {
    this->nom = "";
    this->prix = "0";
    }

Menu_Impl::Menu_Impl(QString nom,QString prix )
    {
    this->nom = nom;
    this->prix =prix;

    }



bool Menu_Impl::ajouter(QString nom,QString prix)
   {
    QSqlQuery qry;
    qry.prepare("INSERT INTO MENU ( NOM,PRIX) "
                                       "VALUES (:NOM,:PRIX)");
    qry.bindValue(":NOM",nom);
    qry.bindValue(":PRIX",prix);
    return qry.exec();
   }
QSqlTableModel *Menu_Impl::afficher()
   {
      QSqlTableModel *mmodel = new QSqlTableModel();
       mmodel->setTable("MENU");
      // mmodel->setHeaderData(0,Qt::Horizontal,QObject::tr("ID"));
      // mmodel->setHeaderData(1,Qt::Horizontal,QObject::tr("NOM"));
      // mmodel->setHeaderData(2,Qt::Horizontal,QObject::tr("PRIX"));
       mmodel->select();
       return mmodel;

   }
QSqlTableModel *Menu_Impl::supprimer ()
   {
       QSqlTableModel *mmodel = new QSqlTableModel();
        mmodel->setTable("MENU");
        mmodel->select();
        return mmodel;

   }


void Menu_Impl :: recherche(QTableView * table ,QString rech )
    {
        QSqlQueryModel *model= new QSqlQueryModel();

        QSqlQuery *query=new QSqlQuery;
        query->prepare("select * from MENU where NOM like '%"+rech+"%' or ID like '%"+rech+"%' or PRIX like '%"+rech+"%' ;");
        query->exec();
        model->setQuery(*query);
        table->setModel(model);
        table->show();

    }
void Menu_Impl::cleartable(QTableView * table)
    {
        QSqlQueryModel *model= new QSqlQueryModel();
        model->clear();
        table->setModel(model);
    }
