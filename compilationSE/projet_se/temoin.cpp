#include "temoin.h"
#include <QDebug>

Temoin::Temoin(QObject *parent):QObject(parent)
{
    // vide
}


void Temoin::emission_redacteur(int numero,Etat_redacteur etat,int alea)
{
    emit situation_redacteur(numero,etat,alea);
}


void Temoin::emission_lecteur(int numero,Etat_lecteur etat,int alea)
{
    emit situation_lecteur(numero,etat,alea);
}
