#include <iostream>
using namespace std;

int main()
{
    int Ventas_Art[15][4]={}, Vstock[15], VstockAct[15]={};
    int cant,art,sucursal,stock,total=0;
    int max=0,smax;

    for (int i = 0; i < 15; i++)
    {
        cout<<"Ingrese nro de articulo: "<<endl;
        cin>>art;
        cout<<"Ingrese stock: "<<endl;
        cin>>stock;
        cout<<"====================="<<endl;
        Vstock[art-1]=stock;
    }
    
    cout<<"Ingrese nro de articulo: "<<endl;
    cin>>art;
    while (art!=0)
    {   
        cout<<"Ingrese Sucursal: "<<endl;
        cin>>sucursal;
        cout<<"Ingrese cantidad vendida: "<<endl;
        cin>>cant;
        cout<<"=================="<<endl;

        Ventas_Art[art-1][sucursal-1]+=cant;
        VstockAct[art-1]-=cant;

        cout<<"Ingrese nro de articulo: "<<endl;
        cin>>art;
    }
    
    // A) Cant.Vendida x articulo:

    for (int i = 0; i < 15; i++)
    {
        total=0;
        for (int j = 0; j < 4; j++)
        {
            total+=Ventas_Art[i][j];
        }
        cout<<"El total de unidades vendidas para el articulo "<<i+1<<" es: "<<total<<endl;
        cout<<"================================================================"<<endl;
    }
    
    // B) Por cada sucursal, los nros 
    // de artículos que vendieron más de 10 unidades:

    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 15; j++)
        {
            if (Ventas_Art[j][i]>10)
            {
                cout<<"En la sucursal "<<i+1<<" se vendieron mas de 10 unidades del articulo: "<<j+1<<endl;
                cout<<"============================================================================"<<endl;

            }
            
        }
        
    }
    
    // C) Por cada artículo,
    // la sucursal donde más se comercializó.

    for (int i = 0; i < 15; i++)
    {
        max=0;
        smax=0;
        for (int j = 0; j < 4; i++)
        {
            if (Ventas_Art[i][j]>max)
            {
                max=Ventas_Art[i][j];
                smax=j+1;
            }
            
        }
        cout<<"El art. "<<i+1<<" Se comercializo mas en la sucursal: "<<smax<<endl;
        cout<<"=========================================================="<<endl;
    }

    // D)

    for (size_t i = 0; i < 15; i++)
    {
        if (Vstock[i]==0)
        {
            cout<<"El articulo nro "<<i+1<<" quedo en cero."<<endl;
            cout<<"======================================"<<endl;
        }
    }
    
    // E)
    
    for (int i = 0; i < 15; i++)
    {
        if (VstockAct[i] < (Vstock[i]/2))
        {
            cout<<"El stock del articulo: "<<i+1<<" disminuyo mas de la mitad."<<endl;
        }
        
        
    }
    

    return 0;
}