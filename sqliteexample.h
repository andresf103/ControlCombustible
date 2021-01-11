#include <iostream>
#include <iomanip>
#include <string>
#include <stdio.h>
#include <cstdlib>
#include <sqlite3.h> /* incluimos la cabecera de la libreria libsqlite3*/
 
using namespace std;
 
int main(int argc, char *argv[])
{
    sqlite3 *db;                /* Definimos un puntero a la base de datos */
    sqlite3_stmt *resultado;    /* Definimos un puntero a la respuesta de la consulta*/
    int msg;                    /* valor de retorno de las sentencias */
    string sentencia;           /* string para las sentencias */
    const char* siguiente;      /* puntero a la siguiente sentencia */
    char* error;                /* variable para el mensaje de error */
 
    msg = sqlite3_open("pucara.db",&db);    /* creo el archivo para la base de datos */
    if (msg!=SQLITE_OK)                     /* verifico si hay error */
    {
        cout << "Error al crear la base de datosn" << endl;
        exit(1);
    }
 
    sentencia = "DROP TABLE IF EXISTS hosts;";  /* compongo un sentencia para crear la base de datos*/
    sentencia += "CREATE TABLE hosts (id INTEGER PRIMARY KEY AUTOINCREMENT NOT NULL, ip TEXT NOT NULL, mac TEXT NOT NULL, nombre TEXT, estado INTEGER NOT NULL, web INTEGER NOT NULL, puertos TEXT);";
    msg = sqlite3_exec(db,sentencia.c_str(),NULL,NULL,&error);  /* ejecuto la sentencia */
    if (msg!=SQLITE_OK)     /* verifico si hay error */
    {
        cout << error << endl;
        exit(2);
    }

    sentencia = "insert into hosts (id, ip, mac, nombre, estado, web, puertos) values ('1', '192.168.0.1', '00:27:0e:09:2d:4d', 'fermat', '1', '2', '22, 443, 1863');"; /* compongo una nueva sentencias */
    msg = sqlite3_exec(db,sentencia.c_str(),NULL,NULL,&error);  /* ejecuto la sentencia */
    if (msg!=SQLITE_OK)     /* verifico si hay error */
    {
        cout << error << endl;
        exit(2);
    }
 
    sentencia = "SELECT * FROM hosts ORDER BY ip;"; /* compongo una sentencia de consulta */
    msg = sqlite3_prepare(db,sentencia.c_str(),sentencia.length(),&resultado,&siguiente);   /* ejecuto la sentencia */
    if (msg!=SQLITE_OK) /* verifico si hay error */
    {
        cout << "Error en la consulta" << endl;
        exit(3);
    }
 
    while (sqlite3_step(resultado)==SQLITE_ROW) /* imprimo el resultado de la consulta */
    {
        cout << sqlite3_column_int(resultado, 0) << " | ";
        cout << sqlite3_column_text(resultado, 1) << " | ";
        cout << sqlite3_column_text(resultado, 2) << " | ";
        cout << sqlite3_column_text(resultado, 3) << " | ";
        cout << sqlite3_column_int(resultado, 4) << " | ";
        cout << sqlite3_column_int(resultado, 5) << " | ";
        cout << sqlite3_column_text(resultado, 6) << endl;
    }
 
    sqlite3_close(db);      /* cierro la base de datos*/
    return 0;
 