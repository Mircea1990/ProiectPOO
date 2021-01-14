#pragma once

#include "Sala.h"
#include <iostream>
#include <fstream>

using namespace std;

class Loc {
private:
    int id;
    const int numar;
    Sala sala;
public:
    // constructor fara parametri
    Loc();
    // constructur cu parametri
    Loc(int id, int numar, Sala sala);

    // operatori >> si <<
    friend istream &operator>>(istream &in, Loc &f);

    friend ostream &operator<<(ostream &out, const Loc &f);

    // []
    int operator[](int index);

    // +/-/*/\/
	Loc operator+(int i);

    // ++ sau -- cu cele doua forme
    Loc operator++();

    Loc operator++(int);

    // cast catre un tip explicit sau implicit
    explicit operator char *() const;
    // !
	Loc operator!();

    // </>/...
    bool operator<(const Loc &f);

    bool operator<=(const Loc &f);

    // ==
    bool operator==(const Loc &f);

    // gettere si settere (toti setter-ii vor contine validari)


	// Etapa 2:
	void toFile(ofstream& fout) {
		fout << "Numarul locului: " << numar << endl;
		fout << "--Date despre sala--" << endl;
		fout << sala;
	}

	// pentru scrierea << si citirea >> dintr-un fisier binar

	friend ofstream& operator<<(ofstream& fout, const Loc& l) {
		// id, numar, sala

		fout.write((char*)&l.id, sizeof(l.id));

		fout.write((const char*)&l.numar, sizeof(l.numar)); // const deoarece l.numar este const

		fout << l.sala; // Supraincarcat in clasa Sala

		return fout;
	}

	friend ifstream& operator>>(ifstream& fin, Loc& l) {
		// citim id, numar, sala

		fin.read((char*)&l.id, sizeof(l.id));

		// pentru modificarea dupa apelul constructorului a const int numar
		int *numar = const_cast<int *>(&l.numar);
		int numarNou;
		fin.read((char*)&numarNou, sizeof(numarNou));
		*numar = numarNou;

		fin >> l.sala;

		return fin;
	}

};


