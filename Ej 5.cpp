#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

struct Helado {
    int codigo;
    char sabor[20];
    float precio;
};

int main() {
    Helado h[10];
    float suma = 0;
    float menor;
    int posMenor = 0;
    bool encontradoMora = false;

    ofstream archivo("helados.txt");

    for(int i = 0; i < 10; i++) {
        cout << "\nHelado " << i + 1 << endl;
        cout << "Codigo: ";
        cin >> h[i].codigo;
        cin.ignore();
        cout << "Sabor: ";
        cin.getline(h[i].sabor, 20);
        cout << "Precio: ";
        cin >> h[i].precio;

        archivo << h[i].codigo << " "
                << h[i].sabor << " "
                << h[i].precio << endl;
    }
    archivo.close();
    menor = h[0].precio;

    for(int i = 0; i < 10; i++) {
        suma += h[i].precio;

        if(h[i].precio < menor) {
            menor = h[i].precio;
            posMenor = i;
        }

        if(strcmp(h[i].sabor, "mora") == 0) {
            encontradoMora = true;
        }
    }

    cout << "Helado con menor precio:\n";
    cout << "Codigo: " << h[posMenor].codigo << endl;
    cout << "Sabor: " << h[posMenor].sabor << endl;
    cout << "Precio: " << h[posMenor].precio << endl;

    if(encontradoMora)
        cout << "Existe un helado de sabor mora";
    else
        cout << "No existe helado de sabor mora";
   		cout << "Suma total de precios: " << suma << endl;

    return 0;
}
