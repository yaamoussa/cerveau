#include <iostream>
using namespace std;

CRemunereAvecDecouvert::CRemunereAvecDecouvert()
: super(), m_dmax(0.0)
{
  cout<<">> Constr. CRemunereAvecDecouvert()"<<endl;
}

CRemunereAvecDecouvert::CRemunereAvecDecouvert(const string& num, double mt, double taux, double dmax)
: super(num, mt, taux), m_dmax(dmax)
{
  cout<<">> Constr. CRemunereAvecDecouvert(...)"<<endl;
}

void CRemunereAvecDecouvert::fixerDMax(double mt)
{
  m_dmax = mt;
}

void CRemunereAvecDecouvert::retirer(double montant)
{
  cout<<"CRemunereAvecDecouvert::retirer "<<m_num<<endl;
  if (getSolde() - montant >= -m_dmax)
  {
    m_solde -= montant;
  }
  else
  {
    cerr<<endl
        <<">>> CRAvecDec: OUPS Provision insuffisante <<<"
        <<endl<<endl;;
  }
}

void CRemunereAvecDecouvert::afficher() const
{
  cout<<"CRemunereAvecDecouvert : dmax "<<m_dmax<<endl<<"  ";
  super::afficher();
}
