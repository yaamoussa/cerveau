#ifndef COMPTEBANCAIRE_CLASS
#define COMPTEBANCAIRE_CLASS
#include <string>
using namespace std;

class CBancaire
{
  public:
    CBancaire();
    CBancaire(const string& num, double mt);
    ~CBancaire();
    double getSolde() const;
    void deposer(double mt);
    void retirer(double mt);
    void afficher() const;
    void virerVers(CBancaire& c, double mt);
  protected:
    string m_num;
    double m_solde;
};
#include "CBancaire.cpp"
#endif
