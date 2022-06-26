#include <iostream>
#include "rlutil.h"
#include <locale.h>
#include "funciones.h"
using namespace std;





int main() {

    setlocale(LC_ALL, "Spanish");
    int Player[2][HITOS]={};
    int PDV[2][HITOS]={};
    string Nombre[2];
    Nombre[0]="Jugador 1";
    Nombre[1]="Jugador 2";

    Resultados(PDV,Player,Nombre);
    

    // Menú principal
    rlutil::setBackgroundColor(rlutil::RED);
    rlutil::cls();
    GranCerdo();

    DibujarCuadrado(42,11,34,8);
    rlutil::locate(52,13);
    cout << "1: JUGAR";
    rlutil::locate(52,14);
    cout << "2: ESTADISTICAS";
    rlutil::locate(52,15);
    cout << "3: CERDITOS";
    rlutil::locate(52,16);
    cout << "0: SALIR";

    rlutil::locate(1,28);
    for (int i = 1; i <= 120; i++)
    {   
        cout<<"-";
    }
    

    rlutil::anykey();

    return 0;
}