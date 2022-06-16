#include <iostream>
using namespace std;

int main()
{   
    int id,idmax,sodio,b,c,cp=0;
    float platino,pH,lts,pHmax,prome,lts_total;

    cout<<"Ingrese id de Protocolo: "<<endl;
    cin>>id;
    c=0;

    while (id!=0)
    {   
        c++;
        b=0;
        cout<<"Litros de la muestra: "<<endl;
        cin>>lts;
        cout<<"Ingrese nivel de sodio: "<<endl;
        cin>>sodio;
        cout<<"Ingrese nivel de platino: "<<endl;
        cin>>platino;
        cout<<"Determinacion de pH: "<<endl;
        cin>>pH;

        if (sodio<0 || sodio>150)
            {b=1;}
        if (platino<0.2 || platino>12)
            {b=1;}
        if (pH<6.5 || pH>8.5)
            {b=1;}

        if (b==0)
            {cp++;}
     
       if (c==1)
       {
           pHmax=pH;
           idmax=id;
       }
       else if (pH>pHmax)
       {
           pHmax=pH;
           idmax=id;
       } 

       lts_total+=lts;
        cout<<"Ingrese id de Protocolo: "<<id<<endl;    
    }
    prome=lts_total/c;  // con c!=0 (el primer id no tiene que ser cero)
    cout<<"La cant. de protocolos que se encuentran dentro de los param. aceptables son "<<cp<<endl;
    cout<<"La muestra de pH mas alta fue de: "<<pHmax<<" en el protocolo: "<<idmax<<endl;
    cout<<"El promedio de litros de muestra entre todos los protocolos es de: "<<prome;
    
    return 0;
}