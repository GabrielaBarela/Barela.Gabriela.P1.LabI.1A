#ifndef AEROLINEAS_H_INCLUDED
#define AEROLINEAS_H_INCLUDED

typedef struct
{
    int id;
    char descripcion[20];
}eAerolineas;

#endif // AEROLINEAS_H_INCLUDED

int printPassengerA(eAerolineas* listAerolinea, int tamAerolinea);

int cargarAerolineas(eAerolineas* listAerolinea, int tamAerolinea,int idAerolineas,char descripcionAerolineas[]);
