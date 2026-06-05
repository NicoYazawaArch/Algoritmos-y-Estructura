//Nicolas Corpus Ejercicio 2 - Trabajo Practico 1 - Algoritmos y Estructuras de Datos

#include <iostream>
using namespace std;

// CONSTANTES GLOBALES
const int MAX_CICLISTAS = 30;
const int CANT_CIRCUITOS = 5;

// Funcion para no repetir la busqueda de un DNI
int buscarCiclista(const int dnis[], int cantInscriptos, int dniBuscado) {
    int indice = -1; // -1 no lo encontro
    
    for (int i = 0; i < cantInscriptos; i = i + 1) {
        if (dnis[i] == dniBuscado) {
            indice = i; 
        }
    }
    return indice;
}

int ingresarOpcion() {
    int opc = 0;
    
    cout << "\n=========================================" << endl;
    cout << "   COMPETENCIA AMATEUR DE CICLISMO" << endl;
    cout << "=========================================" << endl;
    cout << "1. Inscribir un ciclista." << endl;
    cout << "2. Registrar tiempos de un circuito." << endl;
    cout << "3. Mostrar tiempos de un ciclista." << endl;
    cout << "4. Mostrar ganador/es." << endl;
    cout << "5. Salir." << endl;
    cout << "-----------------------------------------" << endl;
    cout << "Ingrese una opcion (1-5): ";
    
    cin >> opc;
    return opc;
}

void inscribirCiclista(int dnis[], int &cantInscriptos) {
    int dniIngresado = 0;
    int indice = -1;

    // Verifica si hay cupo antes de pedir
    if (cantInscriptos == MAX_CICLISTAS) {
        cout << "No se admiten mas inscriptos." << endl;
    } else {
        // Validacion del DNI
        cout << "Ingrese DNI del ciclista (Sin puntos): ";
        cin >> dniIngresado;

        while (dniIngresado < 10000000 || dniIngresado > 99999999) {
            cout << "DNI invalido. Ingrese un DNI entre 10000000 y 99999999: ";
            cin >> dniIngresado;
        }

        // Busca si ya esta registrado
        indice = buscarCiclista(dnis, cantInscriptos, dniIngresado);

        if (indice != -1) {
            // El indice del arreglo + 1 equivale al numero de pechera
            cout << "El ciclista ya esta inscripto. Su numero de pechera es: " << indice + 1 << endl;
        } else {
            // Lo agrega al arreglo
            dnis[cantInscriptos] = dniIngresado;
            cout << "Inscripcion exitosa. Numero de pechera asignado: " << cantInscriptos + 1 << endl;
            
            // Aumentar el contador de inscriptos
            cantInscriptos = cantInscriptos + 1;
        }
    }
}

// Pasa la matriz, requiere que la segunda dimension sea constante
void registrarTiempos(float tiempos[][CANT_CIRCUITOS], int cantInscriptos) {
    int numCircuito = 0;
    float tiempoIngresado = 0.0;

    if (cantInscriptos == 0) {
        cout << "No hay ciclistas inscriptos todavia." << endl;
    } else {
        cout << "Ingrese el numero de circuito (1 a " << CANT_CIRCUITOS << "): ";
        cin >> numCircuito;

        // Validacion de rango de circuito
        while (numCircuito < 1 || numCircuito > CANT_CIRCUITOS) {
            cout << "Circuito invalido. Ingrese nuevamente (1 a " << CANT_CIRCUITOS << "): ";
            cin >> numCircuito;
        }

        cout << "\n--- Ingresando tiempos para el Circuito " << numCircuito << " ---" << endl;
        
        // Recorre todos los ciclistas inscriptos para pedir su tiempo
        for (int i = 0; i < cantInscriptos; i = i + 1) {
            cout << "Ingrese el tiempo (en minutos) para la Pechera #" << i + 1 << ": ";
            cin >> tiempoIngresado;

            // Validam que el tiempo no sea negativo
            while (tiempoIngresado < 0) {
                cout << "El tiempo no puede ser negativo. Ingrese nuevamente: ";
                cin >> tiempoIngresado;
            }

            // Guarda el tiempo en la fila del ciclista (i) y la columna del circuito
            // Resta 1 al circuito para que coincida con los indices (0 a 4)
            tiempos[i][numCircuito - 1] = tiempoIngresado;
        }
        cout << "Tiempos registrados correctamente." << endl;
    }
}

