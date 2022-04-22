#include <iostream>
using namespace std;

int main()
{
    bool ordenado=true;
    int i,n,anterior;

    cout<<"Ingrese el 1 numero: "<<endl;
    cin>>anterior;

    for (i = 2; i <= 8; i++)
    {
        cout<<"Ingrese el "<<i<<" numero:"<<endl;
        cin>>n;
        if (n>=anterior)
        {
            anterior=n;
        }
        else
        {
            ordenado=false;
        }
        
    }
    
    if (ordenado==true)
    {
        cout<<"Conjunto ordendo";
    }
    else
    {
        cout<<"Conjunto desordenado";
    }
    
    return 0;
}

//Hacer un programa para ingresar una lista de 8 números y luego informar 
//si todos están ordenados en forma creciente. 
//En caso de haber dos números “empatados” considerarlos como crecientes.
//Por ejemplo si la lista fuera:
//Ejemplo 1: -10, 1, 5, 7, 15, 18, 20, 23 se emitirá un cartel: “Conjunto Ordenado”
//Ejemplo 2: 10, 10, 15, 20, 25, 25, 28, 33 se emitirá un cartel: “Conjunto Ordenado”
//Ejemplo 3: 10, 1, 15, 7, -15, 18, 20, 23 se emitirá un cartel: “Conjunto No Ordenado”
	
