#include "gestionthreads.h"
#include <QDebug>
#include <QTime>
#include <cstdlib>
#include <ctime>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlDriver>
#include <QtSql/QSqlError>
#include <QtSql/QSqlQuery>

static pthread_mutex_t mutex;
static sem_t db; // Accès à la db
static sem_t attente; // utilise seulement dans le cas des priorites egales
static int nbre_lecteurs = 0; // Nombre de lecteurs

int preparer_donnees(Proprietes p);
void ecrire_bd(Proprietes p,int valeur);
int lire_bd(Proprietes p);
bool init_db(); // cree ou ouvre la base de donnees Sqlite


GestionThreads::GestionThreads(QObject *parent) : QThread(parent)
{
   connect(this,SIGNAL(started()),this,SLOT(init()));
   connect(this,SIGNAL(finished()),this,SLOT(start()));

   init_db();
   start();
}


bool init_db()
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
    "(nombre_aleatoire BIGINT NOT NULL);") == false)
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


void GestionThreads::init()
{
    if ( priorites_egales) {
        sem_init(&db, NULL, 1);
        sem_init(&attente, NULL, 1);

        pthread_mutex_init(&mutex,NULL);

        // Creation des redacteurs

        for (int i = 0; i < 3; i++)
        {
            proprietes_red[i].numero = i;
            proprietes_red[i].temoin = new Temoin(this);
            pthread_create(&(redacteurs[i]),nullptr,redacteur1,&proprietes_red[i]);

            connect(proprietes_red[i].temoin,SIGNAL(situation_redacteur(int,Etat_redacteur,int)),this,SLOT(emission_redacteur(int,Etat_redacteur,int)),Qt::DirectConnection);

            proprietes_lect[i].numero = i;
            proprietes_lect[i].temoin = new Temoin(this);
            pthread_create(&(lecteurs[i]),nullptr,lecteur1,&proprietes_lect[i]);

            connect(proprietes_lect[i].temoin,SIGNAL(situation_lecteur(int,Etat_lecteur,int)),this,SLOT(emission_lecteur(int,Etat_lecteur,int)),Qt::DirectConnection);
        }
     }
     else
     {
        sem_init(&db, NULL, 1);

        pthread_mutex_init(&mutex,NULL);

        // Creation des redacteurs

        for (int i = 0; i < 3; i++)
        {
            proprietes_red[i].numero = i;
            proprietes_red[i].temoin = new Temoin(this);
            pthread_create(&(redacteurs[i]),nullptr,redacteur2,&proprietes_red[i]);

            connect(proprietes_red[i].temoin,SIGNAL(situation_redacteur(int,Etat_redacteur,int)),this,SLOT(emission_redacteur(int,Etat_redacteur,int)),Qt::DirectConnection);

            proprietes_lect[i].numero = i;
            proprietes_lect[i].temoin = new Temoin(this);
            pthread_create(&(lecteurs[i]),nullptr,lecteur2,&proprietes_lect[i]);

            connect(proprietes_lect[i].temoin,SIGNAL(situation_lecteur(int,Etat_lecteur,int)),this,SLOT(emission_lecteur(int,Etat_lecteur,int)),Qt::DirectConnection);
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
    if (priorites_egales)
        priorites_egales = false;
    else
        priorites_egales = true;

    this->exit(EXIT_SUCCESS);

    pthread_mutex_destroy(&mutex);
    sem_destroy(&db);
    sem_destroy(&attente);
}

void GestionThreads::emission_redacteur(int numero,Etat_redacteur etat,int alea)
{
    emit signal_redacteur(numero,etat,alea);
}


void GestionThreads::emission_lecteur(int numero,Etat_lecteur etat,int alea)
{
   emit signal_lecteur(numero,etat,alea);
}


void* GestionThreads::redacteur1(void *arg)
{
    Proprietes p = *(Proprietes*)(arg);
    QTime t;
    int n;

    while(true) {

        emit p.temoin->emission_redacteur(p.numero,redacteur_bloque,-1);

        sem_wait(&attente);

        t.start();

        while (t.elapsed() < 2500)
        {
            // vide
        }

        n = preparer_donnees(p);
        sem_wait(&db);
        sem_post(&attente);
        // section critique, un seul writer à la fois
        ecrire_bd(p,n);
        sem_post(&db);
    }
}


void* GestionThreads::lecteur1(void *arg)
{
    Proprietes p = *(Proprietes*)(arg);
    QTime t;

    while(true) {
        sem_wait(&attente);

        p.temoin->emission_lecteur(p.numero,lecteur_bloque,-1);
        t.start();

        while (t.elapsed() < 2500)
        {
            // vide
        }

        pthread_mutex_lock(&mutex);
        // section critique
        nbre_lecteurs++;

        if (nbre_lecteurs == 1)
        {
            // arrivée du premier reader
            sem_wait(&db);
        }

        emit p.temoin->emission_lecteur(p.numero,lecteur_pret,-1);

        t.start();

        while (t.elapsed() < 2500)
        {
            // vide
        }

        pthread_mutex_unlock(&mutex);
        sem_post(&attente);

        int n = lire_bd(p);
        pthread_mutex_lock(&mutex);
        // section critique
        nbre_lecteurs--;

        if(nbre_lecteurs == 0) {
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
    int n;

    while(true) {

        emit p.temoin->emission_redacteur(p.numero,redacteur_bloque,-1);

        t.start();

        while (t.elapsed() < 2500)
        {
            // vide
        }

        n = preparer_donnees(p);
        sem_wait(&db);
        // section critique, un seul writer à la fois
        ecrire_bd(p,n);
        sem_post(&db);
    }
}


void* GestionThreads::lecteur2(void *arg)
{
    Proprietes p = *(Proprietes*)(arg);
    QTime t;
    int n;

    while(true) {
        p.temoin->emission_lecteur(p.numero,lecteur_bloque,-1);
        t.start();

        while (t.elapsed() < 2500)
        {
            // vide
        }

        pthread_mutex_lock(&mutex);
        // section critique
        nbre_lecteurs++;

        if (nbre_lecteurs == 1)
        {
            // arrivée du premier reader
            sem_wait(&db);
        }

        emit p.temoin->emission_lecteur(p.numero,lecteur_pret,-1);

        t.start();

        while (t.elapsed() < 2500)
        {
            // vide
        }

        pthread_mutex_unlock(&mutex);

        n = lire_bd(p);
        pthread_mutex_lock(&mutex);
        // section critique
        nbre_lecteurs--;

        if(nbre_lecteurs == 0) {
            // départ du dernier reader
            sem_post(&db);
        }

        pthread_mutex_unlock(&mutex);
        // process_data();
    }
}


int preparer_donnees(Proprietes p)
{
    int n = 0;
    QTime t;

    t.start();

    p.temoin->emission_redacteur(p.numero,redacteur_pret,-1);

    while (t.elapsed() < 2500)
    {
        // Vide
    }

    // On tente d'avoir un nom de connexion unique avec 3 nombres
    srand(time(NULL));
    n = rand() % 10000;

    return n;
}


void ecrire_bd(Proprietes p,int n)
{
    QTime t;

    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE","init");

    db.setDatabaseName("test.db");

    if (!db.open())
    {
        qDebug() << "Echec de l'ouverture de la base de donnees \n" << endl;
    }
    else
        qDebug() << "Succes de l'ouverture de la base de donnees \n" << endl;

    QSqlQuery query(db);

    query.exec("INSERT INTO table_test(nombre_aleatoire) VALUES (%)");
    query.addBindValue(n);

    db.close();

    t.start();

    p.temoin->emission_redacteur(p.numero,ecriture,n);

    while (t.elapsed() < 2500)
    {
        // Vide
    }
}


int lire_bd(Proprietes p)
{
    int n = 0;
    QTime t;

    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE","init");

    db.setDatabaseName("test.db");

    if (!db.open())
    {
        qDebug() << "Echec de l'ouverture de la base de donnees \n" << endl;

        return false;
    }
    else
        qDebug() << "Succes de l'ouverture de la base de donnees \n" << endl;

    QSqlQuery query(db);

    query.exec("SELECT * FROM table_test(nombre_aleatoire) ORDER BY nombre_aleatoire * random()");
    query.addBindValue(n);

    if (query.next())
    {
        n = query.value(0).toInt();
    }
    else
        n = -1;

    t.start();

    p.temoin->emission_lecteur(p.numero,lecture,n);

    while (t.elapsed() < 2500)
    {
        // Vide
    }

    return n;
}
