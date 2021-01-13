#include "Loc.h"
#include "Sala.h"
#include "util.h"

Loc::Loc(int id, int numar, Sala sala) : numar(numar), sala(sala) {
    this->id = id;
}

istream &operator>>(istream &in, Loc &f) {
    cout << "Introduceti Locul:" << endl;

    cout << "Id: ";
    in >> f.id;

    cout << "Numar: ";
    // pentru initializarea dupa constructor a const int numar:
    int *numar = const_cast<int *>(&f.numar);
    int numarNou;
    in >> numarNou;
    *numar = numarNou;

    cout << "Sala este" << endl;
    in >> f.sala;

    return in;
}

ostream &operator<<(ostream &out, const Loc &f) {
    cout << "Locul:" << endl;

    out << "Id: " << f.id << endl;
    out << "Numar: " << f.numar << endl;
    out << "Sala este" << endl;
    cout << f.sala;

    return out;
}

int Loc::operator[](int index) {
    return 0;// TODO change?
}

Loc Loc::operator+(int i)
{
	return *this;
}

Loc Loc::operator++() {
    // TODO change?
    return *this;
}

Loc Loc::operator++(int) {
    // TODO change?
    return *this;
}

Loc::operator char *() const { // explicit
	const int maxLen = 1000;
	char *str = new char[maxLen];
	strcpy_s(str, maxLen, "Loc { id=");
	strcat_s(str, maxLen, intToString(id));

	strcat_s(str, maxLen, ", numar=\"");
	strcat_s(str, maxLen, intToString(this->numar));
	strcat_s(str, maxLen, "\"");

	strcat_s(str, maxLen, ", sala=");
	strcat_s(str, maxLen, (char*) this->sala);

	strcat_s(str, maxLen, " }");

	return str; // return the entire object as a char*
}

Loc Loc::operator!()
{
	return *this;
}

bool Loc::operator<(const Loc &f) {
    return this->numar < f.numar;
}

bool Loc::operator<=(const Loc &f) {
    return this->numar <= f.numar;
}

bool Loc::operator==(const Loc &f) {
    return this->id == f.id &&
           this->numar == f.numar &&
           this->sala == f.sala;
}

// gettere si settere (toti setter-ii vor contine validari)