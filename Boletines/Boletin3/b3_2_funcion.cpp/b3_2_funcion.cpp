/**
 * @file b3_2_funcion.cpp
 *
 * @brief Ejercicio 02: resolucion de funcion cuadratica.
 *
 * Este programa muestra por pantalla los valores de la función y = a * x * x + b * x + c
 * para los valores enteros contenidos en el intervalo [r1, r2]. Los valores de a, b y c, así como los de
 * r1 y r2 son introducidos por el usuario.
 *
 * @version 1
 * @author Aldemaro Gonzalez
 * @date 26/10/2017
 * @todo Arreglar que el al poner los coeficiente salga uno detras del otro
 */

#include <iostream>
using namespace std;

/**
 * Funcion principal
 */
int main (void)
{
    int coeficiente_a, coeficiente_b, coeficiente_c;
    int rango_menor, rango_mayor, rango_condicional;
    int y;
    
    cout << "Este programa resuelve la función y = a * x * x + b * x + c";
    cout << " las cifras de las posiciones impares que componen el número.\n\n";
    
    cout << "Dame los coeficientes a, b, c: ";
    cin >> coeficiente_a >> coeficiente_b >> coeficiente_c;
    cout << "Dame los limites del rango: ";
    cin >> rango_menor >> rango_mayor;
    
    /*
     * Si el primer limite que el usuario introduce es mayor que el segundo,
     * se intercambia sus valores y se procede a realizar la ecuacion.
     */
    if (rango_menor > rango_mayor)
    {
        rango_condicional = rango_mayor;
        rango_mayor = rango_menor;
        rango_menor = rango_condicional;
        
        for (; rango_menor <= rango_mayor; rango_menor++)
        {
            y = coeficiente_a * rango_menor * rango_menor + coeficiente_b * rango_menor + coeficiente_c;
            cout << "\nValor de x = " << rango_menor << ", valor de y = " << y << "\n\n";
        }
    }
    
    else
    {
        for (; rango_menor <= rango_mayor; rango_menor++)
        {
            y = coeficiente_a * rango_menor * rango_menor + coeficiente_b * rango_menor + coeficiente_c;
            cout << "\nValor de x = " << rango_menor << ", valor de y = " << y << "\n\n";
        }
    }
    
    return 0;
}

/**
 * BANCO DE PRUEBAS:
 *
 * Ejemplo 1:
 * Coeficientes: 1 2 3
 * Limites del Rango: 1 -2
 * 1) Valor de x = -2, valor de y = 3
 * 2) Valor de x = -1, valor de y = 2
 * 3) Valor de x = 0, valor de y = 3
 * 2) Valor de x = 1, valor de y = 6
 *
 * Ejemplo 2:
 * Coeficientes: 5 7 -9
 * Limites del Rango: -5 -2
 * 1) Valor de x = -2, valor de y = 81
 * 2) Valor de x = -1, valor de y = 43
 * 3) Valor de x = 0, valor de y = 15
 * 2) Valor de x = 1, valor de y = -3
 *
 * Ejemplo 3:
 * Coeficientes: -3 8 1
 * Limites del Rango: 2 -1
 * 1) Valor de x = -1, valor de y = -10
 * 2) Valor de x = 0, valor de y = 1
 * 3) Valor de x = 1, valor de y = 6
 * 2) Valor de x = 2, valor de y = 5
 *
 */
