#include <iostream>
using namespace std;

int main()
{
    int i,n,n1,max,max2;
    int b=0;

    cout<<"Ingrese el 1 numero: "<<endl;
    cin>>n1;
    max=n1;

    for (i = 2; i <= 5; i++)
    {
        cout<<"Ingrese el "<<i<<" numero"<<endl;
        cin>>n;

        if (n>max)
        {
            max2=max;
            max=n;
        }
        else if (b==0)
        {
            max2=n;
            b=1;
        }
        else if (n>max2)
        {
            max2=n;
        }
    }
    
    cout<<"El primer maximo es: "<<max<<endl;
    cout<<"El segundo maximo es: "<<max2<<endl;

    return 0;
}