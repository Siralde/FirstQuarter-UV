/**
 * @file b8_2_clientes.cpp
 *
 * @brief Ejercicio 02: Boletin 8, Gestion de un cliente de un taller mecanico.
 *
 * Gestiona un solo cliente de un taller mecanico
 *
 * @version 1
 * @author Aldemaro Gonzalez
 * @date 01/01/2018
 */
#include <fstream>
#include <cctype>
#include <string>
#include <iostream>
using namespace std;

const int MAX = 50;
const string FICH_CLIENTES = "b8_2_clientes.info";

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

struct Cliente
{
    Nombre nombre_compl;
    Direccion direccion_postal;
    string e_mail, dni;
    automoviles vehiculos;
    int cant_autos;
};

void Presentacion ();
void LeerMostrarClientes ();
bool LeerClienteFichero (ifstream &, Cliente &);
bool LeerCocheFichero (ifstream & f, Cliente & cliente);
void MostrarCliente (const Cliente);
unsigned short ContarCoches (unsigned short);
bool LeerClienteFicheroParaContarCoches  (ifstream & f, Cliente & cliente, automoviles, int & cant_coches_taller);
bool LeerCocheFicheroParaContarCoches (ifstream & f, Cliente & cliente, automoviles, int & cant_coches_taller);

int main (void)
{
    string pais;
    unsigned short anyo, num_coches;
    
    Presentacion ();
    
    LeerMostrarClientes ();
    
    cout << "Dame el ano de revision: ";
    cin >> anyo;
    
    num_coches = ContarCoches(anyo);
    
    if (num_coches == 0)
    {
        cout << "\nNo hubo ningun coche revisado en ese ano.\n\n";
    }
    
    else if (num_coches == 1)
    {
        cout << "\nSolo un coche paso por revision en el anyo ";
        cout << anyo << ".\n\n";
    }
    else
    {
        cout << "\nEl numero de coches que pasaron por revision en el anyo ";
        cout << anyo << " fueron " << num_coches << " coches.\n\n";
    }
    
    return 0;
}
/************************** Presentacion ******************************//**
*
* Muestra por pantalla las funciones de este programa para informale al
* usuario
*
*//*************************************************************************/
void Presentacion(void)
{
    cout << "Este programa realiza las siguientes funciones: \n";
    cout << "Lee uno a uno los clientes contenidos en ";
    cout << "el fichero y los muestre por pantalla.";
    cout << endl;
    cout << "Muestra el número de vehículos que pasaron ";
    cout << "la revisión en el año introducido por teclado.";
    cout << endl << endl;
    
    return;
}
/************************** LeerMostrarClientes ******************************//**
*
* Gestiona la lectura y la muestra por pantalla de los clientes de un
* fichero
*
*//*************************************************************************/
void LeerMostrarClientes(void)
{
    Cliente cliente;
    ifstream f;

    f.open(FICH_CLIENTES.c_str());
    if(!f)
        cout << "Error abriendo el fichero" << endl;
    else
    {
        while (LeerClienteFichero(f, cliente))
        {
            MostrarCliente(cliente);
            cout << endl << endl;
        }
        f.close();
    }
    return;
}

/************************** LeerClienteFichero ******************************//**
*
* Lee el cliente de un fichero
*
* @param[in] f          Descriptor del fichero
* @param[in] cliente    Vector de clientes que tiene el taller
*
* @retval true Cliente ha sido leido correctamente
* @retval false Cliente no ha sido leido correctamente
*
*//*************************************************************************/
bool LeerClienteFichero (ifstream & f, Cliente & cliente)
{
    bool lectura_ok = false;
    
    if (getline (f, cliente.nombre_compl.nombre))
    {
        getline (f, cliente.nombre_compl.apellidos);
        getline (f, cliente.direccion_postal.calle);
        getline (f, cliente.direccion_postal.numero_portal);
        f >> cliente.direccion_postal.codigo_postal;
        f.ignore();
        getline (f, cliente.direccion_postal.provincia);
        getline (f, cliente.e_mail);
        getline (f, cliente.dni);
        
        lectura_ok = LeerCocheFichero(f, cliente);
    }
    
    return lectura_ok;
}
/************************** LeerCocheFichero ******************************//**
*
* Lee el cliente de un fichero
*
* @param[in] f          Descriptor del fichero
* @param[in] cliente    Vector de clientes que tiene el taller
*
* @retval true Cliente ha sido leido correctamente
* @retval false Cliente no ha sido leido correctamente
*
*//*************************************************************************/
bool LeerCocheFichero (ifstream & f, Cliente & cliente)
{
    bool lectura_ok = false;
    int i;
    
    if(f >> cliente.cant_autos)
        {
        for (i = 0; i < cliente.cant_autos; i++)
        {
            f >> cliente.vehiculos[i].matricula;
            f.ignore();
            f >> cliente.vehiculos[i].kilometros;
            f >> cliente.vehiculos[i].revision.dia;
            f.ignore();
            f >> cliente.vehiculos[i].revision.mes;
            f.ignore();
            f >> cliente.vehiculos[i].revision.ano;
            f.ignore();
            
            lectura_ok = true;
        }
    }
    
    return lectura_ok;
}

