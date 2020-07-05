
#include<iostream>
using namespace std;
#include"Str.h"

str::str()
{
	long_chaine=0;
	chaine=NULL;
}
str::str(char* ch)
{
	int i,n=0;
	for(i=0;ch[i]!='\0';i++) n++;
	long_chaine=n;
	chaine=new char[n];
	for(i=0;i<n;i++)
		chaine[i]=ch[i];
}
str::str(str& s)
{
	long_chaine=s.long_chaine;
	chaine=new char[long_chaine];
	for(int i=0;i<long_chaine;i++)
		chaine[i]=s.chaine[i];
}
str::~str()
{
	if(long_chaine) delete chaine;
}
str& str::operator =(const str& s)
{
	if(this==&s) return *this;
	delete chaine;
	long_chaine=s.long_chaine;
	chaine=new char[long_chaine];
	for(int i=0;i<long_chaine;i++)
		chaine[i]=s.chaine[i];
	return *this;
}
bool str::operator ==(const str& s)
{
	if(long_chaine!=s.long_chaine)
		return false;
	else
	{
		int i=0;
		while((i<long_chaine) && (chaine[i]==s.chaine[i]))
			i++;
		if(i==long_chaine)
			return true;
		else
			return false;
	}
}
str str:: operator +(const str& s2)
{
	str s;
	int i,j=0,n=long_chaine+s2.long_chaine;
	s.long_chaine=n;
	s.chaine=new char[n];
	for(i=0;i<n;i++)
	{
		if(i<long_chaine)
			s.chaine[i]=chaine[i];
		else 
			s.chaine[i]=s2.chaine[j++];
	}
	return s;
}
char str::operator [](int i)
{
	if((i<0)||(i>=long_chaine))
		cout<<"\nAttention : mauvais indice !";
	else
		return chaine[i-1];
}
ostream & operator << (ostream & sortie ,const str & s ){
      
             sortie << s.chaine ;
             sortie<<endl;

          return sortie;
}