#include <iostream>
using namespace std;
#include <cstdlib> //Librerias para funcion srand
#include <ctime>

int sortear_entre(int min, int max)
{
    return min + (rand() % (max - min));
}

int main()
{
    int VNROS[100]={},n;
    int primero,segundo,sin_vender=100;
    float total=0,recaudacion=0;
    bool gano1=false,gano2=false;
    

    //Ingreso de nros Comprados:
    cout << "Ingrese nro comprado: " << endl;
    cin >> n;
    while (n!=-1)
    {   
        if (VNROS[n]==0)
        {
            VNROS[n]=1;
            recaudacion+=500;
            sin_vender--;
        }
        else
        {
            cout<<"Numero comprado, elija otro."<<endl<<endl;
        }
        cout<<"Ingrese nro comprado: "<<endl;
        cin>>n;
    }
    
    /// SORTEO
    srand((unsigned)time(0));
    do
    {
        primero=sortear_entre(0,99);
        segundo=sortear_entre(0,99);
    } while (primero==segundo);
    /// Fin Sorteo

    //A
    cout<<"Total recaudado en conc. de compra de numeros: $"<<recaudacion<<endl;
    
    //C
    cout<<"Porcentaje de numeros no vendidos: "<<sin_vender<<"%"<<endl;
    
    //D
    cout<<"Nro Ganador del 1ER PREMIO: "<<primero<<endl;
    cout<<"Nro Ganador del 2DO PREMIO: "<<segundo<<endl;

    if (VNROS[primero]==1)
    {   
        gano1=true;
        cout<<"El nro ganador del 1er premio fue vendido"<<endl;
    }
    else
    {
        cout<<"El nro ganador del 1er premio no fue vendido"<<endl;
    }
    
    if (VNROS[segundo]==1)
    {   
        gano2=true;
        cout<<"El nro ganador del 2do premio fue vendido"<<endl;
    }
    else
    {
        cout<<"El nro ganador del 2do premio no fue vendido"<<endl;
    }
    
    //B
    total=recaudacion;
    if (gano1==true)
    {
        total=(total-(float)30000);
    }
    
    if (gano2==true)
    {
        total=(total-(float)5000);
    }
    
    if (total>0)
    {
        cout<<"Ganancia del Sr.Lara: $"<<total;
    }
    else
    {
        cout<<"Perdida del Sr.Lara: $"<<total;
    }
    
    return 0;
}