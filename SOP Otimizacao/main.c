//
//  main.c
//  SOP Otimizacao
//
//  Created by Fernando Spaniol and Isadora Possebon on 10/9/16.
//  Copyright © 2016 Fernando Spaniol, Isadora Possebon. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include "tour.h"

#define tamanho_populacao 32
#define tamanho_torneio 8
#define quantidade_iteracoes 100

int main(int argc, const char * argv[]) {
    //printf("Insira o seu input: \n");
    
    char string[100];
    int x, y;
    int quantidade_cidades;
    int melhor;
    int elitismo = 0;
    
    for (x = 0; x < 7; x++){
        gets(string);
    }
    
    //printf("Chegamos ao final dos requerimentos \n");
    
    scanf("%d", &quantidade_cidades); // LE DO STDIN QUANTAS CIDADES SERAO VISITADAS
    
    int distancias[quantidade_cidades * quantidade_cidades]; // Distancias contem as distancias entre as cidades
    int tours_atuais[quantidade_cidades * tamanho_populacao]; // tours_atuais contem a populacao
    int fitness[tamanho_populacao]; // fitness[x] contem o fitness to tour_atual[x*tamanho_populacao,x*(tamanho_populacao+1)-1]
    
    for(x = 0; x < quantidade_cidades; x++){
        for(y = 0; y < quantidade_cidades; y++){
            scanf("%d", &distancias[x * quantidade_cidades + y]); // PREENCHE A MATRIZ
        }
    }
    
    gets(string); // TIRAR O EOF DO STDIN
    
    for(x=0;x<tamanho_populacao;x++){
        criarTour(&tours_atuais[x*quantidade_cidades], quantidade_cidades);
        //imprimirTour(&tours_atuais[x * quantidade_cidades], quantidade_cidades, x);
    }
    
    melhor = calculaFitnessPopulacao(distancias, quantidade_cidades, tours_atuais, fitness, tamanho_populacao);
    if (melhor < quantidade_cidades * 10000)
        elitismo = 1;
    
    int pai, mae; // Seleciona os pais da nova população
    
    pai = torneio(tamanho_populacao, tamanho_torneio, fitness);
    mae = pai;
    while (pai == mae){
        mae = torneio(tamanho_populacao, tamanho_torneio,fitness);
    }
    
    printf("O pai eh: %d com fitness %d\n", pai, fitness[pai]);
    printf("A mae eh: %d com fitness %d\n", mae, fitness[mae]);
    
    return 0;
}
