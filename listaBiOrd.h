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

