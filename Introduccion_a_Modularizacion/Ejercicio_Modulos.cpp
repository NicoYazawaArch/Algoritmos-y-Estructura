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

int ingresarDiaValido(int min, int max){
    int dia=min-1; // Se inicializa fuera del rango para forzar el ingreso al while
    while(dia<min||dia>max){

    }
}