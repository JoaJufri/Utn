#include <iostream>
using namespace std;
int main()
{
    int cv;
    int T;
    cout << "Ingrese cantidad de autos vendida: ";
    cout << endl;
    cin >> cv;
    T = (2000 * cv) + 15000;
    cout << "el sueldo total a pagar es de: " << T;
    
    return 0;
}
