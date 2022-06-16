#include <iostream>
using namespace std;

int main()
{   
    
    int VTipoE[50],mat_min[50] [10]={},i,j;
    int NumE,Cliente,TipoE;
    float Tiempo;

    cout<<"Numero de entrenamiento: "<<endl;
    cin>>NumE;

    while (NumE!=0)
    {
        cin>>Cliente;
        cin>>TipoE;
        cin>>Tiempo;
        
        mat_min[Cliente-101] [TipoE-1]+=Tiempo;
        
        cout<<"===================="<<endl;
        cin>>NumE;
    }
    
    ///A (Optimizado para q no muestre tiempo de entrenamiento si es = 0)
     for (i = 0; i < 50; i++)
        {
            for (j = 0; j < 10; j++)
            {   int horas,min;
                if (mat_min[i][j]!=0)
                {
                    horas=mat_min[i][j]/60;
                    min=mat_min[i][j]%60;
                    cout<<"Cliente: "<<i+101<< " - Tiempo de entrenamiento: "<<horas<<":"<<min<<endl;
                }
            }
            
        }
    
    ///B x Cada cliente, los tipos de entrenamiento que realizó

    for (i = 0; i < 50; i++)
    {
        for (j = 0; j < 10; j++)
        {
            if (mat_min[i][j]!=0)
            {
                cout<<"Cliente: "<<i+101<<" Realizo el entrenamiento: "<<j<<endl;
            }
            
        }
        
    }
    
    ///C

    for (i = 0; i < 50; i++)
    {
        for (j = 0; j < 10; j++)
        {
            if (mat_min[i][j]!=0)
            {
                cout<<"Cantidad de min entrenados para Cliente: "<<i+101<<" en tipo de entrenamiento: "<<j<<" :"<<mat_min[i][j]<<endl;
            }
            
        }
        
    }
    
    
    return 0;
}