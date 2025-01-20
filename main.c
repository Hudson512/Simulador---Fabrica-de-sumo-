/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmateque <hmateque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 16:20:01 by hmateque          #+#    #+#             */
/*   Updated: 2025/01/20 11:28:40 by hmateque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/home.h"



// Função principal refatorada
int main(void) {
    // Criação das filas e máquinas
    Fila *fila_enchimento_PA = criarFila();
    Fila *fila_enchimento_PB = criarFila();
    Fila *fila_embalamento_PA = criarFila();
    Fila *fila_embalamento_PB = criarFila();

    Maquina *maquina_enchimento_PA = criarMaquina("Enchimento PA", "enchimento", 2);
    Maquina *maquina_enchimento_PB = criarMaquina("Enchimento PB", "enchimento", 3);
    Maquina *maquina_embalamento_PA = criarMaquina("Embalamento PA", "embalamento", 5);
    Maquina *maquina_embalamento_PB = criarMaquina("Embalamento PB", "embalamento", 4);

    // Criar gerenciadores de pilhas
    GerenciadorPilhas* gerenciador_PA = criar_gerenciador_pilhas("PA");
    GerenciadorPilhas* gerenciador_PB = criar_gerenciador_pilhas("PB");

    int opcao;
    do {
        print_menu();
        scanf("%d", &opcao);
        printf("\n");
        if (feof(stdin)) {
            system("clear");
            print_menu();
            printf("\033[34mSaindo do programa...\033[0m\n");
            break;
        }
        system("clear");
        print_menu();
        switch (opcao) {
            case 1:
                processar_insercao_pacotes(fila_enchimento_PA, fila_enchimento_PB);
                break;
            case 2:
                processar_enchimento(maquina_enchimento_PA, maquina_enchimento_PB,
                                   fila_enchimento_PA, fila_enchimento_PB,
                                   fila_embalamento_PA, fila_embalamento_PB);
                break;
            case 3:
                processar_validacao_produtos(fila_embalamento_PA, fila_embalamento_PB);
                break;
            case 4:
                processar_encaminhamento(fila_embalamento_PA, fila_embalamento_PB,
                maquina_embalamento_PA, maquina_embalamento_PB);
                break;
            case 5:
                processar_embalamento(maquina_embalamento_PA, maquina_embalamento_PB,
                gerenciador_PA, gerenciador_PB);
                break;
            case 6:
                imprimir_informacoes(fila_enchimento_PA, fila_enchimento_PB,
                fila_embalamento_PA, fila_embalamento_PB,
                maquina_enchimento_PA, maquina_enchimento_PB,
                maquina_embalamento_PA, maquina_embalamento_PB,
                gerenciador_PA, gerenciador_PB);
                break;
            case 8:
                printf("\033[34mSaindo do programa...\033[0m\n");
                break;
            default:
                printf("\033[31mErro: Opção inválida. Escolha uma opção válida.\033[0m\n");
                break;
        }
    } while (opcao != 8);

    return (0);
}