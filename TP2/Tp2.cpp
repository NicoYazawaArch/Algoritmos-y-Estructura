#include <iostream>
#include <cstring> 

using namespace std;
//Estructura para almacena la informacion 
struct Evaluacion {
    int nota;
    char devolucion[100]; 
    char fechaEntrega[9]; 
    bool fueEvaluado; 
};

struct Estudiante {
    char dni[11]; 
    char apellido[50];
    char nombre[50];
    Evaluacion tps[16];
};

void ingresarEstudiantes(Estudiante curso[], int &cantidadActual) {
    bool quiereContinuar = true;
    char opcionContinuar[2]; 

    while (quiereContinuar && cantidadActual < 50) {
        
        cout << "\n--- INGRESO DE ESTUDIANTE N" << (cantidadActual + 1) << " ---" << endl;

        // 1. Validar DNI (Longitud 10, formato nn.nnn.nnn)
        bool dniValido = false;
        while (dniValido==false) {
            cout << "Ingrese el DNI (10 caracteres, ej: 11.222.333): ";
            cin >> curso[cantidadActual].dni;

            if (strlen(curso[cantidadActual].dni) == 10) {
                dniValido = true;
            } else {
                cout << "Error: El DNI debe tener exactamente 10 caracteres." << endl;
            }
        }
        cin.ignore(); 

        // 2. Validar Apellido No vacío
        bool apellidoValido = false;
        while (apellidoValido==false) {
            cout << "Ingrese el Apellido: ";
            cin.getline(curso[cantidadActual].apellido, 50); 

            if (strlen(curso[cantidadActual].apellido) > 0) {
                apellidoValido = true;
            } else {
                cout << "Error: El apellido no puede ser vacio." << endl;
            }
        }

        // 3. Validar Nombre No vacío
        bool nombreValido = false;
        while (nombreValido==false) {
            cout << "Ingrese el Nombre: ";
            cin.getline(curso[cantidadActual].nombre, 50); 

            if (strlen(curso[cantidadActual].nombre) > 0) {
                nombreValido = true;
            } else {
                cout << "Error: El nombre no puede ser vacio." << endl;
            }
        }

        cantidadActual++; 

        if (cantidadActual < 50) {
            cout << "¿Desea ingresar un nuevo/a estudiante? (S para si, otra tecla para no): ";
            cin >> opcionContinuar;
            
            if (strcmp(opcionContinuar, "S") != 0 && strcmp(opcionContinuar, "s") != 0) {
                quiereContinuar = false; 
            }
        } else {
            cout << "Se ha alcanzado el cupo maximo de 50 estudiantes." << endl;
            quiereContinuar = false;
        }
    }
}

void ingresarNotasTP(Estudiante curso[], int cantidadActual) {
    if (cantidadActual == 0) {
        cout << "Error: No hay estudiantes cargados en el curso." << endl;
        // Retornamos de la función ya que no hay a quién cargarle notas
        return; 
    }

    int numeroTP = 0;
    bool tpValido = false;

    // Ingresar y validar el número de TP
    while (tpValido==false) {
        cout << "\nIngrese el numero de Trabajo Practico (1 a 16): ";
        cin >> numeroTP;

        if (numeroTP >= 1 && numeroTP <= 16) {
            tpValido = true;
        } else {
            cout << "Error: El numero de TP debe estar entre 1 y 16." << endl;
        }
    }
    int indiceTP = numeroTP - 1;

    cout << "\n--- CARGANDO EVALUACIONES PARA EL TP " << numeroTP << " ---" << endl;

    // Iterar sobre todos los estudiantes cargados
    int i = 0;
    while (i < cantidadActual) {
        cout << "\nEstudiante: " << curso[i].dni << " | " << curso[i].apellido << ", " << curso[i].nombre << endl;

        // Validar Nota (entre 1 y 10)
        bool notaValida = false;
        while (notaValida==false) {
            cout << "Ingrese la nota (1 a 10): ";
            cin >> curso[i].tps[indiceTP].nota;

            if (curso[i].tps[indiceTP].nota >= 1 && curso[i].tps[indiceTP].nota <= 10) {
                notaValida = true;
            } else {
                cout << "Error: La nota debe estar comprendida entre 1 y 10." << endl;
            }
        }

        cin.ignore();

        // Validar Devolucion no vacía
        bool devolucionValida = false;
        while (devolucionValida==false) {
            cout << "Ingrese la devolucion: ";
            cin.getline(curso[i].tps[indiceTP].devolucion, 100);

            if (strlen(curso[i].tps[indiceTP].devolucion) > 0) {
                devolucionValida = true;
            } else {
                cout << "Error: La devolucion no puede ser vacia." << endl;
            }
        }

        // Validar Fecha de Entrega (longitud de 8, formato dd/mm/aa)
        bool fechaValida = false;
        while (fechaValida==false) {
            cout << "Ingrese la fecha de entrega (formato dd/mm/aa): ";
            cin.getline(curso[i].tps[indiceTP].fechaEntrega, 9); // 8 chars + 1 del '\0'

            if (strlen(curso[i].tps[indiceTP].fechaEntrega) == 8) {
                fechaValida = true;
            } else {
                cout << "Error: La fecha de entrega debe tener exactamente 8 caracteres (dd/mm/aa)." << endl;
            }
        }

        // Marcamos este TP específico como evaluado para este estudiante
        curso[i].tps[indiceTP].fueEvaluado = true;

        i++; // Pasamos al siguiente estudiante
    }

    cout << "\nEvaluaciones del TP " << numeroTP << " cargadas correctamente para todos los estudiantes." << endl;
}

