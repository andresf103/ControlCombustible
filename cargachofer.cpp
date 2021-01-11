//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "cargachofer.h"
#include "principal.h"
#include "funciones.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TFchofer *Fchofer;
//---------------------------------------------------------------------------
__fastcall TFchofer::TFchofer(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TFchofer::BtguardarClick(TObject *Sender)
{
        schofer unchofer;
        strcpy(unchofer.chofer,Enombre->Text.c_str());
        strcpy(unchofer.id_vehiculo,Evehiculo->Text.c_str());
        //int contador;
        /*contador=*/escribir(unchofer,dir_chofer.c_str());
        //ShowMessage(contador);
        vector<schofer> chofer;
        chofer=leer<schofer>(dir_chofer.c_str());
        Fprincipal->Echofer->Items->Clear();
        for(int i=0;i<(int)chofer.size();i++){
                Fprincipal->Echofer->Items->Add(chofer[i].chofer);
        }
        AnsiString aux;
        aux=Enombre->Text;
        limpiar(Enombre);
        Fprincipal->Echofer->Text=aux;
        Evehiculo->ItemIndex=-1;
        this->Close();
}
//---------------------------------------------------------------------------

void __fastcall TFchofer::FormCreate(TObject *Sender)
{
        //Le ponemos datos al combobox EVEHICULO
        vector<svehiculo> unvehiculo;
        unvehiculo=leer<svehiculo>(dir_vehiculo.c_str());
        for(int i=0;i<(int)unvehiculo.size();i++){
                Evehiculo->Items->Add(unvehiculo[i].patente);
        }
        //FIN Le ponemos datos al combobox EVEHICULO
}
//---------------------------------------------------------------------------

void __fastcall TFchofer::FormKeyPress(TObject *Sender, char &Key)
{
        if(Key==VK_ESCAPE){
                this->Close();
        }
}
//---------------------------------------------------------------------------

void __fastcall TFchofer::EnombreChange(TObject *Sender)
{
Fprincipal->Echofer->Text=Enombre->Text;
}
//---------------------------------------------------------------------------

