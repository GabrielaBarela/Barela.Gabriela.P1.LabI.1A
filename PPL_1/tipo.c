#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <conio.h>
#include "vuelo.h"
#include "utn.h"
#include "tipo.h"

int printPassengerT(eTipo* listTipo, int tamTipo)
{
    int base=-1;
    int i;
    if(listTipo!=NULL && tamTipo>0)
    {
        printf("\nID   Tipo\n\n");
        for(i=0;i<tamTipo;i++)
        {
                printf("%d %7s \n",listTipo[i].id,listTipo[i].descripcion);
        }
        base=0;
    }
    return base;
}

int cargarTipo(eTipo* listTipo, int tamTipo,int idTipo,char descripcionTipo[])
{
    int todoOK=-1;
    int i;
    if(listTipo!=NULL && tamTipo>0 && descripcionTipo!=NULL)
    {
       for(i=0;i<tamTipo;i++)
       {
           if(listTipo[i].id== idTipo)
           {
               strcpy(descripcionTipo,listTipo[i].descripcion);
               break;
           }
       }
       todoOK=0;
    }
    return todoOK;
}
