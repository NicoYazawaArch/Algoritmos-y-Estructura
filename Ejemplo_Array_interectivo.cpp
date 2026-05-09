//Array interactivo
#include <iostream>
using namespace std;

int main(){
    int array[8];
    for(int i=0; i<8; i++){//limitar el ingreso a 8 elementos
        cout<<"Posicion: "<<i<<endl;
        cout<<"Ingrese un numero: ";
        cin>>array[i];
    }
    //para mostrar el array completo
    for (int i=0; i<8; i++){
        cout<< array[i]<< " ";

    }

    return 0;
}