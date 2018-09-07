/**
 * @file b2_2_ritcher.cpp
 *
 * @brief Ejercicio 02: Determina la magnitud de un terremoto y sus daños.
 *
 * Este programa determina los efectos de un terremoto a partir de la magnitud local
 * medida en la escala de Ritcher, obtenida a partir de la amplitud <en milimetros> y el tiempo en segundos>
 *
 * @version 1
 * @author Aldemaro Gonzalez
 * @date 18/10/2017
 */

#include <iostream>
using namespace std;
#include <math.h>


const int MULTIPLO_LOG = 3; ///< Este valor es neceario para satisfacer la formula de magnitud
const int MULTIPLO_TIEMPO = 8; ///< Este valor es necesario para satisfacer la formula de magnitud
const float RESTAR = 2.92; ///< Este valor es necesario para satisfacer la formula de magnitud

/**
 * Funcion principal
 */
int main (void)
{
   
    int amplitud, tiempo;
    float magnitud;
    
    //Empezamos el programa explicando al usuario lo que hace
    cout << "Este programa determina los efectos de un terremoto a partir de la magnitud local ";
    cout << "medida en la escala de Ritcher, obtenida a partir de la amplitud <en milimetros> y el tiempo en segundos\n\n";
    
    //Pedimos al usurario la velocidad y el limite de circulacion sobre la via
    cout << "Dame la amplitud <en milimetros>: ";
    cin >> amplitud;
    cout << "Dame el tiempo <en segundos>: ";
    cin >> tiempo;
    
    //Formula para obtener la magnitud de un terremoto
    magnitud = log10(amplitud) + MULTIPLO_LOG * log10(MULTIPLO_TIEMPO * tiempo) - RESTAR;
    
    //Verificamos la escala de la magnitud del terremoto y mostramos los datos en pantalla
    if (magnitud < 3.5)
    {
        cout << "La magnitud del terremoto es " << magnitud << " en la escala Ritcher.";
        cout << "Imperciptible";
    }
    
    else if (magnitud >= 3.5 && magnitud <= 5.4)
    {
        cout << "La magnitud del terremoto es " << magnitud << " en la escala Ritcher.\n";
        cout << "Perceptible, pero solo causa danos menores.\n\n";
    }
    
    else if (magnitud >= 5.5 && magnitud <= 6.0)
    {
        cout << "La magnitud del terremoto es " << magnitud << " en la escala Ritcher.\n";
        cout << "Ocasiona danos ligeros a edificios.\n\n";
    }
    
    else if (magnitud >= 6.1 && magnitud <= 6.9)
    {
        cout << "La magnitud del terremoto es " << magnitud << " en la escala Ritcher.\n";
        cout << "Puede ocasionar danos severos en areas muy pobladas.\n\n";
    }
    
    else if (magnitud >= 7.0 && magnitud <= 7.9)
    {
        cout << "La magnitud del terremoto es " << magnitud << " en la escala Ritcher.\n";
        cout << "Terremoto mayor, Causa graves danos.\n\n";
    }
    
    else
    {
        cout << "La magnitud del terremoto es " << magnitud << " en la escala Ritcher.\n";
        cout << "Gran terremoto. Destruccion total a comunidades cercanas.\n\n";
    }
    
    return 0;
}
