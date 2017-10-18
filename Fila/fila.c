#include <stdio.h>
#include <stdlib.h>

#include "fila.h"

//inicializa as filas e variaveis
void init() {

    //inicializa nó cabeça da fila 1
    if (!(fila1_head = malloc(sizeof(fila_t))) {
        printf("Nao ha memoria o suficiente\n");
        exit(-1);
    }
    
    //inicializa nó cabeça da fila 2
    if (!(fila2_head = malloc(sizeof(fila_t))) {
        printf("Nao ha memoria o suficiente\n");
        exit(-1);
    }
    
    //não há primeiro elemento ainda
    fila1_head->prox = NULL;
    fila2_head->prox = NULL;

}
//adiciona um novo elemento à lista
void add(fregues_t fregues, fila_t *fila) {     

    //aloca memoria para o novo elemento
    fila_t *novo_elem;
    if(!(novo_elem = malloc(sizeof(fila_t))) {
        printf("Nao ha memoria o suficiente\n");
        exit(-1);
    }
    
    //inicializa o novo elemento
    novo_elem->fregues = fregues;
    novo_elem->prox = NULL;
    
    //checa se a fila esta vazia, caso esteja, o novo elemento será o primeiro
    if(fila->prox == NULL) {
        fila->prox = novo_elem;
    }
    //caso haja elementos na fila, percorremos a fila até encontrar o último elemento
    else {
        elemento *condutor = fila->prox;
        
        while(condutor->prox != NULL) {
            condutor = condutor->prox;
        }
        
        condutor->prox = novo_elem;
    }

}

fila_t remove(fila_t *fila) {

    //verifica se a fila esta vazia, se não estiver remove o primeiro elemento, se estiver vazia, não faz nada
    if(fila->prox != NULL) {
        elemento *condutor = fila->prox
        fila->prox = condutor->prox;
    }
    
    return condutor;
}
