//---------------------------------------------------------------------------
#include <vcl.h>
#include <iostream>
#pragma hdrstop
#include "principal.h"
#include "imprimir.h"
#include "funciones.h"
#include "cargachofer.h"
#include "cargavehiculo.h"
#include "cargaobra.h"
#include "Promedio.h"
#include "modificarchofer.h"
#include "modificarvehiculo.h"
#include "Cargam.h"
#include "Login.h"
#include "usuarios.h"
#include "modificarusuario.h"
#include "Stock.h"
#include "modificarobra.h"
#include "consulta.h"
#include "buscar.h"
//susuario usuario;

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TFprincipal *Fprincipal;
//---------------------------------------------------------------------------
__fastcall TFprincipal::TFprincipal(TComponent *Owner)
    : TForm(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TFprincipal::FormCreate(TObject *Sender)
{

        //StringGrid1->RowCount--;
        //for(int i=0;i<Elubricante->Items->Count;i++){
        StringGrid1->RowCount = 0;
        vector<String> matriz;
        vector<Stock> _stock;

        _stock = leer<Stock>("stock.dat");
        for (int i = 0; i < (int)_stock.size(); i++)
        {
                StringGrid1->Cells[0][i] = _stock[i].get_descripcion();
                StringGrid1->Cells[1][i] = _stock[i].get_cantstock();
                StringGrid1->RowCount = StringGrid1->RowCount + 1;
        }
        StringGrid1->RowCount = StringGrid1->RowCount - 1;
        auto_sizing(StringGrid1);
        Efecha->Text = Date().CurrentDate().FormatString("dd/mm/yyyy");
        //Le ponemos datos al combobox ECHOFER
        vector<schofer> unchofer;
        unchofer = ordenar_chofer(leer<schofer>(dir_chofer.c_str()));
        for (int i = 0; i < (int)unchofer.size(); i++)
        {
                Echofer->Items->Add(unchofer[i].chofer);
        }
        //FIN Le ponemos datos al combobox ECHOFER
        //Le ponemos datos al combobox EPATENTE
        vector<svehiculo> unvehiculo;
        unvehiculo = ordenar_vehiculo(leer<svehiculo>(dir_vehiculo.c_str()));
        for (int i = 0; i < (int)unvehiculo.size(); i++)
        {
                Epatente->Items->Add(unvehiculo[i].patente);
        }
        //FIN Le ponemos datos al combobox EPATENTE

        //Le ponemos datos al combobox EDESTINO
        vector<sobra> unobra;
        unobra = ordenar_obra(leer<sobra>(dir_obra.c_str()));
        for (int i = 0; i < (int)unobra.size(); i++)
        {
                Edestino->Items->Add(unobra[i].destino);
        }

        //FIN Le ponemos datos al combobox EDESTINO
}
//---------------------------------------------------------------------------

void __fastcall TFprincipal::FormKeyPress(TObject *Sender, char &Key)
{
        if (Key == VK_RETURN)
        {                                     //VK_RETURN ES EL ENTER QUE COSA DE LOCOS
                Perform(WM_NEXTDLGCTL, 0, 0); //Con esto el enter actua como el tab.
        }
}
//---------------------------------------------------------------------------

void __fastcall TFprincipal::Cargas1Click(TObject *Sender)
{
        /*char destino[100];/*Poniendo el nombre del archivo*/
        /*strcpy(destino,SDarchivo->FileName.c_str());
        //strcat(destino,"\\cargas_combustible");
        SDarchivo->FileName=destino;

        strcpy(destino,SDarchivo2->FileName.c_str());
        //strcat(destino,"\\cargas_combustible.dat");*/
        SDarchivo->FileName = "cargas_combustible.csv";
        SDarchivo->Execute();
        if (0 < exportar_carga(dir_carga.c_str(), SDarchivo->FileName.c_str()))
        {

                ShowMessage("el archivo fue guardado con exito");
        }
        else
        {
                ShowMessage("OOOPS algo a salido terriblemente mal...");
        }
        SDarchivo->FileName = "carga_lubricante.csv";
        SDarchivo->Execute();
        if (0 < exportar_cargal(dir_cargal.c_str(), SDarchivo->FileName.c_str()))
        {

                ShowMessage("el archivo fue guardado con exito");
        }
        else
        {
                ShowMessage("OOOPS algo a salido terriblemente mal...");
        }
}
//---------------------------------------------------------------------------

void __fastcall TFprincipal::vehiculos1Click(TObject *Sender)
{
        /*char destino[100];

        strcpy(destino,SDarchivo->FileName.c_str());
        strcat(destino,"\\vehiculos");
        SDarchivo->FileName=destino;

        strcpy(destino,SDarchivo2->FileName.c_str());
        strcat(destino,"\\vehiculos.dat");*/
        SDarchivo->Execute();

        if (0 < exportar_vehiculo(dir_vehiculo.c_str(), SDarchivo->FileName.c_str()))
        {

                ShowMessage("el archivo fue guardado con exito");
        }
        else
        {
                ShowMessage("OOOPS algo a salido terriblemente mal...");
        }
}

//---------------------------------------------------------------------------

void __fastcall TFprincipal::choferes1Click(TObject *Sender)
{
        /*char destino[100];
        strcpy(destino,SDarchivo->FileName.c_str());
        strcat(destino,"\\chofer");
        SDarchivo->FileName=destino;

        strcpy(destino,SDarchivo2->FileName.c_str());
        strcat(destino,"\\chofer.dat");*/
        SDarchivo->Execute();

        if (0 < exportar_chofer(dir_chofer.c_str(), SDarchivo->FileName.c_str()))
        {

                ShowMessage("el archivo fue guardado con exito");
        }
        else
        {
                ShowMessage("OOOPS algo a salido terriblemente mal...");
        }
}
//---------------------------------------------------------------------------

void __fastcall TFprincipal::Cargas2Click(TObject *Sender)
{
        //Aqui vamos a importar utilizando getline()

        string inicial;
        ifstream archivo("carga_combustible.csv");
        scarga carga;
        /*vector <scarga> cargas;*/

        while (!archivo.eof())
        {
                inicial.clear();
                getline(archivo, inicial, ';');
                carga.id = atoi(inicial.c_str());
                inicial.clear();
                getline(archivo, inicial, ';');
                carga.litros = atoi(inicial.c_str());
                inicial.clear();
                getline(archivo, inicial, ';');
                carga.kilometros = atof(inicial.c_str());
                inicial.clear();
                getline(archivo, inicial, ';');
                inicial.copy(carga.patente, inicial.length(), 0);
                carga.patente[6] = '\0';
                inicial.clear();
                /*Ignoramos la descripcion vehicular*/
                getline(archivo, inicial, ';');
                inicial.copy(carga.chofer, inicial.length(), 0);
                inicial.clear();
                /*Fin Ignoramos la descripcion vehicular*/
                inicial.copy(carga.chofer, inicial.length(), 0);
                carga.chofer[inicial.length()] = '\0';
                inicial.clear();
                getline(archivo, inicial, ';');
                inicial.copy(carga.destino, inicial.length(), 0);
                carga.destino[inicial.length()] = '\0';
                inicial.clear();
                getline(archivo, inicial, '\n');
                inicial.copy(carga.fecha, inicial.length(), 0);
                inicial.clear();
                carga.fecha[10] = '\0';
                /*ShowMessage(carga.fecha);*/
                escribir(carga, dir_carga.c_str());
        }
}
//---------------------------------------------------------------------------

void __fastcall TFprincipal::EdestinoChange(TObject *Sender)
{
        if (!RBLubricante->Checked)
        {
                //vamos a calcular el valor de la sugerencia
                std::stringstream sug;
                sug << "sugerencia";
                sug << ' ';
                sug << sugerencia(Epatente->Text.c_str(), Edestino->Text.c_str()) << "lts";
                Lsugerencia->Caption = sug.str().c_str();
        }
        else
        {
                Lsugerencia->Caption = "";
        }
}
//---------------------------------------------------------------------------

void __fastcall TFprincipal::EkilometrosKeyPress(TObject *Sender,
                                                 char &Key)
{
        if (!(Key >= '0' && Key <= '9' || Key == VK_BACK || Key == VK_DELETE || Key == '-'))
        {
                Key = '\0';
        }
}
//---------------------------------------------------------------------------

void __fastcall TFprincipal::EfechaKeyPress(TObject *Sender, char &Key)
{
        TEdit *Edit = dynamic_cast<TEdit *>(Sender);
        if (!(Key >= '0' && Key <= '9' || Key == VK_BACK || Key == VK_DELETE))
        {
                Key = '\0';
        }

        if (((Edit->Text.Length() == 2 && Edit->SelStart == 2) || (Edit->Text.Length() == 5 && Edit->SelStart == 5)) && !(Key == VK_BACK || Key == VK_DELETE))
        {

                Edit->Text = Edit->Text + "/";
                Edit->SelStart = Edit->Text.Length();
        }
        if ((Edit->Text.Length() == 10 && Edit->SelStart == 10) && !(Key == VK_BACK || Key == VK_DELETE))
        {
                Key = '\0';
        }
}
//---------------------------------------------------------------------------

void __fastcall TFprincipal::EpatenteKeyPress(TObject *Sender, char &Key)
{
        if ((Epatente->Text.Length() == 7 && Epatente->SelStart == 7) && !(Key == VK_BACK || Key == VK_DELETE))
        {
                Key = '\0';
        }
}
//---------------------------------------------------------------------------

void __fastcall TFprincipal::Promedio1Click(TObject *Sender)
{
        Fpromedio=new TFpromedio(this);
        Fpromedio->ShowModal();
        Fpromedio->~TFpromedio();
}
//---------------------------------------------------------------------------

void __fastcall TFprincipal::EpatenteChange(TObject *Sender)
{
        scargalubricante elanteriorl = anteriorl(Epatente->Text.c_str());
        scarga elanterior = anterior(Epatente->Text.c_str());
        std::stringstream ant;
        if (elanteriorl.kilometros > elanterior.kilometros)
        {
                ant << "KM anterior: ";
                ant << ' ';
                ant << elanteriorl.kilometros << " KM";
        }
        else
        {
                ant << "KM anterior: ";
                ant << ' ';
                ant << elanterior.kilometros << " KM";
        }
        if (RBLubricante->Checked)
        {
                //vamos a calcular el valor de la sugerencia
                Echofer->Text = elanteriorl.chofer;
                Edestino->Text = elanteriorl.destino;
                Lanterior->Caption = ant.str().c_str();
                EdestinoChange(Sender);
        }
        else
        {
                //vamos a calcular el valor de la sugerencia
                Echofer->Text = elanterior.chofer;
                Edestino->Text = elanterior.destino;
                Lanterior->Caption = ant.str().c_str();
                EdestinoChange(Sender);
        }
        svehiculo vehiculo;
        vehiculo = datosvehiculo(Epatente->Text.c_str());
        Label8->Caption = vehiculo.vehiculo;
        Epatente->Hint = vehiculo.vehiculo;
}
//---------------------------------------------------------------------------

void __fastcall TFprincipal::Alta1Click(TObject *Sender)
{       Fchofer=new TFchofer(this);
        Fchofer->ShowModal();
        Fchofer->~TFchofer();
}
//---------------------------------------------------------------------------

void __fastcall TFprincipal::Alta2Click(TObject *Sender)
{       Fvehiculos=new TFvehiculos(this);
        Fvehiculos->ShowModal();
        Fvehiculos->~TFvehiculos();
}
//---------------------------------------------------------------------------

void __fastcall TFprincipal::Modificacion1Click(TObject *Sender)
{
        Fmodificarchofer=new TFmodificarchofer(this);
        Fmodificarchofer->FormCreate(Sender);
        Fmodificarchofer->ShowModal();
        Fmodificarchofer->~TFmodificarchofer();
}
//---------------------------------------------------------------------------


void __fastcall TFprincipal::Modificacion2Click(TObject *Sender)
{
        Fmvehiculo=new TFmvehiculo(this);
        Fmvehiculo->ShowModal();
        Fmvehiculo->~TFmvehiculo();
}
//---------------------------------------------------------------------------

void __fastcall TFprincipal::modificar1Click(TObject *Sender)
{
        Fcargam=new TFcargam(this);
        Fcargam->ShowModal();
        Fcargam->~TFcargam();
}
//---------------------------------------------------------------------------

void __fastcall TFprincipal::FormClose(TObject *Sender,
                                       TCloseAction &Action)
{
        Flogin->Close();
}
//---------------------------------------------------------------------------

void __fastcall TFprincipal::Alta3Click(TObject *Sender)
{
        Fusuario=new TFusuario(this);
        Fusuario->ShowModal();
        Fusuario->~TFusuario();
}
//---------------------------------------------------------------------------

void __fastcall TFprincipal::Modificacion3Click(TObject *Sender)
{
        Fmusuario->Eusuario->Text = usuario.usuario;
        Fmusuario->CBadmin->Enabled = usuario.admin;
        Fmusuario->CBadmin->Checked = usuario.admin;
        Fmusuario->ShowModal();
}
//---------------------------------------------------------------------------

void __fastcall TFprincipal::RBLubricanteClick(TObject *Sender)
{
        Elubricante->Visible = True;
        Label7->Visible = True;
        Elubricante->Enabled = True;
        EpatenteChange(Sender);
}
//---------------------------------------------------------------------------

void __fastcall TFprincipal::RBCombustibleClick(TObject *Sender)
{
        Elubricante->Enabled = False;
        Elubricante->Visible = False;
        Label7->Visible = False;
        EpatenteChange(Sender);
}
//---------------------------------------------------------------------------

void __fastcall TFprincipal::Vehiculos2Click(TObject *Sender)
{
        //Aqui vamos a importar utilizando getline()

        string inicial;
        ifstream archivo("vehiculo.csv");
        svehiculo vehiculo;
        getline(archivo, inicial, '\n');

        while (!archivo.eof())
        {

                inicial.clear();
                getline(archivo, inicial, ';');
                vehiculo.id = atoi(inicial.c_str());
                inicial.clear();
                getline(archivo, inicial, ';');
                inicial.copy(vehiculo.patente, inicial.length(), 0);
                vehiculo.patente[inicial.length()] = '\0';
                inicial.clear();
                getline(archivo, inicial, ';');
                inicial.copy(vehiculo.vehiculo, inicial.length(), 0);
                vehiculo.vehiculo[inicial.length()] = '\0';
                inicial.clear();
                getline(archivo, inicial, '\n');
                vehiculo.consumo = atoi(inicial.c_str());
                inicial.clear();
                escribir(vehiculo, dir_vehiculo.c_str());
        }
}
//---------------------------------------------------------------------------

void __fastcall TFprincipal::Stock1Click(TObject *Sender)
{       Fstock=new TFstock(this);
        Fstock->ShowModal();
        Fstock->~TFstock();
}
//---------------------------------------------------------------------------

void __fastcall TFprincipal::Consulta1Click(TObject *Sender)
{
        FConsulta=new TFConsulta(this);
        FConsulta->ShowModal();
        FConsulta->~TFConsulta();
}
//---------------------------------------------------------------------------

void __fastcall TFprincipal::Alta4Click(TObject *Sender)
{
        Fobras=new TFobras(this);
        Fobras->ShowModal();
        Fobras->~TFobras();
}
//---------------------------------------------------------------------------

void __fastcall TFprincipal::Modificar2Click(TObject *Sender)
{
        Fmobra=new TFmobra(this);
        Fmobra->ShowModal();
        Fmobra->~TFmobra();
}
//---------------------------------------------------------------------------

void __fastcall TFprincipal::BtguardarClick(TObject *Sender)
{
        String archive;
        bool lubricante = false;
        if (RBLubricante->Checked)
        {
                archive = dir_cargal;
                lubricante = true;
        }
        else
        {
                archive = dir_carga;
        }

        if (Epatente->Text != "" && Echofer->Text != "" && Elitros->Text != "" && Edestino->Text != "" && Ekilometros->Text != 0)
        {
                scarga elanterior = anterior(Epatente->Text.c_str());
                scargalubricante elanteriorl = anteriorl(Epatente->Text.c_str());
                if (lubricante)
                {
                        elanterior.kilometros = elanteriorl.kilometros;
                }
                if (Ekilometros->Text.ToInt() >= elanterior.kilometros)
                {
                        if (IDNO != Application->MessageBoxA("¿Estás seguro de querer guardar?", "Guardar", MB_YESNO))
                        {
                                //comparamos los items de los combobox para ver si existen coincidencias
                                bool match;
                                match = false;
                                int i = 0;
                                while (!match)
                                {
                                        for (i = 0; i < Echofer->Items->Count; i++)
                                        {
                                                if (Echofer->Text == Echofer->Items->Strings[i])
                                                { //ERROR Ni idea porque
                                                        match = true;
                                                }
                                        }
                                        if (!match)
                                        {
                                                ShowMessage("Ese chofer no esta registrado");
                                                Fchofer=new TFchofer(this);
                                                Fchofer->Enombre->Text = Echofer->Text;
                                                Fchofer->Evehiculo->Text = Epatente->Text;
                                                Fchofer->ShowModal();
                                        }
                                }
                                match = false;
                                i = 0;
                                while (!match)
                                {
                                        for (i = 0; i < Epatente->Items->Count; i++)
                                        {
                                                if (Epatente->Text == Epatente->Items->Strings[i])
                                                {
                                                        match = true;
                                                }
                                        }

                                        if (!match)
                                        {
                                                ShowMessage("Ese vehiculo no esta registrado");
                                                Fvehiculos=new TFvehiculos(this);
                                                Fvehiculos->Epatente->Text = Epatente->Text;
                                                Fvehiculos->ShowModal();
                                        }
                                }
                                match = false;
                                i = 0;
                                while (!match)
                                {
                                        for (i = 0; i < Edestino->Items->Count; i++)
                                        {
                                                if (Edestino->Text == Edestino->Items->Strings[i])
                                                {
                                                        match = true;
                                                }
                                        }
                                        if (!match)
                                        {
                                                ShowMessage("Esa Obra no esta registrada");
                                                Fobras=new TFobras(this);
                                                Fobras->Edestino->Text = Edestino->Text;
                                                Fobras->ShowModal();
                                        }
                                }
                                //FIN comparamos los items de los combobox para ver si existen coincidencias
                                //Pasamos a imprimir
                                int vale;
                                Stock _stock;
                                vector<Stock> s;
                                if (lubricante)
                                {
                                        scargalubricante uncarga;
                                        strcpy(uncarga.lubricante, mayuscula(Elubricante->Text.c_str()));
                                        uncarga.litros = Elitros->Text.ToDouble();
                                        uncarga.kilometros = Ekilometros->Text.ToDouble();
                                        strcpy(uncarga.patente, Epatente->Text.c_str());
                                        strcpy(uncarga.chofer, Echofer->Text.c_str());
                                        strcpy(uncarga.destino, Edestino->Text.c_str());
                                        strcpy(uncarga.fecha, Efecha->Text.c_str());
                                        strcpy(uncarga.usuario, usuario.usuario);
                                        uncarga.id = 0;
                                        vale = escribir(uncarga, archive.c_str());
                                        Fprint->QRLetra->Caption = "B";
                                        Fprint->QRGasoil->Caption = Elubricante->Text;
                                        Fprint->QRobservacion->Caption = "";
                                        _stock.set_descripcion(uncarga.lubricante);
                                }
                                else
                                {
                                        scarga unacarga;
                                        unacarga.litros = Elitros->Text.ToInt();
                                        unacarga.kilometros = Ekilometros->Text.ToDouble();
                                        strcpy(unacarga.patente, Epatente->Text.c_str());
                                        strcpy(unacarga.chofer, Echofer->Text.c_str());
                                        strcpy(unacarga.destino, Edestino->Text.c_str());
                                        strcpy(unacarga.fecha, Efecha->Text.c_str());
                                        strcpy(unacarga.usuario, usuario.usuario);
                                        unacarga.id = 0;
                                        vale = escribir(unacarga, archive.c_str());
                                        Fprint->QRLetra->Caption = "A";
                                        Fprint->QRGasoil->Caption = "Gasoil";
                                        Fprint->QRobservacion->Caption = "NO VALIDO FUERA DEL OBRADOR";
                                        _stock.set_descripcion("gasoil surtidor");
                                }
                                Fprint->QRlitros->Caption = Elitros->Text;
                                Fprint->QRvale->Caption = vale;
                                Fprint->QRdestino->Caption = Edestino->Text;
                                Fprint->QRchofer->Caption = Echofer->Text;
                                Fprint->QRkilometros->Caption = Ekilometros->Text;
                                Fprint->QRpatente->Caption = Epatente->Text;
                                Fprint->QRFecha->Caption = Efecha->Text;
                                svehiculo vehiculo = datosvehiculo(Epatente->Text.c_str());
                                Fprint->QRmarca->Caption = vehiculo.vehiculo;
                                Fprint->QRLabel10->Caption = strupr(usuario.usuario);
                                Fprint->Show();
                                if (0 != strcmp(_stock.get_descripcion(), "NAFTA SUPER"))
                                {
                                        if (0 != strcmp(_stock.get_descripcion(), "NAFTA PREMIUM"))
                                        {
                                                if (0 != strcmp(_stock.get_descripcion(), "GASOIL PREMIUM"))
                                                {
                                                        _stock = leerstock(_stock);
                                                        _stock.restar(Elitros->Text.ToInt());
                                                        escribirstock(_stock);
                                                        s = leer<Stock>("stock.dat");
                                                        for (int i = 0; i < 14; i++)
                                                        {
                                                                StringGrid1->Cells[0][i] = s[i].get_descripcion();
                                                                StringGrid1->Cells[1][i] = s[i].get_cantstock();
                                                        }
                                                }
                                        }
                                }
                                limpiar(Elitros);
                                limpiar(Ekilometros);
                                //Fstock->FormCreate(Sender);
                        }
                        //Fin Ahora limpiamos los valores
                }
                else
                {
                        ShowMessage("Los kilometros ingresados son menores al ultimo ingresado...");
                        Ekilometros->SetFocus();
                }
        }
        else
        {
                ShowMessage("Faltan Datos...");
                Epatente->SetFocus();
        }
}
//---------------------------------------------------------------------------


void __fastcall TFprincipal::SpeedButton1Click(TObject *Sender)
{
/*Buscador de vehiculos por descripcion*/
Fbuscar=new TFbuscar(this);
Fbuscar->ShowModal();
}
//---------------------------------------------------------------------------

