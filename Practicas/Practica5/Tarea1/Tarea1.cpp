/**
 * @file Tarea1.cpp
 *
 * @brief Tarea1: Laboratorio, Practica5.
 *
 *
 * @version 1
 * @author Aldemaro Gonzalez
 * @date 12/11/2017
 */

#include <iostream>
using namespace std;
#include <stdlib.h>

const int MAX = 3;

typedef float Vector[MAX];

void LeerVector (Vector);
float ProductoEscalar (const Vector, const Vector);
void ProductoVectorial (const Vector, const Vector, Vector);
void MostrarVector (const Vector);

int main (void)
{
    Vector v1, v2, v_res;
    float f_res;
    int op;
    
    cout << "Este programa permite multiplicar escalar y ";
    cout << "vectorialmente dos vectores.\n";
    
    cout << "Dame primer vector: ";
    LeerVector (v1);
    cout << "Dame segundo vector: ";
    LeerVector (v2);
    
    do
    {
        cout << "Operaciones: \nOpcion 1 -> Produnto Escalar \tOpcion 2 -> Producto Vectorial \nEleccion: ";
        cin >> op;
        
        switch (op)
        {
            case 1:
                f_res = ProductoEscalar (v1, v2);
                cout << "\nEl resultado es: " << f_res << "\n\n";
                break;
            case 2:
                ProductoVectorial (v1, v2, v_res);
                cout << "\nEl resultado es: ";
                MostrarVector (v_res);
                break;
            default:
                cout << "\nOpcion incorrecta.\n";
        }
    }
    while (op !=1 && op != 2);
    
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
void LeerVector (Vector a)
{
    int i;
    
    for (i = 0; i < MAX; i++)
        cin >> a[i];
        
        return;
}

/************************ ProductoEscalar *********************//**
*
* Calcula el producto vectorial
*
*
* @param[in] v1 Vector 1
* @param[in] v2 Vector 2
*
* @return Producto Vectorial de los vectores
*
*//*************************************************************/
float ProductoEscalar (const Vector v1, const Vector v2)
{
    float producto_escalar = 0;
    int i;
    
    for (i = 0; i < MAX; i++)
        producto_escalar += v1[i] * v2[i];
    
    return producto_escalar;
}

/************************ ProductoVectorial *********************//**
*
* Calcula el producto vectorial
*
*
* @param[in] v1 Vector 1
* @param[in] v2 Vector 2
* @param[out] resultado Vector resultante del producto vectorial del vector 1 y vector 2
*
*//*************************************************************/
void ProductoVectorial (const Vector v1, const Vector v2, Vector resultado)
{
    
    float producto_i, producto_j, producto_k;
    
    producto_i = (v1[1] * v2[2]) - (v1[2] * v2[1]);
    resultado[0] = producto_i;
    
    producto_j = -((v1[0] * v2[2]) - (v1[2] * v2[0]));
    resultado[1] = producto_j;
    
    producto_k = (v1[0] * v2[1]) - (v1[1] * v2[0]);
    resultado[2] = producto_k;
    
}

/************************ MostrarVector *********************//**
*
* Muestra el vector por pantalla
*
*
* @param[in] v Vector
*
*//*************************************************************/
void MostrarVector(const Vector v)
{
    int i;
    for(i = 0; i < MAX; i++)
        cout << v[i] << " ";
    cout << endl << endl;
    return;
}
