#include <iostream>
using namespace std;

int main()
{
    int i,j,A,B,N;

    cout << "Ingrese el primer numero: " <<endl;
    cin >> A;
    cout << "Ingrese el segundo numero: " <<endl;
    cin >> B;

    if (A>B)
    {
        N = A-B;
        i = B;
    }
    else {
        N = B-A;
        i = A;
    }

    i++;

    for (j = i; j <= N; j++)
    {
        cout << j <<endl;
    }
    
    

    return 0;
}
