//---------------------------------------------------------------------------

#ifndef modificarvehiculoH
#define modificarvehiculoH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
//---------------------------------------------------------------------------
class TFmvehiculo : public TForm
{
__published:	// IDE-managed Components
        TComboBox *Epatente;
        TLabel *Label2;
        TLabel *Label1;
        TEdit *Edescripcion;
        TLabel *Lconsumo;
        TEdit *Econsumo;
        TButton *Bmodificar;
        TButton *Beliminar;
        TLabel *Ltitulo;
        void __fastcall FormShow(TObject *Sender);
        void __fastcall BeliminarClick(TObject *Sender);
        void __fastcall BmodificarClick(TObject *Sender);
        void __fastcall EpatenteChange(TObject *Sender);
        void __fastcall FormKeyPress(TObject *Sender, char &Key);
private:	// User declarations
public:		// User declarations
        __fastcall TFmvehiculo(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TFmvehiculo *Fmvehiculo;
//---------------------------------------------------------------------------
#endif
