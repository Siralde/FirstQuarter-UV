/**
 * @file b3_3_piramide.cpp
 *
 * @brief Ejercicio 03: construccion de piramides.
 *
 * Este programa muestra una pirámide conformada entre
 * los números 4 y 1560, que sean impares.
 *
 * @version 1
 * @author Aldemaro Gonzalez
 * @date 27/10/2017
 */

#include <iostream>
using namespace std;

const int MINIMO = 4;       ///< Altura minima de la piramide
const int MAXIMO = 1560;    ///< Altura maxima de la piramide

/**
 * Funcion principal
 */
int main (void)
{
    int altura, impar;
    int cantidad_fila; // Conteo de Filas
    int n; // Contador 
    int espacio_blanco;
    char space = ' ';
    int descendente;
    
    cout << "Este programa muestra una pirámide ";
    cout << "conformada entre los números 4 y 1560, que sean impares.\n\n";
    
    cout << "Dame altura de la piramide (valor impar entre 4 y 1560): " ;
    cin >> altura;
    cout << endl;
    
    impar = altura % 2;
    
    // Comprobacion de altura par o impar
    if (impar == 0)
        cout << "El numero no es impar, intentalo de nuevo.\n\n";
   
    // Comprobacion de que esta entre la altura maxima y minima
    else if ( altura < MINIMO || altura > MAXIMO)
        cout << "El numero no esta en el rango indicado, intentalo de nuevo.\n\n";
    
    // Creacion de la piramide
    else
    {
        for (cantidad_fila = 1; cantidad_fila <= altura ; cantidad_fila++)
        {
            // Creacion de espacios en blancos para darle forma de piradime
            espacio_blanco = altura - cantidad_fila;
            for (n = 0; n < espacio_blanco ; n++ )
                cout << space ;
            
            // Creacion del conjunto de numeros ascendentes
            for (n = 1; n <= cantidad_fila ; n++ )
                cout << n ;
            
            // Creacion del conjunto de numeros descendentes
            descendente = cantidad_fila - 1;
            for (n = descendente ; n >= 1; n--)
                cout << n;
            
            // Para pasar a la siguiente fila
            cout << endl;
        } //FOR
    }//ELSE
    
    return 0;
}
