#include <iostream>
#include <string>
#include "Article.h"
using namespace std ;

int Article:: nbArticle=0;
int Article:: getnb(){
	return nbArticle;
}
  Article:: Article(string num,string des,int prix){
  	/*cout<<"constructeur d un article"<<endl;*/
  	this->numref=num;
  	this->designation=des;
  	this->prix_achat=prix;
    nbArticle++;
  }
 double  Article:: calcul_prix(){
  	return prix_achat;
  }

  Article:: ~Article(){
  	cout<< "la destruction de l article"<<this<<endl;
  }


  int Article :: getPrix(){
  	return prix_achat;
  }


  void Article:: afficher(ostream & sortie){

  	sortie<<"Article : "<<designation<<endl;
  	sortie<< "cout "<<prix_achat <<endl;
  	sortie<< "numero referance "<<numref<<endl;
  }


ostream & operator << (ostream& sortie ,Article & A){
         A.afficher(sortie);
  	    return sortie;
}

