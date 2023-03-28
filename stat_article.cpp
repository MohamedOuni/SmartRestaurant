#include "stat_article.h"
#include "ui_stat_article.h"

stat_article::stat_article(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::stat_article)
{
    ui->setupUi(this);
}

stat_article::~stat_article()
{
    delete ui;
}
int stat_article::Stat_article_partie2()
{
    QSqlQuery query;
    int count=0 ;
    QSqlQuery requete("select * from ARTICLE where QUANTITE BETWEEN '1' AND '2' ") ;
    while(requete.next())
    {
            count++ ;
    }

return count ;

}
int stat_article::Stat_article_partie3()
{
    QSqlQuery query;
    int count=0 ;
    QSqlQuery requete("select * from ARTICLE where QUANTITE BETWEEN '3' AND '4'") ;
    while(requete.next())
    {
            count++ ;
    }

return count ;

}
int stat_article::Stat_article_partie4()
{
    QSqlQuery query;
    int count=0 ;
    QSqlQuery requete("select * from ARTICLE where QUANTITE BETWEEN '4' AND '9999'") ;
    while(requete.next())
    {
            count++ ;
    }

return count ;


}
void stat_article::paintEvent(QPaintEvent *)
{

    int b=Stat_article_partie2();
    //cout<<b<<endl ;
    int c=Stat_article_partie3();
   // cout<<c<<endl ;
    int d=Stat_article_partie4();
    //cout<<d<<endl ;

        float s2= b*100 ;
        float s3=c*100;
        float nb = b+c+d ;
        float q2 ;
        q2 = s2/nb ;
        float q3;
        q3=s3/nb;
        float y  ;
        y = (q2*360)/100 ;
        float m;
        m= (q3*360)/100;
        float z  ;
        z=360-(y+m) ;
    QPainter painter(this);
    QRectF size=QRectF(50,50,this->width()-500,this->width()-500);

    painter.setBrush(Qt::blue);
    painter.drawPie(size,0,16*y);
    ui->label_2->setText("entre 1 et 2") ;
    painter.setBrush(Qt::green);
    painter.drawPie(size,16*y,16*m);
    ui->label_3->setText("entre 3 et 4") ;
    painter.setBrush(Qt::red);
    painter.drawPie(size,16*(m+y),16*z);
    ui->label_4->setText("plus que 4") ;

}
