//Escribir un subprograma para que dados dos 
//números enteros, obtengamos el máximo de ambos.

#include <iostream>
using namespace std;

int max(int A,int B)
{
    int maximo;
    if (A>B)
    {
        maximo=A;
    }
    else
    {
        maximo=B;
    }
    
    return maximo;
}

int main()
{
    int a,b,Max;

    cout<<"Ingrese un numero: "<<endl;
    cin>>a;
    cout<<"Ingrese otro numero: "<<endl;
    cin>>b;
    Max=max(a,b);
    cout<<"El maximo es: "<<Max;

    return 0;
}