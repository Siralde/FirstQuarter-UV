/**
 * @file b1_3_sumadigitos.cpp
 *
 * @brief Ejercicio 03. Boletin 1.
 *
 * Este programa determina la suma de los digitos de un numero de, a lo sumo, 4 digitos.
 *
 * @version 1
 * @author Aldemaro Gonzalez
 * @date 5/10/2017
 */

#include <iostream>
using namespace std;

const unsigned char FACTOR = 10; ///< Este numero es necesario para calcular los digitos de un numero

/**
 * Funcion principal
 */
int main (void)
{
    int numero, operacion_1, operacion_1_1, operacion_2, operacion_2_2;
    int operacion_3, operacion_3_3, operacion_4, operacion_4_4;
    int sumatoria_num;
    
    //Empezamos el programa explicando al usuario lo que hace
    cout << "Este programa determina la suma de los digitos ";
    cout << "de un numero de, a lo sumo, 4 digitos.\n\n";
    
    //Pedimos al usurario que nos indique el numero
    cout << "Dame numero de, a lo sumo, cuatro digitos: ";
    cin >> numero;
    
    /*
     * Hacemos los calculos para obtener la sumatoria de cada digito
     */
    operacion_1 = numero / FACTOR;
    operacion_1_1 = numero % FACTOR;
    operacion_2 = operacion_1 / FACTOR;
    operacion_2_2 = operacion_1 % FACTOR;
    operacion_3 = operacion_2 / FACTOR;
    operacion_3_3 = operacion_2 % FACTOR;
    operacion_4 = operacion_3 / FACTOR;
    operacion_4_4 = operacion_3 % FACTOR;
    sumatoria_num = operacion_1_1 + operacion_2_2 + operacion_3_3 + operacion_4_4;
    
    //Mostramos los resultados obtenidos
    cout << "\nLa suma de los digitos de " << numero << " es: ";
    cout << sumatoria_num << endl;
    
    return 0;
}

