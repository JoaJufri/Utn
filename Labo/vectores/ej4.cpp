#include <iostream>
using namespace std;

int main()
{   
    const int tam=10;
    int nro_venta,dia,i,diamax;
    float ventas[tam],importe,max=0;
    

    for (i = 0; i < tam; i++)
    {
        ventas[i]=0;
    }
    
    cout<<"Ingrese nro de venta: "<<endl;
    cin>>nro_venta;

    while (nro_venta!=0)
    {   
        cout<<"Ingrese importe de venta: "<<endl;
        cin>>importe;
        cout<<"Ingrese dia de venta: "<<endl;
        cin>>dia;    
        
        ventas[dia-1]+=importe;
    
        cout<<"Ingrese nro de venta: "<<endl;
        cin>>nro_venta;
    }

    for (i = 0; i < tam; i++)
    {
        if (ventas[i]>max)
        {
            max=ventas[i];
            diamax=i+1;
        }
        if (ventas[i]!=0)
        {
            cout<<"La recaudacion total para el dia "<<i+1<<" fue de: $"<<ventas[i]<<endl;
        }   
    }
    
    cout<<"El nro de dia que mas se recaudo en total fue el dia: "<<diamax<<endl;
    cout<<"la recaudacion maxima fue de: $"<<max<<endl;

    return 0;
}