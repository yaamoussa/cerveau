#ifndef TEMOIN_H
#define TEMOIN_H

#include <QObject>
#include "etat.h"

class Temoin: public QObject
{
    Q_OBJECT
public:
    Temoin(QObject* parent = nullptr);
    void emission_redacteur(int numero,Etat_redacteur etat,int alea);
    void emission_lecteur(int numero,Etat_lecteur etat,int alea);

signals:
    void situation_redacteur(int numero,Etat_redacteur etat,int alea);
    void situation_lecteur(int numero,Etat_lecteur etat,int alea);
};

#endif // TEMOIN_H
