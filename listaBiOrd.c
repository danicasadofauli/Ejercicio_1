#include "listaBiOrd.h"

/*********************************************************************************************************************
*
* @Finalidad: Crea una nueva lista bidireccional ordenada vacía para que el usuario pueda rellenar posteriormente
* @Parametros: xxxxxxx
* @Retorno: Devuelve la lista vacía creada
*
**********************************************************************************************************************/

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

/*********************************************************************************************************************
*
* @Finalidad: Inserta un elemento de valor entero que el usuario determine dentro de la lista de forma que esté
*             ordenado de menor a mayor
* @Parametros:	*list = puntero que contiene la dirección donde se encuentra la lista bidireccional ordenada
*				elemento = variable entera que el usuario quiere insertar en la lista
* @Retorno: xxxxxxxxx
*
**********************************************************************************************************************/

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

/*********************************************************************************************************************
*
* @Finalidad: Devuelve el elemento que se encuentre en el nodo al que apunta la PDI de la lista
* @Parametros:	list = estructura de punteros que apuntan a diferentes nodos principales de la lista (principio,
*               final y PDI)
* @Retorno: Devuelve el valor del elemento consultado (elemento en PDI)
*
**********************************************************************************************************************/

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

/*********************************************************************************************************************
*
* @Finalidad: Elimina de la lista el nodo al que PDI esté apuntando
* @Parametros:	*list = puntero que contiene la dirección donde se encuentra la lista bidireccional ordenada
* @Retorno: xxxxxxxxx
*
**********************************************************************************************************************/

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

/*********************************************************************************************************************
*
* @Finalidad: Mueve el puntero PDI a la casilla siguiente de la lista con respecto a la que se encuentra.
* @Parametros:	*list = puntero que contiene la dirección donde se encuentra la lista bidireccional ordenada
* @Retorno: xxxxxxxxx
*
**********************************************************************************************************************/

void LISTABIORD_avanza (ListaBi *list){
    if (lista -> pdi == lista -> ult){
        printf("Error al avanzar en la lista");
    }
    else {
        lista -> pdi = lista-> pdi -> sig;
    }
}

/*********************************************************************************************************************
*
* @Finalidad: Mueve el puntero PDI a la casilla anterior de la lista con respecto a la que se encuentra.
* @Parametros:	*list = puntero que contiene la dirección donde se encuentra la lista bidireccional ordenada
* @Retorno: xxxxxxxxx
*
**********************************************************************************************************************/

void LISTABIORD_retrocede (ListaBi *list){
    if (lista -> pdi == lista -> pri){
        printf("Error al retroceder en la lista");
    }
    else {
        lista -> pdi = lista-> pdi -> ant;
    }
}

/*********************************************************************************************************************
*
* @Finalidad: Mueve el puntero PDI a la primera casilla de la lista (no fantasma)
* @Parametros:	*list = puntero que contiene la dirección donde se encuentra la lista bidireccional ordenada
* @Retorno: xxxxxxxxx
*
**********************************************************************************************************************/

void LISTABIORD_vesInicio (ListaBi *list){
    lista -> pdi = lista -> pri -> sig;
}

/*********************************************************************************************************************
*
* @Finalidad: Mueve el puntero PDI a la última casilla de la lista (no fantasma)
* @Parametros:	*list = puntero que contiene la dirección donde se encuentra la lista bidireccional ordenada
* @Retorno: xxxxxxxxx
*
**********************************************************************************************************************/

void LISTABIORD_vesFinal (ListaBi *list){
    lista -> pdi = lista -> ult -> ant;
}

/*********************************************************************************************************************
*
* @Finalidad: Mueve el puntero PDI a la primera casilla de la lista (no fantasma). Usado para finalizar recorridos
*             por la lista de final a principio.
* @Parametros:	list = estructura de punteros que apuntan a diferentes nodos principales de la lista (principio,
*               final y PDI)
* @Retorno: Cierto (1) si PDI se encuentra en la primera casilla fantasma, falso (0) si no
*
**********************************************************************************************************************/

int LISTABIORD_inicio (ListaBi list){
    return lista.pdi == lista.pri;
}

/*********************************************************************************************************************
*
* @Finalidad: Mueve el puntero PDI a la última casilla de la lista (no fantasma). Usado para finalizar recorridos
*             por la lista de principio a final.
* @Parametros:	list = estructura de punteros que apuntan a diferentes nodos principales de la lista (principio,
*               final y PDI)
* @Retorno: Cierto (1) si PDI se encuentra en la primera casilla fantasma, falso (0) si no
*
**********************************************************************************************************************/

int LISTABIORD_final (ListaBi list){
    return  lista.pdi == lista.ult;
}

/*********************************************************************************************************************
*
* @Finalidad: Destruye la lista al completo, haciendola inutilizable de nuevo y perdiéndose todos sus datos.
* @Parametros:	*list = puntero que contiene la dirección donde se encuentra la lista bidireccional ordenada
* @Retorno: xxxxxxxxx
*
**********************************************************************************************************************/

void LISTABIORD_destruye (ListaBi *list){
    Nodo *aux;

    while (lista -> pri != NULL){
        aux = lista -> pri;     //Se asigna la dirección de pri a aux para guardar direccion
        lista -> pri = lista -> pri -> sig;     //Avanzamos pri al sigueinte elemento
        free(aux);  //Eliminamos el nodo que habíamos guardado en aux
    }

    lista -> ult = NULL;
    lista -> pdi = NULL;
}

