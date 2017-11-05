#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#include "thread.h"
#include "../gerador/gerador.h"
#include "../fila/fila.h"

pthread_t thread_fila, thread_servidor;
pthread_mutex_t mutex;
pthread_cond_t sem;
int flag = 0;

void *fun_fila() {

	int i;
	double time;
	int id = 0;
	fregues_t fregues;

	//inicializa seed
	init_seed();

	//loop principal
	for(i = 0; i < 5; i++) {

		//espera um fregues
		time = exp_generator();
		gera_fregues(time, id);
		printf("Fila: Fregues %d chegou apos %lf!\n", id, time);

		//preenche os dados do fregues
		fregues.id_fregues = id;
		fregues.fila = 1;
		fregues.xr = 0;

		//coloca o fregues na fila e envia o sinal para o servidor
		pthread_mutex_lock(&mutex);
		add(fregues, fila_1);
		printf("Fila: Fregues %d entrou na fila 1\n", fregues.id_fregues);
		pthread_cond_broadcast(&sem);
		pthread_mutex_unlock(&mutex);
		id++;
	}

	//muda a flag para avisar o servidor que acabaram de chegar clientes
	flag = 1;

	pthread_exit(NULL);

}

void *fun_servidor() {

	int i;
	fregues_t fregues;

	//loop principal
	while(1) {

		pthread_mutex_lock(&mutex);

		//loop de controle(verifica se ha algum cliente para ser atendido)
		while(fila_1->prox == NULL && fila_2->prox == NULL) {
			pthread_cond_wait(&sem, &mutex);
		}

		//retira o cliente da fila, com prioridade para fila 1
		if(fila_1->prox != NULL) {
			fregues = remover(fila_1);
		}
		else {
			fregues = remover(fila_2);
		}

		pthread_mutex_unlock(&mutex);

		//atende o fregues
		printf("Servidor: atendendo fregues %d...\n", fregues.id_fregues);

		//loop que simula o tempo de atendimento
		for(i = fregues.xr; i < 1000; i++) {
			fregues.xr = i;
		
			//se fregues for da fila 2 e houver alguem esperando na fila 1, interrompe
			pthread_mutex_lock(&mutex);
			if(fregues.fila == 2 && fila_1->prox != NULL) {
				printf("Tem fregues esperando na fila 1, interrompendo %d na etapa %d...\n", fregues.id_fregues, i);
				add_primeiro(fregues,fila_2);
				pthread_mutex_unlock(&mutex);
				break;
			}
			pthread_mutex_unlock(&mutex);
		}
		if(fregues.xr == 100000000) printf("Servidor: fregues %d atendido!\n", fregues.id_fregues);

		//caso o fregues tenha vindo da fila 1, passa pra fila 2
		pthread_mutex_lock(&mutex);
		if(fregues.fila == 1) {
			fregues.fila = 2;
			add(fregues, fila_2);
			printf("Fregues %d foi pra fila 2\n", fregues.id_fregues);
		}
		pthread_mutex_unlock(&mutex);

		if(fila_1->prox == NULL && fila_2->prox == NULL && flag == 1) break;

	}

	pthread_exit(NULL);

}

//funcao para criar as threads
void cria_threads() {

	//inicia semaforo e exclusao mutua
	pthread_mutex_init(&mutex, NULL);
	pthread_cond_init(&sem, NULL);

	//cria as threads
	pthread_create(&thread_fila, NULL, fun_fila, NULL);
	pthread_create(&thread_servidor, NULL, fun_servidor, NULL);

	//aguarda as threads
	pthread_join(thread_fila, NULL);
	pthread_join(thread_servidor, NULL);

	//destroi semaforo e exclusao mutua
	pthread_mutex_destroy(&mutex);
	pthread_cond_destroy(&sem);

}
