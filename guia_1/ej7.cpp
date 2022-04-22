#include <iostream>
using namespace std;
int main()
{
    double imp;
    double des;
    double T;

    cout << "Ingrese importe: ";
    cin >> imp;
    cout << "ingrese porcentaje de descuento: ";
    cin >> des;

    des = 1 - (des/100);
    T = imp * des;

    cout << "El total a pagar es: " << T;

    return 0;
}
