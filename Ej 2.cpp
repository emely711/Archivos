#include <iostream>
#include <fstream>
using namespace std;

int main() {
    char materia[30];
    ofstream archivo("materias.txt", ios::app);

    cout << "Ingrese materia: ";
    cin.getline(materia, 30);

    archivo << materia << endl;
    archivo.close();

    return 0;
}
