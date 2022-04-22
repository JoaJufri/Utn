#include <iostream>
using namespace std;
int main()
{
    double A;
    double B;
    double C;
    double T;


    cout << "Ingrese alfajores venidos para la marca A : ";
    cin >> A;
    cout << "ingrese alfajores vendidos para la marca B: ";
    cin >> B;
    cout << "Ingrese alfajores venidos por la marca C: ";
    cin >> C;

    T = A + B + C;
    A = (100 * A) / T;
    B = (100 * B) / T;
    C = (100 * C) / T;

    cout << "Porcentaje de ventas de la marca 'A': " << A << endl; 
    cout << "Porcentaje de ventas de la marca 'B': " << B << endl;
    cout << "Porcentaje de ventas de la marca 'C': " << C;

    return 0;
}
