#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED
// DEFINICION DE CONSTANTES
#define HITOS 4
#define RONDAS 5

#include <iostream>
using namespace std;
#include <stdio.h>
#include "rlutil.h"

//Prototipos de funciones
void TirarDados(int vec[], int dados);
void MostrarDados(int vec[], int c_dados);
void DibujarCuadrado(int x, int y, int ancho, int alto);
int SumarDados(int vec[], int dados);
int DadoMax(int vec[], int dados);
void CartelTurno(int Ronda, int Lanzamientos, int TrufasRonda);
void CalculoPDV(int player[][HITOS], int PDV[][HITOS]);
void GranCerdo();
int SumarPDV(int PDV[][HITOS], int jugador);
void Resultados(int PDV[][HITOS], int Player[][HITOS], string Nombre[]);
void Estadisticas(string ganador, int puntos); 
void VaciarMatriz(int Matriz[][HITOS]);
int Sorteo(string Vnombre[]);
int ContarUnos(int vec[], int cant);
bool Hay_Oink(int vec[], int cant);
void MaximosLanzamientos(int Lanza[][RONDAS], int Player[][HITOS]);
void Cerditos();
void Menu(int &opcion);


//Definición de funciones

/**
 * @brief Devuelve un número al azar de dados por jugador
 *
 * @param vec Vector de dados
 * @param dados Cantidad de dados
 */
void TirarDados(int vec[], int dados)
{
    for (int i = 0; i < dados; i++)
        vec[i] = 1 + rand() % 6;
}

/**
 * @brief Muestra los dados sorteados
 *
 * @param vec Vector de dados
 * @param c_dados Cantidad de dados
 */
void MostrarDados(int vec[], int c_dados)
{
    string dado[5] = {};

    // Da un margen izquierdo de 5 espacios a cada dado
    for (int i = 0; i < 5; i++)
        dado[i] = "     ";

    // Asigna un dado en cada índice del vector
    for (int i = 0; i < c_dados; i++)
    {
        switch (vec[i])
        {
        case 1:
            dado[0] += " +-----+ ";
            dado[1] += " |     | ";
            dado[2] += " |  0  | ";
            dado[3] += " |     | ";
            dado[4] += " +-----+ ";
            break;
        case 2:
            dado[0] += " +-----+ ";
            dado[1] += " |   0 | ";
            dado[2] += " |     | ";
            dado[3] += " | 0   | ";
            dado[4] += " +-----+ ";
            break;
        case 3:
            dado[0] += " +-----+ ";
            dado[1] += " |   0 | ";
            dado[2] += " |  0  | ";
            dado[3] += " | 0   | ";
            dado[4] += " +-----+ ";
            break;
        case 4:
            dado[0] += " +-----+ ";
            dado[1] += " | 0 0 | ";
            dado[2] += " |     | ";
            dado[3] += " | 0 0 | ";
            dado[4] += " +-----+ ";
            break;
        case 5:
            dado[0] += " +-----+ ";
            dado[1] += " | 0 0 | ";
            dado[2] += " |  0  | ";
            dado[3] += " | 0 0 | ";
            dado[4] += " +-----+ ";
            break;
        case 6:
            dado[0] += " +-----+ ";
            dado[1] += " | 0 0 | ";
            dado[2] += " | 0 0 | ";
            dado[3] += " | 0 0 | ";
            dado[4] += " +-----+ ";
            break;
        }
    }

    cout << (" TU JUGADA: \n") << endl;

    for (int i = 0; i < 5; i++)
        cout << dado[i] << endl;
    cout << "\n";
}

/**
 * @brief  Dibuja un cartel en pantalla
 *
 * @param x Origen izq. del cartel
 * @param y Origen superior. del cartel
 * @param ancho Ancho del cartel
 * @param alto Alto del cartel
 */
void DibujarCuadrado(int x, int y, int ancho, int alto)
{
    int yaux = y;
    string BordeHorizontal = "+";
    // Dibuja techo y piso "  +-------+"
    for (int i = 0; i <= ancho - 2; i++)
        BordeHorizontal += "-";
    BordeHorizontal += "+";

    // Dibuja borde superior
    rlutil::locate(x, y);
    cout << BordeHorizontal;
    // Dibuja borde inferior (Le resta 1 al alto porque ya dibuja el borde superior)
    rlutil::locate(x, y + alto - 1);
    cout << BordeHorizontal;

    // Dibuja los laterales del cuadro (le resta 2 al alto por los bordes superior e inferior)
    for (int i = 0; i < alto - 2; i++)
    {
        yaux++;
        rlutil::locate(x, yaux);
        cout << "|";
        rlutil::locate(x + ancho, yaux);
        cout << "|";
    }
}

