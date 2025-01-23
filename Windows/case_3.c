/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   case_3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmateque <hmateque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 08:39:18 by hmateque          #+#    #+#             */
/*   Updated: 2025/01/23 06:31:59 by hmateque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "home.h"

// Função para processar a validação de produtos
void processar_validacao_produtos(Fila* fila_embalamento_PA, Fila* fila_embalamento_PB, int* descartados_PA, int* descartados_PB)
{
    char tipo[3];
    printf("\nQual tipo de produto deseja validar? (PA/PB): ");
    scanf("%2s", tipo);

    if (strcmp(tipo, "PA") == 0) {
        validarProduto(fila_embalamento_PA, tipo, descartados_PA, descartados_PB);
    } else if (strcmp(tipo, "PB") == 0) {
        validarProduto(fila_embalamento_PB, tipo, descartados_PA, descartados_PB);
    } else {
        printf("\033[31mErro: Tipo inválido! Escolha 'PA' ou 'PB'.\033[0m\n");
    }
}