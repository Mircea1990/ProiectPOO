#include <cstring>
#include "Bilet.h"

Bilet::Bilet(const Film &film, const Loc &loc) : film(film), loc(loc) {}

ostream &operator<<(ostream &out, const Bilet &b) {
    out << "Biletul are urmatoarele rezervari:" << endl;

    out << "Filmul este" << endl;
    out << b.film;

    out << "Locul este" << endl;
    out << b.loc;

    return out;
}

istream &operator>>(istream &in, Bilet &b) {
    cout << "Introduceti filmul" << endl;
    in >> b.film;

    cout << "Introduceti locul" << endl;
    in >> b.loc;

    return in;
}

int Bilet::operator[](int index) {
    return 0; }

Bilet Bilet::operator+(int i)
{
	return *this;
}

Bilet Bilet::operator++() {
        return *this;
}

Bilet Bilet::operator++(int) {
    Bilet old = *this;
        return old;
}

Bilet Bilet::operator!() {
    return *this; }

bool Bilet::operator<=(int minutes) {
    return this->film.getMinutes() < minutes;
}

bool Bilet::operator==(const Bilet &b) {
    return this->film == b.film &&
           this->loc == b.loc;
}

Bilet::operator char *() {
	const int maxLen = 1000;
    char *s = new char[maxLen];
    strcpy_s(s, maxLen, "Bilet {");
    strcat_s(s, maxLen, (char *) this->film);
    strcat_s(s, maxLen, (char *) this->loc);
	strcat_s(s, maxLen, " }");
    return s;
}

int Bilet::bileteProcesate = 0;