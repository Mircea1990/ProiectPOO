#pragma once

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
	// constructor fara parametri
	Sala();

	// constructor cu parametri
	Sala(int id, int numarLocuri);

	Sala(int id, int numarLocuri, int numarLocuriLibere, const int*locuriLibere);

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

	int getId() const {
		return id;
	}
	int getNumarLocuriLibere() const {
		return numarLocuriLibere;
	}
	int getNumarLocuri() const {
		return numarLocuri;
	}

	// Etapa 2:
	void toFile(ofstream& fout) {
		fout << "Id Sala: " << id << endl;
			}

	void showFreeSeats() const {
		cout << "Locurile libere sunt: ";
		for (int i = 0; i < numarLocuriLibere; i++) {
			cout << locuriLibere[i] << ' ';
		}
		cout << endl;
	}
	bool containsLoc(int numarLoc) const {
		for (int i = 0; i < numarLocuriLibere; i++) {
			if (locuriLibere[i] == numarLoc) {
				return true;
			}
		}
		return false;
	}

	// pentru scriere si citire in fisiere binare:
	friend ofstream& operator<<(ofstream& fout, const Sala& s) {
		// id, numarLocuri, numarLocuriLibere, locuriLibere
		fout.write((char*)&s.id, sizeof(s.id));

		fout.write((char*)&s.numarLocuri, sizeof(s.numarLocuri));

		fout.write((char*)&s.numarLocuriLibere, sizeof(s.numarLocuriLibere));

		if (s.numarLocuriLibere > 0 && s.locuriLibere != nullptr) {
			fout.write((char*)s.locuriLibere, s.numarLocuriLibere * sizeof(s.locuriLibere[0]));
		}

		return fout;
	}
	friend ifstream& operator>>(ifstream& fin, Sala& s) {
		fin.read((char*)&s.id, sizeof(s.id));

		fin.read((char*)&s.numarLocuri, sizeof(s.numarLocuri));

		fin.read((char*)&s.numarLocuriLibere, sizeof(s.numarLocuriLibere));

		// dealocam locuriLibere
		delete[]s.locuriLibere;
		// dupa caz, punem nullptr sau realocam locuriLibere
		if (s.numarLocuriLibere > 0) {
			s.locuriLibere = new int[s.numarLocuriLibere];
			fin.read((char*)s.locuriLibere, s.numarLocuriLibere * sizeof(s.locuriLibere[0]));
		}
		else {
			s.locuriLibere = nullptr;
			s.numarLocuriLibere = 0; // even if it was negative.
		}

		return fin;
	}

	// pentru cerinta cu situatia locurilor libere

	void afiseazaLocuriLibere() {
		for (int i = 0; i < numarLocuriLibere; i++) {
			cout << locuriLibere[i] << " ";
		}
		cout << endl;
	}
	bool contineLocuriLibere() {
		return numarLocuriLibere > 0;
	}
};

