#include <iostream>
using namespace std;
int main()
{
    int imp;
    int M;
    int Q;
    int D;
    int C;

    cout<< "ingrese importe a retirar: " <<endl;
    cin>> imp;

    M = imp % 1000;
    M = (imp - M) / 1000;
    imp = imp - (1000 * M);
    Q = imp % 500;
    Q = (imp - Q) / 500;
    imp = imp - (500 * Q);
    D = imp % 200;
    D = (imp - D) / 200;
    imp = imp - (200 * D);
    C = imp/100;

    cout<< M << "  billetes de 1000, " << Q << " billetes de 500, " << D << " billetes de 200 y " << C << " billetes de 100";

    return 0;
}
