#include "gestionthreads.h"
#include <QDebug>
#include <QTime>

static pthread_mutex_t mutex;
static sem_t db; // Accès à la db
static sem_t attente;
static int readcount = 0; // Nombre de readers

quint64 preparer_donnees(Proprietes p);
void ecrire_bd(Proprietes p);
quint64 lire_bd(Proprietes p);


GestionThreads::GestionThreads(QObject *parent) : QThread(parent)
{
   connect(this,SIGNAL(started()),this,SLOT(init()));
   connect(this,SIGNAL(finished()),this,SLOT(start()));

   start();
}


void GestionThreads::init()
{
    if ( priorite_egale) {
        sem_init(&db, NULL, 1);
        sem_init(&attente, NULL, 1);

        mutex = PTHREAD_DEFAULT_MUTEX_INITIALIZER;

        // Creation des redacteurs

        for (int i = 0; i < 3; i++)
        {
            proprietes_red[i].numero = i;
            proprietes_red[i].temoin = new Temoin(this);
            pthread_create(&(redacteurs[i]),nullptr,redacteur1,&proprietes_red[i]);

            connect(proprietes_red[i].temoin,SIGNAL(situation_redacteur(int,Etat_redacteur)),this,SLOT(emission_redacteur(int,Etat_redacteur)),Qt::DirectConnection);

            proprietes_lect[i].numero = i;
            proprietes_lect[i].temoin = new Temoin(this);
            pthread_create(&(lecteurs[i]),nullptr,lecteur1,&proprietes_lect[i]);

            connect(proprietes_lect[i].temoin,SIGNAL(situation_lecteur(int,Etat_lecteur)),this,SLOT(emission_lecteur(int,Etat_lecteur)),Qt::DirectConnection);
        }
     }
     else
     {
        sem_init(&db, NULL, 1);
        sem_init(&attente, NULL, 1);

        mutex = PTHREAD_DEFAULT_MUTEX_INITIALIZER;

        // Creation des redacteurs

        for (int i = 0; i < 3; i++)
        {
            proprietes_red[i].numero = i;
            proprietes_red[i].temoin = new Temoin(this);
            pthread_create(&(redacteurs[i]),nullptr,redacteur2,&proprietes_red[i]);

            connect(proprietes_red[i].temoin,SIGNAL(situation_redacteur(int,Etat_redacteur)),this,SLOT(emission_redacteur(int,Etat_redacteur)),Qt::DirectConnection);

            proprietes_lect[i].numero = i;
            proprietes_lect[i].temoin = new Temoin(this);
            pthread_create(&(lecteurs[i]),nullptr,lecteur2,&proprietes_lect[i]);

            connect(proprietes_lect[i].temoin,SIGNAL(situation_lecteur(int,Etat_lecteur)),this,SLOT(emission_lecteur(int,Etat_lecteur)),Qt::DirectConnection);
        }
     }
}


GestionThreads::~GestionThreads()
{
    qDebug() << "Destruction du gestionnaire de Threads" << endl;
    pthread_mutex_destroy(&mutex);
    sem_destroy(&db);
    sem_destroy(&attente);
}


void GestionThreads::redemarrer()
{
    if (priorite_egale)
        priorite_egale = false;
    else
        priorite_egale = true;

    this->exit(EXIT_SUCCESS);

    sem_destroy(&db);
    sem_destroy(&attente);

    qDebug() << "Restart";
}

void GestionThreads::emission_redacteur(int numero,Etat_redacteur etat)
{
    emit signal_redacteur(numero,etat);
}


void GestionThreads::emission_lecteur(int numero,Etat_lecteur etat)
{
   emit signal_lecteur(numero,etat);
}


