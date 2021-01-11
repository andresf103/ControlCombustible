//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "usuarios.h"
#include "principal.h"
#include "funciones.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TFusuario *Fusuario;
//---------------------------------------------------------------------------
__fastcall TFusuario::TFusuario(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TFusuario::Button1Click(TObject *Sender)
{       susuario unusuario;
        vector<susuario> usuarios;
        usuarios=leer<susuario>(dir_usuario.c_str());
        bool existe=false;
        for(unsigned int i=0;i<usuarios.size();i++){
                if(0==strcmp(usuarios[i].usuario,Eusuario->Text.c_str())){
                        existe=true;
                        break;
                }
        }
        if(existe){
                ShowMessage("el nombre de usuario ya existe");
        }else{
                if(Eusuario->Text.Length()>3)
            if((Epassword1->Text==Epassword2->Text) && (Epassword1->Text!="")){
                unusuario.id=usuarios.size()+1;
                strcpy(unusuario.usuario,Eusuario->Text.c_str());
                strcpy(unusuario.password,Epassword1->Text.c_str());
                unusuario.admin=CBadmin->Checked;
                escribir<susuario>(unusuario,dir_usuario.c_str());
                ShowMessage("Usuario registrado correctamente");
                limpiar(Eusuario);
                limpiar(Epassword1);
                limpiar(Epassword2);
                CBadmin->Checked=false;
            }

        }

}



//---------------------------------------------------------------------------
