#include <cstring>
#include "Film.h"
#include "util.h"

Film::Film(const Film &f) : Film(f.id, f.nume, f.minutes) {}

Film::Film(int id, const char *nume, int minutes) {
    this->id = id;

    if (nume != nullptr) {
        this->nume = new char[strlen(nume) + 1];
        strcpy_s(this->nume, strlen(nume) + 1, nume);
    } else {
        this->nume = nullptr;
    }

    this->minutes = minutes;
}

istream &operator>>(istream &in, Film &f) {
    cout << "Introduceti datele filmului." << endl;

    cout << "Id: ";
    in >> f.id;

    cout << "Nume: ";
    char nume[1000];
	in.get();
    in.getline(nume, 1000);
    if (f.nume) {
        delete[] f.nume;
    }
    f.nume = new char[strlen(nume) + 1];
    strcpy_s(f.nume, strlen(nume) + 1, nume);

    cout << "Numar minute: ";
    in >> f.minutes;

    return in;
}

ostream &operator<<(ostream &out, const Film &f) {
    out << "Filmul:" << endl;

    out << "Id: " << f.id << endl;
    out << "Nume: " << f.nume << endl;
    out << "Numar minute: " << f.minutes << endl;

    return out;
}

Film Film::operator+(int extraMinutes)
{
	Film nou = *this;
	nou.minutes += extraMinutes;
	return nou;
}

Film Film::operator++() {
    this->minutes++;
    return *this;
}

Film Film::operator++(int) {
    Film neincrementat = *this;
    this->minutes++;
    return neincrementat;
}

Film::operator char *() const {
	const int maxLen = 1000;
    char *str = new char[maxLen];
    strcpy_s(str, maxLen, "Film{id=");
    strcat_s(str, maxLen, intToString(id));

    strcat_s(str, maxLen, ",nume=\"");
    strcat_s(str, maxLen, this->nume);
    strcat_s(str, maxLen, "\"");

    strcat_s(str, maxLen, ",minutes=");
    strcat_s(str, maxLen, intToString(this->minutes));

    strcat_s(str, maxLen,  "}");

	return str; // return the entire object as a char*
}

Film Film::operator!()
{
	return *this;
}

bool Film::operator<(const Film &f) {
    return this->minutes < f.minutes;
}

bool Film::operator<=(const Film &f) {
    return *this < f || this->minutes == f.minutes;
}

bool Film::operator==(const Film &f) {
    return this->id == f.id &&
           strcmp(this->nume, f.nume) == 0 && // TODO poate da eroare la null?
           this->minutes == f.minutes;
}

Film Film::operator=(const Film &f) {
    this->id = f.id;

    if (this->nume) {
        delete[]this->nume;
    }
    if (f.nume != nullptr) {
        this->nume = new char[strlen(f.nume) + 1];
        strcpy_s(this->nume, strlen(f.nume) + 1, f.nume);
    } else {
        this->nume = nullptr;
    }

    this->minutes = f.minutes;

    return *this;
}

Film::~Film() {
    if (this->nume != nullptr) {
        delete[] this->nume;
    }
}

int Film::getMinutes() {
    return this->minutes;
}

