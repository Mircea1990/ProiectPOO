#ifndef BILETE_FILM_H
#define BILETE_FILM_H

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
        Film();
        Film(int id, const char *nume, int minutes);

        Film(const Film &f);
    ~Film();
    Film operator=(const Film& f);

        friend istream &operator>>(istream &in, Film &f);

    friend ostream &operator<<(ostream &out, const Film &f);

        int operator[](int index) {
        return 0;
    }

    	Film operator+(int extraMinutes);

        Film operator++();

    Film operator++(int);

        operator char *() const;
    	Film operator! ();

        bool operator<(const Film& f);
    bool operator<=(const Film& f);
        bool operator==(const Film& f);

    
    int getMinutes() const;

	string getNume() const;

		void toFile(ofstream& fout) {
		fout << "Numele filmului: " << nume << endl;
		fout << "Lungimea filmului: " << minutes << " minute" << endl;
	}

	friend ofstream& operator<<(ofstream& fout, const Film& f) {
	            fout.write((char*)&f.id, sizeof(f.id));

        if (f.nume != nullptr) {
			size_t numChars = strlen(f.nume);
            fout.write((char*)&numChars, sizeof(size_t));
			fout.write(f.nume, numChars * sizeof(char));
        } else {
			size_t numChars = 0;
            fout.write((char*)&numChars, sizeof(size_t));         }

        fout.write((char*)&f.minutes, sizeof(f.minutes));

        return fout;
	}
    friend ifstream& operator>>(ifstream& fin, Film& f) {
        fin.read((char*)&f.id, sizeof(f.id));

        size_t numChars;
        fin.read((char*)&numChars, sizeof(size_t));
                delete []f.nume;
                if (numChars > 0) {
			f.nume = new char[numChars + 1];
            fin.read(f.nume, numChars * sizeof(char)); 			f.nume[numChars] = 0;         } else {
            f.nume = new char[2];
            strcpy_s(f.nume, 2, "");
        }
        fin.read((char*)&f.minutes, sizeof(f.minutes));

        return fin;
    }
};


#endif 