void* GestionThreads::redacteur1(void *arg)
{
    Proprietes p = *(Proprietes*)(arg);
    QTime t;

    while(true) {

        emit p.temoin->emission_redacteur(p.numero,redacteur_debut);

        sem_wait(&attente);

        t.start();

        while (t.elapsed() < 2000)
        {
            // vide
        }

        qDebug() << "numero" << p.numero << endl;
        preparer_donnees(p);
        sem_wait(&db);
        sem_post(&attente);
        // section critique, un seul writer à la fois
        ecrire_bd(p);
        sem_post(&db);
    }
}


void* GestionThreads::lecteur1(void *arg)
{
    Proprietes p = *(Proprietes*)(arg);
    QTime t;

    while(true) {
        sem_wait(&attente);

        qDebug() << "numero" << p.numero << endl;

        p.temoin->emission_lecteur(p.numero,lecteur_debut);
        t.start();

        while (t.elapsed() < 2000)
        {
            // vide
        }

        pthread_mutex_lock(&mutex);
        // section critique
        readcount++;

        if (readcount == 1)
        {
            // arrivée du premier reader
            sem_wait(&db);
        }

        emit p.temoin->emission_lecteur(p.numero,lecteur_pret);

        t.start();

        while (t.elapsed() < 1500)
        {
            // vide
        }

        pthread_mutex_unlock(&mutex);
        sem_post(&attente);

        lire_bd(p);
        pthread_mutex_lock(&mutex);
        // section critique
        readcount--;

        if(readcount == 0) {
            // départ du dernier reader
            sem_post(&db);
        }

        pthread_mutex_unlock(&mutex);
        // process_data();
    }
}


void* GestionThreads::redacteur2(void *arg)
{
    Proprietes p = *(Proprietes*)(arg);
    QTime t;

    while(true) {

        emit p.temoin->emission_redacteur(p.numero,redacteur_debut);

        t.start();

        while (t.elapsed() < 2000)
        {
            // vide
        }

        qDebug() << "numero" << p.numero << endl;
        preparer_donnees(p);
        sem_wait(&db);
        // section critique, un seul writer à la fois
        ecrire_bd(p);
        sem_post(&db);
    }
}


void* GestionThreads::lecteur2(void *arg)
{
    Proprietes p = *(Proprietes*)(arg);
    QTime t;

    while(true) {
       qDebug() << "numero" << p.numero << endl;

        p.temoin->emission_lecteur(p.numero,lecteur_debut);
        t.start();

        while (t.elapsed() < 2000)
        {
            // vide
        }

        pthread_mutex_lock(&mutex);
        // section critique
        readcount++;

        if (readcount == 1)
        {
            // arrivée du premier reader
            sem_wait(&db);
        }

        emit p.temoin->emission_lecteur(p.numero,lecteur_pret);

        t.start();

        while (t.elapsed() < 1500)
        {
            // vide
        }

        pthread_mutex_unlock(&mutex);

        lire_bd(p);
        pthread_mutex_lock(&mutex);
        // section critique
        readcount--;

        if(readcount == 0) {
            // départ du dernier reader
            sem_post(&db);
        }

        pthread_mutex_unlock(&mutex);
        // process_data();
    }
}


quint64 preparer_donnees(Proprietes p)
{
    qDebug() << "Thread redacteur " << pthread_self() << ": preparation des donnees" << endl;

    quint64 n = 0;
    QTime t;

    t.start();

    p.temoin->emission_redacteur(p.numero,redacteur_pret);

    while (t.elapsed() < 3000)
    {
        // Vide
    }

    return n;
}


void ecrire_bd(Proprietes p)
{
    qDebug() << "Thread redacteur " << pthread_self() << ": ecriture dans bd" << endl;

    QTime t;
    t.start();

    p.temoin->emission_redacteur(p.numero,ecriture);

    while (t.elapsed() < 3000)
    {
        // Vide
    }
}


quint64 lire_bd(Proprietes p)
{
    qDebug() << "Thread " << pthread_self() << ": lecture dans bd" << endl;

    quint64 n = 0;
    QTime t;

    t.start();

    p.temoin->emission_lecteur(p.numero,lecture);

    while (t.elapsed() < 3000)
    {
        // Vide
    }

    return n;
}
