/*
Diseñar e implementar en C++ aplicando arreglos estáticos:
Un/a runner realiza 21 kilómetros diarios como entrenamiento para su próxima maratón.
Se requiere un programa que le permita registrar los tiempos (en minutos) de una semana
(7 días) y filtrar según su criterio.
El programa deberá mostrar al usuario/a las siguientes opciones:
1: Ingresar el tiempo de un día específico.
2: Mostrar los tiempos de la semana.
3: Mostrar el mejor tiempo de la semana.
4: Salir.
Al seleccionar la opción 1, 2 o 3 deberá ejecutarse la funcionalidad escogida y a posterior
mostrar nuevamente el menú para una nueva elección. Por último, al seleccionar la opción
4 se finalizará.
Detalle:
Al seleccionar 1, el usuario/a deberá ingresar:
- El número de día de la semana (entre 1 y 7).
- El tiempo de ese día en minutos.
Por ejemplo:
Día: 1
Tiempo (minutos): 15.33
En caso que ese día se haya ingresado previamente, deberá mostrar el mensaje: “Ese día
ya está cargado con el tiempo: x. Desea modificarlo? Ingresar S(si) o N(no)” - donde x
corresponderá al tiempo existente (en minutos). Si el usuario/a responde con ‘S’, se
actualizará con el tiempo ingresado por el usuario/a. En caso contrario, se ignorará.
Al seleccionar 2, deberán mostrarse los tiempos cargados hasta ese momento - detallando
por cada uno: el número de día y tiempo correspondiente. Los días que no hayan sido
registrados, no deberán mostrarse.
Al seleccionar 3, deberá mostrarse el mejor tiempo cargado hasta ese momento –
detallando: ese tiempo y el/los números de días en que se registró. Tener en cuenta que un
mismo tiempo puede repetirse en más de un día.

*/

/*
SUPOSICIONES REALIZADAS:
1. Se asume que el usuario ingresara valores numericos validos tanto para el menu, 
   como para el numero de dia y el tiempo. No se contempla el ingreso de caracteres 
   (letras) en variables numericas (lo que romperia el flujo de 'cin').
2. Se asume que cualquier caracter distinto de 'S' o 's' ingresado al preguntar 
   si desea modificar un tiempo existente, sera interpretado como un "No".
3. Se asume que los tiempos registrados son siempre mayores a 0 minutos.
4. Se asume que en la Opcion 3, si existen multiples dias con el mismo mejor tiempo 
   exacto, es correcto mostrarlos todos de forma secuencial.
*/

#include <iostream>
using namespace std;

