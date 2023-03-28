#ifndef STAT_ARTICLE_H
#define STAT_ARTICLE_H

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
class stat_article;
class QPieSlice;
}

class stat_article : public QDialog
{
    Q_OBJECT

public:
    explicit stat_article(QWidget *parent = nullptr);
    ~stat_article();
    int Stat_article_partie2() ;
    int Stat_article_partie3() ;
    int Stat_article_partie4() ;
    void paintEvent(QPaintEvent *) ;

private:
    Ui::stat_article *ui;
};

#endif // STAT_ARTICLE_H
