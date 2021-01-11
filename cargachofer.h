//---------------------------------------------------------------------------

#ifndef cargachoferH
#define cargachoferH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
//---------------------------------------------------------------------------
class TFchofer : public TForm
{
__published:	// IDE-managed Components
        TLabel *Ltitutlo;
        TEdit *Enombre;
        TLabel *Lnombre;
        TLabel *Lvehiculo;
        TButton *Btguardar;
        TComboBox *Evehiculo;
        void __fastcall BtguardarClick(TObject *Sender);
        void __fastcall FormCreate(TObject *Sender);
        void __fastcall FormKeyPress(TObject *Sender, char &Key);
        void __fastcall EnombreChange(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall TFchofer(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TFchofer *Fchofer;
//---------------------------------------------------------------------------
#endif
