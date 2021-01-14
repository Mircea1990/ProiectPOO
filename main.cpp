#include <iostream>

#include "Cinema.h"
#include "CinemaMenu.h"

#include <fstream>

using namespace std;

int main()
{
	//CINEMA, testam scrierea si citirea dintr-un fisier binar
	int locuriLibere[] = { 3, 5, 12, 13, 1 },
		numarLocuriLibere = 5;
	Sala sala{ 2, 15, numarLocuriLibere, locuriLibere };
	Loc loc{ 101, 13, sala };
	Film film{ 101, "Matrix 3", 132 }, film2{ 102, "Jurassic", 200 };
	Bilet bilet{ film, loc };

	Cinema cinema;
	cinema.add(film, sala);
	cinema.add(film2, sala);

	// TESTAM pentru un cinema afisarea din clasa CinemaMenu:

	CinemaMenu app(cinema); 
	app.run();

	//// try saving the cinema state:

	//ofstream fout("file.bin", ios::out | ios::binary);
	//fout << cinema;
	//fout.close();

	//ifstream fin("file.bin", ios::in | ios::binary);
	//Cinema copieCinema;

	//fin >> copieCinema;
	//fin.close();

	//cout << (char*)cinema << endl;
	//cout << (char*)copieCinema << endl;

	//// BILET
	//ofstream fout("file.bin", ios::out | ios::binary);
	//int locuriLibere[] = { 3, 5, 12, 13, 1 },
	//	numarLocuriLibere = 5;
	//Sala sala{ 2, 15, numarLocuriLibere, locuriLibere };
	//Loc loc{ 101, 13, sala };
	//Film film{ 101, "Matrix 3", 132 };
	//Bilet bilet{ film, loc };

	//fout << bilet;
	//fout.close();

	//ifstream fin("file.bin", ios::in | ios::binary);
	//Bilet copie;

	//fin >> copie;
	//fin.close();

	//cout << (char*)bilet << endl;
	//cout << (char*)copie << endl;

	//// LOC
	//ofstream fout("file.bin", ios::out | ios::binary);
	//int locuriLibere[] = { 3, 5, 12, 13, 1 },
	//	numarLocuriLibere = 5;
	//Sala sala{ 2, 15, numarLocuriLibere, locuriLibere };
	//Loc loc{ 101, 13, sala };

	//fout << loc;
	//fout.close();

	//ifstream fin("file.bin", ios::in | ios::binary);
	//Loc copie;

	//fin >> copie;
	//fin.close();

	//cout << (char*)loc << endl;
	//cout << (char*)copie << endl;

	//// RULARE FILM
	//ofstream fout("file.bin", ios::out | ios::binary);
	//int locuriLibere[] = { 3, 5, 12, 13, 1 },
	//	numarLocuriLibere = 5;
	//Sala sala{ 2, 15, numarLocuriLibere, locuriLibere };
	//RulareFilm rulare(Film(1, "Matrix 1", 121), sala);

	//fout << rulare;
	//fout.close();

	//ifstream fin("file.bin", ios::in | ios::binary);
	//RulareFilm copie;

	//fin >> copie;
	//fin.close();

	//cout << (char*) rulare << endl;
	//cout << (char*) copie << endl;

	//// SALA:
	//ofstream fout("file.bin", ios::out | ios::binary);
	//int locuriLibere[] = { 3, 5, 12, 13, 1 },
	//	numarLocuriLibere = 5;
	//Sala sala{ 2, 15, numarLocuriLibere, locuriLibere };

	//fout << sala;
	//fout.close();

	//ifstream fin("file.bin", ios::in | ios::binary);
	//Sala copie;

	//fin >> copie;
	//fin.close();


	//cout << (char*) sala << endl;
	//cout << (char*) copie << endl;

	// FILM:
	/*ofstream fout("file.bin", ios::out | ios::binary);
	Film film(1, "Matrix 1", 121);

	fout << film;
	fout.close();

	ifstream fin("file.bin", ios::in | ios::binary);
	Film copie;

	fin >> copie;
	fin.close();

	cout << (char*) film << endl;
	cout << (char*) copie << endl;*/

	// remove files:

	return 0;
}

//#include "Film.h"
//#include "Sala.h"
//#include "Loc.h"
//#include "Client.h"
//#include "Bilet.h"
//using namespace std;
//int main() {
//	//    Film f(101, "Matrix", 134);
//	//    cout << f << endl;
//	//    cout << (char*)f << endl;
//
//	//    cin >> f;
//	//    cout << f << endl;
//
//		//Sala sala1(1, 60);
//		//int locuriLibere[] = {0, 10, 11, 19},
//		//        countSeats = 4;
//		//Sala sala2(2, 20, countSeats, locuriLibere);
//
//		//cout << sala1 << endl;
//		//cout << (char *) sala1 << endl;
//		//cout << sala2 << endl;
//		//cout << (char *) sala2 << endl;
//
//		//cin >> sala1;
//		//cout << sala1 << endl;
//
//	 //   Client client(1, "Robert Deronu");
//	 //   cout << client << endl;
//		//cout << (char*)client << endl;
//	//
//	//    cin >> client;
//	//    cout << client << endl;
//
//	 //   Loc loc(1, 9, Sala(1, 10));
//
//	 //   cout << loc << endl;
//		//cout << (char*)loc << endl;
//	 //   cin >> loc;
//	 //   cout << loc << endl;
//		//cout << (char*)loc << endl;
//
//	Bilet bilet(
//		Film(1, "Matrix", 120),
//		Loc(1, 10, Sala(1, 120))
//	);
//
//	cout << bilet << endl;
//	cout << (char*)bilet << endl;
//
//	cin >> bilet;
//	cout << bilet << endl;
//	cout << (char*)bilet << endl;
//
//	return 0;
//}
