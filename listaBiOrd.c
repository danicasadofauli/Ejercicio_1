#include "listaBiOrd.h"

ListaBiOrd LiSTABIORD_crea(){
    ListaBiOrd list;

    list.pri = (Nodo *) malloc (sizeof(Nodo));  // Creamos primer nodo fantasma

    if (list.pri == NULL){  // Error creación primer nodo
        printf("\nError");
    }
    else {
        list.ult = (Nodo *) malloc (sizeof(Nodo)); // Creamos segundo nodo fantasma

        if(list.pri == NULL){   //Error creación segundo nodo
            free(list.pri);
            list.pdi == NULL;
            printf("\nError");
        }
        else {
            //Nodos se autoapuntan y punteros de concatenación se dejan vacíos
            list.pri -> sig = list.ult;
            list.pri -> ant = NULL;
            list.ult -> sig = NULL;
            list.pdi = list.ult;
        }
    }

    return list;
}

void LISTABIORD_insertaOrd(ListaBiOrd *list, int elemento){

}

int LISTABIORD_consulta(ListaBiOrd list){

}

void LISTABIORD_elimina(ListaBi *list){

}

void LISTABIORD_avanza (ListaBi *list){

}

void LISTABIORD_retrocede (ListaBi *list){

}

void LISTABIORD_vesInicio (ListaBi *list){

}

void LISTABIORD_vesFinal (ListaBi *list){

}

int LISTABIORD_inicio (ListaBi list){

}

int LISTABIORD_final (ListaBi list){

}

void LISTABIORD_destruye (ListaBi *list){
    
}

