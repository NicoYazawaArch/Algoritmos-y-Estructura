/*
Diseñar e implementar en C++ los siguientes ejercicios.
Importante: Aplicar arreglos sólo cuando sea necesario.
3-Un algoritmo que solicite el ingreso de diez números enteros (de a uno) y muestre como
salida el menor de ellos.
*/


#include <iostream>
using namespace std;

int main(){
    int numeros,menor; //si pongo menor=0 no va a funcionaria si se ingresan numeros negativos
    for(int i=0; i<10; i++){
        cout<<"Ingrese un numero: ";
        cin>>numeros;
        cin.ignore();
        if(numeros<menor){
            menor=numeros;
        }
    }
    cout<<"El menor numero es: "<<menor<<endl;

    return 0;
}