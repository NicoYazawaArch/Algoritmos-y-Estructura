#include <iostream>
using namespace std;

//menu de opciones para el usuario. Retorna la opcion elegida por el usuario.
int ingresarOpcion(){
    int opcion;
    cout<<"---- MENU ---- "<<endl;
    cout<<"1. Ingresar un consumo especifico."<<endl;
    cout<<"2. Mostrar consumo de la primera quincena."<<endl;
    cout<<"3. Mostrar consumo de la segunda quincena."<<endl;
    cout<<"4. Mostrar consumo total del mes."<<endl;
    cout<<"5. Salir."<<endl;
    cout<<"Ingrese una opcion: ";
    cin>>opcion;
    cin.ignore();
    return opcion;

}

//Funcion para validar el dia ingresado por el usuario. Recibe como parametros el primer y ultimo dia permitido, y retorna un dia valido.
int ingresarDiaValido(int primerDia,int ultimoDia){
    int diaIngresado; //variable local
    cout<<"Dia: ";
    cin>>diaIngresado;
    cin.ignore();
    while(diaIngresado<primerDia or diaIngresado>ultimoDia){// or o &&
        cout<<"Dia Invalido. Intente nuevamente."<<endl;
        cin>>diaIngresado;
        cin.ignore();
    }
    return diaIngresado;//retorna el dia ingresado, que es valido0
}
//Funcion para validar el consumo ingresado por el usuario. Recibe como parametro el menor consumo permitido, y retorna un consumo valido.
int ingresarConsumoValido(int menorConsumoPermitido){
    int consumoIngresado;
    cout<<"Consumo: ";
    cin>>consumoIngresado;
    cin.ignore();
    while(consumoIngresado<menorConsumoPermitido){
        cout<<"Consumo Invalido. Intente nuevamente."<<endl;
        cin>>consumoIngresado;
        cin.ignore();
    }
    return consumoIngresado; //es un valor booleano, pero lo usamos como int para facilitar su uso en el arreglo de consumos. Si es 0, no hay consumo registrado. Si es mayor a 0, es un consumo valido.

}

void cargarConsumo(int consumos[31],int diaRecibido,int consumoRecibido){
    char respuesta;
    /*La variable esta recibiendo la direccion del arreglo no el arreglo 
    completo. Es la referecia del arreglo osea su valor en posicion */
    if (consumos[diaRecibido-1]!=0){
        cout<<"El dia "<<diaRecibido<<" ya tiene cargado un consumo de: "<<consumos[diaRecibido-1]<<"."<<endl;
        cout<<endl<<"Desea modificarlo? (s/n): ";
        cin>>respuesta;
        cin.ignore();
        if(respuesta=='s' or respuesta=='S'){
            consumos[diaRecibido-1]=ingresarConsumoValido(1);
            cout<<"Consumo se actualizo correctamente."<<endl;
        }
        else{
            consumos[diaRecibido-1]=consumoRecibido;
            cout<<"Consumo se mantuvo sin cambios."<<endl;
        }
    }
}
int calcularConsumoTotal(int consumos[31],int diaDesde,int diaHasta){
    int totalCalculado=0;
    for(int i=diaDesde-1;i<diaHasta;i++){
        totalCalculado+=consumos[i];
    }
return totalCalculado;
}
//Base del programa
int main(){
    int consumos[31]={0},opcion=0,dia,consumo,total;
    while(opcion!=5){
        opcion=ingresarOpcion();
        switch(opcion){
            case 1:
            cout<<"---- Ingreso de un consumo especifico ---- "<<endl;
            //dia=ingresarDiaValido(1,31);
            //consumo=ingresarConsumoValido(1);
            //cargarConsumo(consumos,dia,consumo);
            cargarConsumo(consumos,ingresarDiaValido(1,31),ingresarConsumoValido(1));
            break;
            case 2:
            cout<<"---- Consumo primera quincena ---- "<<endl;
            total=calcularConsumoTotal(consumos,1,15);
            cout<<"El Consumo de la primera quincena fue: "<<total<<endl;
            break;
            case 3:
            cout<<"---- Consumo segunda quincena ---- "<<endl;
            total=calcularConsumoTotal(consumos,16,31);
            cout<<"El Consumo de la segunda quincena fue: "<<total<<endl;
            break;
            case 4:
            cout<<"---- Consumo total del mes ---- "<<endl;
            total=calcularConsumoTotal(consumos,1,31);
            cout<<"El Consumo total del mes fue: "<<total<<endl;
            break;
            case 5:
            cout<<"Saliendo del programa..."<<endl;
            break;
            default:
            cout<<"Opcion Invalida. Intente nuevamente."<<endl;

        }
    }
}