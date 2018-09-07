/**
 * @file Tarea2.cpp
 *
 * @brief Tarea 2: Laboratorio 7.
 *
 * Determina cual empleado combra mas
 *
 * @version 1
 * @author Aldemaro Gonzalez
 * @date 8/12/2017
 */
#include <iostream>
using namespace std;

struct Racional
{
    int num;
    int den;
};

Racional FormulaTaylor(int terminos);

int Factorial (int numero);

Racional LeerRacional (int, int);
Racional IniciarRacional (int, int);
Racional Sumar (Racional, Racional);
void MostrarRacional (Racional);
void MostrarValorRacional (Racional);
void MostrarFracciones (int);

int Min(int, int);
int MaximoComunDivisor(int, int);
void Simplificar(int &, int &);

int main (void)
{
    int terminos;
    Racional result_tay;
    
    cout << "Introduce numero de terminos: ";
    cin >> terminos;
    result_tay = FormulaTaylor(terminos);
    
    cout << "\n--------------------------------------------------------------";
    cout << "\nValor aproximado de e: " << result_tay.num << "/" << result_tay.den;
    cout << " = ";
    MostrarValorRacional(result_tay);
    
    
    return 0;
}

/************************ FormulaTaylor *********************//**
*
* Crea el numero racional a partir de la formula de Taylor,
* dependiendo de los terminos que quiera el usuario
*
* @param[in] terminos Cantidad de veces que se aplica Taylor
*
* @return Numero combinatorio resultante
*
*//*************************************************************/
Racional FormulaTaylor(int terminos)
{
    Racional sumador, resultado;
    int i;
    
    resultado.num = 0;
    resultado.den = 1;
    
    for (i = 0; i < terminos; i++)
    {
        sumador.num = 1;
        sumador.den = Factorial(i);
        cout << "\n" << resultado.num << "/" << resultado.den << " + ";
        cout << sumador.num << "/" << sumador.den << " = ";
        resultado = Sumar(resultado, sumador);
        cout << resultado.num << "/" << resultado.den;
    }
    
    return resultado;
}

/***************************** Sumar ******************/ /**
*
* Suma dos numero racionales
*
* @param[in] sumador1 Racional al que tenemos que sumar
* @param[in] sumador2 Racional al que tenemos que sumar
*
* @return resultado de la suma
*
*/ /**************************************************************/
Racional Sumar (Racional sumador1, Racional sumador2)
{
    Racional resultado, simplificado;
    int result_num, result_den;
    
    /*
     * Realizamos la suma
     */
    if (sumador1.den == sumador2.den)
    {
        resultado.num = sumador1.num + sumador2.num;
        result_num = resultado.num;
        resultado.den = sumador1.den;
        result_den = resultado.den;
    }
    else
    {
        resultado.num = sumador1.num * sumador2.den + sumador1.den * sumador2.num;
        result_num = resultado.num;
        resultado.den = sumador1.den * sumador2.den;
        result_den = resultado.den;
    }
    
    /*
     * Simplificamos el resultado
     */
    Simplificar(result_num, result_den);
    simplificado.num = result_num;
    simplificado.den = result_den;
    
    
    return simplificado;
}

/************************ Factorial *********************//***
*
* Calcula el numero combinatorio de m y n
*
* @param[in] numero Numero al que hay que calcular su factorial
*
* @return Factorial del numero
*
*//*************************************************************/
int Factorial (int numero)
{
    int f = 1, i;
    
    f = 1;
    
    for (i = 1; i <= numero; i++)
    {
        f = f * i;
    }
    
    return f;
}

/***************************** MostrarValorRacional ******************/ /**
*
* Muestra el valor real asociado a la fraccion
*
* @param[in] num La fraccion a la que hay que sacarle su valor
*
*/ /**************************************************************/
void MostrarValorRacional (Racional num)
{
    float resultado;
    
    resultado = float (num.num) / float (num.den);
    
    cout << resultado << endl << endl;
    
    return;
}


/************************ MaximoComunDivisor *********************//**
*
* Determina el Maximo Comun Divisior de dos numeros
*
* @param[in] a Numerador de la fraccion
* @param[in] b Denominador de la fraccion
*
* @return Maximo Comun Divisor de dos numeros
*
*//*************************************************************/
int MaximoComunDivisor (int a, int b)
{
    int mcd;
    
    if (b == a)
        mcd = b;
    else
        mcd = MaximoComunDivisor (Min (a, b), abs(a - b));
    
    return mcd;
}

/***************************** Min **************************//**
*
* Determina el minimo de dos valores
*
* @param[in] a Numero al que hay que comparar
* @param[in] b Numero al que hay que comparar
*
* @return Minimo entre los dos numeros
*
*//*************************************************************/
int Min(int a, int b)
{
    int minimo;
    
    minimo = a;
    
    if ( b < a)
        minimo = b;
    
    return minimo;
}

/************************ Simplificar *********************//**
*
* Simplifica fracciones
*
* @param[in] a Numero al que hay que simplificar
* @param[in] b Numero al que hay que simplificar
*
*//*************************************************************/
void Simplificar(int & a, int & b)
{
    int mcd;
    
    mcd = MaximoComunDivisor (a, b);
    
    a = a / mcd;
    b = b / mcd;
    
    return;
}
