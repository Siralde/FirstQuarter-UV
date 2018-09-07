/**
 * @file b5_2_simplificar.cpp
 *
 * @brief Ejercicio 02: M.C.D y Simplicacion de fracciones.
 *
 * Este programa calcula el mcd de dos numeros y simplifica una fraccion
 *
 * @version 1
 * @author Aldemaro Gonzalez
 * @date 14/11/2017
 */
#include <cstdlib>
#include <iostream>
using namespace std;

int Min(int, int);
int PedirNumeroPositivo(void);
int MaximoComunDivisor(int, int);
void Simplificar(int &, int &);

/**
 * Funcion principal
 */
int main (void)
{
    int numerador, denominador;
    
    cout << "Este programa simplifica una fraccion.\n\n";
    
    cout << "Dame el numerador y denominador de la fraccion\n";
    numerador = PedirNumeroPositivo();
    denominador = PedirNumeroPositivo();
    
    cout << "El m.c.d es " << MaximoComunDivisor(numerador, denominador) << endl;
    cout << "La fraccion " << numerador << " / " << denominador << " simplificada es: ";
    Simplificar(numerador, denominador);
    cout << numerador << " / " << denominador << endl << endl;
    
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

/************************ MaximoComunDivisor *********************//
*
* Determina el Maximo Comun Divisior de dos numeros
*
* @param[in] a Numerador de la fraccion
* @param[in] b Denominador de la fraccion
*
* @return Maximo Comun Divisor de dos numeros
*
*//*************************************************************/
int MaximoComunDivisor (int a, int b)
{
    int mcd;
    
    if (b == a)
        mcd = b;
    else
        mcd = MaximoComunDivisor (Min (a, b), abs(a - b));
    
    return mcd;
}

/***************************** Min **************************//
*
* Determina el minimo de dos valores
*
* @param[in] a Numero al que hay que comparar
* @param[in] b Numero al que hay que comparar
*
* @return Minimo entre los dos numeros
*
*//*************************************************************/
int Min(int a, int b)
{
    int minimo;
    
    minimo = a;
    
    if ( b < a)
        minimo = b;

    return minimo;
}

/************************ Simplificar *********************//
*
* Simplifica fracciones
*
* @param[in] a Numero al que hay que simplificar
* @param[in] b Numero al que hay que simplificar
*
*//*************************************************************/
void Simplificar(int & a, int & b)
{
    int mcd;
    
    mcd = MaximoComunDivisor (a, b);
    
    a = a / mcd;
    b = b / mcd;
    
    return;
}
