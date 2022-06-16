//Escribir un subprograma para que dados dos números enteros, obtengamos la suma
//y el producto de ambos. 

#include <iostream>
using namespace std;

void sum_prod(int A,int B)
{
    int suma,producto;
    suma=A+B;
    producto=A*B;
    cout<<"La suma es: "<<suma<<endl;
    cout<<"El producto es: "<<producto<<endl;
}

int main()
{
    int a,b;

    cout<<"Ingrese un numero: "<<endl;
    cin>>a;
    cout<<"Ingrese un numero: "<<endl;
    cin>>b;

    sum_prod(a,b);

return 0;
}