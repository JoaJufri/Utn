/*Escribir un subprograma para que dados dos números enteros, calcule y devuelva la
potencia del primero a la del segundo. Por ejemplo si la rutina recibe 2 y 3 respectivamente,
el cálculo que generará será 8 (2 a la potencia 3).*/

#include <iostream>
using namespace std;

void potencia(int base,int exp)
{   
    int potencia=1;
    for (int i = 0; i < exp; i++)
    {
        potencia*=base;
    }
    cout<<potencia;
}

int main()
{
    int b,e;
    cout<<"Ingrese un numero: "<<endl;
    cin>>b;
    cout<<"Ingrese otro numero: "<<endl;
    cin>>e;

    potencia(b,e);

    return 0;
}