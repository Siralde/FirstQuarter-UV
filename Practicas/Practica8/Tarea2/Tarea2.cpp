/**
 * @file Tarea2.cpp
 *
 * @brief Ejercicio 02: Laboratoria 8, Guarda los valores en un fichero binario.
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
    ofstream fich;
    int i, num;
    float raiz;
    
    //Empezamos el programa explicando al usuario lo que hace
    cout << "Muestre una tabla con los valores de la raíz cuadrada de los números del 1 al 100.\n\n";
    
    cout << "---------------------- ";
    cout << "\nNumero\tRaiz Cuadrada\n";
    cout << "----------------------\n";
    
    fich.open("raiz.bin", ios::binary);
    if(!fich)
        cout << "Error abriendo el fichero" << endl;
    else
    {
        for (i = 1; i <= MAX; i++)
        {
            num = i;
            raiz = sqrt(i);
            fich.write ( (char *) (& num), sizeof (num));
            fich.write ( (char *) (& raiz), sizeof (raiz));
            cout << i << "\t\t" << raiz << endl;
        }
        
        fich.close();
        
        cout << endl;
    }
    
    return 0;
}

