//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "imprimir.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TFprint *Fprint;
//---------------------------------------------------------------------------
__fastcall TFprint::TFprint(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------



void __fastcall TFprint::QuickRep1AfterPrint(TObject *Sender)
{
//Fprint->Close();
}
//---------------------------------------------------------------------------

void __fastcall TFprint::BtprintClick(TObject *Sender)
{
QuickRep1->Print();
this->Close();
}
//---------------------------------------------------------------------------

void __fastcall TFprint::BitBtn1Click(TObject *Sender)
{
QuickRep1->PrinterSetup();
}
//---------------------------------------------------------------------------

void __fastcall TFprint::FormKeyPress(TObject *Sender, char &Key)
{
        if(Key==VK_ESCAPE){
                this->Close();
        }
}
//---------------------------------------------------------------------------

