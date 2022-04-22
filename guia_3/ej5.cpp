#include <iostream>
using namespace std;

int main()
{
    int i,n,A;
    int posi=0;

    cout << "Ingrese la cant de elementos de la lista: ";
    cin >> n;

    for (i = 1; i <= n; i++)
    {
        cout << "Ingrese un numero: " <<endl;
        cin >> A;
        if (A>0)
        {
            posi++;
        }
        
    }

    cout << "Hay: " << posi <<" nros positivos";
    

    return 0;
}
