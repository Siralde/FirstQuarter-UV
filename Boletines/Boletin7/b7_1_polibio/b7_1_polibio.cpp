/**
 * @file b7_1_polibio.cpp
 *
 * @brief Ejercicio 01: Boletin 7, codifificacion y decodificacion de frases.
 *
 * Este programa codifica/decodifica una frase por el metodo de
 * Polibio.
 *
 * @version 1
 * @author Aldemaro Gonzalez
 * @date 12/12/2017
 */
#include <cctype>
#include <string>
#include <iostream>
using namespace std;

const int MAX = 5;
const string ABECEDARIO = "ABCDEFGHIJKLMNOPQRSTUVXYZ";
typedef char Matriz [MAX][MAX];


string MatrizBifido(string clave, string frase);
string Codifica(string frase, string clave);
string Decodifica(string frase, string clave);

int main (void)
{
    string clave, frase, codificada, decodificada;
    char op;
    
    //Empezamos el programa explicando al usuario lo que hace
    cout << "Este programa codifica/decodifica ";
    cout << "una frase por el metodo de Polibio.\n";
    
    /*
     * Procesamos la informacion
     */
    do {
        cout << "\nDame tarea a realizar (codifica-c/decodifica-d/salir-s): ";
        cin >> op;
        cin.ignore();
        switch (op)
        {
            case 'c':
            case 'C':
                cout << "Crea una clave: ";
                cin >> clave;
                cout << "Dame frase: ";
                getline(cin, frase);
                codificada = Codifica(frase, clave);
                cout << "La frase codificada es: ";
                cout << "\t" << codificada << endl << endl;
                break;
            case 'd':
            case 'D':
                cout << "Dame clave: ";
                cin >> clave;
                cout << "Dame frase: ";
                getline(cin, frase);
                decodificada = Codifica(frase, clave);
                cout << "La frase decodificada es: ";
                cout << "\t" << decodificada << endl << endl;
                break;
            case 's':
            case 'S':
                break;
            default:
                cout << "Opcion no valida, intente otra vez.\n\n";
                break;
    
        }
    } while (op == 'c' || op == 'd' || op == 'C' || op == 'D');
    
    return 0;
}
/************************ MatrizBifido *********************//
*
* Verifica si la clave introducida es correcta
*
* @param[in] clave Clave introducida por el usuario
* @param[in] frase Frase introducida por el usuario
*
* @retval true Clave correcta
* @retval false Clave incorrecta
*
*//*************************************************************/
string MatrizBifido (string clave, string frase)
{
    string mb;
    Matriz matriz;
    int fila, colum, i= 0, j = 0;
    
    //Creamos la matriz de Bifido
    for (fila = 0; fila < MAX; fila++)
    {
        for (colum = 0; colum < MAX; colum++)
        {
            if (i < frase.length())
            {
                matriz[fila][colum] = clave[i];
                i++
            }//IF RELLENO CON CLAVE
            else
            {
                if (matriz[fila][colum] == ABECEDARIO[j])
                {
                    j++
                }
                else
                {
                    matriz[fila][colum] == ABECEDARIO[j];
                    j++
                }
            }//ELSE RELLENO CON ABECEDARIO
        }//FOR COLUMNA
    }//FOR FILA
    
    for (fila = 0; fila < MAX; fila++)
    {
        for (colum = 0; colum < MAX; colum++)
        {
            frase_mb = frase_mb + matriz[fila][colum];
        }
    }
    
    cout << frase_mb;
    
    return frase_mb;
}

/*************************** Codifica ************************//**
*
* Codifica una frase por el metodo de polibio
*
* @param[in] frase Frase que se tiene que decodificar
*
* @return Frase codificada
*
*//*************************************************************/
string Codifica(string frase, string clave)
{
    size_t i;
    string frase_co, frase_x;
    
    //Para sustituir los espacios por X
    for (i = 0; i < MAX; i++)
    {
        if (frase[i] == ' ')
        {
            frase[i] = 'X';
        }
        frase_x = frase_x + to_string (toupper(frase[i])) ;
        
    }

    frase_co = MatrizBifido(clave, frase_x);
    
    return frase_co;
}

/************************** Decodifica ************************//**
*
* Decodifica una frase por el metodo de polibio
*
* @param[in] frase Frase que se tiene que decodificar
*
* @return Frase decodificada
*
*//***************************************************************/
string Decodifica(string frase)
{
    size_t i;
    string frase_de;
    
    //Para sustituir las X por espacios
    for (i = 0; i < MAX; i++)
    {
        if (frase[i] == 'X')
        {
            frase[i] = ' ';
        }
        frase_de = frase_de + to_string (toupper(frase[i])) ;
        
    }
    
    return frase_de;
}
