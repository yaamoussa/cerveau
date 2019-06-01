#ifndef GESTIONTHREADS_H
#define GESTIONTHREADS_H

#include <QThread>
#include <QString>
#include <sys/types.h>
#include <sys/unistd.h>
#include <semaphore.h>
#include <pthread.h>
#include <cstdlib>
#include <ctime>
#include "temoin.h"
#include "etat.h"

struct Proprietes {
    int numero;
    Temoin *temoin;
};

class GestionThreads : public QThread
{
    Q_OBJECT
public:
    explicit GestionThreads(QObject *parent = nullptr);
    ~GestionThreads();

signals:
    void signal_redacteur(int numero,Etat_redacteur etat,int alea);
    void signal_lecteur(int numero,Etat_lecteur etat,int alea);

public slots:
    void emission_redacteur(int numero,Etat_redacteur etat,int alea);
    void emission_lecteur(int numero,Etat_lecteur etat,int alea);
    void init();
    void redemarrer();

private:
    pthread_t lecteurs[3];
    pthread_t redacteurs[3];

    Proprietes proprietes_lect[3];
    Proprietes proprietes_red[3];

    static void *redacteur1(void *arg); // priorite egale
    static void *lecteur1(void *arg); //priorite egale

    static void *redacteur2(void *arg); //priorite pour le lecteur
    static void *lecteur2(void *arg);//priorite pour le lecteur

    friend int preparer_donnees(Proprietes p);
    friend void ecrire_bd(Proprietes p,int valeur);
    friend int lire_bd(Proprietes p);

    bool priorites_egales = true;
};

#endif // GESTIONTHREADS_H
