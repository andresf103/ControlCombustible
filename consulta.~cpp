//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "consulta.h"
#include "principal.h"
#include "funciones.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TFConsulta *FConsulta;

//---------------------------------------------------------------------------
__fastcall TFConsulta::TFConsulta(TComponent *Owner)
    : TForm(Owner)
{
}

//---------------------------------------------------------------------------
void __fastcall TFConsulta::FormCreate(TObject *Sender)
{
  CBobra->Items = Fprincipal->Edestino->Items;
  CBvehiculo->Items = Fprincipal->Epatente->Items;
  CBchofer->Items = Fprincipal->Echofer->Items;

  /* filtrar fecha se va a armar con las fechas disponibles dentro del archivo
  de carga
  va a leer todo y va a ir agregando las fechas disponibles
  */
  vector<scargalubricante> cargasl;
  cargasl = leer<scargalubricante>(dir_cargal.c_str());
  vector<scarga> cargas;
  scarga carga;
  strcpy(carga.fecha, "01/01/2000");
  cargas = leer<scarga>(dir_carga.c_str());
  long int litros = 0;
  int size;
  if (CBgasoil->Checked)
  {
    size = cargas.size();
  }
  else
  {
    size = cargasl.size();
  }

  /* Tenemos que sumar las cantidades de fechas y ordenerlas para recorrerlas aqui debajo*/
  sfecha fecha;
  vector<sfecha> fechasc, fechasl, fechas;
  for (int i = 1; i < (int)cargas.size(); i++)
  {
    strcpy(fecha.fecha, cargas[i].fecha);
    if (i < 1)
    {
      fechasc.push_back(fecha);
    }
    if (0 != compararFecha(cargas[i].fecha, cargas[i - 1].fecha))
    {
      fechasc.push_back(fecha);
    }
  }
  for (int i = 1; i < (int)cargasl.size(); i++)
  {
    strcpy(fecha.fecha, cargasl[i].fecha);
    if (i < 1)
    {
      fechasl.push_back(fecha);
    }
    if (0 != compararFecha(cargasl[i].fecha, cargasl[i - 1].fecha))
    {
      fechasl.push_back(fecha);
    }
  }
  fechas = ordenarFecha(fechasl, fechasc);
  for (int i = 0; i < (int)fechas.size(); i++)
  {
    CBfecha->Items->Add(fechas[i].fecha);
  }
  CBfecha2->Items = CBfecha->Items;

  StringGrid1->RowCount = 0;
  StringGrid1->Cells[0][0] = "Fecha";
  StringGrid1->Cells[1][0] = "Patente";
  StringGrid1->Cells[2][0] = "Kilometros";
  StringGrid1->Cells[3][0] = "Obra";
  StringGrid1->Cells[4][0] = "Chofer";
  StringGrid1->Cells[5][0] = "Litros";
  StringGrid1->Cells[6][0] = "Vale";
  StringGrid1->Cells[7][0] = "Usuario";
  StringGrid1->Cells[8][0] = "Descripcion";
  for (int i = 1; i <= size; i++)
  {
    if (CBgasoil->Checked)
    {
      StringGrid1->Cells[0][i] = cargas[i - 1].fecha;
      StringGrid1->Cells[1][i] = cargas[i - 1].patente;
      StringGrid1->Cells[2][i] = cargas[i - 1].kilometros;
      StringGrid1->Cells[3][i] = cargas[i - 1].destino;
      StringGrid1->Cells[4][i] = cargas[i - 1].chofer;
      StringGrid1->Cells[5][i] = cargas[i - 1].litros;
      StringGrid1->Cells[6][i] = cargas[i - 1].id + 1;
      StringGrid1->Cells[7][i] = cargas[i - 1].usuario;
      StringGrid1->Cells[8][i] = "GAS OIL";
      StringGrid1->RowCount = StringGrid1->RowCount + 1;
      litros = litros + cargas[i].litros;
    }
    else
    {
      StringGrid1->Cells[0][i] = cargasl[i - 1].fecha;
      StringGrid1->Cells[1][i] = cargasl[i - 1].patente;
      StringGrid1->Cells[2][i] = cargasl[i - 1].kilometros;
      StringGrid1->Cells[3][i] = cargasl[i - 1].destino;
      StringGrid1->Cells[4][i] = cargasl[i - 1].chofer;
      StringGrid1->Cells[5][i] = cargasl[i - 1].litros;
      StringGrid1->Cells[6][i] = cargasl[i - 1].id + 1;
      StringGrid1->Cells[7][i] = cargasl[i - 1].usuario;
      StringGrid1->Cells[8][i] = cargasl[i - 1].lubricante;
      StringGrid1->RowCount = StringGrid1->RowCount + 1;
      litros = 0;
    }
  }
  //StringGrid1->RowCount=StringGrid1->RowCount-1;
  Lblitros->Caption = litros;
  try
  {
    StringGrid1->FixedRows = 1;
  }
  catch (Exception &Err)
  {
    StringGrid1->RowCount = 1;
    StringGrid1->FixedRows = 0;
  }
  auto_sizing(StringGrid1);
}
//---------------------------------------------------------------------------





