/*
3. void obtenerAnio(char fecha[11], char anio[5])
Recibe como parámetros de entrada:
- la cadena de caracteres fecha, respetando el siguiente formato: dd/MM/yyyy
- la cadena de caracteres anio
Filtra el año yyyy de la cadena fecha y lo deja almacenado en la cadena anio.
Ejemplo:
Teniendo las cadenas de caracteres:
char fecha[11]="26/05/2025";
char anio[5];
Luego de la ejecución queda almacenado en anio la cadena: “2025”.
Observación: Tener en cuenta que la cadena anio debe finalizar con el caracter nulo (para quedar
“bien formada”).
*/

#include <iostream>
#include <cstring>
using namespace std;

void obtenerAnio(char fecha[11], char anio[5]){
    strncpy(anio, fecha + 6, 4); 
    anio[4] = '\0'; 
}
int main(){
    char fecha[11] = "26/05/2025";
    char anio[5];
    
    obtenerAnio(fecha, anio);
    
    cout << "El anio es: " << anio << endl; 
    return 0;
}