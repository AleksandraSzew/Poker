#ifndef karty
#define karty 
#include<iostream>
#include <conio.h>
#include <windows.h>
#include<string>
#include <cstdlib>
#include <ctime>

using namespace std;

class karta{
public:
	string kart;
	int wart;
	

	karta(string a, int b)
	{
		wart=b;
		kart=a;
		
	}
	karta() { }


karta generujkarty();
	friend class Gra;
	friend class Gracz;

};


#endif