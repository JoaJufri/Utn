#include <iostream>
using namespace std;

int main()
{
    int i,mov,dia,movdia10=0;
    float importe;
    char tipo;
    int saldofin=0,extracciones=0,depositos=0;
    float pextraccion=0,pdeposito=0;
    int diamax,nromax,depmax=0;

    for (i = 1; i <= 14; i++)
    {
        cout<<"Ingrese el dia:"<<endl;
        cin>>dia;
        cout<<"ingrese el nro de movimiento:"<<endl;
        cin>>mov;
        cout<<"Ingrese tipo de movimiento ('E'-extraccion / 'D'-deposito"<<endl;
        cin>>tipo;
        toupper(tipo);
        cout<<"Indique importe:"<<endl;
        cin>>importe;
        
        
        if (dia==10)
        {
            movdia10++;             //cant.movimientos del dia 10
        }
        
        switch (tipo)
        {
        case 'E':
            extracciones++;                     //calculo para %de extracciones
            saldofin = (saldofin-importe);      //saldo final (acumulador)
            break;
        
        case 'D':
            depositos++;                         //calculo para % de depositos
            saldofin = (saldofin+importe);      //saldo final (acumulador)

            if (importe>depmax)
            {
                depmax=importe;                 //deposito maximo
                nromax=mov;                     //nro de movimiento del deposito maximo
                diamax=dia;                     //dia del deposito maximo
            }
            break;
        }

    }
    
    pextraccion = ((float)extracciones/14)*100;
    pdeposito = ((float)depositos/14)*100;

    cout<<"El saldo final de la cuenta es: "<<saldofin<<endl;
    cout<<"El porcentaje de mov de extraccion es: "<<pextraccion<<endl;
    cout<<"El porcentaje de mov de depositos es: "<<pdeposito<<endl;
    cout<<"El deposito mayor fue de: "<<depmax<<endl;
    cout<<"Depositado el dia: "<<diamax<<endl;
    cout<<"Con nro de movimiento: "<<nromax<<endl;
    cout<<"La cantidad de movimientos del dia 10 fue: "<<movdia10<<" movimientos";

    return 0;
}