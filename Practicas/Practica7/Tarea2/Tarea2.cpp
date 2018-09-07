/**
 * @file Tarea2.cpp
 *
 * @brief Tarea 2: Laboratorio 7.
 *
 * Determina cual empleado combra mas
 *
 * @version 1
 * @author Aldemaro Gonzalez
 * @date 6/12/2017
 */
#include <iostream>
#include <string>
using namespace std;

struct Empleado
{
    string nombre;
    float salario;
    string num_telefono;
};

Empleado LeerEmpleado (void);
Empleado QuienCobraMas (Empleado, Empleado);
void MostrarEmpleado (Empleado);

int main (void)
{
    Empleado emp1, emp2, mejor_cobra;
    
    cout << "Dames los datos del empleado 1";
    emp1 = LeerEmpleado ();
    MostrarEmpleado (emp1);
    
    cout << "Dames los datos del empleado 2";
    emp2 = LeerEmpleado ();
    MostrarEmpleado (emp2);
    
    cout << "El empleado que mas cobra es: ";
    mejor_cobra = QuienCobraMas (emp1, emp2);
    cout << mejor_cobra.nombre << endl << endl;
    
    return 0;
}

/***************************** LeerEmpleado ******************/ /**
*
* Leer de teclado la informacion de un
* empleado y devolver a quien haya
* hecho la llamada esa informacion
*
* @return Informacion leida de teclado
*/ /**************************************************************/
Empleado LeerEmpleado (void)
{
    Empleado emp;
    
    cout << "\nDame el nombre del empleado: ";
    cin >> emp.nombre;
    cout << "Dame el salario del empleado: ";
    cin >> emp.salario;
    cout << "Dame el numero de telefono del empleado: ";
    cin >> emp.num_telefono;
    
    return emp;
}
/************************** MostrarEmpleado ***************/ /**
*
* Mostrar por pantalla la informacion de
* un empleado
*
* @param emp informacion a mostrar
*
*/ /************************************************************/
void MostrarEmpleado (Empleado emp)
{
    cout << "Los Datos del empleado son los siguientes: \n";
    cout << "Nombre: " << emp.nombre << endl;
    cout << "Salario del empleado: " << emp.salario << endl;
    cout << "Numero de telefono del empleado: " << emp.num_telefono << endl << endl;
}

/**************** QuienCobraMas ************************************/ /**
*
* Proposito: Determinar el empleado que tiene mas salario
* de los dos empleados pasados como parametros
*
* @param emp1 Datos primer empleado
* @param emp2 Datos segundo empleado
*
* @return Empleado que mas cobra de los dos pasados
*
*/ /****************************************************************/
Empleado QuienCobraMas (Empleado emp1, Empleado emp2)
{
    Empleado mejor_cobra;
    
    if (emp1.salario > emp2.salario)
    {
        mejor_cobra = emp1;
    }
    else
    {
        mejor_cobra = emp2;
    }
    
    return mejor_cobra;
}
