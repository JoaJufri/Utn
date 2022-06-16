/*Hacer un programa donde se carguen 15 números enteros y 
luego muestre por pantalla el mínimo elemento del vector 
y además indique cuántas veces se repite el valor mínimo 
dentro del vector.
*/
#include <iostream>
using namespace std;

int main()
{
    int nros[15],i,min,cmin=0;

    for (i = 0; i < 15; i++)
    {
        cout<<"Ingrese un numero: "<<endl;
        cin>>nros[i];
        if (i==1)
        {
            min=nros[i];
        }
        else if (nros[i]<min)
        {
            min=nros[i];
        } 
    }
    
    for (i = 0; i < 15; i++)
    {
        if (nros[i]==min)
        {
            cmin++;
        }
    }
    
    cout<<"El minimo valor es: "<<min<<endl;
    cout<<"EL minimo se repite "<<cmin<<" veces.";

return 0;
}