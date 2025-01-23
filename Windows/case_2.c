/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   case_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmateque <hmateque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 08:11:57 by hmateque          #+#    #+#             */
/*   Updated: 2025/01/23 06:39:30 by hmateque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "home.h"

// Função auxiliar para o caso 2
void	processar_enchimento(Maquina *maquina_enchimento_PA,
		Maquina *maquina_enchimento_PB, Fila *fila_enchimento_PA,
		Fila *fila_enchimento_PB, Fila *fila_embalamento_PA,
		Fila *fila_embalamento_PB)
{
	Maquina *maquina;
	Fila *fila_embalamento;
	Pacote *pacote;
	char tipo[3];

	printf("\nQual fila deseja encher? (PA/PB): ");
	scanf("%2s", tipo);
	if (strcmp(tipo, "PA") == 0)
	{
		maquina = maquina_enchimento_PA;
		maquina->fila_entrada = fila_enchimento_PA;
		fila_embalamento = fila_embalamento_PA;
	}
	else if (strcmp(tipo, "PB") == 0)
	{
		maquina = maquina_enchimento_PB;
		maquina->fila_entrada = fila_enchimento_PB;
		fila_embalamento = fila_embalamento_PB;
	}
	else
	{
		printf("\033[31mErro: Tipo inválido! Escolha 'PA' ou 'PB'.\033[0m\n");
		return ;
	}

	if (maquina->fila_entrada->inicio == NULL)
	{
		printf("\033[33mAviso: Não há pacotes na fila de entrada para encher.\033[0m\n");
		return ;
	}
	pacote = removerPacote(maquina->fila_entrada);
	printf("Enchendo pacote do tipo %s com peso %.2f...\n", pacote->tipo,
		pacote->peso);
	Sleep(maquina->tempo_processamento);

	if (enfileirar(fila_embalamento, pacote))
		printf("\033[32mPacote enfileirado com sucesso!\033[0m\n");
	else
		printf("\033[31mErro ao enfileirar pacote!\033[0m\n");

	maquina->unidades_processadas++;
	maquina->pacotes_na_maquina++;

	printf("\033[32mPacote do tipo %s com peso %.2f foi enchido e movido para a fila de embalamento.\033[0m\n",
    pacote->tipo, pacote->peso);
}