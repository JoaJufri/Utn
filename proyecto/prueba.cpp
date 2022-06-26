#include <iostream>
using namespace std;
#include <string>
#include "rlutil.h"

void CartelTurno(int Ronda, int Lanzamientos, int TrufasRonda, int x, int y)
{
    int Yaux=y+1;
   
    rlutil::locate(x,y);
    cout<<"+--------------------------------+"<<endl;
    rlutil::locate(x,y+1);
    cout<<"| Ronda: "<<Ronda<<endl;
    rlutil::locate(x,y+2);
    cout<<"| Trufas de la Ronda: "<<TrufasRonda<<endl;
    rlutil::locate(x,y+3);
    cout<<"| #Lanzamiento: "<<Lanzamientos<<endl;
    rlutil::locate(x,y+4);
    cout<<"+--------------------------------+"<<endl;

    
    for (int i = 0; i < 3; i++)
    {   
        rlutil::locate(33+x,Yaux); 
        cout<<"|";
        Yaux++;
    }
}

//Funcion dibujar cuadrado

void DibujarCuadrado(int x, int y, int ancho, int alto) {

    int xaux=x;
    int yaux=y;
    string BordeHorizontal="+";
    //Dibuja techo y piso "  +-------+"
    for (int i = 0; i <= ancho-2; i++)
    {
        BordeHorizontal+="-";  
    }

    BordeHorizontal+="+";
  
    //Dibuja borde superior
    rlutil::locate(x,y);
    cout<<BordeHorizontal;

    //Dibuja lado izquierdo "|" (le resto 2 al alto por los bordes sup. e inferior)
    for (int i = 0; i < alto-2; i++)
    {
        yaux++;
        rlutil::locate(x,yaux);
        cout<<"|";
    }
    
    //Dibuja lado derecho "|" (le resto 2 al alto por los bordes sup. e inferior)
    yaux=y;
    for (int i = 0; i < alto-2; i++)
    {   
        yaux++;
        rlutil::locate(x+ancho,yaux);
        cout<<"|";
    }
    
    //Dibuja borde inferior (Le resto 1 al alto pq ya dibuje el borde superior)
    rlutil::locate(x,y+alto-1);
    cout<<BordeHorizontal;

}


//Calcula Puntos De Victoria
void CalculoPDV(int player[][4], int PDV[][4]) {

    int a= player[0][0];
    int b= player[1][0];

    //Mas Trufas en total
    if (a==b)
    {
        PDV[0][0]=5;
        PDV[1][0]=5;
    }
    else if (a>b)
    {
        PDV[0][0]=5;
    }
    else
    {
        PDV[1][0]=5;
    }
    

    //Cada 50 trufas
    PDV[0][1] = player[0][0]/50;
    PDV[1][1] = player[1][0]/50;
    
    //Cerdo codicioso
    a=player[0][2];
    b=player[1][2];

    if (a==b) 
    {
        PDV[0][3]=2;
        PDV[1][3]=2;
    }
    else if (a>b) 
    {
        PDV[0][3]=2;
    }
    else 
    {
        PDV[1][3]=2;
    }
    
    //Cant de oinks
    PDV[0][3]=player[0][1]*2;
    PDV[1][3]=player[1][1]*2;
}



int main()
{
    int Ronda=5,TrufasRonda=25,Lanzamientos=4;
    int x,y;
    
    rlutil::cls();
    // CartelTurno(Ronda,Lanzamientos,TrufasRonda,x,y);

    DibujarCuadrado(15,4,60,10);

    rlutil::locate(80,4);
    cout<<"TEXTO RE LOCO";
    rlutil::cls();
    cout<<"fin";
    rlutil::anykey();

return 0;
}