#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

using namespace std;
#include <stdio.h>
// Func. Random dados x jugador
void TirarDados(int vec[], int dados)
{
    for (int i = 0; i < dados; i++)
    {
        vec[i] = 1 + rand() % 6;
    }
}

// Func. Mostrar dados sorteados
void MostrarDados(int vec[], int c_dados)
{
    string dado[5] = {};

    for (int i = 0; i < 5; i++)
    {
        dado[i] = "     ";
    }

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

    cout << ("Tu jugada: \n") << endl;

    for (int i = 0; i < 5; i++)
    {
        cout << dado[i] << endl;
    }
    cout << "\n";
}

// Func. Sumar dados x jugador
int SumarDados(int vec[], int dados)
{
    int acu = 0;
    for (int i = 0; i < dados; i++)
    {
        acu += vec[i];
    }
    return acu;
}

// Hallar Dado Maximo x jugador
int DadoMax(int vec[], int dados)
{
    int max = 0;
    for (int i = 0; i < dados; i++)
    {
        if (vec[i] > max)
        {
            max = vec[i];
        }
    }
    return max;
}

int stringMasLargo(string vec[], int cant)
{
    int max = 0;
    for (int i = 0; i < cant; i++)
    {
        if (vec[i].length() > max)
        {
            max = vec[i].length();
        }
    }
    return max;
}

void mostrarCartel() {
    string vecTest[5] = {"Hola", "Como", "Estas", "Hoy", "Gil"};
    int largo = stringMasLargo(vecTest, 5);
    int margen = 2;
    for (int i = 0; i<largo+2; i++) {
      
        cout<< margen<<"hola"<<margen;
    }
}


//

//FORMATEAR PARA IMPRIMIR
// JUGADOR 1
// Por cada categoria, tomar el string más largo (OBTIENE EL ANCHO DE CADA COLUMNA)
//laksjdlaksjdlakjsd
//5 PDV (3000000000020 trufas)
//5 PDV (30 trufas)

// Por cada linea, rellenar hasta el string máximo
// Categoria 1
//laksjdlaksjdlakjsd
//"cada 50 trufas   "
//"Oinks            "
//"Cerdo codicioso  "

// Categoria 2
//"6 PDV (300 trufas)    "
//"6 PDV (3 Oinks)       "
//"0 PDV (8 lanzamientos)"




//|    laksjdlaksjdlakjsd    [5 PDV (3000000000020 trufas),"     ", 5 PDV (30 trufas)]    |
//|    asdasdasdasd     ,    [5 PDV (3000000000020 trufas),"     ", 5 PDV (30 trufas)]    |


//MOSTRAR CARTEL
//"mas trufas en total"+=/"                               "+=/"     asdas      "








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

        cout << "Turno de "<<Vnombre[0]<<"\n\n";
        MostrarDados(Lanzar,2);

        TirarDados(Lanzar, 2);
        acu2 = SumarDados(Lanzar, 2);
        max2 = DadoMax(Lanzar, 2);

        cout << "Turno de "<<Vnombre[1]<<"\n\n";
        MostrarDados(Lanzar,2);

        if (acu1 == acu2)
        {
            if (max1 > max2)
            {
                turno = 0;
                cout << "Comienza "<<Vnombre[turno]<< endl;
                flag = true;
            }
            else if (max2 > max1)
            {
                turno = 1;
                cout << "Comienza "<<Vnombre[turno] << endl;
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
            cout << "Comienza "<<Vnombre[turno] << endl;
            flag = true;
        }
        else
        {
            turno = 1;
            cout << "Comienza "<<Vnombre[turno] << endl;
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
    {
        if (vec[i] == 1)
        {
            c_unos++;
        }
    }
    return c_unos;
}

// Func. Hay Oink ?
bool Hay_Oink(int vec[], int cant)
{
    bool hay_Oink = false;
    int contador = 0;
    for (int i = 0; i < cant - 1; i++)
    {
        if (vec[i] == vec[i + 1])
        {
            contador++; /*(Cuento los dados iguales)*/
        }
    }
    if (contador == cant - 1)
    {
        hay_Oink = true;
    }

    return hay_Oink;
}

#endif