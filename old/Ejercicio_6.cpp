#include<iostream>
using namespace std;

int main(){
    float nota,suma=0,promedio,contador=0; //a suma le empezamos su valor en 0 
    int respuesta;
    while(respuesta==1){
        cout<<"Ingrese la nota: ";
        cin>>nota;
        cin.ignore();
        suma=suma+nota;
        cout<<"Desea continuar? 1 Para Si o 0(cero) para No"<<"\n";
        cin>>respuesta;
        cin.ignore();
        contador=contador+1;
    }


//promedios y calculos    
    promedio=suma/contador;
    cout<<"El promedio es: "<<promedio<<"\n";

     if (promedio>=7)
    {
        cout<<"Promocionado  \n";

    }
    else if (promedio>=4)
    { 
        cout<< "Aprobado \n";
        
    }
    else
    {
        cout<< "Desaprobado \n";
    }


return 0;
}