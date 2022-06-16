#include <iostream>
using namespace std;

int main()
{
    int Vprov[24]={};
    int prov, zona;

    for (int i = 0; i < 24; i++)
    {
        cout<<"Ingrese provincia (1-24): "<<endl;
        cin>>prov;
        cout<<"Ingrese zona geografica (1-9): "<<endl;
        cin>>zona;
        cout<<"======================"<<endl;
        Vprov[prov-1]=zona;
    }

    for (int i = 1; i <= 9; i++)
    {
        int cont=0;
        for (int j = 0; j < 24; j++)
        {
            if (Vprov[j]==i)
            {
                cont++;
            }
            
        }
        
        if (cont>3)
        {   
            cout<<"La zona: "<<i<<" pertenece a las provincias: "<<endl;
            for (int j = 0; j < 24; j++)
            {
                if (Vprov[j]==i)
                {
                    cout<<j+1<<endl;
                }
                
            }
            
        }

        cont=0;   
    }
    
    return 0;
}