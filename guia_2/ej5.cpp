
/*Si el importe es menor a $100 aplicar un descuento del 5% - 
Si el importe es entre $100 y hasta $500 aplicar un descuento del 10% 
- Si el importe es mayor a $500  aplicar un descuento del 15%
 
*/


#include <iostream>
using namespace std;
#include <stdlib.h>

int main()
{
    float imp;

    cout<<"Ingrese importe: ";
    cin>>imp;

    if (imp>500)
    {
        imp=imp*0.85;
    }
    else if (imp>=100 && imp<=500)
    {
        imp=imp*0.9;
    }
    else {
        imp=imp*0.95;
    }
    
    cout<<"El importe a pagar es de : $ " <<imp;

    return 0;
}
