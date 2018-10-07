#ifndef _LLISTA_H_
#define _LLISTA_H_

typedef struct N {
    int elemento;
    struct N *sig;
    struct N *ant;
} Nodo;

typedef struct {
    Nodo *pri;
    Nodo *ult;
    Nodo *pdi
} ListaBiOrd;

ListaBiOrd LiSTABIORD_crea();
void LISTABIORD_insertaOrd(ListaBiOrd *list, int elemento);
int LISTABIORD_consulta(ListaBiOrd list);
void LISTABIORD_elimina(ListaBiOrd *list);
void LISTABIORD_avanza (ListaBiOrd *list);
void LISTABIORD_retrocede (ListaBiOrd *list);
void LISTABIORD_vesInicio (ListaBiOrd *list);
void LISTABIORD_vesFinal (ListaBiOrd *list);
int LISTABIORD_inicio (ListaBiOrd list);
int LISTABIORD_final (ListaBiOrd list);
void LISTABIORD_destruye (ListaBiOrd *list);

#endif

