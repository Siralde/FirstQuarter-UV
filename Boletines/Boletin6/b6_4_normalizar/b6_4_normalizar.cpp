/**
 * @file b6_4_normalizador.cpp
 *
 * @brief Tarea3: Laboratorio, Practica5.
 *
 * Este programa determina el valor maximo y minimo de una matriz maxima de
 * 20x20 y tambien calcula su normalizada
 *
 * @version 1
 * @author Aldemaro Gonzalez
 * @date 29/11/2017
 */
#include <cstdlib>
#include <iostream>
using namespace std;

const int COLUMNA = 20; ///< Tamanyo maximo de columnas
const int FILA = 20; ///< Tamanyo maximo de filas

typedef float Matriz [FILA] [COLUMNA];

void LeerMatriz (Matriz m, int & tam_fila, int & tam_columna);
void MostrarMatriz(const Matriz m, int tam_fila, int tam_columna);
int MinMaxMatriz (const Matriz m, int tam_fila, int tam_columna, int & max);
void Normalizador (Matriz m, int tam_fila, int tam_columna);

int main (void)
{
    Matriz m;
    int tam_fila, tam_columna;
    int max, min;
    
    cout << "Este programa determina el valor maximo ";
    cout << "y minimo de una matriz maxima de ";
    cout << "20x20 y tambien calcula su normalizada.\n\n";
    
    LeerMatriz (m, tam_fila, tam_columna);
    
    min = MinMaxMatriz(m, tam_fila, tam_columna, max);
    
    cout << "\nLa matriz introducida es: \n";
    MostrarMatriz(m, tam_fila, tam_columna);
    cout << "\nEl valor minimo de la matriz es: " << min << endl;
    cout << "El valor maximo de la matriz es: " << max << endl;
    
    if (max == min)
    {
        cout << "\nLa matriz no se puede normalizar.\n\n";
    }
    else
    {
        Normalizador(m, tam_fila, tam_columna);
        cout << "\nLa matriz con los valores normalizados es: \n";
        MostrarMatriz(m, tam_fila, tam_columna);
        cout << endl << endl;
    }

    return 0;
}

/************************ LeerMatriz *********************//**
*
* Se introduce en la matriz los valores que introduce el usuario
*
* @param[in] m Matriz
* @param[in] tam_fila Numero de filas de la matriz
* @param[in] tam_columna Numero de columnas de la matriz
*
*//*************************************************************/
void LeerMatriz (Matriz m, int & tam_fila, int & tam_columna)
{
    int posicion_fila, posicion_columna;
    
    do
    {
        cout << "Introduce el numero de filas de la Matriz (Max. " << FILA << "): ";
        cin >> tam_fila;
        cout << "Introduce el numero de columnas de la Matriz (Max. " << COLUMNA << "): ";
        cin >> tam_columna;
        cout << endl;
    }
    while (tam_fila <= 0 || tam_fila > FILA || tam_columna <= 0 || tam_columna > COLUMNA);
    
    cout << "Vamos a crear una matriz de " << tam_fila << "x" << tam_columna << endl;
    
    for(posicion_fila = 0; posicion_fila < tam_fila; posicion_fila++)
        for(posicion_columna = 0; posicion_columna < tam_columna; posicion_columna++)
        {
            cout << "Elemento " << posicion_fila << ", " << posicion_columna << ": ";
            cin >> m [posicion_fila] [posicion_columna];
        }
    
    return;
}

/************************ MinMaxVector *********************//**
*
* Calcula el valor minimo y el valor maximo
*
* @param[in] m Matriz
* @param[in] tam_fila Numero de filas de la matriz
* @param[in] tam_columna Numero de columnas de la matriz
* @param[out] max Valor Maximo de la matriz
*
* @return Valor Minimo del vector
*
*//*************************************************************/
int MinMaxMatriz (const Matriz m, int tam_fila, int tam_columna, int & max)
{
    int min;
    int posicion_fila, posicion_columna;
    
    min = max = m[0][0];
    
    for(posicion_fila = 0; posicion_fila < tam_fila; posicion_fila++)
    {
        for(posicion_columna = 0; posicion_columna < tam_columna; posicion_columna++)
        {
            if (m[posicion_fila] [posicion_columna] < min)
            {
                min = m[posicion_fila] [posicion_columna];
            }
            else if (m[posicion_fila] [posicion_columna] > max)
                max = m[posicion_fila] [posicion_columna];
        }
    }
    
    return min;
}

/************************ Normalizador *********************//**
*
* Calcula los valores normalizados de los elementos de la matriz
*
* @param[in] m Matriz
* @param[in] tam_fila Numero de filas de la matriz
* @param[in] tam_columna Numero de columnas de la matriz
*
**************************************************************/
void Normalizador (Matriz m, int tam_fila, int tam_columna)
{
    int min, max;
    int posicion_fila, posicion_columna;
    float denominador, numerador, division, valor_normalizado;

    min = MinMaxMatriz(m, tam_fila, tam_columna, max);

    denominador = max - min;

    for(posicion_fila = 0; posicion_fila < tam_fila; posicion_fila++)
    {
        for(posicion_columna = 0; posicion_columna < tam_columna; posicion_columna++)
        {
            numerador = m[posicion_fila][posicion_columna] - min;
            division = numerador / denominador;
            valor_normalizado = division + min;

            m[posicion_fila][posicion_columna] = valor_normalizado;
        }
    }

    return;
}

/************************ MostrarMatriz *********************//**
*
* Muestra la matriz por pantalla
*
* @param[in] m Matriz
* @param[in] tam_fila Numero de filas de la matriz
* @param[in] tam_columna Numero de columnas de la matriz
*
*//*************************************************************/
void MostrarMatriz(const Matriz m, int tam_fila, int tam_columna)
{
    int posicion_fila, posicion_columna;
    
    for(posicion_fila = 0; posicion_fila < tam_fila; posicion_fila++)
    {
        cout << " |   ";
        for(posicion_columna = 0; posicion_columna < tam_columna; posicion_columna++)
        {
            cout << m [posicion_fila] [posicion_columna] << "   ";
        }
        
        cout << "|"<< endl;
    }
    
    return;
}
