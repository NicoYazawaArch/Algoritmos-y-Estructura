/*
Introducción a Modularización
Se requiere un programa que permita a un usuario/a llevar un control de sus gastos diarios
(en pesos) durante el período de un mes (se considera que un mes tiene como máximo 31
días).
Deberá incluir un menú con las siguientes opciones:
1. Ingresar el gasto de un día del mes.
2. Mostrar el gasto total de la primera quincena del mes.
3. Mostrar el gasto total de la segunda quincena del mes.
4. Mostrar el gasto total de todo el mes.
5. Salir.
Luego de escoger una opción, deberá ejecutarse la funcionalidad correspondiente y a
posterior mostrarse nuevamente el menú (de forma recurrente). Únicamente al seleccionar
la opción 5 se finalizará con el programa.
Detalle:
Al seleccionar 1, el usuario/a podrá ingresar el gasto de un día específico del mes –
respetando lo siguiente:
- Se le solicitará el día del mes: el cual deberá estar comprendido entre 1 y 31. Si no
cumple con esa condición, deberá reingresarlo hasta ser correcto.
- Luego se le solicitará el gasto asociado a ese día: el cual deberá ser como mínimo
1, es decir, no se admite como gasto un valor cero ni negativo. Si no cumple con esa
condición deberá reingresarlo hasta ser correcto.
- Si ya existe un gasto cargado para ese día, deberá mostrarse en pantalla y preguntar
al usuario/a si desea modificarlo. Si el usuario/a indica que sí, deberá actualizarse
(es decir, el nuevo gasto deberá reemplazar al anterior) y mostrar el mensaje: “El
gasto se actualizó de forma correcta”.
- En caso contrario, si es la primera vez que se ingresa un gasto para ese día
directamente deberá cargarse y mostrar el mensaje: “El gasto se cargó de forma
correcta”.
Al seleccionar 2, el usuario/a podrá visualizar el gasto total de la primera quincena del mes
(es decir, de los primeros 15 días del mes), en base a los gastos diarios cargados hasta ese
momento.
Al seleccionar 3, el usuario/a podrá visualizar el gasto total de la segunda quincena del mes
(es decir, de los últimos 15/16 días del mes), en base a los gastos diarios cargados hasta
ese momento.
Al seleccionar 4, el usuario/a podrá visualizar el gasto total del mes, en base a los gastos
diarios cargados hasta ese momento.
Aclaración: Hacer las suposiciones que sean necesarias siempre que no sean contrarias al
enunciado
*/
#include <iostream>
using namespace std;

// --- Declaración e Implementación de Funciones ---

int ingresarOpcion() {
    int op;
    cout << "\n========== MENU DE GASTOS ==========\n";
    cout << "1. Ingresar el gasto de un dia del mes.\n";
    cout << "2. Mostrar el gasto total de la primera quincena.\n";
    cout << "3. Mostrar el gasto total de la segunda quincena.\n";
    cout << "4. Mostrar el gasto total de todo el mes.\n";
    cout << "5. Salir.\n";
    cout << "Seleccione una opcion: ";
    cin >> op;
    return op;
}

int ingresarDiaValido(int min, int max) {
    int dia = min - 1; // Se inicializa fuera del rango para forzar el ingreso al while
    while (dia < min || dia > max) {
        cout << "Ingrese el dia del mes (" << min << " a " << max << "): ";
        cin >> dia;
        
        if (dia < min || dia > max) {
            cout << "Dia invalido. Por favor, reingrese.\n";
        }
    }
    return dia;
}

int ingresarConsumoValido(int min) {
    int consumo = min - 1; 
    while (consumo < min) {
        cout << "Ingrese el gasto del dia (minimo " << min << "): ";
        cin >> consumo;
        
        if (consumo < min) {
            cout << "Gasto invalido. No se admiten ceros ni negativos. Reingrese.\n";
        }
    }
    return consumo;
}

void cargarConsumo(int consumos[], int dia, int nuevoConsumo) {
    int indice = dia - 1;
    int respuesta = 1; // Usamos int en lugar de bool (1 = Si, 0 = No)
    int estadoAnterior = consumos[indice]; // Guardamos el valor previo para evitar IFs anidados

    // Si ya existe un gasto, preguntamos si se desea modificar
    if (estadoAnterior > 0) {
        cout << "Ya existe un gasto cargado para el dia " << dia << " por un valor de $" << estadoAnterior << ".\n";
        cout << "Desea modificarlo? (1 para Si, 0 para No): ";
        cin >> respuesta;

        while (respuesta != 0 && respuesta != 1) {
            cout << "Respuesta invalida. Ingrese 1 para Si, 0 para No: ";
            cin >> respuesta;
        }
    }

    // Evaluaciones planas y separadas (sin anidar IFs)
    if (respuesta == 1) {
        consumos[indice] = nuevoConsumo;
    }

    if (respuesta == 1 && estadoAnterior == 0) {
        cout << "El gasto se cargo de forma correcta.\n";
    }

    if (respuesta == 1 && estadoAnterior > 0) {
        cout << "El gasto se actualizo de forma correcta.\n";
    }
}

int calcularConsumoTotal(int consumos[], int inicio, int fin) {
    int total = 0;
    // Se ajustan los indices porque los arreglos empiezan en 0
    for (int i = inicio - 1; i < fin; i++) {
        total = total + consumos[i];
    }
    return total;
}

// --- Funcion Principal ---

int main() {
    // Inicializamos el arreglo en 0 para saber qué días están vacíos
    int consumos[31] = {0}; 
    int opcion = 0;
    int total = 0;

    while (opcion != 5) {
        opcion = ingresarOpcion();

        switch (opcion) {
            case 1:
                cout << "\n---- Ingreso de un consumo especifico ----\n";
                // Se invoca modularmente respetando el ejemplo solicitado
                cargarConsumo(consumos, ingresarDiaValido(1, 31), ingresarConsumoValido(1));
                break;
                
            case 2:
                cout << "\n---- Consumo primera quincena ----\n";
                total = calcularConsumoTotal(consumos, 1, 15);
                cout << "El Consumo de la primera quincena fue: $" << total << "\n";
                break;
                
            case 3:
                cout << "\n---- Consumo segunda quincena ----\n";
                // Para la segunda quincena tomamos del día 16 al 31 inclusive
                total = calcularConsumoTotal(consumos, 16, 31);
                cout << "El Consumo de la segunda quincena fue: $" << total << "\n";
                break;
                
            case 4:
                cout << "\n---- Consumo total del mes ----\n";
                total = calcularConsumoTotal(consumos, 1, 31);
                cout << "El Consumo total del mes fue: $" << total << "\n";
                break;
                
            case 5:
                cout << "\nSaliendo del programa...\n";
                break;
                
            default:
                cout << "\nOpcion Invalida. Intente nuevamente.\n";
                break; // El break en default dentro del switch es correcto y estándar
        }
    }
    
    return 0;
}