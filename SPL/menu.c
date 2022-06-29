#include <stdio.h>
#include <stdlib.h>
#include "menu.h"
int pedirOpcionMenu()
{
    int opcion;
    printf("                          A B M                  \n\n");
    printf(" 1. Cargar archivo  \n 2. Listar   \n 3. Asignar Raiting \n 6. Ordenar por Genero Y Raiting  \n 7. Guardar \n 8. Salir\n");
    scanf("%d", &opcion);

    return opcion;

}
