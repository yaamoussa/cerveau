  #include"ArticleLocal.h"
#include <iostream>
#include <string>
using namespace std;

int ArticleLocal :: nbAlocal =0;
int ArticleLocal:: getnb(){return nbAlocal;}
ArticleLocal:: ArticleLocal (string num,string des ,int prix,int coute): Article(num,des,prix) {
/*	cout <<"constructeur de ArticleLocal"<<endl;*/
	this->coute=coute;
	this->nbAlocal++;

}

ArticleLocal:: ~ArticleLocal(){
	cout<<"Appel du destructeur ArticleLocal"<<endl;
}


void ArticleLocal:: afficher(ostream & sortie){
       sortie<<"nombre total de Article local "<<nbAlocal<<endl;
  	   sortie<<"Article  Local : "<<designation<<endl;
  	   sortie<< "coute "<< calcul_prix() <<endl;
  	   sortie<< "numero referance "<<numref<<endl;
  	   sortie<< "Avec de cout de transport"<<coute<<endl;
  }


  double ArticleLocal:: calcul_prix(){
  	return prix_achat+coute;
  }
