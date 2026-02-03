#include <iostream>
#include <fstream>
using namespace std;

struct Publicacion {
    int codigo;
    char titulo[50];
    int anio;
    bool prestado;
};

int main() {
    Publicacion p[3];

    for(int i=0;i<3;i++){
        cout << "Codigo: ";
        cin >> p[i].codigo;
        cin.ignore();
        cout << "Titulo: ";
        cin.getline(p[i].titulo,50);
        cout << "Anio: ";
        cin >> p[i].anio;
        p[i].prestado = false;
    }

    p[1].prestado = true; // ejemplo

    ofstream prestados("LibrosPrestados.txt");
    ofstream stock("LibrosEnStock.txt");

    for(int i=0;i<3;i++){
        if(p[i].prestado){
            prestados << p[i].codigo << " " << p[i].titulo << endl;
        } else {
            stock << p[i].codigo << " " << p[i].titulo << endl;
        }
    }

    prestados.close();
    stock.close();

    return 0;
}
