#include <iostream>
#include <string> // <--- Nueva librería necesaria
using namespace std;

int main() {
    string texto; // No necesita tamaño previo

    cout << "Ingrese un texto (sin limite): ";
    
    // getline con string lee toda la linea hasta presionar Enter
    getline(cin, texto);

    cout << "Texto ingresado: " << texto << endl;
    cout << "Longitud de la palabra: " << texto.length() << " caracteres." << endl;

    return 0;
}