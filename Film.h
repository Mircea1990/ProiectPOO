#pragma once

#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

class Film {
private:
    int id;
    char *nume;
    int minutes;
public:
    // constructor fara parametri
    Film();
    // constructor cu parametri
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

    int getMinutes() const;

	string getNume() const;

	// Etapa 2:
	void toFile(ofstream& fout) {
		fout << "Numele filmului: " << nume << endl;
		fout << "Lungimea filmului: " << minutes << " minute" << endl;
	}

	friend ofstream& operator<<(ofstream& fout, const Film& f) {
	    // id, nume, minutes
        fout.write((char*)&f.id, sizeof(f.id));

        if (f.nume != nullptr) {
			size_t numChars = strlen(f.nume);
            fout.write((char*)&numChars, sizeof(size_t));
			fout.write(f.nume, numChars * sizeof(char));
        } else {
			size_t numChars = 0;
            fout.write((char*)&numChars, sizeof(size_t)); // size_t is same type as strlen() return-type
        }

        fout.write((char*)&f.minutes, sizeof(f.minutes));

        return fout;
	}
    friend ifstream& operator>>(ifstream& fin, Film& f) {
        fin.read((char*)&f.id, sizeof(f.id));

        size_t numChars;
        fin.read((char*)&numChars, sizeof(size_t));
        // deallocate f.nume
        delete []f.nume;
        // reallocate and read new value
        if (numChars > 0) {
			f.nume = new char[numChars + 1];
            fin.read(f.nume, numChars * sizeof(char)); // read all numChars characters of the string
			f.nume[numChars] = 0; // end of char*
        } else {
            f.nume = new char[2];
            strcpy_s(f.nume, 2, "");
        }
        fin.read((char*)&f.minutes, sizeof(f.minutes));

        return fin;
    }
};

