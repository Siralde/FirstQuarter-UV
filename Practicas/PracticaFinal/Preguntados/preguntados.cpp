/**
 * @file preguntados.cpp
 *
 * @brief Juego 'Preguntados', hecho por Aldemaro Gonzalez.
 *
 * Responde preguntas aleatorias y gana categorias.
 *
 * @version 1
 * @author Aldemaro Gonzalez
 * @date 13/01/2018
 */
#include <stdlib.h>     /* srand, rand */
#include <fstream>
#include <cctype>
#include <string>
#include <iostream>
using namespace std;

const int IR_MENU = 30071998;                       ///< Para regresar al menu
const int PUNTAJE_INICIAL = 50;
const int NUMERO_DE_PREGUNTAS = 20;
const int HALL_OF_FAME = 5;
const string FICH_JUGADORES = "puntuaciones.txt";
const string PARTIDASUNJUGADOR = "1partida.txt";    ///< Nombre del fichero donde se guardan los nombre de las partidas guardadas en solitario
const string PARTIDADOSJUGADORES = "2partida.txt";
const int MAX = 6;                                  ///< Numero maximo de elementos de un vector

struct Pregunta
{
    string enunciado;
    string verdadera;
    string falsa1;
    string falsa2;
    string falsa3;
};

typedef Pregunta YaPreguntadas [NUMERO_DE_PREGUNTAS];

struct Categorias
{
    bool tito, albert, hector, bonzo, tina, pop;
};

struct DatosBinarios
{
    int cant_jugadores;
    int puntaje;
    Categorias categorias_ganadas;
    int num_preguntas_realizadas;
};

typedef DatosBinarios VDatosBinarios [2];

struct HallOfFame
{
    string nick;
    int puntuacion;
};

typedef HallOfFame VLosMejores [MAX];

struct Top
{
    VLosMejores mejores;
    int cant_jugadores;
};

typedef string VNombres_Guardados [10];

//Generales
bool HacerPregunta(Pregunta);
bool JuegoGanado(Categorias & categorias_ganadas);
//HallOfFame
bool HallOfFame(string, int);
bool LeerFicheroHallOfFame (ifstream & f, Top & mejores);
bool BusquedaSecOrd(const Top v, int buscado, int & pos, int tam);
bool InsercionOrd(Top & v, int elemento, int pos, int & tam, string nick);;
void MostrarVector(const VLosMejores v, int tam);
//Funciones de Presentacion del programa
void Presentacion(void);
void MenuInicial (void);
//Funciones de Partida Nueva
void NuevaPartidaUnJugador();
bool NuevaPartidaUnJugadorCaso1(YaPreguntadas, int, Categorias &);
bool NuevaPartidaUnJugadorCaso2(YaPreguntadas, int, Categorias &, int &);
void NuevaPartidaDosJugadores();
bool NuevaPartidaDosJugadoresCaso2(YaPreguntadas, int, Categorias &, int &);
bool NuevaPartidaDosJugadoresCaso1(YaPreguntadas, int, Categorias &);
//Funciones de Reanudar Partida
bool ReanudarPartida(void);
bool LeerNombrePartida(int, string &);
bool LeerPartidaGuardadaUnJugador (string);
bool LeerPartidaGuardadaDosJugadores (string);
void PartidaReanudadaUnJugador(DatosBinarios, string, YaPreguntadas);
void PartidaReanudadaDosJugadores(VDatosBinarios, string, string, YaPreguntadas);
//Funciones de Guardar Partida
bool GuardarPartida (int, int, Categorias, int, string, YaPreguntadas);
bool GuardarPartidaDosJugadores (int, int, int, Categorias, Categorias, int, string, string, YaPreguntadas);
bool EscribirNombrePartida (string, int);
//Funciones de Anadir Preguntas
void AmpliarNumeroTarjetas (void);
bool EstaPreguntaEnFichero (const string enunciado,unsigned short categoria, bool & error_fichero_enunciados_iguales);
string TodoMayuscula(string frase);
bool LeerPreguntaFichero (ifstream & f, Pregunta & pr_temporal);
Pregunta LeerPregunta (void);
bool AnadirPreguntaAFichero (Pregunta, unsigned short);
void GuardarPreguntaFichero (ofstream &, Pregunta);
void MostrarPregunta (Pregunta);

int main (void)
{
    Presentacion();
    
    MenuInicial();
    
    return 0;
}

/************************** Presentacion ******************************//**
*
* Informa al usuario de las reglas del juego, los modos de juego
* disponibles y el objetivo en cada uno de los modos de juego
*
*//***********************************************************************/
void Presentacion (void)
{
    cout << "Bienvenidos al Juego: PREGUNTADOS, hecho por Aldemaro Gonzalez\n";
    cout << "Solo se permitira dos modos de juego:\n";
    cout << "\t1 - Un jugador con una puntuacion final\n";
    cout << "\t2 - Dos jugadorres uno contra otro\n";
    cout << "Este es un juego de preguntas con seis categorias y un personaje relacionado ";
    cout << "con cada una de las categorías:\n";
    cout << "\t1. Geografía (Tito): es el planeta Tierra (de color azul).\n";
    cout << "\t2. Ciencia (Albert): es un tubo de ensayo (de color verde).\n";
    cout << "\t3. Historia (Hector): es un guerrero (de color amarillo).\n";
    cout << "\t4. Deportes (Bonzo): es una pelota de Futbol Americano (de color naranja).\n";
    cout << "\t5. Arte (Tina): es un pincel (de color rojo).\n";
    cout << "\t6. Entretenimiento (Pop): es una bolsa de palomitas de maíz de color rosa.\n";
    cout << "El objetivo del juego es obtener cada uno de los personajes ";
    cout << "contestando preguntas relacionadas con cada uno de los temas.\n";
    cout << "\tSi se juega solo, la meta del juego es completar el objetivo ";
    cout << "con el menor número de preguntas.\n";
    cout << "\tSi se juega contra otro jugador, la meta del juego es completar ";
    cout << "el objetivo antes que el otro jugador.\n";
    cout << "RECUERDA SIEMPRE QUE LAS OPCIONES, CATEGORIAS Y RESPUESTAS SOLO DEBES ESCRIBIR EL NUMERO CORRESPONDIENTE\n";
    
    return;
}

/*************** MenuInicial **************//**
*
* Muestras los modos de juego del programa
*
*//*******************************************/
void MenuInicial (void)
{
    int opcion, opcion2, repetir, reanudar;
    
    do
    {
        cout << "\nMenu\n";
        cout << "Opcion 1: Partida Nueva\n";
        cout << "Opcion 2: Reanudar Partida\n";
        cout << "Opcion 3: Ampliar el numero de tarjetas de juego disponible\n";
        cout << "Opcion 4: Salir\n";
        cout << "Opcion: ";
        cin >> opcion;
        
        switch (opcion)
        {
            case 1:
                cout << endl;
                cout << "PARTIDA NUEVA: \n";
                cout << "Opcion 1: Un Jugador\n";
                cout << "Opcion 2: Dos Jugadores\n";
                cout << "Opcion 3: Regresar a Menu\n";
                cout << "Opcion: ";
                cin >> opcion2;
                switch (opcion2)
                {
                    case 1:
                        NuevaPartidaUnJugador();
                        break;
                    case 2:
                        NuevaPartidaDosJugadores();
                        break;
                    case 3:
                    default:
                        cout << "\nLo llevaremos al menu...\n";
                        opcion = IR_MENU;
                        break;
                }
                break;
            case 2:
                cout << endl;
                reanudar = ReanudarPartida ();
                if (reanudar == false)
                {
                    opcion = IR_MENU;
                }
                break;
            case 3:
                cout << endl;
                AmpliarNumeroTarjetas();
                cout << "\nIntroduce el numero 1 para salir al menu o introduce el numero 2 ";
                cout << "para cerrar el juego: ";
                cin >> repetir;
                switch (repetir)
                {
                    case 1:
                        opcion = IR_MENU;
                        break;
                    case 2:
                        cout << endl;
                        break;
                    default:
                        cout << "\nOpcion no es valida, lo llevaremos al menu...\n";
                        opcion = IR_MENU;
                        break;
                }
                break;
            case 4:
                break;
            default:
                cout << "\nLa opcion no es valida, intente nuevamente.\n";
                opcion = IR_MENU;
                break;
        }
        
    }
    while (opcion == IR_MENU);
    
    return;
}

/************************** NuevaPartidaUnJugador ***************************//**
*
* El jugador a elegido iniciar una partida nueva de un solo jugador
*
*//*****************************************************************************/
void NuevaPartidaUnJugador()
{
    Categorias categorias_ganadas;
    YaPreguntadas preguntas_preguntadas;
    string nickname;
    int puntaje = PUNTAJE_INICIAL, opcion = 1, dado, cant_jugadores = 1;
    bool respuesta, seguir_jugando = true, opcion_invalida, partida_ganada, partida_guardada_correctamente, hall_fame;
    int num_preguntas_realizadas = 0;
    
    cout << "\nIntroduce NickName(una sola palabra): ";
    cin >> nickname;
    cout << "Puntaje Inicial: " << puntaje << endl << endl;
    
    do
    {
        if (puntaje >= 5 && opcion != 0)
        {
            respuesta = NuevaPartidaUnJugadorCaso1(preguntas_preguntadas, num_preguntas_realizadas, categorias_ganadas);
            if (respuesta)
            {
                puntaje -= 5;
            }
            else
                puntaje -= 10;
            num_preguntas_realizadas++;
        }
        else if (puntaje <= 5 || opcion == 0)
        {
            respuesta = NuevaPartidaUnJugadorCaso2(preguntas_preguntadas, num_preguntas_realizadas, categorias_ganadas, dado);
            if (respuesta == true && dado != 7)
            {
                puntaje += 1;
            }
            else if (respuesta == false && dado == 7)
            {
                puntaje -= 5;
            }
            num_preguntas_realizadas++;
        }
        
        partida_ganada = JuegoGanado(categorias_ganadas);
        
        if (partida_ganada == false)
        {
            cout << endl << "Puntaje Actual: " << puntaje;
            if (puntaje >= 5)
            {
                cout << endl << "Opcion 0: Tirar Dado";
            }
            cout << endl << "Opcion 1: Seguir Jugando";
            cout << endl << "Opcion 2: Abandonar partida sin guardar";
            cout << endl << "Opcion 3: Guardar partida";
            cout << endl << "Opcion: ";
            cin >> opcion;
            
            opcion_invalida = false;
            while (opcion_invalida == false)
            {
                switch (opcion)
                {
                    case 0:
                        seguir_jugando = true;
                        opcion_invalida = true;
                        break;
                    case 1:
                        seguir_jugando = true;
                        opcion_invalida = true;
                        break;
                    case 2:
                        cout << "\nJuego terminado\n\n";
                        seguir_jugando = false;
                        opcion_invalida = true;
                        break;
                    case 3:
                        partida_guardada_correctamente = GuardarPartida (cant_jugadores, puntaje, categorias_ganadas, num_preguntas_realizadas, nickname, preguntas_preguntadas);
                        if (partida_guardada_correctamente == true)
                        {
                            cout << "\nLa partida ha sido guardada correctamente\n\n";
                            opcion_invalida = true;
                            seguir_jugando = false;
                        }
                        else
                        {
                            cout << "\nLa partida no ha sido guardada. Dame otra vez la opcion: ";
                            cin >> opcion;
                            opcion_invalida = false;
                        }
                        break;
                    default:
                        cout << "\nOpcion Invalida. Dame otra vez la opcion (OPCIONES DEL 1 AL 3): ";
                        cin >> opcion;
                        opcion_invalida = false;
                        break;
                }
            }
        }
    }
    while (seguir_jugando == true && partida_ganada == false);
    
    if (partida_ganada == true)
    {
        cout << "\nFelicidades has ganado el juego";
        cout << "\nPuntaje Final: " << puntaje;
        cout << "\nNumeros de Preguntas Realizadas: " << num_preguntas_realizadas;
        hall_fame = HallOfFame(nickname, puntaje);
        if (hall_fame == false)
        {
            cout << "\nNo se pudo cargar el Hall Of Fame...\n\n";
        }
    }
    
    return;
}

