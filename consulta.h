//---------------------------------------------------------------------------

#ifndef consultaH
#define consultaH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <Grids.hpp>
#include <ExtCtrls.hpp>
//---------------------------------------------------------------------------
class TFConsulta : public TForm
{
__published:	// IDE-managed Components
        TLabel *Label1;
        TLabel *Label2;
        TLabel *Label3;
        TLabel *Label4;
        TComboBox *CBfecha;
        TComboBox *CBobra;
        TComboBox *CBvehiculo;
        TComboBox *CBchofer;
        TStringGrid *StringGrid1;
        TLabel *Lblitros;
        TComboBox *CBfecha2;
        TLabel *Label5;
        TLabel *Label6;
        TRadioGroup *RadioGroup1;
        TRadioButton *CBgasoil;
        TRadioButton *CBotros;
        void __fastcall FormCreate(TObject *Sender);
        void __fastcall CBotrosClick(TObject *Sender);
        void __fastcall CBgasoilClick(TObject *Sender);
        void __fastcall CBfechaExit(TObject *Sender);
        void __fastcall CBfecha2Exit(TObject *Sender);
        void __fastcall FormKeyPress(TObject *Sender, char &Key);
        void __fastcall CBobraExit(TObject *Sender);
        void __fastcall CBvehiculoExit(TObject *Sender);
        void __fastcall CBchoferExit(TObject *Sender);
        void __fastcall CBfechaKeyPress(TObject *Sender, char &Key);
        void __fastcall CBfecha2KeyPress(TObject *Sender, char &Key);
private:	// User declarations
public:		// User declarations
        __fastcall TFConsulta(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TFConsulta *FConsulta;
//---------------------------------------------------------------------------
#endif
