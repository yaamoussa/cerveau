

#include<iostream>
#include<cstdlib>
#include<cstring>
using namespace std;
#include"Str.h"


int main()
{
	str s1;
	char * chaine=new char [10];
	strcpy(chaine,"bonjour");
	str s2(chaine);
	char * chaine1=new char [10];
	strcpy(chaine1,"tout le monde");
	str s3(chaine1);
	s1=s2;
	if(s2==s3)
		cout<<s2<<" et "<<s3<<" sont égales"<<endl;
	else
		cout<<s2<<" et "<<s3<<"sont differentes"<<endl;
	cout<<"s1+s3 donne "<<s1+s3<<endl;
	cout<<"A la deuxieme position de s2 on a : "<<s2[2]<<endl;
	return 0;
}