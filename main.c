#include<stdio.h>
#include"metodos.h"


int main()
{


    int pelX;
    int pelY;
    int iniRaquet;
    int finRaquet;
    int iniRaquetIA;
    int finRaquetIA;

    char campo [V][H];

    int modX;
    int modY;
    int modIA;


    pelX = 37;
    pelY = 10;

    iniRaquet = 8;
    finRaquet = 12;

    iniRaquetIA = 3;
    finRaquetIA = 18;


    inicio(campo, pelX,pelY, iniRaquet, finRaquet, iniRaquetIA, finRaquetIA);

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


