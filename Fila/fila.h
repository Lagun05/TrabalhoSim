#ifndef FILA_H
#define FILA_H

//estrutura do fregues
typedef struct fregues_s {

    int id_fregues;
    int fila; //1 para fila 1, 2 para fila 2, 0 em nenhuma fila
    int xr; //etapa do servico que ele estava quando foi interrompido, 0 se não está interrompido
    double tempo_espera_1; //tempo que esperou na fila 1
    double tempo_espera_2; //tempo que esperou na fila 2
    double tempo_serv_1; //tempo que gastou em servico 1
    double tempo_serv_2; //tempo que gastou em servico 2
    
}fregues_t;

//estrutura da fila
typedef struct fila_s {
    
    fregues_t fregues;
    fila_s *prox;

} fila_t;


//funções da fila
void init();
void add(fregues_t, fila_t*);
void remove(fregues_t, fila_t*);

//variaves essenciais
extern fila_t *fila1_head; //nó cabeça da fila 1
extern fila_t *fila2_head; //nó cabeça da fila 2

#endif

#include <stdio.h>
#include <stdlib.h>

#include "fila.h"
