//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
//---------------------------------------------------------------------------
USEFORM("principal.cpp", Fprincipal);
USEFORM("imprimir.cpp", Fprint);
USEFORM("cargachofer.cpp", Fchofer);
USEFORM("cargavehiculo.cpp", Fvehiculos);
USEFORM("cargaobra.cpp", Fobras);
USEFORM("Promedio.cpp", Fpromedio);
USEFORM("modificarchofer.cpp", Fmodificarchofer);
USEFORM("modificarvehiculo.cpp", Fmvehiculo);
USEFORM("Cargam.cpp", Fcargam);
USEFORM("Login.cpp", Flogin);
USEFORM("usuarios.cpp", Fusuario);
USEFORM("modificarusuario.cpp", Fmusuario);
USEFORM("Stock.cpp", Fstock);
USEFORM("consulta.cpp", FConsulta);
USEFORM("modificarobra.cpp", Fmobra);
USEFORM("buscar.cpp", Fbuscar);
//---------------------------------------------------------------------------
WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
        try
        {
                 Application->Initialize();
                 Application->Title = "Carga Combustible";
                 Application->CreateForm(__classid(TFlogin), &Flogin);
                 Application->CreateForm(__classid(TFprint), &Fprint);
                 Application->Run();
        }
        catch (Exception &exception)
        {
                 Application->ShowException(&exception);
        }
        catch (...)
        {
                 try
                 {
                         throw Exception("");
                 }
                 catch (Exception &exception)
                 {
                         Application->ShowException(&exception);
                 }
        }
        return 0;
}
//---------------------------------------------------------------------------