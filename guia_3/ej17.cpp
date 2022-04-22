#include <iostream>
using namespace std;

int main()
{
    int dia,i,b=0;
    float temp,lluvia,visibilidad;
    int amplitud,neblina=0,tempmax,tempmin;
    int diamax,diaslluvia=0,diassecos=0;

    for (i = 1; i <= 15; i++)
    {
        cout<<"Ingrese nro de dia:"<<endl;
        cin>>dia;
        cout<<"Ingrese la temperatura:"<<endl;
        cin>>temp;
        cout<<"Ingrese los mm de lluvia:"<<endl;
        cin>>lluvia;
        cout<<"Ingrese la visibilidad en km:"<<endl;
        cin>>visibilidad;

        if (i==1)
        {
            tempmax=temp;
            tempmin=temp;
        }

        if (temp>tempmax)
        {
            tempmax=temp;
            diamax=dia;             //salida
        }
        else if (temp<tempmin)
        {
            tempmin=temp;
        }
        
        if (visibilidad<2)
        {
            neblina++;
        }

        if (lluvia!=0)
        {
            diaslluvia++;
        }
        else
        {
            diassecos++;
        }
          

    }

        cout<<"El dia que se registro la temp.maxima es el dia: "<<endl<<diamax<<endl;

        amplitud=tempmax-tempmin;        //salida

        cout<<"La amplitud termica del periodo es:"<<endl<<amplitud<<endl;

        cout<<"Cantidad de dias con neblina:"<<endl<<neblina<<endl;

        if (diaslluvia>diassecos)
        {
            cout<<"Quincena lluviosa"<<endl;
        }
        
        if (diaslluvia>=5)  // (1/3)*15 dias= 5 dias
        {
            cout<<"Quincena humeda";
        }
        else
        {
            cout<<"Quincena seca";
        }

    return 0;
}