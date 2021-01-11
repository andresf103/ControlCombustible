#ifndef FUNCIONES_H
#define FUNCIONES_H
#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <cstdlib>
#include <math.h>
#include <vector>
#include <iomanip>
#include <utility>   // std::pair
#include <stdexcept> // std::runtime_error
#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include <vcl.h>
#include <Grids.hpp>
#pragma hdrstop
extern AnsiString direccion_global;
extern AnsiString dir_carga;
extern AnsiString dir_cargal;
extern AnsiString dir_chofer;
extern AnsiString dir_vehiculo;
extern AnsiString dir_obra;
extern AnsiString dir_usuario;

using namespace std;

void limpiar(TEdit *Sender)
{
	Sender->Text = "";
}

char *mayuscula(char *a)
{
	String b = a;
	for (int i = 0; i < b.Length(); i++)
	{
		a[i] = (char)toupper(a[i]);
	}
	return a;
}

char *encriptar(char *a)
{
	String b = a;
	for (int i = 0; i < b.Length(); i++)
	{
		a[i] = a[i] + 2;
	}
	return a;
}
// clase Stock para guardar los lubricantes y demas y llevar un conteo de cuanto queda, cuando ingresa o egresa
class Stock
{
private:
	char descripcion[50];
	float cant_stock;

public:
	void set_cantstock(float);
	void set_descripcion(char *);
	float get_cantstock();
	char *get_descripcion();
	void sumar(float);
	void restar(float);
};

void Stock::set_cantstock(float _cant_stock)
{
	cant_stock = _cant_stock;
}

void Stock::set_descripcion(char *_descripcion)
{
	strcpy(descripcion, _descripcion);
}

float Stock::get_cantstock()
{
	return cant_stock;
}

char *Stock::get_descripcion()
{
	char *a = descripcion;
	return a;
}

void Stock::sumar(float a)
{
	cant_stock = cant_stock + a;
}

void Stock::restar(float b)
{
	cant_stock = cant_stock - b;
}
// fin clase Stock
class Stockantigua
{
private:
	char descripcion[50];
	int cant_stock;

public:
	void set_cantstock(int);
	void set_descripcion(char *);
	int get_cantstock();
	char *get_descripcion();
	void sumar(int);
	void restar(int);
};

void Stockantigua::set_cantstock(int _cant_stock)
{
	cant_stock = _cant_stock;
}

void Stockantigua::set_descripcion(char *_descripcion)
{
	strcpy(descripcion, _descripcion);
}

int Stockantigua::get_cantstock()
{
	return cant_stock;
}

char *Stockantigua::get_descripcion()
{
	char *a = descripcion;
	return a;
}

void Stockantigua::sumar(int a)
{
	cant_stock = cant_stock + a;
}

void Stockantigua::restar(int b)
{
	cant_stock = cant_stock - b;
}
// fin clase Stock

//creamos el archivo stock que llevaria el conteo de todo

/*Creamos la estructura para los usuarios del sistema*/
struct susuario
{
	int id;
	char usuario[30];
	char password[20];
	bool admin;
};
extern susuario usuario;
/*Fin estructura Usuarios*/

/*creamos una estructura que es igual a una clase pero con todos sus elementos publicos*/
/*estructura auxiliar para rescatar datos ahora que le agregamos el usuario*/
struct santiguacarga
{
	int id;
	int litros;
	long kilometros;
	char patente[8];
	char chofer[30];
	char destino[20];
	char fecha[11];
};
/*fin estructura auxiliar*/

/*creamos una estructura que es igual a una clase pero con todos sus elementos publicos*/
struct scarga
{
	int id;
	int litros;
	long kilometros;
	char patente[8];
	char chofer[30];
	char destino[20];
	char fecha[11];
	char usuario[30];
};

/* Estructura de datos de lubricante */
struct slubricante
{
	int id;
	char lubricante[30]; /*Unica variante con respecto a la carga de combustible*/
	char presentacion[10];
};
/*FIN Estructura de datos de lubricante */

/* Estructura de datos para cargas de lubricante */
struct scargalubricanteantigua
{
	int id;
	int litros;
	char lubricante[30]; /*Unica variante con respecto a la carga de combustible*/
	long kilometros;
	char patente[8];
	char chofer[30];
	char destino[20];
	char fecha[11];
	char usuario[30];
};
/* Estructura de datos para cargas de lubricante */
struct scargalubricante
{
	int id;
	float litros;
	char lubricante[30]; /*Unica variante con respecto a la carga de combustible*/
	long kilometros;
	char patente[8];
	char chofer[30];
	char destino[20];
	char fecha[11];
	char usuario[30];
};
/*FIN Estructura de datos para cargas de lubricante */

