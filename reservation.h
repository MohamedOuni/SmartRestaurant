#ifndef RESERVATION_H
#define RESERVATION_H
#include "gestion_reservation.h"
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QtCore/qglobal.h>
#include "mainwindow.h"
#include "ui_mainwindow.h"

class reservation
{
public:
    reservation();

     reservation(int ID, QString NOM_CLIENT, QString NUM_TEL, QString TABLE_NUM, int NOMBRE_PERSONNES);
    reservation(QString NOM_CLIENT, QString NUM_TEL, QString TABLE_NUM, int NOMBRE_PERSONNES);
    bool ajouter();
    void afficher(Ui::MainWindow *ui);
    bool Supprimer(Ui::MainWindow *ui);
    bool modifier(Ui::MainWindow *ui);
    void tables(Ui::MainWindow *ui);
    void Recherche(Ui::MainWindow *ui);
    int NOMBRE_TABLES();
    int NOMBRE_RESERVATION();
    void GRAPH(Ui::MainWindow *ui);
    int getID();
    void setID(int &value);
    QString getNOM_CLIENT();
    void setNOM_CLIENT(QString &value);
    QString getTABLE_NUM();
    void setTABLE_NUM(QString &value);
    QString getNUM_TEL();
    void setNUM_TEL(QString &value);
    int getNOMBRE_PERSONNES();
    void setNOMBRE_PERSONNES(int &value);

private:
    QString TABLE_NUM,NOM_CLIENT;
    int ID,NOMBRE_PERSONNES;
    QString NUM_TEL;
};

#endif // RESERVATION_H
