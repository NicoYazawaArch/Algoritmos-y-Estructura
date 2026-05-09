/*
Descripcion:
 * Este programa gestiona una matriz cuadrada de numeros enteros.
 * Permite al usuario definir el tamano logico de la matriz (hasta un maximo 
 * predefinido para asegurar escalabilidad sin memoria dinamica) y ofrece un 
 * menu interactivo con las siguientes opciones:
 * * 1. Ingresar Matriz: Carga los elementos fila por fila.
 * 2. Visualizar Matriz: Muestra la matriz en formato de filas y columnas.
 * 3. Mayor Elemento de la Matriz: Busca el mayor valor en toda la matriz.
 * 4. Mayor Elemento Diagonal Principal: Busca el mayor en la diagonal (i == j).
 * 5. Mayor Elemento Diagonal Secundaria: Busca el mayor en la diagonal inversa.
 * 6. Salir: Finaliza la ejecucion del programa.
 * * Restricciones tecnicas aplicadas:
 * - Implementacion en una unica funcion (main).
 * - Prohibido el uso de variables tipo bool.
 * - Prohibido el uso de sentencias de salto (break, continue, goto).
 * - Evita el codigo espagueti (anidacion excesiva de if) mediante el uso 
 * de operadores logicos (&& y ||).
 * * Observaciones: 
 * Si se intenta acceder a las opciones 2, 3, 4 o 5 sin haber cargado 
 * previamente la matriz, el programa mostrara una advertencia.

*/
#include <iostream>
using namespace std;

int main(){
    // Definimos la capacidad maxima de la matriz en memoria. 
    // Usamos 50 para permitir escalabilidad futura sin usar memoria dinamica.
    const int MAX_TAMANO = 50;
    int matriz[MAX_TAMANO][MAX_TAMANO];
    
    // n: tamano logico actual (lo que el usuario elige usar, por defecto 5)
    // opcion: guarda la eleccion del menu
    // matrizCargada: bandera numerica (0 = Falso, 1 = Verdadero)
    int n = 5, opcion = 0, matrizCargada = 0;
    
    // Bucle principal: se ejecuta mientras el usuario no elija salir (opcion 6)
    while (opcion != 6) {
        cout << "\n--- MENU ---\n";
        cout << "1. Ingresar Matriz\n";
        cout << "2. Visualizar Matriz\n";
        cout << "3. Mayor Elemento de la Matriz\n";
        cout << "4. Mayor Elemento de la Diagonal Principal\n";
        cout << "5. Mayor Elemento de la Diagonal Secundaria\n";
        cout << "6. Salir\n";
        cout << "Ingrese una opcion: ";
        cin >> opcion;
            
        // ==========================================
        // Lógica de la Opción 1: Carga de datos
        // ==========================================
        
        // Primero pedimos el tamano que desea utilizar
        if(opcion == 1){
            cout << "Ingrese el tamano de la matriz (maximo " << MAX_TAMANO << "): ";
            cin >> n;
        }
        
        // Si eligio 1 Y el tamano esta dentro de los limites de nuestra memoria estatica
        if (opcion == 1 && n > 0 && n <= MAX_TAMANO) {
            cout << "Ingrese los elementos de la matriz " << n << "x" << n << ":\n";
            // Recorremos fila por fila
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    cout << "Fila " << i << ", Columna " << j << ": ";
                    cin >> matriz[i][j];
                }
            }
            // Cambiamos el estado de la bandera para habilitar las demas opciones
            matrizCargada = 1;
            cout << "Matriz cargada exitosamente.\n";
        }

        // Si eligio 1 pero introdujo un tamano matematicamente invalido o que excede el buffer
        if (opcion == 1 && (n <= 0 || n > MAX_TAMANO)) {
            cout << "Tamano invalido. Intente nuevamente.\n";
        }

        // ==========================================
        // Lógica de Validación Global
        // ==========================================
        
        // Agrupamos las opciones que requieren lectura de datos (2 a 5).
        // Si elige alguna de ellas Y la matriz aun no se cargo (bandera en 0), bloqueamos el acceso.
        if ((opcion == 2 || opcion == 3 || opcion == 4 || opcion == 5) && matrizCargada == 0) {
            cout << "Aun no se ingreso la matriz\n";
        }

        // ==========================================
        // Lógica de las Opciones 2 a 5
        // ==========================================

        // Visualizacion: Imprimimos respetando el formato de grilla bidimensional
        if (opcion == 2 && matrizCargada == 1) {
            cout << "Matriz ingresada:\n";
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    // \t agrega una tabulacion para alinear las columnas
                    cout << matriz[i][j] << "\t";
                }
                cout << "\n";
            }
        }

        // Mayor Global: Asumimos que el primer elemento [0][0] es el mayor.
        // Luego lo comparamos contra todos los demas. Si encontramos uno mas grande, lo pisamos.
        if (opcion == 3 && matrizCargada == 1) {
            int mayor = matriz[0][0];
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    if (matriz[i][j] > mayor) {
                        mayor = matriz[i][j];
                    }
                }
            }
            cout << "El mayor elemento de toda la matriz es: " << mayor << "\n";
        }

        // Diagonal Principal: Son los elementos donde el indice de fila es igual al de columna (i == j).
        // Optimizacion: Usamos un solo for iterando 'i', leyendo directamente matriz[i][i].
        if (opcion == 4 && matrizCargada == 1) {
            int mayorDiagP = matriz[0][0];
            for (int i = 0; i < n; i++) {
                if (matriz[i][i] > mayorDiagP) {
                    mayorDiagP = matriz[i][i];
                }
            }
            cout << "El mayor elemento de la diagonal principal es: " << mayorDiagP << "\n";
        }

        // Diagonal Secundaria: Es la linea invertida. Mientras 'i' aumenta (baja de fila),
        // la columna retrocede desde el final (n - 1 - i).
        if (opcion == 5 && matrizCargada == 1) {
            int mayorDiagS = matriz[0][n - 1]; // Arrancamos en la esquina superior derecha
            for (int i = 0; i < n; i++) {
                if (matriz[i][n - 1 - i] > mayorDiagS) {
                    mayorDiagS = matriz[i][n - 1 - i];
                }
            }
            cout << "El mayor elemento de la diagonal secundaria es: " << mayorDiagS << "\n";
        }

        // ==========================================
        // Lógica de Salida y Errores del Menú
        // ==========================================

        // Si ingresa un numero fuera de las 6 opciones declaradas
        if (opcion < 1 || opcion > 6) {
            cout << "Opcion invalida. Intente nuevamente.\n";
        }
    }

    return 0; // Finaliza la ejecucion correctamente
}