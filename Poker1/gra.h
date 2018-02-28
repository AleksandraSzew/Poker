#ifndef gra
#define gra
#include <iostream>
#include <string>
#include <conio.h>
#include <windows.h>
#include "menu.h"
#include "gracz.h"
#include<stdlib.h>
#include<time.h>

class Gra
{	
public:
	friend class menu;
	friend class gracz;
	void game(); //generuje gre
	void stol(int suma, karta a,karta b,karta c,karta d, karta e, int DoObstawienia); //generuje karty na stole
	int losowanie(int min, int max)
	{return( rand() % max ) + min;}
	void check(karta g1a,karta g1b,karta g2a,karta g2b,karta a,karta b,karta c,karta d, karta e, int &kto,int passg1,int passg2); //sprawdza wygrana
	void rozdajpieniadze(int kto, int &suma, Gracz &a, Gracz &b);
	Gra() 
	{  }
};


#endif