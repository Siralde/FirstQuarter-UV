/**
 * @file b6_3_aleatorios.cpp
 *
 * @brief Ejercicio 03: Boletin 6, Cuadrado Magico.
 *
 * Este programa determina si una matriz es cuadrado magico
 *
 * @version 1
 * @author Aldemaro Gonzalez
 * @date 12/11/2017
 */
#include <cstdlib>
#include <iostream>
using namespace std;

const int COLUMNA = 10; ///< Tamanyo maximo de columnas
const int FILA = 10; ///< Tamanyo maximo de filas

typedef float Matriz [FILA] [COLUMNA];

void LeerMatriz (Matriz m, int & tam_fila, int & tam_columna);
void MostrarMatriz(const Matriz m, int tam_fila, int tam_columna);
bool ComprobacionDeCuadrados(const Matriz m, int tam_fila, int tam_columna);
bool NumerosRepetidos (const Matriz m, int tam_fila, int tam_columna);
bool LadosCuadrado(const Matriz m, int tam_fila, int tam_columna);
bool SumaFilas(const Matriz m, int tam_fila, int tam_columna, int & sumatoria_filas);
bool SumaColumnas(const Matriz m, int tam_fila, int tam_columna, int & sumatoria_columnas);
bool SumaDiagonal(const Matriz m, int tam_fila, int & sumatoria_diagonales);

int main (void)
{
    Matriz m;
    int tam_fila, tam_columna; // Tamanyo real de la matriz
    
    cout << "Este programa determina si una matriz es cuadrado magico.\n\n";
    
    LeerMatriz(m, tam_fila, tam_columna);
    
    if (ComprobacionDeCuadrados(m, tam_fila, tam_columna))
        cout << "\n\nLa matriz si cumple las reglas de cuadrado mágico.\n\n";
    else
        cout << "La matriz no cumple las reglas de cuadrado mágico.\n\n";

    return 0;
}

/************************ LeerMatriz *********************//**
*
* Se introduce en la matriz los valores que introduce el usuario
*
* @param[in] m Matriz
* @param[in] tam_fila Numero de filas de la matriz
* @param[in] tam_columna Numero de columnas de la matriz
*
*//*************************************************************/
void LeerMatriz (Matriz m, int & tam_fila, int & tam_columna)
{
    int posicion_fila, posicion_columna;
    
    do
    {
        cout << "Introduce el numero de filas de la Matriz (Max. " << FILA << "): ";
        cin >> tam_fila;
        cout << "Introduce el numero de columnas de la Matriz (Max. " << COLUMNA << "): ";
        cin >> tam_columna;
        
        if (tam_fila != tam_columna)
        {
            cout << "Tiene que ser una matriz cuadrada. Vuelve a introducir";
            cout << " el numero de filas y columnas.\n\n";
        }
        
        else if (tam_fila <= 1)
        {
            cout << "Tiene que ser una matriz cuadrada mayor a 1x1.";
            cout << " Vuelve a introducir el numero de filas y columnas.\n\n";
        }
    }
    while (tam_fila != tam_columna || tam_fila <= 1);
    
    cout << "Vamos a crear una matriz de " << tam_fila << "x" << tam_columna << endl;
    cout << "\nIntroduce los valores de la matriz: ";
    for(posicion_fila = 0; posicion_fila < tam_fila; posicion_fila++)
        for(posicion_columna = 0; posicion_columna < tam_columna; posicion_columna++)
            cin >> m [posicion_fila] [posicion_columna];
    
    cout << "\nLa matriz introducida es:" << endl;
    MostrarMatriz(m, tam_fila, tam_columna);
    
    return;
}

/************************ MostrarMatriz *********************//**
*
* Muestra la matriz por pantalla
*
* @param[in] m Matriz
* @param[in] tam_fila Numero de filas de la matriz
* @param[in] tam_columna Numero de columnas de la matriz
*
*//*************************************************************/
void MostrarMatriz(const Matriz m, int tam_fila, int tam_columna)
{
    int posicion_fila, posicion_columna;
    
    for(posicion_fila = 0; posicion_fila < tam_fila; posicion_fila++)
    {
        cout << " |   ";
        for(posicion_columna = 0; posicion_columna < tam_columna; posicion_columna++)
        {
            cout << m [posicion_fila] [posicion_columna] << "   ";
        }
        
        cout << "|"<< endl;
    }
    
    return;
}


/************************ ComprobacionDeCuadrados *********************//**
*
* Suma cada fila de la matriz
*
* @param[in] m Matriz
* @param[in] tam_fila Numero de filas de la matriz
* @param[in] tam_columna Numero de columnas de la matriz
*
* @retval true Si es cuadrado perfecto
* @retval false Si no es cuadrado perfecto
*
*//************************************************************************/
bool ComprobacionDeCuadrados(const Matriz m, int tam_fila, int tam_columna)
{
    bool es_cuadrado = false;
    int sumatoria_filas, sumatoria_columnas, sumatoria_diagonales;
    
    if (NumerosRepetidos(m, tam_fila, tam_columna) == false &&
        LadosCuadrado(m, tam_fila, tam_columna) == false &&
        SumaFilas(m, tam_fila, tam_columna, sumatoria_filas) &&
        SumaColumnas(m, tam_fila, tam_columna, sumatoria_columnas) &&
        SumaDiagonal(m, tam_fila, sumatoria_diagonales) )
    {
        if ( (sumatoria_filas == sumatoria_columnas) && (sumatoria_filas == sumatoria_diagonales) )
        {
            es_cuadrado = true;
        }
    }
    
    return es_cuadrado;
}


