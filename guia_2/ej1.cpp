#include <iostream>
using namespace std;
int main()
{
    int n;      

    cout<<"ingrese un numero: ";   
    cin>> n;                         

    if (n==0)                           
    {
        cout<<"Es cero";
    }
    else if (n>0)
    {
        cout<<"Es positivo";
    }
    else
    {
        cout<<"Es negativo";
    }

    return 0;
}
