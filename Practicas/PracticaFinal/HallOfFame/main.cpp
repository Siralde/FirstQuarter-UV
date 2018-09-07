#include <iostream>
#include <string>
#include <fstream>
using namespace std;
const string FICH_JUGADORES = "puntuaciones.txt";
void HallOfFame(string name, int puntaje);
struct Jugador
{
    string nombre;
    int punt ;
};
const int DIM = 5;
typedef Jugador JugadorVect[DIM];

void MostrarJugadores (JugadorVect , int);
void MostrarJugador (Jugador prov);
void OrdenarVector(JugadorVect vec, int nelementos);

int main(void)
{
    string nombre;
    int puntos;
    int i;
    for (i = 0; i < 6; i++)
    {
    cout << "nombre:";
    cin >> nombre;
    cout << "puntos";
    cin >> puntos;
    HallOfFame(nombre, puntos);
    }
    
}
void HallOfFame(string name, int puntaje)
{
    string aux;
    char texto[128];
    int i = 1;
    JugadorVect vect;
    ifstream fich;
    ofstream fich2;
    
    fich.open (FICH_JUGADORES.c_str () );
    fich2.open (FICH_JUGADORES , ios :: app);
    
    if (!fich)
    {
        cout << "Error" << endl;
    }
    else
    {
        cout << "Abierto" << endl;
        vect[0].nombre = name;
        vect[0].punt = puntaje;
        while(fich >> texto)
        {
            fich >> vect[i].nombre;
            cout << i << "-" << vect[i].nombre << "------------" << endl;
            fich >> aux;
            vect[i].punt = stoi(aux);
            cout << i << "-" << vect[i].punt << "------------" << endl;
            i++;
        }
        cout << endl;
        
        
        fich2 << "........";
        fich2 << endl;
        fich2 << name;
        fich2 << endl;
        fich2 << puntaje;
        fich2 << endl;
        
        
        OrdenarVector(vect, i);
        MostrarJugadores(vect, i);
        fich.close ();
        fich2.close ();
    }
}
void MostrarJugadores (JugadorVect vec, int numjug)
{
    int i;
    cout << "******" << endl;
    cout << "* PUNTUACIONES *"<< endl;
    cout << "******" << endl;
    for (i = 0; i < numjug ; i++)
    {
        cout << i + 1 << " - ";
        MostrarJugador (vec[i]);
    }
    return;
}
void MostrarJugador (Jugador prov)
{
    cout << prov.nombre << " : " << prov.punt << " puntos. " << endl;
    return;
}
void OrdenarVector(JugadorVect vec, int nelementos)
{
    JugadorVect aux;
    int i, j;
    for (i = 0; i < nelementos; i ++)
        for (j = 0; j < nelementos; j ++)
            if(vec[i].punt > vec[j].punt)
            {
                aux[i] = vec[j];
                vec[j] = vec[i];
                vec[i] = aux[i];
            }
    return;
}