/************************ NumerosRepetidos *********************//**
*
* Comprueba si hay o no numeros repetidos en la matriz
*
* @param[in] m Matriz a comprobar
* @param[in] tam_fila Numero de filas
* @param[in] tam_columna Numero de columnas
*
* @return Si hay o no numeros repetidos dentro de la matriz
*
*//****************************************************************/
bool NumerosRepetidos(const Matriz m, int tam_fila, int tam_columna)
{
    bool repetido = false;
    int posicion_fila, posicion_columna, posicion_fila2, posicion_columna2;
    int comprobador, columnas = 0;
    int verificador;
    
    /*
     * Con los dos primeros for se obtiene un valor del vector
     */
    for(posicion_fila = 0; posicion_fila < tam_fila; posicion_fila++)
    {
        columnas = 0;
        
        for(posicion_columna = columnas; posicion_columna < tam_columna; posicion_columna++)
        {
            comprobador = m[posicion_fila][posicion_columna];   // Valor al que hay que comprobar si tiene repetido
            
            /*
             * Con los dos siguientes for se obtiene los otros valores con lo que
             * se va a comprobar si es igual al valor obtenido en los dos primeros for
             */
            for(posicion_fila2 = 0; posicion_fila2 < tam_fila; posicion_fila2++)
            {
                for(posicion_columna2 = columnas; posicion_columna2 < tam_columna; posicion_columna2++)
                {
                    /*
                     * Valor que se compara con el comprobador, si son igual es que hay repetidos
                     */
                    verificador = m[posicion_fila2][posicion_columna2];
                    
                    /*
                     * Este if es para que no haga nada si las posiciones de los
                     * dos primeros for (comprobador) son la misma que la los dos siguientes for
                     * (verificador), si son iguales es que es el mismo numero
                     * por lo tanto no tiene que hacer nada el programa
                     */
                    if (posicion_fila == posicion_fila2 && posicion_columna == posicion_columna2)
                    {
                        
                    }
                    else if (comprobador == verificador)
                    {
                        cout << "\nHay un numero repetido y es el: " << verificador << endl;
                        repetido = true;
                        posicion_columna2 = tam_columna;
                    }
                    
                } // for 4
                
                if (repetido == true)
                {
                    posicion_fila2 = tam_fila;
                }
            } // for 3
            
            if (repetido == true)
            {
                posicion_columna = tam_columna;
            }
            
        } // for 2
        
        if (repetido == true)
        {
            posicion_fila = tam_fila;
        }
    } // for 1
    
    
    if (repetido == false)
    {
        cout << "\nNo hay repetidos.\n";
    }

    return repetido;
}


/************************ LadosCuadrado *********************//**
*
* Calcula el los valores normalizados de los elementos del vector
*
* @param[in] m Matriz a comprobar
* @param[in] tam_fila Numero de filas
* @param[in] tam_columna Numero de columnas
*
*//*************************************************************/
bool LadosCuadrado(const Matriz m, int tam_fila, int tam_columna)
{
    bool mayor = false;
    int n_cuadrado, posicion_fila, posicion_columna;
    
    n_cuadrado = tam_columna * tam_fila;
    
    for(posicion_fila = 0; posicion_fila < tam_fila; posicion_fila++)
    {
        for(posicion_columna = 0; posicion_columna < tam_columna; posicion_columna++)
        {
            if (m [posicion_fila] [posicion_columna] > n_cuadrado || m [posicion_fila] [posicion_columna] <= 0)
            {
                mayor = true;
                cout << "El numero " << m[posicion_fila][posicion_columna] << " no esta entre ";
                cout << "1 a " << tam_fila << " al cudrado ( " << n_cuadrado << " ).\n\n";
                posicion_columna = tam_columna;
            }
        }//For interno
        
        if (mayor == true)
        {
            posicion_fila = tam_fila;
        }
    }//For externo
    
    if (mayor == false)
    {
        cout << "Los numeros que estan dentro de la matriz si estan dentro de 1 a ";
        cout << n_cuadrado;
    }
    
    return mayor;
}

