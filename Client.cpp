#include <iostream>
#include <string>

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
    in.get(); // de folosit inainte de a citi un rand
    getline(in, f.nume);

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
    // TODO change?
}

Client Client::operator+(int i)
{
	return *this;
}

Client Client::operator++() {
    // TODO change?
    return *this;
}

Client Client::operator++(int) {
    // TODO change?
    return *this;
}

Client::operator char *() const {
	const int maxLen = 1000;
	char *s = new char[maxLen + 1];

	strcpy_s(s, maxLen, "Client { id=");
	strcat_s(s, maxLen, intToString(this->id));

	strcat_s(s, maxLen, ", nume=\"");
	strcat_s(s, maxLen, &this->nume[0]); // use the char array from the string, by passing the address of the first char
	strcat_s(s, maxLen, "\"");

	strcat_s(s, maxLen, " }");


	return s; // TODO return a char* for the whole object
}

Client Client::operator!() {
    return *this; // TODO change?
}

bool Client::operator<(const Client &f) {
    return this->nume < f.nume;
}

bool Client::operator<=(const Client &f) {
    return this->nume <= f.nume;
}

bool Client::operator==(const Client &f) {
    return this->nume == f.nume && this->id == f.id;
}

// gettere si settere (toti setter-ii vor contine validari)

