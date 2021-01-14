#pragma once

#include <fstream>
#include <cstring>

#include <vector>
#include <set>

#include "Film.h"
#include "Bilet.h"
#include "Client.h"
#include "Loc.h"
#include "Sala.h"
#include "RulareFilm.h"



class Cinema
{
protected:
	set<RulareFilm*> filmeRulate;
	vector<Sala*> sali;
	vector<Bilet*> bileteEmise;

	string fisierBinar;
	string fisierTextBileteEmise;

public:

	friend class CinemaMenu; // pentru accesul in CinemaMenu, care mosteneste cinema

	// constructor fara parametri
	Cinema() {
		fisierBinar = "./files/cinema.bin";
		fisierTextBileteEmise = "./files/bilete.txt";
	}
	// constructor cu parametri
	Cinema(
		const set<RulareFilm*>& filmeRulate,
		const vector<Sala*>& sali,
		const vector<Bilet*>& bileteEmise,
		const string& fisierBinar,
		const string& fisierTextBileteEmise
	)
		:
		fisierBinar(fisierBinar),
		fisierTextBileteEmise(fisierTextBileteEmise) {
		// de fiecare data cand cream un cinema, alocam dinamic toate filmele salile si biletele:
		for (auto rulare : filmeRulate) {
			this->filmeRulate.insert(new RulareFilm(*rulare));
		}
		for (auto sala : sali) {
			this->sali.push_back(new Sala(*sala));
		}
		for (auto bilet : bileteEmise) {
			this->bileteEmise.push_back(new Bilet(*bilet));
		}
	}

	~Cinema() {
		for (auto film : filmeRulate) {
			delete film;
		}
		for (auto sala : sali) {
			delete sala;
		}
		for (auto bilet : bileteEmise) {
			delete bilet;
		}
	}

	// cast explicit catre char*, pentru afiseara pe o linie a datelor din cinema:
	explicit operator char* () const {
		const int maxLen = 10000; //
		char* s = new char[maxLen + 1];

		strcpy_s(s, maxLen, "Cinema { ");

		strcat_s(s, maxLen, "fisierBinar=");
		strcat_s(s, maxLen, fisierBinar.c_str());

		strcat_s(s, maxLen, ", \n\tfisierTextBileteEmise=");
		strcat_s(s, maxLen, fisierTextBileteEmise.c_str());

		strcat_s(s, maxLen, ", \n\tfilmeRulate=[ ");
		for (auto rulat : filmeRulate) {
			strcat_s(s, maxLen, " \n\t\t");
			strcat_s(s, maxLen, (char*)(*rulat));
		}
		strcat_s(s, maxLen, "]");

		strcat_s(s, maxLen, ", \n\tsali=[ ");
		for (auto sala : sali) {
			strcat_s(s, maxLen, " \n\t\t");
			strcat_s(s, maxLen, (char*)(*sala));
		}
		strcat_s(s, maxLen, "]");

		strcat_s(s, maxLen, ", \n\tbileteEmise=[ ");
		for (auto bilet : bileteEmise) {
			strcat_s(s, maxLen, " \n\t\t");
			strcat_s(s, maxLen, (char*)(*bilet));
		}
		strcat_s(s, maxLen, "]");

		strcat_s(s, maxLen, " }");

		return s;
	}

	// functiile add, selectareRulare si selectareSala sunt metode auxiliare pentru rularea CRUD-ului
	void add(const RulareFilm& r) {
		filmeRulate.insert(new RulareFilm(r));
	}
	void add(const Film& f, const Sala& s) {
		filmeRulate.insert(new RulareFilm(f, s));
	}
	void add(const Sala& s) {
		sali.push_back(new Sala(s));
	}
	void add(const Bilet& b) {
		bileteEmise.push_back(new Bilet(b));
	}

