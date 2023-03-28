#include "articles_impl.h"
#include "notifications.h"
#include <QMessageBox>
#include <QDebug>
#include<QPainter>
#include<QPdfWriter>
#include<QSystemTrayIcon>
#include "mainwindow.h"
#include "ui_mainwindow.h"
articles_impl::articles_impl()
{
this->nom = "";
 this->quantite = 0;

}

articles_impl::articles_impl(QString nom, int quantite)
{
this->nom = nom;
 this->quantite =quantite;

}


bool articles_impl::ajouter(QString nom, int quantite)
{
    QSqlQuery qry;
                qry.prepare("INSERT INTO ARTICLE ( NOM,QUANTITE) "
                                    "VALUES (:NOM,:QUANTITE)");


        qry.bindValue(":NOM",nom);
        qry.bindValue(":QUANTITE",quantite);
        return qry.exec();
}
QSqlTableModel *articles_impl::afficher()
{
   QSqlTableModel *mmodel = new QSqlTableModel();
    mmodel->setTable("ARTICLE");
    mmodel->select();
    return mmodel;

}
 QSqlTableModel *articles_impl::supprimer ()
{
    QSqlTableModel *mmodel = new QSqlTableModel();
     mmodel->setTable("ARTICLE");
     mmodel->select();
     return mmodel;

}


 void articles_impl :: recherche(QTableView * table ,QString nom )
 {
     QSqlQueryModel *model= new QSqlQueryModel();

     QSqlQuery *query=new QSqlQuery;
     query->prepare("select * from ARTICLE where NOM like '%"+nom+"%' ;");


     query->exec();
     model->setQuery(*query);
     table->setModel(model);
     table->show();

 }
 void articles_impl::cleartable(QTableView * table)
 {
     QSqlQueryModel *model= new QSqlQueryModel();
     model->clear();
     table->setModel(model);
 }
 void articles_impl::verifier()
 {
     QSqlQuery qry;

  if (qry.exec("select * from ARTICLE "))
  {

      int n=0;
      while (qry.next())
      {
          qDebug () <<n;


            n= qry.value(2).toInt();
            if(n<5)
            {  Notifications N;
                  N.notifications_quantite();
            }

      }

  }


 }

 void  articles_impl::telecharger(){

                          QPdfWriter pdf("C:\\Users\\USER\\Desktop\\qt\\article.pdf");
                          QPainter painter(&pdf);
                                                   int i = 4000;
                                                       painter.setPen(Qt::blue);
                                                       painter.setFont(QFont("Arial", 64));
                                                       painter.drawText(1100,1200,"article");
                                                       painter.setPen(Qt::black);
                                                       painter.setFont(QFont("Arial", 20));
                                                       painter.drawRect(100,100,7300,2600);
                                                       painter.drawRect(0,3000,9600,500);
                                                       painter.setFont(QFont("Arial", 15));
                                                       painter.drawText(200,3300,"ID");
                                                       painter.drawText(1300,3300,"Nom");
                                                       painter.drawText(6000,3300,"Quantite");

                                                       QSqlQuery query;
                                                       query.prepare("select * from ARTICLE");
                                                       query.exec();
                                                       while (query.next())
                                                                                {
                                                                                    painter.drawText(200,i,query.value(0).toString());
                                                                                    painter.drawText(1300,i,query.value(1).toString());
                                                                                    painter.drawText(6000,i,query.value(2).toString());

                                                                                    i = i + 500;
                                                                                }
                                                      }


