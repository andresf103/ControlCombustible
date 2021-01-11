//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "cargaobra.h"
#include "funciones.h"
#include "principal.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TFobras *Fobras;
//---------------------------------------------------------------------------
__fastcall TFobras::TFobras(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TFobras::BtguardarClick(TObject *Sender)
{
sobra unobra;
        strcpy(unobra.destino,Edestino->Text.c_str());
        unobra.distancia=Edistancia->Text.ToInt();
        /*int cantidad;
        cantidad=*/escribir(unobra,dir_obra.c_str());
        //ShowMessage(cantidad);

        vector<sobra> obra;
        obra=leer<sobra>(dir_obra.c_str());
        Fprincipal->Edestino->Items->Clear();
        for(int i=0;i<(int)obra.size();i++){
                Fprincipal->Edestino->Items->Add(obra[i].destino);
        }
        AnsiString auxDestino=Edestino->Text.c_str();
        limpiar(Edestino);
        limpiar(Edistancia);
        Fprincipal->Edestino->Text=auxDestino.c_str();
        this->Close();
}
//---------------------------------------------------------------------------

void __fastcall TFobras::FormKeyPress(TObject *Sender, char &Key)
{
        if(Key==VK_ESCAPE){
                this->Close();
        }
}
//---------------------------------------------------------------------------

void __fastcall TFobras::EdestinoChange(TObject *Sender)
{
Fprincipal->Edestino->Text=Edestino->Text;
}
//---------------------------------------------------------------------------

