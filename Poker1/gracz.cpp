#include<iostream>
#include <conio.h>
#include <windows.h>
#include<string>
#include "gracz.h"
#include "karta.h"
#include<stdlib.h>
#include<time.h>
using namespace std;


ostream& operator<<(ostream& out, Gracz& a)
{	out<<"_____________________"<<endl;
	out<<"Gracz "<<a.imie<<endl<<"Kwota gracza: "<<a.monety<<"$"<<endl;
	out<<"_____________________"<<endl<<endl;
	return out;
}

karta Gracz::cards(karta a,karta b)
{
			cout << "K A R T Y   G R A C Z A :" << endl;
            cout << "   ___   ___   " << endl;
			cout << "  | " << a.kart << " | | " << b.kart << " |" << endl;
			cout << "  | " << a.wart << " | | " << b.wart << " |" << endl;
            cout << "  |___| |___| " << endl;
            cout << endl << endl;
			return a;
}

void Gracz::menu()
{
	
	//generowanie menu
				cout<<" ____________________"<<endl;
				cout<<"|Wybierz opcje:      |"<<endl;
                cout<<"|1. Zwieksz kwote    |"<<endl;
				cout<<"|2.Obstaw            |"<<endl;
				cout<<"|3.Pasuj             |"<<endl;
				cout<<"|4.Rezygnuj          |"<<endl;
				cout<<"|____________________|"<<endl;

}

int Gracz::zwieksz(int &obstawione, int przeciwnika, int &suma, int &DoObst)
{	
	cout<<"Kwota "<<przeciwnika<<"+ ";
	cin>>obstawione;
	if(obstawione <= Gracz::monety)
	{
		obstawione=obstawione+przeciwnika;
		DoObst=obstawione;
		Gracz::monety=Gracz::monety-obstawione;
		suma=suma+obstawione;
	}
	else
	{
		cout<<"B R A K   M O N E T !"<<endl;
		Sleep(1000);
	}
	return obstawione;
	
	 
}

int Gracz::obstaw(int &obstawione, int przeciwnika, int &suma, int &DoObst)
{	if(przeciwnika<=Gracz::monety)
	{	cout<<"Kwota:"<<przeciwnika;
		Sleep(1000);
		obstawione=przeciwnika;
		DoObst=obstawione;
		Gracz::monety=Gracz::monety-obstawione;
		suma=suma+obstawione;
	}
	else
	{
		cout<<"B R A K   M O N E T !"<<endl;
		Sleep(1000);
	}
	return obstawione;
}

void Gracz::pasuj(int &pass)
{
	pass=1;

}

int Gracz::rezygnuj(int &wygrana, int &poddaj)
{
	wygrana=1;
	poddaj=1;
	return wygrana;
}