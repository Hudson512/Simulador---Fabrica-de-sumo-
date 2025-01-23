/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   relatorio.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmateque <hmateque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 08:58:03 by hmateque          #+#    #+#             */
/*   Updated: 2025/01/23 06:34:14 by hmateque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "home.h"

// Função para calcular lucro por pacote
float   calcular_lucro_pacote(const char* tipo)
{
    // Valores fictícios para exemplo
    return strcmp(tipo, "PA") == 0 ? 1100.0 : 1700.0;
}

// Função para gerar estatísticas da simulação
EstatisticasSimulacao   gerar_estatisticas(GerenciadorPilhas* gerenciador_PA, GerenciadorPilhas* gerenciador_PB,
                        int descartados_PA,
                        int descartados_PB)
{
    EstatisticasSimulacao stats = {0};
    
    // Calcular produtos embalados
    for (int i = 0; i < gerenciador_PA->numero_pilhas; i++)
        stats.produtos_embalados_PA += gerenciador_PA->pilhas[i].quantidade_embalagens * LIMITE_PA;
    
    for (int i = 0; i < gerenciador_PB->numero_pilhas; i++)
        stats.produtos_embalados_PB += gerenciador_PB->pilhas[i].quantidade_embalagens * LIMITE_PB;
    
    // Registrar produtos descartados
    stats.produtos_descartados_PA = descartados_PA;
    stats.produtos_descartados_PB = descartados_PB;
    
    // Calcular lucros e prejuízos
    stats.lucro_PA = stats.produtos_embalados_PA * calcular_lucro_pacote("PA");
    stats.lucro_PB = stats.produtos_embalados_PB * calcular_lucro_pacote("PB");
    stats.prejuizo_PA = stats.produtos_descartados_PA * calcular_lucro_pacote("PA");
    stats.prejuizo_PB = stats.produtos_descartados_PB * calcular_lucro_pacote("PB");
    
    return (stats);
}

// Função para salvar relatório em arquivo
void    salvar_relatorio(const EstatisticasSimulacao* stats)
{
    // Relatório de produtos embalados
    FILE* f_embalados = fopen("relatorio_embalados.txt", "w");
    if (f_embalados)
    {
        fprintf(f_embalados, "=== Relatório de Produtos Embalados ===\n");
        fprintf(f_embalados, "Produtos PA: %d unidades\n", stats->produtos_embalados_PA);
        fprintf(f_embalados, "Produtos PB: %d unidades\n", stats->produtos_embalados_PB);
        fprintf(f_embalados, "Total: %d unidades\n", 
                stats->produtos_embalados_PA + stats->produtos_embalados_PB);
        fclose(f_embalados);
    }

    // Relatório de produtos descartados
    FILE* f_descartados = fopen("relatorio_descartados.txt", "w");
    if (f_descartados) {
        fprintf(f_descartados, "=== Relatório de Produtos Descartados ===\n");
        fprintf(f_descartados, "Produtos PA: %d unidades\n", stats->produtos_descartados_PA);
        fprintf(f_descartados, "Produtos PB: %d unidades\n", stats->produtos_descartados_PB);
        fprintf(f_descartados, "Total: %d unidades\n", 
                stats->produtos_descartados_PA + stats->produtos_descartados_PB);
        fclose(f_descartados);
    }

    // Relatório financeiro
    FILE* f_financeiro = fopen("relatorio_financeiro.txt", "w");
    if (f_financeiro)
    {
        fprintf(f_financeiro, "=== Relatório Financeiro ===\n\n");
        fprintf(f_financeiro, "Lucro previsto:\n");
        fprintf(f_financeiro, "- Produtos PA: Kz %.2f\n", stats->lucro_PA);
        fprintf(f_financeiro, "- Produtos PB: Kz %.2f\n", stats->lucro_PB);
        fprintf(f_financeiro, "- Total: Kz %.2f\n\n", stats->lucro_PA + stats->lucro_PB);
        fprintf(f_financeiro, "Prejuízo:\n");
        fprintf(f_financeiro, "- Produtos PA: Kz %.2f\n", stats->prejuizo_PA);
        fprintf(f_financeiro, "- Produtos PB: Kz %.2f\n", stats->prejuizo_PB);
        fprintf(f_financeiro, "- Total: Kz %.2f\n", stats->prejuizo_PA + stats->prejuizo_PB);
        fclose(f_financeiro);
    }
}

// Função para destruir uma fila
void    destruir_fila(Fila* fila)
{
    if (!fila) return;
    
    Pacote* atual = fila->inicio;
    while (atual != NULL)
    {
        Pacote* temp = atual;
        atual = atual->prox;
        free(temp);
    }
    free(fila);
}

// Função para destruir uma máquina
void    destruir_maquina(Maquina* maquina)
{
    if (maquina)
        free(maquina);
}

// Função para destruir um gerenciador de pilhas
void    destruir_gerenciador_pilhas(GerenciadorPilhas* gerenciador)
{
    if (gerenciador)
        free(gerenciador);
}

// Função para destruir todas as estruturas
void    destruir_estruturas(Fila* fila_enchimento_PA, Fila* fila_enchimento_PB,
        Fila* fila_embalamento_PA, Fila* fila_embalamento_PB,
        Maquina* maquina_enchimento_PA, Maquina* maquina_enchimento_PB,
        Maquina* maquina_embalamento_PA, Maquina* maquina_embalamento_PB,
        GerenciadorPilhas* gerenciador_PA, GerenciadorPilhas* gerenciador_PB)
{
    // Destruir filas
    destruir_fila(fila_enchimento_PA);
    destruir_fila(fila_enchimento_PB);
    destruir_fila(fila_embalamento_PA);
    destruir_fila(fila_embalamento_PB);
    
    // Destruir máquinas
    destruir_maquina(maquina_enchimento_PA);
    destruir_maquina(maquina_enchimento_PB);
    destruir_maquina(maquina_embalamento_PA);
    destruir_maquina(maquina_embalamento_PB);
    
    // Destruir gerenciadores de pilhas
    destruir_gerenciador_pilhas(gerenciador_PA);
    destruir_gerenciador_pilhas(gerenciador_PB);
}


