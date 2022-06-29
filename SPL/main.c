#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include "LinkedList.h"
#include "controller.h"
#include "menu.h"
#include "peliculas.h"

int main()
{
    int option;
    int flag1=0;

    LinkedList* listMovie = ll_newLinkedList();
    LinkedList* listMovieNULL= NULL;

    do
    {
        option= pedirOpcionMenu();
        switch(option)
        {
        case 1:
            if(flag1==0)
            {
                controller_loadFromText("movies.csv",listMovie);

                system("pause");
                system("cls");

                flag1=1;
                break;
            }
            else
            {
                printf("Ya ha cargado los datos\n");
                system("pause");
                system("cls");
            }

        case 2:
            if(flag1==1)
            {
                controller_ListMovie(listMovie);
            }
            break;
        case 3:
            listMovieNULL= ll_map(listMovie,movie_mapRaiting);
            controller_ListMovie(listMovieNULL);
            break;
        case 4:
            controller_mapRaiting(listMovieNULL);
            controller_ListMovie(listMovieNULL);
            break;
        case 5:
            break;
        case 6:
            ll_sort(listMovieNULL,movie_sortGeneroxRaiting,1);
            controller_ListMovie(listMovieNULL);
            break;
        case 7:
            controller_SaveAsText("ListaGuardada.csv",listMovieNULL);
            break;
        case 8:
            break;
        default:
            printf("Opcion Invalida\n");
            break;
        }
    }
    while(option!=4);
    return 0;
}
