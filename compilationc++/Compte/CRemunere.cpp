#include <iostream>
using namespace std;

CRemunere::CRemunere()
: super(), m_taux(0.0)
{
  cout << ">> Constr. CRemunere()" << endl;
}

CRemunere::CRemunere(const string& num, double mt, double taux)
: super(num, mt), m_taux(taux)
{
  cout << ">> Constr. CRemunere(...)" << endl;
}

void CRemunere::fixerTaux(double mt)
{
  m_taux = mt;
}

void CRemunere::retirer(double mt)
{
  cout << "CRemunere::retirer " << m_num << endl;
  super::retirer(mt);
}

void CRemunere::calculerInterets()
{
  m_solde += getSolde() * m_taux;
}

void CRemunere::afficher() const
{
  cout << "CRemunere : taux " << m_taux << endl << "  ";
  super::afficher();
}
