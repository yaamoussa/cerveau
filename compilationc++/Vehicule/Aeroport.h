#ifndef AEROPORT_CLASS
#define AEROPORT_CLASS
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

#include "Vehicule.hpp"
#include "Voiture.hpp"
#include "Avion.hpp"

/**
  Collection heterogene de Vehicule
*/
class Aeroport
{
  public:
    Aeroport();
    ~Aeroport();
    bool charger(const string& fn);
    unsigned size() const;
    void ajouter(Vehicule* v);
    void calculer(int annee) const;
    void vider();

  protected:
    bool ajouterVoiture(istream& is);
    bool ajouterAvion(istream& is);

  private:
    vector<Vehicule*> m_parc; //<- POINTEUR

    Aeroport(const Aeroport&); // interdit la recopie
    Aeroport& operator=(const Aeroport&); // interdit l'affectation
};
#include "Aeroport.cpp"
#endif