/*funcion para igualar una carga de lubricantes a uno de gasoil*/
scargalubricante igual(scarga un)
{
	scargalubricante a;
	strcpy(a.chofer, un.chofer);
	strcpy(a.destino, un.destino);
	strcpy(a.fecha, un.fecha);
	a.id = un.id;
	a.kilometros = un.kilometros;
	a.litros = un.litros;
	strcpy(a.lubricante, "GAS OIL");
	strcpy(a.patente, un.patente);
	strcpy(a.usuario, un.usuario);
	return a;
};
//creamos la estructura chofer
struct schofer
{
	int id;				 //id del chofer
	char chofer[30];	 //nombre y apellido
	char id_vehiculo[8]; //patente del vehiculo asignado
};
//creamos la estructura vehiculo
struct svehiculo
{
	int id;			   //lo usamos alpedo
	char patente[8];   //patente
	char vehiculo[30]; //descripcion
	int consumo;	   //consumo en litros cada 100km
};
//creamos la estructura Obra
struct sobra
{
	int id;			  //lo usamos alpedo.
	char destino[35]; // Nombre de la obra � lugar.
	int distancia;	  // Distancia desde nuestro obrador hasta ese lugar.
};

struct sfecha
{
	char fecha[11];
};

/* funcion que compara dos fechas guardadas como texto
0 iguales
-1 el de la izquierda es menor
1  el de la izquierda es mayor
*/
int compararFecha(char *fecha1, char *fecha2) // char de 11 caracteres
{
	int anio;
	int mes;
	int dia;
	int anio2;
	int mes2;
	int dia2;
	std::stringstream cadena;
	cadena << fecha1[0] << fecha1[1];
	dia = atoi(cadena.str().c_str());
	cadena.str("");
	cadena << fecha1[3] << fecha1[4];
	mes = atoi(cadena.str().c_str());
	cadena.str("");
	cadena << fecha1[6] << fecha1[7] << fecha1[8] << fecha1[9];
	anio = atoi(cadena.str().c_str());
	cadena.str("");

	cadena << fecha2[0] << fecha2[1];
	dia2 = atoi(cadena.str().c_str());
	cadena.str("");
	cadena << fecha2[3] << fecha2[4];
	mes2 = atoi(cadena.str().c_str());
	cadena.str("");
	cadena << fecha2[6] << fecha2[7] << fecha2[8] << fecha2[9];
	anio2 = atoi(cadena.str().c_str());

	unsigned long a;
	unsigned long b;

	a = anio * 365 + mes * 30 + dia;
	b = anio2 * 365 + mes2 * 30 + dia2;
	return (a > b) - (a < b); // lanza 0 si son iguales 1 si a es mayor y -1 si a es menor
}

/*Funcion que ordena una fecha en un arreglo de fechas*/
vector<sfecha> ordenarFecha(vector<sfecha> fechasl, vector<sfecha> fechas)
{
	vector<sfecha> nuevasfechas;
	/*ponemos todos los datos de las fechas en el mismo vector*/
	for (int j = 0; j < (int)fechas.size(); j++)
	{
		nuevasfechas.push_back(fechas[j]);
	}
	for (int i = 0; i < (int)fechasl.size(); i++)
	{
		nuevasfechas.push_back(fechasl[i]);
	}
	/*comparamos todas las fechas contra todas las fechas*/
	for (int i = 0; i < (int)nuevasfechas.size(); i++)
	{
		for (int j = 0; j < (int)nuevasfechas.size(); j++)
		{
			if (0 == compararFecha(nuevasfechas[i].fecha, nuevasfechas[j].fecha))
			{ /*si encuentra que son iguales lo elimina */
				if (i != j)
				{
					nuevasfechas.erase(nuevasfechas.begin() + j);
				}
			}
		}
	}
	return nuevasfechas;
}

struct spromedio
{
	char patente[7];
	long kminicial;
	long kmfinal;
	long litros;
	float rinde;
};
// funcion que nos devuelve la cantidad de bytes que tiene un archivo
long sizearch(char *archivo)
{
	long bytes;
	fstream fichero(archivo);
	fichero.seekg(0, ios::end);
	bytes = fichero.tellg();
	fichero.close();
	return bytes;
}

