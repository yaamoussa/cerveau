#ifndef TEMOIN_H
#define TEMOIN_H

#include <QObject>
#include "etat.h"

class Temoin: public QObject
{
    Q_OBJECT
public:
    Temoin(QObject* parent = nullptr);
    void emission_redacteur(int numero,Etat_redacteur etat);
    void emission_lecteur(int numero,Etat_lecteur etat);

signals:
    void situation_redacteur(int numero,Etat_redacteur etat);
    void situation_lecteur(int numero,Etat_lecteur etat);
};

#endif // TEMOIN_H
