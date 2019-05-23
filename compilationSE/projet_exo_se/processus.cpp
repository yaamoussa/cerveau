#include "processus.h"

Processus::Processus(unsigned int num,unsigned int instant_soum,
                     unsigned int temps_ex,unsigned int prior,QObject *parent) : QObject(parent)
{
    numero = num;
    instant_soumission = instant_soum;
    duree_execution = temps_ex;
    priorite = prior;
}

void Processus::reinitialiser(unsigned int num,unsigned int instant_soum,
                              unsigned int temps_ex,unsigned int prior)
{
    numero = num;
    instant_soumission = instant_soum;
    duree_execution = temps_ex;
    priorite = prior;
}