int main(){
    // Arreglos
    double tiempos[7] = {-1, -1, -1, -1, -1, -1, -1};
    
    // Variables de tipo double
    double tiempo = 0.0;
    double mejor = 99999.0;
    
    // Variables de tipo int (incluye menu, ingresos y banderas logicas)
    int opcion = 0, dia = 0, op1_valida = 0, dia_existe = 0, dia_nuevo = 0, dia_invalido = 0, op2 = 0, op3 = 0, hay_tiempos = 0, sin_tiempos = 0, op_invalida = 0;
    
    // Variables de tipo char
    char modificar = 'N';
    
    
    while(opcion != 4){ // Salimos con opcion 4
    
        // Menu
        if(opcion == 0){
            cout << "\n--- REGISTRO DE ENTRENAMIENTO (21 KM) ---\n";
            cout << "1: Ingresar el tiempo de un dia especifico\n";
            cout << "2: Mostrar los tiempos de la semana\n";
            cout << "3: Mostrar el mejor tiempo de la semana\n";
            cout << "4: Salir\n";
            cout << "Seleccione una opcion: ";
            cin >> opcion;
        }

        // --- ESTO ES LO QUE FALTABA: Pedir los datos de la opcion 1 ---
        if(opcion == 1){
            cout << "Dia (1-7): ";
            cin >> dia;
            cout << "Tiempo (Minutos): ";
            cin >> tiempo;
        }

        // 1. Reseteamos banderas
        op1_valida = 0;
        dia_existe = 0;
        dia_nuevo = 0;
        dia_invalido = 0;

        // 2. Cambiamos el estado a 1 solo si corresponde
        if (opcion == 1 && dia >= 1 && dia <= 7) {
            op1_valida = 1;
        }
        if (opcion == 1 && (dia < 1 || dia > 7)) {
            dia_invalido = 1;
        }
        if (op1_valida == 1 && tiempos[dia - 1] != -1) {
            dia_existe = 1;
        }
        if (op1_valida == 1 && tiempos[dia - 1] == -1) {
            dia_nuevo = 1;
        }

        if(dia_existe == 1){
            cout << "Ese dia ya esta cargado con el tiempo: " << tiempos[dia-1] << ". Desea modificarlo? Ingrese S(si) o N(no): ";
            cin >> modificar; 
        }

        // Resolucion de la Opcion 1
        if (dia_nuevo == 1) {
            tiempos[dia - 1] = tiempo;
            opcion = 0; 
        }
        if (dia_existe == 1 && (modificar == 'S' || modificar == 's')) {
            tiempos[dia - 1] = tiempo;
            opcion = 0;
        }
        if (dia_existe == 1 && (modificar != 'S' && modificar != 's')) {
            opcion = 0; 
        }
        if (dia_invalido == 1) {
            cout << "Error: El dia debe ser entre 1 y 7.\n";
            opcion = 0;
        }

        // --- FUNCIONALIDAD OPCION 2 ---
        op2 = 0;
        if (opcion == 2) {
            op2 = 1;
        }
        
        if (op2 == 1) cout << "\n-- Tiempos de la semana --\n";
        if (op2 == 1 && tiempos[0] != -1) cout << "Dia 1: " << tiempos[0] << " minutos\n";
        if (op2 == 1 && tiempos[1] != -1) cout << "Dia 2: " << tiempos[1] << " minutos\n";
        if (op2 == 1 && tiempos[2] != -1) cout << "Dia 3: " << tiempos[2] << " minutos\n";
        if (op2 == 1 && tiempos[3] != -1) cout << "Dia 4: " << tiempos[3] << " minutos\n";
        if (op2 == 1 && tiempos[4] != -1) cout << "Dia 5: " << tiempos[4] << " minutos\n";
        if (op2 == 1 && tiempos[5] != -1) cout << "Dia 6: " << tiempos[5] << " minutos\n";
        if (op2 == 1 && tiempos[6] != -1) cout << "Dia 7: " << tiempos[6] << " minutos\n";
        
        if (op2 == 1) opcion = 0;

        // --- FUNCIONALIDAD OPCION 3 ---
        op3 = 0;
        if (opcion == 3) {
            op3 = 1;
            mejor = 99999.0; // Se resetea el mejor tiempo al entrar a la opcion
        }

        if (op3 == 1 && tiempos[0] != -1 && tiempos[0] < mejor) mejor = tiempos[0];
        if (op3 == 1 && tiempos[1] != -1 && tiempos[1] < mejor) mejor = tiempos[1];
        if (op3 == 1 && tiempos[2] != -1 && tiempos[2] < mejor) mejor = tiempos[2];
        if (op3 == 1 && tiempos[3] != -1 && tiempos[3] < mejor) mejor = tiempos[3];
        if (op3 == 1 && tiempos[4] != -1 && tiempos[4] < mejor) mejor = tiempos[4];
        if (op3 == 1 && tiempos[5] != -1 && tiempos[5] < mejor) mejor = tiempos[5];
        if (op3 == 1 && tiempos[6] != -1 && tiempos[6] < mejor) mejor = tiempos[6];

        // Evaluamos banderas para mostrar resultados
        hay_tiempos = 0;
        sin_tiempos = 0;
        
        if (op3 == 1 && mejor != 99999.0) hay_tiempos = 1;
        if (op3 == 1 && mejor == 99999.0) sin_tiempos = 1;

        if (sin_tiempos == 1) cout << "\nAun no hay tiempos registrados.\n";
        if (hay_tiempos == 1) cout << "\nMejor tiempo: " << mejor << " min. Registrado en el/los dia(s): ";
        
        if (hay_tiempos == 1 && tiempos[0] == mejor) cout << "1 ";
        if (hay_tiempos == 1 && tiempos[1] == mejor) cout << "2 ";
        if (hay_tiempos == 1 && tiempos[2] == mejor) cout << "3 ";
        if (hay_tiempos == 1 && tiempos[3] == mejor) cout << "4 ";
        if (hay_tiempos == 1 && tiempos[4] == mejor) cout << "5 ";
        if (hay_tiempos == 1 && tiempos[5] == mejor) cout << "6 ";
        if (hay_tiempos == 1 && tiempos[6] == mejor) cout << "7 ";
        
        if (hay_tiempos == 1) cout << "\n";
        if (op3 == 1) opcion = 0;

        // --- CONTROL DE OPCIONES INVALIDAS ---
        op_invalida = 0;
        if (opcion != 0 && opcion != 1 && opcion != 2 && opcion != 3 && opcion != 4) {
            op_invalida = 1;
        }
        if (op_invalida == 1) {
            cout << "Opcion invalida. Intente nuevamente.\n";
            opcion = 0;
        }
    }

    return 0;
}