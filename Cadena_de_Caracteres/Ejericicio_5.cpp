/*
5. bool contienePie(char texto [], char pie[])
Recibe como parámetros de entrada:
- la cadena de caracteres texto
- la cadena de caracteres pie
Si la cadena texto contiene al final la cadena pie retorna true – y en caso contrario, retorna false.
Ejemplos:
a) Teniendo las cadenas de caracteres:
char texto[100]="Estimado, queda citado para el dia 4/06/25. Atte. Jorge Calzoni. UNDAV";
char pie[6]="UNDAV";
Luego de la ejecución retorna true.
b) Teniendo las cadenas de caracteres:
char texto[100]="Estimado, queda citado para el dia 04/06/24. Atte. Jorge Calzoni. ";
char pie[6]="UNDAV";
Luego de la ejecución retorna false.
*/

#include <iostream>
#include <cstring>
using namespace std;

bool contienePie(char texto[], char pie[]) {
    int lenTexto = strlen(texto); 
    int lenPie = strlen(pie);     

    if (lenPie > lenTexto) {
        return false;
    }
    char* inicioComparacion = texto + (lenTexto - lenPie);

    if (strcmp(inicioComparacion, pie) == 0) {
        return true;
    } else {
        return false;
    }
}

int main() {
    char textoA[100] = "Estimado, queda citado para el dia 4/06/25. Atte. Jorge Calzoni. UNDAV";
    char textoB[100] = "Estimado, queda citado para el dia 04/06/24. Atte. Jorge Calzoni. ";
    char pie[6] = "UNDAV";

    // Prueba A
    if (contienePie(textoA, pie)) {
        cout << "Ejemplo A: true (Termina en UNDAV)" << endl;
    } else {
        cout << "Ejemplo A: false" << endl;
    }

    // Prueba B
    if (contienePie(textoB, pie)) {
        cout << "Ejemplo B: true" << endl;
    } else {
        cout << "Ejemplo B: false (No termina en UNDAV)" << endl;
    }

    return 0;
}