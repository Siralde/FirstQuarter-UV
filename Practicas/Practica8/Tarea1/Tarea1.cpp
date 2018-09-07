/**
 * @file Tarea1.cpp
 *
 * @brief Ejercicio 01: Laboratoria 8, Tabla con valores de la raiz cuadrada.
 *
 * Muestra una tabla con los valores de la raíz cuadrada de
 * los números del 1 al 100.
 *
 * @version 1
 * @author Aldemaro Gonzalez
 * @date 14/12/2017
 */
#include <fstream>
#include <math.h>
#include <iostream>
using namespace std;

const int MAX = 100;

/**
 * Funcion principal
 */
int main (void)
{
    ofstream f;
    int i, num;
    float raiz;
    
    //Empezamos el programa explicando al usuario lo que hace
    cout << "Muestre una tabla con los valores de la raíz cuadrada de los números del 1 al 100.\n\n";
    
    cout << "---------------------- ";
    cout << "\nNumero\tRaiz Cuadrada\n";
    cout << "----------------------\n";
    
    f.open("TablaRaizCuadrada.txt");
    if(!f)
        cout << "Error abriendo el fichero" << endl;
    else
    {
        for (i = 1; i <= MAX; i++)
        {
            num = i;
            raiz = sqrt(i);
            f << num << "\t\t" << raiz << endl;
            cout << num << "\t\t" << raiz << endl;
        }
        
        f.close();
        
        cout << endl;
    }
    
    return 0;
}
