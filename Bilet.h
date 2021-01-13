#ifndef BILET_H
#define BILET_H

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

    // constructur cu parametri
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
};

//int Bilet::bileteProcesate = 0;

#endif //BILET_H
