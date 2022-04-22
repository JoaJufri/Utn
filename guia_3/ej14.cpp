#include <iostream>
using namespace std;

int main()
{
    int i,n;
    int cant=0;

    cout<<"Ingrese un numero:"<<endl;
    cin>>n;

    for (i = 1; i <= n; i++)
    {
        if (n%i == 0)
        {
            cant++;
        }
    }

    cout<<"La cantidad de divisores de "<<n<<" es: "<<cant;

    return 0;
}