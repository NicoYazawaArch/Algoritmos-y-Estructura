/*
1.Plantear un algoritmo que reciba como entrada cinco números enteros y muestre como
salida cuántas veces se ingresó el número 3 
– respetando lo siguiente:
- Se ingresan los cinco números enteros (de a uno).
- Se muestra la cantidad de veces que se ingresó el 3.
*/
#include <iostream>
using namespace std;

int main(){
int numIngresos,contadornum=0,arreglos[5],contadortres=0;

/*cout<<"Ingrese un numero: ";
cin>>numIngresos;
cin.ignore(); */

while(contadornum!=5){

    cout<<"Ingrese un numero: ";
    cin>>arreglos[contadornum];
    cin.ignore();
    

    if(arreglos[contadornum]==3){
        contadortres++;
    }
    contadornum++;

}
    cout<<"Se ingresaron esta cantidad de numeros 3: "<<contadortres<<endl;
    for (int i=0;i<5;i++){
        cout<<arreglos[i]<<" ";
    }
    return 0;
}