double round(double r, int n_digit)
{
	int n = pow(10, n_digit);
	r = ((float)((int)(r * n + 0.5))) / n;
	return (r);
}

// funcion tipo template que lee de un archivo binario y coloca los datos en un vector del tipo que se le pase
template <typename T>
vector<T> leer(char *archivos)
{
	vector<T> cargas;
	T carga;
	ifstream archivo(archivos, ios::binary);
	for (int i = 0; i < (sizearch(archivos) / (int)sizeof(carga)); i++)
	{
		archivo.read((char *)&carga, sizeof(carga));
		cargas.push_back(carga);
	};
	archivo.close();
	return cargas;
}
//"carga_combustible.dat"
//funcion del tipo template que escribe una estructura de datos en un archivo binario.
template <typename T>
int escribir(T carga, char *archivos)
{ /*devuelve la cantidad registros del archivo*/
	int contador = 0;
	vector<T> cargas;
	cargas = leer<T>(archivos);
	ofstream archivo(archivos, ios::binary | ios::trunc);
	if (cargas.size() == 0)
	{ /*si el vector no tiene nada*/
		archivo.write((char *)&carga, sizeof(carga));
	}
	else
	{ /* si el vector tiene muchos, va hasta el final y agrega*/
		cargas.push_back(carga);
		for (int i = 0; i < (int)cargas.size(); i++)
		{
			cargas[i].id = i;
			archivo.write((char *)&cargas[i], sizeof(carga));
		}
	}
	archivo.close();
	contador = cargas.size();
	return contador;
}
/*Modificar datos cargados*/
void escribirstock(Stock _stock)
{

	vector<Stock> cargas;
	cargas = leer<Stock>("stock.dat");
	ofstream archivo("stock.dat", ios::binary | ios::trunc);
	if (cargas.size() == 0)
	{ /*si el vector no tiene nada*/
		archivo.write((char *)&_stock, sizeof(_stock));
	}
	else
	{
		bool found; /* si el vector tiene muchos, va hasta el final y agrega*/
		for (int i = 0; i < (int)cargas.size(); i++)
		{
			std::string a = mayuscula(cargas[i].get_descripcion());
			std::string b = mayuscula(_stock.get_descripcion());
			if (a == b)
			{
				cargas[i].set_cantstock(_stock.get_cantstock());
				found = true;
			}
		}

		if (!found)
		{
			ShowMessage(cargas.size());
			cargas.push_back(_stock);
			ShowMessage(cargas.size());
		}

		for (int i = 0; i < (int)cargas.size(); i++)
		{
			archivo.write((char *)&cargas[i], sizeof(cargas[i]));
		}
	}
	archivo.close();
}

Stock leerstock(Stock _stock)
{
	vector<Stock> cargas;
	cargas = leer<Stock>("stock.dat");
	for (int i = 0; i < (int)cargas.size(); i++)
	{
		std::string a = mayuscula(cargas[i].get_descripcion());
		std::string b = mayuscula(_stock.get_descripcion());
		if (a == b)
		{
			return cargas[i];
		}
	}
	Stock a;
	return a;
}

vector<svehiculo> leer_M(svehiculo modificado, char *archivos)
{
	vector<svehiculo> cargas;
	svehiculo carga;
	ifstream archivo(archivos, ios::binary);
	for (int i = 0; i < (sizearch(archivos) / (int)sizeof(carga)); i++)
	{
		archivo.read((char *)&carga, sizeof(carga));
		if (0 == strcmp(carga.patente, modificado.patente))
		{
			if (modificado.vehiculo[0] != '%')
			{
				cargas.push_back(modificado);
			}
		}
		else
		{
			cargas.push_back(carga);
		}
	};
	archivo.close();
	return cargas;
}

int modificar(svehiculo modificado, char *archivos)
{
	int contador = 0;
	vector<svehiculo> cargas;
	cargas = leer_M(modificado, archivos);
	ofstream archivo(archivos, ios::binary | ios::trunc);
	if (cargas.size() == 0)
	{
		archivo.write((char *)&modificado, sizeof(modificado));
	}
	else
	{
		for (int i = 0; i < (int)cargas.size(); i++)
		{
			cargas[i].id = i;
			archivo.write((char *)&cargas[i], sizeof(modificado));
		}
	};
	archivo.close();
	contador = cargas.size();
	return contador;
}

