#ifndef CBREMUNEREAVECDECOUVERT_CLASS
#define CBREMUNEREAVECDECOUVERT_CLASS

#include "CRemunere.hpp"
class CRemunereAvecDecouvert : public CRemunere
{
  typedef CRemunere super;
  public:
    CRemunereAvecDecouvert();
    CRemunereAvecDecouvert(const string& num, double mt, double taux, double dmax);
    void fixerDMax(double mt);
    void retirer(double mt);
    void afficher() const;
  private:
    double m_dmax;
};
#include "CRmAvecDec.cpp"
#endif
