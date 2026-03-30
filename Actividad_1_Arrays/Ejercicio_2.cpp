/*
Diseñar e implementar en C++ los siguientes ejercicios.
Importante: Aplicar arreglos sólo cuando sea necesario.
2.Un algoritmo que solicite el ingreso de diez números enteros (de a uno) y muestre como
salida el mayor de ellos.

*/
#include <iostream>
using namespace std;

int main(){
    int numeros,mayor=0;
    for(int i=0; i<10; i++){
        cout<<"Ingrese un numero: ";
        cin>>numeros;
        cin.ignore();
        if(numeros>mayor){
            mayor=numeros;
        }
    }
    cout<<"El mayor numero es: "<<mayor<<endl;

    return 0;
}