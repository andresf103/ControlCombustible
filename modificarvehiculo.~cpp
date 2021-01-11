//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "modificarvehiculo.h"
#include "principal.h"
#include "funciones.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TFmvehiculo *Fmvehiculo;
//---------------------------------------------------------------------------
__fastcall TFmvehiculo::TFmvehiculo(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TFmvehiculo::FormShow(TObject *Sender)
{
Epatente->Items=Fprincipal->Epatente->Items;

}
//---------------------------------------------------------------------------
void __fastcall TFmvehiculo::BeliminarClick(TObject *Sender)
{
        svehiculo eliminar;

        strcpy(eliminar.patente,Epatente->Text.c_str());
        eliminar_vehiculo(eliminar);
        vector<svehiculo> unvehiculo;
        unvehiculo=leer<svehiculo>(dir_vehiculo.c_str());
        Epatente->Items->Clear();
        for(int i=0;i<(int)unvehiculo.size();i++){
                Epatente->Items->Add(unvehiculo[i].patente);
        }
        Epatente->ItemIndex=0;
        EpatenteChange(Sender);
        Fprincipal->Epatente->Items=Epatente->Items;
}
//---------------------------------------------------------------------------
void __fastcall TFmvehiculo::BmodificarClick(TObject *Sender)
{
        svehiculo modificado;

        strcpy(modificado.patente,Epatente->Text.c_str());
        strcpy(modificado.vehiculo,Edescripcion->Text.c_str());
        modificado.consumo=Econsumo->Text.ToInt();
        modificar(modificado,dir_vehiculo.c_str());
}
//---------------------------------------------------------------------------
void __fastcall TFmvehiculo::EpatenteChange(TObject *Sender)
{
svehiculo vehiculo=datosvehiculo(Epatente->Text.c_str());
    Edescripcion->Text=vehiculo.vehiculo;
    Econsumo->Text=vehiculo.consumo;
}
//---------------------------------------------------------------------------

void __fastcall TFmvehiculo::FormKeyPress(TObject *Sender, char &Key)
{
        if(Key==VK_ESCAPE){
                this->Close();
        }        
}
//---------------------------------------------------------------------------

