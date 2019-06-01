#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLabel>
#include <QPushButton>
#include <QLineEdit>
#include "animation.h"
#include "gestionthreads.h"
#include "etat.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void changer_animation(int numero,Etat_redacteur etat,int alea);
    void changer_animation(int numero,Etat_lecteur etat,int alea);
    void changer_texte();

private:
    QWidget *w;
    QVBoxLayout *vbox;
    QHBoxLayout *hbox;
    QLabel *label_accueil;
    QLineEdit *champ;
    QLabel *label_champ;
    QPushButton *bouton;
    QVBoxLayout *conteneur_anime;
    Animation *zone_anime;
    Etat_lecteur lecteurs[3];
    Etat_redacteur redacteurs[3];
    GestionThreads* gestionnaire;

    bool priorites_egales;
};

#endif // MAINWINDOW_H
