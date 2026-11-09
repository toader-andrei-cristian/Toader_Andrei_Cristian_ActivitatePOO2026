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
	
};
int contBancar::numarConturi = 0;
