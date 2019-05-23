#include "pagesaisie.h"

PageSaisie::PageSaisie(QWidget *parent) : QWidget(parent)
{
    conteneur = new QGridLayout;

    tableau = new QVBoxLayout;

    entete = new QHBoxLayout;

    lab_numero = new QLabel("Numero",this);
    lab_date = new QLabel("Date",this);
    lab_duree = new QLabel("Duree",this);
    lab_priorite = new QLabel("Priorite",this);

    entete->addWidget(lab_numero);
    entete->addWidget(lab_date);
    entete->addWidget(lab_duree);
    entete->addWidget(lab_priorite);

    tableau->addLayout(entete);

    for (int i = 0; i < 5; i++)
    {
        tab_lignes[i] = new LigneProcessus(this);
        tableau->addWidget(tab_lignes[i]);
    }

    conteneur->addLayout(tableau,2,2,Qt::AlignCenter);
    conteneur->setContentsMargins(70,70,70,70);

    this->setLayout(conteneur);
}
