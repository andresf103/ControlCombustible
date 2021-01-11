//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Stock.h"
#include "funciones.h"
#include "principal.h"
#include "Login.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TFstock *Fstock;
int fila2;
//---------------------------------------------------------------------------
__fastcall TFstock::TFstock(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TFstock::FormCreate(TObject *Sender)
{
StringGrid1->RowCount=0;
vector <Stock> s;
s.clear();
s=leer<Stock>("stock.dat");

for(int i=0;i<(int)s.size();i++){
        StringGrid1->Cells[0][i]=s[i].get_descripcion();
        StringGrid1->Cells[1][i]=s[i].get_cantstock();
        StringGrid1->RowCount=StringGrid1->RowCount+1;
}
StringGrid1->RowCount=StringGrid1->RowCount-1;
}
//---------------------------------------------------------------------------
/*void __fastcall TFstock::Button1Click(TObject *Sender)
{
        vector <Stock> s;
        s=leer<Stock>("stock.dat");
        int contlabel=0;
        int contedit=0;
        for(int i=0;i<this->ComponentCount;i++){
                        TLabel* label=dynamic_cast<TLabel*>(this->Components[i]);
                        TEdit* edit=dynamic_cast<TEdit*>(this->Components[i]);
                        if(label){
                        s[contlabel].set_descripcion(label->Caption.c_str());
                        contlabel++;
                        }else if(edit){
                              if(edit->Text.IsEmpty()){
                              s[contedit].set_cantstock(0);
                              }else{
                              s[contedit].set_cantstock(edit->Text.ToInt());
                              }
                          contedit++;
                        }
                }
        for (int i=0;i<(int)s.size();i++){
                escribirstock(s[i]);
        }
s.clear();
s=leer<Stock>("stock.dat");
for(int i=0;i<14;i++){
        Fprincipal->StringGrid1->Cells[0][i]=s[i].get_descripcion();
        Fprincipal->StringGrid1->Cells[1][i]=s[i].get_cantstock();
}
Fstock->Close();
}*/
//---------------------------------------------------------------------------

void __fastcall TFstock::modificarClick(TObject *Sender)
{
Stock unstock;
vector <Stock> s;
s.clear();
s=leer<Stock>("stock.dat");

for(int i=0;i<(int)s.size();i++){
        if(i==fila2){
           StringGrid1->Cells[0][i]=Edit1->Text;
           StringGrid1->Cells[1][i]=Edit2->Text;
        }
   unstock.set_descripcion(StringGrid1->Cells[0][i].c_str());
   unstock.set_cantstock(StringGrid1->Cells[1][i].ToDouble());
   escribirstock(unstock);
   }
FormCreate(Sender);
Fprincipal->FormCreate(Sender);

}
//---------------------------------------------------------------------------

void __fastcall TFstock::eliminarClick(TObject *Sender)
{
Stock unstock;
vector <Stock> s;
s.clear();
s=leer<Stock>("stock.dat");
ofstream archivo("stock.dat",ios::binary|ios::trunc);
for(int i=0;i<(int)s.size();i++){
        if(i!=fila2){
   unstock.set_descripcion(StringGrid1->Cells[0][i].c_str());
   unstock.set_cantstock(StringGrid1->Cells[1][i].ToDouble());
   archivo.write((char*) &unstock,sizeof(unstock));
        }
   }
archivo.close();
FormCreate(Sender);
Fprincipal->FormCreate(Sender);
}
//---------------------------------------------------------------------------

void __fastcall TFstock::StringGrid1DrawCell(TObject *Sender, int ACol,
      int ARow, TRect &Rect, TGridDrawState State)
{
fila2=ARow;
Edit1->Text=StringGrid1->Cells[0][ARow];
Edit2->Text=StringGrid1->Cells[1][ARow];
}
//---------------------------------------------------------------------------

void __fastcall TFstock::FormKeyPress(TObject *Sender, char &Key)
{
        if(Key==VK_ESCAPE){
                this->Close();
        }        
}
//---------------------------------------------------------------------------

