/**
 * @file b1_2_grados.cpp
 *
 * @brief Ejercicio 02. Boletin 1.
 *
 * Este programa nos pasa una medida de un angulo en grados sexagesimales a su equivalente
 * en grados centesimales y radianes
 *
 * @version 1
 * @author Aldemaro Gonzalez
 * @date 4/10/2017
 */

#include <iostream>
using namespace std;

const unsigned char GRADOS_A_MINYSEG = 1; ///< Un grado sexagesimal equivale a 60 minutos y 60^2 segundos
const short TRES_GRADOS_SEXA = 360; ///< Cambio de 360 grados sexagesimales a 400 grados centesimales
const short CUATRO_GRADOS_CTSM = 400; ///< 400 grados centesimales equivalen 360 grados sexagesimales
const double PI = 3.1415926536; ///< Valor de PI
const short IGUALDAD_RADEANES_GRADOS = 180; ///< Cambio de un radean a grados
const short SEGUNDOS_A_MINUTOS_SEXA = 60;   ///<Cambio de segundos sexagesimales a minutos sexagesimales
const short MINUTOS_A_GRADOS_SEXA = 60;   ///<Cambio de minutos sexagesimales a grados sexagesimales

/**
 * Funcion principal
 */
int main (void)
{
    //Las siguientes variables las utilizo para almacenar los datos de entrada
    short grados_sexa, minutos_sexa, total_segs_grados;
    //Las siguientes variables las utilizo para realizar la conversion sexagesimal a centesimal
    float mins_a_grados, segs_a_grados, segundos_sexa, grados_sexa_1;
    float segundos_minutos, total_minutos, minutos_grados, total_grados;
    double grados_csml;
    //Las siguientes variables las utilizo para realizar la conversion a radeanes
    double num_radianes;
    int grados;
    int minutos;
    float segundos;
    
    //Empezamos el programa explicando al usuario lo que hace
    cout << "Este programa nos pasa una medida de un angulo en grados sexagesimales a ";
    cout << "su equivalente en grados centesimales y radianes.\n\n";
    
    //Pedimos al usurario la distancia en metros
    cout << "Dame angulo en grados sexagesimales: ";
    cin >> grados_sexa;
    cout << "Dame angulo en minutos sexagesimales: ";
    cin >> minutos_sexa;
    cout << "Dame angulo en segundos sexagesimales: ";
    cin >> segundos_sexa;
    
    /*
     * Pasamos los minutos y segundos a grados sexagesimales
     */
    // Ahora pasamos de minutos sexagesimales a grados sexagesimales
    mins_a_grados = (minutos_sexa * GRADOS_A_MINYSEG) / float (MINUTOS_A_GRADOS_SEXA);
    // Ahora pasamos de segundos sexagesimales a grados sexagesimales
    total_segs_grados = MINUTOS_A_GRADOS_SEXA * SEGUNDOS_A_MINUTOS_SEXA;
    segs_a_grados = ((segundos_sexa * GRADOS_A_MINYSEG) / float (total_segs_grados));
    grados_sexa_1 = grados_sexa + mins_a_grados + segs_a_grados; //Total Grados sexagesimales
   
    /*
     * Pasamos los grados sexagesimales a centesimales
     */
    grados_csml = (grados_sexa_1 * CUATRO_GRADOS_CTSM) / TRES_GRADOS_SEXA;
    
    /*
     * Ponemos los grados centesimales en grados, minutos y segundos
     */
    grados = (grados_csml);
    minutos = ((grados_csml * 100) - (grados * 100));
    segundos = ((grados_csml * 10000) - (grados * 10000) - (minutos * 100));
    
    /*
     * Pasamos de grados a radianes
     */
    segundos_minutos = segundos_sexa / SEGUNDOS_A_MINUTOS_SEXA; // Los segundos los cambiamos a mintuos
    total_minutos = minutos_sexa + segundos_minutos; // Sumamos todos los minutos
    minutos_grados = total_minutos / MINUTOS_A_GRADOS_SEXA; // El total de minutos lo cambiamos a grados
    total_grados = (grados_sexa + minutos_grados); // Sumamos todos los grados
    num_radianes = total_grados * (PI/IGUALDAD_RADEANES_GRADOS); // El total de grados lo cambiamos a radianes
    
    //Mostramos los resultados obtenidos
    cout << "\nGrados sexagesimales: " << grados_sexa << "o " << minutos_sexa << "' " << segundos_sexa <<"''";
    cout << "\nGrados centesimales: " << grados << "g " << minutos <<"m "<< segundos << "s" ;
    cout << "\nRadianes: " << num_radianes << endl << endl;
    
    return 0;
}
