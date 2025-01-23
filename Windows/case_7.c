/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   case_7.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmateque <hmateque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 09:52:00 by hmateque          #+#    #+#             */
/*   Updated: 2025/01/23 06:32:26 by hmateque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "home.h"

// Função principal para processar o término da simulação
void    processar_termino_simulacao(Fila** fila_enchimento_PA, Fila** fila_enchimento_PB,
        Fila** fila_embalamento_PA, Fila** fila_embalamento_PB,
        Maquina** maquina_enchimento_PA, Maquina** maquina_enchimento_PB,
        Maquina** maquina_embalamento_PA, Maquina** maquina_embalamento_PB,
        GerenciadorPilhas** gerenciador_PA, GerenciadorPilhas** gerenciador_PB,
        int* descartados_PA, int* descartados_PB)
{
    // Gerar estatísticas
    EstatisticasSimulacao stats = gerar_estatisticas(*gerenciador_PA, *gerenciador_PB, *descartados_PA, *descartados_PB);
    
    // Salvar relatórios
    salvar_relatorio(&stats);
    
    printf("\033[32m=== Relatórios gerados com sucesso! ===\033[0m\n\n");
    printf("Os seguintes arquivos foram criados:\n");
    printf("- relatorio_embalados.txt\n");
    printf("- relatorio_descartados.txt\n");
    printf("- relatorio_financeiro.txt\n\n");
    
    // Destruir estruturas
    destruir_estruturas(
        *fila_enchimento_PA, *fila_enchimento_PB,
        *fila_embalamento_PA, *fila_embalamento_PB,
        *maquina_enchimento_PA, *maquina_enchimento_PB,
        *maquina_embalamento_PA, *maquina_embalamento_PB,
        *gerenciador_PA, *gerenciador_PB
    );
    
    // Zerar ponteiros
    *fila_enchimento_PA = NULL;
    *fila_enchimento_PB = NULL;
    *fila_embalamento_PA = NULL;
    *fila_embalamento_PB = NULL;
    *maquina_enchimento_PA = NULL;
    *maquina_enchimento_PB = NULL;
    *maquina_embalamento_PA = NULL;
    *maquina_embalamento_PB = NULL;
    *gerenciador_PA = NULL;
    *gerenciador_PB = NULL;
    
    // Perguntar se deseja iniciar nova simulação
    char resposta;
    printf("Deseja iniciar uma nova simulação? (S/N): ");
    scanf(" %c", &resposta);
    
    if (toupper(resposta) == 'S')
    {
        // Criar novas estruturas
        *fila_enchimento_PA = criarFila();
        *fila_enchimento_PB = criarFila();
        *fila_embalamento_PA = criarFila();
        *fila_embalamento_PB = criarFila();
        *maquina_enchimento_PA = criarMaquina("Enchimento PA", "enchimento", 2);
        *maquina_enchimento_PB = criarMaquina("Enchimento PB", "enchimento", 3);
        *maquina_embalamento_PA = criarMaquina("Embalamento PA", "embalamento", 5);
        *maquina_embalamento_PB = criarMaquina("Embalamento PB", "embalamento", 4);
        *gerenciador_PA = criar_gerenciador_pilhas("PA");
        *gerenciador_PB = criar_gerenciador_pilhas("PB");
        
        // Resetar contadores de descarte
        *descartados_PA = 0;
        *descartados_PB = 0;
        
        printf("\033[32mNova simulação iniciada com sucesso!\033[0m\n");
    }
    else
    {
        printf("\033[34mEncerrando o programa...\033[0m\n");
        exit(0);
    }
}