#pragma once

#include "Film.h"
#include "Loc.h"
#include "Sala.h"

#include <iostream>
#include <fstream>

using namespace std;

class Bilet {
private:
    static int bileteProcesate;
	int id; // etapa 2
    Film film;
    Loc loc; // contine si sala
public:
    // constructor fara parametri
    Bilet() : id(0), film(), loc() {}

    // constructor cu parametri
    Bilet(const Film &f, const Loc &l);

    // operatori >> si <<
    friend ostream &operator<<(ostream &os, const Bilet &bilet);
    friend istream& operator>>(istream &in, Bilet& b);
    // []
    int operator[](int index);
    // +/-/*/\/
	Bilet operator+(int i);
    // ++ sau -- cu cele doua forme
    Bilet operator++();
    Bilet operator++(int);
    // cast catre un tip explicit sau implicit
    explicit operator char*();
    // !
    Bilet operator!();
    // </>/...
    bool operator<=(int minutes);
    // ==
    bool operator==(const Bilet& b);
    // set vor contine validari

	// Etapa 2:
	void toFile(ofstream& fout) {
		// save the Bilet for later printing
		this->film.toFile(fout);
		this->loc.toFile(fout);
		fout << endl;
	}

	// >> si << pentru scriere si citire din fisiere binare:
	friend ofstream& operator<<(ofstream& fout, const Bilet& b) {
		// bileteProcesate (static, but used for recounting when loading the Cinema), id, film, loc
		 
		fout.write((char*)&(Bilet::bileteProcesate), sizeof(Bilet::bileteProcesate));

		fout.write((char*)&b.id, sizeof(b.id));

		fout << b.film;

		fout << b.loc;

		return fout;
	}

	friend ifstream& operator>>(ifstream& fin, Bilet& b) {
		// bileteProcesate (static, but used for recounting when loading the Cinema), id, film, loc

		int bileteProcesateFisier = 0; // acelasi tip ca si campul static.
		fin.read((char*)&bileteProcesateFisier, sizeof(bileteProcesateFisier));
		if (bileteProcesateFisier > Bilet::bileteProcesate) {
			Bilet::bileteProcesate = bileteProcesateFisier + 1;
		}

		fin.read((char*)&b.id, sizeof(b.id));

		fin >> b.film;

		fin >> b.loc;

		return fin;
	}
};
