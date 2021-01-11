//---------------------------------------------------------------------------

#ifndef modificarusuarioH
#define modificarusuarioH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
//---------------------------------------------------------------------------
class TFmusuario : public TForm
{
__published:	// IDE-managed Components
        TCheckBox *CBadmin;
        TButton *Button1;
        TEdit *Epassword2;
        TLabel *Label3;
        TLabel *Label2;
        TEdit *Epassword1;
        TLabel *Label1;
        TEdit *Eusuario;
        TLabel *Label4;
        TEdit *Eoldpassword;
        void __fastcall Button1Click(TObject *Sender);
        void __fastcall FormKeyPress(TObject *Sender, char &Key);
private:	// User declarations
public:		// User declarations
        __fastcall TFmusuario(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TFmusuario *Fmusuario;
//---------------------------------------------------------------------------
#endif
