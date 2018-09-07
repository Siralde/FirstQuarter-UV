/**
 * @file b7_3_clientes.cpp
 *
 * @brief Ejercicio 03: Boletin 7, Gestion de varios clientes de un taller mecanico.
 *
 * Gestion varios clientes de un taller mecanico
 *
 * @version 1
 * @author Aldemaro Gonzalez
 * @date 21/12/2017
 */
#include <cctype>
#include <string>
#include <iostream>
using namespace std;

const int MAX_AUTOS = 5;
const int MAX_CLIENTES = 20;

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

typedef Autos automoviles [MAX_AUTOS];

struct Clientes
{
    Nombre nombre_compl;
    Direccion direccion_postal;
    string e_mail, dni;
    int cant_autos;
    automoviles vehiculos;
    bool un_coche;
};

typedef Clientes cl [MAX_CLIENTES];

void BusquedaPorFechas(const cl cliente ,int cant_clientes,int dia1, int mes1, int ano1, int dia2, int mes2, int ano2);
void UnCoche (const cl cliente, int cant_clientes);
string Mayusculas (string palabra);
void BuscadorDePersonas (string nom_cliente, int cant_clientes, const cl clientes);
bool NombreIguales (string nom_cliente, int cant_clientes, const cl clientes, int & posicion);
void LeerCliente (cl, int);
void MostrarCliente (const cl, int);
int main (void)
{
    cl clientes;
    int i, opcion, cant_clientes = 0, mas_clientes, total_clientes = 0;
    string nom_cliente;
    int dia1, dia2, mes1, mes2, ano1, ano2;
    
    do
    {
        cout << "Opcion 1: Anadir Nuevo Cliente\nOpcion 2: Buscar Cliente\n";
        cout << "Opcion 3: Mostrar todos los clientes\nOpcion 4: Mostrar clientes con un solo coche";
        cout << "\nOpcion 5: Coches con la revision pasada entre dos fechas\nOpcion 6: Salir\nElige una opcion: ";
        cin >> opcion;
        switch (opcion)
        {
            case 1:
                cout << "\n Cuantos Clientes quieres anadir: ";
                if (cant_clientes == 0)
                {
                    cin >> cant_clientes;
                    cout << endl << endl;
                    for (i = 0; i < cant_clientes; i++)
                    {
                        cout << " Cliente numero: " << i + 1 << endl;
                        LeerCliente(clientes, i);
                    }
                }
                else
                {
                    cin >> mas_clientes;
                    cout << endl << endl;
                    total_clientes = cant_clientes + mas_clientes;
                    for (i = cant_clientes; i < total_clientes; i++)
                    {
                        cout << " Cliente numero: " << i + 1 << endl;
                        LeerCliente(clientes, i);
                    }
                }
                break;
            case 2:
                if (total_clientes == 0)
                {
                    if (cant_clientes == 0)
                    {
                        cout << "\n Primero introduce un cliente\n\n";
                    }
                    else
                    {
                        cout << "\n Dame el nombre del cliente a buscar: ";
                        cin >> nom_cliente;
                        BuscadorDePersonas(nom_cliente, cant_clientes, clientes);
                    }
                }
                else
                {
                    cout << "\n Dame el nombre del cliente a buscar: ";
                    cin >> nom_cliente;
                    BuscadorDePersonas(nom_cliente, total_clientes, clientes);
                }
                break;
            case 3:
                if (total_clientes == 0)
                {
                    if (cant_clientes == 0)
                    {
                        cout << "\n Primero introduce un usuario\n\n";
                    } else {
                        for (i = 0; i < cant_clientes; i++)
                        {
                            cout << "\n Cliente Numero: " << i + 1 << endl;
                            MostrarCliente(clientes, i);
                        }
                    }
                }
                else
                {
                    for (i = 0; i < total_clientes; i++)
                    {
                        cout << "\n Cliente Numero: " << i + 1 << endl;
                        MostrarCliente(clientes, i);
                    }
                }
                break;
            case 4:
                if (total_clientes == 0)
                {
                    if (cant_clientes == 0)
                    {
                        cout << "\n Primero introduce un usuario\n\n";
                    }
                    else
                    {
                        UnCoche (clientes, cant_clientes);
                    }
                }
                else
                {
                    UnCoche (clientes, total_clientes);
                }
                break;
            case 5:
                if (cant_clientes == 0)
                {
                    cout << "\n Primero introduce un cliente\n\n";
                }
                else
                {
                    cout << "\nDame dos fechas:\n\tFecha 1\n\tDia: ";
                    cin >> dia1;
                    cout << "\tMes: ";
                    cin >> mes1;
                    cout << "\tAno: ";
                    cin >> ano1;
                    cout << "\n\tFecha 2\n\tDia: ";
                    cin >> dia2;
                    cout << "\tMes: ";
                    cin >> mes2;
                    cout << "\tAno: ";
                    cin >> ano2;
                    if (total_clientes == 0)
                    {
                        BusquedaPorFechas(clientes, cant_clientes, dia1, mes1, ano1, dia2, mes2, ano2);
                    }
                    else
                    {
                        BusquedaPorFechas(clientes, total_clientes, dia1, mes1, ano1, dia2, mes2, ano2);
                    }
                }
                break;
            case 6:
                break;
            default:
                cout << "\n Opcion Invalida, por favor intente nuevamente\n\n";
                break;
        }
    }
    while (opcion != 6);
    
    cout << endl << endl;
    
    return 0;
    
}

