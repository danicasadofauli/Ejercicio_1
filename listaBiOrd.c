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
    int elemento;

    if(lista.pdi == lista.pri || lista.pdi == lista.ult){
        //valor indefinido de error
        elemento = -1;
        printf("\nError al consultar valor");
    }

    else {
        elemento = lista.pdi -> elemento;
    }

    return elemento;
}

void LISTABIORD_elimina(ListaBi *list){
    Nodo *aux;

    // Error lista vacía
    if(lista -> pdi == lista -> pri || lista -> pdi = lista -> ult){
        printf("\nError al eliminar elemento");
    }

    else {
        aux = lista -> pdi;  // Guarda dirección del elemento que queremos eliminar
        aux -> ant -> sig = aux -> sig;
        aux -> sig -> ant = aux -> ant;
        lista -> pdi = lista -> pdi -> sig;
        free(aux);  //Elimina elemento
    }
}

void LISTABIORD_avanza (ListaBi *list){
    if (lista -> pdi == lista -> ult){
        printf("Error al avanzar en la lista");
    }
    else {
        lista -> pdi = lista-> pdi -> sig;
    }
}

void LISTABIORD_retrocede (ListaBi *list){
    if (lista -> pdi == lista -> pri){
        printf("Error al retroceder en la lista");
    }
    else {
        lista -> pdi = lista-> pdi -> ant;
    }
}

void LISTABIORD_vesInicio (ListaBi *list){
    lista -> pdi = lista -> pri -> sig;
}

void LISTABIORD_vesFinal (ListaBi *list){
    lista -> pdi = lista -> ult -> ant;
}

int LISTABIORD_inicio (ListaBi list){

}

int LISTABIORD_final (ListaBi list){

}

void LISTABIORD_destruye (ListaBi *list){
    
}

