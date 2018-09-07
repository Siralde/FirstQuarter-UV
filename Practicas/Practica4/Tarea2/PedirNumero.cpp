/**
 *
 * @file PedirNumero.cpp
 *
 * @brief Tarea 02: Laboratorio 3.
 *
 *
 *
 * @version 1
 * @author Aldemaro Gonzalez
 * @date 2/11/2017
 *
 */

#include <iostream>
using namespace std;

int PedirNumero(int lim_inf, int lim_sup);
bool NumeroEnRango(int num, int lim_inf, int lim_sup);

/**
 * Funcion principal
 */
int main (void)
{
    int lim_inf, lim_sup, corrector;
    int resultado;
    
    //Empezamos el programa explicando al usuario lo que hace
    cout << "Este programa si un numero esta dentro de un rango.\n\n";
    
    
    //Pedimos al usurario
    cout << "Dame los limites: ";
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
    
    resultado = PedirNumero(lim_inf, lim_sup);
    
    // Mostramos los resultados obtenidos
    cout << "\nLa funcion devuelve el numero: " << resultado << ".\n\n";
    
    return 0;
}

/** Pedir Numero
 *
 * Comprueba si un numero esta dentro de un rango
 *
 * @param[in] lim_inf Limite Inferior
 * @param[in] lim_sup Limite Superior
 * @return Resultado de la comprobacion
 *
 */
int PedirNumero(int lim_inf, int lim_sup)
{
    int num;
    bool comprobacion;
    
    do
    {
        cout << "[entre " << lim_inf << " y " << lim_sup << " incluidos]: ";
        cin >> num;
        comprobacion = NumeroEnRango(num, lim_inf, lim_sup);
    }
    while (comprobacion == false);
    
    return num;
}

/** NumeroEnRango
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

