#ifndef AVION_CLASS
#define AVION_CLASS
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
  Represente des avions
*/
class Avion : public Vehicule
{
  typedef Vehicule super;

  public:
    // Enumerateurs des categories
    enum { REACTION = 0, HELICES };

    Avion(const string& m, int d, double p, unsigned mt, unsigned h);
    VIRTUAL void afficher() const;
    #if !defined(USE_POLYMORPHISME)
    double eval(int annee) const;
    #endif

  protected:
    VIRTUAL double decote(int annee) const;

  private:
    unsigned m_mt; // type de moteur
    unsigned m_hv; // nombre d'heures de vol
};
#include "Avion.cpp"
#endif

