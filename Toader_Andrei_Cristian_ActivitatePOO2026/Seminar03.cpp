#include <iostream>
using namespace std;

class Telefon {
public:
	float rezolutie;
	float memorie;
	string model;
	char* producator;
	float pret;
	int nrAplicatii;
	float* memorieAplicatii;

	Telefon()
	{
		this->rezolutie = 5.3;
		this->memorie = 128;
		this->model = "iPhone 17";
		this->producator = new char[strlen("Apple") + 1];
		strcpy_s(producator, strlen("Apple") + 1, "Apple");
		this->pret = 4000;
		this->nrAplicatii = 5;
		this->memorieAplicatii = new float[this->nrAplicatii];
		this->memorieAplicatii[0] = 2;
		this->memorieAplicatii[1] = 3;
		this->memorieAplicatii[2] = 1.4;
		this->memorieAplicatii[3] = 1.6;
		this->memorieAplicatii[4] = 2.4;
	}
};

void main() {

}