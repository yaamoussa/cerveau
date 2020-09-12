


#ifndef VEHICULE_CLASS
#define VEHICULE_CLASS
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

#if defined(USE_POLYMORPHISME)
  #define VIRTUAL virtual
#else
  #define VIRTUAL
#endif

/**
  Represente des vehicules
*/
class Vehicule
{
  public:
    Vehicule(const string& m, int d, double p);
    VIRTUAL ~Vehicule();
    VIRTUAL void afficher() const;
    double eval(int annee) const;

  protected:
    VIRTUAL double decote(int annee) const;

  protected:
    string m_marque;  // marque du vehicule
    int m_date;       // date (annee) d'achat
    double m_achat;   // prix d'achat
};
#include "Vehicule.cpp"
#endif

