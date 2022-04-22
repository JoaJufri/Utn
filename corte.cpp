#include <iostream>
using namespace std;

int main()
{
    int nro_paquete, cant_personas,hs_actividades;
    float precio_unitario,total_venta=0;
    char tipo_aventura, tipo_aventura_ant,act_min;
    int cant_personas_total=0,cant_paquetes_xaventura=0;
    float ventamax;
    int min,paquete_min;

    cout<<"Ingrese nro de paquete: "<<endl;
        cin>>nro_paquete;
        cout<<"Ingrese cant. de personas: "<<endl;
        cin>>cant_personas;
        cout<<"Ingrese precio p/persona: "<<endl;
        cin>>precio_unitario;
        cout<<"Ingrese hs totales de actividades: "<<endl;
        cin>>hs_actividades;
        cout<<"Ingrese tipo de aventura: "<<endl;
        cin>>tipo_aventura;
        
        min=hs_actividades;
        act_min=tipo_aventura;
        paquete_min=nro_paquete;

    while (nro_paquete!=0)
    {
        ventamax=0;
        tipo_aventura_ant=tipo_aventura;
        cant_paquetes_xaventura=0;
        while (tipo_aventura==tipo_aventura_ant)
        {
        cant_paquetes_xaventura++; //a)
        cant_personas_total+=cant_personas; // b)
        total_venta=precio_unitario*cant_personas; //c
        cout<<"El total de la venta es: "<<total_venta<<endl;
        if (total_venta>ventamax)
        {
            ventamax=total_venta;  //c
        }
        if (hs_actividades<min)
        {
            min=hs_actividades;
            act_min=tipo_aventura;
            paquete_min=nro_paquete;
        }

        cout<<"Ingrese nro de paquete: "<<endl;
        cin>>nro_paquete;
        cout<<"Ingrese cant. de personas: "<<endl;
        cin>>cant_personas;
        cout<<"Ingrese precio p/persona: "<<endl;
        cin>>precio_unitario;
        cout<<"Ingrese hs totales de actividades: "<<endl;
        cin>>hs_actividades;
        cout<<"Ingrese tipo de aventura: "<<endl;
        cin>>tipo_aventura;

        }
            cout<<"La cantidad de paquetes vendidos para la aventura "<<tipo_aventura_ant<<" es: "<<cant_paquetes_xaventura<<endl;
            cout<<"La venta con mayor importe de la actividad "<<tipo_aventura_ant<<" es: "<<ventamax<<endl;
    }
    cout<<"El paquete con menos horas incurridas fue el : "<<paquete_min<<" en la actividad: "<<act_min<<endl; 
    cout<<"El total de personas es: "<<cant_personas_total<<endl;

    return 0;
}