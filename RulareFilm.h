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

	// gettere:
	Film getFilm() const {
		return film;
	}
};

