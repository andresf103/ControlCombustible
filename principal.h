//---------------------------------------------------------------------------

#ifndef principalH
#define principalH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <Menus.hpp>
#include <Dialogs.hpp>
#include <ExtCtrls.hpp>
#include <Grids.hpp>
#include <Buttons.hpp>
//---------------------------------------------------------------------------
class TFprincipal : public TForm
{
__published:	// IDE-managed Components
        TMainMenu *MainMenu1;
        TMenuItem *Chofer1;
        TMenuItem *Vehiculo1;
        TMenuItem *Exportar1;
        TMenuItem *Cargas1;
        TMenuItem *vehiculos1;
        TMenuItem *choferes1;
        TSaveDialog *SDarchivo;
        TSaveDialog *SDarchivo2;
        TMenuItem *Importar1;
        TMenuItem *Cargas2;
        TMenuItem *Vehiculos2;
        TMenuItem *Choferes2;
        TMenuItem *Promedio1;
        TMenuItem *Alta1;
        TMenuItem *Modificacion1;
        TMenuItem *Alta2;
        TMenuItem *Modificacion2;
        TMenuItem *Obra1;
        TMenuItem *ss1;
        TMenuItem *modificar1;
        TMenuItem *Usuarios1;
        TMenuItem *Alta3;
        TMenuItem *Baja1;
        TMenuItem *Modificacion3;
        TGroupBox *GroupBox1;
        TStringGrid *StringGrid1;
        TMenuItem *Stock1;
        TMenuItem *Consulta1;
        TLabel *Label1;
        TLabel *Label2;
        TLabel *Label3;
        TLabel *Label4;
        TLabel *Label5;
        TLabel *Label6;
        TLabel *Ltitulo;
        TLabel *Lsugerencia;
        TLabel *Lanterior;
        TLabel *Label7;
        TEdit *Ekilometros;
        TEdit *Efecha;
        TEdit *Elitros;
        TComboBox *Echofer;
        TComboBox *Epatente;
        TComboBox *Edestino;
        TRadioGroup *RadioGroup1;
        TRadioButton *RBCombustible;
        TRadioButton *RBLubricante;
        TComboBox *Elubricante;
        TLabel *Lusuario;
        TLabel *Label8;
        TMenuItem *Alta4;
        TMenuItem *Modificar2;
        TLabel *Label9;
        TButton *Btguardar;
        TSpeedButton *SpeedButton1;
        void __fastcall FormCreate(TObject *Sender);
        void __fastcall FormKeyPress(TObject *Sender, char &Key);
        void __fastcall Cargas1Click(TObject *Sender);
        void __fastcall vehiculos1Click(TObject *Sender);
        void __fastcall choferes1Click(TObject *Sender);
        void __fastcall Cargas2Click(TObject *Sender);
        void __fastcall EdestinoChange(TObject *Sender);
        void __fastcall EkilometrosKeyPress(TObject *Sender, char &Key);
        void __fastcall EfechaKeyPress(TObject *Sender, char &Key);
        void __fastcall EpatenteKeyPress(TObject *Sender, char &Key);
        void __fastcall Promedio1Click(TObject *Sender);
        void __fastcall EpatenteChange(TObject *Sender);
        void __fastcall Alta1Click(TObject *Sender);
        void __fastcall Alta2Click(TObject *Sender);
        void __fastcall Modificacion1Click(TObject *Sender);
        void __fastcall Modificacion2Click(TObject *Sender);
        void __fastcall modificar1Click(TObject *Sender);
        void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
        void __fastcall Alta3Click(TObject *Sender);
        void __fastcall Modificacion3Click(TObject *Sender);
        void __fastcall RBLubricanteClick(TObject *Sender);
        void __fastcall RBCombustibleClick(TObject *Sender);
        void __fastcall Vehiculos2Click(TObject *Sender);
        void __fastcall Stock1Click(TObject *Sender);
        void __fastcall Consulta1Click(TObject *Sender);
        void __fastcall Alta4Click(TObject *Sender);
        void __fastcall Modificar2Click(TObject *Sender);
        void __fastcall BtguardarClick(TObject *Sender);
        void __fastcall SpeedButton1Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall TFprincipal(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TFprincipal *Fprincipal;
//---------------------------------------------------------------------------
#endif
