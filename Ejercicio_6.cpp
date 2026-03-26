/*
Plantear un algoritmo que reciba como datos de entrada:
- La cantidad de notas a ingresar.
- A posterior, cada una de esas notas (del TP1 en adelante).
Y muestre como salida:
a) el promedio de ellas
b) indique si el/la estudiante desaprobó, aprobó o promocionó – sabiendo que: “con
un promedio desde 4 se aprueba y desde 7 se promociona”.
Nota: Considerar que las notas son valores reales comprendidos entre 1 y 10 – y son
ingresados correctamente.
*/

#include <iostream>
using namespace std;

int main(){
    int cantidadNotas=0,entrada=1; float notas,calculo=0,promedio=0;

    cout<<"Quiere ingresar notas Si=1 No=0; ";
    cin>>entrada;
    while(entrada==1){
        cout<<"Ingrese la nota: ";
        cin>>notas;
        cin.ignore();
        
        calculo+=notas;
        cantidadNotas++;

        cout<<"Quiere seguir ingresar notas Si=1 No=0; ";
        cin>>entrada;
    }
    promedio=calculo/cantidadNotas;
    cout<<"El promedio es: " << promedio<<"\n";
    
    if(promedio>=7){
        cout<<"Promociono";        
    }
    else if(promedio>=4){
        cout<<"Aprobo";
    }
    else{
        cout<<"Desaprobo";
    }
    return 0;
}