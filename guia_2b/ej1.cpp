#include <iostream>
using namespace std;
#include <stdlib.h>

int main()
{
    int hs=0;
    char lenguaje;
    bool urgente=0;
    float total=0;

    cout << "Ingrese tipo de lenguaje: "<<endl;
    cin >> lenguaje;
    cout << "Ingrese cantidad de horas: "<<endl;
    cin >> hs;
    cout << "Es urgente? (1 para si / 0 para no) :"<<endl;
    cin >> urgente;

    switch (lenguaje)
    {
    case 'C':
        total = 2500 * hs;
        break;

    case '#':    
        total = 2100 * hs;
        break;

    case 'P': 
        total= 1400 * hs;
        break; 

    case 'G':
        total = 2000 * hs;
        break;          
    }

    if (urgente==1)
    {
        total = total * 2.20;
    }

    cout << "El costo total del proyecto es de: " <<total;
    

    return 0;
}

/*Le solicitan un programa que permita calcular 
el costo total de un proyecto basado en la cantidad de horas (int), 
el tipo de lenguaje (char) y si es urgente o no (bool).
Si es urgente se le agrega un 120% mas al total del proyecto*/
