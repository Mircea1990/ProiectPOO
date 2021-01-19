#pragma once

#include "util.h"
#include "our_iterator.h"

#include <cstring>
#include <fstream>
#include <iostream>

using namespace std;

class LocuriLibereSala {
private:
	int len;
	int *locuriLibere;

public:
		LocuriLibereSala() :len(0), locuriLibere(nullptr) {}
		LocuriLibereSala(const int len, const int* locuriLibere) {
		if (len > 0 && locuriLibere != nullptr) {
			this->locuriLibere = new int[len];
			for (int i = 0; i < len; i++)
			{
				this->locuriLibere[i] = locuriLibere[i];
			}
			this->len = len;
		}
		else {
			this->locuriLibere = nullptr;
			this->len = 0;
		}
	}
		LocuriLibereSala(const LocuriLibereSala& l)
		:LocuriLibereSala(l.len, l.locuriLibere)
	{

	}

	~LocuriLibereSala() {
		if (locuriLibere != nullptr) {
			delete locuriLibere;
		}
	}
	LocuriLibereSala operator=(const LocuriLibereSala& l) {
		if (l.len > 0 && l.locuriLibere != nullptr) {
			delete this->locuriLibere;
			this->locuriLibere = new int[l.len];
			for (int i = 0; i < l.len; i++)
			{
				this->locuriLibere[i] = l.locuriLibere[i];
			}
			this->len = l.len;
		}
		else {
			this->locuriLibere = nullptr;
			this->len = 0;
		}

		return *this;
	}

		our_iterator<int> begin() const { return our_iterator<int>(locuriLibere); }
	our_iterator<int> end() const { return our_iterator<int>(locuriLibere + len); }

		explicit operator char*() const {
		const int maxLen = 1000;
		char *s = new char[maxLen + 1];

		strcpy_s(s, maxLen, "Locuri libere [ ");
		for (auto& loc : *this) {
			strcat_s(s, maxLen, intToString(loc));
			strcat_s(s, maxLen, " ");
		}
		strcat_s(s, maxLen, "] ");

		return s;
	}

		friend ostream& operator<<(ostream& out, const LocuriLibereSala& l);
	friend istream& operator>>(istream& in, LocuriLibereSala& l);
		friend ofstream& operator<<(ofstream& fout, const LocuriLibereSala& l);
	friend ifstream& operator>>(ifstream& fin, LocuriLibereSala& l);

};

