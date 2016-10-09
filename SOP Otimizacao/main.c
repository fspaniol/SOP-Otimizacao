//
//  main.c
//  SOP Otimizacao
//
//  Created by Fernando Spaniol and Isadora Possebon on 10/9/16.
//  Copyright © 2016 Fernando Spaniol, Isadora Possebon. All rights reserved.
//

#include <stdio.h>

int main(int argc, const char * argv[]) {
    printf("Começaremos: \n");
    
    char string[100];
    int x, y;
    int quantidade_cidades;
    
    for (x = 0; x < 7; x++){
        gets(string);
    }
    
    printf("Chegamos ao final dos requerimentos \n");
    
    scanf("%d", &quantidade_cidades); // LE DO STDIN QUANTAS CIDADES SERAO VISITADAS
    
    printf("Quantas cidades serão visitadas: %d \n", quantidade_cidades);
    
    int distancias[quantidade_cidades][quantidade_cidades];
    
    for(x = 0; x < quantidade_cidades; x++){
        for(y = 0; y < quantidade_cidades; y++){
            scanf("%d", &distancias[x][y]); // PREENCHE A MATRIZ
        }
    }
    
    for(x = 0; x < quantidade_cidades; x++){
        for(y = 0; y < quantidade_cidades; y++){
            printf("%d ", distancias[x][y]); // TESTA OS DADOS DA MATRIZ
        }
        printf("\n");
    }
    
    gets(string); // TIRAR O EOF DO STDIN
    return 0;
}
