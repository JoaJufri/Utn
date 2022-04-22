#include <iostream>
using namespace std;

int main()
{
    int i,num;
    int p=0,n=0,c=0;

    for (i = 1; i <= 10; i++)
    {
        cout << "Ingrese un numero: "<<endl;
        cin >> num;
        if (num==0)
        {
            c++;
        }
        else if (num>0)
        {
            p++;
        }
        else {
            n++;
        }
        
    }

    cout << "Hay: " <<p <<" positivos, " <<n <<" negativos y " << c << " iguales a cero";
    

    return 0;
}