/********************************* NuevaPartidaUnJugadorCaso1 ***********************************//**
*
* El jugador tiene 5 o mas puntos
*
* @param [in] preguntas_preguntadas Vector con las preguntas ya preguntadas
* @param [in] num_preguntas_realizadas Cantidad de preguntas que lleva respondidas el usuario
* @param [out] categorias_ganadas Categorias ganadas por el jugador
*
* @retval true El jugador respondio correctamente
* @retval false El jugador respondio incorrectamente
*
*//***********************************************************************************************/
bool NuevaPartidaUnJugadorCaso1(YaPreguntadas preguntas_preguntadas, int num_preguntas_realizadas, Categorias & categorias_ganadas)
{
    unsigned short categoria;
    string cat;
    Pregunta pr_temporal;
    ifstream f;
    bool respuesta = false, pregunta_realizada = false, repetida = false;
    int i;
    
    cout << "Introduce el numero de categoria (1 - 6): ";
    cin >> categoria;
    
    cat = to_string(categoria) + ".dat";
    
    f.open(cat);
    if(!f)
    {
        cout << "\nError Abriendo el Fichero en Funcion \"NuevaPartidaUnJugadorCaso1\"\n";
    }
    else
    {
        // Primero leemos en Pr_Temporal la pregunta del fichero
        while (LeerPreguntaFichero(f, pr_temporal) && pregunta_realizada == false)
        {
            /* Cuando tenemos leido una de la pregunta del fichero,
             * la comprobamos con el vector de Preguntas que ya fueron preguntadas
             * para ver si ya estaen dicho vector
             */
            i = 0;
            repetida = false;
            while (i < num_preguntas_realizadas && repetida == false)
            {
                if (pr_temporal.enunciado == preguntas_preguntadas[i].enunciado)
                {
                    repetida = true;
                }
                else
                    repetida = false;
                i++;
            }
            /*
             * Si no esta repetida la insertaremos en el vector
             */
            if (repetida == false)
            {
                //Primero Insertamos en el vector la pregunta
                preguntas_preguntadas[num_preguntas_realizadas].enunciado = pr_temporal.enunciado;
                preguntas_preguntadas[num_preguntas_realizadas].verdadera = pr_temporal.verdadera;
                preguntas_preguntadas[num_preguntas_realizadas].falsa1 = pr_temporal.falsa1;
                preguntas_preguntadas[num_preguntas_realizadas].falsa2 = pr_temporal.falsa2;
                preguntas_preguntadas[num_preguntas_realizadas].falsa3 = pr_temporal.falsa3;
                
                //Ahora Preguntaremos y verificaremos la respuesta
                respuesta = HacerPregunta(pr_temporal);
                
                if (respuesta == true)
                {
                    cout << "\nRespuesta Correcta. ";
                    pregunta_realizada = true;
                    switch (categoria)
                    {
                        case 1:
                            cout << "Haz ganado al personaje Tito.\n";
                            categorias_ganadas.tito = true;
                            break;
                        case 2:
                            cout << "Haz ganado al personaje Albert.\n";
                            categorias_ganadas.albert = true;
                            break;
                        case 3:
                            cout << "Haz ganado al personaje Hector.\n";
                            categorias_ganadas.hector = true;
                            break;
                        case 4:
                            cout << "Haz ganado al perosnaje Bonzo.\n";
                            categorias_ganadas.bonzo = true;
                            break;
                        case 5:
                            cout << "Haz ganado al personaje Tina.\n";
                            categorias_ganadas.tina = true;
                            break;
                        case 6:
                            cout << "Haz ganado al personaje Pop.\n";
                            categorias_ganadas.pop = true;
                            break;
                    }//SWITCH
                }//IF DE HACER PREGUNTA
                else
                {
                    pregunta_realizada = true;
                    cout << "\nRespuesta Incorrecta.\n";
                }//ELSE DE HACER PREGUNTA
            }//IF DE REPETIDA = FALSE
        }//WHILE DE LEER FICHERO
        f.close();
    }//ELSE DE LECTURA
    
    return respuesta;
}

/*********************************** NuevaPartidaUnJugadorCaso2 ***********************************//**
*
* El jugador tiene 4 o menos puntos
*
* @param [out] preguntas_preguntadas Vector con las preguntas ya preguntadas
* @param [in] num_preguntas_realizadas Cantidad de preguntas que lleva respondidas el usuario
* @param [out] categorias_ganadas Categorias ganadas por el jugador
* @param [in] dado Dado que se genera con numeros aleatorios
*
* @retval true El jugador respondio correctamente
* @retval false El jugador respondio incorrectamente
*
*//***********************************************************************************************/
bool NuevaPartidaUnJugadorCaso2(YaPreguntadas preguntas_preguntadas, int num_preguntas_realizadas, Categorias & categorias_ganadas, int & dado)
{
    string cat;
    Pregunta pr_temporal;
    ifstream f;
    bool respuesta = false, pregunta_realizada = false, repetida = false;
    int i;
    unsigned int s;
    long n;
    
    n = time(NULL);
    s = int (n);
    
    srand(s);
    dado = 1 + rand() % (8 - 1);

    cout << "\nVamos a tirar el dado";
    cout << "\nValor obtenido: " << dado << endl;
    
    if (dado == 7)
    {
       respuesta = NuevaPartidaUnJugadorCaso1(preguntas_preguntadas, num_preguntas_realizadas, categorias_ganadas);
    }
    else
    {
        cat = to_string(dado) + ".dat";
        
        f.open(cat);
        if(!f)
        {
            cout << "\nError Abriendo el Fichero en Funcion \"NuevaPartidaUnJugadorCaso-->2\"\n";
        }
        else
        {
            // Primero leemos en Pr_Temporal la pregunta del fichero
            while (LeerPreguntaFichero(f, pr_temporal) && pregunta_realizada == false)
            {
                /* Cuando tenemos leido una de la pregunta del fichero,
                 * la comprobamos con el vector de Preguntas que ya fueron preguntadas
                 * para ver si ya estaen dicho vector
                 */
                i = 0;
                repetida = false;
                while (i < num_preguntas_realizadas && repetida == false)
                {
                    if (pr_temporal.enunciado == preguntas_preguntadas[i].enunciado)
                    {
                        repetida = true;
                    }
                    else
                        repetida = false;
                    i++;
                }
                /*
                 * Si no esta repetida la insertaremos en el vector
                 */
                if (repetida == false)
                {
                    //Primero Insertamos en el vector la pregunta
                    preguntas_preguntadas[num_preguntas_realizadas].enunciado = pr_temporal.enunciado;
                    preguntas_preguntadas[num_preguntas_realizadas].verdadera = pr_temporal.verdadera;
                    preguntas_preguntadas[num_preguntas_realizadas].falsa1 = pr_temporal.falsa1;
                    preguntas_preguntadas[num_preguntas_realizadas].falsa2 = pr_temporal.falsa2;
                    preguntas_preguntadas[num_preguntas_realizadas].falsa3 = pr_temporal.falsa3;
                    
                    //Ahora Preguntaremos y verificaremos la respuesta
                    respuesta = HacerPregunta(pr_temporal);
                    
                    if (respuesta == true)
                    {
                        cout << "\nRespuesta Correcta. ";
                        pregunta_realizada = true;
                        switch (dado)
                        {
                            case 1:
                                cout << "Haz ganado al personaje Tito.\n";
                                categorias_ganadas.tito = true;
                                break;
                            case 2:
                                cout << "Haz ganado al personaje Albert.\n";
                                categorias_ganadas.albert = true;
                                break;
                            case 3:
                                cout << "Haz ganado al personaje Hector.\n";
                                categorias_ganadas.hector = true;
                                break;
                            case 4:
                                cout << "Haz ganado al perosnaje Bonzo.\n";
                                categorias_ganadas.bonzo = true;
                                break;
                            case 5:
                                cout << "Haz ganado al personaje Tina.\n";
                                categorias_ganadas.tina = true;
                                break;
                            case 6:
                                cout << "Haz ganado al personaje Pop.\n";
                                categorias_ganadas.pop = true;
                                break;
                        }//SWITCH
                    }//IF DE HACER PREGUNTA
                    else
                    {
                        pregunta_realizada = true;
                        cout << "\nRespuesta Incorrecta.\n";
                    }//ELSE DE HACER PREGUNTA
                }//IF DE REPETIDA = FALSE
            }//WHILE DE LEER FICHERO
            f.close();
        }//ELSE DE LECTURA
    }
    
    return respuesta;
}

