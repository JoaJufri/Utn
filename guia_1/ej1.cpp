#include <iostream>
using namespace std;
int main()
{
    int ch = 0;
    int vh = 0;
    int s = 0;

    cout << "Ingrese la cantidad de horas trabajadas";
    cin >> ch;

    cout << "Ingrese el valor-hora";
    cin >> vh;

    s = ch * vh;

    cout << "El sueldo a pagar es de : $ " << s;

    return 0;
}
