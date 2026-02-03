#include <iostream>
#include <fstream>
using namespace std;

struct Prestamo {
    char nombre[30];
    float capital;
    float interes;
    float total;
};

int main() {
    Prestamo p;

    cout << "Nombre: ";
    cin.getline(p.nombre,30);
    cout << "Capital: ";
    cin >> p.capital;

    p.interes = p.capital * 0.15;
    p.total = p.capital + p.interes;

    ofstream archivo("intereses.txt");
    archivo << p.nombre << endl;
    archivo << "Interes: " << p.interes << endl;
    archivo << "Total a pagar: " << p.total << endl;
    archivo.close();

    return 0;
}
