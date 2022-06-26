#include <iostream>
#include "rlutil.h"
#include <locale.h>
#include "funciones.h"
using namespace std;


//SumarPDV para un jugador
int SumarPDV(int PDV[][HITOS],int jugador) {

    int suma=0;

    for (int j = 0; j < HITOS; j++)
    {
        suma+=PDV[jugador-1][j];
    }
        
    return suma;
}


void Resultados(int PDV[][HITOS],int Player[][HITOS],string Nombre[])
{
    //Coordenadas iniciales
    const int x=15;
    const int y=12;

    string hitos[HITOS];
    hitos[0] = "MAS TRUFAS EN TOTAL";
    hitos[1] = "OINKS";
    hitos[2] = "CERDO CODICIOSO";
    hitos[3] = "CADA 50 TRUFAS";

    string descripcion[HITOS];
    descripcion[0]=" Trufas";
    descripcion[1]=" Oinks";
    descripcion[2]=" Lanzamientos";
    descripcion[3]=" Trufas";
    

    rlutil::locate(50, 2);
    cout << "GRAN CERDO" << endl;
    for (int i = 0; i < 120; i++)
    {
        cout<<"-";
    }

    //Dibujo cartel resultados
    DibujarCuadrado(45,5,17,3);
    rlutil::locate(48,6);
    cout<<" RESULTADOS ";

    //Posiciona string de hitos
    for (int i = 0; i < HITOS; i++)
    {   
        rlutil::locate(x, y + i);
        cout << hitos[i];
    }
    
    //PDV jugador 1
    for (int i = 0; i < HITOS; i++)
    {
        rlutil::locate(x+30, y + i);
        cout << PDV[0][i] << " PDV  ("<< Player[0][i] << descripcion[i] << ")";
    }
     

    //PDV jugador 2
    for (int i = 0; i < HITOS; i++)
    {
        rlutil::locate(x+60, y + i);
        cout <<PDV[1][i] << " PDV  ("<< Player[1][i] << descripcion[i] << ")";
    }

    //Dibujo cartel
    DibujarCuadrado(x-2,y-2,90,HITOS+4);

    int pisocartel=y+HITOS+1; //var auxiliar para la posicion inferior del cartel. (se suma 1 por el margen entre hito y el piso)
    
    //Guardo Cant. de PDV por jugador
    int PuntosJ1= SumarPDV(PDV,1);
    int PuntosJ2 = SumarPDV(PDV,2);

    //Posiciono textos/ganador/ptos
    rlutil::locate(x+30,y-3);
    cout<<Nombre[0];
    rlutil::locate(x+30,pisocartel+2);
    cout<<PuntosJ1<<" PDV";
    rlutil::locate(x+60,y-3);
    cout<<Nombre[1];
    rlutil::locate(x+60,pisocartel+2);
    cout<<PuntosJ2<<" PDV";

    int ganador;
    if (PuntosJ1>PuntosJ2)
    {
        ganador=0;
    }
    else
    {
        ganador=1;
    }
    

    rlutil::locate(40,y+12);
    cout<<"GANADOR: "<<Nombre[ganador] <<endl;
    
    rlutil::locate(1,y+17);
    cout<<" Pulse cualquier tecla para volver al menu"<<endl;
    rlutil::locate(44,y+17);
    rlutil::anykey();

}


int main() {

    setlocale(LC_ALL, "Spanish");
    int Player[2][HITOS]={};
    int PDV[2][HITOS]={};
    string Nombre[2];
    Nombre[0]="Jugador 1";
    Nombre[1]="Jugador 2";

    Resultados(PDV,Player,Nombre);

    rlutil::anykey();

    return 0;
}