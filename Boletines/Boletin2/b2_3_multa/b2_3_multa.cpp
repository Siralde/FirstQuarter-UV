/**
 * @file b2_3_multa.cpp
 *
 * @brief Ejercicio 03: Determina si hay multa, el importe y puntos.
 *
 * Este programa determina depediendo de la velocidad si una persona tiene una multa o no.
 * En el caso de tenerla tambien nos da el importe y los puntos de sancion
 *
 * @version 1
 * @author Aldemaro Gonzalez
 * @date 16/10/2017
 */

#include <iostream>
using namespace std;

/**
 * Funcion principal
 */
int main (void)
{
    int velocidad, limite, sancion;
    
    //Empezamos el programa explicando al usuario lo que hace
    cout << "Este programa calcula si tenemos multa o no. Si la tenemos tambien calcula ";
    cout << "el importe y los puntos de la sancion a partir de la velocidad a la que circulamos ";
    cout << "y el limite de velocidad de la via.\n\n";
    
    //Pedimos al usurario la velocidad y el limite de circulacion sobre la via
    cout << "Dime la velocidad de circulacion: ";
    cin >> velocidad;
    cout << "Dime limite de la via: ";
    cin >> limite;
    
    //Calculamos la diferencia que hubo entre la velocidad y limite para poder establecer si tiene o no sancion.
    sancion = velocidad - limite;
    
    if (limite < 30)
    {
        cout << "\nLimite no valido, vuelve a intentarlo introduciendo otro limte ";
        cout << "mayor o igual a 30.\n\n";
    }
    
    else if (sancion <= 0)
        cout << "\nNo hay sancion.\n\n";
    
    /*
     * En el caso de tener saccion, definimos cuanto es el importe y los puntos
     * mediante la diferencia de la velocidad y limite(sancion).
     * Teniendo en cuenta los valores de los limites iguales y menores a 50
     * dados por la Direccion General de Trafico de España
     */
    else if (sancion > 0 && limite <= 50)
    {
        if (sancion >= 1 && sancion <= 20)
            cout << "\nHay sanción. El importe es de 100 euros y 0 puntos.\n\n";
        else if (sancion >= 21 && sancion <= 30)
            cout << "\nHay sanción. El importe es de 300 euros y 2 puntos.\n\n";
        else if (sancion >= 31 && sancion <= 40)
            cout << "\nHay sanción. El importe es de 400 euros y 4 puntos.\n\n";
        else if (sancion >= 41 && sancion <= 50)
            cout << "\nHay sanción. El importe es de 500 euros y 6 puntos.\n\n";
        else if (sancion >= 51)
            cout << "\nHay sanción. El importe es de 600 euros y 6 puntos.\n\n";
    }
    
    /*
     * En el caso de tener saccion, definimos cuanto es el importe y los puntos
     * mediante la diferencia de la velocidad y limite(sancion).
     * Teniendo en cuenta los valores de los limites iguales y menores a 60
     * (Estos son diferentes a los limetes iguales o menos que 50)
     * dados por la Direccion General de Trafico de España
     */
    else if (sancion > 0 && limite >= 60)
    {
        if (sancion >= 1 && sancion <= 30)
            cout << "\nHay sanción. El importe es de 100 euros y 0 puntos.\n\n";
        else if (sancion >= 31 && sancion <= 50)
            cout << "\nHay sanción. El importe es de 300 euros y 2 puntos.\n\n";
        else if (sancion >= 61 && sancion <= 70)
            cout << "\nHay sanción. El importe es de 400 euros y 4 puntos.\n\n";
        else if (sancion >= 71 && sancion <= 80)
            cout << "\nHay sanción. El importe es de 500 euros y 6 puntos.\n\n";
        else if (sancion >= 81)
            cout << "\nHay sanción. El importe es de 600 euros y 6 puntos.\n\n";
    }
    
    return 0;
}

/**
 * BANCO DE PRUEBAS
 * ENTRADA = SALIDA
 * Velocidad: 104, Limite: 90  = Hay sancion. El importe es de 100 euros y 0 puntos.
 * Velocidad: 65, Limite: 30  = Hay sancion. El importe es de 100 euros y 0 puntos.
 * Velocidad: 100, Limite: 60  = Hay sanción. El importe es de 300 euros y 2 puntos.
 * Velocidad: 200, Limite: 120  = Hay sanción. El importe es de 600 euros y 6 puntos.
 * Velocidad: 100, Limite: 20  = Limite no valido, vuelve a intentarlo...
 * Velocidad: 100, Limite: 120  = No hay sancion.
 */

