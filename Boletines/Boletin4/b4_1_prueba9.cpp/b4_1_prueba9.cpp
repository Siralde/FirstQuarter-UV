/**
 * @file b4_1_prueba9.cpp
 *
 * @brief Ejercicio 01: Compruebacion de una multiplicacion.
 *
 * Este programa determina el posible error realizado en una multiplicación utilizando
 * para ello la prueba del nueve.
 *
 * @version 1
 * @author Aldemaro Gonzalez
 * @date 14/11/2017
 */

#include <iostream>
using namespace std;

int SumaCifras(int numero);

/**
 * Funcion principal
 */
int main (void)
{
    int primer_factor, segundo_factor, posible_resultado;
    int multiplicacion;
    int producto_factores;
    
    //Empezamos el programa explicando al usuario lo que hace
    cout << "Este programa determina si hay un posible error en una multiplicación.\n\n";
    
    
    //Pedimos al usurario
    cout << "Dime primer factor: ";
    cin >> primer_factor;
    cout << "Dime segundo factor: ";
    cin >> segundo_factor;
    cout << "Dime tu propuesta de resultado: ";
    cin >> posible_resultado;
    
    multiplicacion = SumaCifras(primer_factor) * SumaCifras(segundo_factor);
    producto_factores = SumaCifras(multiplicacion);

    cout << "\nLa 'raiz digital' de " << primer_factor << " es: " << SumaCifras(primer_factor);
    cout << "\nLa 'raiz digital' de " << segundo_factor << " es: " << SumaCifras(segundo_factor);
    cout << "\nLa 'raiz digital' del producto (" << multiplicacion << ") es: " << producto_factores;
    cout << "\nLa 'raiz digital' de tu propuesta de resultado es: " << SumaCifras(posible_resultado);
    
    
    if (producto_factores == SumaCifras(posible_resultado))
    {
        cout << "\n\nLa multiplicación, probablemente, este bien.\n\n";
    }
    
    else
    cout << "\n\nLa multiplicación esta MAL.\n\n";
    
    return 0;
}

/************************ SumaCifras *********************//**
*
* Realiza la suma sucesiva de las cifras de un numero hasta que
* llegue a una cifra
*
* @param[in] numero Numero al que hay que sumarle la cifras
*
* @return Sumatoria de la cifras del numero introducido
*
*//*************************************************************/
int SumaCifras(int numero)
{
    int resto, suma_cifras = 0;
    
    /*
     * Extraemos las cifras de un numero y se la sumamos
     */
    while (numero != 0)
    {
        resto = numero % 10;
        suma_cifras += resto;
        numero /= 10;
    }
    
    if (suma_cifras >= 10)
    {
        suma_cifras = SumaCifras(suma_cifras);
    }
    
    else if (suma_cifras == 9)
        suma_cifras = 0;
        
    return suma_cifras;
}
