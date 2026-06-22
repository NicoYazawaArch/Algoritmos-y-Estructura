struct producto {
    char nombre[20];
    char descripcion[50];
    float precioUnitario;
};

struct promocion {
float descuento;
float topeReintegro; };

/*
1. La función permite agregar un nuevo producto, sabiendo que no se admiten dos productos con el mismo nombre.
void agregarNuevoProducto(producto productos[50],unsigned short int &cantidad, producto nuevoProducto)
Recibe como entradas:
- El arreglo productos según lo detallado en A) y B) cargado con los productos existentes hasta el momento.
- El parámetro cantidad con el total de productos cargados en el arreglo productos.
- El parámetro nuevoProducto cargado con los campos: nombre, descripcion y precioUnitario del nuevo producto
que desea agregarse al arreglo productos.
La función debe validar que en el arreglo productos no exista un producto con el mismo nombre que el nuevoProducto
recibido:
- Si ya existe, no debe agregarlo al arreglo. Simplemente debe mostrar el mensaje: “El producto ya existe . Su
código es: x”, siendo x el código del producto existente.
- Si no existe, debe agregarlo al arreglo productos (a continuación del último producto existente), actualizar el
parámetro cantidad y finalmente mostrar el mensaje: “El producto se agregó correctamente. Su código es: x”,
siendo x el código asignado.
Nota: Al agregar el nuevoProducto al arreglo productos, no deben modificarse los datos ya existentes en el arreglo.
*/

void AgregarProducto(producto productos[50],unasigned short int &cantidad, producto nuevoProducto){
    int i ,codigoExistente=0;
    bool existe=false;
    
    while(i<cantidad && existe==false){
        if(strcmp(productos[i].nombre,nuevoProducto.nombre)==0){//para saber si la cadena es identica
        existe=true;
        codigoExistente=i+1 //Se mueve como un indice
        }
        i++;
    if(existe==true){cout << "El producto ya existe. Su código es: " << codigoExistente << endl;}
    else{
        if(cantidad<50){
            productos[cantidad]=nuevoProducto;
            cantidad++;
            cout<<"El producto se agrego correctamente.Su codigo es: "<<cantidad<<endl;
        }
        else {
            cout << "Error: No hay espacio para agregar más productos." << endl;
        }
    }
    }
}
/*
2. La función busca la primera promoción de un mes determinado.
bool buscarPrimeraPromocionDelMes(promocion promociones[31][12], unsigned short int mes, promocion &primeraPromocion, unsigned short int &dia)
Recibe como entradas:
- La matriz promociones según lo detallado en A) y C). Las promociones que aún no fueron cargadas tienen
todos sus campos en cero (son promociones no disponibles).
- El parámetro mes cargado con el número del mes a evaluar (valor entre 1 y 31).
- El parámetro primeraPromocion donde quedará almacenada la primera promoción del mes con los campos:
descuento y topeReintegro.
- El parámetro dia donde quedará almacenado el número del día del mes correspondiente a la
primeraPromocion.
Tomando como base la matriz promociones, la función debe buscar cuál es la primera promoción disponible del mes
recibido en mes:
- Si existe:
o Debe dejar almacendo: en primeraPromocion esa promoción y en dia el número del día del mes
asociado.
o Y por último, retornar “true”.
- En caso contrario, simplemente debe retornar “false”.
Nota: Hacer las suposiciones que considere necesarias mientras no sean contrarias al enunciado. Es necesario
aclararlas.
*/

bool buscarPrimeraPromocionDelMes(promocion promociones[31][12], unsigned short int mes,promocion &primeraPromocion, unsigned short int &dia){
    int indiceMes=mes-1 ,f=0; //mes 1 esta en la columna 0, f son las filas 
    bool encontrada=false;
    while(f<31&&encontrada==false){
        if(promedio[f][indiceMes].descuento!=0){
            primeraPromocion=promociones[f][indiceMes];
            dia=f+1;
            encontrada=true;
        }
        else{f++;}//Se avanza si no promociona
    }
    return encontrada;
}