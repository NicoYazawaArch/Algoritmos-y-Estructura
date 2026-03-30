/*
Diseñar e implementar en C++ los siguientes ejercicios.
Importante: Aplicar arreglos sólo cuando sea necesario.
1. Un algoritmo que solicite el ingreso de diez números enteros (de a uno) y muestre como
salida el promedio de ellos.
*/
#include <iostream>
using namespace std;

int main(){
int numeros,contador=0;
float promedio=0 ,suma=0;
for(int i=0; i<10; i++){
    cout<<"Ingrese un numero: ";
    cin>>numeros;
    cin.ignore();
    suma+=numeros;
    contador++;
}
promedio=suma/contador;
cout<<"El promedio es: "<<promedio<<endl;

return 0;
}
