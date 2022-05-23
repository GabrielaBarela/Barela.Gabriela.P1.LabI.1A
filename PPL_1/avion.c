#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <conio.h>
#include "vuelo.h"
#include "utn.h"
#include "avion.h"
#include "aerolineas.h"
#include "tipo.h"
#include "piloto.h"

int initPassengersFly(eAvion* listAvion, int tamAvion)
{
    int base=-1;
    int i;
    if(listAvion!=NULL && tamAvion>0)
    {
        for(i=0;i<tamAvion;i++)
            {
                listAvion[i].isEmpty=1;///si esta vacio 1=verdadero 0=flaso
                base=0;
            }
    }
    return base;
}
int printOnePassengersFly(eAvion unAvion,int tamAvion, eTipo* tipo,int tamTipo,eAerolineas* aerolineas,int tamAerolineas,ePiloto* listPiloto, int tamPiloto)
{
    int todoOk=-1;
    char descripcionAerolinea[20];
    char descripcionTipo[20];
    char descripcionPiloto[20];

    if(tipo!=NULL && aerolineas!=NULL && tamAvion>0 && tamTipo>0 && tamAerolineas>0 && listPiloto!=NULL && tamPiloto>0)
    {
        cargarAerolineas(aerolineas,tamAerolineas,unAvion.idAerolinea,descripcionAerolinea);

        cargarTipo(tipo,tamTipo,unAvion.idTipo,descripcionTipo);

        cargarPiloto(listPiloto,tamPiloto,unAvion.idPilto,descripcionPiloto);

        printf("\n%d     %-10s     %-10s       %d      %-10s",unAvion.id,descripcionTipo,descripcionAerolinea,unAvion.capacidad,descripcionPiloto);
       todoOk=0;
    }
    return todoOk;
}
int printAvionxAerolinea(eAvion unAvion,eAerolineas* aerolineas,int tamAvion, int tamAerolineas)
{
    int todoOk=-1;
    char descripcionAerolinea[20];
    if(aerolineas!=NULL && tamAvion>0 && tamAerolineas>0)
    {
        cargarAerolineas(aerolineas,tamAerolineas,unAvion.idAerolinea,descripcionAerolinea);
        printf("\n%d                   %-10s",unAvion.id,descripcionAerolinea);
        todoOk=0;
    }
    return todoOk;
}
int printTipo(eAvion unAvion,eTipo* listTipo,int tamAvion,int tamTipo)
{
    int todoOk=-1;
    char descripcionTipo[20];
    if(listTipo!=NULL && tamAvion>0 && tamTipo>0)
    {
        cargarTipo(listTipo,tamTipo,unAvion.idTipo,descripcionTipo);
        printf("\n%d                   %-10s",unAvion.id,descripcionTipo);
        todoOk=0;
    }
    return todoOk;
}
int printPassengerFly(eAvion* listAvion,eTipo* tipo,eAerolineas* aerolineas,int tamAvion,int tamTipo,int tamAerolinea,ePiloto* listPiloto, int tamPiloto)
{
    int base=-1;
    int i;
    if(listAvion!=NULL && tamAvion>0)
    {
        printf("\nID   Tipo          Aerolinea    Capacidad    Piloto\n\n");
        for(i=0;i<tamAvion;i++)
        {
            if(listAvion[i].isEmpty==0)
            {
                printOnePassengersFly(listAvion[i],tamAvion,tipo,tamTipo,aerolineas,tamAerolinea,listPiloto,tamPiloto);
            }
        }
        printf("\n\n");
        base=0;
    }
    return base;
}


int findPassengersFreeSpaceFly(eAvion* listAvion, int tamAvion)
{
    int head=-1;
    int i;
    for(i=0;i<tamAvion;i++)
    {
        if(listAvion[i].isEmpty == 1)
        {
            head= i;
            break;
        }
    }
    return head;
}
int findPassengersByIdFly(eAvion* listAvion, int tamAvion,int id)
{
    int head=-1;
    int i;
    if(listAvion!=NULL && tamAvion>0)
    {
        for(i=0; i < tamAvion; i++)
        {
            if(listAvion[i].isEmpty == 0 && listAvion[i].id == id)
            {
                head = i;
                break;
            }
        }
    }
    return head;
}

int generateNextIdA()
{
    static int id=0;
    id ++;
    return id;
}