void __fastcall TFConsulta::CBotrosClick(TObject *Sender)
{
if (!CBfecha->Text.IsEmpty() && !CBfecha2->Text.IsEmpty())
  {
   CBfechaExit(Sender);
  }
  else
  {
  FormCreate(Sender);
  }
}
//---------------------------------------------------------------------------
void __fastcall TFConsulta::CBgasoilClick(TObject *Sender)
{
if (!CBfecha->Text.IsEmpty() && !CBfecha2->Text.IsEmpty())
  {
  CBfechaExit(Sender);
  }
  else
  {
FormCreate(Sender);
}
}
//---------------------------------------------------------------------------

void __fastcall TFConsulta::CBfechaExit(TObject *Sender)
{
  if(CBfecha2->Text.IsEmpty())
  {
        CBfecha2->Text=CBfecha->Text;
  }
  if (!CBfecha->Text.IsEmpty() && !CBfecha2->Text.IsEmpty())
  {
    vector<scarga> cargas;
    cargas = leer<scarga>(dir_carga.c_str());
    vector<scargalubricante> cargasl;
    scargalubricante cargado;
    cargasl = leer<scargalubricante>(dir_cargal.c_str());
    StringGrid1->CleanupInstance();
    StringGrid1->RowCount = 0;
    StringGrid1->Cells[0][0] = "Fecha";
    StringGrid1->Cells[1][0] = "Patente";
    StringGrid1->Cells[2][0] = "Kilometros";
    StringGrid1->Cells[3][0] = "Obra";
    StringGrid1->Cells[4][0] = "Chofer";
    StringGrid1->Cells[5][0] = "Litros";
    StringGrid1->Cells[6][0] = "Vale";
    StringGrid1->Cells[7][0] = "Usuario";
    StringGrid1->Cells[8][0] = "Descripcion";
    int contador = 1;
    long int litros = 0;
    int size;
    if (CBgasoil->Checked)
    {
      size = cargas.size();
    }
    else
    {
      size = cargasl.size();
    }
    for (int i = 1; i <= size; i++)
    {
      if (CBgasoil->Checked)
      {
        cargado = igual(cargas[i - 1]);
      }
      else
      {
        cargado = cargasl[i - 1];
      }
      if (1 != compararFecha(CBfecha->Text.c_str(), cargado.fecha))
      {
        if (-1 != compararFecha(CBfecha2->Text.c_str(), cargado.fecha))
        {
          StringGrid1->Cells[0][contador] = cargado.fecha;
          StringGrid1->Cells[1][contador] = cargado.patente;
          StringGrid1->Cells[2][contador] = cargado.kilometros;
          StringGrid1->Cells[3][contador] = cargado.destino;
          StringGrid1->Cells[4][contador] = cargado.chofer;
          StringGrid1->Cells[5][contador] = cargado.litros;
          StringGrid1->Cells[6][contador] = cargado.id + 1;
          StringGrid1->Cells[7][contador] = cargado.usuario;
          StringGrid1->Cells[8][contador] = cargado.lubricante;
          StringGrid1->RowCount = StringGrid1->RowCount + 1;
          contador++;
          if (CBgasoil->Checked)
          {
            litros = litros + cargas[i - 1].litros;
          }
          else
          {
            litros = 0;
          }
        }
      }
    }
    //StringGrid1->RowCount=StringGrid1->RowCount-1;
    Lblitros->Caption = litros;
    try
    {
      StringGrid1->FixedRows = 1;
    }
    catch (Exception &Err)
    {
      StringGrid1->RowCount = 1;
      StringGrid1->FixedRows = 0;
    }
    CBobra->Text = "";
    CBvehiculo->Text = "";
    CBchofer->Text = "";
  }
        
}
//---------------------------------------------------------------------------

