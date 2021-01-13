#ifndef BILETE_LOC_H
#define BILETE_LOC_H

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
};


#endif //BILETE_LOC_H
