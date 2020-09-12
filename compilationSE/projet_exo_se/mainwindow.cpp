#include "mainwindow.h"
#include <QMenuBar>
#include <QGroupBox>
#include <QAction>
#include <QStatusBar>
#include <QMessageBox>
#include <iostream>

using namespace std;

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent)
{
    setMinimumHeight(800);
    setMinimumWidth(1500);
    setWindowTitle(tr("Exo_SE"));

    algo_actuel = FIFO;
    apropos_existe = false;
    accueuil_existe = false;

    for (int i = 0; i < 5; i++)
    {
        tableau_processus[i] = new Processus(0,0,0,0,this);

        if (tableau_processus[i] == nullptr)
        {
            cout << "Echec de l'allocation dynamique" << endl;

            exit(EXIT_FAILURE);
        }
    }

    // CREATION DU MENU

    menuBar()->setMinimumHeight(35);
    menuBar()->setContentsMargins(10,10,10,10);

    action_accueil = new QAction("Accueil",menuBar());
    menuBar()->addAction(action_accueil);

    menuFichier = new QMenu("Fichier",menuBar());

    action_ouvrir = new QAction("Ouvrir",menuFichier);
    action_quitter = new QAction("Quitter",menuFichier);

    menuFichier->addAction(action_ouvrir);
    menuFichier->addAction(action_quitter);

    menuBar()->addMenu(menuFichier);

    menuAlgoOrdonnancement = new QMenu("Algo. d'ordonnancement",menuBar());

    algo_fifo = new QRadioButton("FIFO",menuBar());
    algo_tourniquet = new QRadioButton("Tourniquet",menuBar());
    algo_pcte = new QRadioButton("PCTE",menuBar());
    algo_pcter = new QRadioButton("PCTER",menuBar());
    algo_pgp = new QRadioButton("Plus grande priorite",menuBar());

    conteneur_algo = new QVBoxLayout(menuBar());

    conteneur_algo->addWidget(algo_fifo);
    conteneur_algo->addWidget(algo_tourniquet);
    conteneur_algo->addWidget(algo_pcte);
    conteneur_algo->addWidget(algo_pcter);
    conteneur_algo->addWidget(algo_pgp);

    algo_fifo->setChecked(true);

    menuAlgoOrdonnancement->setLayout(conteneur_algo);

    menuBar()->addMenu(menuAlgoOrdonnancement);

    menuTableau = new QMenu("Tableau recapitulatif",menuBar());

    action_afficher = new QAction("Afficher",menuTableau);

    menuTableau->addAction(action_afficher);

    menuBar()->addMenu(menuTableau);

    action_apropos = new QAction("A propos",menuBar());

    menuBar()->addAction(action_apropos);

    connect(action_accueil,SIGNAL(triggered()),this,SLOT(creer_accueil()));
    connect(action_apropos,SIGNAL(triggered()),this,SLOT(creer_apropos()));
    connect(action_ouvrir,SIGNAL(triggered()),this,SLOT(creer_saisie()));
    connect(action_quitter,SIGNAL(triggered()),this,SLOT(quit()));

    creer_accueil();
}


void MainWindow::creer_accueil()
{
    if (accueuil_existe)
        page_accueil->show();

    page_accueil = new InterfaceAccueil(this);

    setCentralWidget(page_accueil);
}


void MainWindow::creer_apropos()
{
    if (apropos_existe)
        apropos->show();

    apropos = new Apropos(this);

    setCentralWidget(apropos);

    apropos_existe = true;
}


void MainWindow::creer_saisie()
{
    page_saisie = new PageSaisie(this);

    this->setCentralWidget(page_saisie);
}


MainWindow::~MainWindow()
{
    // ???????
}
