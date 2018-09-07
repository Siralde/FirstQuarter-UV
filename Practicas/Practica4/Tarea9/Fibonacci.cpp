/**
 * @file Fibonacci.cpp
 *
 * @brief Tarea 09: Laboratorio 3.
 *
 * Este programa determina un termino fibonacci mediante la recursividad
 *
 * @version 1
 * @author Aldemaro Gonzalez
 * @date 2/11/2017
 *
 */

#include <iostream>
using namespace std;

long long Fibonacci(int num);

/**
 * Funcion principal
 */
int main (void)
{
    int num;
    
    //Empezamos el programa explicando al usuario lo que hace
    cout << "Este programa determina un termino fibonacci.\n\n";
    
    
    //Pedimos al usurario
    cout << "Dame un numero: ";
    cin >> num;
    
    cout << "La funcion Fibonacci del numero '" << num << "' es: ";
    cout << Fibonacci(num) << endl << endl;
    
    return 0;
}

/**
 *
 * Numero Fibonacci
 *
 * @param[in] num El termino de fibonacci que se quire determinar
 *
 * @return El termino fibonacci
 *
 */
long long Fibonacci(int num)
{
    long long res;
    
    if (num == 0 || num == 1)
        res = num;
    else
        res = Fibonacci(num - 1) + Fibonacci (num - 2);
    
    return res;
}
