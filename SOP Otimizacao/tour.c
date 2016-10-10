//
//  tour.c
//  SOP Otimizacao
//
//  Created by Fernando Spaniol on 10/9/16.
//  Copyright © 2016 Fernando Spaniol. All rights reserved.
//

#include "tour.h"
#include <stdlib.h> 
#include <time.h>
#include <unistd.h>

void imprimeTour(int *vetor, int tamanho){
    int x,y;
    for(x = 0; x < tamanho; x++){
        for(y = 0; y < tamanho; y++){
            printf("%d ", vetor[x*tamanho + y]);
        }
        printf("\n");
    }
}

int calculaFitness(int *distancias, int tamanho, int *cidades){
    int x, soma=0;
    int aux;
    
    for(x = 0; x < tamanho; x++){
        aux = cidades[x];
         //printf("A distancia da cidade %d para a %d eh: %d \n", cidades[x], cidades[x+1], distancias[aux * tamanho + (cidades[x+1])]);
        if (distancias[aux * tamanho + (cidades[x+1])] == -1) return 0;
        soma += distancias[aux * tamanho + (cidades[x+1])]; // Calcula a distancia de uma cidade para a próxima
    }
    
    soma += distancias[x * tamanho + (cidades[0])];
    
    return soma;
}

int* calculaFitnessPopulacao(int *distancias, int tamanho, int *cidades, int *fitness, int tamanho_populacao){
    int x;
    for(x=0;x<tamanho_populacao;x++){
        fitness[x] = calculaFitness(distancias,tamanho,&cidades[x*tamanho]);
        if(fitness[x] != 0)
            printf("O fitness do %d eh: %d \n", x, fitness[x]);
    }
    return fitness;
}

void criarTour(int *vetor, int tamanho){
    int x;
    
    for (x = 0; x<tamanho; x++){
        vetor[x] = x;
    }
    sleep(1);
    randomize(vetor,tamanho);
    imprimirTour(vetor, tamanho);
}

void swap (int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void randomize ( int *vetor, int n )
{
    srand(time(NULL));
    
    for (int i = n-1; i > 0; i--)
    {
        // Pick a random index from 0 to i
        int j = rand() % (i+1);
        
        // Swap arr[i] with the element at random index
        swap(&vetor[i], &vetor[j]);
    }
}

void imprimirTour(int *vetor, int tamanho){
    int x;
    
    for (x = 0; x<tamanho; x++){
        printf("%d ", vetor[x]);
    }
    printf("\n");
}

