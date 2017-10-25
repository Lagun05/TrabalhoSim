/* ARQUIVO SÓ PRA TESTE, NÃO É FINAL */
#include <stdio.h>
#include <stdlib.h>

#include "src/fila/fila.h"
#include "src/gerador/gerador.h"

void menu(fila_t *fila);
void mudar_lambda();
void mudar_seed();
int add_f(fila_t*, int);
void rm_f(fila_t*);

int main() {

	fila_t *fila = malloc(sizeof(fila_t));
	init();
	lambda = 1;

	menu(fila);

	return 0;	

}

void menu(fila_t *fila) {

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
		printf("6 - Sair\n");
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
				id = add_f(fila, id);
				break;
			case '4':
				rm_f(fila);
				break;
			case '5':
				print(fila);
				break;
			case '6':
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

int add_f(fila_t *fila, int id) {

	fregues_t fregues;
	fregues.id_fregues = id++;
	fregues.fila = 1;
	add(fregues, fila);

	return id;
}

void rm_f(fila_t *fila) {

	remover(fila);
	

}

