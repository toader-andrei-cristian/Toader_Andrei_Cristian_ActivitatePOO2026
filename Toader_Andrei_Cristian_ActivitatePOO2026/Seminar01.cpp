#include <iostream>
using namespace std;

struct Colectie {
	char* denumire;
	char categorie;
	int nr_elemente;
	float pret;
	bool finit;
};

void afisareColectie(Colectie c)
{
	cout << c.categorie << " " << c.denumire << " " << c.nr_elemente << " " << c.pret << " " << c.finit << endl;
}

void main()
{
	std::cout << "Hello world!" << std::endl;
	Colectie c;
	c.categorie = 'A';
	c.finit = true;
	c.nr_elemente = 245;
	c.pret = 4000;
	c.denumire = new char[strlen("Ceai") + 1];
	strcpy_s(c.denumire, strlen("Ceai") + 1, "Ceai");
	afisareColectie(c);
	delete[]c.denumire;
	//cout << sizeof(bool); sa determin dimensiunea unei functii
}