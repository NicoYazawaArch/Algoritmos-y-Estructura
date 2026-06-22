#include <iostream>
#include <cstring> 

using namespace std;

struct Taller{
    char titulo[100];
    char descripcion[200];
    int duracion;
};

void ingresarTalleresDia(Taller congreso[][50],int cantidadPorDia[]){
int dia=0,indiceDia=0,col=0;
bool diaValido=false, quiereContinuar = true,tituloValido=false,descValida,duracionValida = false;
char opcionContinuar;
//Validar ingreso.
while(diaValido==false){
    cout<<"Ingrese el dia del taller (1,2 o 3): ";
    cin>>dia;

    if(dia>=1 && dia<=3){
        diaValido=true;
    }else{
        cout<<"Error: el dia debe ser 1,2 o 3."<<endl;

    }
}
//Adaptamos el dia al indice de la matriz (Dia 1 = Indice 0)
int indiceDia=dia-1;//La declaramos aqui para que se mantenga el valor durante todo el proceso de carga de talleres para ese dia

//Ciclo de carga mientras quiera seguir y no supere el limite
while(quiereContinuar == true && cantidadPorDia[indiceDia]<50){
    int col= cantidadPorDia[indiceDia]; //La columna actual para el dia seleccionado
    cout<<"\n--- CARGANDO TALLER  "<<(col+1)<<" Para el dia"<<dia<<" ---"<<endl;
    //Reinicio de variables
    tituloValido = false;
    descValida = false;
    duracionValida = false;
    cout << "\n--- CARGANDO TALLER " << (col + 1) << " PARA EL DIA " << dia << " ---" << endl;
    cin.ignore();

    while(tituloValido==false){
        cout<<"Ingrese el titulo del taller. ";
        //Validamos que el titulo no sea vacio, getline para permitir espacios
        cin.getline(congreso[indiceDia][col].titulo,100);
        //Si el titulo tiene mas de 0 caracteres, es valido
        //strlen funciona para obtener la longitud de la cadena, si es mayor a 0, no esta vacia
        if(strlen(congreso[indiceDia][col].titulo)>0){//strlen devuelve la longitud de la cadena, si es mayor a 0, no esta vacia
            tituloValido=true;
        }else{
            cout<<"Error: el titulo no puede ser vacio."<<endl;
        }
    }
    while(descValida==false){
        cout<<"Ingrese la descripcon del taller";
        cin.getline(congreso[indiceDia][col].descripcion,200);
        if(strlen(congreso[indiceDia][col].descripcion)>0){
            descValida=true;
        }else{
            cout<<"Error: la descripcion no puede ser vacia."<<endl;
        }
    }
    while(duracionValida==false){
        cout<<"Ingrese la duracion estimada en minutos";
        cin>>congreso[indiceDia][col].duracion;

        if(congreso[indiceDia][col].duracion>0){
            duracionValida=true;
        }else{
            cout<<"Error: la duracion debe ser mayor a 0."<<endl;
        }
    }
    cantidadPorDia[indiceDia]++;//Incrementamos la cantidad de talleres para ese dia
    //Consultar si continua
    if(cantidadPorDia[indiceDia]<50){
        cout<<"Desea ingresar otro taller para el dia "<<dia<<"? (S/N): ";
        cin>>opcionContinuar;
        if(opcionContinuar!='S' && opcionContinuar!='s'){
            quiereContinuar=false;
        }
    }
}
}

void visualizarMayorDuracion(Taller congreso[][50], int cantidadPorDia[]){
    int dia=0, indiceDia=0,maxDuracion=0,indiceMayor=0 , c=0;
    bool diaValido=false;
    //Validar ingreso del dia 
    while(diaValido==false){
        cout<<"\nIngrese el dia a consultar(1,2 o 3): ";
        cin>>dia;

        if(dia>=1 && dia<=3){
            diaValido=true;
        }else{
            cout<<"Error: el dia debe ser 1,2 o 3. "<<endl;
        }
    }

    indiceDia=dia-1;
    //Validacion de segurirdad por si se eligien un dia sin talleres cargados
    if(cantidadPorDia[indiceDia]==0){
        return; //Forzar salida no hay talleres para mostrar 
    }
    //inicio y reinicio de variables para la busqueda
    maxDuracion=-1;
    indiceMayor=0;
    c=0;

    //Recorremos los talleres del dia seleccionadopara buscar el de mayor duracion
    while(c<cantidadPorDia[indiceDia]){
        if(congreso[indiceDia][c].duracion>maxDuracion){
            maxDuracion=congreso[indiceDia][c].duracion;
            indiceMayor=c; //guardamos posicion del taller de mayor duracion
        }
        c++;
    }
    // Impresión de resultados
    cout << "\n=== TALLER DE MAYOR DURACION (DIA " << dia << ") ===" << endl;
    cout << "Titulo: " << congreso[indiceDia][indiceMayor].titulo << endl;
    cout << "Descripcion: " << congreso[indiceDia][indiceMayor].descripcion << endl;
    cout << "Duracion: " << congreso[indiceDia][indiceMayor].duracion << " minutos." << endl;
    cout << "==========================================" << endl;
}