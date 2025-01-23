/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   empilhar.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmateque <hmateque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 10:09:44 by hmateque          #+#    #+#             */
/*   Updated: 2025/01/23 06:33:43 by hmateque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "home.h"

// Função para criar novo gerenciador de pilhas
GerenciadorPilhas* criar_gerenciador_pilhas(const char* tipo)
{
    GerenciadorPilhas* gerenciador = malloc(sizeof(GerenciadorPilhas));
    gerenciador->numero_pilhas = 1;  // Começa com uma pilha
    strcpy(gerenciador->tipo, tipo);
    
    // Inicializa a primeira pilha
    gerenciador->pilhas[0].quantidade_embalagens = 0;
    gerenciador->pilhas[0].capacidade_maxima = strcmp(tipo, "PA") == 0 ? ALTURA_PILHA_PA : ALTURA_PILHA_PB;
    
    return (gerenciador);
}

// Função para obter a altura máxima da pilha por tipo
int obter_altura_maxima_pilha(const char* tipo)
{
    return strcmp(tipo, "PA") == 0 ? ALTURA_PILHA_PA : ALTURA_PILHA_PB;
}

// Função para verificar se é possível criar nova pilha
int pode_criar_nova_pilha(GerenciadorPilhas* gerenciador)
{
    return gerenciador->numero_pilhas < MAX_PILHAS;
}

// Função para criar nova pilha
void criar_nova_pilha(GerenciadorPilhas* gerenciador)
{
    if (pode_criar_nova_pilha(gerenciador))
    {
        int nova_pilha_index = gerenciador->numero_pilhas;
        gerenciador->pilhas[nova_pilha_index].quantidade_embalagens = 0;
        gerenciador->pilhas[nova_pilha_index].capacidade_maxima = 
            obter_altura_maxima_pilha(gerenciador->tipo);
        gerenciador->numero_pilhas++;
        printf("\033[32mNova pilha criada para tipo %s (Pilha #%d)\033[0m\n",
        gerenciador->tipo, gerenciador->numero_pilhas);
    }
    else
        printf("\033[31mErro: Limite máximo de pilhas atingido (%d)\033[0m\n", MAX_PILHAS);
}
