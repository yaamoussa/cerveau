using namespace std;
#ifndef STR_H_INCLUDED
#define STR_H_INCLUDED

/*#include<iostream>*/
using namespace std;
class str
{
	int long_chaine;
	char* chaine;
public:
	str();
	str(char* ch);
	str(str& s);
	~str();
	str& operator = (const str& s2);
	bool operator ==(const str& s2);
	str operator +(const str& s2);
	char operator [](int i);
   friend ostream & operator << (ostream &  ,const str &); 
};

#endif