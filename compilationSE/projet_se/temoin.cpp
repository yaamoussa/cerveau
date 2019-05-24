#include "temoin.h"
#include <QDebug>

Temoin::Temoin(QObject *parent):QObject(parent)
{

}


void Temoin::emission_redacteur(int numero,Etat_redacteur etat)
{
    qDebug() << "TRATRATRATRATARAT";

    emit situation_redacteur(numero,etat);
}


void Temoin::emission_lecteur(int numero,Etat_lecteur etat)
{
    emit situation_lecteur(numero,etat);
}
