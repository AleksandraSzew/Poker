#include<iostream>
#include <conio.h>
#include <windows.h>
#include<string>
#include "menu.h"
#include "gracz.h"
#include "gra.h"



void menu::pomoc()
{
	cout<<"ZASADY GRY:"<<endl;
	cout<<"Otrzymujesz dwie zakryte karty, ktorych Twoi przeciwnicy nie widza. Nastepnie  "<<endl;
	cout<<"zostaje odkrytych pod rzad piec kart. Nosza one nazwe kart wspolnych, z  "<<endl; 
	cout<<"ktorych moga korzystac wszyscy gracze. Przed rozdaniem kart pierwszy gracz "<<endl;
	cout<<"wnosi Small Blind(zaklad w ciemno). W ten sposob powstaje pula wyjsciowa "<<endl;
	cout<<"Natepnie kazdy gracz dostaje po dwie zakryte karty.Wtedy rusza pierwsza runda "<<endl;
	cout<<"licytacji. Po pierwszej rundzie licytacji na srodek stolu wykladane sa trzy "<<endl;
	cout<<"karty odkryte. Wtedy rusza druga runda licytacji. Dla trzeciej oraz czwartej "<<endl;
	cout<<"rundy odkrywana jest jedna karta na runde."<<endl<<endl;
	cout<<"UKLADY KART: "<<endl;
	cout<<"Poker: piec kolejnych kart w jednym kolorze. "<<endl;
	cout<<"Czworka lub kareta: cztery karty o jednakowej wartosci."<<endl;
	cout<<"Full: trzy karty o jednakowej wartosci i para. "<<endl;
	cout<<"Kolor: piec kart w jednym kolorze. "<<endl;
	cout<<"Strit: pice kolejnych kart. "<<endl;
	cout<<"Trojka: trzy karty o jednakowej wartoœci. "<<endl;
	cout<<"Dwie pary: dwie pary kart o jednakowej wartoœci."<<endl;
	cout<<"Para: dwie karty o jednakowej wartosci."<<endl;
	cout<<"Najwyzsza karta: dowolny uklad nienalezaca do zadnej z powyzszych kategorii. "<<endl;
}


void menu::wyswietl()
{
   
	Gra gra1;


	int op=0;
	char znak;
 while (op !=4 )
 {	system("cls");

			HANDLE kolor;
				kolor = GetStdHandle( STD_OUTPUT_HANDLE );
				SetConsoleTextAttribute( kolor, 2);

		//generowanie menu
				cout<<"____________________________________"<<endl;
				cout<<"|Witamy w grze Poker Texas Hold'em!|"<<endl;
 if( op == 0 ) cout <<"|*Graj                             |"<<endl;
        else cout   <<"| Graj                             |"<<endl;
 if( op == 1 ) cout <<"|*Pomoc                            |"<<endl;
        else cout   <<"| Pomoc                            |"<<endl;
 if( op == 2 ) cout <<"|*Wyjscie                          |"<<endl;
        else cout   <<"| Wyjscie                          |"<<endl;
				cout<<"|__________________________________|"<<endl;
		//opcje menu
znak = getch();
if(op == 0 && znak == 13)
                {
                    system("cls");
					gra1.game();
				

                }

if(op == 1 && znak == 13)
                {
                    
					system("cls");
					menu::pomoc();

                }

if(op == 2 && znak == 13)
                {
                   system("cls");
					break; 
					
                }



	znak = getch();
switch(znak)
	{
case 72:
		op--;
		break;
case 80:
		op++;
		break;
	}

	if(op<0) op++;
	if(op>2) op--;

	}
}

