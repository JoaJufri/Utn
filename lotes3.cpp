#include <iostream>
using namespace std;

//Busca el indice correspondiente al parametro, en un vector de dimensión 20
int BuscarIndice(int vec[],int indice) {
    
    for (int i = 0; i < 20; i++)
    {
        if (indice==vec[i])
        {
            return i;
        }
         
    }
    
}

int main()
{   
    //Primer lote
    int NroTarifa,NroCamion;
    float ImporteKm, ImpKM[20]={},KmRecorridos;
    int Tarifas[20]={};

    for (int i = 0; i < 20; i++)
    {
        cin>>NroTarifa;
        Tarifas[i]=NroTarifa;
        cin>>ImporteKm;
        ImpKM[i]= ImporteKm;
    }
    
    float VTotal[100]={};

    int x;
    int CamionMin,KmMin;
    float VAcuTarifas[20]={}, TotalCamion[100]={};
    bool PrimerViaje=false;

    cout<<"Ingrese nro de Camion: "<<endl;
    cin>>NroCamion;

    while (NroCamion>=0)
    {   
        cout<<"Ingrese nro de Tarifa: "<<endl;
        cin>>NroTarifa;
        cout<<"Ingrese KM recorridos: "<<endl;
        cin>>KmRecorridos;
        
        x=BuscarIndice(Tarifas,NroTarifa);
        VAcuTarifas[x]+=KmRecorridos*Tarifas[x]; //total recaudado x c/tarifa
        TotalCamion[NroCamion-1]+=KmRecorridos*ImpKM[x]; //Total recaudado x c/camion

        // Camion que recorrió menos kilometros (entre los que hicieron viajes)
        if (PrimerViaje==false)
        {   
            KmMin=KmRecorridos;
            CamionMin=NroCamion;
            PrimerViaje==true;
        }
        else if (KmRecorridos!=0 && KmRecorridos<KmMin)
        {   
            KmMin=KmRecorridos;
            CamionMin=NroCamion;
        }
        
        cout<<"Ingrese nro de camion: "<<endl;
        cin>>NroCamion;
    }
    



return 0;
}