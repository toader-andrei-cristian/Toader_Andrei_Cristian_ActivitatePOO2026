#include <iostream>
using namespace std;

struct Ghiozdan {
	float lungime;
	int nrBuzunare;
	bool laptop;
	char *producator;
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

void main() {
	
}