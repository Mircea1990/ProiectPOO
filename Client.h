#ifndef BILETE_CLIENT_H
#define BILETE_CLIENT_H

#include <string>

using namespace std;

class Client {
private:
    int id;
    string nume;
public:
        Client() : id(-1) {}

        Client(int id, string nume);

        friend istream &operator>>(istream &in, Client &f);

    friend ostream &operator<<(ostream &out, const Client &f);

        int operator[](int index);

        Client operator+(int i);

        Client operator++();

    Client operator++(int);

        explicit operator char *() const;

        Client operator!();

        bool operator<(const Client &f);

    bool operator<=(const Client &f);

        bool operator==(const Client &f);

    

};


#endif 