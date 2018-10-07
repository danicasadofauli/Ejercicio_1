#include "llista.h"

/*********************************************************************************************************************
*
* @Finalidad: Crea una nueva lista bidireccional ordenada vacía para que el usuario pueda rellenar posteriormente
* @Parametros: xxxxxxx
* @Retorno: Devuelve la lista vacía creada
*
**********************************************************************************************************************/

ListaBiOrd LISTABIORD_crea(){
    ListaBiOrd lista;

    lista.pri = (Nodo *) malloc (sizeof(Nodo));  // Creamos primer nodo fantasma

    if (lista.pri == NULL){  // Error creación primer nodo
        printf("\nError al crear lista");
    }
    else {
        lista.ult = (Nodo *) malloc (sizeof(Nodo)); // Creamos segundo nodo fantasma

        if(lista.pri == NULL){   //Error creación segundo nodo
            free(lista.pri);
            printf("\nError al crear lista");
        }
        else {
            //Nodos se autoapuntan y punteros de concatenación se dejan vacíos
            lista.pri -> sig = lista.ult;
            lista.pri -> ant = NULL;
            lista.pri -> elemento = -1;
            lista.ult -> sig = NULL;
            lista.ult -> elemento = -1;
            lista.pdi = lista.ult;
        }
    }

    return lista;
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

/*ListaBiOrd LISTABIORD_insertaOrd(ListaBiOrd lista, int elemento){
    int valor = -1;
    Nodo *aux;
    int stop = 0;

    aux = (Nodo *) malloc (sizeof(Nodo));   // Creamos Nodo nuevo elemento

    if (aux == NULL){
        printf("\nError al insertar elemento");
    }
    else {
        lista.pdi = lista.pri;
        //Asignamos valores y direcciones a nuevo nodo
        aux -> elemento = elemento;

        if (lista.pri -> sig == lista.ult){
          aux -> sig = lista.pdi -> sig;
          aux -> ant = lista.pdi;
          lista.pdi -> sig -> ant = aux;
          lista.pdi -> sig = aux;
        }

        else {

          LISTABIORD_avanza(&lista);

          while(!stop) {
            if(LISTABIORD_final(lista)){
              // Se inserta el nuevo nodo delante del PDI
              aux -> sig = lista.pdi;
              aux -> ant = lista.pdi -> ant;
              lista.pdi -> ant -> sig = aux;
              lista.pdi -> ant = aux;
              stop = 1;
            }

            else {
              if(valor < elemento){
                  //Bucle para encontrar valor en lista con elemento mayor al elemento introducido por el usuario o lista vacía
                valor = LISTABIORD_consulta(lista);
                printf(".-%d-\n", valor);
                printf(".-%d-.\n", elemento);
                LISTABIORD_avanza(&lista);
              }

              else {
                // Se inserta el nuevo nodo delante del PDI
                aux -> sig = lista.pdi;
                aux -> ant = lista.pdi -> ant;
                lista.pdi -> ant -> sig = aux;
                lista.pdi -> ant = aux;
                stop = 1;
              }

            }

          }

        }
    }

    return lista;
} */

ListaBiOrd LISTABIORD_insertaOrd(ListaBiOrd lista, int elemento){
    int valor = -1;
    Nodo *aux;
    int stop = 0;

    aux = (Nodo *) malloc (sizeof(Nodo));   // Creamos Nodo nuevo elemento

    if (aux == NULL){
        printf("\nError al insertar elemento");
    }
    else {
        lista.pdi = lista.pri;
        //Asignamos valores y direcciones a nuevo nodo
        aux -> elemento = elemento;
        
        if (lista.pri -> sig == lista.ult){
          aux -> sig = lista.pdi -> sig;
          aux -> ant = lista.pdi;
          lista.pdi -> sig -> ant = aux;
          lista.pdi -> sig = aux;
        }

        else {

          LISTABIORD_avanza(&lista);

          while(!stop) {
            if(LISTABIORD_final(lista) || elemento < valor){
              // Se inserta el nuevo nodo delante del PDI
              aux -> sig = lista.pdi;
              aux -> ant = lista.pdi -> ant;
              lista.pdi -> ant -> sig = aux;
              lista.pdi -> ant = aux;
              stop = 1;
            }

            else {
                  //Bucle para encontrar valor en lista con elemento mayor al elemento introducido por el usuario o lista vacía
                LISTABIORD_avanza(&lista);
                valor = LISTABIORD_consulta(lista);
            }



          }

        }


    }

    return lista;
}

/*********************************************************************************************************************
*
* @Finalidad: Devuelve el elemento que se encuentre en el nodo al que apunta la PDI de la lista
* @Parametros:	list = estructura de punteros que apuntan a diferentes nodos principales de la lista (principio,
*               final y PDI)
* @Retorno: Devuelve el valor del elemento consultado (elemento en PDI)
*
**********************************************************************************************************************/

int LISTABIORD_consulta(ListaBiOrd lista){
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

void LISTABIORD_elimina(ListaBiOrd *lista){
    Nodo *aux;

    // Error lista vacía
    if(lista -> pdi == lista -> pri || lista -> pdi == lista -> ult){
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

void LISTABIORD_avanza (ListaBiOrd *lista){
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

void LISTABIORD_retrocede (ListaBiOrd *lista){
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

void LISTABIORD_vesInicio (ListaBiOrd *lista){
    lista -> pdi = lista -> pri -> sig;
}

/*********************************************************************************************************************
*
* @Finalidad: Mueve el puntero PDI a la última casilla de la lista (no fantasma)
* @Parametros:	*list = puntero que contiene la dirección donde se encuentra la lista bidireccional ordenada
* @Retorno: xxxxxxxxx
*
**********************************************************************************************************************/

void LISTABIORD_vesFinal (ListaBiOrd *lista){
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

int LISTABIORD_inicio (ListaBiOrd lista){
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

int LISTABIORD_final (ListaBiOrd lista){
    return  lista.pdi == lista.ult;
}

/*********************************************************************************************************************
*
* @Finalidad: Destruye la lista al completo, haciendola inutilizable de nuevo y perdiéndose todos sus datos.
* @Parametros:	*list = puntero que contiene la dirección donde se encuentra la lista bidireccional ordenada
* @Retorno: xxxxxxxxx
*
**********************************************************************************************************************/

void LISTABIORD_destruye (ListaBiOrd *lista){
    Nodo *aux;

    while (lista -> pri != NULL){
        aux = lista -> pri;     //Se asigna la dirección de pri a aux para guardar direccion
        lista -> pri = lista -> pri -> sig;     //Avanzamos pri al sigueinte elemento
        free(aux);  //Eliminamos el nodo que habíamos guardado en aux
    }

    lista -> ult = NULL;
    lista -> pdi = NULL;
}
