#include <iostream>
using namespace std;

int main()
{
    int i,primero,segundo,n,n1;
    bool b=false;
    bool b2=false;

    for (i = 1; i <= 7; i++)
    {
        cout <<"Ingrese el "<<i<<" numero"<<endl;
        cin>>n;
        if (n%2 != 0)
        {
            if (b==false)
            {
                primero=n;
                b=true;
            }
            else if (b2==false)
            {
                segundo=n;
                b2=true;
            }
            
        }
        
    }
    
    cout<<"El primer impar ingresado es: "<<primero<<endl;
    cout<<"El segundo impar ingresado es:"<<segundo<<endl;
    
    return 0;
}