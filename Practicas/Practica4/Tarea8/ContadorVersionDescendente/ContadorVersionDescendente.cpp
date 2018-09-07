/**
 * @file NumeroEnRango.cpp
 *
 * @brief Tarea 08: Laboratorio 3.
 *
 * Este programa muestra la cuenta atras de un numero
 *
 * @version 1
 * @author Aldemaro Gonzalez
 * @date 2/11/2017
 *
 * @todo El contador no para despues de 1
 */

#include <iostream>
using namespace std;

void Contador (int num);

int main (void)
{
    int num;
    
    cout << "Dame numero inicial: ";
    cin >> num;
    
    cout << "Contador descendente: \n";
    Contador (num);
    
    return 0;
}

/** Contador
 *
 * Realiza la cuenta atras de un numero
 *
 * @param[in] num Numero que va a comprovar si esta dentro del rango
 *
 */
void Contador (int num)
{
    int max;
    
    max = num;
    
    do
    {
        cout << "\tContador a " << num << endl;
        num -= 1;
    }
    while (num >= 1);
    
    
    cout << "Contador ascendente: \n";
    do
    {
        cout << "\tContador a " << num << endl;
        num += 1;
    }
    while (num < max);
    
    
    return;
}
