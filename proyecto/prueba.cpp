#include <iostream>
using namespace std;
#include <string>
#include "rlutil.h"

void CartelTurno(int& Ronda, int& Lanzamientos, int& TrufasRonda, int& x, int& y)
{
    int Yaux=y+1;
   
    rlutil::locate(x,y);
    cout<<"+--------------------------------+";
    rlutil::locate(x,y++);
    cout<<"| Ronda: "<<Ronda<<endl;
    rlutil::locate(x,y++);
    cout<<"| Trufas de la Ronda: "<<TrufasRonda<<endl;
    rlutil::locate(x,y++);
    cout<<"| #Lanzamiento: "<<Lanzamientos<<endl;
    rlutil::locate(x,y++);
    cout<<"+--------------------------------+"<<endl;

    
    for (int i = 0; i < 3; i++)
    {   
        rlutil::locate(33-x,Yaux); // locate((Yaux+x-2),y)
        cout<<"|";
        Yaux++;
    }
}

void arr(int Arr[][2]){

    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            Arr[i][j]=i+j;
        }
        
    }
    
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            cout<<Arr[i][j]<<" ";
        }
        
    }
}

int main()
{
    int Ronda=5,TrufasRonda=25,Lanzamientos=4;
    int x,y;
    int Puntos[5][2]={};


    arr(Puntos);

    
    
   

    rlutil::anykey();

return 0;
}