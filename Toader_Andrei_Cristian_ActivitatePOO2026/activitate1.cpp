#include <iostream>
using namespace std;

class contBancar {
private:
	static int numarConturi;
	const int idCont;
	string titularCont;
	double* istoricTranzactii;
	int numarTranzactii;

};
int contBancar::numarConturi = 0;
