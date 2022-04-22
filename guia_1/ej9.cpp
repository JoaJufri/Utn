#include <iostream>
using namespace std;
int main()
{
    int m;
    int min;
    int H;

    cout << "Ingrese cantidad de minutos: ";
    cin >> m;
    
    min = m % 60;
    H = (m -min) / 60;

    cout << H << " horas y " << min << " minutos";

    return 0;
}
