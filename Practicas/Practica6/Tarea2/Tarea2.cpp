/**
 * @file tarea2.cpp
 *
 * @brief Ejercicio 02: Laboratoria 5.
 *
 * Este programa pide una frase y muestre por pantalla
 * cada una de las palabras que la forman.
 *
 * @version 1
 * @author Aldemaro Gonzalez
 * @date 24/11/2017
 */
#include <string>
#include <cctype>
#include <iostream>
using namespace std;

const int MAX = 100;

typedef string Vector[MAX];

void SeparadorDePalabras(string);
void MostrarVector (const Vector, size_t);
/**
 * Funcion principal
 */
int main (void)
{
    string frase;
    
    cout << "Este programa pide una frase y muestre por pantalla ";
    cout << "cada una de las palabras que la forman..\n\n";
    
    cout << "Dame Frase: ";
    getline (cin, frase);
    cout << "\nLas palabras que conforman la frase, con palabras repetidas, son:\n";
    
    SeparadorDePalabras(frase);
    
    return 0;
}


/************************ SeparadorDePalabras *********************//**
*
* Separa las palabras de una frase y las muestra por pantalla
* en orden numerico.
*
* @param[in] frase Vector
*
*//*************************************************************/
void SeparadorDePalabras(string frase)
{
    size_t i, numero_palabras = 0, longitud, inicio;
    Vector v;
    
    longitud = frase.length();
    inicio = 0;
    
    for (i = 0; i < longitud; i++)
    {
        if (frase[i] == ' ' || frase[i] == '.' || frase[i] == ',')
        {
            v[numero_palabras] = frase.substr(inicio, i - inicio);
            MostrarVector (v, numero_palabras);
            numero_palabras++;
            inicio = i + 1;
        }
    }
    
    //Ultima palabra
    numero_palabras ++;
    v[numero_palabras] = frase.substr(inicio, longitud - inicio);
    MostrarVector(v, numero_palabras);
    
    return;
}


/************************ MostrarVector *********************//**
*
* Separa las palabras de una frase y las muestra por pantalla
* en orden numerico.
*
* @param[in] v Cada palabra que compone la frase
*
* @param [in] numero_palabras Cantidad de palabras que componen la frase
*
*//*************************************************************/
void MostrarVector(const Vector v, size_t numero_palabras)
{
    size_t i;
    
    for(i = numero_palabras; i == numero_palabras; i++)
        cout << numero_palabras << "-> " << v[i];
    cout << endl;
    return;
}


// Ocho palabras, con comas, y con palabras repetidas.
