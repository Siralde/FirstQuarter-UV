/**
 * @file b2_4_diasmes.cpp
 *
 * @brief Tarea 2: Piedra, Papel o Tijera.
 *
 * Este programa que pida por teclado la población inicial de bacterias y un número
 * máximo de las mismas. Una vez leidos ambos valores, el programa escribirá por pantalla
 * la población de cada día, teniendo en cuenta los esquemas de crecimiento especificados,
 * mientras la población no supere el máximo fijado.
 *
 * @version 1
 * @author Aldemaro Gonzalez
 * @date 22/10/2017
 */

#include <iostream>
using namespace std;

int main()
{
    int poblacion_inicial, poblacion_maxima, tasa_poblacion, tasa_crecimiento;
    int i = 1;
    
    //Empezamos el programa explicando al usuario lo que hace
    cout << "Este programa simula ‘n’ partidas del juego: piedra-papel-tijera.\n\n";
    
    //Pedimos al usurario la poblacion inicial y el numero maximo
    cout << "Introduce la poblacion inicial: ";
    cin >> poblacion_inicial;
    cout << "Introduce el numero maximo de las mismas: ";
    cin >> poblacion_maxima;
    
    tasa_poblacion = poblacion_inicial * 100 / poblacion_maxima;
    
    cout << endl << "Dia 1: " << poblacion_inicial << endl;
    
    
    while (tasa_poblacion < 7)
    {
        i++;
        cout << "Dia " << (i) << ": ";
        poblacion_inicial *= 3;
        tasa_poblacion = poblacion_inicial * 100 / poblacion_maxima;
        cout << poblacion_inicial << endl;
    }
    
    while (tasa_poblacion >= 7 && tasa_poblacion < 60)
    {
        i++;
        cout << "Dia " << (i) << ": ";
        tasa_crecimiento = poblacion_inicial / 3;
        //cout << untercio << "\t";
        poblacion_inicial = poblacion_inicial + tasa_crecimiento;
        tasa_poblacion = poblacion_inicial * 100 / poblacion_maxima;
        cout << poblacion_inicial << endl;
    }
    
    while (tasa_poblacion >= 60 && tasa_poblacion <= 80)
    {
        i++;
        cout << "Dia " << (i) << ": ";
        tasa_crecimiento = poblacion_inicial / 78;
        //cout << untercio << "\t";
        poblacion_inicial = poblacion_inicial + tasa_crecimiento;
        tasa_poblacion = poblacion_inicial * 100 / poblacion_maxima;
        cout << poblacion_inicial << "(3)"  << endl;
    }
    
    while (tasa_poblacion > 80)
    {
        i++;
        cout << "Dia " << (i) << ": ";
        tasa_crecimiento = poblacion_inicial / 10;
        //cout << untercio << "\t";
        poblacion_inicial = poblacion_inicial - tasa_crecimiento;
        tasa_poblacion = poblacion_inicial * 100 / poblacion_maxima;
        cout << poblacion_inicial << endl;
    }
    
    return 0;
}

// Este es con float y no se pierden numeros
//#include <iostream>
//using namespace std;
//
//int main()
//{
//    float poblacion_inicial, poblacion_maxima, tasa_poblacion, untercio;
//    int i = 1;
//
//
//    cout << "Introduce la poblacion inicial: ";
//    cin >> poblacion_inicial;
//    cout << "Introduce el numero maximo de las mismas: ";
//    cin >> poblacion_maxima;
//
//    tasa_poblacion = poblacion_inicial * 100 / poblacion_maxima;
//
//    cout << endl << "Dia 1: " << poblacion_inicial << endl;
//
//
//    while (tasa_poblacion < 7.0)
//    {
//        i++;
//        cout << "Dia " << (i) << ": ";
//        poblacion_inicial *= 3;
//        tasa_poblacion = poblacion_inicial * 100 / poblacion_maxima;
//        cout << poblacion_inicial << endl;
//    }
//
//    while (tasa_poblacion >= 7.0 && tasa_poblacion < 60.0)
//    {
//        i++;
//        cout << "Dia " << (i) << ": ";
//        untercio = poblacion_inicial / 3.0;
//        //cout << untercio << "\t";
//        poblacion_inicial = poblacion_inicial + untercio;
//        tasa_poblacion = poblacion_inicial * 100.0 / poblacion_maxima;
//        cout << poblacion_inicial << endl;
//    }
//
//    while (tasa_poblacion >= 60.0 && tasa_poblacion < 80.0)
//    {
//        i++;
//        cout << "Dia " << (i) << ": ";
//        untercio = poblacion_inicial / 78.0;
//        //cout << untercio << "\t";
//        poblacion_inicial = poblacion_inicial + untercio;
//        tasa_poblacion = poblacion_inicial * 100.0 / poblacion_maxima;
//        cout << poblacion_inicial << endl;
//    }
//
//
//    return 0;
//}
