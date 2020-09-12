#ifndef VOITURE_CLASS
#define VOITURE_CLASS
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
  Represente des voitures
*/
class Voiture : public Vehicule
{
  typedef Vehicule super;

  public:
    // Enumerateurs des categories
    // enum { NORMALE = 0, SPECIALE, SPORTIVE };

    Voiture(const string& m, int d, double p,
            double c, unsigned n, unsigned cv, double km);
    VIRTUAL void afficher() const;
    #if !defined(USE_POLYMORPHISME)
    double eval(int annee) const;
    #endif

  protected:
    VIRTUAL double decote(int annee) const;

  private:
    double m_cylindree;     // cylindree du vehicule
    unsigned m_nportes;     // nombre de portes
    unsigned m_puissance;   // puissance
    double m_km;            // kilometrage
};
#include "Voiture.cpp"
#endif

