#include <iostream>
#include <string>
#include "ArticleImporte.h"
using namespace std ;

  int ArticleImporte::  nbAImporte =0;
  int ArticleImporte:: getnb(){return nbAImporte;}
ArticleImporte:: ArticleImporte (string num,string des ,int prix,double taux): Article(num,des,prix) {
/*	cout <<"constructeur de ArticleImporte"<<endl;*/
	this->taux=taux;
	this->nbAImporte++;

}

ArticleImporte:: ~ArticleImporte(){
	cout<<"Appel du destructeur ArticleImporte"<<endl;
}


void ArticleImporte:: afficher(ostream & sortie){
	    sortie<<"nombre total de Article Importe "<<nbAImporte<<endl;
  	  sortie<<"Article Importe: "<<designation<<endl;
  	  sortie << "coute "<< calcul_prix() <<endl;
  	  sortie << "numero referance "<<numref<<endl;
  
  }


  double ArticleImporte:: calcul_prix(){
  	return prix_achat*taux*40/100;
  }

