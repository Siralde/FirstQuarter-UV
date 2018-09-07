/**
 * @file b4_3_perfectos.cpp
 *
 * @brief Ejercicio 03: Numeros Perfectos de Mersenne.
 *
 * Este programa que nos dice los 10 primeros números perfectos utilizando para ello los
 * números primos de Mersenne.
 *
 * @version 1
 * @author Aldemaro Gonzalez
 * @date 9/11/2017
 */

#include <iostream>
using namespace std;

unsigned long long Mersenne(int num);
unsigned long long Potencia(int base, int exp);
bool EsPrimo(unsigned long long num);

/**
 * Funcion principal
 */
int main (void)
{
    int num = 0;                //Exponente
    int cant_num_perfecto = 1;  //Cantidad de numero perfectos mostrados en pantalla
    
    cout << "Este programa que nos dice los 10 primeros números perfectos ";
    cout << "utilizando para ello los números primos de Mersenne.\n\n";
    
    cout << "Los 10 primeros números perfectos son";
    
    while (cant_num_perfecto <= 10)
    {
        num ++;
        
        if (EsPrimo(num))
        {
            if (Mersenne(num) != 0)
            {
                cout << ", " << Mersenne(num);
                cant_num_perfecto++;
            }
        }
        else
            cant_num_perfecto = cant_num_perfecto;
    }
    
    cout << ".\n\n";
    
    return 0;
}

/************************ Mersenne *********************//**
*
* Determina los numeros primos de Mersenne
*
*
* @param[in] num Numero al que va elevado las dos expresiones
*
* @return numero_perfecto Numero Perfecto obtenido
*
*//*************************************************************/
unsigned long long Mersenne(int num)
{
    unsigned long long primera_expresion;       //Para realizar y comprobar la expresion (2^num) - 1
    unsigned long long segunda_expresion;       //Para realizar y comprabar la expresion (2^num - 1)
    bool comprobacion_primo;
    unsigned long long numero_perfecto;         //Resultado de las dos expresion
    
    primera_expresion = Potencia(2, num);       // Se eleva 2^num
    primera_expresion = primera_expresion - 1;
    
    comprobacion_primo = EsPrimo(primera_expresion);
    
    if (comprobacion_primo == true)
    {
        segunda_expresion = Potencia(2, num - 1);
        numero_perfecto = primera_expresion * segunda_expresion;
    }
    else
        numero_perfecto = 0;
    
    return numero_perfecto;
}

/************************ Potencia *********************//**
*
* Determina la potencias de un numero
*
* @param[in] base Base de la potencia
* @param[in] exp Exponente de la potencia
*
* @return resultado Resultado de la potencia
*
*//*************************************************************/
unsigned long long Potencia(int base, int exp)
{
    int i;
    unsigned long long pot, resultado;
    
    pot = 1;
    
    for (i = 1; i <= exp; i++)
        pot *= base;
    
    resultado = pot;
    
    return resultado;
}

/************************ EsPrimo *********************//**
*
* Determina si un numero es primo o no lo es
*
* @pre num > 0
*
* @param[in] num Numero que hay determinar si es primo o no
*
* @return Devuelve si es o no primo
*
*//*************************************************************/
bool EsPrimo(unsigned long long num)
{
    bool resultado;
    
    if (num % 2 == 0 || num % 3 == 0 || num % 5 == 0 || num % 7 == 0)
    {
        
        switch (num)
        {
            case 2:
            case 3:
            case 5:
            case 7:
                resultado = true;
                break;
            default:
                resultado = false;
                break;
        }
    }
    
    else if (num == 1)
        resultado = false;
    
    else
        resultado = true;
    
    return resultado;
}
