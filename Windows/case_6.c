/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   case_6.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmateque <hmateque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 11:23:06 by hmateque          #+#    #+#             */
/*   Updated: 2025/01/23 06:32:19 by hmateque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "home.h"

// Função principal para imprimir todas as informações
void imprimir_informacoes(
    Fila* fila_enchimento_PA, Fila* fila_enchimento_PB,
    Fila* fila_embalamento_PA, Fila* fila_embalamento_PB,
    Maquina* maquina_enchimento_PA, Maquina* maquina_enchimento_PB,
    Maquina* maquina_embalamento_PA, Maquina* maquina_embalamento_PB,
    GerenciadorPilhas* gerenciador_PA, GerenciadorPilhas* gerenciador_PB
)
{
    int opcao;
    do {
        printf("\n\033[32m=== Menu de Impressão ===\033[0m\n");
        printf("1. Filas de enchimento\n");
        printf("2. Filas de embalamento\n");
        printf("3. Status das máquinas\n");
        printf("4. Número de pilhas e status\n");
        printf("5. Todas as informações\n");
        printf("6. Voltar ao menu principal\n");
        printf("\nEscolha uma opção: ");
        scanf("%d", &opcao);
        printf("\n");

        system("clear");

        switch (opcao) {
            case 1:
                printf("\033[32m=== Filas de Enchimento ===\033[0m\n\n");
                imprimir_fila(fila_enchimento_PA, "Enchimento", "PA");
                imprimir_fila(fila_enchimento_PB, "Enchimento", "PB");
                break;

            case 2:
                printf("\033[32m=== Filas de Embalamento ===\033[0m\n\n");
                imprimir_fila(fila_embalamento_PA, "Embalamento", "PA");
                imprimir_fila(fila_embalamento_PB, "Embalamento", "PB");
                break;

            case 3:
                printf("\033[32m=== Status das Máquinas ===\033[0m\n\n");
                imprimir_status_maquina(maquina_enchimento_PA);
                imprimir_status_maquina(maquina_enchimento_PB);
                imprimir_status_maquina(maquina_embalamento_PA);
                imprimir_status_maquina(maquina_embalamento_PB);
                break;

            case 4:
                printf("\033[32m=== Status das Pilhas ===\033[0m\n\n");
                imprimir_status_detalhado_pilhas(gerenciador_PA);
                imprimir_status_detalhado_pilhas(gerenciador_PB);
                break;

            case 5:
                printf("\033[32m=== Relatório Completo do Sistema ===\033[0m\n\n");
                // Filas de enchimento
                printf("\033[32m--- Filas de Enchimento ---\033[0m\n\n");
                imprimir_fila(fila_enchimento_PA, "Enchimento", "PA");
                imprimir_fila(fila_enchimento_PB, "Enchimento", "PB");
                
                // Filas de embalamento
                printf("\033[32m--- Filas de Embalamento ---\033[0m\n\n");
                imprimir_fila(fila_embalamento_PA, "Embalamento", "PA");
                imprimir_fila(fila_embalamento_PB, "Embalamento", "PB");
                
                // Status das máquinas
                printf("\033[32m--- Status das Máquinas ---\033[0m\n\n");
                imprimir_status_maquina(maquina_enchimento_PA);
                imprimir_status_maquina(maquina_enchimento_PB);
                imprimir_status_maquina(maquina_embalamento_PA);
                imprimir_status_maquina(maquina_embalamento_PB);
                
                // Status das pilhas
                printf("\033[32m--- Status das Pilhas ---\033[0m\n\n");
                imprimir_status_detalhado_pilhas(gerenciador_PA);
                imprimir_status_detalhado_pilhas(gerenciador_PB);
                break;

            case 6:
                printf("\033[34mVoltando ao menu principal...\033[0m\n");
                break;

            default:
                printf("\033[31mOpção inválida! Por favor, escolha uma opção válida.\033[0m\n");
                break;
        }
    } while (opcao != 6);
}
