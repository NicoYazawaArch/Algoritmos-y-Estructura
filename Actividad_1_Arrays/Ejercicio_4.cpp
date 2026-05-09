/*
Diseñar e implementar en C++ los siguientes ejercicios.
Importante: Aplicar arreglos sólo cuando sea necesario.
4.Un algoritmo que solicite el ingreso de diez números enteros (de a uno) y muestre como
salida:
- El promedio de ellos.
- El listado de todos los números cargados respetando el orden de ingreso (del
primero al último).
*/

#include <iostream>
using namespace std;

int main(){
    int arreglo[10];
    float promedio=0,suma=0;
    for(int i=0; i<10; i++){
        cout<<"Ingrese un numero: ";
        cin>>arreglo[i];
        suma+=arreglo[i];
    }
    promedio=suma/10;
    cout<<"------ Resultados ------"<<endl;
    cout<<"El promedio de los numeros ingresados es: "<<promedio<<endl;
    cout<<"El listado de los numeros ingresados es: ";
    for (int i=0;i<10;i++){
        cout<<arreglo[i]<<" ";

    }
    cout << endl; //limpiar salida en terminal 

    return 0;
}