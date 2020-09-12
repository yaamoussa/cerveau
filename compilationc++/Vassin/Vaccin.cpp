#include <iostream>
#include <string>
using namespace std;
#include"Vaccin.h"


Vaccin::	Vaccin(string  nom ,double v,int d,Fabrication f){
	cout<<"Apppel du constructeur "<<endl;
	  this->nom=nom;
	  volume=v;
	  nbdose=d;
	  fabric=f;
}
Vaccin:: Vaccin(const Vaccin & v){
      this->nom=v.nom;
      this->volume=v.volume;
      this->nbdose=v.nbdose;
      this->fabric=v.fabric;
}

Vaccin:: ~Vaccin(){
	cout<<"Appel du destructeur"<<endl;
}

 double Vaccin::conditionnement(){
 	 return volume*nbdose*COND_UNITE;
 }

 double Vaccin:: fabrication (){
 	double couts=0.0;

 	couts=volume*nbdose*PRIX_BASE;
 	if (fabric==HighTech)
 	{
 		/* code */
 		couts+=couts*MAJORATION_HIGHTECH;

 	}
 	return couts;
 }

 double Vaccin:: cout_production (){
 	return conditionnement()+fabrication();
 }

 void Vaccin:: afficher_Vaccin(ostream & sortie)const {
 	    sortie<<nom<<endl;
 	    sortie<< "volume /dose :"<<volume<<endl;
      sortie<<"nombre de dose :"<<nbdose<<endl;
 	 	   if (fabric==Standard)
 	  {
 	  	
 	  	  sortie<< "mode de fabrication : Standard"<<endl;
 	  }

 	  else   sortie<< "mode de fabrication : HighTech"<<endl;
 	  
 }

  Delocalise :: Delocalise(string nom ,double v,int d,bool del,Fabrication f):Vaccin (nom,v,d,f){
           cout<< "Appel du constructeur Delocalise"<<endl;
           deloca=del;
  }
  Delocalise::Delocalise(const Vaccin & v,bool del ): Vaccin(v){
             cout<<"Appel du constructeur"<<endl;
             deloca=del;
  }

   Delocalise ::~Delocalise(){ cout<<"Appel du destructeur Delocalise"<<endl;}
    double  Delocalise:: cout_production(){ 
  	double prix = Vaccin :: cout_production ();
  	  if (deloca)
  	  {
  	  	/* code */
  	  	return prix+=Vaccin::cout_production()*(1-REDUCTION_DELOC);
  	  }
  	  else  return prix+=(Vaccin::cout_production())/2;


  	 
  }



   void Delocalise:: afficher_Vaccin(ostream & sortie)const {
 	   Vaccin:: afficher_Vaccin(sortie);
 	   if (deloca)
 	   {
 	   	/* code */
 	   	sortie<< "Vaccin delocalise  dans un pays frontalier"<<endl;
 	   }

 	   else sortie <<" vaccin delocalise dans un pays non frontalier"<<endl;
 }


 ostream & operator << (ostream & sortie,const Vaccin & v){
 	         v.afficher_Vaccin(sortie);
   
 	     return sortie;
 }