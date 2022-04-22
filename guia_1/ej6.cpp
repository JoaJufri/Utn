#include <iostream>
using namespace std;
int main()
{
    double s1;
    double s2;
    double s3;
    double s4;
    double T;
    double P;

    cout << "ingrese la recaudación de la semana 1 : " ;
    cin >> s1;
    cout << "ingrese la recaudación de la semana 2 : " ;
    cin >> s2;
    cout << "ingrese la recaudación de la semana 3 : " ;
    cin >> s3;
    cout << "ingrese la recaudación de la semana 4 : " ;
    cin >> s4;

    T = (s1 + s2 + s3 + s4);
    P = T / 4;
    s1 = (100 * s1) / T;
    s2 = (100 * s2) / T;
    s3 = (100 * s3) / T;
    s4 = (100 * s4) / T;

    cout << "Promedio de ventas: " << P <<endl;
    cout << "porcentaje de ventas de la semana 1: " << s1 <<endl ;
    cout << "porcentaje de ventas de la semana 2: " << s2 <<endl ;
    cout << "porcentaje de ventas de la semana 3: " << s3 <<endl ;
    cout << "porcentaje de ventas de la semana 4: " << s4 <<endl ;


    return 0;
}
