#include <iostream>
using namespace std;

struct Ghiozdan {
	float lungime;
	int nrBuzunare;
	bool laptop;
	char* producator;
};

Ghiozdan citireGhiozdan()
{
	char numeProducator[10];
	Ghiozdan g;
	cout << "Lungime: ";
	cin >> g.lungime;
	cout << "Buzunare: ";
	cin >> g.nrBuzunare;
	cout << "Pentru laptop? (0/1): ";
	cin >> g.laptop;
	cout << "Producator: ";
	cin >> numeProducator;
	g.producator = new char[strlen(numeProducator) + 1];
	strcpy_s(g.producator, strlen(numeProducator) + 1, numeProducator);
	return g;

}

void afisareGhiozdan(Ghiozdan g)
{
	cout << "lungime:" << g.lungime << endl;
	cout << "buzunare:" << g.nrBuzunare << endl;
	cout << "laptop:" << g.laptop << endl;
	cout << "nume producator:" << g.producator << endl;
}

void modificareLungime(Ghiozdan* g, float lungimeNoua)
{
	(*g).lungime = lungimeNoua;
}

void main() {
	Ghiozdan g = citireGhiozdan();
	afisareGhiozdan(g);
	modificareLungime(&g, 12);
	afisareGhiozdan(g);
}