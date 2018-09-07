/**
 * @file tarea1.cpp
 *
 * @brief Tarea 1: Programa que determina el maximo, minimo y media.
 *
 * Este programa muestra por pantalla el valor máximo, el mínimo y la media de
 * ‘n’ números introducidos por teclado
 *
 * @version 1
 * @author Aldemaro Gonzalez
 * @date 22/10/2017
 */

#include <iostream>
using namespace std;

/*
 * Programa Principal
 */
int main()
{
    char eleccion;
    int num_numeros, min, max, numero, i;
    int centinela, acumulador;
    double media = 0.0;
    
    //Empezamos el programa explicando al usuario lo que hace
    cout << "Este programa que muestre por pantalla el valor máximo, el mínimo y la media de";
    cout << " ‘n’ números introducidos por teclado.\n\n";
    
    //Le mostramos las dos opciones al usuario
    cout << "Elige una opcion:\n";
    cout << "A) Por Numero de Numeros.\nB) Por Centinela.\nEleccion: ";
    cin >> eleccion;
    cout << endl;
    
    // Opcion A: Introducion de numeros
    if (eleccion == 'a' || eleccion == 'A')
    {
        cout << "Introduce el numero de numeros: ";
        cin >> num_numeros;
        
        cout << "Numero 1: ";
        cin >> numero;
        min = max = numero;
        media = numero;
        
        for (i = 0; i < num_numeros - 1; i++)
        {
            cout << "Numero " << (i + 2) << ": ";
            cin >> numero;
            
            if (numero < min)
                min = numero;
            else if(numero > max)
                max = numero;
            
            media += numero;
        }
        media /= num_numeros;
        
        cout << "Valor Maximo : " << max << ", ";
        cout << "Valor Minimo : " << min << ", ";
        cout << "Media de numeros introducidos : " << media << endl << endl;
    }
    
    // Opcion B: Centinela
    else if (eleccion == 'b' || eleccion == 'B')
    {
        cout << "Introduce el valor centinela: ";
        cin >> centinela;
        cout << endl;
        
        cout << "Numero 1: ";
        cin >> numero;
        
        if (numero == centinela)
        {
            cout << "Valor Maximo : - \n";
            cout << "Valor Minimo : - \n";
            cout << "Media de numeros introducidos : - \n";
        }
        
        else
        {
            min = max = numero;
            media = numero;
            i = 0;
            acumulador = 1;
            
            while (numero != centinela)
            {
                cout << "Numero " << i + 2 << ": ";
                cin >> numero;
                
                if (numero == centinela)
                {
                    numero = centinela;
                }
                else
                {
                    acumulador++;
                    i++;
                    
                    if (numero < min)
                        min = numero;
                    else if(numero > max)
                        max = numero;
                
                    media += numero;
                }
            } //WHILE
            
            media /= acumulador;
            
            cout << "Valor Maximo : " << max << ", ";
            cout << "Valor Minimo : " << min << ", ";
            cout << "Media de numeros introducidos : " << media  << endl << endl;
        }
    }
    
    else
        cout << "Opcion no valia\n\n";
    
    return 0;
}
