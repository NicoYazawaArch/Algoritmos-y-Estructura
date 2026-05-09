/*
 Plantear un algoritmo que reciba como datos de entrada cinco notas (del TP1 al TP5),
y muestre como salida:
a) el promedio de ellas
b) indique si el/la estudiante desaprobó, aprobó o promocionó – sabiendo que: “con
un promedio desde 4 se aprueba y desde 7 se promociona”.
Nota: Considerar que las notas son valores reales comprendidos entre 1 y 10 – y son
ingresados correctamente.
*/

#include <iostream>
using namespace std;

int main(){

    float notas,calculo=0,promedio;
    for(int i=1;i<=5;i++){
        cout<<"Ingrese las notas: ";
        cin>>notas;
        cin.ignore();
        calculo+=notas;
    }

    promedio=calculo/5;
    cout<<"El promedio es: "<<promedio<<"\n";

    if(promedio>=7){
        cout<<"Promociono ";
    }
    else if (promedio>=4){
        cout<<"Aprobo";
    }
    else{
        cout<<"Desaprobo";
    }

    return 0;
}