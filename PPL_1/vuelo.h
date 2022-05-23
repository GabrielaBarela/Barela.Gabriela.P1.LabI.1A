#ifndef VUELO_H_INCLUDED
#define VUELO_H_INCLUDED
#define TRUE 1
#define FALSE 0
#include "aerolineas.h"
#include "tipo.h"
#include "avion.h"
#include"destino.h"
#include "fecha.h"
typedef struct
{
    int id;
    int idAvion;
    int idDestino;
    int isEmpty;
    eFecha vueloFecha;
}eVuelo;

#endif // VUELO_H_INCLUDED

int mainMenu();
int initPassengersV(eVuelo* list, int len);
int findPassengersFreeSpaceV(eVuelo* list, int len);
int findPassengersByIdV(eVuelo* list, int len,int id);
int addPassengerV(eVuelo* list,eAvion* listAvion,eDestino* listDestino, int tamVuelo,int tamAvion,int tamDestino,int idVuelo,int idDestino,int idAvion);
int printOnePassengersV(eVuelo listVuelo,eDestino* listDestino,eAvion* listAvion,int tamVuelo,int tamDestino,int tamAvion);
int printPassengerV(eVuelo* listVuelo,eDestino* listDestino,eAvion* listAvion,int tamVuelo,int tamDestino,int tamAvion);
int modifyPassengerV(eVuelo* listVuelo,eDestino* destino,eAvion* avion, int tamVuelo,int tamAvion,int tamDestino, int id, int idDestino,int idAvion);
int generateNextIdV();
int removeVuelo(eVuelo* listVuelo,eDestino* destino,eAvion* avion, int tamVuelo,int tamAvion,int tamDestino, int id, int idDestino,int idAvion);

