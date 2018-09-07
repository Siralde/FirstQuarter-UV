/**
 * @file b4_2_primos.cpp
 *
 * @brief Ejercicio 04: Determinacion de numero primos.
 *
 * Descripcion
 *
 * @version 1
 * @author Aldemaro Gonzalez
 * @date 12/11/2017
 */

#include <iostream>
using namespace std;

void MostrarPresentacionPrograma (void);
int PedirNumeroPositivo (void);
bool EsPrimo(int num);

/**
 * Funcion principal
 */
int main (void)
{
    int num;
    
    MostrarPresentacionPrograma ();
    num = PedirNumeroPositivo ();
    
    if (EsPrimo (num))
        cout << "\nEl numero " << num << " es primo.\n\n";
    else
        cout << "\nEl numero " << num << " NO es primo.\n\n";
    
    return 0;
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
bool EsPrimo(int num)
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

/************************ MostrarPresentacionPrograma *********************//**
*
* Presenta el Programa
*
*//*************************************************************/
void MostrarPresentacionPrograma (void)
{
    cout << "Este determina si un numero es primo o no lo es.\n";
}

/************************ PedirNumeroPositivo *********************//**
*
* Pide al usuario un numero positivo
*
* @return Numero al que se va a evaluar
*
*//*************************************************************/
int PedirNumeroPositivo (void)
{
    int num;
    
    do
    {
        cout << "\nDame un numero entero positivo: ";
        cin >> num;
    }
    while (num <= 0);
    
    return num;
}
