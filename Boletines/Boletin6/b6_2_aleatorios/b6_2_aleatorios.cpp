/**
 * @file b6_2_aleatorios.cpp
 *
 * @brief Ejercicio 02: Boletin 6, Gesnerador de vector.
 *
 * Este programa genere los elementos de un vector de a lo sumo
 * 50 elementos y lo muestre por pantalla.
 *
 * @version 1
 * @author Aldemaro Gonzalez
 * @date 12/11/2017
 */
#include <stdlib.h>
#include <time.h>
#include <iostream>
using namespace std;

const int MAX = 50;

typedef float Vector [MAX];

void GenerarVector (Vector, int);
bool BuscadorDeRepetidos (const Vector, int, int);
void MostrarVector (const Vector, int);

int main (void)
{
    Vector v;
    int num;
    
    do
    {
        cout << "Dame número de elementos del vector (de un maximo de 50): ";
        cin >> num;
    }
    while (num < 0 || num > 50);

    GenerarVector (v, num);
    
    cout << "El vector generado es: ";
    MostrarVector (v, num);
    
    return 0;
}

/************************ GenerarVector *********************//**
*
* Crea un vector aleatorio
*
* @param[in] v Vector
* @param[in] num Numero de Elementos
*
*//*************************************************************/
void GenerarVector (Vector v, int num)
{
    int i, comprobar;
    
    srand(num);
    
    for (i = 0; i < num; i++)
    {
        if (i == 0)
        {
            v[i] = rand() % num;
        }
        else
        {
            do
            {
                v[i] = rand() % num;
                comprobar = v[i];
            }
            while ((BuscadorDeRepetidos(v, comprobar, i) != false));
        }
        
    }
}
/************************ BuscadorDeRepetidos *********************//**
*
* Busca elementos repetidos en un vector
*
* @param[in] v Vector
* @param[in] num_comprobar Numero que se quiere saber si esta repetido
* @param[in] tam Tamanyo del vector
*
* @reval true si se encuentra repetido el numero a comprobar
* @reval false si no se encuentra repetido el numero a comprobar
*
*//********************************************************************/
bool BuscadorDeRepetidos (const Vector v, int num_comprobar, int tam)
{
    int i = 0;
    bool repetido = false;
    
    for (i = 0; i < tam; i++)
    {
        if (num_comprobar == v[i])
            repetido = true;
    }
    
    return repetido;
}

/************************ MostrarVector *********************//**
*
* Muestra el vector por pantalla
*
* @param[in] v Vector
* @param[in] num Numero de Elementos
*
*//*************************************************************/
void MostrarVector(const Vector v, int num)
{
    int i;
    
    cout << "\n";
    
    for(i = 0; i < num; i++)
    {
        if (i == num - 1 )
        {
            cout << v[i];
        }
        else
        cout << v[i] << ",  ";
    }
    
    cout << endl;
    
    return;
}
