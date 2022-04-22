#include <iostream>
using namespace std;
int main()
{
    int cant;
    int sueltos;
    int cajas;
    int T;

    cout<< "Ingrese cantidad de huevos" <<endl;
    cin>> cant;

    sueltos = cant % 12;
    cajas = (cant - sueltos) / 12;
    T = (12 * sueltos) + (100 * cajas);

    cout<< "El total a pagar es de: $ " << T;

    return 0;
}
