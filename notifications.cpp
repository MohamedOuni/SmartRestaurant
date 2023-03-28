#include "notifications.h"
#include <QSystemTrayIcon>
#include<QString>
#include "mainwindow.h"
#include "ui_mainwindow.h"
Notifications::Notifications()
{

}

void Notifications::notifications_quantite()
{

    QSystemTrayIcon *notifyIcon = new QSystemTrayIcon;

    notifyIcon->setIcon(QIcon(":/new/prefix1/download.png"));
    notifyIcon->show();
    notifyIcon->showMessage("Gestion des article ","article presque fini ",QSystemTrayIcon::Information,15000);
}