/************************ SumaFilas ************************//**
*
* Comprueba si la suma de todas las filas de la matriz son
* las mismas y devuelve una de las sumas
*
* @param[in] m Matriz a comprobar
* @param[in] tam_fila Numero de filas
* @param[in] tam_columna Numero de columnas
* @param[out] sumatoria_filas La suma de una fila
*
* @return Si o no son todas las sumatorias de las filas iguales
*
*//*************************************************************/
bool SumaFilas(const Matriz m, int tam_fila, int tam_columna, int & sumatoria_filas)
{
    bool iguales = true;
    int posicion_fila, posicion_columna;
    int suma_temporal;
    
    sumatoria_filas = 0;
    
    //Calculo la suma de la primera fila
    for(posicion_fila = 0; posicion_fila < 1; posicion_fila++)
    {
        for(posicion_columna = 0; posicion_columna < tam_columna; posicion_columna++)
        {
            sumatoria_filas = sumatoria_filas + m [posicion_fila] [posicion_columna];
        }
    }
    
    // Hago la suma de las demas y las comparo con la suma de la primera
    for(; posicion_fila < tam_fila; posicion_fila++)
    {
        suma_temporal = 0;
        
        //Hago la suma de fila
        for(posicion_columna = 0; posicion_columna < tam_columna; posicion_columna++)
        {
            suma_temporal = suma_temporal + m[posicion_fila][posicion_columna];
        }
        
        // Comparo el total de la suma temporal con la sumatoria de la primera fila
        if (sumatoria_filas != suma_temporal)
        {
            iguales = false;
            posicion_fila = tam_fila;
        }
    }
    
    //Imprimo unos valores extras para que el usuario sepa que estuvo bien y que no.
    if (iguales == true)
    {
        cout << "\nLas sumas de las filas son iguales,";
        cout << " sumatoria de las filas = " << sumatoria_filas;
    }
    else
    {
        cout << "\nLas sumas de las filas son diferentes.\n\n";
    }
    
    return iguales;
}

/*************************** SumaColumnas ***********************//**
*
* Comprueba si la suma de todas las columnas de la matriz son
* las mismas y devuelve una de las sumas
*
* @param[in] m Matriz a comprobar
* @param[in] tam_fila Numero de filas
* @param[in] tam_columna Numero de columnas
* @param[out] sumatoria_columnas La suma de una columna
*
* @return Si o no son todas las sumatorias de las columnas iguales
*
*//*****************************************************************/
bool SumaColumnas(const Matriz m, int tam_fila, int tam_columna, int & sumatoria_columnas)
{
    bool iguales = true;
    int posicion_fila, posicion_columna;
    int suma_temporal;
    
    sumatoria_columnas = 0;
    
    //Calculo la suma de la primera columna
    for(posicion_columna = 0; posicion_columna < 1; posicion_columna++)
    {
        for(posicion_fila = 0; posicion_fila < tam_fila; posicion_fila++)
        {
            sumatoria_columnas = sumatoria_columnas + m [posicion_fila] [posicion_columna];
        }
    }
    
    // Hago la suma de las demas y las comparo con la suma de la primera
    for(; posicion_columna < tam_columna; posicion_columna++)
    {
        suma_temporal = 0;
        
        //Hago la suma de fila
        for(posicion_fila = 0; posicion_fila < tam_fila; posicion_fila++)
        {
            suma_temporal = suma_temporal + m[posicion_fila][posicion_columna];
        }
        
        // Comparo el total de la suma temporal con la sumatoria de la primera fila
        if (sumatoria_columnas != suma_temporal)
        {
            iguales = false;
            posicion_fila = tam_fila;
        }
    }
    
    //Imprimo unos valores extras para que el usuario sepa que estuvo bien y que no.
    if (iguales == true)
    {
        cout << "\nLas sumas de las columnas son iguales,";
        cout << " sumatoria de las columnas = " << sumatoria_columnas;
    }
    else
    {
        cout << "\nLas sumas de las columnas son diferentes.\n\n";
    }
    
    return iguales;
}

/************************ SumaDiagonal *********************//**
*
* Comprueba si la suma de las dos diagonales de la matriz son
* las mismas y devuelve una de las sumas
*
* @param[in] m Matriz a comprobar
* @param[in] tam_fila Numero de filas
* @param[out] sumatoria_diagonales La suma de una diagonal
*
* @return Si o no son todas las sumatorias de las diagonales iguales
*
*//*************************************************************/
bool SumaDiagonal(const Matriz m, int tam_fila, int & sumatoria_diagonales)
{
    bool iguales = true;
    int posicion_diagonal;
    int suma_temporal = 0;
    
    sumatoria_diagonales = 0;
    
    //Calculo la suma de la primera fila
    for(posicion_diagonal = 0; posicion_diagonal < tam_fila; posicion_diagonal++)
    {
        sumatoria_diagonales = sumatoria_diagonales + m [posicion_diagonal] [posicion_diagonal];
    }
    
    //Calculo la segunda diagonal y la comparo
    for(posicion_diagonal = tam_fila; posicion_diagonal > -1; posicion_diagonal--)
    {
        suma_temporal = suma_temporal + m [posicion_diagonal] [posicion_diagonal];
    }
    
    if (sumatoria_diagonales != suma_temporal)
    {
        iguales = false;
    }
    
    //Imprimo unos valores extras para que el usuario sepa que estuvo bien y que no.
    if (iguales == true)
    {
        cout << "\nLas sumas de las dos diagonales son iguales,";
        cout << " sumatoria de las diagonales = " << sumatoria_diagonales;
    }
    else
    {
        cout << "\nLas sumas de las dos diagonales son diferentes.\n\n";
    }
    
    return iguales;
}
