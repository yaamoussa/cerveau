/**
  Constructeur normal
*/
Voiture::Voiture(const string& m, int d, double p,
        double c, unsigned n, unsigned cv, double km)
: super(m, d, p),
  m_cylindree(c), m_nportes(n), m_puissance(cv), m_km(km)
{}

/**
  Methode d'affichage
*/
void Voiture::afficher() const
{
  // Etat des attributs internes
  cout<<"** Voiture: ";
  cout<<m_cylindree<<" litres, "
      <<m_nportes<<" portes, "
      <<m_puissance<<" CV, "
      <<m_km<<" km"<<endl;

  // Etat des attributs HERITEs
  cout<<"   ";
  super::afficher();
}

/**
  Decote p/r a une annee
*/
double Voiture::decote(int annee) const
{
  double d = (annee > m_date) ? (annee - m_date) * 0.02 : 0;
  d += 0.05 * static_cast<int>(m_km / 10000);

  if (m_marque == "Fiat" or m_marque == "Renault")
  {
    d += 0.1;
  }
  else if (m_marque == "Ferrari" or m_marque == "Porsche")
  {
    d -= 0.2;
  }
  return d;
}

#if !defined(USE_POLYMORPHISME)
/**
  Prix courant p/r a l'annee
*/
double Voiture::eval(int annee) const
{
  double d = decote(annee);
  return max(0.0, (1.0 - d) * m_achat);
}
#endif
