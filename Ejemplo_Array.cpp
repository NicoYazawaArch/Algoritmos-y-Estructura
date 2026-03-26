//array: es un espacio de memoria contigua de un mismo tipo y tamaño fijo 
//el espacio no puede cambiar durante la ejecucion
#include <iostream>
using namespace std;

int main(){
    //[n] dentro se pone la cantidad de elementos para asignar en memoria empieza con 0
    int edad[5] = {19,20,56,34,25}; 
    for (int i=0; i<=5 ; i++){
        //edad[i] es un puntero que muestra el valor del elemento en la posicion i
        cout << edad[i]<< " Posicion:"<< i << endl;
    }

    

    return 0;
}

/*
int edad[5] = {19,20,56,34,25};
for (int i=0; i<=5 ; i++){
19 Posicion:0
20 Posicion:1
56 Posicion:2
34 Posicion:3
25 Posicion:4
0 Posicion:5

si ponemo i<=5 al no existir la posicion 5 el programa muestra un valor basura 0 
que no pertenece al array. Para evitar esto se debe poner i<5 o i<=4 para que el programa 
solo muestre los valores del array.

*/
