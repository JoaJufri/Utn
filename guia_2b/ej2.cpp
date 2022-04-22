#include <iostream>
using namespace std;
#include <stdlib.h>

int main()
{
    int e1,e2,e3,e4,e5;
    float h1,h2,h3,h4,h5;
    int htotal=0;
    int cant=0;
    float prom=0;
    int n=0;
    int hn=0;

    cout << "Ingrese edad: " <<endl;
    cin >> e1;
    cout << "Ingrese altura: " <<endl;
    cin >> h1;
    cout << "Ingrese edad: " <<endl;
    cin >> e2;
    cout << "Ingrese altura: " <<endl;
    cin >> h2;
    cout << "Ingrese edad: " <<endl;
    cin >> e3;
    cout << "Ingrese altura: " <<endl;
    cin >> h3;
    cout << "Ingrese edad: " <<endl;
    cin >> e4;
    cout << "Ingrese altura: " <<endl;
    cin >> h4;
    cout << "Ingrese edad: " <<endl;
    cin >> e5;
    cout << "Ingrese altura: " <<endl;
    cin >> h5;

    if (e1==20 || e1==30 || e1==40)
    {
        cant = cant+1;                      /*Cant de personas que tienen 20,30 o 40 años*/
    }
    else if (e1>30)
    {   
        prom = prom+h1;
        n = n+1;                          /* prom= prom / n   , promedio de altura de las personas mayores de 30 años*/
        if (h1>1.8)
        {
            htotal = htotal+1;              /*cant de personas q miden + de 1.80*/
        }
        
        
    }
    
    if (h1>=1.70 && h1<=1.80)              /*Cantidad de personas con altura entre 1.70 y 1.80 inclusive*/
    {
        hn = hn + 1;
    }

    if (e2==20 || e2==30 || e2==40)
    {
        cant = cant+1;                      
    }
    else if (e2>30)
    {   
        prom = prom+h2;
        n = n+1;                          
        if (h2>1.8)
        {
            htotal = htotal+1;              
        }
        
        
    }
    
    if (h2>=1.70 && h2<=1.80)              
    {
        hn = hn + 1;
    }
    
    if (e3==20 || e3==30 || e3==40)
    {
        cant = cant+1;                      
    }
    else if (e3>30)
    {   
        prom = prom+h3;
        n = n+1;                          
        if (h3>1.8)
        {
            htotal = htotal+1;              
        }
        
        
    }
    
    if (h3>=1.70 && h3<=1.80)              
    {
        hn = hn + 1;
    }

    if (e4==20 || e4==30 || e4==40)
    {
        cant = cant+1;                     
    }
    else if (e4>30)
    {   
        prom = prom+h4;
        n = n+1;                         
        if (h4>1.8)
        {
            htotal = htotal+1;             
        }
        
        
    }
    
    if (h4>=1.70 && h4<=1.80)             
    {
        hn = hn + 1;
    }

    if (e5==20 || e5==30 || e5==40)
    {
        cant = cant+1;                      
    }
    else if (e5>30)
    {   
        prom = prom+h5;
        n = n+1;                         
        if (h5>1.8)
        {
            htotal = htotal+1;              
        }
        
        
    }
    
    if (h5>=1.70 && h5<=1.80)              
    {
        hn = hn + 1;
    }
    
    prom = prom/n;

    cout << "Las personas mayores a 30, que miden mas de 1.80 son: "<< htotal <<endl;
    cout << "El promedio de altura de las personas mayores a 30 es: " <<prom <<endl;
    cout << "La cant. de personas con altura entre 1.70 y 1.80 inclusive es: " << hn <<endl;
    cout << "La cantidad de personas cuya edad es 20,30 o 40 es: " <<cant;

    
    return 0;
}


/*Hacer un programa en el que se ingresen la edad y altura de 5 personas. Luego, calcular e informar:
La cantidad de personas mayores a 30 años que midan más de 1.8 metros.
El promedio de altura de las personas mayores a 30 años.
La cantidad de personas con altura entre 1.7 y 1.8 (ambos inclusive)
La cantidad de personas cuya edad sea de 20, 30 o 40 años.
*/