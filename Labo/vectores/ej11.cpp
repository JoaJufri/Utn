#include <iostream>
using namespace std;

int main()
{
    int edad,SxC[2][4]={},fila,Vedad[10]={};
    char sexo,color,color_fav,Vcolores[4]={'N','A','B','O'};

    cout<<"Ingrese edad: "<<endl;
    cin>>edad;

    while (edad!=0)
    {
        cout<<"Ingrese Sexo: "<<endl;
        cin>>sexo;
        toupper(sexo);
        cout<<"Ingrese color de preferencia: "<<endl;
        cin>>color;
        toupper(color);
        if (sexo=='M')
        {   
            fila=0; 
        }
        else
        {
            fila=1;
        }
        
        switch (color)
            {
            case 'N':
                SxC[fila][0]++; //
                break;
            case 'A':
                SxC[fila][1]++; //
                break;    
            case 'B':
                SxC[fila][2]++; //
                break;
                        
            default:
                SxC[fila][3]++; 
                break;
            }
        
        for (int i = 0; i < 100; i++)
        {   
            int x=10*i;
            if (edad>=x && edad<(x+10))
            {
                Vedad[i]++;
            }
            
        }
        cout<<"================================"<<endl;
        cout<<"Ingrese edad: "<<endl;
        cin>>edad;
    }

    int max=0;
    for (int i = 0; i < 4; i++)
    {
        if (SxC[1][i]>max)
        {
            max=SxC[1][i];
            color_fav=Vcolores[i];
        }
    }
    
    // A)--->El color más votado entre las mujeres:
    cout<<"El color mas votado entre las mujeres fue el: "<<color_fav<<endl;
    cout<<"=================================================="<<endl;

    // B)--->Por cada década de edad, la cantidad de encuestados:
    for (int i = 0; i < 10; i++)
    {
        cout<<"La cantidad de encuestados para la decada "<<i<<" fue de: "<<Vedad[i]<<" personas."<<endl;
        cout<<"=================================================================================="<<endl;
    }
    
return 0;
}