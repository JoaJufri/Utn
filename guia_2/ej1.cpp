#include <iostream>
#include <stdlib.h>
#include <string>
using namespace std;
int main()
{
    int n;
    
    cout<<"ingrese un numero: "<<endl;  
    cin>> n;
    cout<<"\n";
    cout<<endl;                         
    if (n==0)                           
    {
        cout<<"Es cero"<<endl;
    }
    else if (n>0)
    {
        cout<<"Es positivo"<<endl;
    }
    else
    {
        cout<<"Es negativo"<<endl;
    }

    
    system("pause");
    return 0; 
}
