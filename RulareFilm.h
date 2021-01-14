#pragma once
#include "Film.h"
#include "Sala.h"

class RulareFilm
{
private:
	Film film;
	Sala sala;

public:
	RulareFilm() : film(Film()), sala(Sala()) {}
	RulareFilm(Film film, Sala sala) : film(film), sala(sala) {}
	
	// operatori de flux pentru consola:

	friend istream& operator>>(istream& in, RulareFilm& r);
	friend ostream& operator<<(ostream& out, const RulareFilm& r);
	// operator de cast:

	explicit operator char*() {
		const int maxLen = 1000;
		char *s = new char[maxLen + 1];

		strcpy_s(s, maxLen, "RulareFilm { ");

		strcat_s(s, maxLen, "film=");
		strcat_s(s, maxLen, (char*)film);

		strcat_s(s, maxLen, ", sala=");
		strcat_s(s, maxLen, (char*)sala);
		strcat_s(s, maxLen, " }");

		return s;
	}

	// gettere:
	Film getFilm() const {
		return film;
	}
	Sala getSala() const {
		return sala;
	}
	// operator << si >> pentru scriere si citire din fisier binar

	friend ofstream& operator<<(ofstream& fout, const RulareFilm& r) {
		fout << r.film << r.sala; // supraincarcati in Film si Sala

		return fout;
	}

	friend ifstream& operator>>(ifstream& fin, RulareFilm& r) {
		fin >> r.film >> r.sala; // supraincarcati in Film si Sala

		return fin;
	}


};

