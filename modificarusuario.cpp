//---------------------------------------------------------------------------

#include <vcl.h>
#include "funciones.h"
#pragma hdrstop

#include "modificarusuario.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TFmusuario *Fmusuario;
//---------------------------------------------------------------------------
__fastcall TFmusuario::TFmusuario(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TFmusuario::Button1Click(TObject *Sender)
{
        //susuario unusuario;
        vector<susuario> usuarios;
        usuarios=leer<susuario>(dir_usuario.c_str());
        bool existe=false;
        for(unsigned int i=0;i<usuarios.size();i++){
                if(0==strcmp(mayuscula(usuarios[i].usuario),mayuscula(Eusuario->Text.c_str()))){
                        
                        if((Epassword1->Text==Epassword2->Text)&&(
                        (0==strcmp(usuario.password,encriptar(Eoldpassword->Text.c_str())))||
                        (0==strcmp(usuario.password,Eoldpassword->Text.c_str())))
                         && (Epassword1->Text!="")){
                                strcpy(usuarios[i].usuario,Eusuario->Text.c_str());
                                strcpy(usuarios[i].password,encriptar(Epassword1->Text.c_str()));
                                usuarios[i].admin=CBadmin->Checked;
                                existe=true;
                                ofstream archivo(dir_usuario.c_str(),ios::binary|ios::trunc);
                                for(int i=0;i<(int)usuarios.size();i++){
                                        archivo.write((char*) &usuarios[i],sizeof(usuario));
                                }
                        }
                        break;
                }
        }
        if(!existe){
                ShowMessage("Nombre de usuario o contraseņa incorrecta");
        }else{
                ShowMessage("Usuario modificado correctamente");
                limpiar(Eusuario);
                limpiar(Eoldpassword);
                limpiar(Epassword1);
                limpiar(Epassword2);
                CBadmin->Checked=false;
            }
}
//---------------------------------------------------------------------------

void __fastcall TFmusuario::FormKeyPress(TObject *Sender, char &Key)
{
        if(Key==VK_ESCAPE){
                this->Close();
        }        
}
//---------------------------------------------------------------------------

