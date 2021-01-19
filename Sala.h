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
	int *locuriLibere; public:
		Sala();

		Sala(int id, int numarLocuri);

	Sala(int id, int numarLocuri, int numarLocuriLibere, const int*locuriLibere);

	
	Sala(const Sala &f);

	~Sala();

	Sala operator=(const Sala &f);


		friend istream &operator>>(istream &in, Sala &f);

	friend ostream &operator<<(ostream &out, const Sala &f);

		int operator[](int index) {
		return 0;
	}

		Sala operator+(int extraMinutes);

		Sala operator++();

		Sala operator++(int);

		explicit operator char *() const;
		Sala operator!();

		bool operator<(const Sala &f);

	bool operator<=(const Sala &f);

		bool operator==(const Sala &f);

	
	int getId() const {
		return id;
	}
	int getNumarLocuriLibere() const {
		return numarLocuriLibere;
	}
	int getNumarLocuri() const {
		return numarLocuri;
	}

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

		friend ofstream& operator<<(ofstream& fout, const Sala& s) {
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

				delete[]s.locuriLibere;
				if (s.numarLocuriLibere > 0) {
			s.locuriLibere = new int[s.numarLocuriLibere];
			fin.read((char*)s.locuriLibere, s.numarLocuriLibere * sizeof(s.locuriLibere[0]));
		}
		else {
			s.locuriLibere = nullptr;
			s.numarLocuriLibere = 0; 		}

		return fin;
	}

	
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

#endif 