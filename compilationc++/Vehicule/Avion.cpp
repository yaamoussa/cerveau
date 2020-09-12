/**
  Constructeur normal
*/
Avion::Avion(const string& m, int d, double p, unsigned mt, unsigned h)
: super(m, d, p), m_mt(mt), m_hv(h)
{}

/**
  Methode d'affichage
*/
void Avion::afficher() const
{
  cout<<"** Avion: "
      <<(m_mt == HELICES ? "HELICES" : "REACTION")
      <<", "<<m_hv<<" heures de vol"<<endl;

  cout<<"   ";
  super::afficher();
}

/**
  Decote p/r a une annee
*/
double Avion::decote(int annee) const
{
  return 0.1 * m_hv / (m_mt == HELICES ? 100 : 1000);
}

#if !defined(USE_POLYMORPHISME)
/**
  Prix courant p/r a l'annee
*/
double Avion::eval(int annee) const
{
  double d = decote(annee);
  return max(0.0, (1.0 - d) * m_achat);
}
#endif