	RulareFilm* selecteazaRulare() {
		if (bileteEmise.size() == 0) {
			return nullptr;
		}
		// afiseaza (impreuna cu un indice) toate rularile
		int index = 0;
		for (auto rulare : filmeRulate) {
			cout << index << ". " << (char*)rulare << endl;
		}
		// selecteaza unul dintre rulari
		do {
			cout << "Alegeti un bilet:" << endl;
			cout << "> ";
			cin >> index;
		} while (index < 0 || index > bileteEmise.size());
		// returneaza rulare
		int i = 0;
		for (auto rulare : filmeRulate) {
			if (i == index) {
				return rulare;
			}
			i++;
		}
		return nullptr;
	}
	Sala* selecteazaSala() {
		if (bileteEmise.size() == 0) {
			return nullptr;
		}
		// afiseaza (impreuna cu un indice) toate biletele
		int index = 0;
		for (auto sala : sali) {
			cout << index << ". " << (char*)sala << endl;
		}
		// selecteaza unul dintre bilete
		do {
			cout << "Alegeti un bilet:" << endl;
			cout << "> ";
			cin >> index;
		} while (index < 0 || index > bileteEmise.size());
		// returneaza bilet
		Sala* sala = sali.at(index);
		return sala;
	}
	Loc* selecteazaLocInSala(const Sala& sala) {
		Loc* loc = nullptr;
		if (sala.getNumarLocuriLibere() > 0) {
			int numarLoc = -1;
			sala.showFreeSeats();
			do {
				cout << "Introduceti numarul locului" << endl;
				cout << "> ";
				cin >> numarLoc;
			} while (!sala.containsLoc(numarLoc));
		}
		else {
			cout << "Pentru aceasta sala nu avem locuri libere" << endl;
		}
		return loc;
	}
	Bilet* selecteazaBilet() {
		if (bileteEmise.size() == 0) {
			return nullptr;
		}
		// afiseaza (impreuna cu un indice) toate biletele
		int index = 0;
		for (auto bilet : bileteEmise) {
			cout << index << ". " << (char*)bilet << endl;
		}
		// selecteaza unul dintre bilete
		do {
			cout << "Alegeti un bilet:" << endl;
			cout << "> ";
			cin >> index;
		} while (index < 0 || index > bileteEmise.size());
		// returneaza bilet
		Bilet* bilet = bileteEmise.at(index);
		return bilet;
	}

	// salvare si incarcare din fisiere binare
	friend ifstream& operator>>(ifstream& in, Cinema& c) {
		// dealoca date:
		for (auto film : c.filmeRulate) {
			delete film;
		}
		c.filmeRulate.clear();

		for (auto sala : c.sali) {
			delete sala;
		}
		c.sali.clear();

		for (auto bilet : c.bileteEmise) {
			delete bilet;
		}
		c.bileteEmise.clear();

		// citire date:
		size_t size;

		in.read((char*)&size, sizeof(size));
		for (int i = 0; i < size; i++)
		{
			RulareFilm* rulare = new RulareFilm();
			in >> *rulare; // supraincarcat in RulareFilm
			c.filmeRulate.insert(rulare);
		}


		in.read((char*)&size, sizeof(size));
		for (int i = 0; i < size; i++)
		{
			Sala* sala = new Sala();
			in >> *sala; // supraincarcat in Sala
			c.sali.push_back(sala);
		}


		in.read((char*)&size, sizeof(size));
		for (int i = 0; i < size; i++)
		{
			Bilet* bilet = new Bilet();
			in >> *bilet; // supraincarcat in Bilet
			c.bileteEmise.push_back(bilet);
		}
		return in;
	}
	friend ofstream& operator<<(ofstream& fout, Cinema& c) {
		size_t size;

		size = c.filmeRulate.size();
		fout.write((char*)&size, sizeof(size));
		for (auto rulare : c.filmeRulate)
		{
			fout << *rulare; // supraincarcat in RulareFilm
		}

		size = c.sali.size();
		fout.write((char*)&size, sizeof(size));
		for (auto sala : c.sali)
		{
			fout << *sala; // supraincarcat in Sala
		}

		size = c.bileteEmise.size();
		fout.write((char*)&size, sizeof(size));
		for (auto bilet : c.bileteEmise)
		{
			fout << *bilet; // supraincarcat in Bilet
		}

		return fout;
	}

