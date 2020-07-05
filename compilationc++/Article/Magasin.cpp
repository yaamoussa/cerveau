#include"Magasin.h"
#include<iostream>
using namespace std;



Magasin:: Magasin(int max){
	cout << "Appel Magasin vide plein au plus "<< max <<" Article"<<endl;
	A_max=max;

	A_M=new Article*[max];
	A_ajoute=0;
}



Magasin:: ~Magasin(){
	if (A_M)
		    delete A_M;
	
}

void Magasin :: Ajouter_Article(Article *A){
	if (A_max==A_ajoute)  cout << "Impossible Magasin plein";

	A_M[A_ajoute++]=A;

}


void Magasin :: afficher_Magasin(){
	for (int i=0;i<A_ajoute;i++)
		  cout<< *A_M[i];

}


double Magasin:: Prix_total(){\
	double Total=0.0;
	for(int i=0;i<A_ajoute;i++)
		   Total += A_M[i]->calcul_prix();
    return Total;
}