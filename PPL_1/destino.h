#ifndef DESTINO_H_INCLUDED
#define DESTINO_H_INCLUDED
typedef struct
{
    int id;
    char descripcion[25];
    float precio;
}eDestino;

#endif // DESTINO_H_INCLUDED

int printPassengerD(eDestino* listDestino, int tamDestino);

int cargarDestino(eDestino* listDestino, int tamDestino,int idDestino,char descripcionDestino[]);

int findPassengersByIdDestino(eDestino* listDestino, int tamDestino,int idDestino);
