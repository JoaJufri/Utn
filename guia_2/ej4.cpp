#include <iostream>
using namespace std;
#include <stdlib.h>

int main()
{
    int n,n2,R;

    cout<<"ingrese un numero: ";
    cin>>n;
    cout<< "ingrese otro numero: ";
    cin>>n2;

    R=n-n2; 

    if (R<0)
    {
        R=R*(-1);
    } 
    
    cout<< "La diferencia absoluta es: " <<R;

    return 0;
}
