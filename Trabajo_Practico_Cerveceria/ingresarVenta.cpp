// /Trabajo_Practico_Cerveceria/ingresarVenta.cpp
#include <iostream>
using namespace std;
void ingresarVenta(int &stock,int arr0 [],int &cont0,int arrL[],int &contL){
    char tipoVenta='X';//Le agrego un valor inicial que no sea ni 'O' ni 'L' para asegurar que entre al bucle de validacion
    int cantidad =-1; //inicializo cantidad en -1

    // Pedimos el tipo de venta al usuario
    cout << "Ingrese tipo de venta (O para Online, L para Local): ";
    cin >> tipoVenta;

    //Validar venta
    while(tipoVenta != 'O' && tipoVenta != 'o' && tipoVenta != 'L' && tipoVenta != 'l'){
    cout<<"Error. Ingrese unicamente 'O' o 'L': ";
    cin>>tipoVenta;
    }
    //Validar cantidad
    cout<<"Ingrese cantidad a vender(0 para cancelar).Stock actual: "<<stock<<": ";
    cin>>cantidad;
    while(cantidad<0||cantidad>stock){
        cout<<"Cantidad invalida o suepera el stock. Ingrese nuevamente: ";
        cin>>cantidad;
    }
    //Precesar la venta 
    if(cantidad>0){//anidamos la venta dentro de la validacion de cantidad para evitar procesar una venta cancelada
        if(tipoVenta=='O' ||tipoVenta == 'o'){
            arr0[cont0]=cantidad;
            cont0++;
        }else{
            arrL[contL]=cantidad;
            contL++;
        }
        // El stock se resta sin importar qué tipo de venta fue
        stock = stock - cantidad;
        cout << "Venta registrada con exito." << endl;
    }
    // Pedido con 0 cervezas se considera una cancelación, no se procesa la venta ni se modifica el stock.
    if (cantidad == 0) {
        cout << "Venta cancelada." << endl;
    }
}

