#ifndef PAGESAISIE_H
#define PAGESAISIE_H

#include <QWidget>
#include <QGridLayout>
#include <QSpinBox>
#include <QVBoxLayout>
#include <QLabel>
#include "ligneprocessus.h"

class PageSaisie : public QWidget
{
    Q_OBJECT
public:
    explicit PageSaisie(QWidget *parent = nullptr);

signals:

public slots:

private:
    QHBoxLayout* entete;
    QGridLayout* conteneur;
    QVBoxLayout* tableau;
    QLabel* lab_numero;
    QLabel* lab_date;
    QLabel* lab_duree;
    QLabel* lab_priorite;
    LigneProcessus *tab_lignes[5];
};

#endif // PAGESAISIE_H
