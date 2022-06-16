#include <iostream>
using namespace std;

int main()
{   
    const int tam=10;
    int i,cpos=0,cnega=0;
    float vpos[tam]={},vnega[tam]={},n;

   
    for (i = 0; i < tam; i++)
    {
        cout<<"Ingrese un nro: "<<endl;
        cin>>n;
        if(n!=0)
        {
            if (n>0)
            {   
                vpos[i]=n;
                cpos++;
            }
            else
            {
                vnega[i]=n;
                cnega++;
            }
            
        }
    }
    
    cout<<"La cantidad de elementos positivos es: "<<cpos<<endl;
    cout<<"La cantidad de elementos negativos es: "<<cnega<<endl;

    cout<<"Elementos del vector pos: "<<endl;
    for (i = 0; i < tam; i++)
    {
        if (vpos[i]!=0)
        {
            cout<<vpos[i]<<" "<<endl;
        }
    }
    
    cout<<"Elementos del vector pos: "<<endl;  
    for ( i = 0; i < tam; i++)
    {
        if (vnega[i]!=0)
        {
            cout<<vnega[i]<<" "<<endl;
        }
        
    }
    

    return 0;
}