/************************* NuevaPartidaDosJugadores ***********************//**
*
* El jugador a elegido iniciar una partida nueva de un dos jugadores
*
*//************************************************************************/
void NuevaPartidaDosJugadores()
{
    Categorias categorias_ganadas_jugador1, categorias_ganadas_jugador2;
    YaPreguntadas preguntas_preguntadas;
    string jugador1, jugador2;
    int puntaje_jugador1 = PUNTAJE_INICIAL, puntaje_jugador2 = PUNTAJE_INICIAL, opcion = 1, dado;
    bool respuesta = false, seguir_jugando = true, opcion_invalida, partida_ganada_jugador1, partida_ganada_jugador2, turno = true;
    bool partida_guardada_correctamente = true;
    int num_preguntas_realizadas = 0;
    
    cout << "\nIntroduce NickName(una sola palabra) de: ";
    cout << "\nJugador 1: ";
    cin >> jugador1;
    cout << "Jugador 2: ";
    cin >> jugador2;
    cout << jugador1 << ", Puntaje Inicial: " << puntaje_jugador1 << "\t-----\t" << jugador2;
    cout << ", Puntaje Inicial: " << puntaje_jugador2 << endl;
    
    do
    {
        if (puntaje_jugador1 >= 5 && opcion != 0 && turno == true)
        {
            cout << "\nTurno de: " << jugador1 << endl << endl;
            
            respuesta = NuevaPartidaDosJugadoresCaso1(preguntas_preguntadas, num_preguntas_realizadas, categorias_ganadas_jugador1);
            
            if (respuesta)
            {
                puntaje_jugador1 -= 5;
                turno = true;
            }
            else
            {
                puntaje_jugador1 -= 10;
                turno = false;
            }
            num_preguntas_realizadas++;
        }
        else if ((puntaje_jugador1 <= 5 || opcion == 0) && turno == true )
        {
            cout << "\nTurno de: " << jugador1 << endl << endl;
            
            respuesta = NuevaPartidaDosJugadoresCaso2(preguntas_preguntadas, num_preguntas_realizadas, categorias_ganadas_jugador1, dado);
            
            if (respuesta == true && dado != 7)
            {
                puntaje_jugador1 += 1;
                turno = true;
            }
            else if (respuesta == false && dado != 7)
            {
                turno = false;
            }
            else if (respuesta == true && dado == 7)
            {
                turno = true;
            }
            else if (respuesta == false && dado == 7)
            {
                puntaje_jugador1 -= 5;
                turno = false;
            }
            num_preguntas_realizadas++;
        }
        else if (puntaje_jugador2 >= 5 && opcion != 0 && turno == false)
        {
            cout << "\nTurno de: " << jugador2 << endl << endl;
            
            respuesta = NuevaPartidaDosJugadoresCaso1(preguntas_preguntadas, num_preguntas_realizadas, categorias_ganadas_jugador2);
            
            if (respuesta)
            {
                puntaje_jugador2 -= 5;
                turno = false;
            }
            else
            {
                puntaje_jugador2 -= 10;
                turno = true;
            }
            num_preguntas_realizadas++;
        }
        else if ((puntaje_jugador2 <= 5 || opcion == 0) && turno == false )
        {
            cout << "\nTurno de: " << jugador2 << endl << endl;
            
            respuesta = NuevaPartidaDosJugadoresCaso2(preguntas_preguntadas, num_preguntas_realizadas, categorias_ganadas_jugador2, dado);
            
            if (respuesta == true && dado != 7)
            {
                puntaje_jugador2 += 1;
                turno = false;
            }
            else if (respuesta == false && dado != 7)
            {
                turno = true;
            }
            else if (respuesta == true && dado == 7)
            {
                turno = false;
            }
            else if (respuesta == false && dado == 7)
            {
                puntaje_jugador2 -= 5;
                turno = true;
            }
            
            num_preguntas_realizadas++;
        }
        
        partida_ganada_jugador1 = JuegoGanado(categorias_ganadas_jugador1);
        partida_ganada_jugador2 = JuegoGanado(categorias_ganadas_jugador2);
        
        if (partida_ganada_jugador1 == false && partida_ganada_jugador2 == false && respuesta == true)
        {
            cout << endl << "Puntaje Actual: " << jugador1 << " = " << puntaje_jugador1;
            cout << "\t" << jugador2 << " = " << puntaje_jugador2;
            if ((turno == true && puntaje_jugador1 >= 5) || (turno == false && puntaje_jugador2 >= 5))
            {
                cout << endl << "Opcion 0: Tirar Dado";
            }
            cout << endl << "Opcion 1: Seguir Jugando";
            cout << endl << "Opcion 2: Abandonar partida sin guardar";
            cout << endl << "Opcion 3: Guardar partida";
            cout << endl << "Opcion: ";
            cin >> opcion;
            
            opcion_invalida = false;
            while (opcion_invalida == false)
            {
                switch (opcion)
                {
                    case 0:
                        seguir_jugando = true;
                        opcion_invalida = true;
                        break;
                    case 1:
                        seguir_jugando = true;
                        opcion_invalida = true;
                        break;
                    case 2:
                        cout << "\nJuego terminado\n\n";
                        seguir_jugando = false;
                        opcion_invalida = true;
                        break;
                    case 3:
                        partida_guardada_correctamente = GuardarPartidaDosJugadores (2, puntaje_jugador1, puntaje_jugador2, categorias_ganadas_jugador1, categorias_ganadas_jugador2, num_preguntas_realizadas, jugador1, jugador2, preguntas_preguntadas);
                        if (partida_guardada_correctamente == true)
                        {
                            cout << "\nLa partida ha sido guardada correctamente\n\n";
                            opcion_invalida = true;
                            seguir_jugando = false;
                        }
                        else
                        {
                            cout << "\nLa partida no ha sido guardada. Dame otra vez la opcion: ";
                            cin >> opcion;
                            opcion_invalida = false;
                        }
                        break;
                    default:
                        cout << "\nOpcion Invalida. Dame otra vez la opcion (OPCIONES DEL 1 AL 3): ";
                        cin >> opcion;
                        opcion_invalida = false;
                        break;
                }
            }
        }
        else if (partida_ganada_jugador1 == false && partida_ganada_jugador2 == false && respuesta == false)
        {
            cout << endl << "Puntaje Actual: " << jugador1 << " = " << puntaje_jugador1;
            cout << "\t" << jugador2 << " = " << puntaje_jugador2;
            cout << endl << "Opcion 1: Seguir Jugando";
            cout << endl << "Opcion 2: Abandonar partida sin guardar";
            cout << endl << "Opcion 3: Guardar partida";
            cout << endl << "Opcion: ";
            cin >> opcion;
            
            opcion_invalida = false;
            while (opcion_invalida == false)
            {
                switch (opcion)
                {
                    case 1:
                        seguir_jugando = true;
                        opcion_invalida = true;
                        break;
                    case 2:
                        cout << "\nJuego terminado\n\n";
                        seguir_jugando = false;
                        opcion_invalida = true;
                        break;
                    case 3:
                        partida_guardada_correctamente = GuardarPartidaDosJugadores (2, puntaje_jugador1, puntaje_jugador2, categorias_ganadas_jugador1, categorias_ganadas_jugador2, num_preguntas_realizadas, jugador1, jugador2, preguntas_preguntadas);
                        if (partida_guardada_correctamente == true)
                        {
                            cout << "\nLa partida ha sido guardada correctamente\n\n";
                            opcion_invalida = true;
                            seguir_jugando = false;
                        }
                        else
                        {
                            cout << "\nLa partida no ha sido guardada. Dame otra vez la opcion: ";
                            cin >> opcion;
                            opcion_invalida = false;
                        }
                        break;
                    default:
                        cout << "\nOpcion Invalida. Dame otra vez la opcion (OPCIONES DEL 1 AL 3): ";
                        cin >> opcion;
                        opcion_invalida = false;
                        break;
                }
            }
        }
    }
    while (seguir_jugando == true && partida_ganada_jugador1 == false && partida_ganada_jugador2 == false);
    
    if (partida_ganada_jugador1 == true)
    {
        cout << "\nFelicidades " << jugador1 << " has ganado el juego...\n\n";
    }
    else if (partida_ganada_jugador2 == true)
    {
        cout << "\nFelicidades " << jugador2 << " has ganado el juego...\n\n";
    }
    
    return;
}

/********************************* NuevaPartidaDosJugadoresCaso1 ***********************************//**
*
* El jugador tiene 5 o mas puntos
*
* @param [in] preguntas_preguntadas Vector con las preguntas ya preguntadas
* @param [in] num_preguntas_realizadas Cantidad de preguntas que lleva respondidas el usuario
* @param [out] categorias_ganadas Categorias ganadas por el jugador
*
* @retval true El jugador respondio correctamente
* @retval false El jugador respondio incorrectamente
*
*//*******************************************************************************************************/
bool NuevaPartidaDosJugadoresCaso1(YaPreguntadas preguntas_preguntadas, int num_preguntas_realizadas, Categorias & categorias_ganadas)
{
    unsigned short categoria;
    string cat;
    Pregunta pr_temporal;
    ifstream f;
    bool respuesta = false, pregunta_realizada = false, repetida = false;
    int i;
    
    cout << "Introduce el numero de categoria: ";
    cin >> categoria;
    
    cat = to_string(categoria) + ".dat";
    
    f.open(cat);
    if(!f)
    {
        cout << "\nError Abriendo el Fichero en Funcion \"NuevaPartidaUnJugadorCaso1\"\n";
    }
    else
    {
        // Primero leemos en Pr_Temporal la pregunta del fichero
        while (LeerPreguntaFichero(f, pr_temporal) && pregunta_realizada == false)
        {
            /* Cuando tenemos leido una de la pregunta del fichero,
             * la comprobamos con el vector de Preguntas que ya fueron preguntadas
             * para ver si ya estaen dicho vector
             */
            i = 0;
            repetida = false;
            while (i < num_preguntas_realizadas && repetida == false)
            {
                if (pr_temporal.enunciado == preguntas_preguntadas[i].enunciado)
                {
                    repetida = true;
                }
                else
                    repetida = false;
                i++;
            }
            /*
             * Si no esta repetida la insertaremos en el vector
             */
            if (repetida == false)
            {
                //Primero Insertamos en el vector la pregunta
                preguntas_preguntadas[num_preguntas_realizadas].enunciado = pr_temporal.enunciado;
                preguntas_preguntadas[num_preguntas_realizadas].verdadera = pr_temporal.verdadera;
                preguntas_preguntadas[num_preguntas_realizadas].falsa1 = pr_temporal.falsa1;
                preguntas_preguntadas[num_preguntas_realizadas].falsa2 = pr_temporal.falsa2;
                preguntas_preguntadas[num_preguntas_realizadas].falsa3 = pr_temporal.falsa3;
                
                //Ahora Preguntaremos y verificaremos la respuesta
                respuesta = HacerPregunta(pr_temporal);
                
                if (respuesta == true)
                {
                    cout << "\nRespuesta Correcta. ";
                    pregunta_realizada = true;
                    switch (categoria)
                    {
                        case 1:
                            cout << "Haz ganado al personaje Tito.\n";
                            categorias_ganadas.tito = true;
                            break;
                        case 2:
                            cout << "Haz ganado al personaje Albert.\n";
                            categorias_ganadas.albert = true;
                            break;
                        case 3:
                            cout << "Haz ganado al personaje Hector.\n";
                            categorias_ganadas.hector = true;
                            break;
                        case 4:
                            cout << "Haz ganado al perosnaje Bonzo.\n";
                            categorias_ganadas.bonzo = true;
                            break;
                        case 5:
                            cout << "Haz ganado al personaje Tina.\n";
                            categorias_ganadas.tina = true;
                            break;
                        case 6:
                            cout << "Haz ganado al personaje Pop.\n";
                            categorias_ganadas.pop = true;
                            break;
                    }//SWITCH
                }//IF DE HACER PREGUNTA
                else
                {
                    pregunta_realizada = true;
                    cout << "\nRespuesta Incorrecta.\n";
                }//ELSE DE HACER PREGUNTA
            }//IF DE REPETIDA = FALSE
        }//WHILE DE LEER FICHERO
        f.close();
    }//ELSE DE LECTURA
    
    return respuesta;
}

