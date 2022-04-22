#include <iostream>
using namespace std;

int main()
{
    float sueldo,smax,smin,sprom;
    int cant=0,i;

    smin = 0;
    smax = 0;
    sprom = 0;


    for (i = 1; i <= 5; i++)
    {
        cout << "Ingrese sueldo: " <<endl;
        cin >> sueldo;

        sprom = sprom + sueldo;

        if (smin==0)
        {
           smin = sueldo;
        }
        
        
        if (sueldo >= smax)
        {
            smax = sueldo;
            
        } 
        
        if (sueldo < smin)
        {
            smin = sueldo;
        }

        if (sueldo>50000)
        {
            cant++;
        }
    }

    sprom = sprom/5;
    
    cout << "El maximo es: " <<smax <<endl;
    cout << "El minimo es: " <<smin <<endl;
    cout << "Cantidad de sueldos mayores a 50k: " <<cant <<endl;
    cout << "El promedio es: " <<sprom <<endl;

    return 0;
}
