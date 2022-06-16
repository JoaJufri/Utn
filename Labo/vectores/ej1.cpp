/* 
 Hacer un programa que le pida al usuario una lista de 10 números enteros 
 y luego de ingresarlos muestre cuáles de ellos fueron positivos. 
*/ 

#include <iostream>
using namespace std;

int main()
{
    int nros[10],i,c=0;

    for (i = 0; i < 10; i++)
    {   
        cout<<"ingrese un numero entero: "<<endl;
        cin>>nros[i];
        if (nros[i]>0)
        {   
            c++;
        }
    }    
    cout<<"los numeros positivos fueron: "<<endl;
    int vpos[c];
    for (i = 0; i < 10; i++)
    {
        if (nros[i]>0)
        {
            vpos[i]=nros[i];
            cout<<vpos[i]<<endl;
        }
        
    }
    
return 0;
}