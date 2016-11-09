//
//  tour.h
//  SOP Otimizacao
//
//  Created by Fernando Spaniol on 10/9/16.
//  Copyright © 2016 Fernando Spaniol. All rights reserved.
//

#ifndef tour_h
#define tour_h

#include <stdio.h>
#include <stdlib.h> 
#include <time.h>

void imprimeTodasDistancias(int *vetor, int tamanho);
void imprimirDistancias(int *vetor, int tamanho, int *distancias);
void calculaFitness(int *distancias, int tamanho, int *cidades, int *fitness_parcial);
int calculaFitnessPopulacao(int *distancias, int tamanho, int *cidades, int *fitness, int tamanho_populacao);
void criarTour(int *vetor, int tamanho);
void imprimirTour(int *vetor, int tamanho, int numero);
void swap (int *a, int *b);
void randomize(int *vetor, int n );
int torneio(int populacao, int participantes, int *fitness);

#endif /* tour_h */
