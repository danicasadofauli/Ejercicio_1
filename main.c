#include <stdio.h>
#include "llista.h"

int main(){
    //int elemento;
    // int i;
    ListaBiOrd lista;

    LiSTABIORD_crea(&lista);
    printf("\n\nLista creada");
    printf("\n--------------------------------------------");

    // printf("\nInserte elementos en la lista. Introduzca el valor '0' para dejar de insertar elementos");
    LISTABIORD_insertaOrd(&lista, 5);
    LISTABIORD_insertaOrd(&lista, 9);
    LISTABIORD_insertaOrd(&lista, 1);
    LISTABIORD_insertaOrd(&lista, 6);
    LISTABIORD_insertaOrd(&lista, 3);

    printf("\n\nIntroducidos elementos aleatoriamente en el siguiente orden: 5, 9, 1, 6, y 3");
    printf("\n--------------------------------------------");

    LISTABIORD_vesInicio(&lista);

    while (!LISTABIORD_final(lista)){
        printf("\n%d", LISTABIORD_consulta(lista));
        LISTABIORD_avanza(&lista);
    }

    printf("\n\nOrdenados elementos de principio a fin");
    printf("\n--------------------------------------------");

    LISTABIORD_vesFinal(&lista);

    while (!LISTABIORD_inicio(lista)){
        printf("%d", LISTABIORD_consulta(lista));
        LISTABIORD_retrocede(&lista);
    }

    printf("\n\nOrdenados elementos de fin a principio");
    printf("\n--------------------------------------------");

    LISTABIORD_vesInicio(&lista);
    LISTABIORD_elimina(&lista);

    while (!LISTABIORD_final(lista)){
        printf("\n%d", LISTABIORD_consulta(lista));
        LISTABIORD_avanza(&lista);
    }

    printf("\n\nEliminado primer elemento de la lista (1)");
    printf("\n--------------------------------------------");


    LISTABIORD_destruye(&lista);

    printf("\n\nLista destruida\n");
}
