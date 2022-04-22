#include <iostream>
using namespace std;

int main()
{   
    int lega,sueldo,i,legmax;
    int sueldomax=0;

    for (i = 1; i <= 10; i++)
    {
        cout<<"Ingrese legajo: " <<endl;
        cin>>lega;
        cout<<"Ingrese sueldo: " <<endl;
        cin>>sueldo;

        if (sueldo>sueldomax)
        {
            legmax=lega;
            sueldomax=sueldo;
        }
        
    }
    
    cout <<"El Legajo del empleado con mayor sueldo es: " <<legmax;

    return 0;
}