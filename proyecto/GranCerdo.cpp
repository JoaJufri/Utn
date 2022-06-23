#include <iostream>
#include <cstdlib>
#include <stdio.h>  //fun ran
#include <stdlib.h> //Libreria que incluye la funcion system(cls) que limpia la terminal.
#include <time.h>   //func time para funcion sran()
#include <string>   // fun getline(), strings Nombres
#include "funciones.h"
#include "rlutil.h"
using namespace std;

/*-------------------FIN DE DECLARACION DE FUNCIONES----------------------------*/

int main()
{
    int Player[2][3] = {}; // Vector para 2 jugadores PLayer[Turno][trufas_acumuladas][Cant_Oinks] [Max_Lanzamientos]
    int Lanza[2][5] = {};  // Vector para guardar lanzamientos x Ronda - [Turno][Ronda]
    bool on = true;
    char Continuar;
    int opcion, Lanzar2[2], Lanzar3[3], Lanzamientos;
    string Nombre[2]; // Nombre[0]==Jugador 1(turno 0), Nombre[1]==Jugador2 (Turno 1)
    int Trufas, LanzMax1, LanzMax2, TrufasRonda, Turno, Dados, Ronda;
    int Unos = 0;
    bool Hundido = false, ForzarTurno = false, Oink = false;
    srand(time(NULL));

    rlutil::setBackgroundColor(rlutil::BLUE);

    while (on == true)
    {
        rlutil::cls();
        // Menú principal
        cout << "    GRAN CERDO" << endl;
        cout << "----------------------" << endl;
        cout << "    1: Jugar" << endl;
        cout << "    2: Estadisticas" << endl;
        cout << "    3: Cerditos" << endl;
        cout << "----------------------" << endl;
        cout << "    0: Salir" << endl;

        // Seleccion de opcion de menú
        cin >> opcion;
        rlutil::cls();
        switch (opcion)
        {
        case 1:

            // Peticion de Nombres
            cin.ignore();
            cout << "Bienvenido a Gran Cerdo. Ingrese Nombre de jugador 1: " << endl;
            getline(cin, Nombre[0]);
            cout << "Bienvenido a Gran Cerdo. Ingrese Nombre de jugador 2: " << endl;
            getline(cin, Nombre[1]);

            // Inicio de juego
            rlutil::cls();
            // Sorteo Inicio (Acá va a mostrar la funcion Sorteo y devolver el turno del jugador que empieza)
            Turno = Sorteo(Nombre);
            rlutil::anykey();
            rlutil::cls();

            // Inicio de Turnos
            for (int i = 0; i < 2; i++)
                for (int j = 0; j < 3; j++)
                    Player[i][j] = 0;

            // Reinicio de variables x juego
            Dados = 2;
            Ronda = 1;
            TrufasRonda = 0;
            Lanzamientos = 0;
            LanzMax1 = 0;
            LanzMax2 = 0;

            for (int i = 0; i < 10; i++)
            {
                if (i % 2 == 0 && i != 0)
                    Ronda++;

                do
                {
                    Lanzamientos++;
                    ForzarTurno = false;
                    Oink = false;
                    Continuar = 'S';
                    Trufas = 0, Unos = 0;

                    rlutil::locate(50, 2);
                    cout << "GRAN CERDO" << endl;
                    cout << "------------------------------------------------------------------------------------------------------------------------" << endl;

                    if (Dados == 2)
                    {
                        TirarDados(Lanzar2, 2);
                        Trufas = SumarDados(Lanzar2, 2);
                        Unos = ContarUnos(Lanzar2, 2);
                        if (Unos == 0)
                        {
                            Oink = Hay_Oink(Lanzar2, 2);
                        }

                        rlutil::locate(7, 5);
                        cout << "TURNO DE: " << Nombre[Turno] << endl;
                        /*
                        cout << "Ronda: " << Ronda << endl;
                        cout << "Trufas de la ronda: " << TrufasRonda << endl;
                        cout << "#Lanzamiento: " << Lanzamientos << endl;
                        */

                        CartelTurno(Ronda, Lanzamientos, TrufasRonda);

                        rlutil::locate(7, 14);
                        cout << "TOTAL ACUMULADO POR " << Nombre[Turno] << ": " << Player[Turno][0] << endl;
                        Lanza[Turno][Ronda - 1] = Lanzamientos; // Guarda el ultimo contador de lanzamiento de la ronda para el turno 0 o 1
                        rlutil::locate(1, 17);
                        MostrarDados(Lanzar2, 2);

                    }
                    else
                    {
                        TirarDados(Lanzar3, 3);
                        Trufas = SumarDados(Lanzar3, 3);
                        Unos = ContarUnos(Lanzar3, 3);
                        if (Unos == 0)
                            Oink = Hay_Oink(Lanzar3, 3);

                        rlutil::locate(7, 5);
                        cout << "TURNO DE: " << Nombre[Turno] << endl;
                        CartelTurno(Ronda, Lanzamientos, TrufasRonda);
                        /*
                        cout << "Ronda: " << Ronda << endl;
                        cout << "Trufas de la ronda: " << TrufasRonda << endl;
                        cout << "#Lanzamiento: " << Lanzamientos << endl;
                        */
                        rlutil::locate(7, 14);
                        cout << "TOTAL ACUMULADO POR " << Nombre[Turno] << ": " << Player[Turno][0] << endl;
                        Lanza[Turno][Ronda - 1] = Lanzamientos; // Guarda el ultimo contador lanzamiento de La ronda para el turno 0 o 1
                        rlutil::locate(1, 17);
                        MostrarDados(Lanzar3, 3);
                    }

                    // Evaluacion de jugada:
                    switch (Unos)
                    {
                    case 1:
                        Trufas = 0;
                        cout << "Perdiste las trufas en esta ronda. " << endl;
                        ForzarTurno = true;
                        Continuar = 'N';
                        break;

                    case 2:
                        Trufas = 0;
                        Player[Turno][0] = 0;
                        Hundido = true;
                        ForzarTurno = true;
                        Continuar = 'N';
                        cout << "Te hundiste en el barro! " << endl;
                        break;

                    case 3:
                        if (Turno == 0)
                        {
                            Player[Turno + 1][0] += Player[Turno][0];
                        }
                        else
                        {
                            Player[Turno - 1][0] += Player[Turno][0];
                        }

                        Trufas = 0;
                        Player[Turno][0] = 0;
                        ForzarTurno = true;
                        Continuar = 'N';
                        cout << "Te hundiste en el barro y pasaste todas tus trufas al rival!" << endl;
                        break;
                    }

                    if (Oink == true)
                    {
                        cout << "Hiciste un Oink!" << endl;
                        Trufas *= 2;
                        Player[Turno][1]++;
                        ForzarTurno = true;
                        Continuar = 'S';
                    }

                    // Acumula Trufas ganadas por el jugador y Muestra x pantalla
                    Player[Turno][0] += Trufas;
                    TrufasRonda += Trufas;
                    cout << "Trufas ganadas en el lanzamiento actual: " << Trufas << endl;

                    if (Hundido == true || (Player[0][0] > 50 && Player[1][0] > 50))
                    {
                        Dados = 3;
                        Hundido = false;
                    }

                    // Si no se fuerza el cambio de turno, pregunta si desea continuar hasta que se ingrese 'S' o 'N'
                    if (ForzarTurno == false)
                    {
                        do
                        {
                            cout << "Desea Continuar?" << endl;
                            cin >> Continuar;
                            Continuar = toupper(Continuar);

                        } while (Continuar != 'S' && Continuar != 'N');
                    }
                    else
                    {
                        rlutil::anykey();
                    }

                    // Cambio de turno (Jugador)
                    if (Continuar == 'N')
                    {
                        TrufasRonda = 0;
                        Lanzamientos = 0;

                        if (Turno == 0)
                        {
                            Turno = 1;
                        }
                        else
                        {
                            Turno = 0;
                        }
                    }

                    rlutil::cls();
                } while (Continuar == 'S');
            }

            // Calcular Maximo para c/jugador. (Hacerlo función)
            for (int i = 0; i < 2; i++)
            {
                for (int j = 0; j < 5; j++)
                {
                    if (i == 0)
                    {
                        if (Lanza[i][j] > LanzMax1)
                        {
                            LanzMax1 = Lanza[i][j];
                        }
                    }
                    else
                    {
                        if (Lanza[i][j] > LanzMax2)
                        {
                            LanzMax2 = Lanza[i][j];
                        }
                    }
                }
            }

            // Prueba Lanzamientos maximos
            cout << "Lanzamiento maximo para el jugador: " << Nombre[0] << " : " << LanzMax1 << endl;
            cout << "Lanzamiento maximo para el jugador: " << Nombre[1] << " : " << LanzMax2 << endl;
            cout << "DATOS DEL GANADOR" << endl;
            rlutil::anykey();

            break;

        case 2:
            rlutil::cls();
            /* ESTADISTICAS */
            break;

        case 3:
            rlutil::cls();
            /* CERDITOS */
            break;

        case 0:
            cout << "Gracias por jugar :) , oprima cualquier tecla para salir " << endl;
            rlutil::anykey();
            /*SALIR / fin del programa*/
            on = false;
            break;
        }

        // Fin del Switch Mostrar Ganador y PDV de cada Jugador
    }
    return 0;
}