/*********************************** NuevaPartidaDosJugadoresCaso2 ***********************************//**
*
* El jugador tiene 4 o menos puntos
*
* @param [out] preguntas_preguntadas Vector con las preguntas ya preguntadas
* @param [in] num_preguntas_realizadas Cantidad de preguntas que lleva respondidas el usuario
* @param [out] categorias_ganadas Categorias ganadas por el jugador
* @param [in] dado Dado que se genera con numeros aleatorios
*
* @retval true El jugador respondio correctamente
* @retval false El jugador respondio incorrectamente
*
*//***********************************************************************************************/
bool NuevaPartidaDosJugadoresCaso2(YaPreguntadas preguntas_preguntadas, int num_preguntas_realizadas, Categorias & categorias_ganadas, int & dado)
{
    int i;
    string cat;
    Pregunta pr_temporal;
    ifstream f;
    bool respuesta = false, pregunta_realizada = false, repetida = false;
    unsigned int s;
    long n;
    
    n = time(NULL);
    s = int (n);
    
    srand(s);
    dado = 1 + rand() % (8 - 1);
    
    cout << "\nVamos a tirar el dado";
    cout << "\nValor obtenido: " << dado << endl;
    
    if (dado == 7)
    {
        respuesta = NuevaPartidaUnJugadorCaso1(preguntas_preguntadas, num_preguntas_realizadas, categorias_ganadas);
    }
    else
    {
        cat = to_string(dado) + ".dat";
        
        f.open(cat);
        if(!f)
        {
            cout << "\nError Abriendo el Fichero en Funcion \"NuevaPartidaUnJugadorCaso-->2\"\n";
        }
        else
        {
            // Primero leemos en Pr_Temporal la pregunta del fichero
            while (LeerPreguntaFichero(f, pr_temporal) && pregunta_realizada == false)
            {
                /* Cuando tenemos leido una de la pregunta del fichero,
                 * la comprobamos con el vector de Preguntas que ya fueron preguntadas
                 * para ver si ya estaen dicho vector
                 */
                i = 0;
                repetida = false;
                while (i < num_preguntas_realizadas && repetida == false)
                {
                    if (pr_temporal.enunciado == preguntas_preguntadas[i].enunciado)
                    {
                        repetida = true;
                    }
                    else
                        repetida = false;
                    i++;
                }
                /*
                 * Si no esta repetida la insertaremos en el vector
                 */
                if (repetida == false)
                {
                    //Primero Insertamos en el vector la pregunta
                    preguntas_preguntadas[num_preguntas_realizadas].enunciado = pr_temporal.enunciado;
                    preguntas_preguntadas[num_preguntas_realizadas].verdadera = pr_temporal.verdadera;
                    preguntas_preguntadas[num_preguntas_realizadas].falsa1 = pr_temporal.falsa1;
                    preguntas_preguntadas[num_preguntas_realizadas].falsa2 = pr_temporal.falsa2;
                    preguntas_preguntadas[num_preguntas_realizadas].falsa3 = pr_temporal.falsa3;
                    
                    //Ahora Preguntaremos y verificaremos la respuesta
                    respuesta = HacerPregunta(pr_temporal);
                    
                    if (respuesta == true)
                    {
                        cout << "\nRespuesta Correcta. ";
                        pregunta_realizada = true;
                        switch (dado)
                        {
                            case 1:
                                cout << "Haz ganado al personaje Tito.\n";
                                categorias_ganadas.tito = true;
                                break;
                            case 2:
                                cout << "Haz ganado al personaje Albert.\n";
                                categorias_ganadas.albert = true;
                                break;
                            case 3:
                                cout << "Haz ganado al personaje Hector.\n";
                                categorias_ganadas.hector = true;
                                break;
                            case 4:
                                cout << "Haz ganado al perosnaje Bonzo.\n";
                                categorias_ganadas.bonzo = true;
                                break;
                            case 5:
                                cout << "Haz ganado al personaje Tina.\n";
                                categorias_ganadas.tina = true;
                                break;
                            case 6:
                                cout << "Haz ganado al personaje Pop.\n";
                                categorias_ganadas.pop = true;
                                break;
                        }//SWITCH
                    }//IF DE HACER PREGUNTA
                    else
                    {
                        pregunta_realizada = true;
                        cout << "\nRespuesta Incorrecta.\n";
                    }//ELSE DE HACER PREGUNTA
                }//IF DE REPETIDA = FALSE
            }//WHILE DE LEER FICHERO
            f.close();
        }//ELSE DE LECTURA
    }
    
    return respuesta;
}

/*********************************** HacerPreguntas *****************************//**
*
* Le hace la pregunta al usuario
*
* @param [in] preguntar Pregunta que se le va a preguntar al usuario
*
* @retval true Si el usuario respondio correctamente
* @retval false Si el usuario no respondio correctamente
*
*//*****************************************************************************/
bool HacerPregunta (Pregunta preguntar)
{
    bool correcto = false, opcion_invalida = false;
    int respuesta, numero;
    unsigned int s;
    long n;
    
    n = time(NULL);
    s = int (n);
    
    srand(s);
    numero = 1 + rand() % (5 - 1);

    do
    {
        switch (numero)
        {
            case 1:
                cout << endl << preguntar.enunciado;
                cout << "\nOpcion 1: " << preguntar.verdadera;
                cout << "\nOpcion 2: " << preguntar.falsa1;
                cout << "\nOpcion 3: " << preguntar.falsa2;
                cout << "\nOpcion 4: " << preguntar.falsa3;
                cout << endl << "RESPUESTA: ";
                cin >> respuesta;
                switch (respuesta)
                {
                    case 1:
                        correcto = true;
                        opcion_invalida = false;
                        break;
                    case 2:
                    case 3:
                    case 4:
                        correcto = false;
                        opcion_invalida = false;
                        break;
                    default:
                        cout << "\nOpcion Invalida. Vuelve a intentar...";
                        opcion_invalida = true;
                        break;
                }
                break;
            case 2:
                cout << endl << endl << preguntar.enunciado;
                cout << "\nOpcion 1: " << preguntar.falsa1;
                cout << "\nOpcion 2: " << preguntar.verdadera;
                cout << "\nOpcion 3: " << preguntar.falsa2;
                cout << "\nOpcion 4: " << preguntar.falsa3;
                cout << endl << "RESPUESTA: ";
                cin >> respuesta;
                switch (respuesta)
                {
                    case 2:
                        correcto = true;
                        opcion_invalida = false;
                        break;
                    case 1:
                    case 3:
                    case 4:
                        correcto = false;
                        opcion_invalida = false;
                        break;
                    default:
                        cout << "\nOpcion Invalida. Vuelve a intentar...";
                        opcion_invalida = true;
                        break;
                }
                break;
            case 3:
                cout << endl << endl << preguntar.enunciado;
                cout << "\nOpcion 1: " << preguntar.falsa1;
                cout << "\nOpcion 2: " << preguntar.falsa2;
                cout << "\nOpcion 3: " << preguntar.verdadera;
                cout << "\nOpcion 4: " << preguntar.falsa3;
                cout << endl << "RESPUESTA: ";
                cin >> respuesta;
                switch (respuesta)
                {
                    case 3:
                        correcto = true;
                        opcion_invalida = false;
                        break;
                    case 2:
                    case 1:
                    case 4:
                        correcto = false;
                        opcion_invalida = false;
                        break;
                    default:
                        cout << "\nOpcion Invalida. Vuelve a intentar...";
                        opcion_invalida = true;
                        break;
                }
                break;
            case 4:
                cout << endl << endl << preguntar.enunciado;
                cout << "\nOpcion 1: " << preguntar.falsa1;
                cout << "\nOpcion 2: " << preguntar.falsa2;
                cout << "\nOpcion 3: " << preguntar.falsa3;
                cout << "\nOpcion 4: " << preguntar.verdadera;
                cout << endl << "RESPUESTA: ";
                cin >> respuesta;
                switch (respuesta)
                {
                    case 4:
                        correcto = true;
                        opcion_invalida = false;
                        break;
                    case 2:
                    case 3:
                    case 1:
                        correcto = false;
                        opcion_invalida = false;
                        break;
                    default:
                        cout << "\nOpcion Invalida. Vuelve a intentar...";
                        opcion_invalida = true;
                        break;
                }
                break;
        }
    }
    while (opcion_invalida == true);
    
    return correcto;
}

/************************************* JuegoGanado ***********************************//**
*
* Determina si un jugador a ganado la partida
*
* @param[in] categorias_ganadas Categorias ganadas por los jugadores
*
* @retval true  Si gano la partida
* @retval false Si no ha ganado la partida
*
*//*****************************************************************************************/
bool JuegoGanado(Categorias & categorias_ganadas)
{
    bool win;
    
    if (categorias_ganadas.albert   == true &&
        categorias_ganadas.bonzo    == true &&
        categorias_ganadas.hector   == true &&
        categorias_ganadas.pop      == true &&
        categorias_ganadas.tina     == true &&
        categorias_ganadas.tito     == true )
    {
        win = true;
    }
    else
        win = false;
    
    return win;
}

