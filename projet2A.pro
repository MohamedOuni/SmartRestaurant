QT       += core gui sql
QT       += core gui printsupport
QT       += core gui \
                      multimedia

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    absence.cpp \
    articles.cpp \
    articles_impl.cpp \
    categorie.cpp \
    categorie_impl.cpp \
    commande.cpp \
    commande_impl.cpp \
    connection.cpp \
    fournisseur.cpp \
    fournisseur_impl.cpp \
    gestion_livraison.cpp \
    gestion_personnel.cpp \
    gestion_reservation.cpp \
    gestion_table.cpp \
    livraison.cpp \
    livreur.cpp \
    login.cpp \
    main.cpp \
    mainwindow.cpp \
    menu.cpp \
    menu_impl.cpp \
    notifications.cpp \
    personnel.cpp \
    qcustomplot.cpp \
    reservation.cpp \
    stat_article.cpp \
    stat_commande.cpp \
    table.cpp

HEADERS += \
    absence.h \
    articles.h \
    articles_impl.h \
    categorie.h \
    categorie_impl.h \
    commande.h \
    commande_impl.h \
    connection.h \
    fournisseur.h \
    fournisseur_impl.h \
    gestion_livraison.h \
    gestion_personnel.h \
    gestion_reservation.h \
    gestion_table.h \
    livraison.h \
    livreur.h \
    login.h \
    mainwindow.h \
    menu.h \
    menu_impl.h \
    notifications.h \
    personnel.h \
    qcustomplot.h \
    reservation.h \
    stat_article.h \
    stat_commande.h \
    table.h

FORMS += \
    mainwindow.ui \
    stat_article.ui \
    stat_commande.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    Ressources.qrc \
    Ressources.qrc \
    images.qrc \
    rec.qrc \
    rec.qrc \
    res.qrc

DISTFILES += \
    ajout.mp3 \
    article.pdf \
    db.sql \
    download.png \
    images/pngtree-hamburger-background-with-meat-cheese-and-salad-flat-style-cartoon-illustration-image_307739.jpg \
    modifie.mp3 \
    projet2A.pro.user \
    projet2A.pro.user.0433cd8 \
    projet2A.pro.user.4e63e6f \
    projet2A.pro.user.94a3065 \
    supprime.mp3
