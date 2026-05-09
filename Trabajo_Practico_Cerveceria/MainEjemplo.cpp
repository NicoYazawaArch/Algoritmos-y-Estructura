#include <iostream>
using namespace std;

#include "ingresarVenta.cpp"
#include "listarVentas.cpp"
// #include "otrasFunciones.cpp" (cuando tus compañeros las hagan)

int main() {
    // 1. Preparamos el entorno de memoria
    int stock = 10000;
    int ventasOnline[10000];
    int ventasLocal[10000];
    int contOnline = 0;
    int contLocal = 0;
    
    int opcion = 0; // Inicializamos en 0 para que entre al while

    // 2. Ciclo principal del programa
    while (opcion != 7) {
        
        // Mostramos el menú
        cout << "\n=========================================" << endl;
        cout << "   SISTEMA DE GESTION - CERVECERIA" << endl;
        cout << "=========================================" << endl;
        cout << "Stock actual disponible: " << stock << " botellas." << endl;
        cout << "1. Ingresar una venta." << endl;
        cout << "2. Listado de ventas online." << endl;
        cout << "3. Listado de ventas en el local." << endl;
        // ... (agregar los cout de las opciones 4, 5 y 6) ...
        cout << "7. Salir." << endl;
        cout << "-----------------------------------------" << endl;
        cout << "Ingrese una opcion (1-7): ";
        
        cin >> opcion; // Leemos lo que elige el usuario

        // 3. Evaluamos la opción elegida
        if (opcion == 1) {
            cout << "\n--- INGRESAR VENTA ---" << endl;
            ingresarVenta(stock, ventasOnline, contOnline, ventasLocal, contLocal);
        } 
        else if (opcion == 2) {
            cout << "\n";
            listarVentas(ventasOnline, contOnline, "Ventas Online");
        } 
        else if (opcion == 3) {
            cout << "\n";
            listarVentas(ventasLocal, contLocal, "Ventas en el Local");
        }
        // ... (agregar los else if para las opciones 4, 5 y 6) ...
        else if (opcion == 7) {
            cout << "\nSaliendo del programa. ¡Hasta luego!" << endl;
        } 
        else {
            cout << "\nOpcion invalida. Por favor, intente nuevamente." << endl;
        }
    }

    return 0;
}