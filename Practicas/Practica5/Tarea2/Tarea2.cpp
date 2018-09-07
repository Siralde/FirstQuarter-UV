/**
 * @file Tarea2.cpp
 *
 * @brief Tarea2: Laboratorio, Practica5.
 *
 *
 * @version 1
 * @author Aldemaro Gonzalez
 * @date 12/11/2017
 */
#include <cmath>
#include <cstdlib>
#include <iostream>
using namespace std;


const int MAX = 20;

typedef float Vector [MAX];

int LeerVector (Vector);
void MostrarVector (const Vector, int);
float CalcularMediaVector (const Vector, int);
float CalcularDesviacionEstandar (const Vector, int, float);

int main (void)
{
    Vector vec;
    
    int num_elementos;
    float media, desviacion;
    
    cout << "Este programa pide un vector de, a lo suma, " << MAX;
    cout << " elementos, y calcula su media y su desviación";
    cout << " estandar.\n\n";
    
    num_elementos = LeerVector (vec);
    
    media = CalcularMediaVector (vec, num_elementos);
    
    desviacion = CalcularDesviacionEstandar (vec, num_elementos, media);
    
    cout << "\nEl vector introducido es: ";
    MostrarVector (vec, num_elementos);
    cout << "La media de los valores del vector es: " << media << endl;
    cout << "La desviación estandar es: " << desviacion << endl << endl;
    
    return 0;
}

/************************ LeerVector *********************//**
*
* Escribe en el vector los valores que introduce el usuario
*
*
* @param[in] v Vector en el que se tiene que introducir
*
* @return Cantidad de elemtos del vector
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

/************************ CalculaMediaVector *********************//**
*
* Calcula la media de los valores que se introducen en el vector
*
*
* @param[in] v Vector
* @param[in] num_elementos Numero de Elementos
*
* @return Media de los elemetos del vector
*
*//*************************************************************/
float CalcularMediaVector (const Vector v, int num_elementos)
{
    int i;
    float media;
    float suma_elementos = 0;
    
    for(i = 0; i < num_elementos; i++)
        suma_elementos = suma_elementos + v[i];
    
    media = suma_elementos / num_elementos;
   
    return media;
}

/************************ CalculaMediaVector *********************//**
*
* Calcula la media de los valores que se introducen en el vector
*
*
* @param[in] v Vector
* @param[in] num_elementos Numero de Elementos
* @param[in] media la media de los valores del vector
*
* @return Resultado de la desviacion
*
*//*************************************************************/
float CalcularDesviacionEstandar (const Vector v, int num_elementos, float media)
{
    int i;
    float primera_parte, elevar_2, sumatoria = 0;
    float division;
    float resultado_desviacion;
    
    // Calculamos la sumatoria de cada elemento del vector menos la media
    for(i = 0; i < num_elementos; i++)
    {
        primera_parte = v[i] - media;
        elevar_2 = primera_parte * primera_parte;
        sumatoria = sumatoria + elevar_2;
    }
    
    //Calculamos la division entre la sumatoria y el numero de elementos del vector
    division = sumatoria / num_elementos;
    
    //Calcula la raiz cuadrada de la division
    resultado_desviacion = sqrt (division);
    
    return resultado_desviacion;
}


/************************ MostrarVector *********************//**
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
