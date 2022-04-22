#include <iostream>
using namespace std;
int main()
{
    double pcd;
    double psd;
    double desc;

    cout << "Ingrese importe de venta sin descuento: ";
    cin >> psd;
    cout << "Ingrese importe de venta con descuento: ";
    cin >> pcd;

    desc = psd - pcd;
    desc = (desc * 100) / psd;

    cout << "el descuento fue del: " << desc << "%";    

    return 0;
}
