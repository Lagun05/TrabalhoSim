#ifndef GERADOR_H
#define GERADOR_H

extern double seed;
extern int lambda;

void init_seed();
double uni_generator();
double exp_generator();
void gera_fregues(double, int);

#endif
