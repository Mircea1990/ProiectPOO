#ifndef BILETE_SALA_H
#define BILETE_SALA_H

#include <iostream>
#include <fstream>

using namespace std;

class Sala {
private:
    int id;
    int numarLocuri;
    int numarLocuriLibere;
    int *locuriLibere; // vector alocat dinamic
public:
    // constructur cu parametri
    Sala(int id, int numarLocuri);

    Sala(int id, int numarLocuri, int numarLocuriLibere, const int *locuriLibere);

    // pt cele care contin valori alocate dinamic, obligatoriu CC, ~ si =

    Sala(const Sala &f);

    ~Sala();

    Sala operator=(const Sala &f);

    // operatori >> si <<
    friend istream &operator>>(istream &in, Sala &f);

    friend ostream &operator<<(ostream &out, const Sala &f);

    // []
    int operator[](int index) {
        return 0;
    }

    // +/-/*/\/
    Sala operator+(int extraMinutes);

    // ++ sau -- cu cele doua forme
    Sala operator++();

    Sala operator++(int);

    // cast catre un tip explicit sau implicit
    explicit operator char *() const;
    // !
	Sala operator!();

    // </>/...
    bool operator<(const Sala &f);

    bool operator<=(const Sala &f);

    // ==
    bool operator==(const Sala &f);

    // gettere si settere (toti setter-ii vor contine validari)

	// Etapa 2:
	void toFile(ofstream& fout) {
		fout << "Id Sala: " << id << endl;
		// TODO Sa adaug si un nume salii?
	}

	void showFreeSeats(ostream& out) {
		out << "Locurile libere sunt: ";
		for (int i = 0; i < numarLocuriLibere; i++) {
			out << locuriLibere[i] << ' ';
		}
		out << endl;
	}
	bool containsLoc(int numarLoc) {
		for (int i = 0; i < numarLocuriLibere; i++) {
			if (locuriLibere[i] == numarLoc) {
				return true;
			}
		}
		return false;
	}
};

#endif //BILETE_SALA_H
