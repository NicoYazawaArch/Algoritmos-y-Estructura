#include <iostream>
using namespace std;


unsigned short int buscarCiclista(unsigned int dniCiclistas[30], unsigned short int totalInscriptos, unsigned int dniBuscado) {
    unsigned short int pecheraEncontrada = 0;
    for (unsigned short int i=0;i<totalInscriptos&&pecheraEncontrada==0;i++) {
        if (dniCiclistas[i] == dniBuscado) {
            pecheraEncontrada = i + 1;
        }
    }
    return pecheraEncontrada;
}

void mostrarCiclistasPrimerPuesto(float tiempos[30][5], unsigned short int totalInscriptos){
    float tiemposTotales[30] ,tiempoGanador=0.0,sumarFila=0.0;
    for (unsigned short int i=0;i<totalInscriptos;i++){
        for(int j=0;j<5;j++){
            sumaFila+=tiempos[i][j];
        }
        tiempoTotales[i]=sumaFila;

        if(i==0||sumaFila<tiempoGanador){
            tiempoGanador=sumaFila;
        }
    }
    cout << "Ciclistas en primer puesto (Tiempo: " << tiempoGanador << " min):" << endl;
    for (unsigned short int i = 0; i < totalInscriptos; i++) {
        if (tiemposTotales[i] == tiempoGanador) {
            cout << "Ciclista numero: " << (i + 1) << endl;
        }
    }


}