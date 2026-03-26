/*
Ejercicio 1: A partir de un valor ingresado por el usuario (el cual deberá estar​
comprendido entre 2 y 9, inclusive), generar y mostrar todos los múltiplos del​
mismo menores a 100, primero en forma ascendente y luego en sentido inverso​
dentro del mismo programa.
*/

#include <iostream>
using namespace std;
int main(){
    int numero;
    cout<<"Ingrese un numero entre 2 y 9: ";
    cin>>numero;
    cin.ignore();
    while(numero <2  || numero >9){
        cout<<"Numero invalido, ingrese un numero entre 2 y 9: ";
        cin>>numero;
        cin.ignore();
    }
    // Calcula el múltiplo más alto menor a 100 aprovechando el truncamiento de la división entera.
    // Ejemplo con 7: (99/7) es 14.14, C++ lo toma como 14. Luego 14 * 7 = 98.
    int maxMultiplo= (99/numero)*numero; 
    
    cout<<"\nAscendente: ";
    for (int i=numero; i<=maxMultiplo; i+=numero){
        cout<<i<<" ";

        if(i ==maxMultiplo){
            cout<<"\nDescendente: ";
            for(int j=maxMultiplo; j>=numero; j-=numero){
                cout<<j<<" ";
            }
        }

    }
    return 0;
}