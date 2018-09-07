/**
 * @file b2_1_caracteres.cpp
 *
 * @brief Ejercicio 01: numero asociado a un dia, caracter asociado a un numero.
 *
 * Este programa nos muestra el dia de la semana asociado a un caracter si este es un digito
 * o el numero de orden si es un caracter alfabetico.
 *
 * @version 1
 * @author Aldemaro Gonzalez
 * @date 18/10/2017
 */

#include <iostream>
using namespace std;

/**
 * Funcion principal
 */
int main (void)
{
    char caracter, caracter_minuscula;
    
    //Empezamos el programa explicando al usuario lo que hace
    cout << "Este programa nos muestra el dia de la semana asociado a un caracter ";
    cout << "si este es un digito o el numero de orden si es un caracter alfabetico.\n\n";
    
    //Pedimos al usurario la velocidad y el limite de circulacion sobre la via
    cout << "Dame un solo caracter: ";
    cin >> caracter;
    cout << endl;
    
    //Comprobamos si el caracter es una letras mayuscula
    if ((caracter >= 'A') && (caracter <= 'Z'))
    {
        caracter_minuscula = int ('a') + (int(caracter) - int('A'));
        cout << "El numero de orden asociado al caracter '" << caracter_minuscula << "' es " << caracter - 'A' + 1 << endl << endl;
    }
    
    //Comprobamos si el caracter es una letra minuscula
    else if ((caracter >= 'a') && (caracter <= 'z'))
    {
        cout << "El numero de orden asociado al caracter '" << caracter  << "' es " << caracter - 'a' + 1 << endl << endl;
    }
    
    //Comprobamos si el caracter es un numero del 1 al 7
    else
    {
        switch (caracter)
        {
            case '0':
                cout << "El numero " << caracter << " no corresponde a ningun dia de la semana.\n\n";
                break;
            case '1':
                cout << "El dia de la semana asociado al caracter '1' es lunes\n\n";
                break;
            case '2':
                cout << "El dia de la semana asociado al caracter '2' es martes\n\n";
                break;
            case '3':
                cout << "El dia de la semana asociado al caracter '3' es miercoles\n\n";
                break;
            case '4':
                cout << "El dia de la semana asociado al caracter '4' es jueves\n\n";
                break;
            case '5':
                cout << "El dia de la semana asociado al caracter '5' es viernes\n\n";
                break;
            case '6':
                cout << "El dia de la semana asociado al caracter '6' es sabado\n\n";
                break;
            case '7':
                cout << "El dia de la semana asociado al caracter '7' es domingo\n\n";
                break;
            case '8':
                cout << "El numero " << caracter << " no corresponde a ningun dia de la semana.\n\n";
                break;
            case '9':
                cout << "El numero " << caracter << " no corresponde a ningun dia de la semana.\n\n";
                break;
            default:
                cout << "El caracter no es alfanumerico\n\n";
        } // SWITCH
    } // ELSE

    return 0;
}

/**
 * BANCO DE PRUEBAS
 * ENTRADA = SALIDA
 * Z = El numero de orden asociado al caracter 'z' es 26
 * z = El numero de orden asociado al caracter 'z' es 26
 * A = El numero de orden asociado al caracter 'a' es 1
 * a = El numero de orden asociado al caracter 'a' es 1
 * 1 = El dia de la semana asociado al caracter '1' es lunes
 * 7 = El dia de la semana asociado al caracter '7' es domingo
 */

