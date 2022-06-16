#include <iostream>
using namespace std;

int main()
{
    int Vcinco[5],Vdiez[10],vInterseccion[5],n;

    for (int i = 0; i < 5; i++)
    {
        cout<<"Ingrese un numero para el 1er vector: "<<endl;
        cin>>n;
        Vcinco[i]=n;
    }
    
    for (int i = 0; i < 10; i++)
    {
        cout<<"Ingrese un numero par el 2do vector:"<<endl;
        cin>>n;
        Vdiez[i]=n;
    }
    
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            if (Vcinco[i]==Vdiez[j])
            {
                vInterseccion[i]=Vdiez[j];
            }
            
        }
        
    }
    

    return 0;
}