#include <iostream>
#include <cstdlib>
#include <stdio.h>  //fun ran
#include <stdlib.h> //Libreria que incluye la funcion system(cls) que limpia la terminal.
#include <time.h>   //func time para funcion sran()
#include <string>   // fun getline(), strings Nombres
#include "funciones.h"
#include "rlutil.h"
using namespace std;

//--------------------------CONFIGURACIONES----------------------------------



int main()
{   
    int Player[2][HITOS] = {}; // Matriz para 2 jugadores PLayer[Turno]--[trufas_acumuladas][Cant_Oinks] [Max_Lanzamientos] [Cada 50 trufas]
    int Lanza[2][RONDAS] = {};    // Matriz para guardar lanzamientos x Ronda Lanza[Turno]--[Ronda]
    int PDV[2][HITOS] = {};    // Matriz para almacenar puntos de victoria PDV[turno]--[+Trufasentotal][C/50trufas][Oinks][Cerdocodicioso]
    string Nombre[2];         // Nombre[0]==Jugador 1(turno 0), Nombre[1]==Jugador2 (Turno 1)
    bool on = true;
    char Continuar;
    int opcion, Lanzar2[2], Lanzar3[3], Lanzamientos;
    int Trufas,TrufasRonda, Turno, Dados, Ronda,TurnoAux;
    int Unos = 0;
    bool Hundido = false, ForzarTurno = false, Oink = false;
    srand(time(NULL));

    while (on == true)
    {
        //MENU PRINCIPAL
        Menu(opcion);
        rlutil::showcursor();
        rlutil::setBackgroundColor(rlutil::BLUE);
        rlutil::setColor(rlutil::WHITE);
        rlutil::cls();
        switch (opcion)
        {
        case 1:
            GranCerdo();
            // Peticion de Nombres
            rlutil::locate(2,7);
            cout << "Bienvenido a Gran Cerdo. Ingrese Nombre de jugador 1: " << endl;
            rlutil::locate(56,7);
            getline(cin, Nombre[0]);
            rlutil::locate(2,9);
            cout << "Bienvenido a Gran Cerdo. Ingrese Nombre de jugador 2: " << endl;
            rlutil::locate(56,9);
            getline(cin, Nombre[1]);

            // Inicio de juego
            rlutil::cls();
            // Sorteo Inicio (Acá va a mostrar la funcion Sorteo y devolver el turno del jugador que empieza)
            Turno = Sorteo(Nombre);

            // Inicio de Turnos
            for (int i = 0; i < 2; i++)
                for (int j = 0; j < HITOS-1; j++)
                    Player[i][j] = 0;

            // Reinicio de variables x juego
            Dados = 2;
            Ronda = 1;
            TrufasRonda = 0;
            Lanzamientos = 0;

            for (int i = 0; i < RONDAS*2; i++)
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

                    //TITULO ----GRAN CERDO--
                    GranCerdo();

                    if (Turno==0) {
                        TurnoAux=1;
                         }
                    else {
                        TurnoAux=0;
                         }
                    
                    if (Dados == 2)
                    {
                        TirarDados(Lanzar2, 2);
                        Trufas = SumarDados(Lanzar2, 2);
                        Unos = ContarUnos(Lanzar2, 2);
                        if (Unos == 0)
                        {
                            Oink = Hay_Oink(Lanzar2, 2);
                        }

                        //INTERFAZ VISUAL DEL TURNO/LANZAMIENTO
                        rlutil::locate(7, 5);
                        cout << "TURNO DE: " << Nombre[Turno] << endl;
                        
                        CartelTurno(Ronda, Lanzamientos, TrufasRonda);

                        rlutil::locate(3, 14);
                        cout << "TOTAL ACUMULADO POR " << Nombre[Turno] << ": " << Player[Turno][0] << endl;
                        
                        rlutil::locate(60, 14);
                        cout << "TOTAL ACUMULADO POR " << Nombre[TurnoAux] << ": " << Player[TurnoAux][0] << endl;
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

                        //INTERFAZ VISUAL DEL TURNO/LANZAMIENTO
                        rlutil::locate(7, 5);
                        cout << "TURNO DE: " << Nombre[Turno] << endl;
                        CartelTurno(Ronda, Lanzamientos, TrufasRonda);
                        
                        rlutil::locate(3, 14);
                        cout << "TOTAL ACUMULADO POR " << Nombre[Turno] << ": " << Player[Turno][0] << endl;
                        rlutil::locate(60, 14);
                        cout << "TOTAL ACUMULADO POR " << Nombre[TurnoAux] << ": " << Player[TurnoAux][0] << endl;
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

                        Player[TurnoAux][0]+=Player[Turno][0]; 
                        Player[Turno][0] = 0;
                        Trufas = 0;
                        ForzarTurno = true;
                        Continuar = 'N';
                        cout << "Te hundiste en el barro y pasaste todas tus trufas al rival!" << endl;
                        break;
                    }

                    if (Oink == true)
                    {
                        cout << "Hiciste un Oink!" << endl;
                        Trufas *= 2;
                        Player[Turno][1]++; // ACUMULO OINKS POR JUGADOR
                        ForzarTurno = true;
                        Continuar = 'S';
                    }

                    // Acumula Trufas ganadas por el jugador y Muestra x pantalla
                    Player[Turno][0] += Trufas;
                    TrufasRonda += Trufas;
                    rlutil::locate(1,27);
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
                        {   rlutil::locate(1,29);
                            cout << "Desea Continuar?" << endl;
                            rlutil::locate(17,29);
                            cin >> Continuar;
                            Continuar = toupper(Continuar);

                        } while (Continuar != 'S' && Continuar != 'N');
                    }
                    else
                    {   
                        rlutil::locate(1,29);
                        cout<<"Pulse cualquier tecla para continuar";
                        rlutil::locate(38,29);
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
            //---FINAL DEL JUEGO--
            //Se calculan y almacenan los Puntos de Victoria
            MaximosLanzamientos(Lanza,Player);
            CalculoPDV(Player, PDV);
            // Resultados finales para ambos jugadores, y ganador.
            Resultados(PDV,Player,Nombre);

            cin.ignore();
            break;

        case 2:
            rlutil::cls();
            /* ESTADISTICAS */
            break;

        case 3:
            rlutil::cls();
            /* CERDITOS */
            break;

        case 4:
            cout<<"Estas seguro que queres salir ? S/N"<<endl;
            cin>>Continuar;
            if (toupper(Continuar)=='S')
            {   
                rlutil::cls();
                cout << "Gracias por jugar :) , oprima cualquier tecla para salir " << endl;
                rlutil::anykey();
                /*SALIR / fin del programa*/
                on = false;
            }
            cin.ignore();
            break;
        }
        
        //Fin del switch
    }
    return 0;
}