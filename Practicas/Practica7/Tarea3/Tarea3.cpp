/**
 * @file Tarea3.cpp
 *
 * @brief Tarea 3: Laboratorio 7.
 *
 * Descripcion
 *
 * @version 1
 * @author Aldemaro Gonzalez
 * @date 6/12/2017
 */
#include <iostream>
using namespace std;

struct Racional
{
    int num;
    int den;
};

Racional LeerRacional (void);
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
    Racional numero, result_sum;
    //Para elegir las opciones
    int opcion;
    
    //Para hacer el sumador
    Racional sumador1, sumador2;
    
    //Para mostrar fracciones
    int entero;
    
    
    //Pedimos al usurario
    cout << "Para leer el numero racional, pulsa 1\n";
    cout << "Para iniciar el numero racional, pulsa 2\n";
    cout << "Para mostrar el numero racional, pulsa 3\n";
    cout << "Para mostrar el valor racional, pulsa 4\n";
    cout << "Para sumar dos numeros racionales, pulsa 5\n";
    cout << "Para mostrar las fracciones con valores igual o menores que 1 ";
    cout << "que tenga un entero como denominador, pulsa 6\n";
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
                numero = LeerRacional ();
                break;
            case 2:
                //IniciarRacional ();
                break;
            case 3:
                MostrarRacional (numero);
                break;
            case 4:
                MostrarValorRacional (numero);
                break;
            case 5:
                cout << "Dame el primer numero racional\n";
                sumador1 = LeerRacional();
                cout << "\nDame el segundo numero racional\n";
                sumador2 = LeerRacional();
                result_sum = Sumar(sumador1, sumador2);
                break;
            case 6:
                cout << "\nDame un numero entero: ";
                cin >> entero;
                MostrarFracciones(entero);
                break;
            default:
                cout << "\nOpcion no valida, vuelva a intentarlo\n\n";
                break;
        }
    } while (opcion != 0);

    
    
    return 0;
}

/***************************** LeerRacional ******************/ /**
*
* Leer de teclado el numerador y denominador de un numero racional
*
* @return Numero racional
*
*/ /**************************************************************/
Racional LeerRacional (void)
{
    Racional numero;
    
    cout << "Dame el numerador: ";
    cin >> numero.num;
    cout << "Dame el denominador: ";
    cin >> numero.den;
    
    return numero;
}

/***************************** MostrarRacional ******************/ /**
*
* Muestra por pantalla el numerador y denominador de un numero racional
*
* @param[in] numero La fraccion que hay que mostrar pon pantalla
*
*/ /**************************************************************/
void MostrarRacional (Racional numero)
{
    int simpl_num = numero.num, simpl_dem = numero.den;
    
    cout << "El numero racional introducido es el siguiente: ";
    cout << numero.num << "/" << numero.den << endl;
    Simplificar(simpl_num, simpl_dem);
    if (simpl_num != numero.num || simpl_dem != numero.den)
    {
        cout << "Simplicado: " << simpl_num << "/" << simpl_dem << endl;
    }
    
    return;
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
    
    cout << "El valor racional de " << num.num << "/" << num.den;
    cout << " es: " << resultado << endl << endl;
    
    return;
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
    
    cout << "\nLa suma de ambos numero racionales en forma de fraccion es igual a " << resultado.num;
    cout << "/" << resultado.den;
    
    /*
     * Simplificamos el resultado
     */
    Simplificar(result_num, result_den);
    simplificado.num = result_num;
    simplificado.den = result_den;
    
    if (simplificado.num != resultado.num || simplificado.den != resultado.den)
    {
           cout << ". La fracion simplificada es: " << result_num << "/" << result_den;
    }
    
    /*
     * Mostramos el valor racional de la suma
     */
    cout << endl;
    MostrarValorRacional(simplificado);
    
    return resultado;
}

/***************************** MostrarFracciones ***************************************/ /***
*
* Muestra todas las fracciones con valor menor o igual a uno
* que tengan ese valor como denominador
*
* @param[in] entero al que mostrareomos todas las fracciones que lo tengan como denominador
*
*/ /****************************************************************************************/
void MostrarFracciones (int entero)
{
    int numerador, denominador;
    
    cout << "Las fracciones con valor menor o igual a uno son: ";
    
    for (denominador = entero; denominador >= 1; denominador--)
    {
        for (numerador = 0; numerador <= entero; numerador++)
        {
            if (numerador <= denominador)
            {
                cout << numerador << "/" << denominador << ", ";
            }
        }
    }
    
    cout << endl;
    
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
