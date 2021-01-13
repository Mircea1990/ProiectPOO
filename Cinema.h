#pragma once

#include <fstream>

#include <vector>
#include <set>

#include "Film.h"
#include "Bilet.h"
#include "Client.h"
#include "Loc.h"
#include "Sala.h"
#include "RulareFilm.h"



class Cinema // DB
{
private:
	set<RulareFilm*> filmeRulate;
	vector<Sala*> sali;
	vector<Bilet*> bileteEmise;

	// locurile sunt folosite doar in bileteEmise, pentru a accesa usor informatia
	//	Deci cream Locuri doar la emitere bileteEmise.
	string fisierBinar;
	string fisierTextBileteEmise;

public:
	void save() {
		ofstream fout(fisierBinar, std::ios::binary);
		fout << *this;
	}

	void load() {
		ifstream fin(fisierBinar, std::ios::binary);
		fin >> *this;
	}

	void saveBilet(Bilet * b) {
		ofstream fout(fisierTextBileteEmise, std::ios::app);

		// << was used for binary files, so we used a method:
		b->toFile(fout);
	}

	friend ifstream& operator>>(ifstream& in, Cinema& c) {
		// delete date:
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
		
		in >> size;
		for (int i = 0; i < size; i++)
		{
			RulareFilm* rulare = new RulareFilm();
			in >> *rulare;
			c.filmeRulate.insert(rulare);
		}

		in >> size;
		for (int i = 0; i < size; i++)
		{
			Sala* sala = new Sala();
			in >> *sala;
			c.sali.push_back(sala);
		}

		in >> size;
		for (int i = 0; i < size; i++)
		{
			Bilet* bilet = new Bilet();
			in >> *bilet;
			c.bileteEmise.push_back(bilet);
		}
	}
	friend ofstream& operator<<(ofstream& out, Cinema& c) {
		out << c.filmeRulate.size();
		for (auto film : c.filmeRulate)
		{
			out << *film;
		}
		out << c.sali.size();
		for (auto sala : sali)
		{
			out << *sala;
		}
		out << c.bileteEmise.size();
		for (auto bilet : bilete)
		{
			out << *bilet;
		}
	}

	~Cinema() {
		for (auto film : filmeRulate) {
			delete film;
		}
	}

	Bilet emiteBilet() {
		// select Film rulat, Sala, Loc
		RulareFilm *chosenFilm;
		Sala *chosenSala;
		// afiseaza filme:
		int index = 0, filmIndex, salaIndex;
		for (auto filmRulat : filmeRulate) {
			cout << index << ": " << filmRulat << endl;
			index++;
		}
		// selecteaza film:
		do { 
			cout << "Selecteaza numar film: ";
			cin >> filmIndex;
		} while (filmIndex < 0 || filmIndex >= index);

		index = 0;
		for (auto filmRulat : filmeRulate) {
			if (index = filmIndex) {
				chosenFilm = filmRulat;
				break;
			}
			index++;
		}


		// afiseaza sali:
		index = 0;
		for (auto sala : sali) {
			cout << index << ": " << sala << endl;
			index++;
		}
		// selecteaza sala:
		do {
			cout << "Selecteaza numar film: ";
			cin >> salaIndex;
		} while (salaIndex < 0 || salaIndex >= index);

		index = 0;
		for (auto sala : sali) {
			if (index = salaIndex) {
				chosenSala = sala;
				break;
			}
			index++;
		}

		// afiseaza locuri (din sala)
		chosenSala->showFreeSeats(cout);
		// selecteaza loc
		int numarLoc;
		do {
			cout << "Alege locul liber: ";
			cin >> numarLoc;
		} while (! chosenSala->containsLoc(numarLoc));
		// creeaza locul pentru bilet, apoi biletul:
		Loc locNou(0, numarLoc, *chosenSala);
		Bilet* biletNou = new Bilet(chosenFilm->getFilm(), locNou);
		// salveaza locul in Cinema si pune-l in fisierul text pt printare:
		saveBilet(biletNou);
		bileteEmise.push_back(biletNou);
	}
};

