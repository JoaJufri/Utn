//Escribir un subprograma que reciba la fecha de nacimiento de una persona y la fecha
//de hoy, y calcule y devuelva la edad en años de esa persona. Suponer que cada fecha está
//compuesta por tres valores independientes (día, mes y año). 
#include <iostream>
using namespace std;

void edad(int dia, int mes, int anio, int dia_act, int mes_act, int anio_act)
{
    int edad_act=0;

    if (anio<=anio_act)
    {
        if (mes<mes_act)
        {
            edad_act=anio_act-anio;
        }
        else if (mes==mes_act && dia<dia_act)
        {
            edad_act=anio_act-anio;
        }
        else
        {
            edad_act=anio_act-anio-1;
        }
    }
    cout<<"Su edad es: "<<edad_act<<endl;
}

int main()
{
    int d,m,a,d_act,m_act,a_act;

    cout<<"Ingrese dia de nacimiento: "<<endl;
    cin>>d;
    cout<<"Ingrese mes de nacimiento: "<<endl;
    cin>>m;
    cout<<"Ingrese anio de nacimiento: "<<endl;
    cin>>a;

    cout<<"Ingrese dia actual: "<<endl;
    cin>>d_act;
    cout<<"Ingrese mes actual: "<<endl;
    cin>>m_act;
    cout<<"Ingrese anio actual: "<<endl;
    cin>>a_act;
    
    edad(d,m,a,d_act,m_act,a_act);

    return 0;
}