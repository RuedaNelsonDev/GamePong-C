
#include<stdio.h>
#include"metodos.h"





void borde (char campo[V][H])
{

    int i,j;

    for(i =0; i< V; i++ )
    {
        for(j =0; j < H; j++ )
        {
            if(i==0 || i ==V-1)
            {
                campo [i][j]='_';
            }
            else if(j ==0 || j ==H-1)
            {
                campo [i][j]='|';

            }
            else
            {

                campo [i][j]=' ';
            }
        }



    }
}



void raquetaJugador(char campo [V][H], int iniRaquet, int finRaqueta)
{

    int i, j;

    for(i = iniRaquet; i<=finRaqueta; i ++)
    {

        for(j = 2; j <=3; j++)
        {

            campo [i][j]='X';
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

            campo [i][j]='H';
        }
    }


}

void pelota (char campo [V][H], int pelX, int pelY)
{
    campo[pelY][pelX]='0';

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
