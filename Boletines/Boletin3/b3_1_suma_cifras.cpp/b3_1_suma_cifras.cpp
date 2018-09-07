/**
 * @file b3_1_suma_cifras.cpp
 *
 * @brief Ejercicio 01: suma de las cifras impares de un numero.
 *
 * Este programa acepta un número entero positivo y sume las cifras de las posiciones
 * impares que componen el número.
 *
 * @version 1
 * @author Aldemaro Gonzalez
 * @date 24/10/2017
 */

#include <iostream>
using namespace std;

/**
 * Funcion principal
 */
int main (void)
{
    int num, resto, impar, suma = 0, acumulador = 0;
    
    cout << "Este programa acepta un número entero positivo y sume";
    cout << " las cifras de las posiciones impares que componen el número.\n\n";
    
    cout << "Dame numero entero positivo: ";
    cin >> num;
    cout << endl;
    
    while (num > 0)
    {
        resto = num % 10;
        impar = acumulador % 2;
        if (impar != 0)
            suma += resto;
        acumulador ++;
        num /= 10;
    }
    
    cout << "La suma de las cifras de las posiciones impares es: " << suma << endl << endl;
    
    return 0;
}

/**
 * BANCO DE PRUEBAS
 * ENTRADA = SALIDA
 * 6543210 = 9
 * 245765 = 13
 * 5256789 = 26
 * 6666669 = 18
 * 896576 = 21
 * 123456789 = 20
 * 9876543210 = 25 (PARA REALIZAR ESTE CASO CAMBIAR DECLARACION DE VARIABLES DE INT A LONG LONG)
 * 0123456789 = 20 (PARA REALIZAR ESTE CASO CAMBIAR DECLARACION DE VARIABLES DE INT A LONG LONG)
 */
