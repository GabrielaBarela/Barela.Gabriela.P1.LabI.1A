#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <conio.h>
#include "vuelo.h"
#include "utn.h"
#include "aerolineas.h"

int printPassengerA(eAerolineas* listAerolinea, int tamAerolinea)
{
    int base=-1;
    int i;
    if(listAerolinea!=NULL && tamAerolinea>0)
    {
        printf("\nID   Aerolinea\n\n");
        for(i=0;i<tamAerolinea;i++)
        {
                printf("%d %7s \n",listAerolinea[i].id,listAerolinea[i].descripcion);
        }
        base=0;
    }
    return base;
}

int cargarAerolineas(eAerolineas* listAerolinea, int tamAerolinea,int idAerolineas,char descripcionAerolineas[])
{
    int todoOK=-1;
    if(listAerolinea!=NULL && tamAerolinea>0 && descripcionAerolineas!=NULL)
    {
       for(int i=0;i<tamAerolinea;i++)
       {
           if(listAerolinea[i].id== idAerolineas)
           {
               strcpy(descripcionAerolineas,listAerolinea[i].descripcion);
               break;
           }
       }
       todoOK=0;
    }
    return todoOK;
}
