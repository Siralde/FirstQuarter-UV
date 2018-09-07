/**
 * @file b2_4_diasmes.cpp
 *
 * @brief Ejercicio 04: Dice si una fecha es o no valida.
 *
 * Este programa determina si una fecha ingresada por el usuarios es valida o no.
 *
 * @version 1
 * @author Aldemaro Gonzalez
 * @date 14/10/2017
 */

#include <iostream>
using namespace std;

/**
 * Funcion principal
 */
int main (void)
{
    int dia, mes;
    
    //Empezamos el programa explicando al usuario lo que hace
    cout << "Este programa determina si una fecha es valida.\n\n";
    
    //Pedimos al usurario la fecha
    cout << "Dame el día: ";
    cin >> dia;
    cout << "Dame el mes: ";
    cin >> mes;
    cout << endl;
    
    if ((mes < 1) || (mes > 12)) // verificamos si el mes esta entre 1 y 12
            cout << "Fecha no valida.\n\n";
    else
    {
        //verificamos si el mes es de 31 dias
        if ((mes == 1) || (mes == 3) || (mes == 5) || (mes == 7) || (mes == 8) || (mes == 10) || (mes == 12))
        {
            if (dia >= 1 && dia <= 31)
                cout << "Fecha valida.\n\n";
            else
                cout << "Fecha no valida.\n\n";
        }
        
        //verificamos si el mes es de 30 dias
        else if ((mes == 4) || (mes == 6) || (mes == 9) || (mes == 11))
        {
            if (dia >= 1 && dia <= 30)
                cout << "Fecha valida.\n\n";
            else
                cout << "Fecha no valida.\n\n";
        }
        
        //verificamos si es febrero
        else if (mes == 2)
        {
            if (dia >= 1 && dia <= 29)
                cout << "Fecha valida.\n\n";
            else
                cout << "Fecha no valida.\n\n";
        }
    }
    
    return 0;
}

/**
 * BANCO DE PRUEBAS
 * ENTRADA = SALIDA
 * -02 / 07 = No valido
 * 32 / 01 = No valido
 * 31 / 02 = No valido
 * 31 / 12 = Valido
 */
