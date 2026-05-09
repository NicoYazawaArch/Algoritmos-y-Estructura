//Array letras interactivo
#include <iostream>
using namespace std;

int main(){
    // se asigna un espacio de memoria para 8 caracteres, incluyendo el caracter nulo '\0' que indica el final de la cadena
    char texto[8];
    cout<<"Ingrese un texto: ";
    // se utiliza getline para leer una línea completa de texto, limitando la entrada a 7 caracteres más el caracter nulo
    cin.getline(texto, 8);
    cout<<"Texto ingresado: "<<texto<<endl;
    return 0;
}
