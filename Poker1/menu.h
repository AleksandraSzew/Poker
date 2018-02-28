#ifndef m
#define m
#include<iostream>
#include <conio.h>
#include <windows.h>
#include<string>
#include "gracz.h"
using namespace std;

class menu{
public:
	
	void wyswietl();
	void pomoc();
	friend class gracz;

};
#endif