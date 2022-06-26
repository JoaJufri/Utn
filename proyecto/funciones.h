#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED
#define HITOS 4

#include <iostream>
using namespace std;
#include <stdio.h>
#include "rlutil.h"
// Func. Random dados x jugador
void TirarDados(int vec[], int dados)
{
    for (int i = 0; i < dados; i++)
        vec[i] = 1 + rand() % 6;
}

// Func. Mostrar dados sorteados
void MostrarDados(int vec[], int c_dados)
{
    string dado[5] = {};

    for (int i = 0; i < 5; i++)
        dado[i] = "     ";

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

// Func. Sumar dados x jugador
int SumarDados(int vec[], int dados)
{
    int acu = 0;
    for (int i = 0; i < dados; i++)
        acu += vec[i];
    return acu;
}

// Hallar Dado Maximo x jugador
int DadoMax(int vec[], int dados)
{
    int max = 0;
    for (int i = 0; i < dados; i++)
        if (vec[i] > max)
            max = vec[i];
    return max;
}

// Prueba Carteles pt1
int stringMasLargo(string vec[], int cant)
{
    int max = 0;
    for (int i = 0; i < cant; i++)
        if (vec[i].length() > max)
            max = vec[i].length();
    return max;
}


/** Cartel de Turnos */
void CartelTurno(int &Ronda, int &Lanzamientos, int &TrufasRonda)
{
    rlutil::locate(7, 8);
    cout << "+--------------------------------+";
    rlutil::locate(7, 9);
    cout << "| Ronda: " << Ronda << endl;
    rlutil::locate(7, 10);
    cout << "| Trufas de la Ronda: " << TrufasRonda << endl;
    rlutil::locate(7, 11);
    cout << "| #Lanzamiento: " << Lanzamientos << endl;
    rlutil::locate(7, 12);
    cout << "+--------------------------------+" << endl;

    int y = 9;
    for (int i = 0; i < 3; i++)
    {
        rlutil::locate(40, y);
        cout << "|";
        y++;
    }
}

// Calcula Puntos De Victoria (update)
//orden matriz player: [trufas_acumuladas][Cant_Oinks] [Max_Lanzamientos] [Cada 50 trufas]
void CalculoPDV(int player[][HITOS], int PDV[][HITOS])
{

    int a = player[0][0];
    int b = player[1][0];

    // Mas Trufas en total
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
    // Cada 50 trufas
    PDV[0][3] = player[0][0] / 50;
    PDV[1][3] = player[1][0] / 50;

}

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



// Func. Sorteo Inicial
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
        MostrarDados(Lanzar, 2);

        TirarDados(Lanzar, 2);
        acu2 = SumarDados(Lanzar, 2);
        max2 = DadoMax(Lanzar, 2);

        cout << "Turno de " << Vnombre[1] << "\n\n";
        MostrarDados(Lanzar, 2);

        if (acu1 == acu2)
        {
            if (max1 > max2)
            {
                turno = 0;
                cout << "Comienza " << Vnombre[turno] << endl;
                flag = true;
            }
            else if (max2 > max1)
            {
                turno = 1;
                cout << "Comienza " << Vnombre[turno] << endl;
                flag = true;
            }
            else
            {
                cout << endl;
                cout << "\n Empate, Se repite el lanzamiento: \n"
                     << endl;
            }
        }
        else if (acu1 > acu2)
        {
            turno = 0;
            cout << "Comienza " << Vnombre[turno] << endl;
            flag = true;
        }
        else
        {
            turno = 1;
            cout << "Comienza " << Vnombre[turno] << endl;
            flag = true;
        }
    }
    return turno;
}

// Func. Contar Unos en jugada.
int ContarUnos(int vec[], int cant)
{
    int c_unos = 0;
    for (int i = 0; i < cant; i++)
        if (vec[i] == 1)
            c_unos++;
    return c_unos;
}

// Func. Hay Oink ?
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

#endif