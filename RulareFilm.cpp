#include "RulareFilm.h"

istream & operator>>(istream & in, RulareFilm & r)
{
	cout << "Introduceti filmul rulat:" << endl;
	cin >> r.film;

	cout << "Introduceti sala unde este rulat filmul:" << endl;
	cin >> r.sala;

	return in;
}

ostream & operator<<(ostream & out, const RulareFilm & r)
{
	out << "Filmul rulat este" << endl;
	out << r.film;

	out << "Sala este" << endl;
	out << r.sala;

	return out;
}
