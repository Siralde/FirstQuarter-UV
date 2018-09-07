/**
 * @file b6_1_laboratorio.cpp
 *
 * @brief Ejercicio 01: Boletin 6, Gestion de un vector.
 *
 * Este programa permite gestionar un vector, es decir permite insertar, eliminar,
 * buscar un elemento y tambien puede mostrar el vector
 *
 * @version 1
 * @author Aldemaro Gonzalez
 * @date 28/11/2017
 *
 */

#include <iostream>
using namespace std;

const int MAX = 6; ///< Numero maximo de elementos de un vector
//
typedef int TipoBase;
//
typedef int Vector [MAX];
//
bool BusquedaSecOrd(const Vector v, TipoBase buscado, int & pos, int tam);
bool InsercionOrd(Vector v, TipoBase elemento, int pos, int & tam);
//
void InsertarElemento(Vector v, int & posicion);
void EliminarElemento(Vector v, int valor_eliminar, int & tam);
bool BuscarElemento(Vector v,int valor_buscar, int tam, int & conteo_repetido);
void PosicionElementoRepetido(Vector v,int valor_buscar, int tam);
void MostrarVector(const Vector v, int tam);

/**
 * Funcion principal
 */
int main (void)
{
    Vector vector;
    int opcion, tamano = 0, valor_eliminar, valor_buscar;
    //
    int pos;
    TipoBase elem;
    bool encontrado, correcto;
    
    //Empezamos el programa explicando al usuario lo que hace
    cout << "Este programa permite gestionar un vector, es decir, permite insertar, eliminar, ";
    cout << " buscar un elemento y tambien puede mostrar el vector.\n";
    
    //Pedimos al usurario
    cout << "\nPara insertar un elemento, pulsa 1\n";
    cout << "Para eliminar un elemento, pulsa 2\n";
    cout << "Para buscar un elemento, pulsa 3\n";
    cout << "Para mostrar el vector, pulsa 4\n";
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
                cout << "Introduce un entero: ";
                cin >> elem;
                encontrado = BusquedaSecOrd(vector, elem, pos, tamano);
                correcto = InsercionOrd(vector, elem, pos, tamano);
                if (!correcto)
                    cout << "El vector esta lleno.\n";
                break;
            case 2:
                cout << "Dame el valor entero a eliminar: ";
                cin >> valor_eliminar;
                EliminarElemento(vector, valor_eliminar, tamano);
                break;
            case 3:
                cout << "Dame el valor entero a buscar: ";
                cin >> valor_buscar;
                PosicionElementoRepetido(vector, valor_buscar, tamano);
                break;
            case 4:
                MostrarVector(vector, tamano);
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
* @param[in] v          Vector en el que se tiene que introducir
* @param[in] buscado    Valor introducido por el usuario
* @param[in] tam        Tamano actual/real de vector
* @param[out] pos       Indexacion/Posicion donde se debe insertar un valor en el vector
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
    while((v[pos] > buscado))
        pos++;
    
    return (v[pos] == buscado && pos < tam);
}

/*************************** InsertarOrd ****************************//**
*
* Inserta numero enteros en un vector ordenadamente de menor a mayor
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
    bool insertado;
    

        for(i = tam; i > pos; i--)
            v[i] = v[i - 1];
        v[pos] = elemento;
        tam ++;
        insertado = true;

    
    return insertado;
}

/************************ EliminarElemento *********************//**
*
* Elimina un numero del vector
*
* @param[in] v Vector en el que se tiene que introducir
* @param[in] valor_eliminar Valor que se tiene que eliminar
* @param[in] tam Valor que se tiene que eliminar
*
*//*************************************************************/
void EliminarElemento(Vector v, int valor_eliminar, int & tam)
{
    int i, k;
    bool elimanado = false;

    for(i = 0; i < tam; i++)
    {
        if (valor_eliminar == v[i])
        {
            elimanado = true;
            
            for (k = i; k < tam; k++)
            {
                v[k] = v[k + 1];
            }
            tam --;
            i = -1;
        }
    }
    
    if (elimanado == false)
    {
        cout << "Imposible eliminar el " << valor_eliminar << ". El " << valor_eliminar;
        cout << " no esta en el vector\n";
    }
}

/************************ BuscarElemento *********************//**
*
* Busca un numero entero en un vector
*
* @param[in] v Vector en el que se tiene que introducir
* @param[in] valor_buscar Valor que se busca en el vector
* @param[in] tam Numero de elementos del vector
*
* @reval true si se encuentra repetido el valor a buscar
* @reval false si no se encuentra repetido el valor a buscar
*
*//*************************************************************/
bool BuscarElemento(Vector v, int valor_buscar, int tam, int & conteo_repetidos)
{
    int i;
    bool repetido = false;
    
    conteo_repetidos = 0;
    
    for(i = 0; i < tam; i++)
    {
        if (valor_buscar == v[i])
        {
            repetido = true;
            conteo_repetidos++;
        }
    }

    return repetido;
}

/************************ PosicionElementoRepetido *********************//**
*
* Muestra por pantalla los elementos repetidos del vector
*
* @param[in] v Vector en el que se tiene que introducir
* @param[in] valor_buscar Valor que se busca en el vector
* @param[in] tam Numero de elementos del vector
*
*//*************************************************************/
void PosicionElementoRepetido(Vector v,int valor_buscar, int tam)
{
    int i, conteo_repetidos;
    bool elementos_encontrados;
    
    elementos_encontrados = BuscarElemento(v, valor_buscar, tam, conteo_repetidos);
    
    if (elementos_encontrados == true && conteo_repetidos > 1)
    {
        cout << "El conteo de las posiciones empieza desde el 1\n";
        cout << "El " << valor_buscar << " se encuentra en las posiciones: ";
        for(i = 0; i < tam; i++)
        {
            if (valor_buscar == v[i])
            {
                cout << i + 1 << ", ";
            }
        }
        cout << "del vector. ";
    }
    
    else if(elementos_encontrados == true)
    {
        cout << "El conteo de las posiciones empieza desde el 1\n";
        cout << "El " << valor_buscar << " se encuentra en la posicion: ";
        for(i = 0; i < tam; i++)
        {
            if (valor_buscar == v[i])
            {
                cout << i + 1;
            }
        }
    }
    
    else
        cout << "El " << valor_buscar << " no esta en el vector.";
    
    cout << endl;
}

/************************ MostrarVector *********************//**
*
* Muestra el vector por pantalla
*
* @param[in] v Vector
* @param[in] tam Numero de Elementos
*
*//*************************************************************/
void MostrarVector(const Vector v, int tam)
{
    int i;
    
    cout << "\n El vector es: (  ";
    
    for(i = 0; i < tam; i++)
        cout << v[i] << "  ";
    
    cout << ")" << endl;
    
    return;
}
