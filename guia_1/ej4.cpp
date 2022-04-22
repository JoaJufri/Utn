#include <iostream>
using namespace std;
int main()
{
    int ad;
    int ao;
    float Pocu;
    float Plibre;

    cout << "Ingrese asientos disponibles: ";
    cin >> ad;
    cout << "Ingrese asientos ocupados: ";
    cin >> ao;

    Pocu = (ao*100) / (float)ad;
    Plibre = 100 - Pocu;

    cout << "Porcentaje de ocupación: " << Pocu << endl;
    cout << "Porcentaje de asientos libres: " << Plibre;

    return 0;
}
