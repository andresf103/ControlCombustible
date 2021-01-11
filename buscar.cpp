//---------------------------------------------------------------------------

#include <vcl.h>
#include "funciones.h"
#pragma hdrstop

#include "buscar.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TFbuscar *Fbuscar;
//---------------------------------------------------------------------------
__fastcall TFbuscar::TFbuscar(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TFbuscar::Button1Click(TObject *Sender)
{
/* Buscar informacion dentro de los vehiculos cargados */
    std::string cadena=Edit1->Text.c_str();
    vector<svehiculo> lista=listaVehiculos(cadena);
    int contador=1;
    StringGrid1->CleanupInstance();
    StringGrid1->RowCount = 0;
    StringGrid1->Cells[0][0] = "Patente";
    StringGrid1->Cells[1][0] = "Descripcion";
    StringGrid1->RowCount =(int)lista.size()+1;
    if(0<(int)lista.size()){
    for(int i = 0; i <= (int)lista.size(); i++){
        StringGrid1->Cells[0][i+1] = lista[i].patente;
        StringGrid1->Cells[1][i+1] = lista[i].vehiculo;
        contador++;
        }
    }
    auto_sizing(StringGrid1);
}
//---------------------------------------------------------------------------

void __fastcall TFbuscar::Edit1KeyPress(TObject *Sender, char &Key)
{
if (Key == VK_RETURN)
        {
        Button1Click(Sender);                                
}
}
//---------------------------------------------------------------------------
void __fastcall TFbuscar::FormKeyPress(TObject *Sender, char &Key)
{
        if (Key == VK_RETURN)
        {                                     //VK_RETURN ES EL ENTER QUE COSA DE LOCOS
                Perform(WM_NEXTDLGCTL, 0, 0); //Con esto el enter actua como el tab.
        }
                if(Key==VK_ESCAPE){
                this->Close();
        }
}
//---------------------------------------------------------------------------

void __fastcall TFbuscar::FormCreate(TObject *Sender)
{
  Button1Click(Sender);
}
//---------------------------------------------------------------------------

