//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "modificarchofer.h"
#include "funciones.h"
#include "principal.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TFmodificarchofer *Fmodificarchofer;
//---------------------------------------------------------------------------
__fastcall TFmodificarchofer::TFmodificarchofer(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------

int fila;
void __fastcall TFmodificarchofer::FormCreate(TObject *Sender)
{
        vector<schofer> chofer;
        chofer=leer<schofer>(dir_chofer.c_str());
        StringGrid1->Cells[0][0]="Nombre";
        StringGrid1->Cells[1][0]="Asignado";
        for(int i=0;i<=(int)chofer.size();i++){
                StringGrid1->Cells[0][i+1]=chofer[i].chofer ;
                StringGrid1->Cells[1][i+1]=chofer[i].id_vehiculo;
                StringGrid1->RowCount=i+1;

        }
}
//---------------------------------------------------------------------------


void __fastcall TFmodificarchofer::modificarClick(TObject *Sender)
{
//vector<schofer> chofer;
schofer unchofer;
ofstream archivo(dir_chofer.c_str(),ios::binary|ios::trunc);
  for(int i=1;i<(int)StringGrid1->RowCount;i++){
        if(i==fila){
           StringGrid1->Cells[0][i]=Edit1->Text;
           StringGrid1->Cells[1][i]=Edit2->Text;
        }
   strcpy(unchofer.chofer,StringGrid1->Cells[0][i].c_str());
   strcpy(unchofer.id_vehiculo,StringGrid1->Cells[1][i].c_str());
   unchofer.id=i;
   archivo.write((char*) &unchofer,sizeof(unchofer));
   }
archivo.close();
}
//---------------------------------------------------------------------------

void __fastcall TFmodificarchofer::eliminarClick(TObject *Sender)
{
vector<schofer> chofer;
schofer unchofer;
ofstream archivo(dir_chofer.c_str(),ios::binary|ios::trunc);
  for(int i=1;i<(int)StringGrid1->RowCount;i++){
     unchofer.id=i;
        if(i!=fila){
   strcpy(unchofer.chofer,StringGrid1->Cells[0][i].c_str());
   strcpy(unchofer.id_vehiculo,StringGrid1->Cells[1][i].c_str());
   archivo.write((char*) &unchofer,sizeof(unchofer));
        }
   }
archivo.close();
FormCreate(Sender);
Fprincipal->FormCreate(Sender);
}
//---------------------------------------------------------------------------

void __fastcall TFmodificarchofer::StringGrid1DrawCell(TObject *Sender,
      int ACol, int ARow, TRect &Rect, TGridDrawState State)
{
fila=ARow;
Edit1->Text=StringGrid1->Cells[0][ARow];
Edit2->Text=StringGrid1->Cells[1][ARow];
}
//---------------------------------------------------------------------------

void __fastcall TFmodificarchofer::FormKeyPress(TObject *Sender, char &Key)
{
        if(Key==VK_ESCAPE){
                this->Close();
        }        
}
//---------------------------------------------------------------------------

