/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   case_4.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmateque <hmateque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 08:58:51 by hmateque          #+#    #+#             */
/*   Updated: 2025/01/23 06:32:08 by hmateque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "home.h"

// Função para processar o encaminhamento
void	processar_encaminhamento(Fila *fila_embalamento_PA,
		Fila *fila_embalamento_PB, Maquina *maquina_embalamento_PA,
		Maquina *maquina_embalamento_PB)
{
	char	tipo[3];

	printf("\nQual tipo de produto deseja encaminhar? (PA/PB): ");
	scanf("%2s", tipo);
	if (strcmp(tipo, "PA") == 0)
	{
		encaminharPacote(fila_embalamento_PA, maquina_embalamento_PA, tipo);
	}
	else if (strcmp(tipo, "PB") == 0)
	{
		encaminharPacote(fila_embalamento_PB, maquina_embalamento_PB, tipo);
	}
	else
	{
		printf("\033[31mErro: Tipo inválido! Escolha 'PA' ou 'PB'.\033[0m\n");
	}
}
