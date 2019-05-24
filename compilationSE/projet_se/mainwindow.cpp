#include "mainwindow.h"
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlDriver>
#include <QtSql/QSqlError>
#include <QtSql/QSqlQuery>
#include <QDebug>


MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent)
{
    priorite_egale = true;

    for (int i = 0; i < 3; i++)
    {
        redacteurs[i] = redacteur_debut;
        lecteurs[i] = lecteur_debut;
    }

    label_accueil = new QLabel("Bienvenue sur notre application");
    label_accueil->setFont(QFont("Comic Sans MS",17));

    bouton = new QPushButton("Changer pour priorite des lecteurs");

    bouton->setFixedHeight(65);

    conteneur_anime = new QVBoxLayout;
    zone_anime = new Animation(redacteurs,lecteurs,this);
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

    setMinimumHeight(800);
    setMinimumWidth(1200);

    setCentralWidget(w);

    init_db();

    gestionnaire = new GestionThreads(this);

    connect(gestionnaire,SIGNAL(signal_redacteur(int,Etat_redacteur)),this,SLOT(changer_animation(int,Etat_redacteur)),Qt::BlockingQueuedConnection);
    connect(gestionnaire,SIGNAL(signal_lecteur(int,Etat_lecteur)),this,SLOT(changer_animation(int,Etat_lecteur)),Qt::BlockingQueuedConnection);

    connect(bouton,SIGNAL(clicked()),gestionnaire,SLOT(redemarrer()));
    connect(bouton,SIGNAL(clicked()),this,SLOT(changer_texte()));
}


MainWindow::~MainWindow()
{

}


bool MainWindow::init_db()
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE","init");

    db.setDatabaseName("test.db");

    if (!db.open())
    {
        qDebug() << "Echec de l'ouverture de la base de donnees \n" << endl;

        return false;
    }
    else
        qDebug() << "Succes de l'ouverture de la base de donnees \n" << endl;

    QSqlDatabase::database().transaction();
    QSqlQuery requete(db);

    if (requete.exec("CREATE TABLE IF NOT EXISTS table_test"
    "(chiffre BIGINT NOT NULL);") == false)
    {
        qDebug() << "Echec de la creation de la table \n" << endl;
        db.close();

        return false;
    }
    else
        qDebug() << "Succes de la creation de la Table \n" << endl;

    QSqlDatabase::database().commit();

    db.close();

    return true;
}


void MainWindow::changer_animation(int numero,Etat_redacteur etat)
{
    qDebug() << "Haut";

    redacteurs[numero] = etat;

    disconnect(gestionnaire,SIGNAL(signal_redacteur(int,Etat_redacteur)),this,SLOT(changer_animation(int,Etat_redacteur)));
    disconnect(gestionnaire,SIGNAL(signal_lecteur(int,Etat_lecteur)),this,SLOT(changer_animation(int,Etat_lecteur)));

    delete zone_anime;

    zone_anime = new Animation(redacteurs,lecteurs,this);
    conteneur_anime->addWidget(zone_anime);

    connect(gestionnaire,SIGNAL(signal_redacteur(int,Etat_redacteur)),this,SLOT(changer_animation(int,Etat_redacteur)),Qt::BlockingQueuedConnection);
    connect(gestionnaire,SIGNAL(signal_lecteur(int,Etat_lecteur)),this,SLOT(changer_animation(int,Etat_lecteur)),Qt::BlockingQueuedConnection);
}


void MainWindow::changer_animation(int numero,Etat_lecteur etat)
{
    qDebug() << "top";

    lecteurs[numero] = etat;

    delete zone_anime;

    zone_anime = new Animation(redacteurs,lecteurs,this);
    conteneur_anime->addWidget(zone_anime);
}

void MainWindow::changer_texte()
{
    if (priorite_egale) {
        priorite_egale = false;
        bouton->setText("Changer pour priorites egales");
    }
    else
    {
        priorite_egale = true;
        bouton->setText("Changer pour priorite des lecteurs");
    }
}