/************************************* HallOfFame ***********************************//**
*
* Muestra los 5 mejores jugadores en solitario
*
* @param [in] nombre    Nick del Jugador
* @param [in] puntaje   Puntaje del jugador
*
* @retval true  Abrio el fichero
* @retval false No abrio el fichero
*
*//*************************************************************************************/
bool HallOfFame (string nombre, int puntaje)
{
    ifstream fich;  //Fichero de lectura
    ofstream fich2; //Fichero de escritura
    bool abrio = false, encontrado = false, correcto, terminar = false;
    Top top_5;
    int pos, i;
    
    fich.open ( FICH_JUGADORES.c_str () );
    if (!fich)
    {
        fich2.open ( FICH_JUGADORES.c_str() );
        if (!fich2)
        {
            cout << "\nError abriendo abriendo Hall Of Fame...\n\n";
            abrio = false;
        }
        else
        {
            fich2 << "1" << endl;
            fich2 << nombre << " " << puntaje;
            fich2 << endl;
            cout << "\nHall of Fame: ";
            cout << "\nNumero 1: ";
            cout << nombre << " ---> " << puntaje << endl << endl;
            abrio = true;
        }
    }
    else
    {
        while (LeerFicheroHallOfFame(fich, top_5) && terminar == false)
        {
            encontrado = BusquedaSecOrd(top_5, puntaje, pos, top_5.cant_jugadores);
            correcto = InsercionOrd(top_5, puntaje, pos, top_5.cant_jugadores, nombre);

            if (correcto)
            {
                if (top_5.cant_jugadores > HALL_OF_FAME)
                {
                    top_5.cant_jugadores = HALL_OF_FAME;
                    MostrarVector(top_5.mejores, top_5.cant_jugadores);
                }
                else
                {
                    MostrarVector(top_5.mejores, top_5.cant_jugadores);
                }
                
                fich2.open ( FICH_JUGADORES.c_str() );
                if (!fich2)
                {
                    cout << "\nError abriendo abriendo Hall Of Fame...\n\n";
                    abrio = false;
                }
                else
                {
                    fich2 << top_5.cant_jugadores << endl;
                    for (i = 0; i < top_5.cant_jugadores; i++)
                    {
                        fich2 << top_5.mejores[i].nick << " " << top_5.mejores[i].puntuacion;
                        fich2 << endl;
                    }
                    terminar = true;
                    abrio = true;
                }
            }
        }
    }
    
    return abrio;
}

/******************************** BusquedaSecOrd *******************************//**
*
* Buscamos la posicion correcta donde se debe insertar un
* numero dentro de un vector
*
* @param[in] v          Vector en el que se tiene que introducir
* @param[in] buscado    Valor introducido por el usuario
* @param[in] tam        Tamano actual/real de vector
* @param[out] pos       Indexacion/Posicion donde se debe insertar un valor en el vector
*
* @retval true Si se encotro la posicion donde insertar el valor
* @retval false Si no se encotro la posicion donde insertar el valor
*
*//*********************************************************************************/
bool BusquedaSecOrd(const Top v, int buscado, int & pos, int tam)
{
    pos = 0;
    
    /* Permitimos que pos tome el valor de la primera posicion
     * libre
     */
    while((pos < tam) && (v.mejores[pos].puntuacion > buscado))
        pos++;
    
    return (v.mejores[pos].puntuacion == buscado && pos < tam);
}

/*************************** InsertarOrd ****************************//**
*
* Inserta numero enteros en un vector ordenadamente de menor a mayor
*
* @param[in]    v           Vector en el que se tiene que introducir
* @param[in]    elemento    Numero que introduciremos en el vector
* @param[in]    pos         Indexacion de un valor en el vector
* @param[out]   tam         Tamano actual/real de vector
* @param[in]    nick        Nick del jugador
*
* @retval true Si el vector no esta lleno
* @retval false Si el vector esta lleno
*
*//***********************************************************************/
bool InsercionOrd(Top & v, int elemento, int pos, int & tam, string nick)
{
    int i;
    bool insertado = false;
    
    if(tam < MAX)
    {
        for(i = tam; i > pos; i--)
        {
            v.mejores[i].nick       = v.mejores[i - 1].nick;
            v.mejores[i].puntuacion = v.mejores[i - 1].puntuacion;
        }
        v.mejores[pos].nick = nick;
        v.mejores[pos].puntuacion = elemento;
        tam ++;
        insertado = true;
    }
    
    return insertado;
}

/************************ LeerFicheroHallOfFame ****************************//**
*
* Muestra los 5 mejores jugadores en solitario
*
* @param [out] f     Descriptor del gichero
* @param [out] top   Registro donde almacena la informacion
*
* @retval true  Si se pudo leer el fichero
* @retval false No se pudo leer el fichero
*
*//**************************************************************************/
bool LeerFicheroHallOfFame (ifstream & f, Top & top)
{
    bool lectura_ok = false;
    int i;
    
    f >> top.cant_jugadores;
    f.ignore();
    
    for (i = 0; i < top.cant_jugadores; i++)
    {
        f >> top.mejores[i].nick;
        f >> top.mejores[i].puntuacion;
        lectura_ok = true;
    }

    return lectura_ok;
}

/************************ MostrarVector *********************//**
*
* Muestra el vector por pantalla
*
* @param[in] v Vector
* @param[in] tam Numero de Elementos
*
*//*************************************************************/
void MostrarVector(const VLosMejores v, int tam)
{
    int i;
    
    cout << "\n\n\tHall Of Fame\n\n";
    
    for(i = 0; i < tam; i++)
    {
        cout << "Numero " << i + 1 << endl;
        cout << v[i].nick << " ---> " << v[i].puntuacion << endl;
    }
    
    cout << endl;
    
    return;
}

/************************************* GuardarPartida ***********************************//**
*
* Guarda una partida
*
* @param [in] cant_jugadores            Cantidad de jugadores
* @param [in] puntaje                   Puntaje del jugador
* @param [in] categorias_ganadas        Categorias ganadas por el jugador
* @param [in] num_preguntas_realizadas  Cantidad de preguntas respondidas por el usuario
* @param [in] nick_name                 Nick del Jugador
* @param [in] preguntas_preguntadas     Preguntas ya preguntadas
*
* @retval true  Partida guardada correctamente
* @retval false Partida no guardada
*
*//*****************************************************************************************/
bool GuardarPartida (int cant_jugadores, int puntaje, Categorias categorias_ganadas, int num_preguntas_realizadas, string nick_name, YaPreguntadas preguntas_preguntadas)
{
    bool guardada, guarda_nombre;
    string nombre_partida, nombre_fichero;
    ofstream f;
    DatosBinarios datos_binarios;
    int i;

    cout << "\nDame el nombre de la partida: ";
    cin >> nombre_partida;
    
    nombre_fichero = nombre_partida + ".dat";

    f.open (nombre_fichero.c_str(), ios::binary);
    if (!f)
    {
        guardada = false;
    }
    else
    {
        /*
         * Primero introducimos todos los datos que pueden ser binarios es decir lo que no son strings en
         * un registro
         */
        datos_binarios.cant_jugadores             =   cant_jugadores;
        datos_binarios.puntaje                    =   puntaje;
        datos_binarios.categorias_ganadas.albert  =   categorias_ganadas.albert;
        datos_binarios.categorias_ganadas.bonzo   =   categorias_ganadas.bonzo;
        datos_binarios.categorias_ganadas.hector  =   categorias_ganadas.hector;
        datos_binarios.categorias_ganadas.pop     =   categorias_ganadas.pop;
        datos_binarios.categorias_ganadas.tina    =   categorias_ganadas.tina;
        datos_binarios.categorias_ganadas.tito    =   categorias_ganadas.tito;
        datos_binarios.num_preguntas_realizadas   =   num_preguntas_realizadas;
        f.write((char *) (& datos_binarios), sizeof(datos_binarios) );
        
        /*
         * Ahora escribimos los datos que son strings en el fichero
         */
        f << endl;
        f << nick_name;
        f << endl;
        for (i = 0; i < num_preguntas_realizadas; i++)
        {
            f << preguntas_preguntadas[i].enunciado;
            f << endl;
        }
        
        f.close();
        
        guardada = true;
    }
    
    if (guardada)
    {
        guarda_nombre = EscribirNombrePartida(nombre_partida, cant_jugadores);
        if (guarda_nombre == false)
        {
            cout << "\nError Guardando nombre de la partida\n\n";
        }
    }
    
    return guardada;
}

/************************************* GuardarPartidaDosJugadores ***********************************//**
*
* Guarda una partida de dos jugadores
*
* @param [in] cant_jugadores                    Cantidad de jugadores
* @param [in] puntaje_jugador1                  Puntaje del jugador 1
* @param [in] puntaje_jugador2                  Puntaje del jugador 2
* @param [in] categorias_ganadas_jugador1       Categorias ganadas por el jugador 1
* @param [in] categorias_ganadas_jugador2       Categorias ganadas por el jugador 2
* @param [in] num_preguntas_realizadas          Cantidad de preguntas respondidas por ambos usuarios
* @param [in] nick_jugador1                     Nick del Jugador 1
* @param [in] nick_jugador2                     Nick del Jugador 2
* @param [in] preguntas_preguntadas             Preguntas ya preguntadas
*
* @retval true  Partida guardada correctamente
* @retval false Partida no guardada
*
*//*********************************************************************************************************/
bool GuardarPartidaDosJugadores (int cant_jugadores, int puntaje_jugador1, int puntaje_jugador2, Categorias categorias_ganadas_jugador1, Categorias categorias_ganadas_jugador2, int num_preguntas_realizadas, string nick_jugador1, string nick_jugador2, YaPreguntadas preguntas_preguntadas)
{
    bool guardada, guarda_nombre;
    string nombre_partida, nombre_fichero;
    ofstream f;
    VDatosBinarios datos_binarios;
    int i;
    
    cout << "\nDame el nombre de la partida: ";
    cin >> nombre_partida;
    
    nombre_fichero = nombre_partida + "_2_jugadores.dat";
    
    f.open (nombre_fichero.c_str(), ios::binary);
    if (!f)
    {
        guardada = false;
    }
    else
    {
        /*
         * Primero introducimos todos los datos que pueden ser binarios es decir lo que no son strings en
         * un registro
         */
        datos_binarios[0].cant_jugadores                =   cant_jugadores;
        datos_binarios[0].puntaje                       =   puntaje_jugador1;
        datos_binarios[1].puntaje                       =   puntaje_jugador2;
        datos_binarios[0].categorias_ganadas.albert     =   categorias_ganadas_jugador1.albert;
        datos_binarios[1].categorias_ganadas.albert     =   categorias_ganadas_jugador2.albert;
        datos_binarios[0].categorias_ganadas.bonzo      =   categorias_ganadas_jugador1.bonzo;
        datos_binarios[1].categorias_ganadas.bonzo      =   categorias_ganadas_jugador2.bonzo;
        datos_binarios[0].categorias_ganadas.hector     =   categorias_ganadas_jugador1.hector;
        datos_binarios[1].categorias_ganadas.hector     =   categorias_ganadas_jugador2.hector;
        datos_binarios[0].categorias_ganadas.pop        =   categorias_ganadas_jugador1.pop;
        datos_binarios[1].categorias_ganadas.pop        =   categorias_ganadas_jugador2.pop;
        datos_binarios[0].categorias_ganadas.tina       =   categorias_ganadas_jugador1.tina;
        datos_binarios[1].categorias_ganadas.tina       =   categorias_ganadas_jugador2.tina;
        datos_binarios[0].categorias_ganadas.tito       =   categorias_ganadas_jugador1.tito;
        datos_binarios[1].categorias_ganadas.tito       =   categorias_ganadas_jugador2.tito;
        datos_binarios[0].num_preguntas_realizadas      =   num_preguntas_realizadas;
        f.write((char *) (& datos_binarios), sizeof(datos_binarios) );
        
        /*
         * Ahora escribimos los datos que son strings en el fichero
         */
        f << nick_jugador1;
        f << endl;
        f << nick_jugador2;
        f << endl;
        for (i = 0; i < num_preguntas_realizadas; i++)
        {
            f << preguntas_preguntadas[i].enunciado;
            f << endl;
        }

        guardada = true;
    }
    
    if (guardada)
    {
        guarda_nombre = EscribirNombrePartida(nombre_partida, cant_jugadores);
        if (guarda_nombre == false)
        {
            cout << "\nError Guardando nombre de la partida\n\n";
        }
    }
    
    return guardada;
}

