#include <string>
#include<iostream>
using namespace std;
#include"Article.h"
#include"ArticleImporte.h"
#include "ArticleLocal.h"
#include"Magasin.h"


int main (){
	Article art1("1222","lait",6000);
	Article art2("2234","sucre",7000);
     //affichage des articles 
/*	cout << art2<<endl;
	cout <<art1<<endl;*/


	ArticleImporte artI1("1222","lai",6000,300);
	ArticleImporte artI2("23333","mourou",150,122);

/*	artI1.afficher();
	artI2.afficher();*/



	ArticleLocal artl1("1222","magon",6000,300);
	ArticleLocal artl2("23333","banane",150,122);
	ArticleLocal artl3("23333","oange",100,122);
/*
	artl1.afficher();
	artl2.afficher();*/
	cout<<"le nombre total d articles crees :"<< Article:: getnb()<<endl;
	cout<<"le nombre total d articles importes crees :"<< ArticleImporte:: getnb()<<endl;
	cout<<"le nombre total d articles locals crees :"<< ArticleLocal:: getnb()<<endl;


	Magasin  M(100);

	M.Ajouter_Article(&artI1);
	M.Ajouter_Article(&artI2);
	M.Ajouter_Article(&artl2);
	M.Ajouter_Article(&artl1);
	M.Ajouter_Article(&artl3);
	M.afficher_Magasin();
	M.Prix_total();
}