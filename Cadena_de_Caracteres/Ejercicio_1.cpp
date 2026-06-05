/*
1. void obtenerDia(char fecha[11], char dia[3])
Recibe como parámetros de entrada:
- la cadena de caracteres fecha, respetando el siguiente formato: dd/MM/yyyy
- la cadena de caracteres dia
Filtra el día dd de la cadena fecha y lo deja almacenado en la cadena dia.
Ejemplo:
Teniendo las cadenas de caracteres:
char fecha[11]="26/05/2025";
char dia[3];
Luego de la ejecución queda almacenado en dia la cadena: “26”.
Observación: Tener en cuenta que la cadena dia debe finalizar con el caracter nulo (para quedar
“bien formada”).
*/

#include <iostream>
#include <cstring>
using namespace std;
void obtenerDia(char fecha[11], char dia[3]){
    strncpy(dia,fecha,2);
    dia[2]='\0';

}

int main(){
    char fecha[11]="26/05/2026";
    char dia[3];
    obtenerDia(fecha, dia);
    cout << "El día es: " << dia << endl;
    return 0;
}
