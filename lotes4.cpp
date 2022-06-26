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
    int VCodigos[30]={},PiezasRotasMes[31]={};
    int NroCamion,CodigoChofer,Dia,KmRecorridos,PiezasRotas,MinPiezas[31]={},MinChofer;

    bool PrimerIngreso=true;

    for (int i = 0; i < 30; i++)
    {
        cout<<"Ingrese Codigo de chofer para el camion # "<<i+1<<" : "<<endl;
        cin>>CodigoChofer;
        VCodigos[i]=CodigoChofer;
    }
    
    cout<<"Ingrese Día del viaje: "<<endl;
    cin>>Dia;

    while (Dia!=0)
    {
        cout<<"Ingrese Codigo de chofer: "<<endl;
        cin>>CodigoChofer;
        cout<<"Ingrese KM recorridos: "<<endl;
        cin>>KmRecorridos;
        cout<<"Ingrese Cant. de piezas rotas: "<<endl;
        cin>>PiezasRotas;


        cout<<"Ingrese Día del viaje: "<<endl;
        cin>>Dia;
    }
    


    return 0;
}