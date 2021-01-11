//---------------------------------------------------------------------------

#ifndef CargamH
#define CargamH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
//---------------------------------------------------------------------------
class TFcargam : public TForm
{
__published:	// IDE-managed Components
        TComboBox *Epatente;
        TLabel *Label2;
        TLabel *Label1;
        TEdit *Ekilometros;
        TLabel *Label3;
        TComboBox *Echofer;
        TLabel *Label4;
        TComboBox *Edestino;
        TLabel *Label5;
        TEdit *Efecha;
        TLabel *Label6;
        TEdit *Elitros;
        TButton *Btguardar;
        TEdit *Eid;
        TLabel *Label7;
        TButton *Button2;
        TButton *Button3;
        TRadioGroup *RadioGroup1;
        TRadioButton *RadioButton1;
        TRadioButton *RBLubricante;
        TComboBox *Elubricante;
        TLabel *Label8;
        void __fastcall FormCreate(TObject *Sender);
        void __fastcall EidChange(TObject *Sender);
        void __fastcall Button3Click(TObject *Sender);
        void __fastcall Button2Click(TObject *Sender);
        void __fastcall BtguardarClick(TObject *Sender);
        void __fastcall EidKeyPress(TObject *Sender, char &Key);
        void __fastcall RadioButton1Click(TObject *Sender);
        void __fastcall RBLubricanteClick(TObject *Sender);
        void __fastcall FormKeyPress(TObject *Sender, char &Key);
private:	// User declarations
public:		// User declarations
        __fastcall TFcargam(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TFcargam *Fcargam;
//---------------------------------------------------------------------------
#endif
