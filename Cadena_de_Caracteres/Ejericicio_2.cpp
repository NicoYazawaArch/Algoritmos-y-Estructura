/*
2. void obtenerMes(char fecha[11], char mes[3])
Recibe como parámetros de entrada:
- la cadena de caracteres fecha, respetando el siguiente formato: dd/MM/yyyy
- la cadena de caracteres mes
Filtra el mes MM de la cadena fecha y lo deja almacenado en la cadena mes.
Ejemplo:
Teniendo las cadenas de caracteres:
char fecha[11]="26/05/2025";
char mes [3];
Luego de la ejecución queda almacenado en mes la cadena: “05”.
Observación: Tener en cuenta que la cadena mes debe finalizar con el caracter nulo (para quedar
“bien formada”)
*/

#include <iostream>
#include <cstring>
using namespace std;
void obtenerMes(char fecha[11],char mes[3]){
    strncpy(mes,fecha+3,2); // Copia los caracteres del mes desde la posición 3 de la cadena fecha
    mes[2]='\0'; // Asegura que la cadena mes termine con el caracter nulo
}
int main() {
    char fecha[11] = "26/05/2025";
    char mes[3];
    
    obtenerMes(fecha, mes);
    
    cout << "El mes es: " << mes << endl; // Imprimirá: El mes es: 05
    return 0;
}