void __fastcall TFConsulta::CBfecha2Exit(TObject *Sender)
{
CBfechaExit(Sender);
}
//---------------------------------------------------------------------------

void __fastcall TFConsulta::FormKeyPress(TObject *Sender, char &Key)
{
        if (Key == VK_RETURN)
        {                                     //VK_RETURN ES EL ENTER QUE COSA DE LOCOS
                Perform(WM_NEXTDLGCTL, 0, 0); //Con esto el enter actua como el tab.
        }
                if(Key==VK_ESCAPE){
                this->Close();
        }
}
//---------------------------------------------------------------------------

void __fastcall TFConsulta::CBobraExit(TObject *Sender)
{
if (!CBobra->Text.IsEmpty())
  {
    vector<scarga> cargas;
    cargas = leer<scarga>(dir_carga.c_str());
    vector<scargalubricante> cargasl;
    cargasl = leer<scargalubricante>(dir_cargal.c_str());
    scargalubricante cargado;
    StringGrid1->CleanupInstance();
    StringGrid1->RowCount = 0;
    StringGrid1->Cells[0][0] = "Fecha";
    StringGrid1->Cells[1][0] = "Patente";
    StringGrid1->Cells[2][0] = "Kilometros";
    StringGrid1->Cells[3][0] = "Obra";
    StringGrid1->Cells[4][0] = "Chofer";
    StringGrid1->Cells[5][0] = "Litros";
    StringGrid1->Cells[6][0] = "Vale";
    StringGrid1->Cells[7][0] = "Usuario";
    StringGrid1->Cells[8][0] = "Descripcion";
    int contador = 1;
    long int litros = 0;
    int size;
    if (CBgasoil->Checked)
    {
      size = cargas.size();
    }
    else
    {
      size = cargasl.size();
    }
    for (int i = 1; i <= size; i++)
    {
      if (CBgasoil->Checked)
      {
        cargado = igual(cargas[i - 1]);
      }
      else
      {
        cargado = cargasl[i - 1];
      }
      if (1 != compararFecha(CBfecha->Text.c_str(), cargado.fecha))
      {
        if (-1 != compararFecha(CBfecha2->Text.c_str(), cargado.fecha))
        {
          if (0 == strcmp(CBobra->Text.c_str(), cargado.destino))
          {
            StringGrid1->Cells[0][contador] = cargado.fecha;
            StringGrid1->Cells[1][contador] = cargado.patente;
            StringGrid1->Cells[2][contador] = cargado.kilometros;
            StringGrid1->Cells[3][contador] = cargado.destino;
            StringGrid1->Cells[4][contador] = cargado.chofer;
            StringGrid1->Cells[5][contador] = cargado.litros;
            StringGrid1->Cells[6][contador] = cargado.id + 1;
            StringGrid1->Cells[7][contador] = cargado.usuario;
            StringGrid1->Cells[8][contador] = cargado.lubricante;
            StringGrid1->RowCount = StringGrid1->RowCount + 1;
            contador++;
            if (CBgasoil->Checked)
            {
              litros = litros + cargas[i - 1].litros;
            }
            else
            {
              litros = 0;
            }
          }
        }
      }
    }
    //StringGrid1->RowCount=StringGrid1->RowCount-1;
    Lblitros->Caption = litros;
    try
    {
      StringGrid1->FixedRows = 1;
    }
    catch (Exception &Err)
    {
      StringGrid1->RowCount = 1;
      StringGrid1->FixedRows = 0;
    }
    //CBfecha->Text="";
    CBvehiculo->Text = "";
    CBchofer->Text = "";
  }        
}
//---------------------------------------------------------------------------

