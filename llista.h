#ifndef _LLISTA_H_
#define _LLISTA_H_

#include <stdio.h>
#include <stdlib.h>

typedef struct N {
    int elemento;
    struct N *sig;
    struct N *ant;
} Nodo;

typedef struct {
    Nodo *pri;
    Nodo *ult;
    Nodo *pdi;
} ListaBiOrd;

ListaBiOrd LISTABIORD_crea();
ListaBiOrd LISTABIORD_insertaOrd(ListaBiOrd lista, int elemento);
int LISTABIORD_consulta(ListaBiOrd lista);
void LISTABIORD_elimina(ListaBiOrd *lista);
void LISTABIORD_avanza (ListaBiOrd *lista);
void LISTABIORD_retrocede (ListaBiOrd *lista);
void LISTABIORD_vesInicio (ListaBiOrd *lista);
void LISTABIORD_vesFinal (ListaBiOrd *lista);
int LISTABIORD_inicio (ListaBiOrd lista);
int LISTABIORD_final (ListaBiOrd lista);
void LISTABIORD_destruye (ListaBiOrd *lista);

#endif
