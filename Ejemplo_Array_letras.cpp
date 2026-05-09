//Array con caracteres
#include <iostream>
using namespace std;


int main(){
    // '\0' es el caracter nulo que indica el final de una cadena de caracteres
    char letras[]={'a','b','c','d','e','\0'}; // se pueden usar '' para caracteres individuales
    char texto[]={"Arreglos de caracteres"}; // "" cadenas de caracteres, '' caracteres individuales
    cout<<texto<<endl;
    cout<<letras[2]<<endl; // muestra el valor de la posicion 2 del array letras


    return 0;
}