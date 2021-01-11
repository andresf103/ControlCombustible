//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "cargavehiculo.h"
#include "funciones.h"
#include "principal.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TFvehiculos *Fvehiculos;
//---------------------------------------------------------------------------
__fastcall TFvehiculos::TFvehiculos(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TFvehiculos::BtguardarClick(TObject *Sender)
{       svehiculo unvehiculo;
        strcpy(unvehiculo.patente,Epatente->Text.c_str());
        strcpy(unvehiculo.vehiculo,Edescripcion->Text.c_str());
        unvehiculo.consumo=Econsumo->Text.ToInt();
        //int cantidad;
        /*cantidad=*/escribir(unvehiculo,dir_vehiculo.c_str());
        //ShowMessage(cantidad);

        vector<svehiculo> vehiculo;
        vehiculo=leer<svehiculo>(dir_vehiculo.c_str());
        Fprincipal->Epatente->Items->Clear();
        for(int i=0;i<(int)vehiculo.size();i++){
                Fprincipal->Epatente->Items->Add(vehiculo[i].patente);
        }
        String aux=Epatente->Text;
        limpiar(Epatente);
        limpiar(Edescripcion);
        this->Close();
        Fprincipal->Epatente->Text=aux;
}
//---------------------------------------------------------------------------


void __fastcall TFvehiculos::FormKeyPress(TObject *Sender, char &Key)
{
        if(Key==VK_ESCAPE){
        this->Close();
        }
}
//---------------------------------------------------------------------------

void __fastcall TFvehiculos::EpatenteChange(TObject *Sender)
{
Fprincipal->Epatente->Text=Epatente->Text;
}
//---------------------------------------------------------------------------

