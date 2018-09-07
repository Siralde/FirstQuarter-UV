/**
 * @file Tarea3.cpp
 *
 * @brief Tarea3: Laboratorio, Practica5.
 *
 *
 * @version 1
 * @author Aldemaro Gonzalez
 * @date 12/11/2017
 */
#include <cstdlib>
#include <iostream>
using namespace std;


const int MAX = 20;

typedef float Vector [MAX];

int LeerVector (Vector);
void MostrarVector (const Vector, int);
int MinMaxVector (Vector,int ,int & max);
void Normalizador (Vector v, int tam);

int main (void)
{
    Vector vec;
    
    int num_elementos;
    int max, min;
    
    
    cout << "Este programa normalice los valores del vector";
    cout << " y los muestra por pantalla.\n\n";

    num_elementos = LeerVector (vec);
    
    min = MinMaxVector(vec, num_elementos, max);
   
    cout << "\nEl vector introducido es: ";
    MostrarVector (vec, num_elementos);
    cout << "El valor minimo del vector es: " << min << endl;
    cout << "El valor maximo del vector es: " << max << endl;
    
    Normalizador(vec, num_elementos);
    cout << "El vector con los valores normalizados es: ";
    MostrarVector(vec, num_elementos);
    cout << endl << endl;
    
    return 0;
}

/************************ LeerVector *********************/
*
* Escribe en el vector los valores que introduce el usuario
*
*
* @param[in] v Vector en el que se tiene que introducir
*
*//*************************************************************/
int LeerVector (Vector v)
{
    int i;
    int tam;
    
    cout << "Introduce tamanyo del vector (Max. " << MAX << "): ";
    cin >> tam;
    
    cout << "Introduce el vector: ";
    for(i = 0; i < tam; i++)
        cin >> v[i];
    
    return tam;
}

/************************ MinMaxVector *********************//
*
* Calcula el valor minimo y el valor maximo
*
*
* @param[in] v Vector
* @param[in] tam Numero de elementos del vector
* @param[out] max Valor Maximo del vector
*
* @return Valor Minimo del vector
*
*//*************************************************************/
int MinMaxVector (Vector v, int tam, int & max)
{
    int min, i;
    
    min = max = v[0];
    
    for(i = 0; i < tam; i++)
    {
        if (v[i] < min)
        {
            min = v[i];
        }
        else
            max = v[i];
    }
    
    return min;
}

/************************ Normalizador *********************//
*
* Calcula el los valores normalizados de los elementos del vector
*
*
* @param[in] v Vector al que se va a normalizar sus valores
* @param[in] tam Numero de elementos
*
*//*************************************************************/
void Normalizador (Vector v, int tam)
{
    int i, min, max;
    float denominador, numerador, division, valor_normalizado;
    
    min = MinMaxVector(v, tam, max);
    
    denominador = max - min;
    
    for(i = 0; i < tam; i++)
    {
        numerador = v[i] - min;
        division = numerador / denominador;
        valor_normalizado = division + min;
        
        v[i] = valor_normalizado;
    }
    
    return;
}

/************************ MostrarVector *********************//
*
* Muestra el vector por pantalla
*
*
* @param[in] v Vector
* @param[in] tam Numero de Elementos
*
*//*************************************************************/
void MostrarVector(const Vector v, int tam)
{
    int i;
    for(i = 0; i < tam; i++)
        cout << v[i] << " ";
    cout << endl;
    return;
}
