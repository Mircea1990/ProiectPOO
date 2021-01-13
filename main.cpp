#include <iostream>

using namespace std;

#include "Film.h"
#include "Sala.h"
#include "Loc.h"
#include "Client.h"
#include "Bilet.h"

//class LocClasa1 : public Loc {
//
//};
//
//class LocClasa2 : public Loc {
//
//};

int main() {
	//    Film f(101, "Matrix", 134);
	//    cout << f << endl;
	//    cout << (char*)f << endl;

	//    cin >> f;
	//    cout << f << endl;

		//Sala sala1(1, 60);
		//int locuriLibere[] = {0, 10, 11, 19},
		//        countSeats = 4;
		//Sala sala2(2, 20, countSeats, locuriLibere);

		//cout << sala1 << endl;
		//cout << (char *) sala1 << endl;
		//cout << sala2 << endl;
		//cout << (char *) sala2 << endl;

		//cin >> sala1;
		//cout << sala1 << endl;

	 //   Client client(1, "Robert Deronu");
	 //   cout << client << endl;
		//cout << (char*)client << endl;
	//
	//    cin >> client;
	//    cout << client << endl;

	 //   Loc loc(1, 9, Sala(1, 10));

	 //   cout << loc << endl;
		//cout << (char*)loc << endl;
	 //   cin >> loc;
	 //   cout << loc << endl;
		//cout << (char*)loc << endl;

	Bilet bilet(
		Film(1, "Matrix", 120),
		Loc(1, 10, Sala(1, 120))
	);

	cout << bilet << endl;
	cout << (char*)bilet << endl;

	cin >> bilet;
	cout << bilet << endl;
	cout << (char*)bilet << endl;

	return 0;
}
