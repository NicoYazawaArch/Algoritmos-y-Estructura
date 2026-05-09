#include<iostream>
using namespace std;

int main(){
    float nota,suma=0,promedio; //a suma le empezamos su valor en 0 
    //El for se parece al while de python
    //El for declara sus propias variables que solo se usan en for
    for (int i=0; i<5; i++) // primera inicia con valor X ,llega hasta X, ingrementa valor de i++ 
    {
        cout<< "Ingrese la primera nota: ";
        cin>>nota;
        cin.ignore();
        suma=suma+nota;
    }
    promedio=suma/5;
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