/**
 * @file b7_4_raking.cpp
 *
 * @brief Ejercicio 04: Boletin 7, Ranking de un Juego.
 *
 * Gestion del raking de un juego
 *
 * @version 1
 * @author Aldemaro Gonzalez
 * @date 26/12/2017
 *
 */
#include <string>
#include <iostream>
using namespace std;

const int MAX = 50; ///< Numero maximo de elementos de un vector
//
typedef int TipoBase;
//
typedef int Vector [MAX];
//
struct Jugador
{
    string nick;
    int puntuacion;
};
typedef Jugador jugador[MAX];

//
void InsertarElemento(Vector v, int & posicion);
bool BusquedaSecOrd(const Vector v, TipoBase buscado, int & pos, int tam);
bool InsercionOrd(Vector v, TipoBase elemento, int pos, int & tam);
void MostrarVector(const Vector v, int tam, const jugador);

/**
 * Funcion principal
 */
int main (void)
{
    jugador player;
    Vector vector;
    int opcion, tamano = 0;
    int pos;
    TipoBase elem;
    bool encontrado, correcto;
    
    int i, cant_jugadores = 0, total_jugadores, mas_jugadores;
    
    //Pedimos al usurario
    cout << "Para insertar un elemento, pulsa 1\n";
    cout << "Para mostrar el vector, pulsa 2\n";
    cout << "Para salir, pulsa 0\n";
    
    do
    {
        cout << "\nELIGA UNA OPCION: ";
        cin >> opcion;
        
        switch (opcion)
        {
            case 0:
                cout << endl;
                break;
            case 1:
                cout << "\n Cuantos Jugadores quieres anadir: ";
                if (cant_jugadores == 0)
                {
                    cin >> cant_jugadores;
                    cout << endl;
                    for (i = 0; i < cant_jugadores; i++)
                    {
                        cout << "Dame el nickname: ";
                        cin >> player[i].nick;
                        cout << "Introduce la puntuacion: ";
                        cin >> elem;
                        player[i].puntuacion = elem;
                        encontrado = BusquedaSecOrd(vector, elem, pos, tamano);
                        correcto = InsercionOrd(vector, elem, pos, tamano);
                        if (!correcto)
                            cout << "El vector esta lleno.\n";
                    }
                }
                else
                {
                    cin >> mas_jugadores;
                    cout << endl;
                    total_jugadores = cant_jugadores + mas_jugadores;
                    for (i = cant_jugadores; i < total_jugadores; i++)
                    {
                        cout << "Dame el nickname: ";
                        cin >> player[i].nick;
                        cout << "Introduce la puntuacion: ";
                        cin >> elem;
                        player[i].puntuacion = elem;
                        encontrado = BusquedaSecOrd(vector, elem, pos, tamano);
                        correcto = InsercionOrd(vector, elem, pos, tamano);
                        if (!correcto)
                            cout << "El vector esta lleno.\n";
                    }
                }
                break;
            case 2:
                MostrarVector(vector, tamano, player);
                break;
            default:
                cout << "\nOpcion no valida, vuelva a intentarlo\n\n";
                break;
        }
    } while (opcion != 0);
    
    
    return 0;
}

/******************************** BusquedaSecOrd ****************************//**
*
* Buscamos la posicion correcta donde se debe insertar un
* numero dentro de un vector
*
* @param[in] v Vector en el que se tiene que introducir
* @param[in] buscado Valor introducido por el usuario
* @param[in] tam Tamano actual/real de vector
* @param[out] pos Indexacion/Posicion donde se debe insertar un valor en el vector
*
* @reval true Si se encotro la posicion donde insertar el valor
* @reval false Si no se encotro la posicion donde insertar el valor
*
*//*********************************************************************************/
bool BusquedaSecOrd(const Vector v, TipoBase buscado, int & pos, int tam)
{
    pos = 0;
    
    /* Permitimos que pos tome el valor de la primera posicion
     * libre
     */
    while((pos < tam) && (v[pos] > buscado))
        pos++;
    
    return (v[pos] == buscado && pos < tam);
}

/*************************** InsertarOrd ****************************//**
*
* Inserta numero enteros en un vector ordenadamente de mayor a menor
*
* @param[in] v Vector en el que se tiene que introducir
* @param[in] elemento Numeros que introduciremos en el vector
* @param[in] pos Indexacion de un valor en el vector
* @param[out] tam Tamano actual/real de vector
*
* @reval true Si el vector no esta lleno
* @reval false Si el vector esta lleno
*
*//***********************************************************************/
bool InsercionOrd(Vector v, TipoBase elemento, int pos, int & tam)
{
    int i;
    bool insertado = false;
    
    if(tam < MAX)
    {
        for(i = tam; i > pos; i--)
            v[i] = v[i - 1];
        v[pos] = elemento;
        tam ++;
        insertado = true;
    }
    
    return insertado;
}

/************************ MostrarVector *********************//**
*
* Muestra el vector por pantalla
*
* @param[in] v Vector
* @param[in] tam Numero de Elementos
*
*//*************************************************************/
void MostrarVector(const Vector v, int tam, const jugador player)
{
    int i, j;
    
    cout << "\n El raking es: \n";
    
    for(i = 0; i < tam; i++)
    {
        cout << "Posicion " << i + 1 << endl;
        
        for (j = 0; j < tam; j ++)
        {
            if (v[i] == player[j].puntuacion)
            {
                cout << "Nick: " << player[j].nick << "\t";
                cout << "Puntuacion: " << player[j].puntuacion << endl;
            }
        }
    }

    cout << endl;
    
    return;
}
