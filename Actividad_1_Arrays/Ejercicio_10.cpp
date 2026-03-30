/*
Diseñar e implementar en C++ los siguientes ejercicios.
Importante: Aplicar arreglos sólo cuando sea necesario.
10. Un algoritmo que solicite el ingreso de diez números enteros (de a uno) y evalúe si se
ingresaron números repetidos, mostrando como salida el mensaje: “Hay números
repetidos” o bien “No hay números repetidos” - según corresponda.
Ejemplo 1:
Entrada de datos:
Ingresar diez números enteros:
4 0 7 8 -1 2 9 10 8 -12
Salida de datos:
Hay números repetidos.
Ejemplo 2:
Entrada de datos:
Ingresar diez números enteros:
4 0 4 7 8 -1 2 9 10 50 -12
Salida de datos:
No hay números repetidos.
*/

#include <iostream>
using namespace std;

int main() {
    int arreglo[10],coincidencias=0;

    cout << "Ingresar diez numeros enteros:"<<endl;
    for (int i = 0; i < 10; i++) {
        cout << "Numero " << i + 1 << ": ";
        cin >> arreglo[i];
    }
    // Verificación sin anidaciones (100 vueltas)
    // Usamos 'k' para recorrer todas las combinaciones posibles (10x10)
    for (int k = 0; k < 100; k++) {
        int i = k / 10; // Esto nos da el primer índice (0,0,0... 1,1,1...)
        int j = k % 10; // Esto nos da el segundo índice (0,1,2... 0,1,2...)
        //Funcionaria como buscar en una matriz
        // Un solo IF simple usando && (Y lógico)
        // Condición: Que i sea menor que j (para no compararse consigo mismo)
        // Y que los valores en esas posiciones sean iguales.
        if (i < j && arreglo[i] == arreglo[j]) {//Se crean 2 arrays virtuales, uno con i y otro con j, y se comparan entre sí. Si i es menor que j, se compara el valor en la posición i con el valor en la posición j. Si son iguales, significa que hay un número repetido.
            coincidencias = coincidencias + 1;
        }
    }
 // Resultados finales
    if (coincidencias > 0) {
        cout << "Hay numeros repetidos." << endl;
    }

    if (coincidencias == 0) {
        cout << "No hay numeros repetidos." << endl;
    }

cout << endl;
return 0;
}