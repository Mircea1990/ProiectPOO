

#include <string>

using namespace std;

class Client {
private:
    int id;
    string nume;
public:
    // constructor fara parametri
    Client() : id(-1) {}

    // constructor cu parametri
    Client(int id, string nume);

    // operatori >> si <<
    friend istream &operator>>(istream &in, Client &f);

    friend ostream &operator<<(ostream &out, const Client &f);

    // []
    int operator[](int index);

    // +/-/*/\/
    Client operator+(int i);

    // ++ sau -- cu cele doua forme
    Client operator++();

    Client operator++(int);

    // cast catre un tip explicit sau implicit
    explicit operator char *() const;

    // !
    Client operator!();

    // </>/...
    bool operator<(const Client &f);

    bool operator<=(const Client &f);

    // ==
    bool operator==(const Client &f);

    // gettere si settere (toti setter-ii vor contine validari)


};


