/**
 * @file b4_4_fechas.cpp
 *
 * @brief Ejercicio 04: Determinacion del dia en una fecha.
 *
 * Determina el día de la semana en que cayó o caerá una fecha
 * cualquiera posterior al 1 de enero de 1.583.
 *
 * @version 1
 * @author Aldemaro Gonzalez
 * @date 14/11/2017
 */

#include <iostream>
using namespace std;

const int YEAR = 1583;  ///< Ano minimo

bool FechaCorrecta (int dia, int mes, int año);
int DiaMes (int mes, int year);
bool Bisiesto (int year);
int CalculoDia (int dia, int mes, int year);
int CodigoSiglo (int year);
int CodigoMes(int mes);

/**
 * Funcion principal
 */
int main (void)
{
    int dia, mes, year;
    
    
    cout << "Este programa determina el día de la semana en que cayó ";
    cout << "o caerá una fecha cualquiera posterior al 1 de enero de 1.583.\n\n";
    
    cout << "Dime el ano: ";
    cin >> year;
    cout << "Dime el mes: ";
    cin >> mes;
    cout << "Dime el dia: ";
    cin >> dia;
    cout << endl;

    while (FechaCorrecta(dia, mes, year) == false)
    {
        cout << "La fecha introducida no es valida. ";
        cout << "Por favor vuelva a intentarlo.\n\n";
        cout << "Dime el ano: ";
        cin >> year;
        cout << "Dime el mes: ";
        cin >> mes;
        cout << "Dime el dia: ";
        cin >> dia;
        cout << endl;
    }
    
    switch (CalculoDia(dia, mes, year))
    {
        case 0:
            cout << "El " << dia << "/" << mes << "/" << year;
            cout << " cae Domingo.\n\n";
            break;
        case 1:
            cout << "El " << dia << "/" << mes << "/" << year;
            cout << " cae Lunes.\n\n";
            break;
        case 2:
            cout << "El " << dia << "/" << mes << "/" << year;
            cout << " cae Martes.\n\n";
            break;
        case 3:
            cout << "El " << dia << "/" << mes << "/" << year;
            cout << " cae Miercoles.\n\n";
            break;
        case 4:
            cout << "El " << dia << "/" << mes << "/" << year;
            cout << " cae Jueves.\n\n";
            break;
        case 5:
            cout << "El " << dia << "/" << mes << "/" << year;
            cout << " cae Viernes.\n\n";
            break;
        case 6:
            cout << "El " << dia << "/" << mes << "/" << year;
            cout << " cae Sabado.\n\n";
            break;
    }

    return 0;
}

/************************ FechaCorrecta *********************//**
*
* Comprueba si la fecha introducida es valida
*
* @param[in] dia Dia introducido por el usuario
* @param[in] mes Mes introducido por el usuario
* @param[in] year Ano introducido por el usuario
*
* @return Si la fecha es o no correcta
*
*//*************************************************************/
bool FechaCorrecta (int dia, int mes, int year)
{
    bool fecha;
    
    // El ano no puede ser inferior al ano 1583
    if (year < YEAR)
    {
        fecha = false;
    }
    else
        //El mes debe estar entre 1 y 12.
        if (mes < 1 || mes > 12)
        {
            fecha = false;
        }
        else
            //Comprobamos los dias depediendo del mes
            if (dia < 1 || dia > DiaMes(mes, year))
            {
                fecha = false;
            }
            else
                fecha = true;
    
    return fecha;
}

/************************ DiaMes *********************//**
*
* Comprueba si el dia es acorde al mes
*
* @param[in] mes Mes introducido por el usuario
* @param[in] year Ano introducido por el usuario
*
* @return el dia maximo acorde al ano y al mes
*
*//*************************************************************/
int DiaMes (int mes, int year)
{
    int dia_mes = 0;
    
    switch (mes)
    {
        case 1:
        case 3:
        case 5:
        case 7:
        case 8:
        case 10:
        case 12:
            dia_mes = 31;
            break;
        case 4:
        case 6:
        case 9:
        case 11:
            dia_mes = 30;
            break;
        case 2:
            if (Bisiesto(year))
            {
                dia_mes = 29;
            }
            else
                dia_mes = 28;
    }
    
    return dia_mes;
}

/************************ Bisiesto *********************//**
*
* Comprueba si el ano es bisiesto
*
* @param[in] year Ano introducido por el usuario
*
* @return Si el ano es o no bisiesto
*
*//*************************************************************/
bool Bisiesto (int year)
{
    bool es_bisiesto;
    
    if (year % 400 == 0)
    {
        es_bisiesto = true;
    }
    else
        if (year % 100)
        {
            es_bisiesto = false;
        }
        else
            if (year % 4 == 0)
            {
                es_bisiesto = true;
            }
            else
                es_bisiesto = false;
    
    return es_bisiesto;
}

/************************ CalculoDia *********************//**
*
* Determina el dia asociado a una fecha
*
* @param[in] dia dia introducido por el usuario
* @param[in] mes Mes introducido por el usuario
* @param[in] year Ano introducido por el usuario
*
* @return el dia relacionado a una fecha
*
*//*************************************************************/
int CalculoDia (int dia, int mes, int year)
{
    
    int primera_ecuacion, codigo_mes, dos_digitos_del_ano;
    int cuarta_parte_ano, codigo_siglo;
    int determinacion;
    
    codigo_siglo = CodigoSiglo(year);
    codigo_mes = CodigoMes(mes);
    dos_digitos_del_ano = year % 100;
    cuarta_parte_ano = dos_digitos_del_ano / 4;
    
    primera_ecuacion = dia + codigo_mes + dos_digitos_del_ano + cuarta_parte_ano + codigo_siglo;
    
    determinacion = primera_ecuacion % 7;
    
    return determinacion;
}

/************************ CodigoSiglo *********************//**
*
* Determina un numero(codigo) depediendo de un mes
*
* @param[in] year Ano introducido por el usuario
*
* @return El codigo del siglo
*
*//*************************************************************/
int CodigoSiglo (int year)
{
    int codigo_siglo;
    
    while (year >= 2000)
    {
        year -= 400;
    }
    
    if (year < 1600)
        codigo_siglo = 0;
    else if (year < 1700)
        codigo_siglo = 6;
    else if (year < 1800)
        codigo_siglo = 4;
    // Si ano < 1900
    else
        codigo_siglo = 2;
    
    return codigo_siglo;
}
/************************ CodigoMes *********************//**
*
* Determina un numero(codigo) depediendo del mes
*
* @param[in] mes Mes introducido por el usuario
*
* @return el dia relacionado a la fecha
*
*//*************************************************************/
int CodigoMes(int mes)
{
    int codigo_mes = 0;
    
    switch (mes)
    {
        
        case 1:
        case 10:
            codigo_mes = 0;
            break;
        case 2:
        case 3:
        case 11:
            codigo_mes = 3;
            break;
        case 4:
            codigo_mes = 6;
            break;
        case 5:
            codigo_mes = 1;
            break;
        case 6:
            codigo_mes = 4;
            break;
        case 7:
            codigo_mes = 6;
            break;
        case 8:
            codigo_mes = 2;
            break;
        case 9:
        case 12:
            codigo_mes = 5;
            break;
    }
    
    return codigo_mes;
}
