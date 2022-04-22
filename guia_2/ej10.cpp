#include <iostream>
using namespace std;
#include <stdlib.h>

int main()
{
    int A,B,C,D,E;

    cout<<"Ingrese un numero" <<endl;
    cin>>A;
    cout<<"Ingrese un numero" <<endl;
    cin>>B;
    cout<<"Ingrese un numero" <<endl;
    cin>>C;
    cout<<"Ingrese un numero" <<endl;
    cin>>D;
    cout<<"Ingrese un numero" <<endl;
    cin>>E;

    if (A>=B && A>=C && A>=D && A>=E)
    {
        cout<<"A";
    }

    if (B>=A && B>=C && B>=D && B>=E)
    {
        cout<<B;
    }

    if (C>=A && C>=B && C>=D && C>=E)
    {
        cout<<C;
    }

    if (D>=A && D>=B && D>=C && D>=E)
    {
        cout<<D;
    }

    if (E>=A && E>=B && E>=C && E>=D)
    {
        cout<<E;
    }
    
    return 0;
}
