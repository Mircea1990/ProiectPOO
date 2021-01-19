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

	friend class CinemaMenu; 
		Cinema() {
		fisierBinar = "./files/cinema.bin";
		fisierTextBileteEmise = "./files/bilete.txt";
	}
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

		explicit operator char* () const {
		const int maxLen = 10000; 		char* s = new char[maxLen + 1];

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
		if (filmeRulate.size() == 0) {
			return nullptr;
		}
				int index = 0;
		for (auto rulare : filmeRulate) {
			cout << index << ". " << (char*)*rulare << endl;
			index++;
		}
				do {
			cout << "Alegeti o rulare:" << endl;
			cout << "> ";
			cin >> index;
		} while (index < 0 || index > filmeRulate.size());
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
		if (sali.size() == 0) {
			return nullptr;
		}
				int index = 0;
		for (auto sala : sali) {
			cout << index << ". " << (char*)*sala << endl;
			index++;
		}
				do {
			cout << "Alegeti o sala:" << endl;
			cout << "> ";
			cin >> index;
		} while (index < 0 || index > sali.size());
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
			loc = new Loc(1, numarLoc, sala);
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
				int index = 0;
		for (auto bilet : bileteEmise) {
			cout << index << ". " << (char*)*bilet << endl;
			index++;
		}
				do {
			cout << "Alegeti un bilet:" << endl;
			cout << "> ";
			cin >> index;
		} while (index < 0 || index > bileteEmise.size());
				Bilet* bilet = bileteEmise.at(index);
		return bilet;
	}

		friend ifstream& operator>>(ifstream& in, Cinema& c) {
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

				size_t size;

		in.read((char*)&size, sizeof(size));
		for (int i = 0; i < size; i++)
		{
			RulareFilm* rulare = new RulareFilm();
			in >> *rulare; 			c.filmeRulate.insert(rulare);
		}


		in.read((char*)&size, sizeof(size));
		for (int i = 0; i < size; i++)
		{
			Sala* sala = new Sala();
			in >> *sala; 			c.sali.push_back(sala);
		}


		in.read((char*)&size, sizeof(size));
		for (int i = 0; i < size; i++)
		{
			Bilet* bilet = new Bilet();
			in >> *bilet; 			c.bileteEmise.push_back(bilet);
		}
		return in;
	}
	friend ofstream& operator<<(ofstream& fout, Cinema& c) {
		size_t size;

		size = c.filmeRulate.size();
		fout.write((char*)&size, sizeof(size));
		for (auto rulare : c.filmeRulate)
		{
			fout << *rulare; 		}

		size = c.sali.size();
		fout.write((char*)&size, sizeof(size));
		for (auto sala : c.sali)
		{
			fout << *sala; 		}

		size = c.bileteEmise.size();
		fout.write((char*)&size, sizeof(size));
		for (auto bilet : c.bileteEmise)
		{
			fout << *bilet; 		}

		return fout;
	}

	void save() {
		ofstream fout(fisierBinar, std::ios::binary);
		fout << *this;
		fout.close();
	}

	void load() {
		ifstream fin(fisierBinar, std::ios::binary);
				if (fin.good()) { 			fin >> *this;
		}
		fin.close();
	}

			
	void saveBilet(Bilet* b) {
		ofstream fout(fisierTextBileteEmise, std::ios::app);
				b->toFile(fout);
		fout.close();
	}

	void emiteBilet() { 				cout << "Selectati datele pentru a emite un nou bilet" << endl;
		RulareFilm* rulare = selecteazaRulare();
		if (rulare != nullptr) {
						Loc* loc = selecteazaLocInSala(rulare->getSala());
			if (loc != nullptr) {
				Bilet* biletNou = new Bilet(rulare->getFilm(), *loc);
								saveBilet(biletNou); 				bileteEmise.push_back(biletNou);
			}
			else {
				cout << "Nu am gasit niciun loc la acest film si aceasta sala." << endl;
			}
		}
	}

		void situatieLocuriLibere() {
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

	
	void situatieFilme() {
		
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

						
		void afisRulari() {
		cout << endl;
		cout << "Situatia rularilor de film:" << endl;

		if (filmeRulate.size() == 0) {
			cout << "In prezent nu exista rulari" << endl;
		}
		else {
			for (auto rulare : filmeRulate) {
				cout << (char*)*rulare << endl;
			}
		}

		cout << endl;
	}
	void afisSali() {
		cout << endl;
		cout << "Situatia salilor:" << endl;

		if (sali.size() == 0) {
			cout << "In prezent nu exista sali" << endl;
		}
		else {
			for (auto sala : sali) {
				cout << (char*)*sala << endl;
			}
		}

		cout << endl;
	}
	void afisBilete() {
		cout << endl;
		cout << "Situatia biletelor:" << endl;

		if (bileteEmise.size() == 0) {
			cout << "In prezent nu exista bilete" << endl;
		}
		else {
			for (auto bilet : bileteEmise) {
				cout << (char*)*bilet << endl;
			}
		}

		cout << endl;
	}

	void CRUD() {
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
								RulareFilm rulare;
				cin >> rulare;
				add(rulare);
				afisRulari();
			}
			else if (option == 2) {
								cout << "Selectati o rulare de film pentru a o modifica." << endl;
				RulareFilm* rulare = selecteazaRulare();
				if (rulare != nullptr) {
					cin >> *rulare;
				}
				afisRulari();
			}
			else if (option == 3) {
				cout << "Selectati o rulare de film pentru a o sterge." << endl;
				RulareFilm* rulare = selecteazaRulare();
				filmeRulate.erase(rulare); 				afisRulari();
			}
			else if (option == 4) {
								Sala sala;
				cin >> sala;
				add(sala); 				afisSali();
			}
			else if (option == 5) {
								cout << "Selectati o sala pentru a o modifica." << endl;
				Sala* sala = selecteazaSala();
				if (sala != nullptr) {
					cin >> *sala;
				}
				afisSali();
			}
			else if (option == 6) {
				cout << "Selectati o sala pentru a o sterge." << endl;
				Sala* sala = selecteazaSala();
								for (int i = 0; i < sali.size(); i++) {
					if (sali[i] == sala) {
						sali.erase(sali.begin() + i);
						break;
					}
				}
				afisSali();
			}
			else if (option == 7) {
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
				afisBilete();
			}
			else if (option == 8) {
								cout << "Selectati un bilet pentru a-l modifica." << endl;
				Bilet* bilet = selecteazaBilet();
				if (bilet != nullptr) {
					cin >> *bilet;
				}
				afisBilete();
			}
			else if (option == 9) {
								cout << "Selectati un bilet pentru a-l sterge." << endl;
				Bilet* bilet = selecteazaBilet();
				for (int i = 0; i < bileteEmise.size(); i++) {
					if (bileteEmise[i] == bilet) {
						bileteEmise.erase(bileteEmise.begin() + i);
						break;
					}
				}
				afisBilete();
			}
		} while (option != 10);
	}

	
	const set<RulareFilm*>& getFilmeRulate() const {
		return filmeRulate;
	}

	void setFilmeRulate(const set<RulareFilm*>& filmeRulate) {
		Cinema::filmeRulate = filmeRulate;
	}

	const vector<Sala*>& getSali() const {
		return sali;
	}

	void setSali(const vector<Sala*>& sali) {
		Cinema::sali = sali;
	}

	const vector<Bilet*>& getBileteEmise() const {
		return bileteEmise;
	}

	void setBileteEmise(const vector<Bilet*>& bileteEmise) {
		Cinema::bileteEmise = bileteEmise;
	}

	const string& getFisierBinar() const {
		return fisierBinar;
	}

	void setFisierBinar(const string& fisierBinar) {
		Cinema::fisierBinar = fisierBinar;
	}

	const string& getFisierTextBileteEmise() const {
		return fisierTextBileteEmise;
	}

	void setFisierTextBileteEmise(const string& fisierTextBileteEmise) {
		Cinema::fisierTextBileteEmise = fisierTextBileteEmise;
	}
};