/************************** EscribirNombrePartida ***************************//**
*
* Reanuda una partida guardada
*
* @param [in] nombre_partida    Nombre de la partida
* @param [in] cant_jugadores    Cantidad de jugadores
*
* @retval true  Se guardo el nombre del fichero
* @retval false No se pudo escribir el nombre del fichero
*
*//*****************************************************************************/
bool EscribirNombrePartida (string nombre_partida, int cant_jugadores)
{
    bool escrito;
    int cant_partidas_guardadas, i;
    ifstream leer_fichero;
    ofstream escribir_fichero;
    VNombres_Guardados nombres_guardados;
    
    if (cant_jugadores == 1)
    {
        leer_fichero.open(PARTIDASUNJUGADOR.c_str());
        if (!leer_fichero) //No lo abrio porque no existe
        {
            escribir_fichero.open(PARTIDASUNJUGADOR.c_str());
            if (!escribir_fichero)
            {
                cout << "\n\nProblema en Funcion ESCRIBIR NOMBRE FICHERO, leer fichero no existe \n\n";
                escrito = false;
            }
            else
            {
                escribir_fichero << 1 << endl;
                escribir_fichero << nombre_partida << endl;
                escrito = true;
            }
        }
        else  //Abrio el fichero
        {
            leer_fichero >> cant_partidas_guardadas;
            leer_fichero.ignore();
            for (i = 0; i < cant_partidas_guardadas; i++)
            {
                leer_fichero >> nombres_guardados[i];
            }
            
            cant_partidas_guardadas++;
            
            escribir_fichero.open(PARTIDASUNJUGADOR.c_str());
            if (!escribir_fichero)
            {
                cout << "\n\nProblema en Funcion ESCRIBIR NOMBRE FICHERO, leer fichero no existe \n\n";
                escrito = false;
            }
            else
            {
                escribir_fichero << cant_partidas_guardadas << endl;
                for (i = cant_partidas_guardadas - 1; i >= 0; i--)
                {
                    if ( i == 0)
                    {
                        nombres_guardados[i] = nombre_partida;
                    }
                    else
                    {
                        nombres_guardados[i] = nombres_guardados[i - 1];
                    }
                }
                for (i = 0; i < cant_partidas_guardadas; i++)
                {
                    escribir_fichero << nombres_guardados[i] << endl;
                }
                escrito = true;
            }
        }
    }
    else //Cantida de partidas guardadas = 2
    {
        leer_fichero.open(PARTIDADOSJUGADORES.c_str());
        if (!leer_fichero) //No lo abrio porque no existe
        {
            escribir_fichero.open(PARTIDADOSJUGADORES.c_str());
            if (!escribir_fichero)
            {
                cout << "\n\nProblema en Funcion ESCRIBIR NOMBRE FICHERO, leer fichero no existe \n\n";
                escrito = false;
            }
            else
            {
                escribir_fichero << 1 << endl;
                escribir_fichero << nombre_partida << endl;
                escrito = true;
            }
        }
        else  //Abrio el fichero
        {
            leer_fichero >> cant_partidas_guardadas;
            leer_fichero.ignore();
            for (i = 0; i < cant_partidas_guardadas; i++)
            {
                leer_fichero >> nombres_guardados[i];
            }
            
            cant_partidas_guardadas++;
            
            escribir_fichero.open(PARTIDADOSJUGADORES.c_str());
            if (!escribir_fichero)
            {
                cout << "\n\nProblema en Funcion ESCRIBIR NOMBRE FICHERO, leer fichero no existe \n\n";
                escrito = false;
            }
            else
            {
                escribir_fichero << cant_partidas_guardadas << endl;
                for (i = cant_partidas_guardadas - 1; i >= 0; i--)
                {
                    if ( i == 0)
                    {
                        nombres_guardados[i] = nombre_partida;
                    }
                    else
                    {
                        nombres_guardados[i] = nombres_guardados[i - 1];
                    }
                }
                for (i = 0; i < cant_partidas_guardadas; i++)
                {
                    escribir_fichero << nombres_guardados[i] << endl;
                }
                escrito = true;
            }
        }
    }
    
    return escrito;
}

/************************** ReanudarPartida ***************************//**
*
* Reanuda una partida guardada
*
* @retval true  Partida reanudada
* @retval false Partida no reanudada
*
*//*************************************************************************/
bool ReanudarPartida(void)
{
    bool partida_reanudada = false, opcion_invalida, existe;
    int opcion;
    string nombre_partida;
    
    cout << "\nOpcion 1: Partida un Jugador ";
    cout << "\nOpcion 2: Partida de dos Jugadores ";
    cout << "\nOpcion: ";
    cin >> opcion;
    
    do
    {
        switch (opcion)
        {
            case 1:
                existe = LeerNombrePartida(opcion, nombre_partida);
                if (existe == false)
                {
                    cout << "\nNo hay partidas de un jugador guardadas\n";
                    partida_reanudada = false;
                    opcion_invalida = false;
                }
                else
                {
                    partida_reanudada = LeerPartidaGuardadaUnJugador (nombre_partida);
                    opcion_invalida = false;
                }
                break;
            case 2:
                existe = LeerNombrePartida(opcion, nombre_partida);
                if (existe == false)
                {
                    cout << "\nNo hay partidas de dos jugadores guardadas\n";
                    partida_reanudada = false;
                    opcion_invalida = false;
                }
                else
                {
                    partida_reanudada = LeerPartidaGuardadaDosJugadores (nombre_partida);
                    opcion_invalida = false;
                }
                break;
            default:
                cout << "\nOpcion incorrecta, vuelva a introducir la opcion: ";
                cin >> opcion;
                opcion_invalida = true;
                break;
        }
    }
    while (opcion_invalida == true);

    
    return partida_reanudada;
}

/************************** LeerNombrePartida ***************************//**
*
* Reanuda una partida guardada
*
* @param[in] cant_jugadores Cantidad de jugadores
* @param[in] nombre_partida Nombre de la partida
*
* @retval true  Leyo el nombre de la partida
* @retval false No leyo el nombre de la partida
*
*//*************************************************************************/
bool LeerNombrePartida(int cant_jugadores, string & nombre_partida)
{
    ifstream un_jugador, dos_jugadores;
    VNombres_Guardados nombres_guardadas;
    bool leido;
    int cant_partidas_guardadas, i, opcion;
    string nombre_temporal;
    
    if (cant_jugadores == 1)
    {
        un_jugador.open(PARTIDASUNJUGADOR.c_str());
        if (!un_jugador)
        {
            leido = false;
        }
        else
        {
            un_jugador >> cant_partidas_guardadas;
            un_jugador.ignore();
            cout << "\nOpciones: ";
            for (i = 0; i < cant_partidas_guardadas; i++)
            {
                cout << "\nOpciones " << i + 1 << ": ";
                un_jugador >> nombres_guardadas[i];
                cout << nombres_guardadas[i];
                un_jugador.ignore();
            }
            cout << "\nOpcion: ";
            cin >> opcion;
            
            nombre_temporal = nombres_guardadas[opcion - 1] + ".dat";
            nombre_partida = nombre_temporal;
            
            leido = true;
        }
    }
    else //cantidad de jugadores = 2
    {
        dos_jugadores.open(PARTIDADOSJUGADORES.c_str());
        if (!dos_jugadores)
        {
            leido = false;
        }
        else
        {
            dos_jugadores >> cant_partidas_guardadas;
            dos_jugadores.ignore();
            cout << "\nOpciones: ";
            for (i = 0; i < cant_partidas_guardadas; i++)
            {
                cout << "\nOpciones " << i + 1 << ": ";
                dos_jugadores >> nombres_guardadas[i];
                cout << nombres_guardadas[i];
                dos_jugadores.ignore();
            }
            cout << "\nOpcion: ";
            cin >> opcion;
            
            nombre_temporal = nombres_guardadas[opcion - 1] + "_2_jugadores.dat";
            nombre_partida = nombre_temporal;
            
            leido = true;
        }
    }
    
    return leido;
}

/*************************************** LeerPartidaGuardadaUnJugador ********************************************//**
*
* Lee el fichero de la partida guardada
*
* @param[out] nombre_partida                Nombre de la partida
*
* @retval true  Se ha leido correctamente la partida
* @retval false Se ha leido incorrectamente la partida
*
*//****************************************************************************************************/
bool LeerPartidaGuardadaUnJugador (string nombre_partida)
{
    bool leido;
    int i;
    DatosBinarios datos_binarios;
    YaPreguntadas preguntas_preguntadas;
    string jugador;
    ifstream f;
    
    f.open(nombre_partida.c_str(), ios::binary);
    if(!f)
    {
        leido = false;
    }
    else
    {
        /*
         * Primero leemos todos los datos que pueden ser binarios es decir lo que no son strings en
         * un registro
         */
        f.read( (char *) (& datos_binarios), sizeof (datos_binarios) );

        /*
         * Ahora leemos los datos que son strings en el fichero
         */
        f >> jugador;
        f.ignore();
        for (i = 0; i < datos_binarios.num_preguntas_realizadas; i++)
        {
            getline (f, preguntas_preguntadas[i].enunciado);
        }
 
        f.close();
        
        leido = true;
    }
    
    if (leido == true)
    {
        PartidaReanudadaUnJugador(datos_binarios, jugador, preguntas_preguntadas);
    }
    
    return leido;
}

