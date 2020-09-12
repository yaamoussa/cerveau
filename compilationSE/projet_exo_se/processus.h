#ifndef PROCESSUS_H
#define PROCESSUS_H

#include <QObject>

class Processus : public QObject
{
    Q_OBJECT
public:
    explicit Processus(unsigned int num,unsigned int instant_soum,unsigned int temps_ex,
                       unsigned int prior,QObject *parent = nullptr);

public slots:
    void reinitialiser(unsigned int num,unsigned int instant_soum,
                       unsigned int temps_ex,unsigned int prior);

private:
    unsigned int numero;
    unsigned int instant_soumission;
    unsigned int duree_execution;
    unsigned int priorite;
};

#endif // PROCESSUS_H
