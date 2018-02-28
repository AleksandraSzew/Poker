#include <iostream>
#include <string>
#include <conio.h>
#include <windows.h>
#include "menu.h"
#include "gracz.h"
#include "gra.h"
#include "karta.h"
#include<stdlib.h>
#include<time.h>

void Gra::game()
{	
	
	
	int kto; //kto wygral rozgrywke
	int zamiana=1; //do zamiany graczy
	int obstawioneg1=0; //pieniadze obstawione przez gracza1
	int obstawioneg2=0; //pieniadze obstawione przez gracza2
	int znak; //do zamiany w switchu
	int suma=0; //suma na stole
	int DoObstawienia=0; //kwota ktora musi byc obstawiona
	int pasujG1=0; //jesli gracz passuje
	int pasujG2=0;
	int poddajA=0; //jessli gracz poddaje sie
	int poddajB=0;
	int wygrana=0; //1 jesli ktos wygra

karta As("A", 14);
karta K("K", 13);
karta D("D", 12);
karta J("J", 11);
karta dziesiec("10",10);
karta dziewiec("9",9);
karta osiem("8",8);
karta siedem("7",7);
karta szesc("6", 6);
karta piec("5", 5);
karta cztery("4",4);
karta trzy("3",3);
karta dwa("2",2);

	karta talia[13]={As,K,D,J,dziesiec,dziewiec,osiem,siedem,szesc,piec,cztery,trzy,dwa};
	srand(time(NULL));
	
	Gracz player1;
	Gracz player2;
	Gra a;

	cout<<"GRACZ 1:"<<endl;
	player1.opcje();
	cout<<"GRACZ 2:"<<endl;
	player2.opcje();


	cout<<endl<<"Zaczyna sie rozgrywka!"<<endl<<endl;	
			
			system( "cls" );
		while(player1.monety > 0 && player2.monety > 0)
		{	//losowanie kart
			int g1a= losowanie(0,13);
			int g1b= losowanie(0,13);
			int g2a= losowanie(0,13);
			int g2b= losowanie(0,13);
			int s1=  losowanie(0,13);
			int s2=  losowanie(0,13);
			int s3=  losowanie(0,13);
			int s4=  losowanie(0,13);
			int s5=  losowanie(0,13);
			
			//az gracze spasuja lub ktorys sie podda
			while(wygrana==0 && (pasujG1 == 0 && pasujG2 == 0) && poddajA == 0 && poddajB == 0){		
				if(zamiana==1)
				{	//gracz1
							HANDLE kolor;
							kolor = GetStdHandle( STD_OUTPUT_HANDLE );
							SetConsoleTextAttribute( kolor, 4);

				cout<<"G R A C Z   1:"<<endl;
				cout<<player1;
				player1.cards(talia[g1a],talia[g1b]);
			
							kolor = GetStdHandle( STD_OUTPUT_HANDLE );
							SetConsoleTextAttribute( kolor, 2);

				a.stol(suma,talia[s1],talia[s2],talia[s3],talia[s4],talia[s5],obstawioneg2);
			
				player1.menu(); //menu

					cin>>znak;
					switch(znak)
					{
						case 1:
							player1.zwieksz(obstawioneg1,obstawioneg2,suma,DoObstawienia);
							break;
						case 2:
							player1.obstaw(obstawioneg1,obstawioneg2,suma,DoObstawienia);
							break;
						case 3:
							player1.pasuj(pasujG1);
							break;
						case 4:
							player1.rezygnuj(wygrana,poddajA);
							break;
						default:
							break;
					}


				zamiana++;
				system( "cls" );
				}	

			if(wygrana !=1)
			{
				if(zamiana==2)	
				{	//gracz2
							HANDLE kolor;
							kolor = GetStdHandle( STD_OUTPUT_HANDLE );
							SetConsoleTextAttribute(kolor, 6);
			cout<<"G R A C Z   2:"<<endl;
			cout<<player2;
			player2.cards(talia[g2a],talia[g2b]);
						
							kolor = GetStdHandle( STD_OUTPUT_HANDLE );
							SetConsoleTextAttribute(kolor, 2);
			
			a.stol(suma,talia[s1],talia[s2],talia[s3],talia[s4],talia[s5], obstawioneg1);
			player2.menu();	
			cin>>znak;

								switch(znak)
								{
								case 1:
									player2.zwieksz(obstawioneg2,obstawioneg1, suma, DoObstawienia);
									break;
								case 2:
									player2.obstaw(obstawioneg2,obstawioneg1, suma, DoObstawienia);
									break;
								case 3:
									player2.pasuj(pasujG2);
									break;
								case 4:
									player2.rezygnuj(wygrana, poddajB);
									break;
								default:
									break;
								}
				}
			zamiana--;
			system( "cls" );

			}
		
		}
		a.check(talia[g1a],talia[g1b],talia[g2a],talia[g2b],talia[s1],talia[s2],talia[s3],talia[s4],talia[s5], kto,poddajA,poddajB);
		
		rozdajpieniadze(kto,suma,player1,player2);

		wygrana=0;
		pasujG1=0;
		pasujG2=0;
		suma=0;
		DoObstawienia=0;
		obstawioneg1=0;
		obstawioneg2=0;
		poddajA=0;
		poddajB=0;
		}	

}

