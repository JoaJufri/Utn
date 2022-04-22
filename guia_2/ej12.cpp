#include <iostream>
using namespace std;
#include <stdlib.h>

int main()
{
    int A,B,C;

    cout<<"Ingrese un numero: " <<endl;
    cin >> A;
    cout<<"Ingrese un numero: " <<endl;
    cin >> B;
    cout<<"Ingrese un numero: " <<endl;
    cin >> C;

    if (A<B)
    {
        if (A<C)
        {
            if (B<C)
            {
                cout<< A <<", " << B <<", " << C;
            }
            else {
                cout<< A <<", " << C <<", " << B;
            }
            
        }
        else if (C<B)
        {
            cout<< C <<", " << A <<", " << B;
        }
        
        
    } 
     else if (B<C)
     {
         if (C<A)
         {
             cout<< B <<", " << C <<", " << A;
         }
         else
         {
             cout<< B <<", " << A <<", " << C;
         }
         
         
     }
     else
     {
         if (C<A)
         {
             cout<< C <<", " << B <<", " << A;
         }
         
     }
     
     

    return 0;
}
