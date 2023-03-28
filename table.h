#ifndef TABLE_H
#define TABLE_H
#include "gestion_table.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QtCore/qglobal.h>

class table
{
public:
    table();
    table(QString num_table, int nombre_places);

    QString getNum_table();
    void setNum_table(QString &value);
    int getNombre_places();
    void setNombre_places(int &value);
    bool ajouter();
    void afficher(Ui::MainWindow *ui);
    bool Supprimer(Ui::MainWindow *ui);
    bool modifier(Ui::MainWindow *ui);
    void afficher_vide(Ui::MainWindow *ui);
    void afficher_reserve(Ui::MainWindow *ui);

private:
 QString num_table;
 int nombre_places;
};

#endif // TABLE_H