/************************** MostrarCliente ******************************//**
*
* Muestra la informacion de un cliente
*
* @param[in] cliente Cliente al que hay que mostrar su informacion
*
*//********************************************************************/
void MostrarCliente (const Cliente cliente)
{
    int j;
    
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
    
    for (j = 0; j < cliente.cant_autos; j++)
    {
        if (cliente.cant_autos > 1)
        {
            cout << "\n\nDatos del Auto Numero " << j + 1 << endl;
        }
        cout << "\nMatricula: " << cliente.vehiculos[j].matricula;
        cout << "\nFecha Revision: " << cliente.vehiculos[j].revision.dia;
        cout << "/" << cliente.vehiculos[j].revision.mes;
        cout << "/" << cliente.vehiculos[j].revision.ano;
        cout << "\nKilometraje: " << cliente.vehiculos[j].kilometros;
    }
    
    return;
}

/************************** ContarCoches ******************************//**
*
* Cuenta la cantidad de coches que tuvieron revision en un ano determinado
*
* @param[in] ano Ano de verificacion
*
* @return Cantidad de coches revisados en el ano introducido
*
*//********************************************************************/
unsigned short ContarCoches (unsigned short ano)
{
    int i, cant_coches_taller = 0;
    unsigned short contador = 0;
    ifstream f;
    Cliente cliente;
    automoviles ano_coches;
    
    f.open(FICH_CLIENTES.c_str());
    if(!f)
        cout << "Error abriendo el fichero" << endl;
    else
    {
        while (LeerClienteFicheroParaContarCoches(f, cliente, ano_coches, cant_coches_taller))
        {
            ;
        }
        f.close();
    }
    
    for (i = 0; i < cant_coches_taller; i++)
    {

        if (ano_coches[i].revision.ano == ano)
        {
            contador++;
        }
    }
    
    return contador;
}
/************************** LeerClienteFicheroParaContarCoches ******************************//**
*
* Lee el cliente de un fichero
*
* @param[in] f                  Descriptor del fichero
* @param[in] cliente            Vector de clientes que tiene el taller
* @param[in] ano_coches         Vector de autos que tiene el taller
* @param[in] cant_coches_taller Cantidad de coches que tiene el taller
*
* @retval true Cliente ha sido leido correctamente
* @retval false Cliente no ha sido leido correctamente
*
*//*********************************************************************************************/
bool LeerClienteFicheroParaContarCoches  (ifstream & f, Cliente & cliente, automoviles ano_coches, int & cant_coches_taller)
{
    bool lectura_ok = false;
    
    if (getline (f, cliente.nombre_compl.nombre))
    {
        getline (f, cliente.nombre_compl.apellidos);
        getline (f, cliente.direccion_postal.calle);
        getline (f, cliente.direccion_postal.numero_portal);
        f >> cliente.direccion_postal.codigo_postal;
        f.ignore();
        getline (f, cliente.direccion_postal.provincia);
        getline (f, cliente.e_mail);
        getline (f, cliente.dni);
        
        lectura_ok = LeerCocheFicheroParaContarCoches(f, cliente, ano_coches, cant_coches_taller);
    }
    
    return lectura_ok;
}
/************************** LeerCocheFicheroParaContarCoches ******************************//**
*
* Lee el cliente de un fichero
*
* @param[in] f                  Descriptor del fichero
* @param[in] cliente            Vector de clientes que tiene el taller
* @param[in] ano_coches          Vector de autos que tiene el taller
* @param[in] cant_coches_taller Cantidad de coches que tiene el taller
*
* @retval true Cliente ha sido leido correctamente
* @retval false Cliente no ha sido leido correctamente
*
*//*********************************************************************************************/
bool LeerCocheFicheroParaContarCoches (ifstream & f, Cliente & cliente, automoviles ano_coches, int & cant_coches_taller)
{
    bool lectura_ok = false;
    int i, j = cant_coches_taller;
    
    if(f >> cliente.cant_autos)
    {
        for (i = 0; i < cliente.cant_autos; i++)
        {
            f >> cliente.vehiculos[i].matricula;
            f.ignore();
            f >> cliente.vehiculos[i].kilometros;
            f >> cliente.vehiculos[i].revision.dia;
            f.ignore();
            f >> cliente.vehiculos[i].revision.mes;
            f.ignore();
            f >> cliente.vehiculos[i].revision.ano;
            f.ignore();
            ano_coches[j].revision.ano = cliente.vehiculos[i].revision.ano;
            
            j++;
        
            lectura_ok = true;
        }
        
        cant_coches_taller += i;
    }
    
    return lectura_ok;
}
