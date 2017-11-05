#ifndef THREAD_H
#define THREAD_H

//variaveis das threads
extern pthread_t thread_fila, thread_servidor;
extern pthread_mutex_t mutex;
extern pthread_cond_t sem;

//funções das threads
void *fun_fila();
void *fun_servidor();
void cria_threads();

#endif