bool eliminar_vehiculo(svehiculo eliminar)
{
	bool eliminado = false;
	vector<svehiculo> cargas;
	cargas = leer_M(eliminar, dir_vehiculo.c_str());
	ofstream archivo(dir_vehiculo.c_str(), ios::binary | ios::trunc);
	for (int i = 0; i < (int)cargas.size(); i++)
	{
		if (eliminar.id == cargas[i].id)
		{
			eliminado = true;
		}
		else
		{
			cargas[i].id = i;
			archivo.write((char *)&cargas[i], sizeof(cargas[i]));
		}
	}

	return eliminado;
}

/*FIN Modificar datos cargados*/

/*recuperar datos vehiculo*/
svehiculo datosvehiculo(char *patente)
{
	svehiculo vehiculo;
	vector<svehiculo> cargas;
	cargas = leer<svehiculo>(dir_vehiculo.c_str());
	for (int i = (int)cargas.size(); i >= 0; i--)
	{
		if (0 == strcmp(cargas[i].patente, patente))
		{
			vehiculo = cargas[i];
		}
	}
	return vehiculo;
}
/*FIN recuperar datos vehiculo*/

bool cadenaencontrada(string cadena, string subcadena)
{
	bool encontrado = false;
	stringstream sscadena(cadena);
	if (std::strstr(cadena.c_str(), subcadena.c_str()))
	{
		encontrado = true;
	}
	return encontrado;
}
/* Le ingreso una palabra
y tira un vector de vehiculo resultante
 */
vector<svehiculo> listaVehiculos(string edit)
{
	/*leemos todos los vehiculos del arhivo*/
	vector<svehiculo> cargas;
	vector<svehiculo> resultado;
	string cadena,patente;
	cargas = leer<svehiculo>(dir_vehiculo.c_str());
	/*ahora comparamos el texto de la descripcion con el edit*/
	for (int i = (int)cargas.size(); i >= 0; i--)
	{       patente=mayuscula(cargas[i].patente);
		cadena = mayuscula(cargas[i].vehiculo);
		if ((cadenaencontrada(cadena, edit))||cadenaencontrada(patente,edit))
		{
			/*y guardamos las coincidencias en otro vector*/
			resultado.push_back(cargas[i]);
		}
	}
	return resultado;
}

//funcion que exporta los datos del archivo carga a formato .cvs
int exportar_carga(char *archivos, char *archivo2)
{
	vector<scarga> cargas = leer<scarga>(archivos);
	svehiculo vehiculo;
	ShowMessage(cargas.size());
	ofstream archivo(archivo2);
	int contador = 0;
	//archivo<<"id"<<';'<<"litros"<<';'<<"KM"<<';'<<"Patente"<<';'<<"Descripcion vehicular"<<';'<<"chofer"<<';'<<"destino"<<';'<<"usuario"<<';'<<"fecha"<<endl;
	archivo << "Patente" << ';' << "Vehiculo" << ';' << "KM" << ';' << "litros" << ';' << "Vale" << ';' << "chofer" << ';' << "Firma" << ';' << "Fecha" << ';' << "Obra" << endl;
	if (cargas.size() == 0)
	{
		svehiculo vehiculo = datosvehiculo(cargas[0].patente);
		//archivo<<cargas[0].id<<';'<<cargas[0].litros<<';'<<cargas[0].kilometros<<';'<<cargas[0].patente<<';'<<vehiculo.vehiculo<<';'<<cargas[0].chofer<<';'<<cargas[0].destino<<';'<<cargas[0].usuario<<';'<<cargas[0].fecha<<endl;
		archivo << cargas[0].patente << ';' << vehiculo.vehiculo << ';' << cargas[0].kilometros << ';' << cargas[0].litros << ';' << cargas[0].id << ';' << cargas[0].chofer << ';' << cargas[0].usuario << ';' << cargas[0].fecha << ';' << cargas[0].destino << endl;
	}
	else
	{
		for (int i = 0; i < (int)cargas.size(); i++)
		{
			vehiculo = datosvehiculo(cargas[i].patente);
			archivo << cargas[i].patente << ';' << vehiculo.vehiculo << ';' << cargas[i].kilometros << ';' << cargas[i].litros << ';' << cargas[i].id << ';' << cargas[i].chofer << ';' << cargas[i].usuario << ';' << cargas[i].fecha << ';' << cargas[i].destino << endl;
			//archivo<<cargas[i].id<<';'<<cargas[i].litros<<';'<<cargas[i].kilometros<<';'<<cargas[i].patente<<';'<<vehiculo.vehiculo<<';'<<cargas[i].chofer<<';'<<cargas[i].destino<<';'<<cargas[i].usuario<<';'<<cargas[i].fecha<<endl;
		}
	};
	archivo.close();
	//system("export.csv");
	contador = cargas.size();
	return contador;
}

