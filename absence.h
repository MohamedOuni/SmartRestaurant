#ifndef ABSENCE_H
#define ABSENCE_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include<QPainter>
#include<QPdfWriter>
#include<QSystemTrayIcon>
#include <QSqlTableModel>
#include <QDate>

class Absence
{
    QString nom,daate,motif;
    int id;

public:

    Absence(){};
    Absence(int,QString,QString,QString);


    bool ajouterAB();
    //QSqlQueryModel * afficher_tab();
    QSqlTableModel *afficher();
    bool modifierAB(int id,QString nom,QString motif ,QString daate);
    QSqlQueryModel * afficher_ID();
    bool supprimerAB(int);
    void telechargerPDF();
    QSqlQueryModel * triernom();
    QSqlQueryModel * triermotif();
    QSqlQueryModel * trierdate();
};

#endif // ABSENCE_H
