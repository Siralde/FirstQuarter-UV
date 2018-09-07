#include <stdlib.h>     /* srand, rand */
#include <fstream>
#include <cctype>
#include <string>
#include <iostream>
using namespace std;

const int NUMERO_DE_PREGUNTAS = 20;
const int HALL_OF_FAME = 5;
const string FICH_JUGADORES = "puntuaciones.txt";
const string PARTIDASUNJUGADOR = "1partida.txt";    ///< Nombre del fichero donde se guardan los nombre de las partidas guardadas en solitario
const string PARTIDADOSJUGADORES = "2partida.txt";
const int MAX = 6; ///< Numero maximo de elementos de un vector

struct Pregunta
{
    string enunciado;
    string verdadera;
    string falsa1;
    string falsa2;
    string falsa3;
};

typedef Pregunta YaPreguntadas [NUMERO_DE_PREGUNTAS];

struct Categorias
{
    bool tito, albert, hector, bonzo, tina, pop;
};

struct DatosBinarios
{
    int cant_jugadores;
    int puntaje;
    Categorias categorias_ganadas;
    int num_preguntas_realizadas;
};

typedef DatosBinarios VDatosBinarios [2];

struct HallOfFame
{
    string nick;
    int puntuacion;
};

typedef HallOfFame VLosMejores [HALL_OF_FAME];

struct Top
{
    VLosMejores mejores;
    int cant_jugadores;
};

typedef string VNombres_Guardados [10];


bool HallOfFame (string nombre, int puntaje);
bool BusquedaSecOrd(const Top v, int buscado, int & pos, int tam);
bool InsercionOrd(Top & v, int elemento, int pos, int & tam, string nick);
void MostrarVector(const VLosMejores v, int tam);
bool LeerFicheroHallOfFame (ifstream & f, Top & top);

int main (void)
{
    bool respuesta;
    string nick;
    int puntaje;
    
    cout << "Dame el nick: ";
    cin >> nick;
    cout << "Dame el puntaje: ";
    cin >> puntaje;
    
    respuesta = HallOfFame(nick, puntaje);
    
    if(respuesta)
        cout << "\nBien\n";
    else
        cout << "\nMal\n";
    
    return 0;
}
/************************************* HallOfFame ***********************************//**
*
* Muestra los 5 mejores jugadores en solitario
*
* @param [in] nombre    Nick del Jugador
* @param [in] puntaje   Puntaje del jugador
*
* @retval true  Abrio el fichero
* @retval false No abrio el fichero
*
*//*************************************************************************************/
bool HallOfFame (string nombre, int puntaje)
{
    ifstream fich;  //Fichero de lectura
    ofstream fich2; //Fichero de escritura
    bool abrio = false, encontrado, correcto, terminar = false;
    Top top_5;
    int pos, i;
    
    fich.open ( FICH_JUGADORES.c_str () );
    if (!fich)
    {
        fich2.open ( FICH_JUGADORES.c_str() );
        if (!fich2)
        {
            cout << "\nError abriendo abriendo Hall Of Fame...\n\n";
            abrio = false;
        }
        else
        {
            fich2 << "1" << endl;
            fich2 << nombre << " " << puntaje;
            fich2 << endl;
            cout << "\nHall of Fame: ";
            cout << "\nNumero 1: ";
            cout << nombre << " ---> " << puntaje << endl << endl;
            abrio = true;
        }
    }
    else
    {
        while (LeerFicheroHallOfFame(fich, top_5) && terminar == false)
        {
            encontrado = BusquedaSecOrd(top_5, puntaje, pos, top_5.cant_jugadores);
            correcto = InsercionOrd(top_5, puntaje, pos, top_5.cant_jugadores, nombre);
            
            if (correcto)
            {
                if (top_5.cant_jugadores > 5)
                {
                    top_5.cant_jugadores = 5;
                    MostrarVector(top_5.mejores, top_5.cant_jugadores);
                }
                else
                {
                    MostrarVector(top_5.mejores, top_5.cant_jugadores);
                }
                
                fich2.open ( FICH_JUGADORES.c_str() );
                if (!fich2)
                {
                    cout << "\nError abriendo abriendo Hall Of Fame...\n\n";
                    abrio = false;
                }
                else
                {
                    fich2 << top_5.cant_jugadores << endl;
                    for (i = 0; i < top_5.cant_jugadores; i++)
                    {
                        fich2 << top_5.mejores[i].nick << " " << top_5.mejores[i].puntuacion;
                        fich2 << endl;
                    }
                    terminar = true;
                    abrio = true;
                }
            }
        }
    }
    
    return abrio;
}

