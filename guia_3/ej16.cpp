#include <iostream>
using namespace std;

int main()
{
    int i,j,divisores=0;

    for (i = 1; i <= 1000; i++)
    {
        for (j = 1; j <= i; j++)
        {
            if (i%j==0)
            {
                divisores++;
            }
        }

        if (divisores==2)
        {
            cout<<i<<endl;
        }
        divisores=0;
        
    }
    
    return 0;
}