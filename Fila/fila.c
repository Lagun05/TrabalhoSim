#include <stdio.h>
#include <stdlib.h>

#include "fila.h"

//inicializa as filas e variaveis
fila_t* init() {

	fila_t *fila_head;

	//inicializa nó cabeça da fila
  if (!(fila_head = malloc(sizeof(fila_t)))) {
  	printf("Nao ha memoria o suficiente\n");
    exit(-1);
  }
    
 	//não há primeiro elemento ainda
 	fila_head->prox = NULL;

	return fila_head;

}

//adiciona um novo elemento à lista
void add(fregues_t fregues, fila_t *fila) {     

	//aloca memoria para o novo elemento
  fila_t *novo_fregues;
  if(!(novo_fregues = malloc(sizeof(fila_t)))) {
 		printf("Nao ha memoria o suficiente\n");
    exit(-1);
  }
    
  //inicializa o novo elemento
  novo_fregues->fregues = fregues;
  novo_fregues->prox = NULL;
    
  //checa se a fila esta vazia, caso esteja, o novo elemento será o primeiro, caso haja elementos na fila, percorremos a fila até encontrar o último elemento
  if(fila->prox == NULL) {
  	fila->prox = novo_fregues;
  }
  else {
 		fila = fila->prox;
        
    while(fila->prox != NULL) {
    	fila = fila->prox;
    }
        
    fila->prox = novo_fregues;
	}

}

fregues_t remover(fila_t *fila) {

	fila_t *primeiro_fila;

	//aloca memória
	if (!(primeiro_fila = malloc(sizeof(fila_t)))) {
		printf("Nao ha memoria o suficiente\n");
	}

	//inicializa, o id fica -1 para o caso da fila estar vazia
	primeiro_fila->fregues.id_fregues = -1;
	primeiro_fila->prox = NULL;
	
  //verifica se a fila esta vazia, se não estiver remove o primeiro elemento, se estiver vazia, não faz nada
  if(fila->prox != NULL) {
  	primeiro_fila = fila->prox;
    fila->prox = primeiro_fila->prox;
  }
    
  return primeiro_fila->fregues;
}

void print(fila_t *fila) {

	if(fila->prox == NULL) return;

	printf("XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX\n");
	printf("----------------------FILA-----------------------\n");
	printf("XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX\n");
	while(fila->prox != NULL) {
		fila = fila->prox;
		printf("ID = %d\n", fila->fregues.id_fregues);
		printf("Fila = %d\n", fila->fregues.fila);
		//printf("Tempo de espera na fila 1: %lf\n", fila->fregues.tempo_espera_1);
		//printf("Tempo de espera na fila 2: %lf\n", fila->fregues.tempo_espera_2);
		//printf("Tempo do primeiro servico: %lf\n", fila->fregues.tempo_serv_1);
		//printf("Tempo do segundo servico:  %lf\n", fila->fregues.tempo_serv_2);
		printf("-------------------------------------------------\n");
	}

	printf("\n\n");
}