void __fastcall TFConsulta::CBvehiculoExit(TObject *Sender)
{
if (!CBvehiculo->Text.IsEmpty())
  {
    vector<scarga> cargas;
    cargas = leer<scarga>(dir_carga.c_str());
    vector<scargalubricante> cargasl;
    cargasl = leer<scargalubricante>(dir_cargal.c_str());
    scargalubricante cargado;
    StringGrid1->CleanupInstance();
    StringGrid1->RowCount = 0;
    StringGrid1->Cells[0][0] = "Fecha";
    StringGrid1->Cells[1][0] = "Patente";
    StringGrid1->Cells[2][0] = "Kilometros";
    StringGrid1->Cells[3][0] = "Obra";
    StringGrid1->Cells[4][0] = "Chofer";
    StringGrid1->Cells[5][0] = "Litros";
    StringGrid1->Cells[6][0] = "Vale";
    StringGrid1->Cells[7][0] = "Usuario";
    StringGrid1->Cells[8][0] = "Descripcion";
    int contador = 1;
    long int litros = 0;
    int size;
    if (CBgasoil->Checked)
    {
      size = cargas.size();
    }
    else
    {
      size = cargasl.size();
    }
    for (int i = 1; i <= size; i++)
    {
      if (CBgasoil->Checked)
      {
        cargado = igual(cargas[i - 1]);
      }
      else
      {
        cargado = cargasl[i - 1];
      }
      if (1 != compararFecha(CBfecha->Text.c_str(), cargado.fecha))
      {
        if (-1 != compararFecha(CBfecha2->Text.c_str(), cargado.fecha))
        {
          if (0 == strcmp(CBvehiculo->Text.c_str(), cargado.patente))
          {
            StringGrid1->Cells[0][contador] = cargado.fecha;
            StringGrid1->Cells[1][contador] = cargado.patente;
            StringGrid1->Cells[2][contador] = cargado.kilometros;
            StringGrid1->Cells[3][contador] = cargado.destino;
            StringGrid1->Cells[4][contador] = cargado.chofer;
            StringGrid1->Cells[5][contador] = cargado.litros;
            StringGrid1->Cells[6][contador] = cargado.id + 1;
            StringGrid1->Cells[7][contador] = cargado.usuario;
            StringGrid1->Cells[8][contador] = cargado.lubricante;
            StringGrid1->RowCount = StringGrid1->RowCount + 1;
            contador++;
            if (CBgasoil->Checked)
            {
              litros = litros + cargas[i - 1].litros;
            }
            else
            {
              litros = 0;
            }
          }
        }
      }
    }
    //StringGrid1->RowCount=StringGrid1->RowCount-1;
    Lblitros->Caption = litros;
    try
    {
      StringGrid1->FixedRows = 1;
    }
    catch (Exception &Err)
    {
      StringGrid1->RowCount = 1;
      StringGrid1->FixedRows = 0;
    }
    //CBfecha->Text="";
    CBobra->Text = "";
    CBchofer->Text = "";
  }        
}
//---------------------------------------------------------------------------