/******************************** BusquedaSecOrd ****************************//**
*
* Buscamos la posicion correcta donde se debe insertar un
* numero dentro de un vector
*
* @param[in] v          Vector en el que se tiene que introducir
* @param[in] buscado    Valor introducido por el usuario
* @param[in] tam        Tamano actual/real de vector
* @param[out] pos       Indexacion/Posicion donde se debe insertar un valor en el vector
*
* @retval true Si se encotro la posicion donde insertar el valor
* @retval false Si no se encotro la posicion donde insertar el valor
*
*//*********************************************************************************/
bool BusquedaSecOrd(const Top v, int buscado, int & pos, int tam)
{
    pos = 0;
    
    /* Permitimos que pos tome el valor de la primera posicion
     * libre
     */
    while((pos < tam) && (v.mejores[pos].puntuacion > buscado))
        pos++;
    
    return (v.mejores[pos].puntuacion == buscado && pos < tam);
}
//{
//    pos = 0;
//
//    /* Permitimos que pos tome el valor de la primera posicion
//     * libre
//     */
//    while((v[pos].puntuacion > buscado))
//        pos++;
//
//
//    return (v[pos].puntuacion == buscado && pos < tam);
//}

/*************************** InsertarOrd ****************************//**
*
* Inserta numero enteros en un vector ordenadamente de menor a mayor
*
* @param[in]    v           Vector en el que se tiene que introducir
* @param[in]    elemento    Numero que introduciremos en el vector
* @param[in]    pos         Indexacion de un valor en el vector
* @param[out]   tam         Tamano actual/real de vector
* @param[in]    nick        Nick del jugador
*
* @retval true Si el vector no esta lleno
* @retval false Si el vector esta lleno
*
*//***********************************************************************/
bool InsercionOrd(Top & v, int elemento, int pos, int & tam, string nick)
{
    int i;
    bool insertado = false;
    
    if(tam < MAX)
    {
        for(i = tam; i > pos; i--)
            v.mejores[i].puntuacion = v.mejores[i - 1].puntuacion;
        v.mejores[pos].nick = nick;
        v.mejores[pos].puntuacion = elemento;
        tam ++;
        insertado = true;
    }
    
    return insertado;
}
//{
//    int i;
//    bool insertado;
//
//    for(i = tam; i > pos; i--)
//        v[i] = v[i - 1];
//    v[pos].nick = nick;
//    v[pos].puntuacion = elemento;
//    tam ++;
//    insertado = true;
//
//
//    return insertado;
//}

/************************ LeerFicheroHallOfFame ****************************//**
*
* Muestra los 5 mejores jugadores en solitario
*
* @param [out] f     Descriptor del gichero
* @param [out] top   Registro donde almacena la informacion
*
* @retval true  Si se pudo leer el fichero
* @retval false No se pudo leer el fichero
*
*//**************************************************************************/
bool LeerFicheroHallOfFame (ifstream & f, Top & top)
{
    bool lectura_ok = false;
    int i;
    
    f >> top.cant_jugadores;
    f.ignore();
    
    for (i = 0; i < top.cant_jugadores; i++)
    {
        f >> top.mejores[i].nick;
        f >> top.mejores[i].puntuacion;
        lectura_ok = true;
    }
    
    return lectura_ok;
}

/************************ MostrarVector *********************//**
*
* Muestra el vector por pantalla
*
* @param[in] v Vector
* @param[in] tam Numero de Elementos
*
*//*************************************************************/
void MostrarVector(const VLosMejores v, int tam)
{
    int i;
    
    cout << "\n\n\tHall Of Fame\n\n";
    
    for(i = 0; i < tam; i++)
    {
        cout << "Numero " << i + 1 << endl;
        cout << v[i].nick << " ---> " << v[i].puntuacion << endl;
    }
    
    cout << endl;
    
    return;
}
