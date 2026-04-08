/*
Diseñar e implementar en C++ los siguientes ejercicios.
Importante: Aplicar arreglos sólo cuando sea necesario.
8. Un algoritmo que solicite el ingreso de diez números enteros (de a uno) y muestre los
números que el usuario/a desee, en base a lo siguiente:
Qué números desea filtrar?
Ingresar P si desea filtrar los números ingresados en posiciones pares.
Ingresar I si desea filtrar los números ingresados en posiciones impares.
Según lo indicado por el usuario/a, deberán mostrarse los números ingresados en
posiciones pares (el 2°, el 4°, el 6°, el 8° y 10° - en ese orden) o los números ingresados
en posiciones impares (el 1°, el 3°, el 5°, el 7° y el 9° - en ese orden).
Ejemplo 1:
Entrada de datos:
Ingresar diez números enteros:
4 13 6 8 -1 7 9 10 43 -12
Qué números desea filtrar?
Ingresar P si desea filtrar los números ingresados en posiciones pares.
Ingresar I si desea filtrar los números ingresados en posiciones impares.
P
Salida de datos:
13 8 7 10 -12
Ejemplo 2:
Entrada de datos:
Ingresar diez números enteros:
4 13 6 8 -1 2 7 9 10 43 -12
Qué números desea filtrar?
Ingresar P si desea filtrar los números ingresados en posiciones pares.
Ingresar I si desea filtrar los números ingresados en posiciones impares.
I
Salida de datos:
4 6 -1 9 43
*/

#include <iostream>
using namespace std;

int main() {
    int arreglo[10];
    char respuesta;

    //Carga de los 10 números dde forma mas ordenada 
    cout << "Ingresar diez numeros enteros:" << endl;
    for (int i = 0; i < 10; i++) {
        cout << "Numero " << i + 1 << ": ";
        cin >> arreglo[i];
    }
    //Preguntas al usuario
    cout<<"\nQue numeros desea filtrar?"<<endl;
    cout<<"Ingresar P si desea filtrar los numeros ingresados en posiciones pares."<<endl;
    cout<<"Ingresar I si desea filtrar los numeros ingresados en posiciones impares."<<endl;
    cout<<"Respuesta: ";
    cin>>respuesta;
    //validar si la respuesta es correcta, si no lo es, pedir nuevamente
    //Este ciclo se repetira hasta que el usuario ingrese una respuesta valida (P, p, I o i)
    while (respuesta!='P'&&respuesta!='p'&& respuesta != 'I' && respuesta != 'i'){
        cout<<"Respuesta invalida. Por favor ingrese P o I: ";
        cin>>respuesta;
    }

    if(respuesta=='I' || respuesta=='i'){
        for (int i=0;i<10;i=i+2){//posiciones impares, comenzando desde 0 que es la posicion 1 en el orden de ingreso  
            //El for se incrementa de a 2 para saltar las posiciones pares y solo imprimir las impares
            cout<<arreglo[i]<<" ";
        }
    }

    else{
        for (int i=1;i<10;i=i+2){
            //posiciones pares, comenzando desde 1 que es la posicion 2 en el orden de ingreso
            //El for se incrementa de a 2 para saltar las posiciones impares y solo imprimir las pares
            cout<<arreglo[i]<<" ";
        }
    }

    cout << endl;
    return 0;
}