void modificarNotaTP(Estudiante curso[], int cantidadActual) {
    if (cantidadActual == 0) {
        cout << "Error: Aún no hay estudiantes cargados en el sistema." << endl;
        return;
    }

    // 1. Ingresar y validar el DNI a buscar
    char dniBuscado[11];
    bool dniValido = false;
    
    while (dniValido == false) {
        cout << "\nIngrese el DNI del estudiante a modificar (10 caracteres): ";
        cin >> dniBuscado;

        if (strlen(dniBuscado) == 10) {
            dniValido = true;
        } else {
            cout << "Error: El DNI debe tener exactamente 10 caracteres." << endl;
        }
    }

    // 2. Buscar al estudiante en el arreglo
    int i = 0;
    int indiceEstudiante = -1; // Usamos -1 para indicar que aún no lo encontramos
    bool estudianteEncontrado = false;

    while (i < cantidadActual && estudianteEncontrado == false) {
        // strcmp devuelve 0 si ambas cadenas son exactamente iguales
        if (strcmp(curso[i].dni, dniBuscado) == 0) {
            indiceEstudiante = i;
            estudianteEncontrado = true;
        }
        i++;
    }

    // Si terminó el ciclo y no lo encontró, mostramos el mensaje y salimos 
    if (estudianteEncontrado == false) {
        cout << "No existe un/a estudiante con ese DNI" << endl;
        return; 
    }

    // 3. Mostrar datos personales del estudiante encontrado [cite: 52]
    cout << "\nEstudiante encontrado: " << curso[indiceEstudiante].dni << " | " 
         << curso[indiceEstudiante].apellido << ", " << curso[indiceEstudiante].nombre << endl;

    // 4. Ingresar número de Trabajo Práctico y validar rango (1 a 16)
    int numeroTP = 0;
    bool tpRangoValido = false;

    while (tpRangoValido == false) {
        cout << "\nIngrese el numero de Trabajo Practico (1 a 16): ";
        cin >> numeroTP;

        if (numeroTP >= 1 && numeroTP <= 16) {
            tpRangoValido = true;
        } else {
            cout << "Error: El numero de TP debe estar entre 1 y 16." << endl;
        }
    }

    int indiceTP = numeroTP - 1;

    // 5. Validar que el TP haya sido cargado previamente 
    if (curso[indiceEstudiante].tps[indiceTP].fueEvaluado == false) {
        cout << "Aún no se cargaron las evaluaciones de ese trabajo práctico" << endl;
        return; // Salimos de la opción 
    }

    // Si es válido, mostrar la evaluación actual 
    cout << "\nEvaluacion actual: " 
         << curso[indiceEstudiante].tps[indiceTP].fechaEntrega << " | "
         << curso[indiceEstudiante].tps[indiceTP].nota << " | "
         << curso[indiceEstudiante].tps[indiceTP].devolucion << endl; 

    // 7. Consultar si desea modificar 
    char opcionModificar[2];
    cout << "\n¿Desea modificar esta evaluación? (S para Si, N para No): ";
    cin >> opcionModificar;

    // Si responde "S" o "s", pedimos los nuevos datos
    if (strcmp(opcionModificar, "S") == 0 || strcmp(opcionModificar, "s") == 0) {
        
        // Modificar Nota 
        bool notaValida = false;
        while (notaValida == false) {
            cout << "Ingrese la nueva nota (1 a 10): ";
            cin >> curso[indiceEstudiante].tps[indiceTP].nota;

            if (curso[indiceEstudiante].tps[indiceTP].nota >= 1 && curso[indiceEstudiante].tps[indiceTP].nota <= 10) {
                notaValida = true;
            } else {
                cout << "Error: La nota debe estar comprendida entre 1 y 10." << endl;
            }
        }

        cin.ignore();

        // Modificar Devolución
        bool devolucionValida = false;
        while (devolucionValida == false) {
            cout << "Ingrese la nueva devolucion: ";
            cin.getline(curso[indiceEstudiante].tps[indiceTP].devolucion, 100);

            if (strlen(curso[indiceEstudiante].tps[indiceTP].devolucion) > 0) {
                devolucionValida = true;
            } else {
                cout << "Error: La devolucion no puede ser vacia." << endl;
            }
        }

        // Modificar Fecha de Entrega 
        bool fechaValida = false;
        while (fechaValida == false) {
            cout << "Ingrese la nueva fecha de entrega (dd/mm/aa): ";
            cin.getline(curso[indiceEstudiante].tps[indiceTP].fechaEntrega, 9);

            if (strlen(curso[indiceEstudiante].tps[indiceTP].fechaEntrega) == 8) {
                fechaValida = true;
            } else {
                cout << "Error: La fecha de entrega debe tener 8 caracteres." << endl;
            }
        }

        cout << "\nLa evaluación del trabajo práctico fue modificada correctamente." << endl;
    } else {
        cout << "No se realizaron modificaciones." << endl;
    }
}