int exportar_cargal(char *archivos, char *archivo2)
{
	vector<scargalubricante> cargas = leer<scargalubricante>(archivos);
	svehiculo vehiculo;
	ShowMessage(cargas.size());
	ofstream archivo(archivo2);
	int contador = 0;
	//archivo<<"id"<<';'<<"litros"<<';'<<"KM"<<';'<<"Patente"<<';'<<"Descripcion vehicular"<<';'<<"chofer"<<';'<<"destino"<<';'<<"usuario"<<';'<<"fecha"<<endl;
	archivo << "Patente" << ';' << "Vehiculo" << ';' << "KM" << ';' << "Lubricante" << ';' << "litros" << ';' << "Vale" << ';' << "chofer" << ';' << "Firma" << ';' << "Fecha" << ';' << "Obra" << endl;
	if (cargas.size() == 0)
	{
		svehiculo vehiculo = datosvehiculo(cargas[0].patente);
		//archivo<<cargas[0].id<<';'<<cargas[0].litros<<';'<<cargas[0].kilometros<<';'<<cargas[i].lubricante<<';'<<cargas[0].patente<<';'<<vehiculo.vehiculo<<';'<<cargas[0].chofer<<';'<<cargas[0].destino<<';'<<cargas[0].usuario<<';'<<cargas[0].fecha<<endl;
		archivo << cargas[0].patente << ';' << vehiculo.vehiculo << ';' << cargas[0].kilometros << ';' << cargas[0].lubricante << ';' << cargas[0].litros << ';' << cargas[0].id << ';' << cargas[0].chofer << ';' << cargas[0].usuario << ';' << cargas[0].fecha << ';' << cargas[0].destino << endl;
	}
	else
	{
		for (int i = 0; i < (int)cargas.size(); i++)
		{
			vehiculo = datosvehiculo(cargas[i].patente);
			archivo << cargas[i].patente << ';' << vehiculo.vehiculo << ';' << cargas[i].kilometros << ';' << cargas[i].lubricante << ';' << cargas[i].litros << ';' << cargas[i].id << ';' << cargas[i].chofer << ';' << cargas[i].usuario << ';' << cargas[i].fecha << ';' << cargas[i].destino << endl;
			//archivo<<cargas[i].id<<';'<<cargas[i].litros<<';'<<cargas[i].kilometros<<';'<<cargas[i].patente<<';'<<vehiculo.vehiculo<<';'<<cargas[i].chofer<<';'<<cargas[i].destino<<';'<<cargas[i].usuario<<';'<<cargas[i].fecha<<endl;
		}
	};
	archivo.close();
	//system("export.csv");
	contador = cargas.size();
	return contador;
}

//funcion que exporta los datos del archivo chofer a formato .cvs
int exportar_chofer(char *archivos, char *archivo2)
{
	vector<schofer> cargas = leer<schofer>(archivos);
	ofstream archivo(archivo2);
	int contador = 0;
	archivo << "id" << ';' << "Chofer" << ';' << "Patente" << endl;
	if (cargas.size() == 0)
	{
		archivo << cargas[0].id << ';' << cargas[0].chofer << ';' << cargas[0].id_vehiculo << endl;
	}
	else
	{
		for (int i = 0; i < (int)cargas.size(); i++)
		{

			archivo << cargas[i].id << ';' << cargas[i].chofer << ';' << cargas[i].id_vehiculo << endl;
		}
	};
	archivo.close();
	contador = cargas.size();
	return contador;
}
//funcion que exporta los datos del archivo vehiculo a formato .cvs
int exportar_vehiculo(char *archivos, char *archivo2)
{
	vector<svehiculo> cargas = leer<svehiculo>(archivos);
	ofstream archivo(archivo2);
	int contador = 0;
	archivo << "id" << ';' << "Patente" << ';' << "Vehiculo" << ';' << "Consumo" << endl;
	if (cargas.size() == 0)
	{
		archivo << cargas[0].id << ';' << cargas[0].patente << ';' << cargas[0].vehiculo << ';' << cargas[0].consumo << endl;
	}
	else
	{
		for (int i = 0; i < (int)cargas.size(); i++)
		{

			archivo << cargas[i].id << ';' << cargas[i].patente << ';' << cargas[i].vehiculo << ';' << cargas[i].consumo << endl;
		}
	};
	archivo.close();
	//system("export.csv");
	contador = cargas.size();
	return contador;
}

