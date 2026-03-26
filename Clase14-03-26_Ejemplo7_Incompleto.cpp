#include<iostream>
using namespace std;
int main()
{
	//DECLARACIÓN DE VARIABLES.
	float nota,suma=0,promedio;
	int respuesta=1;
	//CUERPO DEL ALGORITMO.
	//1) Mientras el usuario/a lo desee se ingresa una a una cada nota en la variable nota y se acumula su sumatoria en la variable suma
	while(respuesta==1)
	{
		cout << "Ingrese una nota: ";
		cin >> nota;
		cin.ignore();
		suma=suma+nota;
		cout << "Desea continuar? Ingrese 1 (para si) y 0 (para no): ";
		cin >> respuesta;
		cin.ignore();
	}
	//2) Se calcula el promedio de las notas ingresadas
	promedio=suma/5; // Suponiendo que se ingresaron 5 notas
	//3) Se muestra el promedio
	cout << "El promedio de las notas es: " << promedio << endl;
	
	//FIN DEL PROGRAMA.
	return 0;
}
