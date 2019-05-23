#include "interfaceaccueil.h"
#include <iostream>

using namespace std;

InterfaceAccueil::InterfaceAccueil(QWidget *parent) : QWidget(parent)
{
    box = new QHBoxLayout;
    label = new QLabel("Bienvenue sur notre application de calcul\n d'ordonnacement de processus!!!");
    label->setFont(QFont("Comic Sans MS",25,QFont::Bold,true));
    label->setAlignment(Qt::AlignCenter);
    box->addWidget(label);
    box->setAlignment(label,Qt::AlignCenter);
    label->setMargin(15);
    setLayout(box);
}

InterfaceAccueil::~InterfaceAccueil()
{
    cout << "Appel du destructeur de Interface_accueil" << endl;
}