/************************** BuscadorDePersonas ******************************//**
*
* Busca a una persona mediante el nombre introducido por el usuario
*
* @param[in] nom_cliente Nombre del cliente al que hay que buscar
* @param[in] cant_clientes Cantidad de Clientes introducida por el usuario
* @param[in] clientes Vector de clientes al que hay que comparar su nombre
*                     con el nombre introducido
*
*//*************************************************************************/
void BuscadorDePersonas (string nom_cliente, int cant_clientes, const cl clientes)
{
    int posicion;
    bool encontrado;
    
    encontrado = NombreIguales(nom_cliente, cant_clientes, clientes, posicion);
    
    if (encontrado == true)
    {
        cout << "\nCliente encontrado\n";
        MostrarCliente(clientes, posicion);
    }
    else
        cout << "\nCliente no Encontrado\n\n";
}

/******************************** UnCoche ******************************//**
*
* Muestra los clientes con un solo cocho y crea una estructura de datos
* para los clientes que solo tengan un coche
*
* @param[in] cliente Todos lo clientes
* @param[in] cant_clientes Cantidad de Clientes introducida por el usuario
*
*//*************************************************************************/
void UnCoche (const cl cliente, int cant_clientes)
{
    int i;
    cl un_coche;
    
    for (i = 0; i < cant_clientes; i++)
    {
        if (cliente[i].cant_autos == 1)
        {
            
            un_coche[i].nombre_compl.nombre = cliente[i].nombre_compl.nombre;
            un_coche[i].nombre_compl.apellidos = cliente[i].nombre_compl.apellidos;
            un_coche[i].e_mail = cliente[i].e_mail;
            un_coche[i].dni = cliente[i].dni;
            un_coche[i].direccion_postal.calle = cliente[i].direccion_postal.calle;
            un_coche[i].direccion_postal.numero_portal = cliente[i].direccion_postal.numero_portal;
            un_coche[i].direccion_postal.codigo_postal = cliente[i].direccion_postal.codigo_postal;
            un_coche[i].direccion_postal.provincia= cliente[i].direccion_postal.provincia;
            un_coche[i].cant_autos = cliente[i].cant_autos;
            un_coche[i].cant_autos = cliente[i].cant_autos;
            un_coche[i].vehiculos[0].matricula = cliente[i].vehiculos[0].matricula;
            un_coche[i].vehiculos[0].revision.dia = cliente[i].vehiculos[0].revision.dia;
            un_coche[i].vehiculos[0].revision.mes = cliente[i].vehiculos[0].revision.mes;
            un_coche[i].vehiculos[0].revision.ano = cliente[i].vehiculos[0].revision.ano;
            un_coche[i].vehiculos[0].kilometros = cliente[i].vehiculos[0].kilometros;
            un_coche[i].vehiculos[0].prox_revision.dia = cliente[i].vehiculos[0].prox_revision.dia;
            un_coche[i].vehiculos[0].prox_revision.mes = cliente[i].vehiculos[0].prox_revision.mes;
            un_coche[i].vehiculos[0].prox_revision.ano = cliente[i].vehiculos[0].prox_revision.ano;
            MostrarCliente(un_coche, i);
        }
    }
}

