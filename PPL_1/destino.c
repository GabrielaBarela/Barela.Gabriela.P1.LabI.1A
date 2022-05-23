#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <conio.h>
#include "vuelo.h"
#include "destino.h"
#include "utn.h"

int printPassengerD(eDestino* listDestino, int tamDestino)
{
    int base=-1;
    int i;
    if(listDestino!=NULL && tamDestino>0)
    {
        printf("\nID   Destino     Precio  \n\n");
        for(i=0;i<tamDestino;i++)
        {
                printf("%d %7s %15.3f\n",listDestino[i].id,listDestino[i].descripcion,listDestino[i].precio);
        }
        base=0;
    }
    return base;
}

int cargarDestino(eDestino* listDestino, int tamDestino,int idDestino,char descripcionDestino[])
{
    int todoOK=-1;
    if(listDestino!=NULL && tamDestino>0 && descripcionDestino!=NULL)
    {
       for(int i=0;i<tamDestino;i++)
       {
           if(listDestino[i].id== idDestino)
           {
               strcpy(descripcionDestino,listDestino[i].descripcion);
               break;
           }
       }
       todoOK=0;
    }
    return todoOK;
}

int findPassengersByIdDestino(eDestino* listDestino, int tamDestino,int idDestino)
{
    int head=-1;
    int i;
    if(listDestino!=NULL && tamDestino>0)
    {
        for(i=0; i < tamDestino; i++)
        {
            if(listDestino[i].id == idDestino)
            {
                head = i;
                break;
            }
        }
    }
    return head;
}
