/**
 * @file b3_4_primos.cpp
 *
 * @brief Ejercicio 04: numeros primos realitivos.
 *
 * Este programa determina si dos numeros
 * enteros positivos son primos relativos.
 *
 * @version 1
 * @author Aldemaro Gonzalez
 * @date 27/10/2017
 */

#include <iostream>
using namespace std;

/**
 * Funcion principal
 */
int main (void)
{
    int numero_1, numero_2, i;
    int num_menor;
    int factor_comun = 0; // Acumula la cantidad de divisores entre los dos numeros (cantidad de factores comunes)
    
    cout << "Este programa determina si dos numeros ";
    cout << "enteros positivos son primos relativos.\n\n";
    
    cout << "Dame numero entero positivo: " ;
    cin >> numero_1;
    cout << "Dame numero entero positivo: " ;
    cin >> numero_2;
    
    // Comprobamos que ambos numeros sean positivos
    while (numero_1 < 0 || numero_2 < 0)
    {
        cout << "Uno o ambos numeros son negativos. Vuelve a darme los numeros." << endl << endl;
        cout << "Dame numero entero positivo: " ;
        cin >> numero_1;
        cout << "Dame numero entero positivo: " ;
        cin >> numero_2;
    }
    
    // Establecemos el menor entre ambos numeros
    if (numero_1 > numero_2)
    {
        num_menor = numero_2;
    }
    
    else
    {
        num_menor = numero_1;
    }
    
    // Buscamos cuantos divisores comunes tienen
    for (i = 1; i <= num_menor; i++)
    {
        // Si el resto es entre los numeros y el contador 'i' es igual a 0 entonces ese es su divisor comun
        if ((numero_1 % i == 0) && (numero_2 % i == 0))
            factor_comun += 1;
    }
    
    // Si tienen un solo divisor comun son primos relativos
    if (factor_comun == 1)
    {
        cout << "Los numeros son primos relativos "<< endl << endl;
    }
    
    // Si tienen mas de un divisor comun no son primos relativos
    else
    {
        cout << "Los numeros NO son primos relativos" << endl << endl;
    }

    return 0;
}

/**
 * BANCO DE PRUEBAS:
 *
 * Ejemplo 1:
 * Dame numero entero positivo: 12
 * Dame numero entero positivo: -3
 * Uno o ambos numeros son negativos. Vuelve a darme los numeros
 * Dame numero entero positivo: 12
 * Dame numero entero positivo: 15
 * Los numeros NO son primos relativos
 *
 * Ejemplo 2:
 * Dame numero entero positivo: 12
 * Dame numero entero positivo: 35
 * Los numeros son primos relativos
 *
 * Ejemplo 3:
 * Dame numero entero positivo: -99
 * Dame numero entero positivo: -3
 * Uno o ambos numeros son negativos. Vuelve a darme los numeros
 * Dame numero entero positivo: 99
 * Dame numero entero positivo: 3
 * Los numeros NO son primos relativos
 *
 * Ejemplo 4:
 * Dame numero entero positivo: 2023045067
 * Dame numero entero positivo: 15
 * Los numeros son primos relativos
 *
 * Ejemplo 5:
 * Dame numero entero positivo: 2017
 * Dame numero entero positivo: 1998
 * Los numeros son primos relativos
 */
