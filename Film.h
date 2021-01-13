#ifndef BILETE_FILM_H
#define BILETE_FILM_H

#include <iostream>
#include <fstream>

using namespace std;

class Film {
private:
    int id;
    char *nume;
    int minutes;
public:
    // constructur cu parametri
    Film(int id, const char *nume, int minutes);

    // pt cele care contin valori alocate dinamic, obligatoriu CC, ~ si =
    Film(const Film &f);
    ~Film();
    Film operator=(const Film& f);

    // operatori >> si <<
    friend istream &operator>>(istream &in, Film &f);

    friend ostream &operator<<(ostream &out, const Film &f);

    // []
    int operator[](int index) {
        return 0;
    }

    // +/-/*/\/
	Film operator+(int extraMinutes);

    // ++ sau -- cu cele doua forme
    Film operator++();

    Film operator++(int);

    // cast catre un tip explicit sau implicit
    operator char *() const;
    // !
	Film operator! ();

    // </>/...
    bool operator<(const Film& f);
    bool operator<=(const Film& f);
    // ==
    bool operator==(const Film& f);

    // gettere si settere (toti setter-ii vor contine validari)

    int getMinutes();

	// Etapa 2:
	void toFile(ofstream& fout) {
		fout << "Numele filmului: " << nume << endl;
		fout << "Lungimea filmului: " << minutes << " minute" << endl;
	}
};


#endif // BILETE_FILM_H
