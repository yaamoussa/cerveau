

#ifndef  VACCIN_H_INCLUDED
#define VACCIN_H_INCLUDED
//  prx du conditionnement d'une unite 
const double COND_UNITE =0.5;
// prix de base de fabrication d 'une unite 
const double PRIX_BASE=1.5;
// majoration du prix de fabrication pour vaccin  "high tech"
const double MAJORATION_HIGHTECH=0.5;
//reduction du cout du a la delocalisation 
const double REDUCTION_DELOC=0.2;
enum Fabrication {Standard,HighTech};


class Vaccin {
	protected :
	string nom ;
	double volume ;
	int nbdose;
	Fabrication fabric;

	public :

	Vaccin(string,double,int,Fabrication f=Standard);
	~Vaccin();
	 Vaccin(const Vaccin &);
	double  conditionnement ();
	double fabrication();
	virtual double cout_production();
	virtual void afficher_Vaccin(ostream &)const;
};

 ostream & operator <<(ostream & ,const Vaccin & );

class Delocalise : public Vaccin{
	bool deloca  ;
	public :
	 Delocalise(string,double,int,bool,Fabrication f=Standard) ;
	 Delocalise( const Vaccin &,bool);
	 ~Delocalise();
	 virtual double cout_production();
	 virtual void afficher_Vaccin(ostream &)const;

};
#endif