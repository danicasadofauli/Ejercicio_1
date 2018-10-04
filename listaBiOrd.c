#include "listaBiOrd.h"

ListaBiOrd LiSTABIORD_crea(){
    ListaBiOrd list;

    list.pri = (Nodo *) malloc (sizeof(Nodo));  // Creamos primer nodo fantasma

    if (list.pri == NULL){  // Error creación primer nodo
        printf("\nError al crear lista");
    }
    else {
        list.ult = (Nodo *) malloc (sizeof(Nodo)); // Creamos segundo nodo fantasma

        if(list.pri == NULL){   //Error creación segundo nodo
            free(list.pri);
            list.pdi == NULL;
            printf("\nError al crear lista");
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
    Nodo *aux;
    int stop = 0;

    aux = (Nodo *) malloc (sizeof(Nodo));   // Creamos Nodo nuevo elemento

    if (aux == NULL){
        printf("\nError al insertar elemento");
    }
    else {

        //Asignamos valores y direcciones a nuevo nodo
        aux -> elemento = elemento;
        lista -> pdi = lista -> pri -> sig;

        //Bucle para encontrar valor en lista con elemento mayor al elemento introducido por el usuario o lista vacía
        //Se le asigna PDI a esta posicion
        while(lista -> pdi -> sig != NULL && !stop){

            if(lista -> pdi -> elemento < elemento){
                lista -> pdi = lista -> pdi -> sig;
            }
            else {
                stop = 1;
            }
        }

        // Se inserta el nuevo nodo delante del PDI
        aux -> sig = lista -> pdi;
        aux -> ant = lista -> pdi -> ant;
        lista -> pdi -> ant -> sig = aux;
        lista -> pd -> ant = aux;

    }
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

