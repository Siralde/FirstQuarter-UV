
/************************** Practica2_Ejemplo2.cpp *************************/ /**
*
* @file Practica3_Ejemplo1.cpp
*
* @brief Pr·cticas de Informatica. Practica 3. Ejemplo 2
*
* Este programa determina el primer valor de la serie de fibonacci que
* es mayor que MAX
* Los terminos de Fibonacci son:
* 0  1  1  2  3  5  8  13  21  34  55 ...
*
* @version 1.1
* @author Ricardo Ferris
* @date 28-10-2014
*/ /***************************************************************************/

#include <iostream>
using namespace std;

const int MAX = 10; ///< Valor limite del termino que buscamos

int main (void)
{
    int t, t_a, t_2a;
    
    t_2a = 0;
    t_a = 1;
    t = t_a + t_2a;
    while (t < MAX)
    {
        t_a = t;
        t_2a = t_a;
        t = t_a + t_2a;
    }
    
    cout << "El tÈrmino es " << t;
    
    return 0;
}

