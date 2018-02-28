#ifndef g
#define g
#include<iostream>
#include <conio.h>
#include <windows.h>
#include<string>
#include<stdlib.h>
#include<time.h>


using namespace std;


class Gracz{
public:

	int monety;
	string imie;
	Gracz(int a, string b)
	{
		monety=a;
		imie=b;
	
	}
	Gracz() { }

	friend class menu;
	friend class Gra;
	friend class karta;
	void opcje()
	{
	cout<<"Podaj imie gracza: ";
    cin>>imie;
	do{
    cout<<"Podaj ilosc monet(od 1 do 2000): ";
    cin>>monety;
	}while(monety <= 0 || monety > 2000);

	}
	karta cards(karta a,karta b);
	void menu();
	int zwieksz(int &obstawione, int przeciwnika, int &suma, int &DoObst);
	int obstaw( int &obstawione, int przeciwnika,int &suma, int &DoObst);
	void pasuj(int &pass);
	int rezygnuj(int &wygrana, int &poddaj);
	friend ostream& operator<<(ostream& out, Gracz& a);

	friend class menu;
	friend class Gra;
	friend class karta;
};


#endif