/**
 * @file main.cpp
 *
 * @brief Tarea2: Laboratorio, Practica5.
 *
 *
 * @version 1
 * @author Aldemaro Gonzalez
 * @date //2017
 */
#include <iostream>
using namespace std;
#include <cstdlib>

const int MAX = 20;


int main (void)
{
    Vector vec;
    
    int num_elementos;
    float media, desviación;
    
    cout << "Este programa pide un vector de, a lo suma, " << MAX;
    cout << " elementos, y calcula su media y su desviación";
    cout << " estandar.\n\n";
    
    cout << "Introduce el vector:\n";
    num_elementos = LeerVector (vec);
    
    media = CalcularMediaVector (vec, num_elementos);
    
    desviación = CalcularDesviacionEstandar (vec, num_elementos);
    
    cout << "El vector introducido es:\n";
    MostrarVector (vec, num_elementos);
    cout << endl;
    cout << "La media de los valores del vector es: " << media;
    cout << endl;
    cout << "La desviación estandar es: " << desviacion << endl;
   
    return 0;
}
