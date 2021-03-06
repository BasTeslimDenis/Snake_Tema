﻿// Snake_Tema_ASD_II.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Snake.h"
#include "Body.h"
#include "Food.h"
#include <fstream>
#include <iostream>
#include <conio.h>
#include <fstream>
#include <string>

using namespace std;

enum direction { UP = 'w' , DOWN = 's', LEFT = 'a', RIGHT = 'd' };
direction dir = UP;

int lungime = 30;
int inaltime = 30;
int score = 0;
int numarare_jucatori = 0;
int pozitie_juc = 0;

string scoruri_precedente;
string FullName;

bool Game_Ongoing = true;
char input = 'w';

void init_map();
void switch_dir();
void verificare_jucatori();
void change_direction(char input);
void heapify(int *a);
void Max_Heap(int *a, int i, int n);

bool validare_jucator(string Name);

int main()
{
	Food *a = new Food();
	int x=lungime/2, y=lungime/2;

	cout << "Introduceti numele:";
	getline(cin, FullName);

	int fruit_x = a->get_x();
	int fruit_y = a->get_y();

	Snake *Game_begun= new Snake(x,y);
	Game_begun->AddNewTail(Game_begun, x, y);
	Game_begun->movement(x, y, input);

	while (Game_Ongoing) {

		init_map();

		Game_begun->movement(x, y, input);

		x = Game_begun->current_x();
		y = Game_begun->current_y();

		if (_kbhit()) {
			change_direction(input);
			switch_dir();
		}

		if (x >= lungime || y >= inaltime || x < 0 || y < 0)
			Game_Ongoing = false;

		if (x == fruit_x && y == fruit_y) {
			a->reposition();
			fruit_x = a->get_x();
			fruit_y = a->get_y();
			Game_begun->AddNewTail(Game_begun,x,y);
			score++;
		}
	}

	verificare_jucatori();
	ifstream Scor;
	Scor.open("Scores.txt");
	if (!Scor.is_open()) {
		cout << "Nu s-a putut deschide fisierul cu scoruri." << endl;
		exit(1);
	}

	if (validare_jucator(FullName)) {
		int *a = new int;
		for (int i = 0;i < scoruri_precedente.size();i++) {
			a[i] =scoruri_precedente[i]-'0';
		}
		heapify(a);
	}
	Scor.close();
	delete Game_begun;
    return 0;
}

void init_map()
{
	system("cls");
	for (int i = 0; i < lungime; i++) {
		cout << "#";
	}
	cout << endl;
	for (int i = 1; i < inaltime - 1; i++) {
		for (int j = 0; j < lungime; j++) {
			if (j == 0)
				cout << "#";
			if (j == lungime-1) {
				cout << "#";
				cout << endl;
			}
			else
				cout << " ";
		}
	}
	for (int i = 0; i < lungime; i++) {
		cout << "#";
	}
	
}

void switch_dir()
{
	switch (dir) {
	case UP:
		if (dir != DOWN)
			dir = UP;
		break;

	case DOWN:
		if (dir != UP)
			dir = DOWN;
		break;

	case LEFT:
		if (dir != RIGHT)
			dir = LEFT;
		break;

	case RIGHT:
		if (dir != LEFT)
			dir = RIGHT;
		break;
	
	}
}

void verificare_jucatori()
{
	ifstream verificare;
	verificare.open("Scores.txt");
	if (!verificare.is_open()) {
		cout << "Nu s-a putut deschide fisierul." << endl;
		exit(0);
	}
	
	string temp;
	while (!verificare.eof()) {
		numarare_jucatori++;
	}

	verificare.close();
}

void change_direction(char input)
{
	switch (input) {
	case 'w':
		dir = UP;
		break;
	case 's':
		dir = DOWN;
		break;
	case 'd':
		dir = RIGHT;
		break;
	case 'a':
		dir = LEFT;
		break;
	}
}

void heapify(int * a)
{
	int i;
	for (i = scoruri_precedente.size()/2;i>=1;i--) {
		Max_Heap(a, i, scoruri_precedente.size());
	}
}

void Max_Heap(int * a, int i,int n)
{
	int j = 2*i, temp = a[i];
	while (j <= n) {
		if (j <= n && a[j + 1] > a[j])
			j = j + 1;
		if (temp > a[j])
			break;
		else if (temp <= a[j + 1])
		{
			a[j / 2] = a[j];
			j = j * 2;
		}
	}
	a[i / 2] = temp;

	string temporary;
	int poz;
	ifstream Fisier_Jucatori;
	Fisier_Jucatori.open("Scores.txt");
	if (!Fisier_Jucatori.is_open()) {
		cout << "Nu s-a putut deschide fisierul." << endl;
		exit(0);
	}

	for (int line = 0;getline(Fisier_Jucatori, temporary) && line <= pozitie_juc;line++);
	poz = temporary.find(":");


}

bool validare_jucator(string Name)
{
	int lim_s, lim_d;
	string gasire;
	ifstream verificare_scor;
	verificare_scor.open("Scores.txt");

	if (!verificare_scor.is_open())
	{
		cout << "Fisierul nu a putut fi deschis." << endl;
		exit(0);
	}

	while (!verificare_scor.eof()) {
		lim_s = Name.find(" ");
		lim_d = Name.find(":");
		gasire = Name.substr(lim_s, lim_d);
		if (gasire == Name) {
			scoruri_precedente = Name.substr(lim_d);
			return true;
		}
		pozitie_juc++;
	}
	verificare_scor.close();
	return false;
}



