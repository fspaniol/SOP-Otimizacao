//
//  main.c
//  SOP Otimizacao
//
//  Created by Fernando Spaniol and Isadora Possebon on 10/9/16.
//  Copyright © 2016 Fernando Spaniol, Isadora Possebon. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "tour.h"

#define taxa_mutacao 20


int main(int argc, const char * argv[]) {
    //printf("Insira o seu input: \n");
    
    clock_t begin = clock();
    
    if (argc != 4){ // Se não recebe os argumentos
        puts("Erro!");
        puts("Voce deve informar 3 valores!");
        puts("1 - Tamanho da populacao");
        puts("2 - Tamanho do torneio");
        puts("3 - Quantidade de iteracoes");
        return 0; // termina o programa
    }
    
    int tamanho_populacao = atoi(argv[1]);
    int tamanho_torneio = atoi(argv[2]);
    int quantidade_iteracoes = atoi(argv[3]);
    
    
    if (tamanho_populacao <= tamanho_torneio){ // Se torneio for igual ou maior que populacao, da erro
        puts("O tamanho da populacao deve ser maior que o tamanho do torneio!");
        return 0;
    }
    
    char string[100];
    int x, y;
    int quantidade_cidades;
    int melhor;
    
    for (x = 0; x < 7; x++){
        gets(string);
    }
    
    //printf("Chegamos ao final dos requerimentos \n");
    
    scanf("%d", &quantidade_cidades); // LE DO STDIN QUANTAS CIDADES SERAO VISITADAS
    //printf("Quantidade cidades: %d\n", quantidade_cidades);
    
    int distancias[quantidade_cidades * quantidade_cidades]; // Distancias contem as distancias entre as cidades
    int tours_atuais[quantidade_cidades * tamanho_populacao]; // tours_atuais contem a populacao
    int fitness[tamanho_populacao]; // fitness[x] contem o fitness to tour_atual[x*tamanho_populacao,x*(tamanho_populacao+1)-1]
    int tours_filho[quantidade_cidades * tamanho_populacao];
    int melhor_fitness=10000000;
    int tour_melhor_fitness[quantidade_cidades];
    
    
    for(x = 0; x < quantidade_cidades; x++){
        for(y = 0; y < quantidade_cidades; y++){
            //puts("O que faltou?");
            scanf("%d", &distancias[x * quantidade_cidades + y]); // PREENCHE A MATRIZ
            //printf("%d\t", distancias[x * quantidade_cidades + y]);
        }
    }
    
    gets(string); // TIRAR O EOF DO STDIN
    
    for(x=0;x<tamanho_populacao;x++){
        criarTour(&tours_atuais[x*quantidade_cidades], quantidade_cidades);
        //imprimirTour(&tours_atuais[x * quantidade_cidades], quantidade_cidades, x);
    }
    
    // aqui começa o processo de algoritmo genetico
    int pai, mae; // Seleciona os pais da nova população
    int contador;
    
    for(contador = 0; contador<quantidade_iteracoes;contador++){
        melhor = calculaFitnessPopulacao(distancias, quantidade_cidades, tours_atuais, fitness, tamanho_populacao);
        if (fitness[melhor] < melhor_fitness){
            //printf("O antigo melhor era: %d, o novo eh: %d\n", melhor_fitness, fitness[melhor]);
            melhor_fitness = fitness[melhor];
            copiar(&tour_melhor_fitness[0],&tours_atuais[melhor*quantidade_cidades],quantidade_cidades);
        }
    
        pai = torneio(tamanho_populacao, tamanho_torneio, fitness);
        mae = pai;
        while (pai == mae){
            mae = torneio(tamanho_populacao, tamanho_torneio,fitness);
        }
    
        for (x = 0; x<tamanho_populacao;x++){ // preenche o vetor do filho
            crossover(&tours_atuais[pai * quantidade_cidades],&tours_atuais[mae * quantidade_cidades], &tours_filho[x*quantidade_cidades], quantidade_cidades);
            //imprimirTour(&tours_filho[x*quantidade_cidades],quantidade_cidades,x);
            mutacao(&tours_filho[x*quantidade_cidades],quantidade_cidades,taxa_mutacao);
        }
    
        copiar(&tours_atuais[0],&tours_filho[0], tamanho_populacao*quantidade_cidades); // atualiza o vetor oficial com o resultado do crossover
        
        
    }
    
    printf("O melhor tour teve fitness: %d\n", melhor_fitness);
    imprimirTour(tour_melhor_fitness,quantidade_cidades,1);
   // imprimirDistancias(tour_melhor_fitness,quantidade_cidades,distancias);
    
    clock_t end = clock();
    double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    
    printf("The time spent was %f seconds\n", time_spent);
    return 0;
}
