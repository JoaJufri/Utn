/*Hacer un programa donde se carguen 15 números enteros y 
luego le solicite al usuario un número e indique si el mismo
pertenece a la lista cargada anteriormente.*/
#include <iostream>
using namespace std;

int main()
{
    int nros[15],i,n,b=0;

    for (i = 0; i < 15; i++)
    {
        cout<<"Ingrese un numero: "<<endl;
        cin>>nros[i];
    }
    
    cout<<"Ingrese el número que desea buscar en la lista: "<<endl;
    cin>>n;

    for (i = 0; i < 15; i++)
    {
        if (n==nros[i])
        {
            b=1;
        }
        
    }
    
    if (b==1)
    {
        cout<<"El numero "<<n<<" esta en la lista."<<endl;
    }
    else 
    {
        cout<<"El numero "<<n<<" no esta en la lista.";
    }

return 0;
}