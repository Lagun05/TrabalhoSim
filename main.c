//ARQUIVO SÓ PRA TESTE, NÃO É FINAL
#include <stdio.h>
#include <stdlib.h>

#include "src/fila/fila.h"
#include "src/gerador/gerador.h"

void menu(fila_t *fila);
void mudar_seed();
int add_f(fila_t*, int);
void rm_f(fila_t*);

void main() {

	fila_t *fila = malloc(sizeof(fila_t));
	init();

	menu(fila);

}

void menu(fila_t *fila) {

	char escolha;
	int continua = 1;
	int id = 0;

	while(1) {

		if(continua == 0) break;

		printf("----------------------------\n");
		printf("1 - Mudar seed\n");
		printf("2 - Adicionar fregues\n");
		printf("3 - Remover fregues\n");
		printf("4 - Mostrar Fila\n");
		printf("5 - Sair\n");
		printf("----------------------------\n");

		scanf(" %c", &escolha);

		switch(escolha) {
			case '1':
				mudar_seed();
				break;
			case '2':
				id = add_f(fila, id);
				break;
			case '3':
				rm_f(fila);
				break;
			case '4':
				print(fila);
				break;
			case '5':
				continua = 0;
				break;
			default:
				break;
		}
		printf("\n");
	}
}

void mudar_seed() {

	int seed;
	double valor;

	printf("Nova seed: ");
	scanf(" %d", &seed);

	valor = uni_generator(seed);
	printf("Valor uniforme: %lf\n", valor);
	
	valor =exp_generator(seed, 1);
	printf("Valor exp: %lf\n", valor);

}

int add_f(fila_t *fila, int id) {

	fregues_t fregues;
	fregues.id_fregues = id++;
	fregues.fila = 1;
	add(fregues, fila);

	return id;
}

void rm_f(fila_t *fila) {

	fregues_t fregues;
	fregues = remover(fila);

}