/*ordenamos por patente*/
vector<scarga> ordenar_carga_patente(vector<scarga> lista)
{
	scarga temp;
	for (int i = 1; i < (int)lista.size(); i++)
	{
		for (int j = 0; j < (int)lista.size() - 1; j++)
		{
			if (0 < strcmp(lista[j + 1].patente, lista[j].patente))
			{
				temp = lista[j];
				lista[j] = lista[j + 1];
				lista[j + 1] = temp;
			}
		}
	}
	return lista;
}
vector<schofer> ordenar_chofer(vector<schofer> lista)
{
	schofer temp;
	for (int i = 1; i < (int)lista.size(); i++)
	{
		for (int j = 0; j < (int)lista.size() - 1; j++)
		{
			if (0 < strcmp(lista[j + 1].chofer, lista[j].chofer))
			{
				temp = lista[j];
				lista[j] = lista[j + 1];
				lista[j + 1] = temp;
			}
		}
	}
	return lista;
}
vector<sobra> ordenar_obra(vector<sobra> lista)
{
	sobra temp;
	for (int i = 1; i < (int)lista.size(); i++)
	{
		for (int j = 0; j < (int)lista.size() - 1; j++)
		{
			if (0 < strcmp(lista[j + 1].destino, lista[j].destino))
			{
				temp = lista[j];
				lista[j] = lista[j + 1];
				lista[j + 1] = temp;
			}
		}
	}
	return lista;
}
vector<svehiculo> ordenar_vehiculo(vector<svehiculo> lista)
{
	svehiculo temp;
	for (int i = 1; i < (int)lista.size(); i++)
	{
		for (int j = 0; j < (int)lista.size() - 1; j++)
		{
			if (0 < strcmp(lista[j + 1].patente, lista[j].patente))
			{
				temp = lista[j];
				lista[j] = lista[j + 1];
				lista[j + 1] = temp;
			}
		}
	}
	return lista;
}

/* he aqui la formula Lsugerencia->Caption=distancia*2*consumo*0.01; */
int sugerencia(char *patente, char *destino)
{
	vector<svehiculo> vehiculos;
	vector<sobra> obras;
	vehiculos = leer<svehiculo>("vehiculos.dat");
	obras = leer<sobra>("obras.dat");
	int consumo = 0;
	int distancia = 0;
	for (int i = 0; i < (int)vehiculos.size(); i++)
	{

		if (0 == strcmp(vehiculos[i].patente, patente))
		{
			consumo = vehiculos[i].consumo;
		}
	}
	for (int j = 0; j < (int)obras.size(); j++)
	{

		if (0 == strcmp(obras[j].destino, destino))
		{
			distancia = obras[j].distancia;
		}
	}
	int resultado = distancia * 2 * consumo * 0.01;
	return resultado;
}

