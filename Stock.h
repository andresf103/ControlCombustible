//---------------------------------------------------------------------------

#ifndef StockH
#define StockH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <Grids.hpp>
//---------------------------------------------------------------------------
class TFstock : public TForm
{
__published:	// IDE-managed Components
        TEdit *Edit1;
        TEdit *Edit2;
        TLabel *Label1;
        TLabel *Label2;
        TButton *eliminar;
        TStringGrid *StringGrid1;
        TButton *modificar;
        void __fastcall FormCreate(TObject *Sender);
        void __fastcall modificarClick(TObject *Sender);
        void __fastcall eliminarClick(TObject *Sender);
        void __fastcall StringGrid1DrawCell(TObject *Sender, int ACol,
          int ARow, TRect &Rect, TGridDrawState State);
        void __fastcall FormKeyPress(TObject *Sender, char &Key);
private:	// User declarations
public:		// User declarations
        __fastcall TFstock(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TFstock *Fstock;
//---------------------------------------------------------------------------
#endif