	void save() {
		ofstream fout(fisierBinar, std::ios::binary);
		fout << *this;
	}

	void load() {
		ifstream fin(fisierBinar, std::ios::binary);
		// test if the file actually exists
		if (fin.good()) { // daca fisierul este bun, deci in primul rand sa existe dintr-o bilet anterioara
			fin >> *this;
		}
	}

	// Cerinta:
	// Emitere bilet (cu selectarefilm, bilet, loc, etc) =>
	//  biletul este salvat într-un fișier text pentru a putea fi ulterior printat

	void saveBilet(Bilet* b) {
		ofstream fout(fisierTextBileteEmise, std::ios::app);

		// << was used for binary files, so we used a method:
		b->toFile(fout);
	}

	void emiteBilet() { 		// select Film rulat (contine si Sala), apoi Loc
		cout << "Selectati datele pentru a emite un nou bilet" << endl;
		RulareFilm* rulare = selecteazaRulare();
		if (rulare != nullptr) {
			// selectam un loc in aceasta sala
			Loc* loc = selecteazaLocInSala(rulare->getSala());
			if (loc != nullptr) {
				Bilet* biletNou = new Bilet(rulare->getFilm(), *loc);
				// salveaza locul in Cinema si pune-l in fisierul text pt printare:
				saveBilet(biletNou); 				bileteEmise.push_back(biletNou);
			}
			else {
				cout << "Nu am gasit niciun loc la acest film si aceasta sala." << endl;
			}
		}
	}

	// Situație locuri libere (afișare în consolă sau fișier text)
	void situatieLocuriLibere() {
		// parcurge toate filmele rulate si afiseaza bilet si locurile libera din bilet pentru fiecare dintre ele
		for (auto rulat : filmeRulate) {

			Film film = rulat->getFilm();
			Sala sala = rulat->getSala();

			if (sala.contineLocuriLibere()) {
				cout << "Filmul " << film.getNume() << " ruleaza in sala " << sala.getId() << ". Mai avem urmatoarele locuri libere:" << endl;
				sala.afiseazaLocuriLibere();

				cout << endl;
			}
		}
		if (filmeRulate.size() == 0) {
			cout << "In prezent, in cinema nu ruleaza niciun film, deci nu avem niciun fel de locuri." << endl;
		}
	}

	// o Situație filme (ce filme rulează, la ce ore, în ce săli)

	void situatieFilme() {
		// afisam la modul filmul nume film ruleaza in bilet bilet si mai sunt n locuri libere

		for (auto rulat : filmeRulate) {

			Film film = rulat->getFilm();
			Sala sala = rulat->getSala();

			cout << "Filmul " << film.getNume() << " ruleaza in sala " << sala.getId() << endl;
			if (sala.contineLocuriLibere()) {
				cout << "Au mai ramas " << sala.getNumarLocuriLibere() << " locuri libere din totatul de " << sala.getNumarLocuri() << endl;
			}
			else {
				cout << "\tNu mai sunt locuri libere pentru acest film" << endl;
			}
			cout << endl;
		}
		if (filmeRulate.size() == 0) {
			cout << "In prezent, in cinema nu ruleaza niciun film." << endl;
		}
	}

	// o Operații de tip CRUD (Create Read Update Delete)
	// pentru toate entitățile:
	//      Adăugare bilet, modificare  bilet,  ștergere  bilet,
	//      adăugare  sală,  modificare  sală,  ștergere  sală,
	//      adăugare filme, modificare film, ștergere film,
	//      etc

