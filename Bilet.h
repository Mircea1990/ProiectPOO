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
	int id;     Film film;
    Loc loc; public:
        Bilet() : id(0), film(), loc() {}

        Bilet(const Film &f, const Loc &l);

        friend ostream &operator<<(ostream &os, const Bilet &bilet);
    friend istream& operator>>(istream &in, Bilet& b);
        int operator[](int index);
    	Bilet operator+(int i);
        Bilet operator++();
    Bilet operator++(int);
        explicit operator char*();
        Bilet operator!();
        bool operator<=(int minutes);
        bool operator==(const Bilet& b);
    
		void toFile(ofstream& fout) {
				this->film.toFile(fout);
		this->loc.toFile(fout);
		fout << endl;
	}

		friend ofstream& operator<<(ofstream& fout, const Bilet& b) {
				 
		fout.write((char*)&(Bilet::bileteProcesate), sizeof(Bilet::bileteProcesate));

		fout.write((char*)&b.id, sizeof(b.id));

		fout << b.film;

		fout << b.loc;

		return fout;
	}

	friend ifstream& operator>>(ifstream& fin, Bilet& b) {
		
		int bileteProcesateFisier = 0; 		fin.read((char*)&bileteProcesateFisier, sizeof(bileteProcesateFisier));
		if (bileteProcesateFisier > Bilet::bileteProcesate) {
			Bilet::bileteProcesate = bileteProcesateFisier + 1;
		}

		fin.read((char*)&b.id, sizeof(b.id));

		fin >> b.film;

		fin >> b.loc;

		return fin;
	}
};
