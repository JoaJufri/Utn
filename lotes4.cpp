#include <iostream>
using namespace std;

int BuscarIndice (int vec[], int indice,int dimension) {

    for (int i = 0; i < dimension; i++)
    {
        if (indice==vec[i])
        {
            return i;
        }
        
    }
    

}

int main()
{
    int VCodigos[30]={},PiezasRotasDias[31],MinChofer[31],KmChofer[30]={};
    bool BanderaPiezasRotas[31]={};
    int NroCamion,CodigoChofer,Dia,KmRecorridos,PiezasRotas;

    bool PrimerIngreso=true;

    for (int i = 0; i < 30; i++)
    {
        cout<<"Ingrese Codigo de chofer para el camion # "<<i+1<<" : "<<endl;
        cin>>CodigoChofer;
        VCodigos[i]=CodigoChofer;
    }
    
    cout<<"Ingrese Día del viaje: "<<endl;
    cin>>Dia;
    int x;
    while (Dia!=0)
    {
        cout<<"Ingrese Codigo de chofer: "<<endl;
        cin>>CodigoChofer;
        cout<<"Ingrese KM recorridos: "<<endl;
        cin>>KmRecorridos;
        cout<<"Ingrese Cant. de piezas rotas: "<<endl;
        cin>>PiezasRotas;

        
        //1er punto d)Por cada dia, el codigo de chofer con el minimo de piezas rotas
        if (BanderaPiezasRotas[Dia-1]==0 && KmRecorridos!=0)
        {
            PiezasRotasDias[Dia-1] = PiezasRotas;
            MinChofer[Dia-1]=CodigoChofer;
            BanderaPiezasRotas[Dia-1] = 1;
        }
        else
        {
            if (PiezasRotas<PiezasRotasDias[Dia-1] && KmRecorridos!=0)
            {   
                PiezasRotasDias[Dia-1] = PiezasRotas;
                MinChofer[Dia-1]=CodigoChofer;
            }
             
        }
        
        //2do Punto. Informar Nro de camion con mayor cantidad de km recorridos durante el mes.
        x=BuscarIndice(VCodigos,CodigoChofer,30);
        KmChofer[x]+=KmRecorridos;

        cout<<"Ingrese Día del viaje: "<<endl;
        cin>>Dia;
    }
    
    //Punto 1
    cout<<"Código de chofer con la minima cantidad de piezas rotas por dia: "<<endl;
    for (int i = 0; i < 31; i++)
    {
        cout<<"Dia: " <<i+1<<" ,Chofer"<<MinChofer[i]<<" con: "<<PiezasRotasDias[i]<<" Piezas rotas"<<endl;
    }
    

    //Punto 2
    int MaximosKm=0,CamionMax;
    for (int i = 0; i < 30; i++)
    {
        if (KmChofer[i]>MaximosKm)
        {
            MaximosKm=KmChofer[i];
            CamionMax=i+1;
        }
        
    }
    
    cout<<"El nro de Camion que realizo mas km durante el mes fue el # "<<CamionMax<<" Con "<<MaximosKm<<" Km recorridos"<<endl;

    return 0;
}