void __fastcall TFConsulta::CBchoferExit(TObject *Sender)
{
if (!CBchofer->Text.IsEmpty())
  {
    vector<scarga> cargas;
    cargas = leer<scarga>(dir_carga.c_str());
    vector<scargalubricante> cargasl;
    cargasl = leer<scargalubricante>(dir_cargal.c_str());
    scargalubricante cargado;
    StringGrid1->CleanupInstance();
    StringGrid1->RowCount = 0;
    StringGrid1->Cells[0][0] = "Fecha";
    StringGrid1->Cells[1][0] = "Patente";
    StringGrid1->Cells[2][0] = "Kilometros";
    StringGrid1->Cells[3][0] = "Obra";
    StringGrid1->Cells[4][0] = "Chofer";
    StringGrid1->Cells[5][0] = "Litros";
    StringGrid1->Cells[6][0] = "Vale";
    StringGrid1->Cells[7][0] = "Usuario";
    StringGrid1->Cells[8][0] = "Descripcion";
    int contador = 1;
    long unsigned int litros = 0;
    int size;
    if (CBgasoil->Checked)
    {
      size = cargas.size();
    }
    else
    {
      size = cargasl.size();
    }
    for (int i = 1; i <= size; i++)
    {
      if (CBgasoil->Checked)
      {
        cargado = igual(cargas[i - 1]);
      }
      else
      {
        cargado = cargasl[i - 1];
      }
      if (1 != compararFecha(CBfecha->Text.c_str(), cargado.fecha))
      {
        if (-1 != compararFecha(CBfecha2->Text.c_str(), cargado.fecha))
        {
          if (0 == strcmp(CBchofer->Text.c_str(), cargado.chofer))
          {
            StringGrid1->Cells[0][contador] = cargado.fecha;
            StringGrid1->Cells[1][contador] = cargado.patente;
            StringGrid1->Cells[2][contador] = cargado.kilometros;
            StringGrid1->Cells[3][contador] = cargado.destino;
            StringGrid1->Cells[4][contador] = cargado.chofer;
            StringGrid1->Cells[5][contador] = cargado.litros;
            StringGrid1->Cells[6][contador] = cargado.id + 1;
            StringGrid1->Cells[7][contador] = cargado.usuario;
            StringGrid1->Cells[8][contador] = cargado.lubricante;
            StringGrid1->RowCount = StringGrid1->RowCount + 1;
            contador++;
            if (CBgasoil->Checked)
            {
              litros = litros + cargas[i - 1].litros;
            }
            else
            {
              litros = 0;
            }
          }
        }
      }
    }
    //StringGrid1->RowCount=StringGrid1->RowCount-1;
    Lblitros->Caption = litros;
    try
    {
      StringGrid1->FixedRows = 1;
    }
    catch (Exception &Err)
    {
      StringGrid1->RowCount = 1;
      StringGrid1->FixedRows = 0;
    }
    //CBfecha->Text="";
    CBobra->Text = "";
    CBvehiculo->Text = "";
  }        
}
//---------------------------------------------------------------------------

void __fastcall TFConsulta::CBfechaKeyPress(TObject *Sender, char &Key)
{
if (Key == VK_RETURN)
        {                                     //VK_RETURN ES EL ENTER QUE COSA DE LOCOS
                Perform(WM_NEXTDLGCTL, 0, 0); //Con esto el enter actua como el tab.
        }        
}
//---------------------------------------------------------------------------

void __fastcall TFConsulta::CBfecha2KeyPress(TObject *Sender, char &Key)
{
if (Key == VK_RETURN)
        {                                     //VK_RETURN ES EL ENTER QUE COSA DE LOCOS
                Perform(WM_NEXTDLGCTL, 0, 0); //Con esto el enter actua como el tab.
        }
}
//---------------------------------------------------------------------------

