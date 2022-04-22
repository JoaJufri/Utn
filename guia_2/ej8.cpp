#include <iostream>
using namespace std;
#include <stdlib.h>

int main()
{
    int l1,l2,l3;

    cout<<"Inserte lado 1: ";
    cin>>l1;
    cout<<"Inserte lado 2: ";
    cin>>l2;
    cout<<"Inserte lado 3: ";
    cin>>l3;

    if (l1==l2)
    {
        if (l2==l3)
        {
            cout<<"Equilatero";
        }
        else
        {
            cout<<"Isoceles";
        }
        
    } 
        
    else if (l1==l3 || l2==l3)
    {
        cout<<"Isoceles";
    }
    else{
        cout<<"Escaleno";
    }
    

    return 0;
}
