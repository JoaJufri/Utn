#include <iostream>
using namespace std;

int main()
{
    int i,n,min,max=0;
    bool haymin=false;
    bool haymax=false;

    for (i = 1; i <= 10; i++)
    {
        cout<<"Ingrese el "<<i<<" numero:"<<endl;
        cin >> n;

        if (n>0)
        {
            if (haymin==false)
            {
                min=n;
                haymin=true;
            }
            else if (n<min)
            {
                min=n;
            }
        }
        else if (haymax==false)
        {
            max=n;
        }
        else if (n>max)
        {
            max=n;
        }
    }

    cout<<"El maximo de los negativos es: "<<max <<endl;
    cout<<"El minimo de los positivos es: "<<min;

    return 0;
}