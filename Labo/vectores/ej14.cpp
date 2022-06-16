#include <iostream>
using namespace std;

int main()
{
    int Vcinco[5],Vdiez[10],vUnion[15],n;

    for (int i = 0; i < 5; i++)
    {
        cout<<"Ingrese un nro: "<<endl;
        cin>>n;
        Vcinco[i]=n;

    }
    
    cout<<"===================="<<endl;

    for (int i = 0; i < 10; i++)
    {
        cout<<"Ingrese un nro: "<<endl;
        cin>>n;
        Vdiez[i]=n;
    }
    
    cout<<"========================"<<endl;

    for (int i = 0; i < 5; i++)
    {
        vUnion[i]=Vcinco[i];
    }
    
    for (int i = 5; i < 15; i++)
    {
        vUnion[i]=Vdiez[i-5];
    }
    
    for (int i = 0; i < 15; i++)
    {
        cout<<vUnion[i]<<" ";
    }
    

    return 0;
}