/**
 * @file tarea3.cpp
 *
 * @brief Tarea 3: Piedra, Papel o Tijera.
 *
 * Este programa simula ‘n’ partidas del juego: piedra-papel-tijera.
 *
 * @version 1
 * @author Aldemaro Gonzalez
 * @date 22/10/2017
 */

#include <stdlib.h>
#include <iostream>
using namespace std;

/**
 * Funcion principal
 */
int main (void)
{
    int jugador_1, jugador_2, numero_partidas;
    unsigned int numero;
    
    //Empezamos el programa explicando al usuario lo que hace
    cout << "Este programa simula ‘n’ partidas del juego: piedra-papel-tijera.\n\n";
    
    //Pedimos al usurario la fecha
    cout << "Dame el numero de partidas a simular: ";
    cin >> numero;
    cout << endl;
    
    
    //Partidas
    for (numero_partidas = 0; numero_partidas <= numero; numero_partidas++)
    {
        cout << "Partida Numero " << numero_partidas + 1 << endl;
        srand(numero);
        jugador_1 = 1 + rand () % 3; // 1 2 3
        srand(numero_partidas);
        jugador_2 = 1 + rand () % 3; // 1 2 3
        cout << jugador_1 << "\t" << jugador_2 << endl;
        
    }
    return 0;
}
