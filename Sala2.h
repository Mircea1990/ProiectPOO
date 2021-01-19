#pragma once

#include "LocuriLibereSala.h"
#include "ISala.h"
#include "our_iterator.h"

#include <iostream>
#include <fstream>

using namespace std;

class Sala2 : public ISala<int> {
private:
	int id;
int numarLocuri; 	using ISala::locuriLibere; public:
	Sala2();

	Sala2(int id, int numarLocuri);

	Sala2(int id, int numarLocuri, int numarLocuriLibere, const int* locuriLibere);

	Sala2(int id, int numarLocuri, const LocuriLibereSala& l);

	friend istream& operator>>(istream& in, Sala2& f);

	friend ostream& operator<<(ostream& out, const Sala2& f);

	int operator[](int index) {
		return 0;
	}

	Sala2 operator+(int extraMinutes);

	Sala2 operator++();

	Sala2 operator++(int);

	explicit operator char* () const;
	Sala2 operator!();

	bool operator<(const Sala2& f);

	bool operator<=(const Sala2& f);

	bool operator==(const Sala2& f);


	int getId() const {
		return id;
	}
	int getNumarLocuri() const {
		return numarLocuri;
	}

	void toFile(ofstream& fout) {
		fout << "Id Sala: " << id << endl;
	}


	virtual our_iterator<int> begin() const
	{
		return locuriLibere.begin();
	}
	virtual our_iterator<int> end() const
	{
		return locuriLibere.end();
	}
};


