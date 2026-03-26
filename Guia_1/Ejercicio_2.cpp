/*
Ejercicio 2: De una lista de personas se ingresa su edad. La carga termina cuando
en la edad se ingresa el valor -1.
Se pide indicar:
1.​ Cuál de todos ellos es el mayor (suponer único).
2.​ Cuántos de ellos son menores de edad (17 años o menos).
3.​ Cuántos de ellos están en edad laboral activa (hasta 65 años, inclusive).
4.​ Mostrar las edades de quiénes están por jubilarse (única para ambos sexos)
*/

#include <iostream>
using namespace std;

int main(){
int edad, mayor=0, menor=0, laboral=0,jubilados=0,jubilables=0;

cout<<"Ingrese la edad de las personas (Ingrese -1 para finalizar): ";
cin>>edad;
cin.ignore();
while(edad!=-1){
    if (edad>mayor){
        mayor=edad;
    }
    if (edad<=17){
        menor++;
    }
    if (edad>=18 && edad<=65){
        laboral++;
    }
    if (edad>=60 && edad <=65){
        jubilables++;
        cout<<"--> Edad cercana a jubilacion:"<< edad << endl;
    }
    if (edad > 65) {
            jubilados++;
        }
    
    cout<<"Ingrese la edad de las personas (Ingrese -1 para finalizar): ";
    cin>>edad;
    cin.ignore();
}

cout<<"\n---- Resultados ---- \n";
cout<<"El mayor tiene: "<<mayor<<" años.\n";
cout<<"Cantidad de menores de edad: "<<menor<<endl;
cout<<"Cantidad de personas en edad laboral: "<<laboral<<endl;
cout<<"Cantidad de personas cercanas a la jubilacion: "<<jubilables<<endl;
cout<<"Cantidad de personas jubiladas: "<<jubilados<<endl;
return 0;
}