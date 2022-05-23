#ifndef PILOTO_H_INCLUDED
#define PILOTO_H_INCLUDED

typedef struct
{
    int id;
    char nombre[20];
    char sexo;
}ePiloto;

#endif // PILOTO_H_INCLUDED
int printPassengerP(ePiloto* listPiloto, int tamPiloto);
