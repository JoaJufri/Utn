#include <iostream>
using namespace std;

int main()
{
    float v[10],max;
    int i,pos_max;

    for (i = 0; i < 10; i++)
    {
        cout<<"Ingrese un nro: "<<endl;
        cin>>v[i];
        if (i==0)
        {
            max=v[0];
            pos_max=0;
        }
        else if (v[i]>max)
        {
            max= v[i];
            pos_max=i;
        }
    }
    
    for (i = pos_max; i < 10; i++)
    {
        v[i]=v[i+1];
    }
    
    cout<<"Los elementos sin el maximo son: "<<endl;
    for (i = 0; i < 9; i++)
    {
        cout<<v[i]<<endl;
    }
    
    return 0;
}