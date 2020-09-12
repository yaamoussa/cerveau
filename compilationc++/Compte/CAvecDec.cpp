#include <iostream>
using namespace std;

CAvecDecouvert::CAvecDecouvert()
: super(), m_dmax(0.0)
{
  cout<<">> Constr. CAvecDecouvert()"<<endl;
}

CAvecDecouvert::CAvecDecouvert(const string& num, double mt, double dmax)
: super(num, mt), m_dmax(dmax)
{
  cout<<">> Constr. CAvecDecouvert(...)"<<endl;
}

void CAvecDecouvert::fixerDMax(double mt)
{
  m_dmax = mt;
}

void CAvecDecouvert::retirer(double mt)
{
  cout<<"CAvecDecouvert::retirer "<<m_num<<endl;
  if (getSolde() - mt >= -m_dmax)
  {
    m_solde -= mt;
  }
  else
  {
    cerr<<endl
        <<">>> CAvecDec: OUPS Provision insuffisante <<<"
        <<endl<<endl;
  }
}

void CAvecDecouvert::afficher() const
{
  cout<<"CAvecDecouvert : dmax "<<m_dmax<<endl<<"  ";
  super::afficher();
}

