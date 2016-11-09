//
//  tour.c
//  SOP Otimizacao
//
//  Created by Fernando Spaniol and Isadora Possebon on 10/9/16.
//  Copyright © 2016 Fernando Spaniol, Isadora Possebon. All rights reserved.
//
#include "tour.h"
#include <stdlib.h> 
#include <time.h>
#include <unistd.h>

void imprimeTodasDistancias(int *vetor, int tamanho){
    int x,y;
    for(x = 0; x < tamanho; x++){
        for(y = 0; y < tamanho; y++){
            printf("%d ", vetor[x*tamanho + y]);
        }
        printf("\n");
    }
}

void imprimirDistancias(int *vetor, int tamanho, int *distancias){
    int x;
    for(x = 0; x < tamanho-1; x++){
        printf("%d ", distancias[vetor[x] * tamanho + (vetor[x+1])]);
    }
    
    printf("\n");
}

void calculaFitness(int *distancias, int tamanho, int *cidades, int *fitness_parcial){
    int x;
    int aux;
    *fitness_parcial = 0;
    
    for(x = 0; x < tamanho-1; x++){
        aux = cidades[x];
         //printf("A distancia da cidade %d para a %d eh: %d \n", cidades[x], cidades[x+1], distancias[aux * tamanho + (cidades[x+1])]);
        if (distancias[aux * tamanho + (cidades[x+1])] == -1)
            //*fitness_parcial += (distancias[aux * tamanho + (cidades[x+1])] * 100);
            *fitness_parcial += 10000; // Caso o caminho seja não valido, de uma distancia bem grande
        else
            *fitness_parcial += distancias[aux * tamanho + (cidades[x+1])]; // Calcula a distancia de uma cidade para a próxima
    }
    
    //*fitness_parcial += distancias[x * tamanho + (cidades[0])]; // será que precisa?
}

int calculaFitnessPopulacao(int *distancias, int tamanho, int *cidades, int *fitness, int tamanho_populacao){
    int x;
    int melhor = 10000000;
    int indice_melhor;
    for(x=0;x<tamanho_populacao;x++){
        calculaFitness(distancias,tamanho,&cidades[x*tamanho], &fitness[x]);
        //printf("O fitness do %d eh: %d \n", x, fitness[x]);
        /*if(fitness[x] != 0){
            printf("O fitness do %d eh: %d \n", x, fitness[x]);
            imprimirDistancias(&cidades[x*tamanho], tamanho, distancias);
        }*/
        if(melhor > fitness[x]){
            melhor = fitness[x];
            indice_melhor = x;
        }
    }
    //printf("O fitness do %d eh: %d \n", indice_melhor, melhor);
    //imprimirTour(&cidades[indice_melhor*tamanho],tamanho,indice_melhor);
    //imprimirDistancias(&cidades[indice_melhor*tamanho], tamanho, distancias);
    
    return indice_melhor;
}

void criarTour(int *vetor, int tamanho){
    int x;
    
    vetor[0] = 0;
    vetor[tamanho-1] = tamanho-1; // Preenche as matrizes em [1,tamanho-2], porque as primeira e ultima posições já são pré-definidas
    
    for (x = 1; x<tamanho-1; x++){
        vetor[x] = x;
    }
    randomize(&vetor[1],tamanho-2);
}

void swap (int *a, int *b) // faz o swap entre duas posicoes
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void randomize ( int *vetor, int n )
{
    srand(time(NULL) + clock());
    
    for (int i = n-1; i > 0; i--)
    {
        // Pick a random index from 0 to i
        int j = rand() % (i+1);
        
        // Swap arr[i] with the element at random index
        swap(&vetor[i], &vetor[j]);
    }
}

void imprimirTour(int *vetor, int tamanho, int numero){
    int x;
    
    printf("Tour %d: ", numero); // Informa qual tour
    
    for (x = 0; x<tamanho; x++){
        printf("%d ", vetor[x]); // Imprime qual a cidade da posicao x do tour
    }
    printf("\n");
}

int torneio(int populacao, int participantes, int *fitness){
    
    srand(time(NULL) + clock()); // seed o aleatorio
    
    int x, maior=1000000,index_maior, temp;
    int vetor[participantes];
    int usados[populacao];
    
    for(x = 0; x<populacao;x++){
        usados[x] = 0;
    }
    
    for(x = 0; x<participantes;x++){ // preenche a matriz com participantes, mesmo que sejam repetidos
        temp = rand() % populacao;
        while(usados[temp] == 1){
            temp = rand() % populacao;
        }
        vetor[x] = temp;
        usados[temp] = 1;
        //printf("Participante %d: %d, seu fitness: %d\n", x,temp, fitness[temp]);
    }
    
    for(x=0; x<participantes; x++){ // calcula o vencedor
        if(fitness[vetor[x]] < maior){
            maior = fitness[vetor[x]];
            index_maior = vetor[x];
        }
    }
    //printf("O melhor foi o %d com fitness: %d\n", index_maior, maior); // anuncia o vencedor
    
    return index_maior;
}


















