#include <iostream>
using namespace std;

int BuscarIndice(int vec[],int codigo) {

    for (int i = 0; i < 20; i++)
    {
        if (vec[i]==codigo)
        {
            return i;
        }
        
    }
    
}

float CalcularPromedio(int vec[], int tam) {

    int acu=0;
    float prome=0;
    for (int i = 0; i < tam; i++)
    {
        acu+=vec[i];
    }
    
    prome=acu/tam;
    return prome;
}

void VentasMayoresAlPromedio(int vec[], int tam, float prome, int vec2[]) {

    for (int i = 0; i < tam; i++)
    {
        if (vec[i]>prome)
        {
            cout<<"Articulo nro: "<<vec2[i]<<" es mayor al promedio"<<endl;
        }
        
    }
    
}

void NombreMes(int mes) {

    switch (mes)
    {
    case 1:
        cout<<"Enero"<<endl;
        break;

    case 2:
        cout<<"Febrero"<<endl;
        break;

    case 3:
        cout<<"Marzo"<<endl;
        break;

    case 4:
        cout<<"Abril"<<endl;
        break;

    case 5:
        cout<<"Mayo"<<endl;
        break;

    case 6:
        cout<<"Junio"<<endl;
        break;

    case 7:
        break;
        cout<<"Julio"<<endl;

    case 8:
        cout<<"Agosto"<<endl;
        break;

    case 9:
        cout<<"Septiembre"<<endl;
        break;

    case 10:
        cout<<"Octubre"<<endl;
        break;

    case 11:
        cout<<"Noviembre"<<endl;
        break;

    case 12:
        cout<<"Diciembre"<<endl;
        break;
    }
}

int main()
{   
    //variables vec Carga
    int CodigoArt,Vart[20]={};
    float Precio,Vprecios[20]={};
    //Variables del vector de proceso
    int NroCliente,Mes,Dia,CantVendida,indice;
    int VMeses[12]={}, CantVendidaArt[20]={};
    float Promedio;


    for (int i = 0; i < 20; i++)
    {
        cout<<"Codigo de Articulo: "<<endl;
        cin>>CodigoArt;
        cout<<"Precio unitario: "<<endl;
        cin>>Precio;
        Vart[i]=CodigoArt;
        Vprecios[i]=Precio;
    }
    
    cout<<"Nro de cliente: "<<endl;
    cin>>NroCliente;

    while (NroCliente!=0)
    {   
        cout<<"Codigo de Articulo: "<<endl;
        cin>>CodigoArt;
        cout<<"Mes: "<<endl;
        cin>>Mes;
        cout<<"Dia: "<<endl;
        cin>>Dia;
        cout<<"Cantidad vendida: "<<endl;
        cin>>CantVendida;

        indice=BuscarIndice(Vart,CodigoArt);
        CantVendidaArt[indice]+=CantVendida;    //Punto A)

        VMeses[Mes-1]+=CantVendida;             //Punto B

        cout<<"Nro de cliente: "<<endl;
        cin>>NroCliente;
    }
    
    //Muestra Punto b)
    for (int i = 0; i < 12; i++)
    {
        if (VMeses[i]==0)
        {
            NombreMes(i+1);
            cout<<"No tuvo ventas."<<endl;
        }
        
    }
    

    Promedio=CalcularPromedio(CantVendidaArt,20);
    //Muestra punto C
    VentasMayoresAlPromedio(CantVendidaArt,20,Promedio,Vart); 
    

    return 0;
}