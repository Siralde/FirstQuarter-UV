/**
 * @file Tarea3.cpp
 *
 * @brief Ejercicio 03: Laboratoria 8, Modifica un fichero.
 *
 * Lee de un fichero de texto su contenido y guárdalo en otro
 * fichero de texto, de manera que se formatee de acuerdo a una reglas establecidas.
 *
 * @version 1
 * @author Aldemaro Gonzalez
 * @date 14/12/2017
 */
#include <string>
#include <fstream>
#include <math.h>
#include <iostream>
using namespace std;

struct Resumen
{
    int num_caracteres, total_palabras, num_frases;
};

bool EsSeparador(char ch);
bool EsSigno (char ch);
/**
 * Funcion principal
 */
int main (void)
{
    Resumen resumen;
    ifstream fichero_lectura;
    ofstream fichero_escritura;
    string texto;
    char ch, ch_anterior = 'a';
    int contador_palabras, contador_frases, contador_carateres;
    
    //Fichero a leer
    fichero_lectura.open("ej3.txt");
    if(!fichero_lectura)
        cout << "Error abriendo el fichero de lectura" << endl;
    else
    {
        //Fichero a escribir
        fichero_escritura.open("ej3_modificado.txt");
        if (!fichero_escritura)
        {
            cout << "Error abriendo el fichero de escritura" << endl;
        }
        else
        {
            while ( fichero_lectura.get (ch) )
            {
                contador_carateres++;
                contador_palabras = EsSigno(ch);
                if ( EsSeparador(ch) )
                    {
                        contador_frases++;
                    }
                
                if (EsSigno(ch_anterior) && ch != ' ')
                {
                    fichero_escritura << ' ' << ch;
                }
                else if (ch_anterior == ' ' && ch == ' ')
                {
                    
                }
                else
                {
                    fichero_escritura << ch;
                }
                
                ch_anterior = ch;
            }
        }
        
        fichero_escritura.close();
        fichero_lectura.close();
        
        cout << endl;
    }
    
    //Guardamos el resumnen en un resgistro
    resumen.num_caracteres = contador_carateres;
    resumen.total_palabras = contador_palabras;
    resumen.num_frases = contador_frases;
    
    //Fichero Resumen Binario
    fichero_escritura.open("ej3_resumen.bin", ios::binary);
    if (!fichero_escritura)
    {
        cout << "Error abriendo el fichero de escritura" << endl;
    }
    else
    {
        fichero_escritura.write ( (char *) (& resumen.num_caracteres), sizeof (resumen.num_caracteres));
        fichero_escritura.write ( (char *) (& resumen.total_palabras), sizeof (resumen.total_palabras));
        fichero_escritura.write ( (char *) (& resumen.num_frases), sizeof (resumen.num_frases) );
    }
    
    fichero_escritura.close();
    
    cout << endl;

    return 0;
}
    


/************************ EsSigno *********************//**
*
* Verifica si el caracter introducido es un signo
*
* @param[in] ch Caracter
*
* @retval true es un signo
* @retval false no es un signo
*
*//**********************************************************/
bool EsSigno (char ch)
{
    bool es_signo = false;
    char coma = ',';
    char punto = '.';
    char punto_coma = ';';
    
    if (ch == coma || ch == punto || ch == punto_coma)
        es_signo = true;
    
    return es_signo;
}

/************************ EsSeparador *********************//**
*
* Verifica si el caracter introducido es un signo
*
* @param[in] ch Caracter
*
* @retval true es un signo
* @retval false no es un signo
*
*//**********************************************************/
bool EsSeparador(char ch)
{
    bool es_separador = false;
    char salto = '\n';
    char tabulador = '\t';
    char espacio = ' ';
    
    if (ch == es_separador || ch == tabulador || ch == salto)
        es_separador = true;
    
    return es_separador;
}

