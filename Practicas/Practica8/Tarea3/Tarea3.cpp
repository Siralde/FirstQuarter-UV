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

bool EsSigno (char ch);
/**
 * Funcion principal
 */
int main (void)
{
    ifstream fichero_lectura;
    ofstream fichero_escritura;
    string texto;
    char ch, ch_anterior = 'a';
    
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
    
    return 0;
}

/************************ EsSigno *********************//
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

