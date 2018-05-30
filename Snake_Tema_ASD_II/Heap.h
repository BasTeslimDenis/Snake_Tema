#pragma once
#include <iostream>
#include <algorithm>
#include <fstream>
#include <string>

using namespace std;

int heap(string Nume,string Prenume) {

	fstream fisier;
	fisier.open("Scores.txt");
	if (!fisier.is_open()) {
		cout << "Nu s-a putut deschide fisierul, programul se va inchide." << endl;
		exit(-1);
	}


	fisier.close();
	return 0;
}
