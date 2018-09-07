/**
 * @file b8_1_gris.cpp
 *
 * @brief Ejercicio 01: Boletin 8, Convertidor de ficheros.
 *
 * Este programa convierte un fichero de Tipo ASCCII y lo convierte en binario
 *
 * @version 1
 * @author Aldemaro Gonzalez
 * @date 10/01/2018
 */
#include <fstream>
#include <string>
#include <iostream>
using namespace std;


void Presentacion (void);
void ConvertirFichero (string nombre);

int main (void)
{
    string nombre;
    
    Presentacion ();
    
    cout << "Dame nombre del fichero original: ";
    cin >> nombre;
    
    ConvertirFichero (nombre);
    
    return 0;
}

/******************** MostrarCliente *********************//**
*
* Presenta el programa
*
*//**********************************************************/
void Presentacion (void)
{
    cout << "Este programa convierte un fichero de Tipo ASCCII y lo convierte en binario \n";
}

/************************** MostrarCliente ******************************//**
*
* Muestra la informacion de un cliente
*
* @param[in] nombre Nombre del fichero
*
*//********************************************************************/
void ConvertirFichero (string nombre)
{
    ifstream ppm;   //Fichero a leer
    ofstream pgm;   //Fichero a escribir
    string fichero_ppm, fichero_pgm;
    string magic_num;
    int width_ancho, height_altura, max_value, rojo, verde, azul, sumatoria, media, i;
    
    fichero_ppm = nombre + ".ppm";
    fichero_pgm = nombre + ".pgm";
    
    ppm.open(fichero_ppm);
    if(!ppm)
    {
        cout << "Error abriendo el fichero de lectura (ppm)" << endl;
    }
    else
    {
        pgm.open(fichero_pgm , ios::binary);
        if (!pgm)
        {
            cout << "Error abriendo el fichero de escritura (pgm)" << endl;
        }
        else
        {
            ppm >> magic_num;
            pgm << "P5" << endl;
            ppm >> width_ancho;
            pgm << width_ancho << " ";
            ppm >> height_altura;
            pgm << height_altura << endl;
            ppm >> max_value;
            pgm << max_value << endl;
            
            for (i = 0; i < (width_ancho * height_altura); i++)
            {
                ppm >> rojo;
                ppm >> verde;
                ppm >> azul;
                sumatoria = rojo + verde + azul;
                media = sumatoria / 3;
                pgm.write( (char *) (& sumatoria), sizeof (sumatoria));
            }
            pgm.close();
        }
        ppm.close();
    }
    
    return;
}
