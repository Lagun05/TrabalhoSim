#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <math.h>

#include "gerador.h"

double seed;
int lambda;

void init_seed() {
	srand(seed);
}

double uni_generator(){

    double valor;

    valor = (rand()%100); 
    valor = valor/100;
    
    return valor;

}

double exp_generator() {

    double time;
    
    time = uni_generator(seed);
    time = log(time)/(-lambda);

    return time;

}

void gera_fregues(double time, int id) {

    sleep(time);
    
    printf("Fregues chegou em %lf segundos\n", time);
    printf("ID do fregues: %d\n", id);
        
}
