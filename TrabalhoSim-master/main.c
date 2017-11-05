/* ARQUIVO SÓ PRA TESTE, NÃO É FINAL */
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#include "src/fila/fila.h"
#include "src/gerador/gerador.h"
#include "src/thread/thread.h"

void menu();
void mudar_lambda();
void mudar_seed();
int add_f(int);
void rm_f();
void sim();

int main() {

	fila_1 = malloc(sizeof(fila_t));
	fila_2 = malloc(sizeof(fila_t));

	fila_1 = init();
	fila_2 = init();

	seed = 100;
	lambda = 1;

	menu();

	free(fila_1);
	free(fila_2);

	return 0;	

}

void menu() {

	char escolha;
	int continua = 1;
	int id = 0;

	while(1) {

		if(continua == 0) break;

		printf("----------------------------\n");
		printf("1 - Mudar lambda\n");
		printf("2 - Mudar seed\n");
		printf("3 - Adicionar fregues\n");
		printf("4 - Remover fregues\n");
		printf("5 - Mostrar Fila\n");
		printf("6 - Iniciar simulacao\n");
		printf("7 - Sair\n");
		printf("----------------------------\n");

		scanf(" %c", &escolha);

		switch(escolha) {
			case '1':
				mudar_lambda();
				break;
			case '2':
				mudar_seed();
				break;
			case '3':
				id = add_f(id);
				break;
			case '4':
				rm_f();
				break;
			case '5':
				print(fila_1);
				break;
			case '6':
				sim(id);
				break;
			case '7':
				continua = 0;
				break;
			default:
				break;
		}
		printf("\n");
	}
}

void mudar_lambda() {

	printf("Novo lambda: ");
	scanf(" %d", &lambda);

}
void mudar_seed() {

	printf("Nova seed: ");
	scanf(" %lf", &seed);

	init_seed();
	
	printf("Valor uniforme: %lf\n", uni_generator());
	printf("Valor exp: %lf\n", exp_generator());

}

int add_f(int id) {

	fregues_t fregues;
	fregues.id_fregues = id++;
	fregues.fila = 1;
	add(fregues, fila_1);

	return id;
}

void rm_f() {

	remover(fila_1);
	
}

void sim() {

	cria_threads();

}
