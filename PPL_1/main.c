#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <conio.h>

#include "avion.h"
#include "aerolineas.h"
#include "tipo.h"
#include"destino.h"
#include "fecha.h"
#include "vuelo.h"
#include "piloto.h"

#define LEN 15//VUELO//avion
#define TAMD 4//DESTINO
#define TAMT 4//TIPO
#define TAMA 5//AEROLINEA
#define TAMP 5//piloto

int main()
{
    char seguir;
    int nextId=1;
    int nextIdVuelo=1;
    int loadExist=0;
    int passangerExist=0;

    eVuelo listVuelo[LEN];
    eVuelo vuelo;

    eAvion listAvion[LEN];
    eAvion avion;

    //eDestino auxDestino;

    initPassengersFly(listAvion,LEN);

    eDestino destiny[TAMD]={{20000,"Calafate",22250},{20001,"Miami",103000},{20002,"Madrid",84400},{20003,"Amsterdam",95600}};
    eTipo listTipo[TAMT]={{5000,"Jet"},{5001,"Helice"},{5002,"Planeador"},{5003,"Cargar"}};
    eAerolineas listAerolineas[TAMA]={{1000,"Lan"},{1001,"Iberia"},{1002,"Norweigan"},{1003,"America"},{1004,"Austral"}};
    ePiloto listaPiloto[TAMP]={{3000,"Hernesto",'m'},{3001,"Mia",'f'},{3002,"Pia",'f'},{3003,"Juean",'m'},{3004,"Pedro",'m'}};

            if(loadPassengerFly(listAvion,5)==1 && caragarVuelo(listVuelo,5)==1)
            {
                printPassengerFly(listAvion,listTipo,listAerolineas,5,TAMT,TAMA,listaPiloto,TAMP);
                printPassengerV(listVuelo,destiny,listAvion,5,TAMD,5);
                printf("\n\n");
                loadExist=1;
            }
            else
            {
                printf("Error\n\n");
            }
    do
    {
        switch(mainMenu())
        {
        case 1:
            if(addPassengerFly(listAvion,listAerolineas,listTipo,LEN,nextId,avion.idAerolinea,TAMA,avion.idTipo,TAMT,listaPiloto,TAMP,avion.idPilto)==0)
            {
                nextId++;
                passangerExist=1;
                printf("\nCargado con exito\n\n");
            }
            else
            {
                printf("Error\n\n");
            }
            break;
        case 2:
            if(passangerExist==1 || loadExist==1)
            {
                modifyPassengerFly(listAvion,listAerolineas,listTipo,LEN,nextId,avion.idAerolinea,avion.idTipo,TAMA,TAMT,listaPiloto,TAMP,avion.idTipo);
            }
            else
            {
                printf("\nERROR!!!\nPrimero debe agregar un pasajero\n\n");
            }
            break;
        case 3:
            if(passangerExist==1 || loadExist==1)
            {
               removePassangerAvion(listAvion,LEN,nextId,listTipo,listAerolineas,TAMT,TAMA,listaPiloto,TAMP);
            }
            else
            {
                printf("\nERROR!!!\nPrimero debe agregar un pasajero\n\n");
            }
            break;
        case 4:
            sortAvionxCapacidad(listAvion,LEN);
            printPassengerFly(listAvion,listTipo,listAerolineas,LEN,TAMT,TAMA,listaPiloto,TAMP);
            break;
        case 5:
            printPassengerA(listAerolineas,TAMA);
            break;
        case 6:
            printPassengerT(listTipo,TAMT);
            break;
        case 7:
            printPassengerD(destiny,TAMD);
            break;
        case 8:
            if(addPassengerV(listVuelo,listAvion,destiny,LEN,TAMA,TAMD,vuelo.id,vuelo.idDestino,vuelo.idAvion)==0)
            {
                nextIdVuelo++;
                passangerExist=1;
                printf("\nCargado con exito\n\n");
            }
            else
            {
                printf("Error\n\n");
            }
            break;
        case 9:
            switch(mainMenuInformes())
            {
            case 1:
                avionxAerolinea(listAvion,LEN,listAerolineas,TAMA);
                printPassengerFly(listAvion,listTipo,listAerolineas,LEN,TAMT,TAMA,listaPiloto,TAMP);
                break;
            case 2:
                avionxTipo(listAvion,LEN,listTipo,TAMT);
                printPassengerFly(listAvion,listTipo,listAerolineas,LEN,TAMT,TAMA,listaPiloto,TAMP);
                break;
            case 3:
                promedioJet(listAvion,LEN,listTipo,TAMT,listAerolineas,TAMA);
                printPassengerFly(listAvion,listTipo,listAerolineas,LEN,TAMT,TAMA,listaPiloto,TAMP);

                break;
            }
            break;
        case 10:
            printf("\nConfirma salida?\t");
            fflush(stdin);
            scanf("%c",&seguir);
            break;
        }
    }while(seguir!='s');
    return 0;
}