void mostrarReporte(Estudiante curso[], int cantidadActual) {
    if (cantidadActual == 0) {
        cout << "No hay estudiantes cargados para mostrar el reporte." << endl;
        return;
    }

    cout << "\n========== REPORTE DEL CURSO ==========" << endl;

    int i = 0;
    while (i < cantidadActual) {
        // Mostrar DNI | apellido, nombre
        cout << "\n" << curso[i].dni << " | " << curso[i].apellido << ", " << curso[i].nombre << endl;

        // Determinar si el curso está aprobado o desaprobado
        bool aprobo = true;
        bool tieneTPsEvaluados = false;
        int j = 0;

        // Recorremos los 16 posibles TPs para verificar las notas
        while (j < 16) {
            if (curso[i].tps[j].fueEvaluado == true) {
                tieneTPsEvaluados = true; // Confirmamos que al menos rindió uno
                
                if (curso[i].tps[j].nota < 7) {
                    aprobo = false; // Si hay un TP menor a 7, desaprueba
                }
            }
            j++;
        }

        // Si no se evaluó ningún TP en todo el cuatrimestre, no puede estar aprobado
        if (tieneTPsEvaluados == false) {
            aprobo = false;
        }

        // Mostrar estado
        if (aprobo == true) {
            cout << "Curso aprobado" << endl;
        } else {
            cout << "Curso desaprobado" << endl;
        }

        // Mostrar el detalle de cada TP evaluado
        j = 0; // Reiniciamos el contador 'j' para volver a recorrer el arreglo de TPs
        while (j < 16) {
            if (curso[i].tps[j].fueEvaluado == true) {
                // Formato: TPx | fecha de entrega | nota | devolucion
                cout << "TP" << (j + 1) << " | " 
                     << curso[i].tps[j].fechaEntrega << " | " 
                     << curso[i].tps[j].nota << " | " 
                     << curso[i].tps[j].devolucion << endl;
            }
            j++;
        }
        
        cout << "---------------------------------------" << endl;
        i++; // Pasamos al siguiente estudiante 
    }
    
    cout << "=======================================" << endl;
}

int main() {
    // 1. Declaración de las variables principales
    Estudiante curso[50]={}; // Arreglo para almacenar hasta 50 estudiantes, inicia sin valores definidos
    int cantidadActual = 0;
    int opcion = 0;

    //El bucle del menú principal Se repite hasta elegir 5
    while (opcion != 5) {
        cout << "\n=========================================" << endl;
        cout << "       SISTEMA DE GESTION DE CURSOS      " << endl;
        cout << "=========================================" << endl;
        cout << "1. Ingresar estudiantes." << endl;
        cout << "2. Ingresar las notas de un trabajo practico." << endl;
        cout << "3. Modificar la nota del trabajo practico de un/a estudiante." << endl;
        cout << "4. Mostrar reporte del curso." << endl;
        cout << "5. Salir." << endl;
        cout << "=========================================" << endl;
        cout << "Seleccione una opcion: ";
        cin >> opcion;

        // Limpiamos el buffer por las dudas después de ingresar el número de opción
        cin.ignore();

        //switch 
        switch (opcion) {
            case 1:
                ingresarEstudiantes(curso, cantidadActual);
                break;
            case 2:
                ingresarNotasTP(curso, cantidadActual);
                break;
            case 3:
                modificarNotaTP(curso, cantidadActual);
                break;
            case 4:
                mostrarReporte(curso, cantidadActual);
                break;
            case 5:
                cout << "\nSaliendo del programa... ¡Hasta luego!" << endl;
                break;
            default:
                cout << "\nError: Opcion incorrecta. Por favor, intente nuevamente." << endl;
                break;
        }
    }

    return 0;
}