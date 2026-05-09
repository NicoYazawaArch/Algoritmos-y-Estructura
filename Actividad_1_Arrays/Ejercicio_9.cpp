/*
Diseñar e implementar en C++ los siguientes ejercicios.
Importante: Aplicar arreglos sólo cuando sea necesario.
9.Un algoritmo que solicite el ingreso de diez números enteros (de a uno) y muestre los
números que el usuario/a desee, en base a lo siguiente:
- Cuántos números desea filtrar?
- Los x primeros o los x últimos números ingresados? Indicar P para primeros o U para
últimos. Aclaración: x corresponderá a la cantidad ingresada por el usuario/a
previamente.
Según lo indicado por el usuario/a, deberán mostrarse los x primeros números
ingresados o los x últimos números ingresados, respetando su orden de carga.
Ejemplo 1:
Entrada de datos:
Ingresar diez números enteros:
4 0 6 8 -1 2 9 10 43 -12
Cuántos números desea filtrar?
4
Los 4 primeros o los 4 últimos números ingresados? Indicar P para primeros o U para
últimos.
U
Salida de datos:
9 10 43 -12 3
Ejemplo 2:
Entrada de datos:
Ingresar diez números enteros:
4 0 6 8 -1 2 9 10 43 -12
Cuántos números desea filtrar?
5
Los 5 primeros o los 5 últimos números ingresados? Indicar P para primeros o U para
últimos.
P
Salida de datos:
4 0 6 8 -1
*/

#include <iostream>
using namespace std;

int main() {
    int arreglo[10],filtrar;
    char respuesta;

    cout << "Ingresar diez numeros enteros:"<<endl;
    for (int i = 0; i < 10; i++) {
        cout << "Numero " << i + 1 << ": ";
        cin >> arreglo[i];
    }

    cout<<"\nCuantos numeros desea filtrar?: ";
    cin>>filtrar;
    // Validación básica: que no pida más de 10 ni menos de 0
    while (filtrar < 0 || filtrar > 10) {
        cout << "Error. Solo puede filtrar entre 0 y 10 numeros: ";
        cin >> filtrar;
    }


    // Elección de P o U
    cout<<"Como desea filtrar los numeros?, Ingrese P para primeros o U para ultimos: ";
    cin >> respuesta;
    while (respuesta!='P'&&respuesta!='p'&& respuesta != 'U' && respuesta != 'u'){
        cout<<"Respuesta invalida. Por favor ingrese P o U: ";
        cin>>respuesta;
    }

    if(respuesta=='P' || respuesta=='p'){
        cout<<"Los "<<filtrar<<" primeros numeros ingresados son: ";
        for (int i=0; i<filtrar; i++){//comenzamos desde 0 para obtener los primeros numeros ingresados
            cout<<arreglo[i]<<" ";
        }
    }
    else{
        cout<<"Los "<<filtrar<<" ultimos numeros ingresados son: ";
        for(int i=10-filtrar;i<10;i++){//comenzamos desde 10-filtrar para obtener los ultimos numeros ingresados
            cout<<arreglo[i]<<" ";
        }
    }

    cout << endl;
    return 0;
}
