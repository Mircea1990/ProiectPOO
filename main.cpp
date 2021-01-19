#include <iostream>

#include "Cinema.h"
#include "CinemaMenu.h"

#include <fstream>

using namespace std;



#include "our_iterator.h"
#include "LocuriLibereSala.h"

#include "Sala2.h"


int main() {
		int locuriLibere[] = { 3, 5, 12, 13, 1 },
		numarLocuriLibere = 5;
	Sala sala{ 2, 15, numarLocuriLibere, locuriLibere };
	Loc loc{ 101, 13, sala };
	Film film{ 101, "Matrix 3", 132 }, film2{ 102, "Jurassic", 200 };
	Bilet bilet{ film, loc };

	Cinema cinema;
	cinema.add(film, sala);
	cinema.add(film2, sala);

	CinemaMenu app(cinema);
	app.run();
}



