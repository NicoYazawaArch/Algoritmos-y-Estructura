//Nicolas Corpus Ejercicio 1 - Trabajo Practico 1 - Algoritmos y Estructuras de Datos

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

void ingresarVenta(int &stock,int arr0 [],int &cont0,int arrL[],int &contL){
    char tipoVenta='X';//Le agrego un valor inicial que no sea ni 'O' ni 'L' para asegurar que entre al bucle de validacion
    int cantidad =-1; //inicializo cantidad en -1

    // Pedimos el tipo de venta al usuario
    cout << "Ingrese tipo de venta (O para Online, L para Local): ";
    cin >> tipoVenta;

    //Validar venta
    while(tipoVenta != 'O' && tipoVenta != 'o' && tipoVenta != 'L' && tipoVenta != 'l'){
    cout<<"Error. Ingrese unicamente 'O' o 'L': ";
    cin>>tipoVenta;
    }
    //Validar cantidad
    cout<<"Ingrese cantidad a vender(0 para cancelar).Stock actual: "<<stock<<": ";
    cin>>cantidad;
    while(cantidad<0||cantidad>stock){
        cout<<"Cantidad invalida o suepera el stock. Ingrese nuevamente: ";
        cin>>cantidad;
    }
    //Precesar la venta 
    if(cantidad>0){//anidamos la venta dentro de la validacion de cantidad para evitar procesar una venta cancelada
        if(tipoVenta=='O' ||tipoVenta == 'o'){
            arr0[cont0]=cantidad;
            cont0++;
        }else{
            arrL[contL]=cantidad;
            contL++;
        }
        // El stock se resta sin importar qué tipo de venta fue
        stock = stock - cantidad;
        cout << "Venta registrada con exito." << endl;
    }
    // Pedido con 0 cervezas se considera una cancelación, no se procesa la venta ni se modifica el stock.
    if (cantidad == 0) {
        cout << "Venta cancelada." << endl;
    }
}

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