#ifndef AVION_H_INCLUDED
#define AVION_H_INCLUDED
#include "utn.h"
#include "aerolineas.h"
#include "tipo.h"
#include "piloto.h"
typedef struct
{
    int id;
    int idAerolinea;
    int idTipo;
    int capacidad;
    int idPilto;
    int isEmpty;
}eAvion;


#endif // AVION_H_INCLUDED
int printOnePassengersFly(eAvion unAvion,int tamAvion, eTipo* tipo,int tamTipo,eAerolineas* aerolineas,int tamAerolineas,ePiloto* listPiloto, int tamPiloto);
int printPassengerFly(eAvion* listAvion,eTipo* tipo,eAerolineas* aerolineas,int tamAvion,int tamTipo,int tamAerolinea,ePiloto* listPiloto, int tamPiloto);
int initPassengersFly(eAvion* listAvion, int tamAvion);
int findPassengersFreeSpaceFly(eAvion* listAvion, int tamAvion);
int findPassengersByIdFly(eAvion* listAvion, int tamAvion,int id);
int addPassengerFly(eAvion* listAvion,eAerolineas* aerolinea,eTipo* tipo, int tamAvion,int id,int idAerolinea,int tamAerolinea,int idTipo,int tamTipo,ePiloto* listPiloto, int tamPiloto,int idPiloto);
int generateNextIdA();
int modifyPassengerFly(eAvion* listAvion,eAerolineas* aerolinea,eTipo* tipo, int tamAvion,int id,int idAerolinea,int idTipo,int tamAerolinea, int tamTipo,ePiloto* listPiloto, int tamPiloto,int idPiloto);
int removePassangerAvion(eAvion* listAvion, int tamAvion,int id,eTipo* tipo,eAerolineas* aerolineas,int tamTipo,int tamAerolinea,ePiloto* listPiloto, int tamPiloto);
int sortAvionxCapacidad(eAvion* listAvion,int tamAvion);
int loadPassengerFly(eAvion* listAvion, int tamAvion);
int avionxAerolinea(eAvion* listAvion, int tamAvion,eAerolineas* aerolinea, int tamAerolinea);
int printAvionxAerolinea(eAvion unAvion,eAerolineas* aerolinea,int tamAvion, int tamAerolinea);
int printTipo(eAvion unAvion,eTipo* listTipo,int tamAvion,int tamTipo);
int avionxTipo(eAvion* listAvion,int tamAvio,eTipo* listTipo,int tamTipo);
int promedioJet(eAvion* listAvion,int tamAvio,eTipo* listTipo,int tamTipo,eAerolineas* aerelinea,int tamAEROLINEA);
