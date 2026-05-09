// /Trabajo_Practico_Cerveceria/listarVentas.cpp
#include <iostream>
using namespace std;

// Usamos const en el arreglo porque no se van a modificar sus datos, solo lectura.
void listarVentas(const int arr[], int cont, string titulo) {
    
    // Si el contador es 0, no hay ventas.
    if (cont == 0) {
        cout << "No hay ventas cargadas en " << titulo << "." << endl;
    } else {
        // Si hay ventas, mostramos el título y entramos al bucle
        cout << "--- " << titulo << " ---" << endl;
        
        for (int i = 0; i < cont; i = i + 1) {
            cout << "Orden #" << i + 1 << ": " << arr[i] << " botellas." << endl;
        }
    }
}