void Gra::check(karta g1a,karta g1b,karta g2a,karta g2b,karta a,karta b,karta c,karta d, karta e, int &kto, int passg1,int passg2)
{	
	if(passg2==1)
	{
		kto=1;
		cout<<"W Y G R A L   G R A C Z  1 ! "<<endl;
					Sleep(2000);
	}
	else if(passg1==1)
	{
		kto=2;
		cout<<"W Y G R A L   G R A C Z  2 ! "<<endl;
					Sleep(2000);
	}
	else
	{
		int punktyg1=0;
		int punktyg2=0;
		if(g1a.wart==g1b.wart) // gracz1: para 
		{			punktyg1=punktyg1+2;	}

		//gracz1: para ze stolu
		if((g1a.wart==a.wart || g1a.wart==b.wart || g1a.wart==c.wart || g1a.wart==d.wart || g1a.wart==e.wart) || (g1b.wart==a.wart || g1b.wart==b.wart || g1b.wart==c.wart || g1b.wart==d.wart || g1b.wart==e.wart))
		{			punktyg1=punktyg1+2;	}
		
		//gracz1:trojka ze stolu
		if((g1a.wart==a.wart && g1b.wart==a.wart) || (g1a.wart==b.wart && g1b.wart==b.wart) || (g1a.wart==c.wart && g1b.wart==c.wart) || (g1a.wart==d.wart && g1b.wart==d.wart) || (g1a.wart==e.wart && g1b.wart==e.wart))
		{			punktyg1=punktyg1+4;	}


		//gracz2: para
		if(g2a.wart==g2b.wart)
		{		punktyg2=punktyg2+2;		}
		//gracz2: para ze stolu
		if(g2a.wart==a.wart || g2a.wart==b.wart || g2a.wart==c.wart || g2a.wart==d.wart || g2a.wart==e.wart || g2b.wart==a.wart || g2b.wart==b.wart || g2b.wart==c.wart || g2b.wart==d.wart || g2b.wart==e.wart)
		{	punktyg2=punktyg2+2;			}

		//gracz2: trojka
		if((g2a.wart==a.wart && g2b.wart==a.wart) || (g2a.wart==b.wart && g2b.wart==b.wart) || (g2a.wart==c.wart && g2b.wart==c.wart) || (g2a.wart==d.wart && g2b.wart==d.wart) || (g2a.wart==e.wart && g2b.wart==e.wart))
		{	punktyg2=punktyg2+4;			}


			if(punktyg1>punktyg2)
			{	kto=1;
				cout<<"W Y G R A L   G R A C Z  1 ! "<<endl;
					Sleep(2000);
			}
			else if(punktyg1<punktyg2)
			{
				kto=2;
				cout<<"W Y G R A L   G R A C Z  2 ! "<<endl;
					Sleep(2000);

			}
			else
			{
				kto=0;
				cout<< " R E M I S !"<<endl;
				Sleep(1500);
		
			}
	}
}		

void Gra::stol(int suma, karta a,karta b,karta c,karta d, karta e, int DoObstawienia)
{			
	            cout << "K A R T Y   N A   S T O L E :" << endl;
            cout << "   ___   ___   ___   ___   ___" << endl;
			cout << "  | " << a.kart << " | | " << b.kart << " | | " << c.kart << " | | " << d.kart << " | | " << e.kart << " |" << endl;
			cout << "  | " << a.wart << " | | " << b.wart << " | | " << c.wart << " | | " << d.wart << " | | " << e.wart << " |" << endl;
            cout << "  |___| |___| |___| |___| |___|" << endl;
            cout << endl << endl;
			cout <<"K W O T A   N A   S T O L E : "<<suma<<endl;

			cout <<"D O   O B S T A W I E N I A : "<<DoObstawienia<<endl<<endl;
			

}

void Gra::rozdajpieniadze( int kto, int &suma, Gracz &a, Gracz &b)
{
	if(kto==1)
	{	
			cout<<a.imie<<": "<<a.monety<<" + "<<suma<<endl;
			Sleep(1500);
			system( "cls" );

			a.monety=a.monety+suma;
			cout<<a.imie<<": "<<a.monety;
			cout<<endl<<endl;
			Sleep(1500);
			system( "cls" );
	}
	else if(kto==2)
	{
			cout<<b.imie<<": "<<b.monety<<" + "<<suma<<endl;
			Sleep(1500);
			system( "cls" );
			b.monety=b.monety+suma;
			cout<<b.imie<<": "<<b.monety;
			cout<<endl<<endl;
			Sleep(1500);
			system( "cls" );
	}
	else
	{
			suma=suma/2;
			cout<<a.imie<<": "<<a.monety<<" + "<<suma<<endl;
			cout<<b.imie<<": "<<b.monety<<" + "<<suma<<endl;
			Sleep(1500);
			system( "cls" );
			a.monety=a.monety+suma;
			b.monety=b.monety+suma;
			cout<<a.imie<<": "<<a.monety<<endl;
			cout<<b.imie<<": "<<b.monety<<endl;
			Sleep(1500);
			system( "cls" );
			

	}

}