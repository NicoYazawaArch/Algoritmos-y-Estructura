/*
Diseñar e implementar en C++ los siguientes ejercicios.
Importante: Aplicar arreglos sólo cuando sea necesario.
7.Un algoritmo que solicite el ingreso de diez números enteros (de a uno) y muestre como
salida:
- El mayor número ingresado.
- La o las posiciones donde ese número mayor fue ingresado (considere que pudo
haber sido ingresado más de una vez).
Ejemplo:
Entrada de datos:
Ingresar diez números enteros:
4
13
6
50
-1
7
9
*/

#include <iostream>
using namespace std;

int main(){
    int arreglo[10],mayor;

    cout<<"Ingrese un numero: ";
    cin>>arreglo[0];
    mayor=arreglo[0]; //inicializamos el mayor con el primer numero ingresado
    for(int i=1; i<10; i++){//iniciamos el ciclo desde 1 porque ya ingresamos el primer numero
        cout<<"Ingrese un numero: ";
        cin>>arreglo[i];
        if(arreglo[i]>mayor){
            mayor=arreglo[i];
        }
    }
    cout << "\n------ Resultados ------" << endl;
    cout << "El mayor numero ingresado es: " << mayor << endl;
    cout << "Posiciones donde aparece: ";
    for(int i=0; i<10;i++){//Buscamos las posiciones donde se encuentra el mayor numero
        if (arreglo[i]==mayor){
            cout<<i + 1<<" ";//imprimimos la posicion sumando 1 para que sea mas entendible
        }
    }
    cout << endl; //limpiar salida en terminal
    return 0;
}