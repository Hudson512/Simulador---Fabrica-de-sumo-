/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   case_1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmateque <hmateque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 08:05:06 by hmateque          #+#    #+#             */
/*   Updated: 2025/01/23 06:31:47 by hmateque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "home.h"

// Funções auxiliares para o caso 1
void processar_modo_automatico(Fila *fila_enchimento_PA, Fila *fila_enchimento_PB)
{
    FILE *arquivo = fopen("pacotes.txt", "r");
    char tipo[3];
    float peso;
    
    if (arquivo == NULL) {
        printf("\033[31mErro: Não foi possível abrir o arquivo 'pacotes.txt'.\033[0m\n");
        return;
    }
    printf("\033[32mModo Automático: Lendo pacotes do arquivo...\033[0m\n");
    while (fscanf(arquivo, "%2s %f", tipo, &peso) != EOF) {
        if (strcmp(tipo, "PA") == 0)
            inserirPacote(fila_enchimento_PA, tipo, peso);
        else if (strcmp(tipo, "PB") == 0)
            inserirPacote(fila_enchimento_PB, tipo, peso);
        else
            printf("\033[33mAviso: Pacote ignorado. Tipo inválido: %s\033[0m\n", tipo);
    }
    fclose(arquivo);
}

void processar_modo_manual(Fila *fila_enchimento_PA, Fila *fila_enchimento_PB)
{
    char tipo[3];
    float peso;
    
    printf("\033[32mModo Manual: Insira os dados do pacote.\033[0m\n");
    printf("Tipo (PA/PB): ");
    scanf("%2s", tipo);
    printf("Peso (ml): ");
    scanf("%f", &peso);
    if (strcmp(tipo, "PA") == 0)
        inserirPacote(fila_enchimento_PA, tipo, peso);
    else if (strcmp(tipo, "PB") == 0)
        inserirPacote(fila_enchimento_PB, tipo, peso);
    else
        printf("\033[31mErro: Tipo inválido (%s). Use 'PA' ou 'PB'.\033[0m\n", tipo);
}

void processar_insercao_pacotes(Fila *fila_enchimento_PA, Fila *fila_enchimento_PB)
{
    int modo;
    
    printf("\n1. Automático\n2. Manual\nEscolha o modo: ");
    scanf("%d", &modo);
    if (modo == 1)
        processar_modo_automatico(fila_enchimento_PA, fila_enchimento_PB);
    else if (modo == 2)
        processar_modo_manual(fila_enchimento_PA, fila_enchimento_PB);
    else
        printf("\033[31mErro: Modo inválido. Escolha 1 para Automático ou 2 para Manual.\033[0m\n");
}
