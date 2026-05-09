// /Trabajo_Practico_Cerveceria/Main.cpp
#include <iostream>
using namespace std;

// Importamos todos los módulos externos
#include "ingresarOpcion.cpp"
#include "ingresarVenta.cpp"
#include "listarVentas.cpp"
#include "calcularPromedio.cpp"
#include "listarPrioritarias.cpp"

int main() {
    int stock = 10000, ventasOnline[10000], ventasLocal[10000], contOnline = 0, contLocal = 0, opcion = 0;
    float promedioAux = 0.0, promedioGeneral = 0.0;
    int totalVentas = 0, sumaTotal = 0;

    while (opcion != 7) {
        
        opcion = ingresarOpcion(stock);

        switch (opcion) {
            case 1:
                cout << "\n--- INGRESAR VENTA ---\n";
                ingresarVenta(stock, ventasOnline, contOnline, ventasLocal, contLocal);
                break;
                
            case 2:
                cout << "\n";
                listarVentas(ventasOnline, contOnline, "Ventas Online");
                break;
                
            case 3:
                cout << "\n";
                listarVentas(ventasLocal, contLocal, "Ventas en el Local");
                break;
                
            case 4:
                cout << "\n--- VENTAS ONLINE PRIORITARIAS ---\n";
                promedioAux = calcularPromedio(ventasOnline, contOnline);
                listarPrioritarias(ventasOnline, contOnline, promedioAux, "Prioritarias Online");
                break;
                
            case 5:
                cout << "\n--- VENTAS EN EL LOCAL PRIORITARIAS ---\n";
                promedioAux = calcularPromedio(ventasLocal, contLocal);
                listarPrioritarias(ventasLocal, contLocal, promedioAux, "Prioritarias Local");
                break;
                
            case 6:
                cout << "\n--- VENTAS PRIORITARIAS GENERALES ---\n";
                totalVentas = contOnline + contLocal;
                
                // Evita la división por cero si no se cargó ninguna venta en absoluto
                if (totalVentas == 0) {
                    cout << "No hay ventas cargadas para calcular el promedio general." << endl;
                } else {
                    sumaTotal = 0; // Reinicia la suma 
                    
                    for (int i = 0; i < contOnline; i = i + 1) {
                        sumaTotal = sumaTotal + ventasOnline[i];
                    }
                    for (int i = 0; i < contLocal; i = i + 1) {
                        sumaTotal = sumaTotal + ventasLocal[i];
                    }
                    
                    // Calculamos el promedio general
                    promedioGeneral = (float)sumaTotal / totalVentas;
                    cout << "Promedio General Calculado: " << promedioGeneral << " botellas.\n" << endl;
                    
                    // Reutiliza la función para ambos arreglos
                    listarPrioritarias(ventasOnline, contOnline, promedioGeneral, "Filtro General - Online");
                    cout << "\n";
                    listarPrioritarias(ventasLocal, contLocal, promedioGeneral, "Filtro General - Local");
                }
                break;
                
            case 7:
                cout << "\nSaliendo del programa.\n";
                break;
                
            default:
                cout << "\nOpcion invalida. Intente nuevamente.\n";
                break; 
        }
    }

    return 0;
}