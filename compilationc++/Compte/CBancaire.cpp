#include <iostream>
using namespace std;

CBancaire::CBancaire()
: m_num(), m_solde(0.0)
{
  cout<<">> Constr. CBancaire()"<<endl;
}

CBancaire::CBancaire(const string& num, double mt)
: m_num(num), m_solde(mt)
{
  cout<<">> Constr. CBancaire(num,mt)"<<endl;
}

CBancaire::~CBancaire()
{
  cout<<"<< Destr. CBancaire"<<endl;
}

double CBancaire::getSolde() const
{
  return m_solde;
}

void CBancaire::deposer(double mt)
{
  cout<<"CBancaire::deposer "<<m_num<<" : "<<mt<<endl;
  m_solde += mt;
}

void CBancaire::retirer(double mt)
{
  cout<<"CBancaire::retirer "<<m_num<<" : "<<mt<<endl;
  if (getSolde() >= mt)
  {
    m_solde -= mt;
  }
  else
  {
    cerr<<endl
        <<">>> OUPS Provision insuffisante <<<"
        <<endl<<endl;
  }
}

void CBancaire::afficher() const
{
  cout<<"CBancaire "<<m_num<<" : solde = "<<getSolde()<<endl;
}

void CBancaire::virerVers(CBancaire& c, double montant)
{
  cout<<"CBancaire::virerVers "<<m_num<<" : "<<montant<<endl;
  c.retirer(montant);
  deposer(montant);
}

