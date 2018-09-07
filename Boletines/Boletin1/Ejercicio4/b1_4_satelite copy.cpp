/**
 * @file b1_4_satelite.cpp
 *
 * @brief Ejercicio 04. Boletin 1.
 *
 * Este programa determina la velocidad media de un satelite en orbita
 *
 * @version 1
 * @author Aldemaro Gonzalez
 * @date 6/10/2017
 */

#include <iostream>
using namespace std;

const double SEGUNDOS_MINUTOS = 60.0; ///< Cambio de segundos a minutos
const double MINUTOS_HORAS = 60.0; ///< Caso de minutos a horas
const double PI = 3.1415926536; ///< Valor de PI
const int METRO_KILO = 1000; ///< Equivalecua de un metro sobre un kilometro

/**
 * Funcion principal
 */
int main (void)
{
    
    int horas, minutos, segundos, ra;
    float radio, altura, segundos_horas, minutos_horas, tiempo_h, velocidad_media, vm_hs;
    
    //Empezamos el programa explicando al usuario lo que hace
    cout << "Este programa determina la velocidad media de un satelite en orbita" << endl;
    
    //Pedimos al usurario el radio del planeta, la altura a la que orbita satelite y el tiempo de una orbita
    cout << "\nDame radio del planeta orbitado (en km): ";
    cin >> radio;
    cout << "Dame altura a la que orbita el satelite (en km): ";
    cin >> altura;
    cout << "Dame tiempo de la orbita: " << endl;
    cout << "   Horas: ";
    cin >> horas;
    cout << "   Minutos: ";
    cin >> minutos;
    cout << "   Segundos: ";
    cin >> segundos;
    
    /*
     * Calculamos el tiempo en horas
     */
    segundos_horas = segundos / (SEGUNDOS_MINUTOS * MINUTOS_HORAS);
    minutos_horas = minutos / (MINUTOS_HORAS);
    tiempo_h = horas + minutos_horas + segundos_horas;
   
    /*
     * Calculamos la velocidad media en kilometros sobre horas
     */
    ra = radio + altura;
    velocidad_media = (2 * PI * ra) / tiempo_h;
    
    /*
     * Calculamos la velocidad media en metros sobre segundos
     */
    vm_hs = velocidad_media * METRO_KILO / (MINUTOS_HORAS * SEGUNDOS_MINUTOS) ;
    
    //Mostramos los resultados obtenidos
    cout << "\nLa velocidad del satelite es de " << velocidad_media << " km/h";
    cout << " (" << vm_hs << " m/s)" << endl;
    
    return 0;
}
