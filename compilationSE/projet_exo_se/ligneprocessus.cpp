#include "ligneprocessus.h"

LigneProcessus::LigneProcessus(QWidget *parent) : QWidget(parent)
{
    ligne = new QHBoxLayout(this);

    numero = new QLineEdit;
    date = new QLineEdit;
    duree = new QLineEdit;
    priorite = new QLineEdit;

    numero->setFixedSize(QSize(100,30));
    date->setFixedSize(QSize(100,30));
    duree->setFixedSize(QSize(100,30));
    priorite->setFixedSize(QSize(100,30));

    numero->setInputMask("9");
    date->setInputMask("999");
    duree->setInputMask("999");
    priorite->setInputMask("9");

    ligne->addWidget(numero,Qt::AlignLeft);
    ligne->addWidget(date,Qt::AlignCenter);
    ligne->addWidget(duree,Qt::AlignRight);
    ligne->addWidget(priorite,Qt::AlignRight);
    ligne->setMargin(0);

    this->setLayout(ligne);
}
