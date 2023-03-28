#include "commande_impl.h"
#include <QSqlQuery>
#include <QSqlTableModel>
#include <QDate>
#include <QTableView>
Commande_Impl::Commande_Impl()
{
 this->plats = "";
    this->prix = "0";
}

Commande_Impl::Commande_Impl(QString plats,QString prix )
{
    this->plats = plats;
    this->prix =prix;

}
bool Commande_Impl::ajouter(QString plats,QString prix)
   {
       QSqlQuery qry;
       qry.prepare("INSERT INTO COMMANDE ( PLATS,PRIX,QUANTITE) "
                                       "VALUES (:PLATS,:PRIX,:QUANTITE)");

           qry.bindValue(":PLATS",plats);
           qry.bindValue(":PRIX",prix);
           return qry.exec();
   }
QSqlTableModel *Commande_Impl::affichercommande()
   {
      QSqlTableModel *mmodel = new QSqlTableModel();
       mmodel->setTable("COMMANDE");
      //mmodel->setHeaderData(0,Qt::Horizontal,QObject::tr("ID"));
      //mmodel->setHeaderData(1,Qt::Horizontal,QObject::tr("NOM"));
      //mmodel->setHeaderData(2,Qt::Horizontal,QObject::tr("PRIX"));
       mmodel->select();
       return mmodel;

   }
    QSqlTableModel *Commande_Impl::supprimer ()
   {
       QSqlTableModel *mmodel = new QSqlTableModel();
        mmodel->setTable("COMMANDE");
        mmodel->select();
        return mmodel;

   }

    void Commande_Impl :: platsstatut(QTableView * table  )
    {
        QSqlQueryModel *model= new QSqlQueryModel();

        QSqlQuery *query=new QSqlQuery;
        query->prepare("select * from MENU where QUANTITE > 0;");


        query->exec();
        model->setQuery(*query);
        table->setModel(model);
        table->show();

    }
    void Commande_Impl::cleartable(QTableView * table)
    {
        QSqlQueryModel *model= new QSqlQueryModel();
        model->clear();
        table->setModel(model);
    }

    void  Commande_Impl::telecharger(){

                         QPdfWriter pdf("C:\\Users\\mahdi\\Desktop\\Gestion Menu_commande\\Commande.pdf");
                         QPainter painter(&pdf);
                         int i = 4000;
                             painter.setPen(Qt::blue);
                             painter.setFont(QFont("Arial", 64));
                             painter.drawText(1100,1200,"Commande");
                             painter.setPen(Qt::black);
                             painter.setFont(QFont("Arial", 20));
                             painter.drawRect(100,100,7300,2600);
                             painter.drawRect(0,3000,9600,500);
                             painter.setFont(QFont("Arial", 15));
                             painter.drawText(200,3300,"ID");
                             painter.drawText(1300,3300,"Plats");
                             painter.drawText(6000,3300,"Prix");
                             painter.drawText(7500,3300,"Quantite");
                             QSqlQuery query;
                             query.prepare("select * from COMMANDE");
                             query.exec();
                             while (query.next())
                                                      {
                                                          painter.drawText(200,i,query.value(0).toString());
                                                          painter.drawText(1300,i,query.value(1).toString());
                                                          painter.drawText(6000,i,query.value(2).toString());
                                                          painter.drawText(7500,i,query.value(3).toString());
                                                          i = i + 500;
                                                      }
                            }
