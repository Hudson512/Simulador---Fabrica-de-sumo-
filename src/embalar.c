/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   embalar.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmateque <hmateque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 10:04:27 by hmateque          #+#    #+#             */
/*   Updated: 2025/01/20 10:19:38 by hmateque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/home.h"

// Função para embalar e empilhar pacotes
void embalarEEmpilhar(Maquina* maquina, GerenciadorPilhas* gerenciador)
{
    // Verificar se há pacotes suficientes na máquina
    int qtd_necessaria = strcmp(gerenciador->tipo, "PA") == 0 ? LIMITE_PA : LIMITE_PB;
    
    if (maquina->pacotes_na_maquina < qtd_necessaria)
    {
        printf("\033[31mErro: Quantidade insuficiente de pacotes na máquina.\n");
        printf("Necessário: %d, Atual: %d\033[0m\n",
        qtd_necessaria, maquina->pacotes_na_maquina);
        return;
    }

    // Verificar se há espaço na pilha atual
    int pilha_atual = gerenciador->numero_pilhas - 1;
    if (gerenciador->pilhas[pilha_atual].quantidade_embalagens >= 
        gerenciador->pilhas[pilha_atual].capacidade_maxima)
    {
        // Tentar criar nova pilha
        if (!pode_criar_nova_pilha(gerenciador)) {
            printf("\033[31mErro: Todas as pilhas estão cheias e não é possível criar mais.\033[0m\n");
            return;
        }
        criar_nova_pilha(gerenciador);
        pilha_atual = gerenciador->numero_pilhas - 1;
    }

    // Simular tempo de embalamento
    printf("\033[32mEmbalando %d pacotes do tipo %s...\033[0m\n", qtd_necessaria, gerenciador->tipo);
    sleep(maquina->tempo_processamento);

    // Atualizar contadores
    maquina->pacotes_na_maquina -= qtd_necessaria;
    gerenciador->pilhas[pilha_atual].quantidade_embalagens++;

    // Mostrar status
    printf("\033[32mEmbalagem concluída com sucesso!\033[0m\n");
    printf("Status atual:\n");
    printf("- Pacotes restantes na máquina: %d\n", maquina->pacotes_na_maquina);
    printf("- Pilha atual (#%d): %d/%d embalagens\n",
    pilha_atual + 1,
    gerenciador->pilhas[pilha_atual].quantidade_embalagens,
    gerenciador->pilhas[pilha_atual].capacidade_maxima);
    printf("- Total de pilhas: %d\n", gerenciador->numero_pilhas);
}

