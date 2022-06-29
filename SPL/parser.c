#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "peliculas.h"
#include "parser.h"

int parser_MovieFromText(FILE* pFile, LinkedList* pArrayListMovie)
{
    eMovie* auxMovie = movie_new();
    int r;
    int i=0;

    char id_Aux[50], titulo_Aux[50], genero_Aux[50], raiting_Aux[50];
    if (pFile != NULL && pArrayListMovie != NULL)
    {
        while(!feof(pFile))
        {
            r = fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",id_Aux,titulo_Aux,genero_Aux,raiting_Aux);
            if(r==4)
            {
                auxMovie = movie_newParametros(id_Aux,titulo_Aux,genero_Aux,raiting_Aux);
                ll_add(pArrayListMovie,auxMovie);
                i++;
            }
        }
        printf("Se cargaron %d Peliculas a la lista (modo texto)\n", i);
    }
    return i;
}
