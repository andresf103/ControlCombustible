//---------------------------------------------------------------------------

#ifndef modificarobraH
#define modificarobraH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <Grids.hpp>
//---------------------------------------------------------------------------
class TFmobra : public TForm
{
__published:	// IDE-managed Components
        TStringGrid *StringGrid1;
        TButton *modificar;
        TButton *eliminar;
        TEdit *Edit1;
        TEdit *Edit2;
        void __fastcall FormCreate(TObject *Sender);
        void __fastcall modificarClick(TObject *Sender);
        void __fastcall StringGrid1DrawCell(TObject *Sender, int ACol,
          int ARow, TRect &Rect, TGridDrawState State);
        void __fastcall eliminarClick(TObject *Sender);
        void __fastcall FormKeyPress(TObject *Sender, char &Key);
private:	// User declarations
public:		// User declarations
        __fastcall TFmobra(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TFmobra *Fmobra;
//---------------------------------------------------------------------------
#endif
