#include <iostream>
using namespace std;

int main()
{
    float vec[10],n;
    int i,pos;

    for (i = 0; i < 9; i++)
    {
        cout<<"Ingrese un nro: "<<endl;
        cin>>vec[i];
    }
    
    cout<<"Ahora ingrese un numero para agregar: "<<endl;
    cin>>n;

    for (i = 0; i < 10; i++)
    {
        if (n>vec[i] && n<vec[i+1])
        {
           
           pos=i+1;
        }
        
    }
    
   for (i = 8; i >= pos; i--)
   {   
       vec[i+1]=vec[i];
   }
   
   vec[pos]=n;

   for (i = 0; i < 10; i++)
   {
       cout<<vec[i]<<" ";
   }
   
    return 0;
}