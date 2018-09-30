#ifndef _LISTABIORD_H_
#define _LISTABIORD_H_

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
void LISTABIORD_elimina(ListaBi *list);
void LISTABIORD_avanza (ListaBi *list);
void LISTABIORD_retrocede (ListaBi *list);
void LISTABIORD_vesInicio (ListaBi *list);
void LISTABIORD_vesFinal (ListaBi *list);
int LISTABIORD_inicio (ListaBi list);
int LISTABIORD_final (ListaBi list);
void LISTABIORD_destruye (ListaBi *list);

#endif