int addPassengerFly(eAvion* listAvion,eAerolineas* aerolinea,eTipo* tipo, int tamAvion,int id,int idAerolinea,int tamAerolinea,int idTipo,int tamTipo,ePiloto* listPiloto, int tamPiloto,int idPiloto)
{
    int base;
    int head=-1;
    int option;

    if(listAvion!=NULL && tamAvion>0)
    {
        base=findPassengersFreeSpaceFly(listAvion,tamAvion);
        if(base!= -1)
        {
            system("cls");
            printf("\nAlta Avion\n");

            listAvion[base].id=generateNextIdA();
            id++;

            printPassengerP(listPiloto,tamPiloto);
            getValidInt("\nIngrese el id del piloto:\n","\n*******************  Warning  *******************\nIngrese solo numeros del <3000-3004>",3000,3004,&idPiloto);
            listAvion[base].idPilto=idPiloto;

            printPassengerA(aerolinea,tamAerolinea);
            getValidInt("\nIngrese el id de La aerolinea:\n","\n*******************  Warning  *******************\nIngrese solo numeros del <1000-1004>",1000,1004,&idAerolinea);
            listAvion[base].idAerolinea=idAerolinea;

            printPassengerT(tipo,tamTipo);
            getValidInt("\nIngrese el id del Tipo:\n","\n*******************  Warning  *******************\nIngrese solo numeros del <5000-5003>",5000,5003,&idTipo);
            listAvion[base].idTipo=idTipo;

            getValidInt("\nIngrese la Cantidad de Pasajeros:\n","\n*******************  Warning  *******************\nIngrese solo numeros del <10-300>",10,300,&option);
            listAvion[base].capacidad=option;

            listAvion[base].isEmpty=0;
            head=0;
        }
        else
        {
            printf("\nSISTEMA COMPLETO\n");
        }
    }
    return head;
}

