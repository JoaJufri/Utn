#include <iostream>
using namespace std;
#include <stdlib.h>

int main()
{
    int n,x;

    cout<<"Ingrese un numero: ";
    cin>>n;

    x=n%2;

    if (x==0)
    {
        cout << n << " Es par.";
    }
    else
    {
        cout << n << " no es par.";
    }
    
    

    return 0;
}
