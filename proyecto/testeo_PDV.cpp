#include <iostream>
#include "rlutil.h"
#include <locale.h>
#include "funciones.h"
using namespace std;

void menu(int &Opcion)
{
    rlutil::setBackgroundColor(rlutil::BLACK);
    rlutil::setColor(rlutil::GREEN);
    rlutil::cls();

    GranCerdo();

    DibujarCuadrado(42, 11, 34, 8);

    rlutil::locate(56, 13);
    cout << "JUGAR";
    rlutil::locate(53, 14);
    cout << "ESTADISTICAS";
    rlutil::locate(55, 15);
    cout << "CERDITOS";
    rlutil::locate(56, 16);
    cout << "SALIR";

    // Adorno divisor inferior
    rlutil::locate(1, 28);
    for (int i = 1; i <= 120; i++)
        cout << "-";

    int y = 0;
    // Posiciono el cursor en la opcion 1 por default
    rlutil::hidecursor();
    rlutil::locate(50, 13 + y);
    cout << char(16) << char(16);
    int key;
    do
    {
        key = rlutil::getkey();

        switch (key)
        {
        case 15: // MOVE UP
            rlutil::locate(50, 13 + y);
            cout << "  ";
            y++;
            // Limite superior
            if (y > 3)
                y = 3;
            break;

        case 14: // MOVE DOWN
            rlutil::locate(50, 13 + y);
            cout << "  ";
            y--;
            // Limite inferior
            if (y < 0)
                y = 0;
            break;

        default:
            break;
        }

        rlutil::locate(50, 13 + y);
        cout << char(16) << char(16);

    } while (key != 1);

    Opcion = y + 1;
}

void Estadisticas(string ganador, int puntos)
{   
    rlutil::setBackgroundColor(rlutil::BLACK);
    rlutil::setColor(rlutil::GREEN);
    rlutil::cls();

    GranCerdo();
    rlutil::locate(48, 8);
    cout << "DATOS DEL MAXIMO GANADOR";

    int largo;
    int x;
    largo = ganador.length();
    x = 60 - (largo / 2);
    rlutil::locate(x, 15);
    cout << ganador;
    int ancho = largo + 5;
    DibujarCuadrado(x - 3, 13, ancho, 5);

    rlutil::locate(57, 20);
    cout << puntos << " PDV";
    DibujarCuadrado(56, 19, 8, 3);
}

int main()
{
    setlocale(LC_ALL, "Spanish");
    int Player[2][HITOS] = {};
    int PDV[2][HITOS] = {};
    string Nombre[2];
    Nombre[0] = "Jugador 1";
    Nombre[1] = "Jugador 2";
    string ganador = "JONATHAN";
    int puntos = 1;
    int Opcion;

    menu(Opcion);

    rlutil::setBackgroundColor(rlutil::BLUE);
    rlutil::setColor(rlutil::WHITE);
    rlutil::cls();
    switch (Opcion)
    {
    case 1:
        rlutil::cls();
        cout << "Opcion 1" << endl;
        rlutil::anykey();
        break;

    case 2:
        rlutil::cls();
        Estadisticas(ganador, puntos);
        rlutil::anykey();
        break;

    case 3:
        rlutil::cls();
        cout << "Opcion 3" << endl;
        rlutil::anykey();
        break;

    case 4:
        rlutil::cls();
        cout << "Opcion 4" << endl;
        rlutil::anykey();
        break;

    default:
        break;
    }

    return 0;
}