/*************************************** LeerPartidaGuardadaDosJugadores ********************************************//**
*
* Lee el fichero de la partida guardada
*
* @param[in] nombre_partida                Nombre de la partida
*
* @retval true  Se ha leido correctamente la partida
* @retval false Se ha leido incorrectamente la partida
*
*//********************************************************************************************************************/
bool LeerPartidaGuardadaDosJugadores (string nombre_partida)
{
    int i;
    bool leido;
    string jugador1, jugador2;
    ifstream f;
    VDatosBinarios datos_binarios;
    YaPreguntadas preguntas_preguntadas;
    
    f.open(nombre_partida.c_str(), ios::binary);
    if (!f)
    {
        leido = false;
    }
    else
    {
        /*
         * Primero leemos todos los datos que pueden ser binarios es decir lo que no son strings en
         * un registro
         */
        f.read( (char *) (& datos_binarios), sizeof(datos_binarios) );
        
        /*
         * Ahora leemos los datos que son strings en el fichero
         */
        f >> jugador1;
        f.ignore();
        f >> jugador2;
        f.ignore();
        for (i = 0; i < datos_binarios[0].num_preguntas_realizadas; i++)
        {
            getline (f, preguntas_preguntadas[i].enunciado);
        }
        
        leido = true;
    }
    
    if (leido == true)
    {
        PartidaReanudadaDosJugadores(datos_binarios, jugador1, jugador2, preguntas_preguntadas);
    }
    
    return leido;
}

/*************************************** PartidaReanudadaUnJugador ********************************************//**
*
* Reanuda la partida
*
* @param[in] datos_binarios         Datos importantes de la partida
* @param[in] jugador                Nick del jugador
* @param[in] preguntas_preguntadas  Preguntas ya preguntadas en la partida
*
*//****************************************************************************************************************/
void PartidaReanudadaUnJugador(DatosBinarios datos_binarios, string jugador, YaPreguntadas preguntas_preguntadas)
{
    int opcion = 1, dado, cant_jugadores = 1;
    bool respuesta, seguir_jugando = true, opcion_invalida, partida_ganada, partida_guardada_correctamente, hall_fame;
    
    cout << "\nJugador: " << jugador;
    cout << "\nPuntaje Actual: " << datos_binarios.puntaje;
    cout << endl;
    
    do
    {
        if (datos_binarios.puntaje >= 5 && opcion != 0)
        {
            respuesta = NuevaPartidaUnJugadorCaso1(preguntas_preguntadas, datos_binarios.num_preguntas_realizadas, datos_binarios.categorias_ganadas);
            if (respuesta)
            {
                datos_binarios.puntaje -= 5;
            }
            else
                datos_binarios.puntaje -= 10;
            datos_binarios.num_preguntas_realizadas++;
        }
        else if (datos_binarios.puntaje <= 5 || opcion == 0)
        {
            respuesta = NuevaPartidaUnJugadorCaso2(preguntas_preguntadas, datos_binarios.num_preguntas_realizadas, datos_binarios.categorias_ganadas, dado);
            if (respuesta == true && dado != 7)
            {
                datos_binarios.puntaje += 1;
            }
            else if (respuesta == false && dado == 7)
            {
                datos_binarios.puntaje -= 5;
            }
            datos_binarios.num_preguntas_realizadas++;
        }
        
        partida_ganada = JuegoGanado(datos_binarios.categorias_ganadas);
        
        if (partida_ganada == false)
        {
            cout << endl << "Puntaje Actual: " << datos_binarios.puntaje;
            if (datos_binarios.puntaje >= 5)
            {
                cout << endl << "Opcion 0: Tirar Dado";
            }
            cout << endl << "Opcion 1: Seguir Jugando";
            cout << endl << "Opcion 2: Abandonar partida sin guardar";
            cout << endl << "Opcion 3: Guardar partida";
            cout << endl << "Opcion: ";
            cin >> opcion;
            
            opcion_invalida = false;
            while (opcion_invalida == false)
            {
                switch (opcion)
                {
                    case 0:
                        seguir_jugando = true;
                        opcion_invalida = true;
                        break;
                    case 1:
                        seguir_jugando = true;
                        opcion_invalida = true;
                        break;
                    case 2:
                        cout << "\nJuego terminado\n\n";
                        seguir_jugando = false;
                        opcion_invalida = true;
                        break;
                    case 3:
                        partida_guardada_correctamente = GuardarPartida (cant_jugadores, datos_binarios.puntaje, datos_binarios.categorias_ganadas, datos_binarios.num_preguntas_realizadas, jugador, preguntas_preguntadas);
                        if (partida_guardada_correctamente == true)
                        {
                            cout << "\nLa partida ha sido guardada correctamente\n\n";
                            opcion_invalida = true;
                            seguir_jugando = false;
                        }
                        else
                        {
                            cout << "\nLa partida no ha sido guardada. Dame otra vez la opcion: ";
                            cin >> opcion;
                            opcion_invalida = false;
                        }
                        break;
                    default:
                        cout << "\nOpcion Invalida. Dame otra vez la opcion (OPCIONES DEL 1 AL 3): ";
                        cin >> opcion;
                        opcion_invalida = false;
                        break;
                }
            }
        }
        
        
    }
    while (seguir_jugando == true && partida_ganada == false);
    
    if (partida_ganada == true)
    {
        cout << "\nFelicidades has ganado el juego";
        cout << "\nPuntaje Final: " << datos_binarios.puntaje;
        cout << "\nNumeros de Preguntas Realizadas: " << datos_binarios.num_preguntas_realizadas;
        hall_fame = HallOfFame(jugador, datos_binarios.puntaje);
        if (hall_fame == false)
        {
            cout << "\nNo se pudo cargar el Hall Of Fame...\n\n";
        }
    }
    
    return;
}

/*************************************** PartidaReanudadaDosJugadores ********************************************//**
*
* Reanuda la partida
*
* @param[in] datos_binarios         Datos importantes de la partida
* @param[in] jugador1               Nick del jugador 1
* @param[in] jugador2               Nick del jugador 2
* @param[in] preguntas_preguntadas  Preguntas ya preguntadas en la partida
*
*//****************************************************************************************************************/
void PartidaReanudadaDosJugadores(VDatosBinarios datos_binarios,string jugador1, string jugador2, YaPreguntadas preguntas_preguntadas)
{
    int  opcion = 1, dado;
    bool respuesta = false, seguir_jugando = true, opcion_invalida, partida_ganada_jugador1, partida_ganada_jugador2, turno = true;
    bool partida_guardada_correctamente = true;
    
    cout << "\nJugador 1: ";
    cout << jugador1 << ", Puntaje Inicial: " << datos_binarios[0].puntaje;
    cout << "\nJugador 2: ";
    cout << jugador2 << ", Puntaje Inicial: " << datos_binarios[1].puntaje;
    
    do
    {
        if (datos_binarios[0].puntaje >= 5 && opcion != 0 && turno == true)
        {
            cout << "\nTurno de: " << jugador1 << endl << endl;
            
            respuesta = NuevaPartidaDosJugadoresCaso1(preguntas_preguntadas, datos_binarios[0].num_preguntas_realizadas, datos_binarios[0].categorias_ganadas);
            
            if (respuesta)
            {
                datos_binarios[0].puntaje -= 5;
                turno = true;
            }
            else
            {
                datos_binarios[0].puntaje -= 10;
                turno = false;
            }
            datos_binarios[0].num_preguntas_realizadas++;
        }
        else if ((datos_binarios[0].puntaje <= 5 || opcion == 0) && turno == true )
        {
            cout << "\nTurno de: " << jugador1 << endl << endl;
            
            respuesta = NuevaPartidaDosJugadoresCaso2(preguntas_preguntadas, datos_binarios[0].num_preguntas_realizadas, datos_binarios[0].categorias_ganadas, dado);
            
            if (respuesta == true && dado != 7)
            {
                datos_binarios[0].puntaje += 1;
                turno = true;
            }
            else if (respuesta == false && dado != 7)
            {
                turno = false;
            }
            else if (respuesta == true && dado == 7)
            {
                turno = true;
            }
            else if (respuesta == false && dado == 7)
            {
                datos_binarios[0].puntaje -= 5;
                turno = false;
            }
            datos_binarios[0].num_preguntas_realizadas++;
        }
        else if (datos_binarios[1].puntaje >= 5 && opcion != 0 && turno == false)
        {
            cout << "\nTurno de: " << jugador2 << endl << endl;
            
            respuesta = NuevaPartidaDosJugadoresCaso1(preguntas_preguntadas, datos_binarios[0].num_preguntas_realizadas, datos_binarios[1].categorias_ganadas);
            
            if (respuesta)
            {
                datos_binarios[1].puntaje -= 5;
                turno = false;
            }
            else
            {
                datos_binarios[1].puntaje -= 10;
                turno = true;
            }
            datos_binarios[0].num_preguntas_realizadas++;
        }
        else if ((datos_binarios[1].puntaje <= 5 || opcion == 0) && turno == false )
        {
            cout << "\nTurno de: " << jugador2 << endl << endl;
            
            respuesta = NuevaPartidaDosJugadoresCaso2(preguntas_preguntadas, datos_binarios[0].num_preguntas_realizadas, datos_binarios[1].categorias_ganadas, dado);
            
            if (respuesta == true && dado != 7)
            {
                datos_binarios[1].puntaje += 1;
                turno = false;
            }
            else if (respuesta == false && dado != 7)
            {
                turno = true;
            }
            else if (respuesta == true && dado == 7)
            {
                turno = false;
            }
            else if (respuesta == false && dado == 7)
            {
                datos_binarios[1].puntaje -= 5;
                turno = true;
            }
            
            datos_binarios[0].num_preguntas_realizadas++;
        }
        
        partida_ganada_jugador1 = JuegoGanado(datos_binarios[0].categorias_ganadas);
        partida_ganada_jugador2 = JuegoGanado(datos_binarios[1].categorias_ganadas);
        
        if (partida_ganada_jugador1 == false && partida_ganada_jugador2 == false && respuesta == true)
        {
            cout << endl << "Puntaje Actual: " << jugador1 << " = " << datos_binarios[0].puntaje;
            cout << "\t" << jugador2 << " = " << datos_binarios[1].puntaje;
            if ((turno == true && datos_binarios[0].puntaje >= 5) || (turno == false && datos_binarios[1].puntaje >= 5))
            {
                cout << endl << "Opcion 0: Tirar Dado";
            }
            cout << endl << "Opcion 1: Seguir Jugando";
            cout << endl << "Opcion 2: Abandonar partida sin guardar";
            cout << endl << "Opcion 3: Guardar partida";
            cout << endl << "Opcion: ";
            cin >> opcion;
            
            opcion_invalida = false;
            while (opcion_invalida == false)
            {
                switch (opcion)
                {
                    case 0:
                        seguir_jugando = true;
                        opcion_invalida = true;
                        break;
                    case 1:
                        seguir_jugando = true;
                        opcion_invalida = true;
                        break;
                    case 2:
                        cout << "\nJuego terminado\n\n";
                        seguir_jugando = false;
                        opcion_invalida = true;
                        break;
                    case 3:
                        partida_guardada_correctamente = GuardarPartidaDosJugadores (2, datos_binarios[0].puntaje, datos_binarios[1].puntaje, datos_binarios[0].categorias_ganadas, datos_binarios[1].categorias_ganadas, datos_binarios[0].num_preguntas_realizadas, jugador1, jugador2, preguntas_preguntadas);
                        if (partida_guardada_correctamente == true)
                        {
                            cout << "\nLa partida ha sido guardada correctamente\n\n";
                            opcion_invalida = true;
                            seguir_jugando = false;
                        }
                        else
                        {
                            cout << "\nLa partida no ha sido guardada. Dame otra vez la opcion: ";
                            cin >> opcion;
                            opcion_invalida = false;
                            seguir_jugando = false;
                        }
                        break;
                    default:
                        cout << "\nOpcion Invalida. Dame otra vez la opcion (OPCIONES DEL 1 AL 3): ";
                        cin >> opcion;
                        opcion_invalida = false;
                        break;
                }
            }
        }
        else if (partida_ganada_jugador1 == false && partida_ganada_jugador2 == false && respuesta == false)
        {
            cout << endl << "Puntaje Actual: " << jugador1 << " = " << datos_binarios[0].puntaje;
            cout << "\t" << jugador2 << " = " << datos_binarios[1].puntaje;
            cout << endl << "Opcion 1: Seguir Jugando";
            cout << endl << "Opcion 2: Abandonar partida sin guardar";
            cout << endl << "Opcion 3: Guardar partida";
            cout << endl << "Opcion: ";
            cin >> opcion;
            
            opcion_invalida = false;
            while (opcion_invalida == false)
            {
                switch (opcion)
                {
                    case 1:
                        seguir_jugando = true;
                        opcion_invalida = true;
                        break;
                    case 2:
                        cout << "\nJuego terminado\n\n";
                        seguir_jugando = false;
                        opcion_invalida = true;
                        break;
                    case 3:
                        partida_guardada_correctamente = GuardarPartidaDosJugadores (2, datos_binarios[0].puntaje, datos_binarios[1].puntaje, datos_binarios[0].categorias_ganadas, datos_binarios[1].categorias_ganadas, datos_binarios[0].num_preguntas_realizadas, jugador1, jugador2, preguntas_preguntadas);;
                        if (partida_guardada_correctamente == true)
                        {
                            cout << "\nLa partida ha sido guardada correctamente\n\n";
                            opcion_invalida = true;
                            seguir_jugando = false;
                        }
                        else
                        {
                            cout << "\nLa partida no ha sido guardada. Dame otra vez la opcion: ";
                            cin >> opcion;
                            opcion_invalida = false;
                            seguir_jugando = false;
                        }
                        break;
                    default:
                        cout << "\nOpcion Invalida. Dame otra vez la opcion (OPCIONES DEL 1 AL 3): ";
                        cin >> opcion;
                        opcion_invalida = false;
                        break;
                }
            }
        }
    }
    while (seguir_jugando == true && partida_ganada_jugador1 == false && partida_ganada_jugador2 == false);
    
    if (partida_ganada_jugador1 == true)
    {
        cout << "\nFelicidades " << jugador1 << " has ganado el juego...\n\n";
    }
    else if (partida_ganada_jugador2 == true)
    {
        cout << "\nFelicidades " << jugador2 << " has ganado el juego...\n\n";
    }
    
    return;
}

