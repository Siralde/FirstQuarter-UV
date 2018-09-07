/**
 * @file b5_3_tartaglia.cpp
 *
 * @brief Ejercicio 03: Niveles del Triangulo de Tartalia.
 *
 * Este programa determina un nivel del triangulo del tartalia a partir de un numero
 * introducido. Lo calcula usando los numeros combinatorios
 *
 * @version 1
 * @author Aldemaro Gonzalez
 * @date 14/11/2017
 */

#include <iostream>
using namespace std;

int PedirNumeroPositivo (void);
int NumeroCombinatorio(int, int);
/**
 * Funcion principal
 */
int main (void)
{
    int nivel, i;
    
    cout << "Este programa simplifica una fraccion.\n\n";
    
    cout << "Dime el nivel a mostrar:\n";
    nivel = PedirNumeroPositivo();
    
    cout << "\nNivel " << nivel << " del triangulo:\n";
    for (i = 0; i <= nivel; i ++)
    {
        cout << NumeroCombinatorio (nivel, i) << " ";
    }
    
    cout << endl << endl;
    
    return 0;
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
    
    cout << "Dame un entero positivo: ";
    cin >> num;
    
    if (num <= 0)
    {
        cout << "El numero es negativo. ";
        num = PedirNumeroPositivo();
    }
    
    return num;
}

/************************ NumeroCombinatorio *********************//**
*
* Calcula el numero combinatorio de m y n
*
* @param[in] m Numero al que hay que sumarle la cifras\
* @param[in] n Numero al que hay que sumarle la cifras
*
* @return Numero combinatorio
*
*//*************************************************************/
int NumeroCombinatorio(int m, int n)
{
    int numero_combinatorio;
    
    if (m == n || n == 0)
    {
        numero_combinatorio = 1;
    }
    else
        numero_combinatorio = NumeroCombinatorio(m - 1, n - 1) + NumeroCombinatorio(m - 1, n);

    return numero_combinatorio;
}