	void CRUD() {
		// Efectueaza operatii CRUD pe cinema:
		int option = 0;

		do {
			cout << "-- Meniu CRUD --" << endl;
			cout << "1. Adauga rulare film" << endl;
			cout << "2. Modifica date rulare" << endl;
			cout << "3. Sterge date rulare" << endl;
			cout << "4. Adauga sala" << endl;
			cout << "5. Modifica date sala" << endl;
			cout << "6. Sterge date sala" << endl;
			cout << "7. Adauga bilet nou" << endl;
			cout << "8. Modifica date bilet" << endl;
			cout << "9. Sterge date bilet" << endl;
			cout << "10. Exit CRUD" << endl;

			do {
				cout << "> ";
				cin >> option;
			} while (option < 1 || option > 10);

			if (option == 1) {
				// citim o noua rulare de film
				RulareFilm rulare;
				cin >> rulare;
				add(rulare);
			}
			else if (option == 2) {
				// selectam si modificam o rulare existenta
				cout << "Selectati o rulare de film pentru a o modifica." << endl;
				RulareFilm* rulare = selecteazaRulare();
				if (rulare != nullptr) {
					cin >> *rulare;
				}
			}
			else if (option == 3) {
				cout << "Selectati o rulare de film pentru a o sterge." << endl;
				RulareFilm* rulare = selecteazaRulare();
				filmeRulate.erase(rulare); // stergem rularea din set
			}
			else if (option == 4) {
				// citim un nou bilet
				Sala sala;
				cin >> sala;
				add(sala); // salveaza datele din bilet ca un pointer Sala*
			}
			else if (option == 5) {
				// selectam si modificam un bilet existenta
				cout << "Selectati o sala pentru a o modifica." << endl;
				Sala* sala = selecteazaSala();
				if (sala != nullptr) {
					cin >> *sala;
				}
			}
			else if (option == 6) {
				cout << "Selectati o sala pentru a o modifica." << endl;
				Sala* sala = selecteazaSala();
				// stergem bilet din vector
				for (int i = 0; i < sali.size(); i++) {
					if (sali[i] == sala) {
						sali.erase(sali.begin() + i);
						break;
					}
				}
			}
			else if (option == 7) {
				// citim un nou bilet, care sa poate fi eliberat de catre Cinema
				//	adica selectam o rulare film si un loc in functie de sala din rulare
				cout << "Selectati datele pentru un nou bilet" << endl;
				RulareFilm* rulare = selecteazaRulare();
				if (rulare != nullptr) {
					Loc* loc = selecteazaLocInSala(rulare->getSala());
					if (loc != nullptr) {
						add(Bilet(rulare->getFilm(), *loc));
					}
					else {
						cout << "Nu am gasit niciun loc la acest film si aceasta sala." << endl;
					}
				}
			}
			else if (option == 8) {
				// selectam si modificam un bilet existent
				cout << "Selectati o rulare de film pentru a o modifica." << endl;
				Bilet* bilet = selecteazaBilet();
				if (bilet != nullptr) {
					cin >> *bilet;
				}
			}
			else if (option == 9) {
				// stergem un bilet existent
				cout << "Selectati un bilet pentru a-l sterge." << endl;
				Bilet* bilet = selecteazaBilet();
				for (int i = 0; i < bileteEmise.size(); i++) {
					if (bileteEmise[i] == bilet) {
						bileteEmise.erase(bileteEmise.begin() + i);
						break;
					}
				}
			}
		} while (option != 10);
	}

	// gettere si settere:

	const set<RulareFilm*>& getFilmeRulate() const {
		return filmeRulate;
	}

	const vector<Sala*>& getSali() const {
		return sali;
	}

	const vector<Bilet*>& getBileteEmise() const {
		return bileteEmise;
	}

	const string& getFisierBinar() const {
		return fisierBinar;
	}

	const string& getFisierTextBileteEmise() const {
		return fisierTextBileteEmise;
	}

};

