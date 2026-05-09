// /Trabajo_Practico_Cerveceria/ingresarOpcion.cpp
#include <iostream>
using namespace std;

int ingresarOpcion(int stockActual) {
    int opc = 0;
    
    cout << "\n=========================================" << endl;
    cout << "   SISTEMA DE GESTION - CERVECERIA" << endl;
    cout << "=========================================" << endl;
    cout << "Stock actual disponible: " << stockActual << " botellas." << endl;
    cout << "1. Ingresar una venta." << endl;
    cout << "2. Listado de ventas online." << endl;
    cout << "3. Listado de ventas en el local." << endl;
    cout << "4. Ventas online prioritarias." << endl;
    cout << "5. Ventas en el local prioritarias." << endl;
    cout << "6. Ventas prioritarias (General)." << endl;
    cout << "7. Salir." << endl;
    cout << "-----------------------------------------" << endl;
    cout << "Ingrese una opcion (1-7): ";
    
    cin >> opc;
    return opc;
}