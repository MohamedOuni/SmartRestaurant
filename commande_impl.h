#ifndef COMMANDE_IMPL_H
#define COMMANDE_IMPL_H
#include <QSqlQuery>
#include <QSqlTableModel>
#include <QDate>
#include <QTableView>
#include<QPainter>
#include<QPdfWriter>
#include<QSystemTrayIcon>
class Commande_Impl
{

   QString plats ;
   QString prix;
   int quantite;
public:
   //Constructeurs
      Commande_Impl();
      Commande_Impl(QString,QString);

   //Getters
      QString getPlats() {return plats;}
      QString getPrix(){return prix;}

   //setters
      void setPlats(QString plats){this->plats=plats;}
       void setPrix(QString p){this->prix=p;}
      bool ajouter(QString,QString);
      QSqlTableModel *supprimer();
      QSqlTableModel* affichercommande();
      void cleartable(QTableView * table);
      void platsstatut(QTableView * tabl);
         void  telecharger();
};
#endif // COMMANDE_IMPL_H
