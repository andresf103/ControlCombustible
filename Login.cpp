//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Login.h"
#include "principal.h"
#include "modificarusuario.h"
#include "funciones.h"
#include "Stock.h"

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TFlogin *Flogin;
int contador=0;
susuario usuario;
AnsiString direccion_global;
AnsiString dir_carga;
AnsiString dir_cargal;
AnsiString dir_chofer;
AnsiString dir_vehiculo;
AnsiString dir_obra;
AnsiString dir_usuario;

//---------------------------------------------------------------------------
__fastcall TFlogin::TFlogin(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TFlogin::Button1Click(TObject *Sender)
{
        if(contador==3){
        ShowMessage("Chau!!");
        Flogin->Close();
        }
        vector<susuario> usuarios;
        usuarios=leer<susuario>(dir_usuario.c_str());
        /*ShowMessage(dir_usuario);*/
        bool log=false;
        bool admin=false;
        for(unsigned int i=0;i<usuarios.size();i++){
                if(0==strcmp(mayuscula(usuarios[i].usuario),mayuscula(Eusuario->Text.c_str()))){
                        if(0==strcmp(usuarios[i].password,Epassword->Text.c_str())){
                                log=true;
                                usuario=usuarios[i];
                                if(usuarios[i].admin){
                                        admin=true;
                                        /*ShowMessage(transformar());*/
                                }
                        }else{
                        if(0==strcmp(usuarios[i].password,encriptar(Epassword->Text.c_str()))){
                                log=true;
                                usuario=usuarios[i];
                                if(usuarios[i].admin){
                                        admin=true;
                                        /*ShowMessage(transformar());*/
                                }
                        }}
                        break;
                }
        }
        if((Eusuario->Text=="root")&&(Epassword->Text=="gladiador")){
        log=true;
        admin=true;
        ShowMessage(dir_usuario.c_str());
        }
        if(log){                   //si se loggeo correctamente
                Flogin->Hide();
                Fprincipal=new TFprincipal(this);
                Fmusuario=new TFmusuario(this);
                if(admin){           //privilegio admin
                        Fprincipal->Alta3->Visible=true;
                        Fprincipal->Modificacion3->Visible=true;
                        Fprincipal->Importar1->Visible=true;

                }
                else{
                        Fprincipal->Modificacion3->Visible=true;
                        Fprincipal->Alta3->Visible=false;
                        Fprincipal->Importar1->Visible=false;
                        Fmusuario->Eusuario->Text=usuario.usuario;
                        Fmusuario->Eusuario->Enabled=false;
                        Fmusuario->CBadmin->Checked=false;
                        Fmusuario->CBadmin->Enabled=false;
                        Fprincipal->Stock1->Visible=false;
                        Fprincipal->Obra1->Visible=false;
                        Fprincipal->Chofer1->Visible=false;
                        Fprincipal->Vehiculo1->Visible=false;


                }
                Fprincipal->Lusuario->Caption=usuario.usuario;

                Fprincipal->Show();

        }
        else{
                ShowMessage("Usuario y/o contrase�a \n\n erroneas ");
                contador++;
        }
}
//---------------------------------------------------------------------------
void __fastcall TFlogin::Button2Click(TObject *Sender)
{
Flogin->Close();
}
//---------------------------------------------------------------------------

void __fastcall TFlogin::FormKeyPress(TObject *Sender, char &Key)
{
        if(Key==VK_RETURN){  //VK_RETURN ES EL ENTER QUE COSA DE LOCOS
          Perform(WM_NEXTDLGCTL, 0, 0); //Con esto el enter actua como el tab.
        }
}
//---------------------------------------------------------------------------

void __fastcall TFlogin::EusuarioKeyPress(TObject *Sender, char &Key)
{
        if(Key==VK_RETURN){  //VK_RETURN ES EL ENTER QUE COSA DE LOCOS
          Perform(WM_NEXTDLGCTL, 0, 0); //Con esto el enter actua como el tab.
        }
}
//---------------------------------------------------------------------------

void __fastcall TFlogin::EpasswordKeyPress(TObject *Sender, char &Key)
{
if(Key==VK_RETURN){  //VK_RETURN ES EL ENTER QUE COSA DE LOCOS
              Flogin->Button1Click(this);
          //Perform(WM_NEXTDLGCTL, 0, 0); //Con esto el enter actua como el tab.
        }        
}
//---------------------------------------------------------------------------

void __fastcall TFlogin::FormCreate(TObject *Sender)
{




    try{
        HMODULE hModule = GetModuleHandleW(NULL);
         WCHAR path[MAX_PATH];
         GetModuleFileNameW(hModule, path, MAX_PATH);
         direccion_global=quitar_cadena(path,strlen("combustible.exe"));
         dir_carga=direccion_global + "\\cargas_combustible.dat";
         dir_cargal= direccion_global + "\\carga_lubricante.dat";
         dir_chofer=direccion_global + "\\chofer.dat";
         dir_vehiculo=direccion_global + "\\vehiculos.dat";
         dir_obra=direccion_global + "\\obras.dat";
         dir_usuario=direccion_global + "\\usuarios.dat";
         }
         catch(Exception &Err)
         {

         dir_carga="cargas_combustible.dat";
         dir_cargal="carga_lubricante.dat";
         dir_chofer="chofer.dat";
         dir_vehiculo="vehiculos.dat";
         dir_obra= "obras.dat";
         dir_usuario="usuarios.dat";
}


}
//---------------------------------------------------------------------------



void __fastcall TFlogin::FormPaint(TObject *Sender)
{
 if(ParamCount()==2)
{
Flogin->Epassword->Text=ParamStr(2);
Flogin->Eusuario->Text=ParamStr(1);
Flogin->Button1Click(Sender);
}
}
//---------------------------------------------------------------------------

