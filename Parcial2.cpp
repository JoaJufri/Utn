

/*Una empresa de transporte público de ómnibus desea un programa para procesar los los viajes que realizan.

Para ello cuentan con un lote de información con todos los viajes del año anterior, para cada registro se tiene:

-Día de la venta (1 a 31)

-Mes (1 a 12)

-Local de venta (1 a 5)

-Ciudad de origen (string[3])

-Ciudad de destino (string[3])

-Cantidad de pasajes vendidos

Puede haber varias ventas para el mismo día, para el mismo local de venta, etc.

El fin de este lote se indica con un registro con cantidad de pasajes igual a 0.
Además cuentan con los datos de las ciudades que tienen como destino:

-Código de ciudad (string[3])

-Nombre de la ciudad (string[30])

Este lote está ordenado por código de ciudad y hay un total de 100 ciudades.
Y un lote de tarifas y distancias entre ciudades:

-Código de ciudad de origen (string[3])

-Código de ciudad de destino (string[3])

-Distancia en kms

-Precio por pasaje


Este lote finaliza con un registro con distancia igual a 0.
No todas las ciudades están unidas con las otras y hay como máximo 500 combinaciones.



Ejemplo:

Origen Destino Distancia Precio

BAS MDP 400 30

COR SFE 450 35

Nota: El viaje de Buenos Aires a Mar del Plata aparece una sola vez en el lote, es decir no vuelve a repetirse como origen MDP y destino BAS ya que la distancia y precio son iguales.
Pero en el lote de ventas los pasajes se pueden vender en cualquiera de los dos sentidos BAS a MDP o MDP a BAS.

La empresa espera obtener del programa la siguiente información:

a) El nombre de la ciudad a la que hayan viajado mayor cantidad total de pasajeros en cada mes del año.

b) La recaudación total del año discriminada por local de venta.

c) El nombre de la ciudad de origen en la que se haya gastado la mayor cantidad de dinero en viajes.

d) Un listado top 10 con los destinos más visitados. Se deberá mostrar el nombre de la ciudad y su respectiva cantidad, ordenados de mayor a menor.*/

#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;


//Struct lote 1
struct Ciudades
{
    char Codigo[3],Ciudad[30];
};

//Struct lote 2
struct Tarifas
{
    char CodigoDestino[3], CodigoOrigen[3];
    float Precio, DistanciaKm;
};

//Buscar indice
int BuscarCiudad(char codigo_ciudad[3], Ciudades Vciudades[]) {

    for (int i = 0; i < 100; i++)
    {
        if (Vciudades[i].Codigo == codigo_ciudad)
        {
            return i;
        }
        
    }
    
}

//Obtener precio segun codigo de ciudad

float PrecioDeVenta(char cod_origen[3], char cod_destino[3], Tarifas Vtarifas[], int pasajes_vendidos) {
    
    for (int i = 0; i < 500; i++)
    {
        if (Vtarifas[i].CodigoOrigen == cod_origen && Vtarifas[i].CodigoDestino == cod_destino)
        {
            return (Vtarifas[i].Precio*pasajes_vendidos);
        }

        if (Vtarifas[i].CodigoOrigen == cod_destino && Vtarifas[i].CodigoDestino == cod_origen)
        {
            return (Vtarifas[i].Precio*pasajes_vendidos);
        }
        
    }
    
}

float TotalCiudadOrigen(char cod_origen[3], char cod_destino[3], Tarifas Vtarifas[], int pasajes_vendidos){

    for (int i = 0; i < 500; i++)
    {
        if (Vtarifas[i].CodigoOrigen == cod_origen && Vtarifas[i].CodigoDestino == cod_destino)
        {
            return (Vtarifas[i].Precio * pasajes_vendidos);
        }
        
    }
    
}

int main()
{   
    //Var de lote de carga
    Ciudades Vciudades[100];
    Tarifas Vtarifas[500];

    for (int i = 0; i < 500; i++)
    {
        Vtarifas[i].Precio = 0;
        Vtarifas[i].DistanciaKm = 0;
    }

    //Lote de carga Ciudades-Codigos
    for (int i = 0; i < 100; i++)
    {
        cout<<"Nombre de la ciudad: "<<endl;
        cin>>Vciudades[i].Ciudad;
        cout<<"Codigo de la ciudad: "<<endl;
        cin>>Vciudades[i].Codigo;

    }
    
    
    //2do Lote de carga (Tarifas)
    int pos=0;
    cout<<"Distancia recorrida en Kms: "<<endl;
    cin>>Vtarifas[pos].DistanciaKm;
    while (Vtarifas[pos].DistanciaKm!=0 && pos<500)
    {
        cout<<"Codigo de la ciudadad de origen: "<<endl;
        cin>>Vtarifas[pos].CodigoOrigen;
        cout<<"Codigo de la ciudad de destino: "<<endl;
        cin>>Vtarifas[pos].CodigoDestino;
        cout<<"Precio por pasaje: "<<endl;
        cin>>Vtarifas[pos].Precio;

        pos++;
        cout<<"Distancia recorrida en Kms: "<<endl;
        cin>>Vtarifas[pos].DistanciaKm;
    }
    

    //variables lote de proceso
    int Dia,Mes,Local,PasajesVendidos;
    char Origen[3],Destino[3];
    int MA[12][100]={}; //Matriz punto A) de 12 filas (meses) x 100 columnas (ciudades)
    float VB[5] = {};   //Vector punto B) total de ventas en el año para c/ Local
    float VC[100]={};  //Vector punto C) Acumula recaudacion por ciudad de origen
    int x;
    //Lote de procesos
    cout<<"Cantidad de pasajes vendidos: "<<endl;
    cin>>PasajesVendidos;

    while (PasajesVendidos!=0)
    {   
        cout<<"# Local: "<<endl;
        cin>>Local;
        cout<<"Mes de la venta: "<<endl;
        cin>>Mes;
        cout<<"Dia de la venta: "<<endl;
        cin>>Dia;
        cout<<"Ciudad de origen (codigo): "<<endl;
        cin>>Origen;
        cout<<"Ciudad de destino (codigo): "<<endl;
        cin>>Destino;

        // A)
        x=BuscarCiudad(Origen,Vciudades);
        MA[Mes-1][x] += PasajesVendidos;
        x=BuscarCiudad(Destino,Vciudades);
        MA[Mes-1][x] += PasajesVendidos;

        // B)
        VB[Local-1] += PrecioDeVenta(Origen, Destino, Vtarifas, PasajesVendidos);
        // C)
        x=BuscarCiudad(Origen,Vciudades);
        VC[x]+=TotalCiudadOrigen(Origen,Destino,Vtarifas,PasajesVendidos);
        cout << "Cantidad de pasajes vendidos: " << endl;
        cin >> PasajesVendidos;
    }
    


return 0;
}