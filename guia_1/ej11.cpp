#include <iostream>
using namespace std;
int main()
{  // CORREJIR, ESTA MAL 
   int min;
   int D;
   int H;
   int aux;

   cout << "ingrese cantidad de minutos: ";
   cin >> min;

   aux = min % 1440;
   min = min - aux;
   D = min / 1440;
   min = aux % 60;
   H = (aux - min) / 60;

   cout << D << " dias, " << H << " horas y " << min << " minutos";
    
    return 0;
}
