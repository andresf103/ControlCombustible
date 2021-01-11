//---------------------------------------------------------------------------

#ifndef imprimirH
#define imprimirH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include <QRCtrls.hpp>
#include <QuickRpt.hpp>
#include <Graphics.hpp>
#include <jpeg.hpp>
#include <Buttons.hpp>
//---------------------------------------------------------------------------
class TFprint : public TForm
{
__published:	// IDE-managed Components
        TQuickRep *QuickRep1;
        TQRBand *QRtitulo;
        TQRLabel *QRlitros;
        TQRLabel *QRpatente;
        TQRLabel *QRdestino;
        TQRLabel *QRchofer;
        TQRLabel *QRvale;
        TQRLabel *QRFecha;
        TQRLabel *QRkilometros;
        TQRImage *QRImage1;
        TQRLabel *QRGasoil;
        TQRLabel *QRLabel8;
        TQRLabel *QRmarca;
        TQRLabel *QRLabel10;
        TQRLabel *QRLetra;
        TQRLabel *QRLabel2;
        TQRLabel *QRLabel3;
        TQRLabel *QRobservacion;
        TButton *Btprint;
        TBitBtn *BitBtn1;
        void __fastcall QuickRep1AfterPrint(TObject *Sender);
        void __fastcall BtprintClick(TObject *Sender);
        void __fastcall BitBtn1Click(TObject *Sender);
        void __fastcall FormKeyPress(TObject *Sender, char &Key);
private:	// User declarations
public:		// User declarations
        __fastcall TFprint(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TFprint *Fprint;
//---------------------------------------------------------------------------
#endif
