/**
 * @file tarea1.cpp
 *
 * @brief Ejercicio 01: Laboratorio 4b.
 *
 * Tarea 1: Realiza una función llamada CalculoDelMCD con dos parámetros de entrada que serán
 números enteros:
 num1 y num2: los números de los que se va a determinar su Máximo Común Divisor
 La función debe devolver el valor del máximo común divisor. Se recomienda el uso del
 algorimo de Euclides para determinar el MCD, aunque puedes realizarlo de alguna otra
 manera.
 Recuerda que solo puede haber una instrucción
 *
 * @version 1
 * @author Aldemaro Gonzalez
 * @date //2017
 */

#include <iostream>
using namespace std;

int CalculoDelMCD(int numero_1, int numero_2);

/**
 * Funcion principal
 */
int main (void)
{
    int num1, num2, max_comun_multiplo;
    
    //Empezamos el programa explicando al usuario lo que hace
    cout << "Este programa determina el Maximo Comun Multiplo de un numero.\n\n";
    
    
    //Pedimos al usurario
    cout << "Dame dos numeros";
    cin >> num1, num2;
    
    // Mostramos los resultados obtenidos
    cout << "El Maximo Comun Multiplo de los numeros " << num1 " y ";
    cout << num2 << "es: " << CalculoDelMCD(num1, num2)
    
    return 0;
}

/**
 *
 * Consigue el Maximo Comun Divisor
 *
 * @param[in] numero_1 Dividendo
 * @param[in] numero_2  Divisor
 *
 * @return Maximo Comun Divisor de los dos numeros
 */
int CalculoDelMCD(int numero_1, int numero_2)
{
    
}
