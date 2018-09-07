/**
 * @file b5_1_numerosdelucas.cpp
 *
 * @brief Ejercicio 1: Determinar el numero de lucas.
 *
 * Este programa determina un el numero de lucas
 * de un numero natural mediante la recursividad
 *
 * @version 1
 * @author Aldemaro Gonzalez
 * @date 19/11/2017
 *
 */
#include <cstdlib>
#include <iostream>
using namespace std;

int NumeroDeLucas(int num);

/**
 * Funcion principal
 */
int main (void)
{
    int num, res;

    cout << "Este programa determina un numero lucas.\n\n";
    
    cout << "Dame un numero: ";
    cin >> num;
    
    res = NumeroDeLucas (num);
    
    cout << "El numero de lucas " << num << " es: ";
    cout << res << endl << endl;
    
    return 0;
}

/************************ NumeroDeLucas *********************//**
*
* Calcula el numero de lucas
*
* @param[in] num El numero de lucas que se quire determinar
*
* @return El numero de lucas
*
*//*************************************************************/
int NumeroDeLucas(int num)
{
    int res;
    
    num = abs(num);
    
    if (num == 0)
        res = 2;
    else if (num == 1)
        res = num;
    else
        res = NumeroDeLucas(num - 1) + NumeroDeLucas(num - 2);
    
    return res;
}
