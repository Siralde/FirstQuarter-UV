/**
 * @file b8_4_preguntados.cpp
 *
 * @brief Ejercicio 04: Boletin 8, Aumentar el número de preguntas de los ficheros del juego 'Preguntados'.
 *
 * Este programa aumenta el número de preguntas de los ficheros del juego 'Preguntados'.
 *
 * @version 1
 * @author Aldemaro Gonzalez
 * @date 04/01/2018
 */
#include <fstream>
#include <cctype>
#include <string>
#include <iostream>
using namespace std;

struct Pregunta
{
    string enunciado;
    string verdadera;
    string falsa1;
    string falsa2;
    string falsa3;
};

bool EstaPreguntaEnFichero (const string enunciado,unsigned short categoria);
string TodoMayuscula(string frase);
bool LeerPreguntaFichero (ifstream & f, Pregunta & pr_temporal);
Pregunta LeerPregunta (void);
bool AnadirPreguntaAFichero (Pregunta, unsigned short);
void GuardarPreguntaFichero (ofstream &, Pregunta);
void MostrarPregunta (Pregunta);

int main (void)
{
    unsigned short categoria;
    string enunciado;
    Pregunta pregunta;
    
    cout << "Dime categoria: ";
    cin >> categoria;
    cin.ignore ();
    
    cout << "Dime el enunciado de la pregunta: ";
    getline (cin, enunciado);
    
    if (EstaPreguntaEnFichero (enunciado, categoria) )
        cout << "\nLa pregunta ya se encuentra en el fichero.\n\n";
    else
    {
        pregunta = LeerPregunta ();
        if (AnadirPreguntaAFichero (pregunta, categoria) )
        {
            cout << "\nLa pregunta: ";
            MostrarPregunta (pregunta);
            cout << " ha sido anadido satisfactoriamente.";
        }
        else
            cout << "Error procesando fichero. Pregunta NO anadida.";
    }
    
    return 0;
}

/************************** EstaPreguntaEnFichero ******************************//
*
* Comprueba si hay alguna pregunta en el fichero con el mismo enunciado
*
* @param[in] enunciado Enunciado de la pregunta
* @param[in] categoria Categoria de la pregunta
*
* @retval true Si el enunciado de la pregunta esta repetido en el fichero
* @retval false Si el enunciado de la pregunta no esta repetido en el fichero
*
*//*******************************************************************************/
bool EstaPreguntaEnFichero (const string enunciado, unsigned short categoria)
{
    bool repetida = false;
    Pregunta pr_temporal;
    string enunciado_usuario, enunciado_fichero, cat;
    ifstream f;
    
    enunciado_usuario = TodoMayuscula(enunciado);

    cat = to_string(categoria) + ".dat";
    
    f.open(cat);
    if(!f)
        cout << "Error abriendo el fichero en la comprobacion de los enunciados iguales" << endl;
    else
    {
        while (LeerPreguntaFichero(f, pr_temporal) && repetida == false)
        {
            
            enunciado_fichero = TodoMayuscula(pr_temporal.enunciado);
            
            if (enunciado_usuario == enunciado_fichero)
            {
                repetida = true;
            }
        }
        f.close();
    }
    
    return repetida;
}

/************************** TodoMayuscula ******************************//
*
* Lee el enunciado de un fichero
*
* @param[in] frase Frase a poner en mayuscula
*
* @return Frase en Mayusculas
*
*//*********************************************************************/
string TodoMayuscula(string frase)
{
    size_t i;
    string frase_x;
    
    for (i = 0; i < frase.length(); i++)
    {
        frase_x += toupper(frase[i]) ;
    }

    return frase_x;
}

/************************** LeerEnunciadoFichero ******************************//
*
* Lee el enunciado de un fichero de preguntados
*
* @param[in] f           Descriptor del fichero
* @param[in] pr_temporal Donde se va a guarda el enunciado
*
* @retval true El enunciado ha sido leido correctamente
* @retval false El enunciado no ha sido leido correctamente
*
*//*************************************************************************/
bool LeerPreguntaFichero (ifstream & f, Pregunta & pr_temporal)
{
    bool lectura_ok = false;
    char ultimo_caracter;
    size_t cant_caracteres;
    string arreglo;

    if (getline (f, pr_temporal.enunciado))
  {
        cant_caracteres = pr_temporal.enunciado.length();
        ultimo_caracter = pr_temporal.enunciado[cant_caracteres];
        if ( ultimo_caracter == '\r' || ultimo_caracter == '\0')
        {
            arreglo = pr_temporal.enunciado.substr(0, cant_caracteres - 1);
            pr_temporal.enunciado = arreglo;
        }
        getline (f, pr_temporal.verdadera);
        getline (f, pr_temporal.falsa1);
        getline (f, pr_temporal.falsa2);
        getline (f, pr_temporal.falsa3);
        
        lectura_ok = true;
    }
    
    return lectura_ok;
}

/************************** LeerPregunta ******************************//
*
* Rellena los campos del registro
*
* @return Registro Pregunta
*
*//*******************************************************************/
Pregunta LeerPregunta (void)
{
    Pregunta pregunta;
    
    cout << "Dame el enunciado de nuevo: ";
    getline (cin,pregunta.enunciado);
    cout << "Dame la respuesta correcta: ";
    getline (cin,pregunta.verdadera);
    cout << "Dame una respuesta falsa: ";
    getline (cin,pregunta.falsa1);
    cout << "Dame una respuesta falsa: ";
    getline (cin,pregunta.falsa2);
    cout << "Dame una respuesta falsa: ";
    getline (cin,pregunta.falsa3);
    
    return pregunta;
}
/************************** AnadirPreguntaAFichero ******************************//
*
* Comprueba si el fichero a escribir fue abierto satisfactoriamente
*
* @param[in] pregunta   Registro de Pregunta
* @param[in] categoria  Categoria de la pregunta
*
* @retval true  Fichero abierto satisfactoriamente
* @retval false Fichero no abierto satisfactoriamente
*
*//*******************************************************************/
bool AnadirPreguntaAFichero (Pregunta pregunta, unsigned short categoria)
{
    ofstream f;
    string cat;
    bool abrio;
    
    cat = to_string(categoria) + ".dat";
    
    f.open(cat, ios::app);
    if(!f)
    {
        cout << "Error abriendo el fichero en la comprobacion de los enunciados iguales" << endl;
        abrio = false;
    }
    else
    {
        GuardarPreguntaFichero(f, pregunta);
        abrio = true;
        f.close();
    }
    
    return abrio;
}

/************************** AnadirPreguntaAFichero ******************************//
*
* Escribe en el fichero lo que esta en el registro
*
* @param[in] f          Descriptor del fichero
* @param[in] pregunta   Registro Pregunta
*
*//*******************************************************************/
void GuardarPreguntaFichero(ofstream & f, Pregunta pregunta)
{
    f << pregunta.enunciado << endl;
    f << pregunta.verdadera << endl;
    f << pregunta.falsa1 << endl;
    f << pregunta.falsa2 << endl;
    f << pregunta.falsa3 << endl;
    
    return;
}
/********************** MostrarPregunta *********************//
*
* Muestra por pantalla la pregunta anadida por el usuario
*
* @param[in] pregunta   Registro Pregunta
*
*//*******************************************************************/
void MostrarPregunta (Pregunta pregunta)
{
    cout << pregunta.enunciado << endl;
}
