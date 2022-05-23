#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <conio.h>
#include "vuelo.h"
#include "aerolineas.h"
#include "tipo.h"
#include "avion.h"
#include"destino.h"
#include "fecha.h"

int mainMenuInformes()
{
    int option;

        printf("\n ******* MENU DE INFORMES *******");
        printf(" \n 1.Informe x Aerolinea");
        printf(" \n 2.Informe x tipo");
        printf(" \n 3.Promedio 'JET'");
        //printf(" \n 4.Aviones x Aerolineas");
        //printf(" \n 5.Aerolineas con mas pasajeros");
        //printf(" \n 6.Aerolineas con menos aviones");
        //printf(" \n 7.Listado de vuelos x avion");
        // printf(" \n 8.");
        printf(" \n ********************************\n");
        fflush(stdin);
    scanf("\n%d",&option);

    return option;
}


int mainMenu()
{
    int option;

        printf("\n ******* MENU DE OPCIONES *******");
        printf(" \n 1.Alta Avion");
        printf(" \n 2.Modificar Trabajo");
        printf(" \n 3.Baja Trabajo");
        printf(" \n 4.Listado de Aviones");
        printf(" \n 5.Listar de Aerolineas");
        printf(" \n 6.Lista de Tipos");
        printf(" \n 7.Listado de Destinos");
        printf(" \n 8.Alta vuelo");
        printf(" \n 9.Informes");
        printf(" \n 10.Salir");
        printf(" \n ********************************\n");
        fflush(stdin);
    scanf("%d",&option);

    return option;
}


int initPassengersV(eVuelo* list, int len)
{
    int base=-1;
    int i;
    if(list!=NULL && len>0)
    {
        for(i=0;i<len;i++)
            {
                list[i].isEmpty=TRUE;///si esta vacio 1=verdadero 0=flaso
                base=0;
            }
    }
    return base;
}

int printOnePassengersV(eVuelo listVuelo,eDestino* listDestino,eAvion* listAvion,int tamVuelo,int tamDestino,int tamAvion)
{
    int todoOk=-1;
    char descripcionDestino[20];

    if(listDestino!=NULL && listAvion!=NULL && tamVuelo>0 && tamDestino>0 && tamAvion>0)
    {
        cargarDestino(listDestino,tamDestino,listVuelo.idDestino,descripcionDestino);
        printf("%d %7s %15.3f %10d\n",listVuelo.id,descripcionDestino,listDestino->precio,listAvion->capacidad);
        todoOk=0;
    }
    return todoOk;
}

int printPassengerV(eVuelo* listVuelo,eDestino* listDestino,eAvion* listAvion,int tamVuelo,int tamDestino,int tamAvion)
{
    int base=-1;
    int i;
    if(listVuelo!=NULL && tamVuelo>0)
    {
        printf("\nID   Destino     Precio   Capacidad\n\n");
        for(i=0;i<tamVuelo;i++)
        {
            if(listVuelo[i].isEmpty==0)
            {
                printOnePassengersV(listVuelo[i],listDestino,listAvion,tamVuelo,tamDestino,tamAvion);
            }
        }
        printf("\n\n");
        base=0;
    }
    return base;
}
int findPassengersFreeSpaceV(eVuelo* list, int len)
{
    int head=-1;
    int i;
    for(i=0;i<len;i++)
    {
        if(list[i].isEmpty == 1)
        {
            head= i;
            break;
        }
    }
    return head;
}



int findPassengersByIdV(eVuelo* list, int len,int id)
{
    int head=-1;
    int i;
    for(i=0; i < len; i++)
    {
        if(list[i].isEmpty == 0 && list[i].id == id)
        {
            head = i;
            break;
        }
    }
    return head;
}

int generateNextIdV()
{
    static int id=0;
    id ++;
    return id;
}


int addPassengerV(eVuelo* list,eAvion* listAvion,eDestino* listDestino, int tamVuelo,int tamAvion,int tamDestino,int idVuelo,int idDestino,int idAvion)
{
    int base;
    int head=-1;
    int auxDia;
    int auxMes;
    int auxAnio;
    eTipo* tipo;
    eAerolineas* aerolinea;
    ePiloto* piloto;

    if(list!=NULL && tamVuelo>0)
    {
        base=findPassengersByIdV(list,tamVuelo,idVuelo);
        if(base!= -1)
        {
            system("cls");
            printf("\nAlta Vuelo\n");

            list[base].id=generateNextIdV();
            idVuelo++;

            printPassengerFly(listAvion,tipo,aerolinea,tamVuelo,4,5,piloto,5);

            getValidInt("\nIngrese el id del Avion:\n","\n*******************  Warning  *******************\nIngrese solo numeros del <1-10000000>",1,10000000,&idAvion);
            list[base].idAvion=idAvion;

            printPassengerD(listDestino,tamDestino);

            getValidInt("Ingrese el id del Destino:\n","\n*******************  Warning  *******************\nIngrese solo numeros del <20000-20003>",20000,20003,&idDestino);
            list[base].idDestino=idDestino;

            getValidInt("\nIngrese dia:\n","\n*******************  Warning  *******************\nIngrese solo numeros del <1-30>",1,30,&auxDia);
            list[base].vueloFecha.dia=auxDia;

            getValidInt("\nIngrese anio:\n","\n*******************  Warning  *******************\nIngrese solo numeros del <2022-2030>",2022,2030,&auxAnio);
            list[base].vueloFecha.anio=auxAnio;

            getValidInt("\nIngrese mes:\n","\n*******************  Warning  *******************\nIngrese solo numeros del <1-12>",1,12,&auxMes);
            list[base].vueloFecha.mes=auxMes;

            list[base].isEmpty=0;
            head=0;
        }
        else
        {
            printf("\nSISTEMA COMPLETO\n");
        }
    }
    return head;
}


