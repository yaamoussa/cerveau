#include <iostream>
using namespace std;

#define PHASE_TRACE
#define USE_POLYMORPHISME
#include "Aeroport.hpp"

int main()
{
  const int ANNEE_REFERENCE = 2006;
  string fn;
  cout<<"Nom du fichier des donnees? ";
  cin>>fn;
  
  // Encapsulation afin de voir les libérations
  {
    Aeroport parc;

    if ( not parc.charger(fn) )
    {
      cerr<<"OUPS... probleme chargement..."<<endl;
    }
    else
    {
      parc.calculer(ANNEE_REFERENCE);
    }
  }
}