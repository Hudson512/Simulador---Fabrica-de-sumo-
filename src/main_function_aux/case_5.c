/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   case_5.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmateque <hmateque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 10:19:20 by hmateque          #+#    #+#             */
/*   Updated: 2025/01/20 10:20:54 by hmateque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/home.h"

// Função para processar embalamento e empilhamento
void	processar_embalamento(Maquina *maquina_embalamento_PA,
		Maquina *maquina_embalamento_PB, GerenciadorPilhas *gerenciador_PA,
		GerenciadorPilhas *gerenciador_PB)
{
	char tipo[3];
	printf("\nQual tipo de produto deseja embalar? (PA/PB): ");
	scanf("%2s", tipo);

	if (strcmp(tipo, "PA") == 0)
	{
		embalarEEmpilhar(maquina_embalamento_PA, gerenciador_PA);
		mostrar_status_pilhas(gerenciador_PA);
	}
	else if (strcmp(tipo, "PB") == 0)
	{
		embalarEEmpilhar(maquina_embalamento_PB, gerenciador_PB);
		mostrar_status_pilhas(gerenciador_PB);
	}
	else
	{
		printf("\033[31mErro: Tipo inválido! Escolha 'PA' ou 'PB'.\033[0m\n");
	}
}
