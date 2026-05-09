// /Trabajo_Practico_Cerveceria/listarPrioritarias.cpp
#include <iostream>
using namespace std;

// Recibe el arreglo
void listarPrioritarias(const int arr[], int cont, float promedio, string titulo) {
    
    //Si hay datos para analizar
    if (cont == 0) {
        cout << "No hay ventas cargadas en " << titulo << " para analizar." << endl;
    } else {
        //Mostramos el encabezado con el promedio de referencia
        cout << "--- " << titulo << " ---" << endl;
        cout << "Promedio de referencia: " << promedio << " botellas." << endl;
        cout << "Ventas superiores al promedio:" << endl;

        //Recorremos el arreglo filtrando los que superan el promedio
        for (int i = 0; i < cont; i = i + 1) {
            //Solo entran los estrictamente mayores
            if (arr[i] > promedio) {
                cout << "Orden #" << i + 1 << ": " << arr[i] << " botellas." << endl;
            }
        }
    }
}