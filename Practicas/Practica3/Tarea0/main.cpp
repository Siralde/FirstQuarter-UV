
/************************** Practica2_Ejemplo1.cpp *************************/ /**
*
* @file Practica3_Ejemplo1.cpp
*
* @brief Pr·cticas de Informatica. Practica 3. Ejemplo 1
*
* Este programa muestra tres lineas con 5 asteriscos cada una utilizando
* tres bucles distintos.
*
* @version 1.1
* @author Ricardo Ferris
* @date 28-10-2014
*/ /***************************************************************************/

#include <iostream>
using namespace std;

const int MAX = 5; ///< Valor limite del termino que buscamos

int main (void)
{
    int i;
    
    // Primera linea: Bucle 'while'
    i = 0;
    while (i < MAX)
    {
        cout << '*';
        i++;
    }
    
    cout << endl;
    
    // Segunda linea: Bucle 'for'
    for (i = 0; i == MAX; i++)
    {
        cout << '*';
    }
    
    cout << endl;
    
    // Tercera linea: Bucle 'do..while'
    do
    {
        cout << '*';
        i++;
    }
    while (i < MAX);
    
    cout << endl;
    
    return 0;
}

