#include <iostream>
#include <fstream>
using namespace std;

struct Factura {
    int cantidad;
    char detalle[50];
    float valorUnitario;
    float total;
};

int main() {
    Factura f;
    float iva, totalPagar;

    cout << "Cantidad: ";
    cin >> f.cantidad;
    cin.ignore();
    cout << "Detalle: ";
    cin.getline(f.detalle, 50);
    cout << "Valor unitario: ";
    cin >> f.valorUnitario;

    f.total = f.cantidad * f.valorUnitario;
    iva = f.total * 0.12;
    totalPagar = f.total + iva;
    ofstream archivo("factura.txt");
    archivo << "Detalle: " << f.detalle << endl;
    archivo << "Cantidad: " << f.cantidad << endl;
    archivo << "Valor Unitario: " << f.valorUnitario << endl;
    archivo << "Subtotal: " << f.total << endl;
    archivo << "IVA: " << iva << endl;
    archivo << "Total a pagar: " << totalPagar << endl;
    archivo.close();

    return 0;
}
