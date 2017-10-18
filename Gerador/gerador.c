#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "gerador.h"

double uni_generator(unsigned int seed){

    double valor;

    srand(seed);
    valor = (rand()%100); 
    valor = valor/100;
    printf("valor uniforme = %lf\n", valor);
    return valor;

}

double exp_generator(unsigned int seed, int lambda) {

    double valor;
    
    valor = uniform_generator(seed);
    valor = log(valor)/(-lambda);

    return valor;

}
