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

#define tamanho_populacao 6000

int main(int argc, const char * argv[]) {
    printf("Começaremos: \n");
    
    char string[100];
    int x, y;
    int quantidade_cidades;
    
    for (x = 0; x < 7; x++){
        gets(string);
    }
    
    //printf("Chegamos ao final dos requerimentos \n");
    
    scanf("%d", &quantidade_cidades); // LE DO STDIN QUANTAS CIDADES SERAO VISITADAS
    
    //printf("Quantas cidades serão visitadas: %d \n", quantidade_cidades);
    
    int distancias[quantidade_cidades * quantidade_cidades];
    int cidades[quantidade_cidades * tamanho_populacao];
    int fitness[tamanho_populacao];
    
    for(x = 0; x < quantidade_cidades; x++){
        for(y = 0; y < quantidade_cidades; y++){
            scanf("%d", &distancias[x * quantidade_cidades + y]); // PREENCHE A MATRIZ
        }
    }
    
    gets(string); // TIRAR O EOF DO STDIN
    
    for(x=0;x<tamanho_populacao;x++){
        criarTour(&cidades[x*quantidade_cidades], quantidade_cidades);
        //calculaFitness(distancias, quantidade_cidades, &cidades[x*quantidade_cidades]);
        //imprimeTour(distancias, quantidade_cidades);
    }
    //imprimirTour(cidades,quantidade_cidades);
    calculaFitnessPopulacao(distancias, quantidade_cidades, cidades, fitness, tamanho_populacao);
    
    
    return 0;
}