void mostrarTiemposCiclista(const int dnis[], const float tiempos[][CANT_CIRCUITOS], int cantInscriptos) {
    int dniBuscado = 0;
    int indice = -1;

    if (cantInscriptos == 0) {
        cout << "No hay ciclistas inscriptos." << endl;
    } else {
        cout << "Ingrese el DNI del ciclista a consultar: ";
        cin >> dniBuscado;

        indice = buscarCiclista(dnis, cantInscriptos, dniBuscado);

        if (indice == -1) {
            cout << "No existe un ciclista con ese DNI." << endl;
        } else {
            cout << "\n--- Tiempos del ciclista con Pechera #" << indice + 1 << " ---" << endl;
            
            // Recorre los 5 circuitos del ciclista encontrado
            for (int j = 0; j < CANT_CIRCUITOS; j = j + 1) {
                // Solo mostra los circuitos que tengan un tiempo mayor a cero
                if (tiempos[indice][j] > 0) {
                    cout << "Circuito " << j + 1 << ": " << tiempos[indice][j] << " minutos." << endl;
                }
            }
        }
    }
}

void mostrarGanadores(const int dnis[], const float tiempos[][CANT_CIRCUITOS], int cantInscriptos) {
    float sumaTotal = 0.0;
    float menorTiempo = -1.0; 
    float totales[MAX_CICLISTAS]; 

    for (int i = 0; i < MAX_CICLISTAS; i = i + 1) {
        totales[i] = 0.0;
    }

    if (cantInscriptos == 0) {
        cout << "No hay ciclistas inscriptos para evaluar ganadores." << endl;
    } else {
        // Calculamos el tiempo total de cada ciclista
        for (int i = 0; i < cantInscriptos; i = i + 1) {
            sumaTotal = 0.0;
            
            for (int j = 0; j < CANT_CIRCUITOS; j = j + 1) {
                sumaTotal = sumaTotal + tiempos[i][j];
            }
            
            // Guardamos el total en el arreglo 
            totales[i] = sumaTotal;

            //Comparar para encontrar el menor tiempo valido
            if (sumaTotal > 0) {
                // Si es el primero que analizamos (-1) o si es menor al que teniamos guardado
                if (menorTiempo == -1.0 || sumaTotal < menorTiempo) {
                    menorTiempo = sumaTotal;
                }
            }
        }

        //Mostrar los ganadores 
        if (menorTiempo == -1.0) {
             cout << "Aun no hay tiempos registrados para calcular un ganador." << endl;
        } else {
             cout << "\n--- GANADOR/ES DE LA COMPETENCIA ---" << endl;
             cout << "Menor tiempo total: " << menorTiempo << " minutos." << endl;
             
             // Volvemos a recorrer para imprimir todos los que empataron con ese menor tiempo
             for (int i = 0; i < cantInscriptos; i = i + 1) {
                 if (totales[i] == menorTiempo) {
                     cout << "Pechera #" << i + 1 << " - DNI: " << dnis[i] << endl;
                 }
             }
        }
    }
}

// MAIN
int main() {
    //Matriz 1D
    int dnis[MAX_CICLISTAS];
    
    // Matriz 2D
    float tiempos[MAX_CICLISTAS][CANT_CIRCUITOS];
    
    int cantInscriptos = 0;
    int opcion = 0;

    // Inicializamos la matriz de tiempos en 0.0 para saber que estan vacios
    for (int i = 0; i < MAX_CICLISTAS; i = i + 1) {
        for (int j = 0; j < CANT_CIRCUITOS; j = j + 1) {
            tiempos[i][j] = 0.0;
        }
    }

    while (opcion != 5) {
        
        opcion = ingresarOpcion();

        switch (opcion) {
            case 1:
                cout << "\n--- INSCRIBIR CICLISTA ---\n";
                inscribirCiclista(dnis, cantInscriptos);
                break;
                
            case 2:
                cout << "\n--- REGISTRAR TIEMPOS ---\n";
                registrarTiempos(tiempos, cantInscriptos);
                break;
                
            case 3:
                cout << "\n--- CONSULTAR TIEMPOS DE UN CICLISTA ---\n";
                mostrarTiemposCiclista(dnis, tiempos, cantInscriptos);
                break;
                
            case 4:
                cout << "\n--- MOSTRAR GANADOR/ES ---\n";
                mostrarGanadores(dnis, tiempos, cantInscriptos);
                break;
                
            case 5:
                cout << "\nSaliendo del programa. ¡Hasta luego!\n";
                break;
                
            default:
                cout << "\nOpcion invalida. Intente nuevamente.\n";
                break; 
        }
    }

    return 0;
}