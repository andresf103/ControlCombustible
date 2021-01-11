//---------------------------------------------------------------------------

#ifndef cargavehiculoH
#define cargavehiculoH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
//---------------------------------------------------------------------------
class TFvehiculos : public TForm
{
__published:	// IDE-managed Components
        TLabel *Ltitulo;
        TLabel *Label1;
        TEdit *Epatente;
        TLabel *Label2;
        TEdit *Edescripcion;
        TButton *Btguardar;
        TLabel *Lconsumo;
        TEdit *Econsumo;
        void __fastcall BtguardarClick(TObject *Sender);
        void __fastcall FormKeyPress(TObject *Sender, char &Key);
        void __fastcall EpatenteChange(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall TFvehiculos(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TFvehiculos *Fvehiculos;
//---------------------------------------------------------------------------
#endif
