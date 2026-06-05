/*
4. bool buscarSubcadena(char texto [], char subcadena[])
Recibe como parámetros de entrada:
- la cadena de caracteres texto
- la cadena de caracteres subcadena
Si subcadena existe en la cadena texto retorna true – y en caso contrario, retorna false.
Ejemplos:
a) Teniendo las cadenas de caracteres:
char texto[35]="Universidad Nacional de Avellaneda";
char subcadena[9]="Nacional";
Luego de la ejecución retorna true.
b) Teniendo las cadenas de caracteres:
char texto[35]="Universidad Nacional de Avellaneda";
char subcadena[11]="Provincial";
Luego de la ejecución retorna false.
*/
#include <iostream>
#include <cstring>
using namespace std;

bool buscarSubcadena(char texto[], char subcadena[]) {
    // Si strstr devuelve un puntero distinto de nulo, significa que la encontró
    if (strstr(texto, subcadena) != nullptr) {
        return true;
    } else {
        return false;
    }
}

int main() {
    char texto[35] = "Universidad Nacional de Avellaneda";
    char subcadena1[9] = "Nacional";
    char subcadena2[11] = "Provincial";

    if (buscarSubcadena(texto, subcadena1)) {
        cout << "Ejemplo A: true (Encontro '" << subcadena1 << "')" << endl;
    } else {
        cout << "Ejemplo A: false" << endl;
    }

    if (buscarSubcadena(texto, subcadena2)) {
        cout << "Ejemplo B: true" << endl;
    } else {
        cout << "Ejemplo B: false (No encontro '" << subcadena2 << "')" << endl;
    }

    return 0;
}