/**
 * @brief Suma los dados por jugador
 *
 * @param vec Vector de dados
 * @param dados Cantidad de dados
 * @return int Valor de la suma de dados
 */
int SumarDados(int vec[], int dados)
{
    int acu = 0;
    for (int i = 0; i < dados; i++)
        acu += vec[i];
    return acu;
}

/**
 * @brief Halla el dado máximo por jugador
 *
 * @param vec Vector de dados
 * @param dados Cantidad de dados
 * @return int Número máximo de los dados
 */
int DadoMax(int vec[], int dados)
{
    int max = 0;
    for (int i = 0; i < dados; i++)
        if (vec[i] > max)
            max = vec[i];
    return max;
}

/**
 * @brief Crea un cartel con la información del turno
 *
 * @param Ronda Número de ronda
 * @param Lanzamientos Número de lanzamiento
 * @param TrufasRonda Número de Trufas en la ronda
 */
void CartelTurno(int Ronda, int Lanzamientos, int TrufasRonda)
{
    DibujarCuadrado(3, 8, 27, 5);
    rlutil::locate(5, 9);
    cout << "Ronda: " << Ronda << endl;
    rlutil::locate(5, 10);
    cout << "Trufas de la Ronda: " << TrufasRonda << endl;
    rlutil::locate(5, 11);
    cout << "#Lanzamiento: " << Lanzamientos << endl;
}

/**
 * @brief Calcula Puntos De Victoria (update)
 *
 * @param player Órden de matriz Player: [trufas_acumuladas][Cant_Oinks] [Lanzamiento Max] [c/50 trufas]
 * @param PDV Órden de matriz pdv: [TrufasEnTotal] [CantOinks*2] [CerdoCodicioso] [c/50 trufas]
 */
void CalculoPDV(int player[][HITOS], int PDV[][HITOS])
{
    // Mas Trufas en total
    int a = player[0][0];
    int b = player[1][0];

    if (a == b)
    {
        PDV[0][0] = 5;
        PDV[1][0] = 5;
    }
    else if (a > b)
    {
        PDV[0][0] = 5;
    }
    else
    {
        PDV[1][0] = 5;
    }

    // Cant de oinks
    PDV[0][1] = player[0][1] * 2;
    PDV[1][1] = player[1][1] * 2;

    // Cerdo codicioso
    a = player[0][2];
    b = player[1][2];

    if (a == b)
    {
        PDV[0][2] = 2;
        PDV[1][2] = 2;
    }
    else if (a > b)
    {
        PDV[0][2] = 2;
    }
    else
    {
        PDV[1][2] = 2;
    }

    // Cada 50 trufas Player (modulo trufas totales por jugador)
    player[0][3] = player[0][0] - player[0][0] % 50;
    player[1][3] = player[1][0] - player[1][0] % 50;

    // Cada 50 trufas PDV
    PDV[0][3] = player[0][0] / 50;
    PDV[1][3] = player[1][0] / 50;
}

/**
 * @brief Suma PDV para un jugador
 *
 * @param PDV Órden de matriz pdv: [Max_Lanzamientos] [Cada 50 trufas]
 * @param jugador Número del jugador
 * @return Resultado de la suma
 */
int SumarPDV(int PDV[][HITOS], int jugador)
{
    int suma = 0;
    for (int j = 0; j < HITOS; j++)
        suma += PDV[jugador - 1][j];
    return suma;
}

/**
 * @brief Titulo del juego
 *
 */
void GranCerdo()
{
    rlutil::locate(55, 2);
    cout << "GRAN CERDO" << endl;
    for (int i = 0; i < 120; i++)
        cout << "-";
}



/**
 * @brief Muestra Estadisticas.
 * Nombre del jugador con mayor cantidad de pdv hasta el momento (Nombre y puntaje),
 * Arreglos visuales
 * @param ganador string nombre
 * @param puntos int pdv
 */
void Estadisticas(string ganador, int puntos)
{   
    GranCerdo();
    rlutil::hidecursor();
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

    // Adorno divisor inferior
    rlutil::locate(1, 28);
    for (int i = 1; i <= 120; i++)
        cout << "-";
}

