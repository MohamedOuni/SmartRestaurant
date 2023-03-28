#include "categorie_impl.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QSqlQuery>
#include <QSqlTableModel>
#include <QDate>
#include <QTableView>
Categorie_Impl::Categorie_Impl()
{
 this->nom = "";
}

Categorie_Impl::Categorie_Impl(QString nom )
{
    this->nom = nom;

}

QStringList Categorie_Impl::getNames(){
    QStringList list;
    QSqlQuery qry;
                qry.prepare("SELECT * FROM CATEGORIE ");

                if (qry.exec())
                {
                    while (qry.next())
                    {
                        list.append(qry.value(1).toString());
                    }

                }

return list;

}


   bool Categorie_Impl::ajouter(QString nom)
   {
       QSqlQuery qry;
                   qry.prepare("INSERT INTO CATEGORIE ( NOM) "
                                       "VALUES (:NOM)");

           qry.bindValue(":NOM",nom);
           return qry.exec();
   }
   QSqlTableModel *Categorie_Impl::afficher()
   {
      QSqlTableModel *mmodel = new QSqlTableModel();
       mmodel->setTable("CATEGORIE");
       mmodel->select();
       return mmodel;

   }
    QSqlTableModel *Categorie_Impl::supprimer ()
   {
       QSqlTableModel *mmodel = new QSqlTableModel();
        mmodel->setTable("CATEGORIE");
        mmodel->select();
        return mmodel;

   }


    void Categorie_Impl :: recherche(QTableView * table ,QString nom )
    {
        QSqlQueryModel *model= new QSqlQueryModel();

        QSqlQuery *query=new QSqlQuery;
        query->prepare("select * from CATEGORIE where NOM like '%"+nom+"%' ;");


        query->exec();
        model->setQuery(*query);
        table->setModel(model);
        table->show();

    }
    void Categorie_Impl::cleartable(QTableView * table)
    {
        QSqlQueryModel *model= new QSqlQueryModel();
        model->clear();
        table->setModel(model);
    }
