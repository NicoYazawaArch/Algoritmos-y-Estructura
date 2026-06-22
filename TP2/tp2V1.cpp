#include <iostream>
#include <cstring>
using namespace std;

// Estructura para almacenar la evaluacion
struct Evaluacion {
    int nota;
    char devolucion[100];
    char fechaEntrega[9];
    bool fueEvaluado;
};

// Estructura del Estudiante
struct Estudiante {
    char dni[11];
    char apellido[50];
    char nombre[50];
};

void ingresarEstudiantes(Estudiante curso[], int &cantidadActual) {
    bool quiereContinuar = true;
    char opcionContinuar[2];

    while (quiereContinuar && cantidadActual < 50) {

        cout << "\n--- INGRESO DE ESTUDIANTE N" << (cantidadActual + 1) << " ---" << endl;

        // Validar DNI (Longitud 10, formato nn.nnn.nnn)
        bool dniValido = false;
        while (dniValido == false) {
            cout << "Ingrese el DNI (10 caracteres, ej: 11.222.333): ";
            cin >> curso[cantidadActual].dni;

            if (strlen(curso[cantidadActual].dni) == 10) {
                dniValido = true;
            }
            else {
                cout << "Error: El DNI debe tener exactamente 10 caracteres." << endl;
            }
        }
        cin.ignore();

        // Validar Apellido No vacío
        bool apellidoValido = false;
        while (apellidoValido == false) {
            cout << "Ingrese el Apellido: ";
            cin.getline(curso[cantidadActual].apellido, 50);

            if (strlen(curso[cantidadActual].apellido) > 0) {
                apellidoValido = true;
            } else
            {
                cout << "Error: El apellido no puede ser vacio." << endl;
            }
        }

        // Validar Nombre No vacío
        bool nombreValido = false;
        while (nombreValido == false) {
            cout << "Ingrese el Nombre: ";
            cin.getline(curso[cantidadActual].nombre, 50);

            if (strlen(curso[cantidadActual].nombre) > 0) {
                nombreValido = true;
            }
            else {
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
        }
        else {
            cout << "Se ha alcanzado el cupo maximo de 50 estudiantes." << endl;
            quiereContinuar = false;
        }
    }
}

void ingresarNotasTP(Estudiante curso[], Evaluacion matrizTPs[][16], int cantidadActual) {
    if (cantidadActual == 0) {
        cout << "Error: No hay estudiantes cargados en el curso." << endl;
        return;
    }

    int numeroTP = 0;
    bool tpValido = false;

    // Ingresar y validar el número de TP
    while (tpValido == false) {
        cout << "\nIngrese el numero de Trabajo Practico (1 a 16): ";
        cin >> numeroTP;

        if (numeroTP >= 1 && numeroTP <= 16) {
            tpValido = true;
        }
        else {
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
        while (notaValida == false) {
            cout << "Ingrese la nota (1 a 10): ";
            cin >> matrizTPs[i][indiceTP].nota;

            if (matrizTPs[i][indiceTP].nota >= 1 && matrizTPs[i][indiceTP].nota <= 10) {
                notaValida = true;
            }
            else {
                cout << "Error: La nota debe estar comprendida entre 1 y 10." << endl;
            }
        }

        cin.ignore();

        // Validar Devolucion no vacía
        bool devolucionValida = false;
        while (devolucionValida == false) {
            cout << "Ingrese la devolucion: ";
            cin.getline(matrizTPs[i][indiceTP].devolucion, 100);

            if (strlen(matrizTPs[i][indiceTP].devolucion) > 0) {
                devolucionValida = true;
            }
            else {
                cout << "Error: La devolucion no puede ser vacia." << endl;
            }
        }

        // Validar Fecha de Entrega , formato dd/mm/aa
        bool fechaValida = false;
        while (fechaValida == false) {
            cout << "Ingrese la fecha de entrega (formato dd/mm/aa): ";
            cin.getline(matrizTPs[i][indiceTP].fechaEntrega, 9);

            if (strlen(matrizTPs[i][indiceTP].fechaEntrega) == 8) {
                fechaValida = true;
            }
            else {
                cout << "Error: La fecha de entrega debe tener exactamente 8 caracteres (dd/mm/aa)." << endl;
            }
        }

        //Esta validado
        matrizTPs[i][indiceTP].fueEvaluado = true;

        i++;
    }

    cout << "\nEvaluaciones del TP " << numeroTP << " cargadas correctamente para todos los estudiantes." << endl;
}

void modificarNotaTP(Estudiante curso[], Evaluacion matrizTPs[][16], int cantidadActual) {
    if (cantidadActual == 0) {
        cout << "Error: Aún no hay estudiantes cargados en el sistema." << endl;
        return;
    }

    // Ingresar y validar el DNI a buscar
    char dniBuscado[11];
    bool dniValido = false;

    while (dniValido == false) {
        cout << "\nIngrese el DNI del estudiante a modificar (10 caracteres): ";
        cin >> dniBuscado;

        if (strlen(dniBuscado) != 10) {
            cout << "Error: El DNI debe tener exactamente 10 caracteres." << endl;
        }
        else {
            dniValido = true;
        }
    }

    // Buscar al estudiante en el arreglo
    int i = 0;
    int indiceEstudiante = -1;
    bool estudianteEncontrado = false;

    while (i < cantidadActual && estudianteEncontrado == false) {
        if (strcmp(curso[i].dni, dniBuscado) == 0) {
            indiceEstudiante = i;
            estudianteEncontrado = true;
        }
        i++;
    }

    if (estudianteEncontrado == false) {
        cout << "No existe un/a estudiante con ese DNI" << endl;
        return;
    }

    // Mostrar datos personales
    cout << "\nEstudiante encontrado: " << curso[indiceEstudiante].dni << " | "
    << curso[indiceEstudiante].apellido << ", " << curso[indiceEstudiante].nombre << endl;

    // Ingresar y validar número de TP
    int numeroTP = 0;
    bool tpRangoValido = false;

    while (tpRangoValido == false) {
        cout << "\nIngrese el numero de Trabajo Practico (1 a 16): ";
        cin >> numeroTP;

        if (numeroTP < 1 || numeroTP > 16) {
            cout << "Error: El numero de TP debe estar entre 1 y 16." << endl;
        }
        else {
            tpRangoValido = true;
        }
    }

    int indiceTP = numeroTP - 1;

    // Validar si el TP fue cargado
    if (matrizTPs[indiceEstudiante][indiceTP].fueEvaluado == false) {
        cout << "Aún no se cargaron las evaluaciones de ese trabajo práctico" << endl;
        return;
    }

    // Impresión formato: fecha | nota | devolución
    cout << "\nEvaluacion actual: " << matrizTPs[indiceEstudiante][indiceTP].fechaEntrega
    << " | " << matrizTPs[indiceEstudiante][indiceTP].nota
    << " | " << matrizTPs[indiceEstudiante][indiceTP].devolucion << endl;

    // Modificación
    char opcionModificar[2];
    cout << "\n¿Desea modificar esta evaluación? (S para Si, N para No): ";
    cin >> opcionModificar;

    if (strcmp(opcionModificar, "S") == 0 || strcmp(opcionModificar, "s") == 0) {

        bool notaValida = false;
        while (notaValida == false) {
            cout << "Ingrese la nueva nota (1 a 10): ";
            cin >> matrizTPs[indiceEstudiante][indiceTP].nota;

            if (matrizTPs[indiceEstudiante][indiceTP].nota < 1 || matrizTPs[indiceEstudiante][indiceTP].nota > 10) {
                cout << "Error: La nota debe estar comprendida entre 1 y 10." << endl;
            }
            else {
                notaValida = true;
            }
        }

        cin.ignore();

        bool devolucionValida = false;
        while (devolucionValida == false) {
            cout << "Ingrese la nueva devolucion: ";
            cin.getline(matrizTPs[indiceEstudiante][indiceTP].devolucion, 100);

            if (strlen(matrizTPs[indiceEstudiante][indiceTP].devolucion) == 0) {
                cout << "Error: La devolucion no puede ser vacia." << endl;
            }
            else {
                devolucionValida = true;
            }
        }

        bool fechaValida = false;
        while (fechaValida == false) {
            cout << "Ingrese la nueva fecha de entrega (dd/mm/aa): ";
            cin.getline(matrizTPs[indiceEstudiante][indiceTP].fechaEntrega, 9);

            if (strlen(matrizTPs[indiceEstudiante][indiceTP].fechaEntrega) != 8) {
                cout << "Error: La fecha de entrega debe tener 8 caracteres." << endl;
            }
            else {
                fechaValida = true;
            }
        }

        cout << "\nLa evaluación del trabajo práctico fue modificada correctamente." << endl;
    }
    else {
        cout << "No se realizaron modificaciones." << endl;
    }
}

void mostrarReporte(Estudiante curso[], Evaluacion matrizTPs[][16], int cantidadActual) {
    if (cantidadActual == 0) {
        cout << "No hay estudiantes cargados para mostrar el reporte." << endl;
        return;
    }

    cout << "\n========== REPORTE DEL CURSO ==========" << endl;

    int i = 0;
    while (i < cantidadActual) {
        cout << "\n" << curso[i].dni << " | " << curso[i].apellido << ", " << curso[i].nombre << endl;

        bool aprobo = true;
        bool tieneTPsEvaluados = false;
        int j = 0;

        // Recorremos las columnas de la matriz para el estudiante 'i'
        while (j < 16) {
            if (matrizTPs[i][j].fueEvaluado == true) {
                tieneTPsEvaluados = true;

                if (matrizTPs[i][j].nota < 7) {
                    aprobo = false;
                }
            }
            j++;
        }

        if (tieneTPsEvaluados == false) {
            aprobo = false;
        }

        if (aprobo == true) {
            cout << "Curso aprobado" << endl;
        }
        else {
            cout << "Curso desaprobado" << endl;
        }

        j = 0;
        while (j < 16) {
            if (matrizTPs[i][j].fueEvaluado == true) {
                cout << "TP" << (j + 1) << " | "
                     << matrizTPs[i][j].fechaEntrega << " | "
                     << matrizTPs[i][j].nota << " | "
                     << matrizTPs[i][j].devolucion << endl;
            }
            j++;
        }

        cout << "---------------------------------------" << endl;
        i++;
    }

    cout << "=======================================" << endl;
}

int main() {
    // ARREGLOS / MATRICES
    Estudiante curso[50] = {};

    // LA MATRIZ DE 50 FILAS (ESTUDIANTES) Y 16 COLUMNAS (TPs)
    Evaluacion matrizTPs[50][16] = {};

    int cantidadActual = 0;
    int opcion = 0;

    // Bucle del menú principal
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

        cin.ignore();

        switch (opcion) {
            case 1:
                ingresarEstudiantes(curso, cantidadActual);
                break;
            case 2:
                ingresarNotasTP(curso, matrizTPs, cantidadActual);
                break;
            case 3:
                modificarNotaTP(curso, matrizTPs, cantidadActual);
                break;
            case 4:
                mostrarReporte(curso, matrizTPs, cantidadActual);
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
