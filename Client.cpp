#include <iostream>
#include <string>

#include <cstring>


#include "Client.h"
#include "util.h"

using namespace std;

Client::Client(int id, string nume) : id(id), nume(nume) {

}

istream &operator>>(istream &in, Client &f) {
    cout << "Introduceti Clientul:" << endl;

    cout << "Id: ";
    in >> f.id;

    cout << "Nume: ";
    in.get();     getline(in, f.nume);

    return in;
}

ostream &operator<<(ostream &out, const Client &f) {
    cout << "Clientul" << endl;

    cout << "Id: " << f.id << endl;
    cout << "Nume: " << f.nume;

    return out;
}

int Client::operator[](int index) {
    return 0;
    }

Client Client::operator+(int i)
{
	return *this;
}

Client Client::operator++() {
        return *this;
}

Client Client::operator++(int) {
        return *this;
}

Client::operator char *() const {
	const int maxLen = 1000;
	char *s = new char[maxLen + 1];

	strcpy_s(s, maxLen, "Client { id=");
	strcat_s(s, maxLen, intToString(this->id));

	strcat_s(s, maxLen, ", nume=\"");
	strcat_s(s, maxLen, &this->nume[0]); 	strcat_s(s, maxLen, "\"");

	strcat_s(s, maxLen, " }");


	return s; }

Client Client::operator!() {
    return *this; }

bool Client::operator<(const Client &f) {
    return this->nume < f.nume;
}

bool Client::operator<=(const Client &f) {
    return this->nume <= f.nume;
}

bool Client::operator==(const Client &f) {
    return this->nume == f.nume && this->id == f.id;
}


