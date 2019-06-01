#include "mainwindow.h"
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlDriver>
#include <QtSql/QSqlError>
#include <QtSql/QSqlQuery>
#include <QDebug>


MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent)
{
    priorites_egales = true;

    for (int i = 0; i < 3; i++)
    {
        redacteurs[i] = redacteur_bloque;
        lecteurs[i] = lecteur_bloque;
    }

    label_accueil = new QLabel("Bienvenue sur notre application");
    label_accueil->setFont(QFont("Comic Sans MS",17));

    bouton = new QPushButton("Changer pour priorite des lecteurs");

    bouton->setFixedHeight(65);

    conteneur_anime = new QVBoxLayout;
    zone_anime = new Animation(redacteurs,lecteurs,true,-1,this);
    conteneur_anime->addWidget(zone_anime);

    vbox = new QVBoxLayout;

    vbox->addWidget(label_accueil);
    vbox->setAlignment(label_accueil,Qt::AlignCenter);
    vbox->addWidget(bouton);
    vbox->setAlignment(bouton,Qt::AlignCenter);
    vbox->addLayout(conteneur_anime);
    vbox->setSpacing(35);
    vbox->setContentsMargins(80,80,80,80);
    vbox->setAlignment(Qt::AlignHCenter);

    w = new QWidget(this);
    w->setLayout(vbox);

    setMinimumHeight(700);
    setMinimumWidth(1200);

    setCentralWidget(w);

    gestionnaire = new GestionThreads(this);

    connect(gestionnaire,SIGNAL(signal_redacteur(int,Etat_redacteur,int)),this,SLOT(changer_animation(int,Etat_redacteur,int)),Qt::BlockingQueuedConnection);
    connect(gestionnaire,SIGNAL(signal_lecteur(int,Etat_lecteur,int)),this,SLOT(changer_animation(int,Etat_lecteur,int)),Qt::BlockingQueuedConnection);

    connect(bouton,SIGNAL(clicked()),gestionnaire,SLOT(redemarrer()));
    connect(bouton,SIGNAL(clicked()),this,SLOT(changer_texte()));
}


MainWindow::~MainWindow()
{

}



void MainWindow::changer_animation(int numero,Etat_redacteur etat,int alea)
{
    redacteurs[numero] = etat;

    if (etat == ecriture)
    {
        for (int i = 0; i < 3; i++)
        {
            if (i != numero && redacteurs[i] == ecriture)
                redacteurs[i] = redacteur_bloque;

            if (lecteurs[i] == lecture)
                lecteurs[i] = lecteur_bloque;
        }
    }

    disconnect(gestionnaire,SIGNAL(signal_redacteur(int,Etat_redacteur,int)),this,SLOT(changer_animation(int,Etat_redacteur,int)));
    disconnect(gestionnaire,SIGNAL(signal_lecteur(int,Etat_lecteur,int)),this,SLOT(changer_animation(int,Etat_lecteur,int)));

    delete zone_anime;

    zone_anime = new Animation(redacteurs,lecteurs,priorites_egales,alea,this);
    conteneur_anime->addWidget(zone_anime);

    connect(gestionnaire,SIGNAL(signal_redacteur(int,Etat_redacteur,int)),this,SLOT(changer_animation(int,Etat_redacteur,int)),Qt::BlockingQueuedConnection);
    connect(gestionnaire,SIGNAL(signal_lecteur(int,Etat_lecteur,int)),this,SLOT(changer_animation(int,Etat_lecteur,int)),Qt::BlockingQueuedConnection);
}


void MainWindow::changer_animation(int numero,Etat_lecteur etat,int alea)
{
    lecteurs[numero] = etat;

    if (etat == lecture)
    {
        for (int i = 0; i < 3; i++)
        {
            if (redacteurs[i] == ecriture)
                redacteurs[i] = redacteur_bloque;

            if (i != numero && lecteurs[i] == lecture)
                lecteurs[i] = lecteur_bloque;
        }
    }

    delete zone_anime;

    zone_anime = new Animation(redacteurs,lecteurs,priorites_egales,alea,this);
    conteneur_anime->addWidget(zone_anime);
}

void MainWindow::changer_texte()
{
    if (priorites_egales) {
        priorites_egales = false;
        bouton->setText("Changer pour priorites egales");
    }
    else
    {
        priorites_egales = true;
        bouton->setText("Changer pour priorite des lecteurs");
    }
}