/*para sacar los promedios de consumo
Ejemplo:
Queremos buscar desde el 01/10/2015 al 29/10/2015
Comparamos la primer fecha del archivo 05/05/2015 como es menor al minimo
no se computa. si es mayor al maximo tampoco
cada nueva linea deber�a recorrer buscando en el vector si ya existe
si no existe se agrega y se ponen kminicial y final iguales y se pone la
cant de litros que cargo, si ya existe se actualiza el kmfinal y se suma la cant litros.
*/
vector<spromedio> promedio(char *fecha1, char *fecha2)
{
	bool match = false;
	spromedio unpromedio;
	vector<spromedio> promedio;
	vector<scarga> cargas;
	cargas = leer<scarga>("cargas_combustible.dat");
	cargas = ordenar_carga_patente(cargas); //Ordenamos las cargas por patente sin alterar el archivo de origen
	for (int i = 0; i < (int)cargas.size(); i++)
	{
		if (1 != compararFecha(fecha1, cargas[i].fecha))
		{ //SI LA FECHA ACTUAL ES MAYOR QUE LA FECHA INICIAL
			if (-1 != compararFecha(fecha2, cargas[i].fecha))
			{ //SI LA FECHA FINAL ES MENOR A LA FECHA A COMPARAR
				for (int j = 0; j < (int)promedio.size(); j++)
				{ //DESDE 0 HASTA QUE QUE LLEGUE AL ULTIMO ELEMENTO DEL VECTOR PROMEDIO
					if (0 == strcmp(promedio[j].patente, cargas[i].patente))
					{ // COMPARAMOS QUE EL ELEMENTO DEL VECTOR PROMEDIO SEA EL DE CARGA
						if (cargas[i].kilometros < promedio[j].kminicial)
						{												  //SI EL KILOMETRAJE QUE ESTAMOS VIENDO ES MENOR AL KILOMETRAJE MENOR HASTA AHORA
							promedio[j].kminicial = cargas[i].kilometros; //GUARDAMOS EL NUEVO VALOR MENOR
						}
						if (cargas[i].kilometros > promedio[j].kmfinal)
						{ //SI EL KILOMETRAJE QUE ESTAMOS VIENDO ES MAYOR QUE EL KILOMETRAJE MAYOR
							if (0 == strcmp(cargas[i + 1].patente, cargas[i].patente))
							{ //VEMOS SI LA SIGUIENTE FECHA ES IGUAL
								if (1 == compararFecha(cargas[i + 1].fecha, cargas[i].fecha))
								{ //SI LA FECHA SIGUIENTE ES MAYOR A LA ACTUAL
									//C�mo est� todo ordenado, podemos ver el siguiente con el anterior
									/* if((cargas[i-1].kilometros>cargas[i].kilometros)&&(cargas[i+1].kilometros>cargas[i].kilometros)){
                                                                                if(0==strcmp(cargas[i].patente,cargas[i-1].patente)){
                                                                                        cargas[i].kilometros=cargas[i-1].kilometros;
                                                                                }
                                                                        }*/
									if ((cargas[i + 1].kilometros < cargas[i].kilometros) && (cargas[i + 2].kilometros < cargas[i].kilometros))
									{													 //SI EL KM SIGUIENTE Y EL SIGUIENTE SONMENORES QUE LA ACTUAL
										cargas[i].kilometros = cargas[i + 1].kilometros; //A KM ACTUAL LE ASIGNAMOS EL VALOR DEL SIGUIENTE
									}
								}
							}
							promedio[j].kmfinal = cargas[i].kilometros;
						}
						promedio[j].litros = promedio[j].litros + cargas[i].litros;
						if (promedio[j].kminicial == 1)
						{
							promedio[j].kminicial = promedio[j].kmfinal;
						}
						if (promedio[j].litros == 0)
						{
							promedio[j].litros = 1;
						}
						if (promedio[j].kmfinal != promedio[j].kminicial)
						{ // CALCULO DEL RINDE
							promedio[j].rinde = round(((float)100 / ((float)(promedio[j].kmfinal - promedio[j].kminicial) / (float)promedio[j].litros)), 0);
						}
						else
						{
							promedio[j].rinde = (float)(promedio[j].kmfinal - promedio[j].kminicial) / (float)promedio[j].litros;
						}

						//FIN DEL CALCULO DEL RINDE
						match = true; // SI ES LA PRIMERA COMPARACION ESTO VA A DAR FALSO
					}
				}
				if (!match)
				{
					strcpy(unpromedio.patente, cargas[i].patente);
					unpromedio.kminicial = cargas[i].kilometros;
					unpromedio.kmfinal = cargas[i].kilometros;
					if (cargas[i].litros == 0)
					{
						cargas[i].litros = 1;
					}
					unpromedio.litros = cargas[i].litros;
					if (unpromedio.kmfinal != unpromedio.kminicial)
					{
						unpromedio.rinde = ((float)100 / ((unpromedio.kmfinal - unpromedio.kminicial) / unpromedio.litros));
					}
					else
					{
						unpromedio.rinde = (unpromedio.kmfinal - unpromedio.kminicial) / unpromedio.litros;
					}
					promedio.push_back(unpromedio); // COMO ES LA PRIMERA VEZ QUE SE ENCUENTRA ESA PATENTE SE CREA UN NODOZ
				}
				match = false;
			}
		}
	}
	return promedio;
	/*conseguir el vector de las cargas*/
	/*comparar la fecha y recuperar*/
}

/*FIN*/

