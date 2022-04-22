#include <iostream>
using namespace std;
int main()
{
    int hs;
    int aux;
    int dias;

    cout << "Ingrese cantidad de horas: ";
    cin >> hs;

    aux = hs - (hs % 24);
    dias = aux / 24;
    aux = hs - (24 * dias);

    cout << dias << " dias, y " << aux << " horas";    
    
    return 0;
}
