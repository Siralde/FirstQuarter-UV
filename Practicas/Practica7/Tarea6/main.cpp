/********* Practica7 *********/ /*
 * @file b1_1laboratorio.cpp
 *
 * @brief Ejercicio 01. Boletin01
 *
 * Determina la edad del usuario a partir de la informacion proporcionada
 * por teclado
 * Pasar las unidades desde el sistema internacional a las unidades
 * británicas
 * @author Alejandro Martí
 * @date 28/9/2017
 / /**************************/

#include <iostream>
using namespace std;

struct Punto
{
    float x;
    float y;
    float z;
};

const int MAX = 20;
typedef Punto Vector [MAX];

void LeerPunto(Punto &p);
void MostrarPunto(Punto);
void SumarPunto(Punto, Punto);
void DividirPunto(Punto, int);
void Baricentro(Punto p, int a, Punto bar);

int main(void)
{
    int a, i;
    Punto bar{};
    Vector puntos;
    cout << "Introduce el numero de puntos" << endl;
    cin >> a;
    
    for (i = 0; i < a; i++)
    {
        cout << "Introduce el punto :" << endl;
        LeerPunto(puntos[i]);
    }
    //for (int i = 0; i < a; i++)
    //{
    //  MostrarPunto(puntos[i]);
    //}
    for (i = 0; i < a; i++)
    {
        //SumarPunto(puntos[i], puntos[i + 1]);
        Baricentro(puntos[i], a, bar);
    }
    cout << "MAIN Baricentro : " << "("<< bar.x  << " , " << bar.y / a << " , " << bar.z / a << ")" << endl;
    
    
    //cout << "Introduce el escalar:" << endl;
    //cin >> a;
    //cout << "Punto 1" << endl;
    //MostrarPunto(p1);
    //cout << "Punto 2" << endl;
    //MostrarPunto(p2);
    //cout << "Suma de puntos" << endl;
    //SumarPunto(p1, p2);
    //cout << "Division del primer punto por el escalar" << endl;
    //DividirPunto(p1, a);
}
void LeerPunto(Punto &p)
{
    cout << "Dame valor de x" << endl;
    cin >> p.x;
    cout << "Dame valor de y" << endl;
    cin >> p.y;
    cout << "Dame valor de z" << endl;
    cin >> p.z;
}
void MostrarPunto(const Punto p)
{
    //cout << "("<< p.x << " , " << p.y << " , " << p.z << ")" << endl;
    cout << "("<< p.x << ")" << endl;
}
void SumarPunto(Punto p, Punto p2)
{
    cout << "("<< p.x + p2.x << " , " << p.y + p2.y << " , " << p.z + p2.z << ")" << endl;
}
void DividirPunto(Punto p, int a)
{
    cout << "("<< p.x / a << " , " << p.y / a << " , " << p.z / a << ")" << endl;
}
void Baricentro(Punto p, int a, Punto bar)
{
    
    bar.x = bar.x + p.x;
    bar.y = bar.y + p.y;
    bar.z = bar.z + p.z;
    cout << "Baricentro : " << "("<< bar.x  << " , " << bar.y << " , " << bar.z << ")" << endl;
    //bar = bar + p.x/a + p.y/a + p.z/a;
    //cout << "Baricentro : " << "("<< p.x / a << " , " << p.y / a << " , " << p.z / a << ")" << endl;
}
