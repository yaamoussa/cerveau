#include <iostream>
#include <string>
#include "Tri_Selection.h"
using namespace std ;


Tri_Selection::  Tri_Selection(){
               cout<< "objet cree";
}

void Tri_Selection :: Trier_tab(int n,int *tab){
	int tempo,i,j,imin;

     for (i=0;i<n;i++){
     	imin=i;
    /* recherche min partiel*/
     	for(j=i+1;j<=n;j++)
     		if (tab[j]<tab[imin]) imin=j;
     	tempo = tab[imin] ;
    /* mise en place min partiel */
        tab[imin] = tab[i] ;
        tab[i] = tempo ;
     }


     /* affichage valeurs triées */
     int k;
       cout << "\n---- valeurs triées ----\n" ;
for ( k=0 ; k<n ; k++)
              cout<< tab[k];
              


}



  void Tri_Selection::affiche_tab(int n ,int *tab){
  	
     /* affichage valeurs triées */
     int k;
       cout << "\n---- valeurs triées ----\n" ;
for ( k=0 ; k<n ; k++)
              cout<< tab[k];

  }