/************************** NombreIguales ******************************//**
*
* Lee toda la informacion necesaria de un cliente
*
* @param[in] nom_cliente Nombre del cliente al que hay que buscar
* @param[in] cant_clientes Cantidad de Clientes introducida por el usuario
* @param[in] clientes Cliente al que hay que introducirle la informacion
* @param[out] posicion Posicion del registro del cliente en el vector
*
* @retval true Se encontro a la persona
* @retval false No se encontro a la persona
*
*//**************************************************************************/
bool NombreIguales (string nom_cliente, int cant_clientes, const cl clientes, int & posicion)
{
    bool iguales = false;
    string nombre_actual;
    int i = 0;
    string nom_buscador_may, nom_cliente_may;
    
    nom_buscador_may = Mayusculas(nom_cliente);
    
    for (i = 0; i < cant_clientes; i++)
    {
        nombre_actual = clientes[i].nombre_compl.nombre;
        nom_cliente_may = Mayusculas(nombre_actual);
        
        if (nom_buscador_may == nom_cliente_may)
        {
            iguales = true;
            posicion = i;
        }
    }
    
    return iguales;
}

/************************** Mayusculas ******************************//**
*
* Busca a una persona mediante el nombre introducido por el usuario
*
* @param[in] palabra Palabra que hay que hay que hacer mayuscula
*
* @return Palabra mayuscula
*
*//*************************************************************************/
string Mayusculas (string palabra)
{
    string mayuscula;
    size_t i;
    
    for (i = 0; i < palabra.length(); i++)
    {
        
        mayuscula += toupper(palabra[i]);
    }
    
    return mayuscula;
}

/************************** LeerCliente ******************************//**
*
* Lee toda la informacion necesaria de un cliente
*
* @param[in] cliente Cliente al que hay que introducirle la informacion
* @param[in] j Posicion a introducir el cliente
*
*//********************************************************************/
void LeerCliente (cl cliente, int j)
{
    int i;
    
    cout << "Introduce los siguientes campos\n";
    cout << "Datos Personales\n";
    cout << "Nombre: ";
    cin >> cliente[j].nombre_compl.nombre;
    cin.ignore();
    cout << "Apellidos: ";
    getline (cin, cliente[j].nombre_compl.apellidos);
    cout << "E-mail: ";
    cin >> cliente[j].e_mail;
    cout << "DNI: ";
    cin >> cliente[j].dni;
    cin.ignore();
    
    cout << "\nDireccion Postal: ";
    cout << "\nCalle: ";
    getline (cin, cliente[j].direccion_postal.calle);
    cout << "Numero del Portal: ";
    cin >> cliente[j].direccion_postal.numero_portal;
    cout << "Codigo Postal: ";
    cin >> cliente[j].direccion_postal.codigo_postal;
    cin.ignore();
    cout << "Provincia: ";
    getline(cin, cliente[j].direccion_postal.provincia);
    
    cout << "\nAutomoviles: ";
    cout << "\nNumero de Automoviles que posee (MAX: " << MAX_AUTOS << "): ";
    cin >> cliente[j].cant_autos;
    for (i = 0; i < cliente[j].cant_autos; i++)
    {
        if (cliente[j].cant_autos > 1)
        {
            cout << "Datos del Auto Numero " << i + 1 << endl;
        }
        cout << "Matricula: ";
        cin >> cliente[j].vehiculos[i].matricula;
        cout << "Fecha Revision: ";
        cout << "\n\tDia: ";
        cin >> cliente[j].vehiculos[i].revision.dia;
        cout << "\tMes: ";
        cin >> cliente[j].vehiculos[i].revision.mes;
        cout << "\tAno: ";
        cin >> cliente[j].vehiculos[i].revision.ano;
        cout << "Kilometraje: ";
        cin >> cliente[j].vehiculos[i].kilometros;
        cout << "Proxima Fecha: ";
        cout << "\n\tDia: ";
        cin >> cliente[j].vehiculos[i].prox_revision.dia;
        cout << "\tMes: ";
        cin >> cliente[j].vehiculos[i].prox_revision.mes;
        cout << "\tAno: ";
        cin >> cliente[j].vehiculos[i].prox_revision.ano;
    }
    cout << endl << endl;
    
    return;
}

