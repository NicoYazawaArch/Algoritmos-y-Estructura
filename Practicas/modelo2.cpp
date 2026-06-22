#include<iostream>
#include<cstring>
using namespace std;

struct producto{
    char nombre[20];
    char descripcion[50];
    float precioUnitario;
};

struct promocion{
    float descuento;
    float topReintegro;
};
// 1.
void agregarNuevoProducto(producto productos[50],unsigned short int &cantidad, producto nuevoProducto){
    int codigoExistente=0, i=0;
    bool existe=false;
    while(i<cantidad&&existe==false){
        if (strcmp(productos[i].nombre, nuevoProducto.nombre)==0){
            existe=true;
            codigoExistente=i++;
        }i++;
    }
    if(existe == true){
        cout<<"El producto ya existe, Su codigo es: "<<codigoExistente<<endl;
    }else{
        if(cantidad<50){
            productos[cantidad]=nuevoProducto;
            cantidad++;
            cout<<"El producto se agrego correctamente"<<endl;
        }else{
            cout<<"Error: No hay espacio para agregar mas productos."<<endl;
        }
        }
    }


// 2.
bool buscarPrimeraPromocionDelMes(promocion promociones[31][12],unsigned short int mes,promocion &primeraPromocion, unsigned short int &dia){
    int indiceMes=mes-1,f=0;//La columna del mes (Mes 1 esta en la columna 0). f las filas
    bool encontrada=false;

    while(f<31&&encontrada==false){
        if(promociones[f][indiceMes].descuento!=0){
            primeraPromocion=promociones[f][indiceMes];
            dia=f+1;


        }
    }



}