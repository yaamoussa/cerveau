#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QAction>
#include <QStatusBar>
#include <QWidget>
#include <QVBoxLayout>
#include <QRadioButton>
#include <QVector>
#include "interfaceaccueil.h"
#include "apropos.h"
#include "processus.h"
#include "pagesaisie.h"

enum AlgoOrdonnancement {
    FIFO = 0,
    TOURNIQUET = 1,
    PCTE = 2,
    PCTER = 3,
    PLUS_GRANDE_PRIORITE = 4
};

class MainWindow : public QMainWindow
{
    Q_OBJECT

private slots:
    void creer_accueil();
    void creer_apropos();
    void creer_saisie();

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    QAction *action_accueil;
    QMenu *menuFichier;
    QMenu *menuAlgoOrdonnancement;
    QMenu *menuTableau;
    QAction *action_apropos;

    QAction *action_ouvrir;
    QAction *action_quitter;

    QVBoxLayout *conteneur_algo;
    QRadioButton *algo_fifo;
    QRadioButton *algo_tourniquet;
    QRadioButton *algo_pcte;
    QRadioButton *algo_pcter;
    QRadioButton *algo_pgp;

    QAction *action_afficher;

    InterfaceAccueil *page_accueil;
    PageSaisie *page_saisie;
    Apropos *apropos;

    Processus* tableau_processus[5]; // Tableau de 5 processus
    AlgoOrdonnancement algo_actuel = FIFO;

    bool apropos_existe;
    bool accueuil_existe;
};

#endif // MAINWINDOW_H
