#include <iostream>
#include<string>
using namespace std;
#include"Vaccin.h"



int main(int argc, char const *argv[])
{


	Vaccin v1("Zamiflu",0.55,200000,HighTech);
	Vaccin v2 ("Triple",0.20,10000);
	/*Delocalise v3("Grtn",0.56,10000,false);*/
	Delocalise v4("VIH",0.40,20000,true);
	Delocalise v5(v2,true);

	// afficher vaccin 
	cout<< v1<<endl;
	cout<<v2<<endl;
	cout<<v4<<endl;
	cout<<v5<<endl;
	cout<< "cout de prodution :"<< v4.cout_production()<<endl;
	cout <<"le cout de production de v1 et v2 est :";
	cout<<v1.cout_production()+v2.cout_production()<<endl;

	return 0;
}