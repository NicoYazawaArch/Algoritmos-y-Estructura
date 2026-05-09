/*
Ejercicio 3:
a) Control de precios de productos en un comercio
Un comercio está realizando un control de precios de sus productos. Se deben
ingresar los precios de los productos uno por uno, mientras el promedio de todos los
precios ingresados sea menor a $20. Al finalizar, informar cuántos productos fueron
registrados.
b) Control adicional de cantidad máxima de productos
Modificar el sistema anterior para que, además de controlar que el promedio de
precios sea menor a $20, también se asegure que no se registren más de 100
productos. Si se alcanza ese límite, el ingreso de precios debe detenerse
automáticamente.
*/
#include <iostream>
using namespace std;

int main(){
    float precio, suma=0, promedio=0;
    int contador=0,preciosmax=20,productosmax=100;

    cout<<"Ingrese el precio de los productos(-1 para finalizar): ";
    cin>>precio;
    cin.ignore();
    while(precio!=-1 && contador < productosmax && promedio <preciosmax){
        suma+=precio;
        contador++;
        promedio=suma/contador;

        if(promedio < preciosmax && contador < productosmax){
            cout<<"Promedio actual: $"<<promedio<<endl;
            cout<<"Ingrese el precio de los productos(-1 para finalizar): ";
            cin>>precio;
            cin.ignore();
        }
    }

    cout<<"\n---- Control Finalizado ---- \n";
    if (promedio>=preciosmax){
        cout<<"Motivo: El promedio ($"<<promedio<< ") alcanzo o supero el limite de $"<<preciosmax <<endl;
    }
    else if(contador>=productosmax){
        cout<<"Motivo: Se alcanzo el limite maximo de "<<productosmax<<" productos"<<endl;

    }
    else{
        cout<<"Finalizado por el usuario.\n";
    }

    cout << "Total de productos registrados: " << contador << endl;
    cout << "Suma total: $" << suma << endl;
    cout << "Promedio final: $" << promedio << endl;


    return 0;
}