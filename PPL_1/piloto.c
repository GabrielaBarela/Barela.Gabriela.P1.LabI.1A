#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <conio.h>
#include "vuelo.h"
#include "utn.h"
#include "piloto.h"

int printPassengerP(ePiloto* listPiloto, int tamPiloto)
{
    int base=-1;
    int i;
    if(listPiloto!=NULL && tamPiloto>0)
    {
        printf("\nID    Nombre    Sexo\n\n");
        for(i=0;i<tamPiloto;i++)
        {
                printf("%d %7s   %c\n",listPiloto[i].id,listPiloto[i].nombre,listPiloto[i].sexo);
        }
        base=0;
    }
    return base;
}

int cargarPiloto(ePiloto* listPiloto, int tamPiloto,int idPiloto,char nombre[])
{
    int todoOK=-1;

    if(listPiloto!=NULL && tamPiloto>0 && nombre!=NULL)
    {
        for(int i=0;i<tamPiloto;i++)
        {
            if(listPiloto[i].id==idPiloto)
            {
                strcpy(nombre,listPiloto[i].nombre);
                break;
            }
        }
        todoOK=0;
    }
    return todoOK;
}
