#include <iostream>
using namespace std;
#include <stdlib.h>

int main()
{
    int A,B,C;

    cout << "Ingrese un numero: " <<endl;
    cin >> A;
    cout << "Ingrese un numero: " <<endl;
    cin >> B;
    cout << "Ingrese un numero: " <<endl;
    cin >> C;

    if (A>B && A<C || A>C && A<B)
    {
        cout << A;
    }

    if (B>A && B<C || B>C && B<A)
    {
        cout << B;
    }

    if (C>A && C<B || C>B && C<A)
    {
        cout << C;
    }
    
    return 0;
}

/*Hacer un programa para ingresar 3 numeros y mostrar el del medio*/