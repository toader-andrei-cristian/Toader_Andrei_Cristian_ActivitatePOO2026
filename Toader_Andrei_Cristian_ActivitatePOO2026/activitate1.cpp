#include <iostream>
using namespace std;

class contBancar {
private:
	static int numarConturi;
	const int idCont;
	string titularCont;
	double* istoricTranzactii;
	int numarTranzactii;
public:
	contBancar() : idCont(numarConturi++)
	{
		this->titularCont = "Mitroi Sorin";
		this->numarTranzactii = 4;
		this->istoricTranzactii = new double[this->numarTranzactii];
		this->istoricTranzactii[0] = 19.60;
		this->istoricTranzactii[1] = 1.65;
		this->istoricTranzactii[2] = 23.4;
		this->istoricTranzactii[3] = 125.2;
	}
	contBancar(string titularCont, double* istoricTranzactii, int numarTranzactii) : idCont(numarConturi++)
	{
		this->titularCont = titularCont;
		this->numarTranzactii = numarTranzactii;
		this->istoricTranzactii = new double[this->numarTranzactii];
		for (int i = 0; i < this->numarTranzactii; i++)
		{
			this->istoricTranzactii[i] = istoricTranzactii[i];
		}
	}
	string getTitularCont() {
		return this->titularCont;
	}
	void setTitularCont(string titularCont)
	{
		this->titularCont = titularCont;
	}
	~contBancar()
	{
		delete[] istoricTranzactii;
	}
	int getNumarTranzactii() {
		return this->numarTranzactii;
	}
	double* getIstoricTranzactii() {
		return this->istoricTranzactii;
	}
	void setIstoricTranzactii(const double* istoricTranzactiiNou, int dimensiuneNoua) {
		delete[] this->istoricTranzactii;
		this->numarTranzactii = dimensiuneNoua;
		this->istoricTranzactii = new double[this->numarTranzactii];
		for (int i = 0; i < this->numarTranzactii; i++) {
			this->istoricTranzactii[i] = istoricTranzactiiNou[i];
		}
	}
	contBancar& operator=(const contBancar& c) {
		if (this != &c) {
			this->titularCont = c.titularCont;
			this->numarTranzactii = c.numarTranzactii;
			if (this->istoricTranzactii != NULL)
				delete[] this->istoricTranzactii;
			this->istoricTranzactii = new double[this->numarTranzactii];
			for (int i = 0; i < this->numarTranzactii; i++)
			{
				this->istoricTranzactii[i] = c.istoricTranzactii[i];
			}
		}
		return *this;
	}
	contBancar(const contBancar& c) : idCont(numarConturi++) {
		this->titularCont = c.titularCont;
		this->numarTranzactii = c.numarTranzactii;
		this->istoricTranzactii = new double[this->numarTranzactii];
		for (int i = 0; i < this->numarTranzactii; i++)
		{
			this->istoricTranzactii[i] = c.istoricTranzactii[i];
		}
	}
	friend ostream& operator<<(ostream& out, const contBancar& c)
	{
		out << "ID cont: " << c.idCont << endl;
		out << "Titular cont: " << c.titularCont << endl;
		out << "Numar tranzactii: " << c.numarTranzactii << endl;
		out << "Istoric Tranzactii: ";
		for (int i = 0; i < c.numarTranzactii; i++)
			out << c.istoricTranzactii[i] << ", ";
		out << endl;
		return out;
	}
};
	int contBancar::numarConturi = 0;
int main()
{
		contBancar c1;
		cout << c1;
}