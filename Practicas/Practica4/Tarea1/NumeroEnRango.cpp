/**
 * @file NumeroEnRango.cpp
 *
 * @brief Tarea 01: Laboratorio 3.
 *
 * Descripcion
 *
 * @version 1
 * @author Aldemaro Gonzalez
 * @date 2/11/2017
 */

#include <iostream>
using namespace std;

bool NumeroEnRango(int num, int lim_inf, int lim_sup);

/**
 * Funcion principal
 */
int main (void)
{
    int num, lim_inf, lim_sup, corrector;
    bool resultado;
    
    //Empezamos el programa explicando al usuario lo que hace
    cout << "Este programa si un numero esta dentro de un rango.\n\n";
    
    
    //Pedimos al usurario
    cout << "Dame un numero: ";
    cin >> num;
    cout << "Dame sus limites: ";
    cin >> lim_inf >> lim_sup;
    
    /*
     * Procesamos la informacion
     */
    if (lim_inf > lim_sup)
    {
        corrector = lim_inf;
        lim_sup = lim_inf;
        lim_inf = corrector;
    }
    
    resultado = NumeroEnRango (num, lim_inf, lim_sup);
    
    // Mostramos los resultados obtenidos
    if (resultado == true)
    {
        cout << "\nEl numero esta en el rango.\n\n";
    }
    else
    {
        cout << "\nEl numero esta fuera del rango.\n\n";
    }
    
    return 0;
}

/**
 *
 * Comprueba si un numero esta dentro de un rango
 *
 * @param[in] num Numero que va a comprovar si esta dentro del rango
 * @param[in] lim_inf Limite Inferior
 * @param[in] lim_sup Limite Superior
 * @return Resultado de la comprobacion
 *
 */
bool NumeroEnRango(int num, int lim_inf, int lim_sup)
{
    bool resultado;
    
    if (num < lim_inf || num > lim_sup)
    {
        resultado = false;
    }
    else
        resultado = true;
    
    return resultado;
}
