/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmateque <hmateque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 16:20:01 by hmateque          #+#    #+#             */
/*   Updated: 2025/01/17 23:48:47 by hmateque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/home.h"

// Função principal
int	main(void)
{
// Criação das filas e máquinas
Fila *fila_enchimento_PA = criarFila();
Fila *fila_enchimento_PB = criarFila();
Fila *fila_embalamento_PA = criarFila();
Fila *fila_embalamento_PB = criarFila();

Maquina *maquina_enchimento_PA = criarMaquina("Enchimento PA", "enchimento", 2);
Maquina *maquina_enchimento_PB = criarMaquina("Enchimento PB", "enchimento", 3);
Maquina *maquina_embalamento_PA = criarMaquina("Embalamento PA", "embalamento", 5);
Maquina *maquina_embalamento_PB = criarMaquina("Embalamento PB", "embalamento", 4);

int opcao;
do
{
    print_menu();
    scanf("%d", &opcao);
    printf("\n");
    if (feof(stdin))
    {
        system("clear");
        print_menu();
        printf("\033[34mSaindo do programa...\033[0m\n");
        break;
    }
    switch (opcao)
    {
		case 1:
		{
            system("clear");
            print_menu();
			int modo;
			printf("\n1. Automático\n2. Manual\nEscolha o modo: ");
			scanf("%d", &modo);

			if (modo == 1)
			{
				// Leitura do arquivo
				FILE *arquivo = fopen("pacotes.txt", "r");
				if (arquivo == NULL)
				{
					printf("\033[31mErro: Não foi possível abrir o arquivo 'pacotes.txt'.\033[0m\n");
					break;
				}

				char tipo[3];
				float peso;
				printf("\033[32mModo Automático: Lendo pacotes do arquivo...\033[0m\n");
				while (fscanf(arquivo, "%2s %f", tipo, &peso) != EOF)
				{ // Limite para evitar estouro
					if (strcmp(tipo, "PA") == 0)
						inserirPacote(fila_enchimento_PA, tipo, peso);
					else if (strcmp(tipo, "PB") == 0)
						inserirPacote(fila_enchimento_PB, tipo, peso);
					else
					    printf("\033[33mAviso: Pacote ignorado. Tipo inválido: %s\033[0m\n", tipo);
				}
				fclose(arquivo);
			}
			else if (modo == 2)
			{
				char tipo[3];
				float peso;
				printf("\033[32mModo Manual: Insira os dados do pacote.\033[0m\n");
				printf("Tipo (PA/PB): ");
				scanf("%2s", tipo); // Limite para evitar estouro
				printf("Peso (ml): ");
				scanf("%f", &peso);

				if (strcmp(tipo, "PA") == 0)
					inserirPacote(fila_enchimento_PA, tipo, peso);
				else if (strcmp(tipo, "PB") == 0)
					inserirPacote(fila_enchimento_PB, tipo, peso);
				else
					printf("\033[31mErro: Tipo inválido (%s). Use 'PA' ou 'PB'.\033[0m\n", tipo);
			}
			else
			{
				printf("\033[31mErro: Modo inválido. Escolha 1 para Automático ou 2 para Manual.\033[0m\n");
			}

			break ;
		}
		case 2: 
        {
            system("clear");
            print_menu();
            char tipo[3];
            printf("\nQual fila deseja encher? (PA/PB): ");
            scanf("%2s", tipo);

            // Determinar a máquina correspondente
            Maquina* maquina;
            Fila* fila_embalamento;

            if (strcmp(tipo, "PA") == 0) {
                maquina = maquina_enchimento_PA;  // Máquina para PA
                maquina->fila_entrada = fila_enchimento_PA; // Fila de entrada para PA
                fila_embalamento = fila_embalamento_PA; // Fila de embalamento para PA
            } else if (strcmp(tipo, "PB") == 0) {
                maquina = maquina_enchimento_PB;  // Máquina para PB
                maquina->fila_entrada = fila_enchimento_PB; // Fila de entrada para PB
                fila_embalamento = fila_embalamento_PB; // Fila de embalamento para PB
            } else {
                printf("\033[31mErro: Tipo inválido! Escolha 'PA' ou 'PB'.\033[0m\n");
                break;
            }

            // Verificar se há pacotes na fila inicial
            if (maquina->fila_entrada->inicio == NULL) {
                printf("\033[33mAviso: Não há pacotes na fila de entrada para encher.\033[0m\n");
                break;
            }

            // Remover pacote da fila inicial
            Pacote* pacote = removerPacote(maquina->fila_entrada);

            // Simular tempo de processamento
            printf("Enchendo pacote do tipo %s com peso %.2f...\n", pacote->tipo, pacote->peso);
            sleep(maquina->tempo_processamento); // Simula o tempo de enchimento

            // Inserir o pacote na fila de embalamento
            if (enfileirar(fila_embalamento, pacote))
                printf("\033[32mPacote enfileirado com sucesso!\033[0m\n");
            else
                printf("\033[31mErro ao enfileirar pacote!\033[0m\n");
            
            // Atualizar a máquina
            maquina->unidades_processadas++;
            maquina->pacotes_na_maquina++;

            printf("\033[32mPacote do tipo %s com peso %.2f foi enchido e movido para a fila de embalamento.\033[0m\n", pacote->tipo, pacote->peso);
            break;
        }
        case 8:
            system("clear");
            print_menu();
            printf("\033[34mSaindo do programa...\033[0m\n");
            break;
        default:
            system("clear");
            print_menu();
            printf("\033[31mErro: Opção inválida. Escolha uma opção válida.\033[0m\n");
            break;
    }
} while (opcao != 8);

	return (0);
}