/************************** MostrarCliente ******************************//**
*
* Muestra la informacion de un cliente
*
* @param[in] cliente Cliente al que hay que mostrar su informacion
* @param[in] i Cliente
*
*//********************************************************************/
void MostrarCliente (const cl cliente, int i)
{
    int j;
    
    cout << "\nDatos Personales\n";
    cout << "Nombre: " << cliente[i].nombre_compl.nombre << " " << cliente[i].nombre_compl.apellidos;
    cout << "\nE-mail: " << cliente[i].e_mail;
    cout << "\nDNI: " << cliente[i].dni;
    
    cout << "\nDireccion Postal: ";
    cout << "\nCalle: " << cliente[i].direccion_postal.calle;
    cout << "\nNumero del Portal: " << cliente[i].direccion_postal.numero_portal;
    cout << "\nCodigo Postal: " << cliente[i].direccion_postal.codigo_postal;
    cout << "\nProvincia: " << cliente[i].direccion_postal.provincia;
    
    cout << "\n\nAutomoviles: ";
    for (j = 0; j < cliente[i].cant_autos; j++)
    {
        if (cliente[i].cant_autos > 1)
        {
            cout << "\nDatos del Auto Numero " << j + 1 << endl;
        }
        cout << "\nMatricula: " << cliente[i].vehiculos[j].matricula;
        cout << "\nFecha Revision: " << cliente[i].vehiculos[j].revision.dia;
        cout << "/" << cliente[i].vehiculos[j].revision.mes;
        cout << "/" << cliente[i].vehiculos[j].revision.ano;
        cout << "\nKilometraje: " << cliente[i].vehiculos[j].kilometros;
        cout << "\nProxima Fecha de Revision: " << cliente[i].vehiculos[j].prox_revision.dia;
        cout << "/" << cliente[i].vehiculos[j].prox_revision.mes;
        cout << "/" << cliente[i].vehiculos[j].prox_revision.ano;
    }
    
    cout << "\n\n";
    
    return;
}

/**************************BusquedaPorFechas ******************************//**
*
* Muestra la informacion de un cliente
*
* @param[in] cliente        Cliente al que hay que buscar si la revision
*                           de su auto fue entre la fecha introducida
* @param[in] cant_clientes  Cantidad de clientes del taller mecanico
* @param[in] dia1           Dia de la primera fecha introducida por el usuario
* @param[in] mes1           Mes de la primera fecha introducida por el usuario
* @param[in] ano1           Ano de la primera fecha introducida por el usuario
* @param[in] dia2           Dia de la segunda fecha introducida por el usuario
* @param[in] mes2           Mes de la segunda fecha introducida por el usuario
* @param[in] ano2           Ano de la segunda fecha introducida por el usuario
*
*//****************************************************************************/
void BusquedaPorFechas(const cl cliente ,int cant_clientes, int dia1, int mes1, int ano1, int dia2, int mes2, int ano2)
{
    int i, j;
    bool hay_coches = false;
    
    for (i = 0; i < cant_clientes ; i++)
    {
        for (j = 0; j < cliente[i].cant_autos; i++)
        {
            if (cliente[i].vehiculos[j].revision.ano >= ano1 && cliente[i].vehiculos[j].revision.ano <= ano2)
            {
                if (cliente[i].vehiculos[j].revision.mes >= mes1 && cliente[i].vehiculos[j].revision.mes <= mes2)
                {
                    if (cliente[i].vehiculos[j].revision.dia >= dia1 && cliente[i].vehiculos[j].revision.dia <= dia2)
                    {
                        hay_coches = true;
                        cout << "\nMatricula: " << cliente[i].vehiculos[j].matricula;
                        cout << "\nFecha Revision: " << cliente[i].vehiculos[j].revision.dia;
                        cout << "/" << cliente[i].vehiculos[j].revision.mes;
                        cout << "/" << cliente[i].vehiculos[j].revision.ano;
                        cout << "\nKilometraje: " << cliente[i].vehiculos[j].kilometros;
                        cout << "\nProxima Fecha de Revision: " << cliente[i].vehiculos[j].prox_revision.dia;
                        cout << "/" << cliente[i].vehiculos[j].prox_revision.mes;
                        cout << "/" << cliente[i].vehiculos[j].prox_revision.ano;
                        cout << endl;
                    }
                }
            }
        }
    }
    
    cout << endl;
    
    if (hay_coches == false)
    {
        cout << "\nNo existe coches entre estas fechas\n\n";
    }
    
    return;
}
