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
        Loc();
        Loc(int id, int numar, Sala sala);

        friend istream &operator>>(istream &in, Loc &f);

    friend ostream &operator<<(ostream &out, const Loc &f);

        int operator[](int index);

    	Loc operator+(int i);

        Loc operator++();

    Loc operator++(int);

        explicit operator char *() const;
    	Loc operator!();

        bool operator<(const Loc &f);

    bool operator<=(const Loc &f);

        bool operator==(const Loc &f);

    

		void toFile(ofstream& fout) {
		fout << "Numarul locului: " << numar << endl;
		fout << "--Date despre sala--" << endl;
		fout << sala;
	}

	
	friend ofstream& operator<<(ofstream& fout, const Loc& l) {
		
		fout.write((char*)&l.id, sizeof(l.id));

		fout.write((const char*)&l.numar, sizeof(l.numar)); 
		fout << l.sala; 
		return fout;
	}

	friend ifstream& operator>>(ifstream& fin, Loc& l) {
		
		fin.read((char*)&l.id, sizeof(l.id));

				int *numar = const_cast<int *>(&l.numar);
		int numarNou;
		fin.read((char*)&numarNou, sizeof(numarNou));
		*numar = numarNou;

		fin >> l.sala;

		return fin;
	}

};


#endif 