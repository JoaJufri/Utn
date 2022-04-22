#include <iostream>
using namespace std;

int main()
{
    int n,i,divisores=0;

    cout<<"Ingrese un nro positivo:"<<endl;
    cin>>n;

    for (i = 1; i <= n; i++)
    {
        if (n%i == 0)
        {
            divisores++;
        }
    }

    if (divisores==2)
    {
        cout<<n<<" Es primo";
    }
    else
    {
        cout<<n<<" No es primo";
    }

    return 0;
}