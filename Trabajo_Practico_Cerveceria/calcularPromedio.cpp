// /Trabajo_Practico_Cerveceria/calcularPromedio.cpp
#include <iostream>
using namespace std;

// Recibe el arreglo como 'const' para no modificarlo y retorna un float
float calcularPromedio(const int arr[], int cont) {
    int suma = 0;
    float calculoFinal = 0.0;
    
    // Evitar la división por cero que da error
    // Si no hay ventas cargadas, el promedio es 0 directo.
    if (cont == 0) {
        // Retornamos apresuradamente un 0.0 para evitar el error de división por cero
        return 0.0;
    }

    // Sumar todos los elementos del arreglo
    for (int i = 0; i < cont; i = i + 1) {
        suma = suma + arr[i];
    }

    // Calculamos forzando los decimales con (float) 
    calculoFinal = (float)suma / cont;
    
    return calculoFinal;
}