scarga anterior(char *patente)
{
	scarga anterior;
	anterior.kilometros = 0;
	anterior.chofer[0] = '\0';
	anterior.destino[0] = '\0';
	vector<scarga> cargas;
	cargas = leer<scarga>(dir_carga.c_str());
	if (cargas.size() < 1)
	{
	}
	else
	{
		for (int i = (int)cargas.size(); i >= 0; i--)
		{
			if (anterior.kilometros == 0)
			{
				if (0 == strcmp(cargas[i].patente, patente))
				{
					anterior = cargas[i];
				}
			}
		}
	}
	return anterior;
}
scargalubricante anteriorl(char *patente)
{
	scargalubricante anterior;
	anterior.kilometros = 0;
	anterior.chofer[0] = '\0';
	anterior.destino[0] = '\0';
	vector<scargalubricante> cargas;
	cargas = leer<scargalubricante>(dir_cargal.c_str());
	if (cargas.size() < 1)
	{
	}
	else
	{
		for (int i = (int)cargas.size(); i >= 0; i--)
		{
			if (anterior.kilometros == 0)
			{
				if (0 == strcmp(cargas[i].patente, patente))
				{
					anterior = cargas[i];
				}
			}
		}
	}
	return anterior;
}

/*Buscamos por id y devolvemos los valores*/

scarga buscarid(int id)
{
	scarga por_id;
	ifstream archivo("cargas_combustible.dat", ios::binary);
	archivo.seekg(id * sizeof(por_id), ios::beg);
	archivo.read((char *)&por_id, sizeof(por_id));
	archivo.close();
	return por_id;
}
/*Buscamos por id y devolvemos los valores lubricantes*/

scargalubricante buscaridl(int id)
{
	scargalubricante por_id;
	ifstream archivo("carga_lubricante.dat", ios::binary);
	archivo.seekg(id * sizeof(por_id), ios::beg);
	archivo.read((char *)&por_id, sizeof(por_id));
	archivo.close();
	return por_id;
}

int escribirid(scarga carga, char *archivos, int id)
{ // se necesita abrir de lectura y escritura para poder escribir binariamente.
	fstream archivo("cargas_combustible.dat", ios::in | ios::out | ios::binary);

	archivo.seekp(id * sizeof(carga));
	archivo.write((char *)&carga, sizeof(carga));
	archivo.close();
	return id;
}

int escribiridl(scargalubricante carga, char *archivos, int id)
{
	fstream archivo("carga_lubricante.dat", ios::in | ios::out | ios::binary);
	archivo.seekp(id * sizeof(carga));
	archivo.write((char *)&carga, sizeof(carga));
	archivo.close();
	return id;
}
/*funcion auxiliar para agregar el campo usuario a las cargas anteriores*/
int transformar()
{
	vector<Stockantigua> antiguascargas;
	Stock auxiliar;
	antiguascargas = leer<Stockantigua>("stock.dat");
	ofstream archivo("stock.dat", ios::binary | ios::trunc);
	for (int i = 0; i < (int)antiguascargas.size(); i++)
	{
		auxiliar.set_cantstock(antiguascargas[i].get_cantstock());
		auxiliar.set_descripcion(antiguascargas[i].get_descripcion());
		archivo.write((char *)&auxiliar, sizeof(auxiliar));
	}
	archivo.close();
	int contador = antiguascargas.size();
	return contador;
}

char *quitar_cadena(wchar_t cadena[], int tamanio_cadena)
{
	/*quitamos el tamanio de la cadena mas la barra*/
	tamanio_cadena++;
	int contador;
	contador = 0;
	char *cadena2;
	for (int i = 0; i < MAX_PATH; i++)
	{
		cadena2[i] = cadena[i];
	}
	while (cadena2[contador] != '\0')
	{
		contador++;
	}
	cadena2[contador - tamanio_cadena] = '\0';
	return cadena2;
}
// autosizing stringgrid
void auto_sizing(TStringGrid *a)
{
	int anchocolumnatotal;
	int sumacolumna;
	for (int j = 0; j < a->ColCount; j++)
	{
		int Max = 0;
		int largocolumna = 0;
		for (int i = 0; i < a->RowCount; i++)
		{
			largocolumna = a->Canvas->TextWidth(a->Cells[j][i]);
			if (largocolumna > Max)
			{
				Max = largocolumna;
			}
		}
		a->ColWidths[j] = Max + 15;
		sumacolumna += a->ColWidths[j];
	}

	a->ColWidths[a->ColCount - 1] = a->Width - sumacolumna + 50;
}

/*Acceso Aleatorio a un archivo binario*/
#endif