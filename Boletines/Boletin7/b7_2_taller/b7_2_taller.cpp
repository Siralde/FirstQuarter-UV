/**
 * @file b7_2_taller.cpp
 *
 * @brief Ejercicio 02: Boletin 7, Gestion de un Clientes de un taller mecanico.
 *
 * Gestiona un solo cliente de un taller mecanico
 *
 * @version 1
 * @author Aldemaro Gonzalez
 * @date 21/12/2017
 */
#include <string>
#include <iostream>
using namespace std;

const int MAX = 5;

struct Nombre
{
    string nombre, apellidos;
};

struct Direccion
{
    string calle, numero_portal, codigo_postal, provincia;
};

struct Fecha
{
    int dia, mes, ano;
};

struct Autos
{
    string matricula;
    Fecha revision, prox_revision;
    unsigned int kilometros;
};

typedef Autos automoviles [MAX];

struct Clientes
{
    Nombre nombre_compl;
    Direccion direccion_postal;
    string e_mail, dni;
    automoviles vehiculos;
    
};

void LeerCliente (Clientes);
void MostrarCliente (const Clientes, int);

int main (void)
{
    Clientes cliente;
    
    LeerCliente(cliente);
    
    return 0;

}

/************************** LeerCliente ******************************//**
*
* Lee toda la informacion necesaria de un cliente
*
* @param[in] cliente Cliente al que hay que introducirle la informacion
*
*//********************************************************************/
void LeerCliente (Clientes cliente)
{
    int i, cant_autos;
    
    cout << "Introduce los siguientes campos\n";
    cout << "Datos Personales\n";
    cout << "Nombre: ";
    cin >> cliente.nombre_compl.nombre;
    cin.ignore();
    cout << "Apellidos: ";
    getline (cin, cliente.nombre_compl.apellidos);
    cout << "E-mail: ";
    cin >> cliente.e_mail;
    cout << "DNI: ";
    cin >> cliente.dni;
    cin.ignore();
    
    cout << "\nDireccion Postal: ";
    cout << "\nCalle: ";
    getline (cin, cliente.direccion_postal.calle);
    cout << "Numero del Portal: ";
    cin >> cliente.direccion_postal.numero_portal;
    cout << "Codigo Postal: ";
    cin >> cliente.direccion_postal.codigo_postal;
    cin.ignore();
    cout << "Provincia: ";
    getline(cin, cliente.direccion_postal.provincia);
    
    cout << "\nAutomoviles: ";
    cout << "\nNumero de Automoviles que posee (MAX: 5): ";
    cin >> cant_autos;
    for (i = 0; i < cant_autos; i++)
    {
        if (cant_autos > 1)
        {
            cout << "Datos del Auto Numero " << i + 1 << endl;
        }
        cout << "Matricula: ";
        cin >> cliente.vehiculos[i].matricula;
        cout << "Fecha Revision: ";
        cout << "\n\tDia: ";
        cin >> cliente.vehiculos[i].revision.dia;
        cout << "\tMes: ";
        cin >> cliente.vehiculos[i].revision.mes;
        cout << "\tAno: ";
        cin >> cliente.vehiculos[i].revision.ano;
        cout << "Kilometraje: ";
        cin >> cliente.vehiculos[i].kilometros;
        cout << "Proxima Fecha: ";
        cout << "\n\tDia: ";
        cin >> cliente.vehiculos[i].prox_revision.dia;
        cout << "\tMes: ";
        cin >> cliente.vehiculos[i].prox_revision.mes;
        cout << "\tAno: ";
        cin >> cliente.vehiculos[i].prox_revision.ano;
    }
    
    cout << "\n\n";
    
    MostrarCliente(cliente, cant_autos);
    
    return;
}

/************************** MostrarCliente ******************************//**
*
* Muestra la informacion de un cliente
*
* @param[in] cliente Cliente al que hay que mostrar su informacion
*
*//********************************************************************/
void MostrarCliente (const Clientes cliente, int cant_autos)
{
    int i;
    
    cout << "Cliente Intoducido:\n";
    cout << "\nDatos Personales\n";
    cout << "Nombre: " << cliente.nombre_compl.nombre << " " << cliente.nombre_compl.apellidos;
    cout << "\nE-mail: " << cliente.e_mail;
    cout << "\nDNI: " << cliente.dni;
    
    cout << "\nDireccion Postal: ";
    cout << "\nCalle: " << cliente.direccion_postal.calle;
    cout << "\nNumero del Portal: " << cliente.direccion_postal.numero_portal;
    cout << "\nCodigo Postal: " << cliente.direccion_postal.codigo_postal;
    cout << "\nProvincia: " << cliente.direccion_postal.provincia;
    
    cout << "\n\nAutomoviles: ";
    for (i = 0; i < cant_autos; i++)
    {
        if (cant_autos > 1)
        {
            cout << "\nDatos del Auto Numero " << i + 1 << endl;
        }
        cout << "\nMatricula: " << cliente.vehiculos[i].matricula;
        cout << "\nFecha Revision: " << cliente.vehiculos[i].revision.dia << "/" << cliente.vehiculos[i].revision.mes;
        cout << "/" << cliente.vehiculos[i].revision.ano;
        cout << "\nKilometraje: " << cliente.vehiculos[i].kilometros;
        cout << "\nProxima Fecha de Revision: " << cliente.vehiculos[i].prox_revision.dia;
        cout << "/" << cliente.vehiculos[i].prox_revision.mes;
        cout << "/" << cliente.vehiculos[i].prox_revision.ano;
    }
    
    cout << "\n\n";
    
    return;
}

