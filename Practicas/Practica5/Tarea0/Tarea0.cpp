/**
 * @file Tarea0.cpp
 *
 * @brief Tarea0: Laboratorio, Practica5.
 *
 *
 * @version 1
 * @author Aldemaro Gonzalez
 * @date //2017
 */

#include <iostream>
using namespace std;

const int NUM = 5;

typedef int Vector[NUM];

void IniciarVector (Vector);
int SumarElementos (const Vector);

int main (void)
{
    int suma;
    Vector v;
    IniciarVector (v);
    
    suma = SumarElementos (v);
    
    cout << "La suma de los elementos del vector es: ";
    cout << suma << endl;
    
    return 0;
}

void IniciarVector (Vector v)
{
    int i;
    
    for (i = 0; i < NUM; i++)
        v[i] = 2 * i;
    
    return;
}

int SumarElementos (const Vector v)
{
    int i, suma = 0;
    
    for (i = 0; i < NUM; i++)
        suma += v[i];
    
    return suma;
}

void MostrarVector (const Vector v)
{
    int i;
    
    cout << "Los elementos del vector son:";
    
    for (i = 0; i < NUM; i++)
        cout << v[i] << ", ";
    
    return;
}

