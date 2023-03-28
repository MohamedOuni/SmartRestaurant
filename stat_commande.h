#ifndef STAT_COMMANDE_H
#define STAT_COMMANDE_H


#include <QDialog>
#include <iostream>
#include <QApplication>
#include <QMainWindow>
#include <QtCharts/QChartView>
#include <QtCharts/QBarSeries>
#include <QtCharts/QBarSet>
#include <QtCharts/QLegend>
#include <QtCharts/QBarCategoryAxis>
#include <QtCharts/QHorizontalStackedBarSeries>
#include <QtCharts/QLineSeries>
#include <QtCharts/QCategoryAxis>
#include <QtCharts/QPieSeries>
#include <QtCharts/QPieSlice>
#include <QPainter>
#include <QSqlQuery>


namespace Ui {
class stat_commande;
class QPieSlice;
}

class stat_commande : public QDialog
{
    Q_OBJECT

public:
    explicit stat_commande(QWidget *parent = nullptr);
    ~stat_commande();
    int Stat_partie2() ;
    int Stat_partie3() ;
    int Stat_partie4() ;
    void paintEvent(QPaintEvent *) ;

private:
    Ui::stat_commande *ui;
};

#endif // STAT_COMMANDE_H
