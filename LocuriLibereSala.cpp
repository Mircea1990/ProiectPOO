#include "LocuriLibereSala.h"
#include <iostream>
#include <fstream>

using namespace std;

ostream & operator<<(ostream & out, const LocuriLibereSala & l)
{
	out << "Datele LocuriLibereSala:" << endl;

	out << "Locuri libere: ";
	for (auto& loc : l) {
		out << loc << ' ';
	}
	out << endl;

	return out;
}

istream & operator>>(istream & in, LocuriLibereSala & l)
{
	cout << "Introduceti datele LocuriLibereSala." << endl;

	cout << "Introduceti numar locuri libere: ";
	int numar;
	in >> numar;

	if (numar > 0) {
		l.locuriLibere = new int[numar];
		cout << "Introduceti locurile: ";
		for (int i = 0; i < numar; i++)
		{
			in >> l.locuriLibere[i];
		}
	}

	return in;
}

ofstream & operator<<(ofstream & fout, const LocuriLibereSala & l)
{
	if (l.len <= 0 || l.locuriLibere == nullptr) {
		int len = 0;
		fout.write((char*)&len, sizeof(len));
	}
	else {
		fout.write((char*)&l.len, sizeof(l.len));
		fout.write((char*)l.locuriLibere, l.len * sizeof(l.locuriLibere[0]));
	}
	return fout;
}

ifstream & operator>>(ifstream& fin, LocuriLibereSala & l) {
	int len;

	fin.read((char*)&len, sizeof(len));

	delete l.locuriLibere;
	if (len > 0) {
		l.len = len;
		l.locuriLibere = new int[len];
		fin.read((char*)l.locuriLibere, len * sizeof(l.locuriLibere[0]));
	}
	else {
		l.len = 0;
		l.locuriLibere = nullptr;
	}
	return fin;
}
