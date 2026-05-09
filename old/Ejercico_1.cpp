#include<iostream>
using namespace std;
/*
Plantear un algoritmo que reciba como datos de entrada dos notas (del TP1 y del TP2),
y muestre como salida:
a) el promedio de ellas
b) y además indique si el/la estudiante desaprobó o aprobó – sabiendo que: “con un
promedio desde 4 se aprueba”.
Nota: Considerar que las notas son valores reales comprendidos entre 1 y 10 – y son
ingresados correctamente. */

//definimos primero las variables que se van a usar(Para asignar el espacio de memoria)
//int sumar(int numero1 , int numero2); para declara un nombre y sus argumentos de ingreso 
//C++ funciona con bloques de codigo entre {} no le importa si hay tabulacion o los espcion mientras este dentro del bloque en orden 
int main() {

    // Se pone la documentacion dentro de la funcion para saber que hace luego cuando se la llamaen otro programa
    // Declarar variables.
    float nota1,nota2,nota3,nota4,nota5,promedio,resultado; //asigna que tipo de dato va a ser este caso flotante
    // Cuerpo del algoritmo 
    //1) Ingresar primera nota y guardamos en nota1
    cout << "Ingrese la primera nota: "; //cout seria consola, << le dice que el mensaje va a la salida  
    cin >> nota1; // >> guarda el valor en la variable 
    cin.ignore(); //Limpia la consola para proximos ingresos , se limpia el buffer

    // 2) Ingresar segunda nota y guardamos en nota2
    cout<<"Ingrese la segunda nota: ";
    cin>>nota2;
    cin.ignore();

    cout << "Ingrese la tercera nota: ";
    cin>>nota3;
    cin.ignore();

    cout << "Ingrese la cuarta nota: ";
    cin>>nota4;
    cin.ignore();

    cout << "Ingrese la quinta nota: ";
    cin>>nota5;
    cin.ignore();

    // 3) Calculamos el promedio
    promedio= (nota1+nota2+nota3+nota4+nota5)/5;

    // 4) Mostramos el promedio
    cout << "El promedio de la nota es : " << promedio << "\n";

    // 5) Evaluamos el promedio y mostramos si esta aprobado o desaprobado
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

    //Fin del programa. (Return)




   return 0;
}


