#include <iostream>
#include <cstring>
using namespace std;

void ingresarTexto(char texto[],int maximo);
void obteberPrimeraPalabra(char texto[],char primeraPalabra[]);

void obtenerPrimeraPalabra(char texto[], char primeraPalabra[])
{
    int i=0;
    while(texto[i]!=' ' and texto[i]!=',' and texto[i]!='.' and texto[i]!='\0')
    {
        primeraPalabra[i]=texto[i];
        i++;
    }
    primeraPalabra[i]='\0';
}


void ingresarTexto(char texto[],int maximo){
  cout<<"Ingrese el texto: ";
  cin.getline(texto,maximo);
  while(strlen(texto)==0){
    cout<<"El texto no puede estar vacio. Ingrese el texto: ";
    cin.getline(texto,maximo);
  }
}
char ingresarCaracter(){
  char caracter=' ';
  cin.ignore(); // Limpiar el buffer de entrada para evitar que tome un salto de linea previo
  cout<<"Ingrese un caracter: ";
  //cin.get(caracter);
  cin>>caracter;
  while(caracter=='\n'){
    cout<<"El caracter no puede estar vacio. Ingrese un caracter: ";
    cin.get(caracter);
  }
  return caracter;
}

int contarRepeticiones(char texto[],char caracter){
    int tamanio=strlen(texto);
    int repeticionesCaracter=0;
    for(int i=0;i<tamanio;i++){
        if(texto[i]==caracter){
            repeticionesCaracter++;
        }
    }
    return repeticionesCaracter;
}
