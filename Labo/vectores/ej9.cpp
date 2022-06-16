#include <iostream>
using namespace std;

int main()
{
    int NE,DIA;
    float HN,HE,HS;
    float vhn,vhe,VSueldo[80]={};
    float MVHS[80] [2],MHXM[80][2]= {}; ///MVHS = Matriz_ValorHoras ---> [NE][HN][HE], MHXM= Matriz_HorasXMes--> [NE][HS][DIA]
    cout<<"Lote de registros: "<<endl<<endl;

    for (int i = 0; i < 80; i++)
    {
    cout<<"Ingrese Nro de Empleado: "<<endl;
    cin>>NE;
    cout<<"Ingrese Valor hora normal: "<<endl;
    cin>>vhn;
    MVHS[NE-1][0]=vhn;
    cout<<"Ingrese valor hora extra: "<<endl;
    cin>>vhe;
    MVHS[NE-1][1]=vhe;
    cout<<"----------------------------------"<<endl;
    }
    
    cout<<"Lote de carga horas en el mes: "<<endl<<endl;
    cout<<"Ingrese nro de empleado: "<<endl;
    cin>>NE;
    
    while (NE!=0)
    {   
        cout<<"Dia: "<<endl;
        cin>>DIA;
        cout<<"Horas trabajadas x dia: "<<endl;
        cin>>HS;

        MHXM[NE-1][0]+=HS;
        MHXM[NE-1][1]+=DIA;

        if (HS>=8)
        {
            HE=HS-8;
            HN=HS-HE;
        }
        else
        {
           HN=HS;
           HE=0; 
        }
        
        VSueldo[NE-1]+=HN*MVHS[NE-1][0];
        VSueldo[NE-1]+=HE*MVHS[NE-1][1];
        
        cout<<"Ingrese nro de empleado: "<<endl;
        cin>>NE; 
    }

    cout<<"Sueldos"<<endl<<"=========="<<endl;

    for (int i = 0; i < 80; i++)
    {
        cout<<"Sueldo del empleado: "<<i+1<<": $"<<VSueldo[i]<<endl;
        cout<<"===================================="<<endl;

    }
    return 0;
}