/**
 * @brief Muestra la pantalla de resultados del jugador
 *
 * @param PDV Órden de matriz pdv: [Max_Lanzamientos] [Cada 50 trufas]
 * @param Player Órden matriz player: [trufas_acumuladas][Cant_Oinks]
 * @param Nombre Nombre del jugador
 */
void Resultados(int PDV[][HITOS], int Player[][HITOS], string Nombre[],int &MaximoPuntaje, string &MaxGanador)
{
    // Coordenadas iniciales
    const int x = 15;
    const int y = 12;

    string hitos[HITOS];
    hitos[0] = "MAS TRUFAS EN TOTAL";
    hitos[1] = "OINKS";
    hitos[2] = "CERDO CODICIOSO";
    hitos[3] = "CADA 50 TRUFAS";

    string descripcion[HITOS];
    descripcion[0] = "Trufas";
    descripcion[1] = "Oinks";
    descripcion[2] = "Lanzamientos";
    descripcion[3] = "Trufas";

    GranCerdo();

    // Dibujo cartel resultados
    DibujarCuadrado(51, 5, 17, 3);
    rlutil::locate(55, 6);
    cout << "RESULTADOS";

    // Posiciona string de hitos
    for (int i = 0; i < HITOS; i++)
    {
        rlutil::locate(x, y + i);
        cout << hitos[i];
    }

    // PDV jugador 1
    for (int i = 0; i < HITOS; i++)
    {
        rlutil::locate(x + 30, y + i);
        cout << PDV[0][i] << " PDV  (" << Player[0][i] << " " << descripcion[i] << ")";
    }

    // PDV jugador 2
    for (int i = 0; i < HITOS; i++)
    {
        rlutil::locate(x + 60, y + i);
        cout << PDV[1][i] << " PDV  (" << Player[1][i] << " " << descripcion[i] << ")";
    }

    // Dibujo cartel
    DibujarCuadrado(x - 2, y - 2, 90, HITOS + 4);

    int pisocartel = y + HITOS + 1; // var auxiliar para la posicion inferior del cartel. (se suma 1 por el margen entre hito y el piso)

    // Guardo Cant. de PDV por jugador
    int PuntosJ1 = SumarPDV(PDV, 1);
    int PuntosJ2 = SumarPDV(PDV, 2);

    // Posiciono textos/ganador/ptos
    rlutil::locate(x + 30, y - 3);
    cout << Nombre[0];
    rlutil::locate(x + 30, pisocartel + 2);
    cout << PuntosJ1 << " PDV";
    rlutil::locate(x + 60, y - 3);
    cout << Nombre[1];
    rlutil::locate(x + 60, pisocartel + 2);
    cout << PuntosJ2 << " PDV";

    //Calculo ganador actual y ganador Maximo
    int ganador;
    int PDVganador;

    if (PuntosJ1 > PuntosJ2)
    {
        ganador = 0;
        PDVganador=PuntosJ1;
        
    }
    else
    {
        ganador = 1;
        PDVganador = PuntosJ2;
    }

    //Calculo de Ganador Record actual (MAXIMO PUNTAJE)
    if (PDVganador > MaximoPuntaje)
    {
        MaximoPuntaje = PDVganador;
        MaxGanador = Nombre[ganador];
    }

    int ancho = Nombre[ganador].length() + 9;
    ancho = 60 - (ancho / 2);
    rlutil::locate(ancho, pisocartel + 5);
    cout << "GANADOR: " << Nombre[ganador] << endl;

    rlutil::locate(1, y + 17);
    cout << " Pulse cualquier tecla para volver al menu" << endl;
    rlutil::locate(44, y + 17);
    rlutil::anykey();
}



/**
 * @brief Vacia una Matriz de 2 filas y HITOS cantidad de columnas (Constante)
 *
 * @param Matriz Player o PDV
 */
void VaciarMatriz(int Matriz[][HITOS])
{
    for (int i = 0; i < 2; i++)
        for (int j = 0; j < HITOS; j++)
            Matriz[i][j] = 0;
}

/**
 * @brief Sorteo Inicial
 *
 * @param Vnombre Nombre del jugador
 * @return int Número del turno
 */