int modifyPassengerV(eVuelo* listVuelo,eDestino* destino,eAvion* avion, int tamVuelo,int tamAvion,int tamDestino, int id, int idDestino,int idAvion)
{
    int head=-1;
    int base;
    int options;

    char confirm;
    int auxDia;
    int auxAnio;
    int auxMes;

    eTipo* tipo;
    eAerolineas* aerolinea;
    ePiloto* piloto;

    system("cls");

    if(listVuelo!=NULL && tamVuelo>0 && tamAvion>0 && tamDestino>0)
    {
        printf("\t***Modificar Vuelo***\n");
        printPassengerV(listVuelo,destino,avion,tamVuelo,tamDestino,tamAvion);

        printf("\nIngrese Id:");
        scanf("%d",&id);
        fflush(stdin);

        base=findPassengersByIdV(listVuelo,tamVuelo,id);
        printf("%d",id);

        if(base==-1)
        {
            printf("\nNo hay registro de un Vuelo con el id: %d",id);
        }
        else if(base>=0 && base<tamAvion && listVuelo[base].isEmpty==0)
        {
            printOnePassengersV(listVuelo[base],destino,avion,tamVuelo,tamDestino,tamAvion);

            printf("\nModificar Avion?(s/n)");
            fflush(stdin);
            scanf("%c",&confirm);

            if(confirm=='s')
            {
                printf("\nQue desea modificar?");
                printf("\n1.Avion");
                printf("\n2.Destino");
                printf("\n3.Fecha");

                scanf("%d",&options);

                switch(options)
                {
                    case 1:
                        printPassengerFly(avion,tipo,aerolinea,tamVuelo,4,5,piloto,5);
                        getValidInt("\nIngrese el id del Avion:\n","\n*******************  Warning  *******************\nIngrese solo numeros del <1-10000000>",1,10000000,&idAvion);
                        listVuelo[base].idAvion=idAvion;
                    break;
                    case 2:
                        printPassengerD(destino,tamDestino);
                        getValidInt("Ingrese el id del Destino:\n","\n*******************  Warning  *******************\nIngrese solo numeros del <20000-20003>",20000,20003,&idDestino);
                        listVuelo[base].idDestino=idDestino;
                    break;
                    case 3:
                        getValidInt("\nIngrese dia:\n","\n*******************  Warning  *******************\nIngrese solo numeros del <1-30>",1,30,&auxDia);
                        listVuelo[base].vueloFecha.dia=auxDia;

                        getValidInt("\nIngrese anio:\n","\n*******************  Warning  *******************\nIngrese solo numeros del <2022-2030>",2022,2030,&auxAnio);
                        listVuelo[base].vueloFecha.anio=auxAnio;

                        getValidInt("\nIngrese mes:\n","\n*******************  Warning  *******************\nIngrese solo numeros del <1-12>",1,12,&auxMes);
                        listVuelo[base].vueloFecha.mes=auxMes;
                    break;
                }
                printf("\nSe a realizado la modificacion con exito\n");
            }
            else
            {
                printf("\nSe ha cancelado la operacion");
            }
        }
    }
    return head;
}


int removeVuelo(eVuelo* listVuelo,eDestino* destino,eAvion* avion, int tamVuelo,int tamAvion,int tamDestino, int id, int idDestino,int idAvion)
{
    int head=-1;
    int base;
    char confirm;

    system("cls");
    if(listVuelo!=NULL && tamAvion>0 && tamVuelo>0 && tamDestino>0)
    {
        printf("\n\t***Baja Vuelo***\n");

        printPassengerV(listVuelo,destino,avion,tamVuelo,tamDestino,tamAvion);

        printf("\nIngrese ID del Avion: ");
        scanf("%d",&id);

        base=findPassengersByIdV(listVuelo,tamVuelo,id);

        if(base==-1)
        {
             printf("\nNo hay registro de un Vuelo con el id: %d",id);
        }
        else if(base>=0 && base<tamVuelo && listVuelo[base].isEmpty==0)
        {
            printOnePassengersV(listVuelo[base],destino,avion,tamVuelo,tamDestino,tamAvion);
            fflush(stdin);

            printf("\nConfirma Baja?(s/n)");
            scanf("%c",&confirm);

            if(confirm== 's')
            {
                listVuelo[base].isEmpty=1;
                printf("\nSe a realizado la baja con exito\n");
            }
            else
            {
                printf("\nSe ha cancelado la operacion");
            }
        }
    }
    return head;
}

int caragarVuelo(eVuelo* listVuelo,int tamVuelo)
{
    int todoOk=-1;
    int i;

    int fly[5]={1,2,3,4,5};
    int dia[5]={12,32,4,21,2};
    int mes[5]={2,1,6,10,11};
    int anio[5]={2020,2021,2022,2022,2019};
    int destino[5]={20000,20000,20001,20002,20003};

    if(listVuelo!=NULL && tamVuelo>0)
    {
        for(i=0;i<tamVuelo;i++)
        {
            listVuelo[i].id=generateNextIdV();
            listVuelo[i].idAvion=fly[i];
            listVuelo[i].idDestino=destino[i];
            listVuelo[i].vueloFecha.dia=dia[i];
            listVuelo[i].vueloFecha.mes=mes[i];
            listVuelo[i].vueloFecha.anio=anio[i];

            listVuelo[i].isEmpty=0;
        }
        todoOk=1;
    }
    printf("\n\t***Harcodeo con EXITO!!!***");
    return todoOk;
}