int modifyPassengerFly(eAvion* listAvion,eAerolineas* aerolinea,eTipo* tipo, int tamAvion,int id,int idAerolinea,int idTipo,int tamAerolinea, int tamTipo,ePiloto* listPiloto, int tamPiloto,int idPiloto)
{
    int head=-1;
    int base;//i
    int options;

    char confirm;
    int auxCapacidad;

        system("cls");

        if(listAvion!=NULL && tamAvion>0 && tamTipo>0 && tamAerolinea>0 && tamPiloto>0)
        {
            printf("Modificar Avion");
            printPassengerFly(listAvion,tipo,aerolinea,tamAvion,tamTipo,tamAerolinea,listPiloto,tamPiloto);

            printf("\nIngrese Id:");
            scanf("%d",&id);
            fflush(stdin);

            base=findPassengersByIdFly(listAvion,tamAvion,id);
            printf("%d",id);

            if(base==-1)
            {
                printf("\nNo hay registro de un Avion con el id: %d",id);
            }
            else if(base>=0 && base<tamAvion && listAvion[base].isEmpty==0)
            {
                printOnePassengersFly(listAvion[base],tamAvion,tipo,tamTipo,aerolinea,tamAerolinea,listPiloto,tamPiloto);

                printf("\nModificar Avion?(s/n)");
                fflush(stdin);
                scanf("%c",&confirm);
                if(confirm=='s')
                {
                    printf("\nQue desea modificar?");
                    printf("\n1.Aerolineas");
                    printf("\n2.Tipo");
                    printf("\n3.Cantidad de Pasajeros");
                    printf("\n4.Piloto");

                    scanf("%d",&options);

                    switch(options)
                        {
                        case 1:
                                printPassengerA(aerolinea,tamAerolinea);
                                getValidInt("\nIngrese el id de La aerolinea:\n","\n*******************  Warning  *******************\nIngrese solo numeros del <1000-1004>",1000,1004,&idAerolinea);
                                listAvion[base].idAerolinea=idAerolinea;
                            break;
                        case 2:
                                printPassengerT(tipo,tamTipo);
                                getValidInt("\nIngrese el id del Tipo:\n","\n*******************  Warning  *******************\nIngrese solo numeros del <5000-5003>",5000,5003,&idTipo);
                                listAvion[base].idTipo=idTipo;
                            break;
                        case 3:
                                getValidInt("\nIngrese la Cantidad de Pasajeros:\n","\n*******************  Warning  *******************\nIngrese solo numeros del <10-300>",10,300,&auxCapacidad);
                                listAvion[base].capacidad=auxCapacidad;
                            break;
                        case 4:
                                printPassengerP(listPiloto,tamPiloto);
                                getValidInt("\nIngrese el id del piloto:\n","\n*******************  Warning  *******************\nIngrese solo numeros del <3000-3004>",1000,1004,&idPiloto);
                                listAvion[base].idPilto=idPiloto;
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

int removePassangerAvion(eAvion* listAvion, int tamAvion,int id,eTipo* tipo,eAerolineas* aerolineas,int tamTipo,int tamAerolinea,ePiloto* listPiloto,int tamPiloto)
{
    int head=-1;
    int base;
    char confirm;

    system("cls");
    if(listAvion!=NULL && tamAvion>0 && tamTipo>0 && tamAerolinea>0 && tamPiloto>0)
    {
        printf("\n\t***Baja Avion***\n");

        printPassengerFly(listAvion,tipo,aerolineas,tamAvion,tamTipo,tamAerolinea,listPiloto,tamPiloto);

        printf("\nIngrese ID del Avion: ");
        //scanf("%d",&id);
        getValidInt("\n","Error, ingrese un numero",0,100000000,&id);

        base=findPassengersByIdFly(listAvion,tamAvion,id);

        if(base==-1)
        {
            printf("\nNo hay registro de un Pasagero con el id: %d",id);
        }
        else if(base>=0 && base<tamAvion && listAvion[base].isEmpty==0)
        {
            printOnePassengersFly(listAvion[base],tamAvion,tipo,tamTipo,aerolineas,tamAerolinea,listPiloto,tamPiloto);
            fflush(stdin);

            printf("\nConfirma Baja?(s/n)");
            scanf("%c",&confirm);


            if(confirm== 's')
            {
                listAvion[base].isEmpty=1;
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

int loadPassengerFly(eAvion* listAvion, int tamAvion)
{
    int todoOk=-1;
    int i;

    int tipo[5]={5000,5001,5002,5003,5000};
    int aerolineas[5]={1000,1001,1002,1003,1004};
    int cantidad[5]={24,65,34,32,41};
    int piloto[5]={3001,3003,3000,3002,3004};

    if (listAvion!=NULL && tamAvion>0)
    {
        for(i=0;i<5;i++)
        {
            listAvion[i].id=generateNextIdA();
            listAvion[i].idTipo=tipo[i];
            listAvion[i].idAerolinea=aerolineas[i];
            listAvion[i].capacidad=cantidad[i];
            listAvion[i].idPilto=piloto[i];

            listAvion[i].isEmpty=0;
        }
        todoOk=1;
    }
    printf("\n\t***Harcodeo con EXITO DE AVION!!!***");
    return todoOk;
}

int sortAvionxCapacidad(eAvion* listAvion,int tamAvion)
{
    eAvion auxAvion;

    int head=-1;
    int i;
    int j;

    if(listAvion!=NULL && tamAvion>0)
    {
        for(i=0;i<tamAvion;i++)
        {
            for(j=i+1;j<tamAvion;j++)
            {
                if(listAvion[i].isEmpty==0)
                {
                    if(listAvion[i].capacidad>listAvion[j].capacidad)
                    {
                        auxAvion=listAvion[i];
                        listAvion[i]=listAvion[j];
                        listAvion[j]=auxAvion;
                    }
                    else if(listAvion[i].capacidad == listAvion[j].capacidad)
                    {
                        if(listAvion[i].idAerolinea>listAvion[j].idAerolinea)
                        {
                            auxAvion=listAvion[i];
                            listAvion[i]=listAvion[j];
                            listAvion[j]=auxAvion;
                        }
                    }
                    head=1;
                }
            }
        }
    }
    return head;
}

int avionxAerolinea(eAvion* listAvion, int tamAvion,eAerolineas* aerolinea, int tamAerolinea)
{
    int head=-1;
    int i;
    int idAerolinea;

    printf("\n***Listado x Aerolinea***");

    printPassengerA(aerolinea,tamAerolinea);

    getValidInt("\nIngrese el id de La aerolinea:\n","\n*******************  Warning  *******************\nIngrese solo numeros del <1000-1004>",1000,1004,&idAerolinea);
    printf("\nID avion      Aerolinea");
    for(i=0;i<tamAvion;i++)
    {
        if(listAvion[i].idAerolinea==idAerolinea && listAvion[i].isEmpty==0)
        {
            printAvionxAerolinea(listAvion[i],aerolinea,tamAvion,tamAerolinea);
        }
    }
    return head;
}
 int avionxTipo(eAvion* listAvion,int tamAvio,eTipo* listTipo,int tamTipo)
 {
    int head=-1;
    int i;
    int idTipo;

    printf("\n***Listado x Tipo***");
    printPassengerT(listTipo,tamTipo);
    getValidInt("\nIngrese el id del Tipo:\n","\n*******************  Warning  *******************\nIngrese solo numeros del <5000-5003>",5000,5003,&idTipo);
    printf("\nID avion      Tipo");
    for(i=0;i<tamAvio;i++)
    {
        if(listAvion[i].idTipo==idTipo && listAvion[i].isEmpty==0)
        {
            printTipo(listAvion[i],listTipo,tamAvio,tamTipo);
        }
    }
    return head;
 }





int promedioJet(eAvion* listAvion,int tamAvio,eTipo* listTipo,int tamTipo,eAerolineas* aerelinea,int tamAEROLINEA)
{
    int head=-1;
    int i;
    int cantTipo=0;
    int cantTotalTipo=0;
    int cantnotipo=0;
    float promedioJet;

    if(listAvion!=NULL && listTipo !=NULL && aerelinea!=NULL && tamAEROLINEA>0 && tamTipo>0 && tamAvio>0)
    {
        for(i=0;i<tamAvio;i++)
        {
            if(listAvion[i].idTipo==5000 && listAvion[i].isEmpty==0)
            {
                cantTipo++;
            }
            else if(listAvion[i].isEmpty==0)
            {
                cantnotipo++;
            }
        }
        if(cantTipo>0 && cantnotipo>0)
        {
            cantTotalTipo=cantTipo+cantnotipo;
            promedioJet=(float)cantTipo/cantTotalTipo;
        }
        if(promedioJet>0)
        {
            printf("\nEl promedio de avion tipo Jet es: %.2f\n",promedioJet);
        }
        else
        {
            printf("\nNo hay Jets en el Sistema");
        }
        head=0;
    }

    return head;
}
