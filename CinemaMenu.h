#pragma once

#include "Cinema.h"

class CinemaMenu : public Cinema {
private:
	/// membrii mosteniti din Cinema:
	using Cinema::filmeRulate;
	using Cinema::sali;
	using Cinema::bileteEmise;
	using Cinema::fisierBinar;
	using Cinema::fisierTextBileteEmise;
	bool loadOnRun; // true daca Cinema ar trebui sa citeasca datele initiale dintr-un fisier binar si false altfel
public:
	/// METODE mostenite din Cinema
	// Comenzile implementate in Cinema:
	using Cinema::emiteBilet;
	using Cinema::situatieLocuriLibere;
	using Cinema::situatieFilme;
	using Cinema::CRUD;
	// Pentru salvarea tuturor datelor din cinema pe disc (fisiere binare:
	using Cinema::save;
	using Cinema::load;

	CinemaMenu() : Cinema() {
		loadOnRun = true;
	}

	CinemaMenu(const Cinema &cinema)
		: Cinema(
			cinema.filmeRulate,
			cinema.sali,
			cinema.bileteEmise,
			cinema.fisierBinar,
			cinema.fisierTextBileteEmise
		) {
		loadOnRun = false;
	}

	void showMenu() {
		cout << "1. Emite bilet" << endl;
		cout << "2. Situatie locuri libere" << endl;
		cout << "3. Situatie filme" << endl;
		cout << "4. Meniu CRUD" << endl;
		cout << "5. Exit" << endl;
	}

	void run() {
		int option;
		bool isRunning = true;

		// load the Cinema:
		if (loadOnRun) {
			load();
		}

		while (isRunning) {
			showMenu();

			cout << "> ";
			cin >> option;

			switch (option) {
			case 1:
				emiteBilet();
				save(); // save the Cinema data, la locatie din campul fisierBinar
				break;
			case 2:
				situatieLocuriLibere();
				break;
			case 3:
				situatieFilme();
				break;
			case 4:
				CRUD();
				save(); // save the Cinema data, la locatie din campul fisierBinar
				break;
			case 5:
				isRunning = false;
				break;
			default:
				continue; // continue while to the next step
			}
		}
	}
};


