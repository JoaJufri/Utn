#include <iostream>
using namespace std;

int main()
{   
    int codigo,volumen,i,volumen_total,alza,c_alza,accion_max,sinvar;
    float papertura,pcierre,prome,max,dif;

    cout<<"Ingrese codigo de accion: "<<endl;
    cin>>codigo;
    c_alza=0;
    sinvar=0;
    while (codigo!=0)
    {   
        volumen_total=0;
        prome=0;
        alza=0;
        for (i = 1; i <= 5; i++)
        {   
            cout<<"Precio de apertura:"<<endl;
            cin>>papertura;
            cout<<"Precio de cierre:"<<endl;
            cin>>pcierre;
            cout<<"Volumen de venta:"<<endl;
            cin>>volumen;
            volumen_total+=volumen;
            if (pcierre>papertura)
            {
                alza++;
            }
            dif=(pcierre*100)/papertura;
            if (i==1)
            {
                max=dif;
                accion_max=codigo;
            }
                else if(dif>max)
                {
                    max=dif;
                    accion_max=codigo;
                }
            if (dif==100)
            {
                sinvar++;
            }
                
        }
        prome=(float)volumen_total/5;
        cout<<"Volumen de venta para accion nro "<<codigo<<" : "<<prome<<endl;
        if (alza==5)
        {
            c_alza++;
        }
        

        cout<<"Ingrese codigo de accion:"<<endl;
        cin>>codigo;       
    }
    cout<<"Cant. de acciones que cerraron en alza: "<<c_alza<<endl;
    cout<<"La accion que mas incremento su valor fue la accion: "<<accion_max<<endl;
    cout<<"Cant. de acciones en las que el precio no vario: "<<sinvar<<endl;
    return 0;
}