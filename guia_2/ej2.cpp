#include <iostream>
using namespace std;
#include <stdlib.h>
int main()
{
    int n1,n2,x;

    cout<<"Ingrese un numero: ";
    cin>>n1;
    cout<<"Ingrese otro numero: ";
    cin>>n2;

    x = n1%n2; 

    if (x==0)
    {
        cout<<"Es multiplo.";
    }
    else {
        cout<<"No es múltiplo.";
    }

    return 0;
}
