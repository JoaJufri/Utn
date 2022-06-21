#include <iostream>
using namespace std;
#include <string>
#include "rlutil.h"

int main()
{
    int Ronda=5,Lanzamiento=5,TrufasRonda=12;
   
    rlutil::locate(10,20);
    cout<<"+--------------------------------+";
    rlutil::locate(10,21);
    cout<<"| Ronda: "<<Ronda<<endl;
    rlutil::locate(10,22);
    cout<<"| Trufas de la Ronda: "<<TrufasRonda<<endl;
    rlutil::locate(10,23);
    cout<<"| #Lanzamiento: "<<Lanzamiento<<endl;
    rlutil::locate(10,24);
    cout<<"+--------------------------------+"<<endl;

    int y=21;
    for (int i = 0; i < 3; i++)
    {   
        rlutil::locate(43,y);
        cout<<"|";
        y++;
    }
    


    rlutil::anykey();
return 0;
}