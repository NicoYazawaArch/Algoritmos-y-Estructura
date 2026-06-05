#include <iostream>
using namespace std;

int buscarCiclista(int dniCiclistas[30], int totalInscriptos,
int dniBuscado){
    int pechera=0;

    for(int i=0;i<totalInscriptos&&pechera==0;i++){
        if(dniCiclistas[i]==dniBuscado){
            pechera=1+i;
        }
    }
    return pechera;
}

void mostrarCiclistasPrimerPuesto(float tiempos[30][5],int totalInscriptos){
    float TiemposTotales[30],TiempoGanador=0.0,SumaFila=0.0;
    for(int i=0;i<totalInscriptos;i++){
        for(int j=0;j<5;j++){
            SumaFila+=tiempos[i][j];
        }
        TiemposTotales[i]=SumaFila;

        if(i==0||SumaFila<TiempoGanador){
            TiempoGanador=SumaFila;
        }
    }
    cout<<"Ciclistas en primer puesto (Tiempo: "<<TiempoGanador<<" min):"<<endl;
    for(int i=0;i<totalInscriptos;i++){
        if(TiemposTotales[i]==TiempoGanador){
            cout<<"Ciclista numero: "<<(i+1)<<endl;
        }
    }

}