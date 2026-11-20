#include <iostream>
#include <cstring>
using namespace std;

class Ghiozdan {
protected:
    char* marca;
    int capacitate;
    float greutate;
    int numarBuzunare;

public:

    // Constructor fara parametri
    Ghiozdan() {
        marca = new char[strlen("Necunoscuta") + 1];
        strcpy(marca, "Necunoscuta");

        capacitate = 0;
        greutate = 0;
        numarBuzunare = 0;
    }

    // Constructor cu parametri
    Ghiozdan(const char* marca, int capacitate,
        float greutate, int numarBuzunare) {

        this->marca = new char[strlen(marca) + 1];
        strcpy(this->marca, marca);

        this->capacitate = capacitate;
        this->greutate = greutate;
        this->numarBuzunare = numarBuzunare;
    }

    // Constructor de copiere
    Ghiozdan(const Ghiozdan& g) {
        marca = new char[strlen(g.marca) + 1];
        strcpy(marca, g.marca);

        capacitate = g.capacitate;
        greutate = g.greutate;
        numarBuzunare = g.numarBuzunare;
    }

    // Operator =
    Ghiozdan& operator=(const Ghiozdan& g) {
        if (this != &g) {
            delete[] marca;

            marca = new char[strlen(g.marca) + 1];
            strcpy(marca, g.marca);

            capacitate = g.capacitate;
            greutate = g.greutate;
            numarBuzunare = g.numarBuzunare;
        }

        return *this;
    }

    // Destructor
    ~Ghiozdan() {
        delete[] marca;
    }

    // Getteri
    const char* getMarca() const {
        return marca;
    }

    int getCapacitate() const {
        return capacitate;
    }

    float getGreutate() const {
        return greutate;
    }

    int getNumarBuzunare() const {
        return numarBuzunare;
    }

    // Setteri
    void setMarca(const char* marca) {
        if (this->marca != nullptr) {
            delete[] this->marca;
        }

        this->marca = new char[strlen(marca) + 1];
        strcpy(this->marca, marca);
    }

    void setCapacitate(int capacitate) {
        this->capacitate = capacitate;
    }

    void setGreutate(float greutate) {
        this->greutate = greutate;
    }

    void setNumarBuzunare(int numarBuzunare) {
        this->numarBuzunare = numarBuzunare;
    }

    // Operator <<
    friend ostream& operator<<(ostream& out, const Ghiozdan& g) {
        out << "Marca: " << g.marca << endl;
        out << "Capacitate: " << g.capacitate << " litri" << endl;
        out << "Greutate: " << g.greutate << " kg" << endl;
        out << "Numar buzunare: " << g.numarBuzunare << endl;

        return out;
    }

    // Operator >>
    friend istream& operator>>(istream& in, Ghiozdan& g) {
        char buffer[100];

        cout << "Marca: ";
        in >> ws;
        in.getline(buffer, 100);

        g.setMarca(buffer);

        cout << "Capacitate: ";
        in >> g.capacitate;

        cout << "Greutate: ";
        in >> g.greutate;

        cout << "Numar buzunare: ";
        in >> g.numarBuzunare;

        return in;
    }

    // Operator ==
    bool operator==(const Ghiozdan& g) const {
        return strcmp(marca, g.marca) == 0 &&
            capacitate == g.capacitate &&
            greutate == g.greutate &&
            numarBuzunare == g.numarBuzunare;
    }

    // Operator <
    bool operator<(const Ghiozdan& g) const {
        return capacitate < g.capacitate;
    }

    // Operator ++ prefix
    Ghiozdan& operator++() {
        capacitate++;
        return *this;
    }

    // Operator ++ postfix
    Ghiozdan operator++(int) {
        Ghiozdan copie(*this);
        capacitate++;
        return copie;
    }

    // Operator []
    int operator[](int index) const {
        if (index == 0)
            return capacitate;
        if (index == 1)
            return numarBuzunare;

        throw out_of_range("Index invalid!");
    }
};

class GhiozdanExtensibil : public Ghiozdan {
protected:

private:
    bool esteExtensibil;
    int capacitateSuplimentara;
public:
    GhiozdanExtensibil() :Ghiozdan() {
        this->esteExtensibil = true;
        this->capacitateSuplimentara = 1;
    }
    GhiozdanExtensibil(const char* marca, int nrBuzunare, float greutate, int capacitate, bool esteExtensibil, int capSuplimentara) :Ghiozdan(marca, capacitate, greutate, nrBuzunare) {
        this->esteExtensibil = esteExtensibil;
        this->capacitateSuplimentara = capSuplimentara;
    }

    GhiozdanExtensibil(bool esteExten, int capSuplimentara) :Ghiozdan("Marca", 20, 10, 3) {
        this->esteExtensibil = esteExten;
        this->capacitateSuplimentara = capSuplimentara;
    }

    ~GhiozdanExtensibil() {
    }

    GhiozdanExtensibil& operator=(const GhiozdanExtensibil& g) {
        (Ghiozdan)*this = (Ghiozdan)g;
        this->capacitateSuplimentara = g.capacitateSuplimentara;
        this->esteExtensibil = g.esteExtensibil;
        return *this;
    }

    GhiozdanExtensibil& operator=(const Ghiozdan& g) {
        (Ghiozdan)*this = (Ghiozdan)g;
        this->capacitateSuplimentara = 10;
        this->esteExtensibil = true;
        return *this;
    }

};


void  main() {
    Ghiozdan g;
    //cout << g;

    GhiozdanExtensibil ge;
    cout << ge.getGreutate();

    GhiozdanExtensibil ge1;
    ge = ge1;

    g = ge;

    ge = g;


}