/**
 * @file tarea1.cpp
 *
 * @brief Ejercicio 01: Laboratoria 5.
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

void SeparadorDePalabras(string);

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
    cout << endl;
    
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
    size_t i;
    int num = 1;
    
    cout << num << "-> ";
    
    for (i = 0; i < frase.length(); i++)
    {
        
        if (isalpha(frase[i]))
        {
            cout << frase[i];
        }
        else
        {
            cout << endl;
            num++;
            cout << num << "-> ";
        }
    }
    
    cout << endl << endl;
    
    return;
}