int Sorteo(string Vnombre[])
{
    bool flag = false;
    int Lanzar[2], turno;

    while (flag == false)
    {
        int acu1 = 0, acu2 = 0, max1 = 0, max2 = 0;

        TirarDados(Lanzar, 2);
        acu1 = SumarDados(Lanzar, 2);
        max1 = DadoMax(Lanzar, 2);

        cout << "Turno de " << Vnombre[0] << "\n\n";
        cout << "Pulse cualquier tecla para lanzar dados \n\n";
        rlutil::anykey();
        MostrarDados(Lanzar, 2);

        TirarDados(Lanzar, 2);
        acu2 = SumarDados(Lanzar, 2);
        max2 = DadoMax(Lanzar, 2);

        cout << "Turno de " << Vnombre[1] << "\n\n";
        cout << "Pulse cualquier tecla para lanzar dados \n\n";
        rlutil::anykey();
        MostrarDados(Lanzar, 2);

        if (acu1 == acu2)
        {
            if (max1 > max2)
            {
                turno = 0;
                cout << "\nCOMIENZA: " << Vnombre[turno] << endl;
                flag = true;
            }
            else if (max2 > max1)
            {
                turno = 1;
                cout << "\nCOMIENZA: " << Vnombre[turno] << endl;
                flag = true;
            }
            else
            {
                cout << endl;
                cout << "Empate, Se repite el lanzamiento: \n"
                     << endl;
            }
        }
        else if (acu1 > acu2)
        {
            turno = 0;
            cout << "\nCOMIENZA: " << Vnombre[turno] << endl;
            flag = true;
        }
        else
        {
            turno = 1;
            cout << "\nCOMIENZA: " << Vnombre[turno] << endl;
            flag = true;
        }
        rlutil::locate(1, 28);
        cout << "Pulse cualquier tecla para continuar";
        rlutil::anykey();
        rlutil::cls();
    }
    return turno;
}

/**
 * @brief Cuenta Unos en Jugada Actual
 *
 * @param vec Vector de lanzamiento
 * @param cant cantidad de dados / dimension del vec[ ]
 * @return int contador con cantidad de 'unos' hallados
 */
int ContarUnos(int vec[], int cant)
{
    int c_unos = 0;
    for (int i = 0; i < cant; i++)
        if (vec[i] == 1)
            c_unos++;
    return c_unos;
}

/**
 * @brief Buscar Oink en la jugada actual
 *
 * @param vec vector de lanzamientos
 * @param Cant Cantidad de dados / dimension del vec[ ]
 * @return true / false
 */
bool Hay_Oink(int vec[], int cant)
{
    bool hay_Oink = false;
    int contador = 0;
    for (int i = 0; i < cant - 1; i++)
        if (vec[i] == vec[i + 1])
            contador++; /*(Cuento los dados iguales)*/
    if (contador == cant - 1)
        hay_Oink = true;

    return hay_Oink;
}

// Calcular Maxima cant. de Lanzamientos para c/jugador y los almacena en Player
/**
 * @brief
 *
 * @param Lanza
 * @param Player
 */
void MaximosLanzamientos(int Lanza[][RONDAS], int Player[][HITOS])
{

    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < RONDAS; j++)
        {
            if (i == 0)
            {
                if (Lanza[i][j] > Player[i][2])
                    Player[i][2] = Lanza[i][j];
            }
            else
            {
                if (Lanza[i][j] > Player[i][2])
                    Player[i][2] = Lanza[i][j];
            }
        }
    }
}

void Cerditos()
{
    const int ancho_terminal = 120;
    rlutil::setBackgroundColor(rlutil::BLACK);
    rlutil::setColor(rlutil::GREEN);
    rlutil::cls();
    rlutil::hidecursor();

    GranCerdo();
    DibujarCuadrado(49, 8, 22, 5);
    rlutil::locate(51, 10);
    cout << "EQUIPO MEESEEKS CPP";

    rlutil::locate(47, 18);
    cout << "JONATHAN WILDEMER Leg.26839";
    rlutil::locate(47, 20);
    cout << "JOAQUIN JUFRIDA Leg.26917";
    DibujarCuadrado(43, 16, 34, 7);

    for (int i = 1; i <= ancho_terminal; i++)
    {
        rlutil::locate(i, 28);
        cout << "-";
    }
    rlutil::anykey();
}

/**
 * @brief Menú principal del juego
 *
 * @param opcion Número de la opción a elegir
 */
void Menu(int &opcion)
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

    opcion = y + 1;
}

#endif