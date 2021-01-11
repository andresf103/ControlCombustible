//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Cargam.h"
#include "funciones.h"
#include "imprimir.h"
#include "principal.h"
#include "Stock.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TFcargam *Fcargam;
//---------------------------------------------------------------------------
__fastcall TFcargam::TFcargam(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TFcargam::FormCreate(TObject *Sender)
{

        /*int a=compararFecha("20/05/2015","20/05/2015");*/

        Efecha->Text=Date().CurrentDate();
      //Le ponemos datos al combobox ECHOFER
        vector<schofer> unchofer;
        unchofer=leer<schofer>(dir_chofer.c_str());
        for(int i=0;i<(int)unchofer.size();i++){
                Echofer->Items->Add(unchofer[i].chofer);
        }
      //FIN Le ponemos datos al combobox ECHOFER
      //Le ponemos datos al combobox EPATENTE
        vector<svehiculo> unvehiculo;
        unvehiculo=leer<svehiculo>(dir_vehiculo.c_str());
        for(int i=0;i<(int)unvehiculo.size();i++){
                Epatente->Items->Add(unvehiculo[i].patente);
        }
      //FIN Le ponemos datos al combobox EPATENTE

      //Le ponemos datos al combobox EDESTINO
        vector<sobra> unobra;
        unobra=leer<sobra>(dir_obra.c_str());
        for(int i=0;i<(int)unobra.size();i++){
                Edestino->Items->Add(unobra[i].destino);
        }
      //FIN Le ponemos datos al combobox EDESTINO

}
//---------------------------------------------------------------------------

void __fastcall TFcargam::EidChange(TObject *Sender)
{
   if(!Eid->Text.IsEmpty()){
        scarga porid;
        scargalubricante poridl;
        vector <scarga> cargas;
        vector <scargalubricante> cargasl;
	cargasl=leer<scargalubricante>("carga_lubricante.dat");
        cargas=leer<scarga>("cargas_combustible.dat");
        int idmax;
        if(RBLubricante->Checked==true){
           idmax=(int)cargasl.size();
        }else{
           idmax=(int)cargas.size();
        }
        if(Eid->Text.ToInt()>idmax){
                Eid->Text=idmax;
        }

        if(RadioButton1->Checked){

        porid=buscarid(Eid->Text.ToInt()-1);
        Epatente->Text=porid.patente;
        Ekilometros->Text=porid.kilometros;
        Echofer->Text=porid.chofer;
        Edestino->Text=porid.destino;
        Efecha->Text=porid.fecha;
        Elitros->Text=porid.litros;
        }
        else{
        poridl=buscaridl(Eid->Text.ToInt()-1);
        Elubricante->Text=poridl.lubricante;
        Epatente->Text=poridl.patente;
        Ekilometros->Text=poridl.kilometros;
        Echofer->Text=poridl.chofer;
        Edestino->Text=poridl.destino;
        Efecha->Text=poridl.fecha;
        Elitros->Text=poridl.litros;
        }
   }

}
//---------------------------------------------------------------------------

void __fastcall TFcargam::Button3Click(TObject *Sender)
{
	vector <scarga> cargas;
        vector <scargalubricante> cargasl;
	cargasl=leer<scargalubricante>("carga_lubricante.dat");
        cargas=leer<scarga>("cargas_combustible.dat");
        int idmax;
        if(RBLubricante->Checked==true){
           idmax=(int)cargasl.size();
        }else{
           idmax=(int)cargas.size();
        }
        if(Eid->Text.ToInt()>1){
                Eid->Text=Eid->Text.ToInt()-1;
        }else{
                Eid->Text=idmax;
        }
}
//---------------------------------------------------------------------------

void __fastcall TFcargam::Button2Click(TObject *Sender)
{
	vector <scarga> cargas;
        vector <scargalubricante> cargasl;
	cargasl=leer<scargalubricante>("carga_lubricante.dat");
        cargas=leer<scarga>("cargas_combustible.dat");
        int idmax;
        if(RBLubricante->Checked==true){
           idmax=(int)cargasl.size();
        }else{
           idmax=(int)cargas.size();
        }
        if(Eid->Text.IsEmpty()){Eid->Text=0;}
        if(Eid->Text.ToInt()<idmax){
           Eid->Text= Eid->Text.ToInt()+1;
        }else{
           Eid->Text=1;
        }

}
//---------------------------------------------------------------------------

void __fastcall TFcargam::BtguardarClick(TObject *Sender)
{
        bool lubricante=false;
        scargalubricante unacargal;
        scargalubricante cargaantigual;
        scarga unacarga, cargaantigua;
        Stock _stock;
        vector <Stock> s;
        int vale;
        int id;
        id=Eid->Text.ToInt()-1;
        if(RBLubricante->Checked==true){
                lubricante=true;
                unacargal=buscaridl(id);
                cargaantigual=unacargal;
                unacargal.litros=Elitros->Text.ToDouble();
                unacargal.kilometros=Ekilometros->Text.ToDouble();
                strcpy(unacargal.patente,Epatente->Text.c_str());
                strcpy(unacargal.lubricante,Elubricante->Text.c_str());
                strcpy(unacargal.chofer,Echofer->Text.c_str());
                strcpy(unacargal.destino,Edestino->Text.c_str());
                strcpy(unacargal.fecha,Efecha->Text.c_str());
                escribiridl(unacargal,dir_cargal.c_str(),unacargal.id);
                if (0 != strcmp(_stock.get_descripcion(), "NAFTA SUPER"))
                        {
                         if (0 != strcmp(_stock.get_descripcion(), "NAFTA PREMIUM"))
                                {
                                 if (0 != strcmp(_stock.get_descripcion(), "GASOIL PREMIUM"))
                                        {
                if(0==strcmp(unacargal.lubricante,cargaantigual.lubricante))
                        {
                        _stock.set_descripcion(unacargal.lubricante);
                        _stock=leerstock(_stock);
                        _stock.sumar(cargaantigual.litros-unacargal.litros);
                        escribirstock(_stock);
                        }
                else
                        {
                        _stock.set_descripcion(cargaantigual.lubricante);
                        _stock=leerstock(_stock);
                        _stock.sumar(cargaantigual.litros);
                        escribirstock(_stock);
                        _stock.set_descripcion(unacargal.lubricante);
                        _stock=leerstock(_stock);
                        _stock.restar(unacargal.litros);
                        escribirstock(_stock);
                }
                                        }
                                }
                        }
                //tenemos que corregir el valor del stock

                //fin de la correccion del stock



        }else{
              unacarga=buscarid(id);
              cargaantigua=unacarga;
              unacarga.litros=Elitros->Text.ToInt();
              unacarga.kilometros=Ekilometros->Text.ToDouble();
              strcpy(unacarga.patente,Epatente->Text.c_str());
              strcpy(unacarga.chofer,Echofer->Text.c_str());
              strcpy(unacarga.destino,Edestino->Text.c_str());
              strcpy(unacarga.fecha,Efecha->Text.c_str());
              escribirid(unacarga,dir_carga.c_str(),unacarga.id);
              _stock.set_descripcion("gasoil surtidor");
              _stock=leerstock(_stock);
              _stock.sumar(cargaantigua.litros-unacarga.litros);
              escribirstock(_stock);

        }

        if(lubricante){

                Fprint->QRLetra->Caption="B";
                Fprint->QRGasoil->Caption=Elubricante->Text;
                vale=unacargal.id+1;
                Fprint->QRLabel10->Caption= strupr(unacargal.usuario);
                Fprint->QRobservacion->Caption ="";
        }else{
                Fprint->QRLetra->Caption="A";
                Fprint->QRGasoil->Caption="Gasoil";
                Fprint->QRobservacion->Caption = "NO VALIDO FUERA DEL OBRADOR";
                vale=unacarga.id+1;
                Fprint->QRLabel10->Caption= strupr(unacarga.usuario);
        }
        //Fstock->FormCreate(Sender);
        s=leer<Stock>("stock.dat");
        for(int i=0;i<14;i++){
                Fprincipal->StringGrid1->Cells[0][i]=s[i].get_descripcion();
                Fprincipal->StringGrid1->Cells[1][i]=s[i].get_cantstock();
        }
        Fprint->QRlitros->Caption=Elitros->Text;
        Fprint->QRvale->Caption=vale;
        Fprint->QRdestino->Caption=Edestino->Text;
        Fprint->QRchofer->Caption=Echofer->Text;
        Fprint->QRkilometros->Caption=Ekilometros->Text;
        Fprint->QRpatente->Caption=Epatente->Text;
        Fprint->QRFecha->Caption=Efecha->Text;
        svehiculo vehiculo=datosvehiculo(Epatente->Text.c_str());
        Fprint->QRmarca->Caption=vehiculo.vehiculo;
        Fprint->Show();


}
//---------------------------------------------------------------------------

void __fastcall TFcargam::EidKeyPress(TObject *Sender, char &Key)
{
        if((Epatente->Text.Length()==7&&Epatente->SelStart==7)&&!(Key==VK_BACK||Key==VK_DELETE)){
                Key='\0';
        }
        
}
//---------------------------------------------------------------------------

void __fastcall TFcargam::RadioButton1Click(TObject *Sender)
{
  EidChange(Sender);
  Elubricante->Enabled=false;
  Elubricante->Visible=false;
  Label8->Visible=false;
}
//---------------------------------------------------------------------------

void __fastcall TFcargam::RBLubricanteClick(TObject *Sender)
{
  EidChange(Sender);
  Elubricante->Enabled=true;
  Elubricante->Visible=true;
  Label8->Visible=true;
}
//---------------------------------------------------------------------------

void __fastcall TFcargam::FormKeyPress(TObject *Sender, char &Key)
{
        if(Key==VK_ESCAPE){
                this->Close();
        }
}
//---------------------------------------------------------------------------



