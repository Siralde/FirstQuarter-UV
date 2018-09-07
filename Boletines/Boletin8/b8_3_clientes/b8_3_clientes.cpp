/**
 * @file b7_3_clientes.cpp
 *
 * @brief Ejercicio 03: Boletin 8, Gestion de varios clientes de un taller mecanico.
 *
 * Gestion varios clientes de un taller mecanico
 *
 * @version 1
 * @author Aldemaro Gonzalez
 * @date 02/01/2018
 */
#include <fstream>
#include <cctype>
#include <string>
#include <iostream>
using namespace std;

const int MAX = 5;
const int MAX_CLIENTES = 20;
const int NUM_CLIENTES = 2;
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

struct Clientes
{
    Nombre nombre_compl;
    Direccion direccion_postal;
    string e_mail, dni;
    automoviles vehiculos;
    int cant_autos;
};
typedef Clientes cl [MAX_CLIENTES];

void Presentacion ();
void LeerMostrarClientes (cl & cliente);
bool LeerClienteFichero (ifstream &, cl &);
bool LeerCocheFichero (ifstream &, cl &, int);
void MostrarCliente (const cl);
void MostrarClienteMes(const cl, unsigned short);

int main (void)
{
    cl clientes;
    unsigned short mes;
    
    Presentacion ();
    
    LeerMostrarClientes (clientes);
    
    cout << "Dame el mes de revision: ";
    cin >> mes;
    
    MostrarClienteMes(clientes, mes);
    
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
void LeerMostrarClientes(cl & cliente)
{
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
* @param[in] f Descriptor del fichero
* @param[in] cliente Cantidad de Clientes introducida por el usuario
*
* @retval true Cliente ha sido leido correctamente
* @retval false Cliente no ha sido leido correctamente
*
*//*************************************************************************/
bool LeerClienteFichero (ifstream & f, cl & cliente)
{
    bool lectura_ok = false;
    int i;
    
    for (i = 0; i < NUM_CLIENTES; i++)
    {
        if (getline (f, cliente[i].nombre_compl.nombre))
        {
            cout << cliente[i].nombre_compl.nombre;
            
            getline (f, cliente[i].nombre_compl.apellidos);
            cout << cliente[i].nombre_compl.apellidos;
            
            getline (f, cliente[i].direccion_postal.calle);
            cout << cliente[i].direccion_postal.calle;
            
            getline (f, cliente[i].direccion_postal.numero_portal);
            cout << cliente[i].direccion_postal.numero_portal;
            
            f >> cliente[i].direccion_postal.codigo_postal;
            cout << cliente[i].direccion_postal.codigo_postal;
            f.ignore();
            
            getline (f, cliente[i].direccion_postal.provincia);
            cout << cliente[i].direccion_postal.provincia;
            
            getline (f, cliente[i].e_mail);
            cout << cliente[i].e_mail;
            
            getline (f, cliente[i].dni);
            cout << cliente[i].dni;
            
            lectura_ok = LeerCocheFichero(f, cliente , i);
        }
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
bool LeerCocheFichero (ifstream & f, cl & cliente, int j)
{
    bool lectura_ok = false;
    int i;
    
    if(f >> cliente[j].cant_autos)
    {
        for (i = 0; i < cliente[j].cant_autos; i++)
        {
            f >> cliente[j].vehiculos[i].matricula;
            cout << cliente[j].vehiculos[i].matricula;
            f.ignore();
            
            f >> cliente[j].vehiculos[i].kilometros;
            cout << cliente[j].vehiculos[i].kilometros;
            
            f >> cliente[j].vehiculos[i].revision.dia;
            cout << cliente[j].vehiculos[i].revision.dia;
            f.ignore();
            
            f >> cliente[j].vehiculos[i].revision.mes;
            cout << cliente[j].vehiculos[i].revision.mes;
            f.ignore();
            
            f >> cliente[j].vehiculos[i].revision.ano;
            cout << cliente[j].vehiculos[i].revision.ano;
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
void MostrarCliente (const cl cliente)
{
    int j, i;
    
    for (i = 0; i < NUM_CLIENTES; i++)
    {
        cout << "\nCliente Intoducido:\n";
        cout << "\nDatos Personales\n";
        cout << "Nombre: " << cliente[i].nombre_compl.nombre << " " << cliente[i].nombre_compl.apellidos;
        cout << "\nE-mail: " << cliente[i].e_mail;
        cout << "\nDNI: " << cliente[i].dni;
        cout << "\nDireccion Postal: ";
        cout << "\nCalle: " << cliente[i].direccion_postal.calle;
        cout << "\nNumero del Portal: " << cliente[i].direccion_postal.numero_portal;
        cout << "\nCodigo Postal: " << cliente[i].direccion_postal.codigo_postal;
        cout << "\nProvincia: " << cliente[i].direccion_postal.provincia;
        cout << "\n\nAutomovil(es): ";
        
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
        }
    }
    return;
}

/************************** MostrarClienteMes ******************************//**
*
* Muestra la informacion de un cliente
*
* @param[in] cliente Cliente al que hay que mostrar su informacion
* @param[in] mes     Mes de verificacion
*
*//****************************************************************************/
void MostrarClienteMes(const cl cliente, unsigned short mes)
{
    int j, i;
    bool encontrado = false;
    
    for (i = 0; i < NUM_CLIENTES; i++)
    {
        for (j = 0; j < cliente[i].cant_autos; j++)
        {
            if (cliente[i].vehiculos[j].revision.mes == mes)
            {
                encontrado = true;
                
                cout << "\nCliente Encontrado:\n";
                cout << "\nDatos Personales\n";
                cout << "Nombre: " << cliente[i].nombre_compl.nombre << " " << cliente[i].nombre_compl.apellidos;
                cout << "\nE-mail: " << cliente[i].e_mail;
                cout << "\nDNI: " << cliente[i].dni;
                cout << "\nDireccion Postal: ";
                cout << "\nCalle: " << cliente[i].direccion_postal.calle;
                cout << "\nNumero del Portal: " << cliente[i].direccion_postal.numero_portal;
                cout << "\nCodigo Postal: " << cliente[i].direccion_postal.codigo_postal;
                cout << "\nProvincia: " << cliente[i].direccion_postal.provincia;
                cout << "\n\nAutomovil(es): ";
                if (cliente[i].cant_autos > 1)
                {
                    cout << "\n\nDatos del Auto Numero " << j + 1 << endl;
                }
                cout << "\nMatricula: " << cliente[i].vehiculos[j].matricula;
                cout << "\nFecha Revision: " << cliente[i].vehiculos[j].revision.dia;
                cout << "/" << cliente[i].vehiculos[j].revision.mes;
                cout << "/" << cliente[i].vehiculos[j].revision.ano;
                cout << "\nKilometraje: " << cliente[i].vehiculos[j].kilometros;
            }
            
        }
    }
    
    if (encontrado == false)
    {
        cout << "\nNingun coche paso por revision este mes.";
    }
    
    cout << endl << endl;
    
    return;
}
