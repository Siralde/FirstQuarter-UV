/**
 * @file Tarea1.cpp
 *
 * @brief Tarea 1: Laboratorio 7.
 *
 * Registro de un empleado
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
void MostrarEmpleado (Empleado);

int main (void)
{
    Empleado emp;
    emp = LeerEmpleado ();
    MostrarEmpleado (emp);
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
    
    cout << "Dame el nombre del empleado: ";
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
