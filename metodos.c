
#include<stdio.h>
#include<windows.h>
#include"metodos.h"


void borde (char campo[V][H])//Limita visualmente los bordes del campo en el que se ejecuta el juego
{
    int i,j;

    for(i =0; i< V; i++ )
    {
        for(j =0; j < H; j++ )
        {
            if(i==0 || i ==V-1)
            {
                campo [i][j]= BORDE_HORIZONTAL;
            }
            else if(j ==0 || j ==H-1)
            {
                campo [i][j]= BORDE_VERTICAL;

            }
            else
            {

                campo [i][j]=' ';
            }
        }
    }
}

void raquetaJugador(char campo [V][H], int iniRaquet, int finRaqueta) //
{

    int i, j;

    for(i = iniRaquet; i<=finRaqueta; i ++)
    {

        for(j = 2; j <=3; j++)
        {

            campo [i][j]=RAQUETA_JUGADOR;
        }
    }


}
void raquetaIA(char campo [V][H], int iniRaquetIA, int finRaquetIA)
{

    int i, j;

    for(i = iniRaquetIA; i<=finRaquetIA; i ++)
    {

        for(j = H -4 ; j <=H-3; j++)
        {

            campo [i][j]=RAQUETA_IA;
        }
    }


}

void pelota (char campo [V][H], int pelX, int pelY)
{
    campo[pelY][pelX]='O';

}

void leerCampo(char campo[V][H])
{

    int i,j;
    for (i = 0; i <V; i++)
    {


        for(j=0; j<H; j++)
        {
            printf("%c", campo[i][j]);
        }
        printf("\n");
    }

}

void update(char campo[V][H], int pelX, int pelY,int iniRaquet, int finRaquet, int iniRaquetIA, int finRaquetIA)
{

    borde(campo);
    raquetaJugador(campo, iniRaquet, finRaquet);
    raquetaIA(campo, iniRaquetIA, finRaquetIA);
    pelota(campo, pelX, pelY);
    //leerCampo(campo);


}
void   gameloop(char campo[V][H], int pelX, int pelY,int iniRaquet, int finRaquet, int iniRaquetIA, int finRaquetIA,int modX, int modY, int modIA)
{
    int gol = 0;
    do
    {

        draw(campo); //Dibujar en pantalla
        input(campo,&pelX, &pelY, &iniRaquet, &finRaquet, &iniRaquetIA,&finRaquetIA, &modX, &modY, &modIA, &gol);  //Verifica y modificar las posiciones
        update(campo, pelX,pelY, iniRaquet, finRaquet, iniRaquetIA, finRaquetIA); //Actualizar la matriz campo
        Sleep(10);
    }
    while(gol==0);
}

void draw(char campo[V][H])
{

    system("cls");
    leerCampo(campo);
}


void input(char campo[V][H], int *pelX, int *pelY,int *iniRaquet, int *finRaquet, int *iniRaquetIA, int *finRaquetIA,int *modX, int *modY, int *modIA, int *gol)
{
    int i;
    char key;
//Verificación///////////
    if(*pelY ==1||*pelY == V-2)
    {
        *modY *= -1;

    }

    if( *pelX==1||*pelX==H-2)
    {
        *gol =1;

    }
    if(*pelX ==4)
    {
        for(i=(*iniRaquet); i<=(*finRaquet); i++)
        {
            if(i==(*pelY))
            {
                *modX*=-1;
            }

        }

    }
    if(*pelX ==H-5)
    {
        for(i=(*iniRaquetIA); i<=(*finRaquetIA); i++)
        {
            if(i==(*pelY))
            {
                *modX*=-10;
            }

        }
    }

    if(*iniRaquetIA ==1 ||*finRaquetIA==V-1)
    {
        *modIA *= -1;

    }

    //Modificación////////////

    if(*gol==0)
    {
        //Pelota

        *pelX +=(*modX);
        *pelY +=(*modY);

        //Raqueta IA
        *iniRaquetIA += (*modIA);
        *finRaquetIA += (*modIA);


        //Raqueta jugador

        if(kbhit() == 1)
        {
            key = getch();

            if(key == 'p')
            {
                if(*iniRaquet!=1)
                {

                    *iniRaquet-=1;
                    *finRaquet-=1;
                }
            }
            if(key == 'l')
            {
                if(*finRaquet!=1)
                {

                    *iniRaquet+=1;
                    *finRaquet+=1;
                }
            }
        }
    }
    void update(char campo[V][H], int pelX, int pelY,int iniRaquet, int finRaquet, int iniRaquetIA, int finRaquetIA)
    {

        borde(campo);
        raquetaJugador(campo, iniRaquet, finRaquet);
        raquetaIA(campo, iniRaquetIA, finRaquetIA);
        pelota(campo, pelX, pelY);

    }
}