/*********** AmpliarNumeroTarjetas ****************************//**
*
* Amplia el numero de tarjetas disponibles.
*
*//************************************************************/
void AmpliarNumeroTarjetas (void)
{
    unsigned short categoria;
    string enunciado;
    Pregunta pregunta;
    bool error_fichero_enunciados_iguales;
    
    cout << "Introduce el numero de categoria: ";
    cin >> categoria;
    cin.ignore ();
    
    cout << "Dime el enunciado de la pregunta: ";
    getline (cin, enunciado);
    
    if (EstaPreguntaEnFichero (enunciado, categoria, error_fichero_enunciados_iguales) )
        cout << "\nLa pregunta ya se encuentra en el fichero.\n";
    else if ( error_fichero_enunciados_iguales == true)
    {
        cout << "\nError abriendo el fichero en la comprobacion de los enunciados iguales" << endl;
    }
    else
    {
        pregunta = LeerPregunta ();
        if (AnadirPreguntaAFichero (pregunta, categoria) )
        {
            cout << "\nLa pregunta: ";
            MostrarPregunta (pregunta);
            cout << ", ha sido anadido satisfactoriamente." << endl;
        }
        else
            cout << "Error procesando fichero. Pregunta NO anadida.";
    }
    
    return;
}

/************************** EstaPreguntaEnFichero ******************************//**
*
* Comprueba si hay alguna pregunta en el fichero con el mismo enunciado
*
* @param[in]    enunciado                          Enunciado de la pregunta
* @param[in]    categoria                          Categoria de la pregunta
* @param[out]   error_fichero_enunciados_iguales   Enunciados iguales
*
* @retval true Si el enunciado de la pregunta esta repetido en el fichero
* @retval false Si el enunciado de la pregunta no esta repetido en el fichero
*
*//*******************************************************************************/
bool EstaPreguntaEnFichero (const string enunciado, unsigned short categoria, bool & error_fichero_enunciados_iguales)
{
    bool repetida = false;
    Pregunta pr_temporal;
    string enunciado_usuario, enunciado_fichero, cat;
    ifstream f;
    
    enunciado_usuario = TodoMayuscula(enunciado);
    
    cat = to_string(categoria) + ".dat";
    
    f.open(cat);
    if(!f)
    {
        error_fichero_enunciados_iguales = true;
    }
    else
    {
        while (LeerPreguntaFichero(f, pr_temporal) && repetida == false)
        {
            
            enunciado_fichero = TodoMayuscula(pr_temporal.enunciado);
            
            if (enunciado_usuario == enunciado_fichero)
            {
                repetida = true;
            }
        }
        f.close();
    }
    
    return repetida;
}

/************************** TodoMayuscula ******************************//**
*
* Lee el enunciado de un fichero
*
* @param[in] frase Frase a poner en mayuscula
*
* @return Frase en Mayusculas
*
*//*********************************************************************/
string TodoMayuscula(string frase)
{
    size_t i;
    string frase_x;
    
    for (i = 0; i < frase.length(); i++)
    {
        frase_x += toupper(frase[i]) ;
    }
    
    return frase_x;
}

/********************** LeerEnunciadoFichero *****************************//**
*
* Lee el enunciado de un fichero de preguntados
*
* @param[in] f           Descriptor del fichero
* @param[in] pr_temporal Donde se va a guarda el enunciado
*
* @retval true  El enunciado ha sido leido correctamente
* @retval false El enunciado no ha sido leido correctamente
*
*//**************************************************************************/
bool LeerPreguntaFichero (ifstream & f, Pregunta & pr_temporal)
{
    bool lectura_ok = false;
    char ultimo_caracter;
    size_t cant_caracteres;
    string arreglo;
    
    if (getline (f, pr_temporal.enunciado))
    {
        cant_caracteres = pr_temporal.enunciado.length();
        ultimo_caracter = pr_temporal.enunciado[cant_caracteres];
        if ( ultimo_caracter == '\r' || ultimo_caracter == '\0')
        {
            arreglo = pr_temporal.enunciado.substr(0, cant_caracteres - 1);
            pr_temporal.enunciado = arreglo;
        }
        getline (f, pr_temporal.verdadera);
        getline (f, pr_temporal.falsa1);
        getline (f, pr_temporal.falsa2);
        getline (f, pr_temporal.falsa3);
        
        lectura_ok = true;
    }
    
    return lectura_ok;
}

/************ LeerPregunta **************//**
*
* Rellena los campos del registro
*
* @return Registro Pregunta
*
*//****************************************/
Pregunta LeerPregunta (void)
{
    Pregunta pregunta;
    
    cout << "Dame el enunciado de nuevo: ";
    getline (cin, pregunta.enunciado);
    cout << "Dame la respuesta correcta: ";
    getline (cin, pregunta.verdadera);
    cout << "Dame una respuesta falsa: ";
    getline (cin, pregunta.falsa1);
    cout << "Dame una respuesta falsa: ";
    getline (cin, pregunta.falsa2);
    cout << "Dame una respuesta falsa: ";
    getline (cin, pregunta.falsa3);
    
    return pregunta;
}
/******************* AnadirPreguntaAFichero ***************************//**
*
* Comprueba si el fichero a escribir fue abierto satisfactoriamente
*
* @param[in] pregunta   Registro de Pregunta
* @param[in] categoria  Categoria de la pregunta
*
* @retval true  Fichero abierto satisfactoriamente
* @retval false Fichero no abierto satisfactoriamente
*
*//*******************************************************************/
bool AnadirPreguntaAFichero (Pregunta pregunta, unsigned short categoria)
{
    ofstream f;
    string cat;
    bool abrio;
    
    cat = to_string(categoria) + ".dat";
    
    f.open(cat, ios::app);
    if(!f)
    {
        cout << "Error abriendo el fichero donde se va a anadir la pregunta" << endl;
        abrio = false;
    }
    else
    {
        GuardarPreguntaFichero(f, pregunta);
        abrio = true;
        f.close();
    }
    
    return abrio;
}

/********************* GuardarPreguntaFichero ************************//**
*
* Escribe en el fichero lo que esta en el registro
*
* @param[in] f          Descriptor del fichero
* @param[in] pregunta   Registro Pregunta
*
*//*******************************************************************/
void GuardarPreguntaFichero(ofstream & f, Pregunta pregunta)
{
    f << pregunta.enunciado << endl;
    f << pregunta.verdadera << endl;
    f << pregunta.falsa1 << endl;
    f << pregunta.falsa2 << endl;
    f << pregunta.falsa3 << endl;
    
    return;
}
/********************** MostrarPregunta ****************************//**
*
* Muestra por pantalla la pregunta anadida por el usuario
*
* @param[in] pregunta   Registro Pregunta
*
*//*******************************************************************/
void MostrarPregunta (Pregunta pregunta)
{
    cout << pregunta.enunciado;
}
