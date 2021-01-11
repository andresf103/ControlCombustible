//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "modificarobra.h"
#include "principal.h"
#include "funciones.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TFmobra *Fmobra;
//---------------------------------------------------------------------------
__fastcall TFmobra::TFmobra(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------
int filas;
void __fastcall TFmobra::FormCreate(TObject *Sender)
{
        vector<sobra> obra;
        obra=leer<sobra>(dir_obra.c_str());
        StringGrid1->Cells[0][0]="Obra";
        StringGrid1->Cells[1][0]="Distancia";
        for(int i=0;i<=(int)obra.size();i++){
                StringGrid1->Cells[0][i+1]=obra[i].destino ;
                StringGrid1->Cells[1][i+1]=obra[i].distancia;
                StringGrid1->RowCount=i+1;
        }
}
//---------------------------------------------------------------------------

void __fastcall TFmobra::modificarClick(TObject *Sender)
{
sobra obra;
ofstream archivo(dir_obra.c_str(),ios::binary|ios::trunc);
  for(int i=1;i<(int)StringGrid1->RowCount;i++){
        if(i==filas){
           StringGrid1->Cells[0][i]=Edit1->Text;
           StringGrid1->Cells[1][i]=Edit2->Text;
        }
   strcpy(obra.destino,StringGrid1->Cells[0][i].c_str());
   obra.distancia=StringGrid1->Cells[1][i].ToInt();
   obra.id=i;
   archivo.write((char*) &obra,sizeof(obra));
   }
archivo.close();
}

//---------------------------------------------------------------------------
void __fastcall TFmobra::StringGrid1DrawCell(TObject *Sender, int ACol,
      int ARow, TRect &Rect, TGridDrawState State)
{
filas=ARow;
Edit1->Text=StringGrid1->Cells[0][ARow];
Edit2->Text=StringGrid1->Cells[1][ARow];
}
//---------------------------------------------------------------------------
void __fastcall TFmobra::eliminarClick(TObject *Sender)
{
vector<sobra> obra;
sobra unobra;
ofstream archivo(dir_obra.c_str(),ios::binary|ios::trunc);
  for(int i=1;i<(int)StringGrid1->RowCount;i++){
     unobra.id=i;
        if(i!=filas){
   strcpy(unobra.destino,StringGrid1->Cells[0][i].c_str());
   unobra.distancia=StringGrid1->Cells[1][i].ToInt();
   archivo.write((char*) &unobra,sizeof(unobra));
        }
   }
archivo.close();
FormCreate(Sender);
Fprincipal->FormCreate(Sender);
}
//---------------------------------------------------------------------------
void __fastcall TFmobra::FormKeyPress(TObject *Sender, char &Key)
{
        if(Key==VK_ESCAPE){
                this->Close();
        }        
}
//---------------------------------------------------------------------------

