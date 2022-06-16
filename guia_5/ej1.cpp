//Escribir un subprograma para que dados dos números enteros, obtengamos la suma
//de ambos. 

#include <iostream>
using namespace std;

int suma(int A,int B){
        int R=A+B;
        return R;
    }

int main()
{
    int n,n2,Resultado;

    cout<<"Ingrese un numero: "<<endl;
    cin>>n;
    cout<<"Ingrese otro numero: "<<endl;
    cin>>n2;

    Resultado=suma(n,n2);

    cout<<"La suma es: "<<Resultado<<endl;

    return 0;
}