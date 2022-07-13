#include<stdio.h>
#include"metodos.h"





int main()
{

    //VARIABLES DE POSICI�N///////////////////////
    int pelX; //posici�n de la pelota en el eje X
    int pelY; //posici�n de la pelota en el eje Y

    int iniRaquet;  //posici�n inicial de la raqueta del jugador
    int finRaquet;  //posici�n final de la raqueta del jugador

    int iniRaquetIA;  //posici�n inicial de la raqueta de la IA
    int finRaquetIA;  //posici�n final de la raqueta de la IA
    ////////////////////////////////////////////////



    char campo [V][H];  //matriz de char la cual hace de campo en el que se ejecutara el juego


    //VARIABLES DE MODIFICACI�N
    int modX;
    int modY;
    int modIA;
    /////////////////////////////

    //possici�n //////////////////
    pelX = 37;
    pelY = 10;

    iniRaquet = 8;
    finRaquet = 12;

    iniRaquetIA = 3;
    finRaquetIA = 18;
    /////////////////////////////

    //modificaci�n//////////
    modX = modY = modIA = -1;
    ///////////////////////

    inicio(campo, pelX,pelY, iniRaquet, finRaquet, iniRaquetIA, finRaquetIA);
    gameloop(campo, pelX,pelY, iniRaquet, finRaquet, iniRaquetIA, finRaquetIA, modX, modY, modIA);

    system("pause");
    return 0;
}
void inicio (char campo[V][H], int pelX, int pelY,int iniRaquet, int finRaquet, int iniRaquetIA, int finRaquetIA)
{

    borde(campo);
    raquetaJugador(campo, iniRaquet, finRaquet);
    raquetaIA(campo, iniRaquetIA, finRaquetIA);
    pelota(campo, pelX, pelY);
    leerCampo(campo);

}


