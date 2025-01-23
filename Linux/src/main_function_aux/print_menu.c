/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_menu.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmateque <hmateque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 23:22:42 by hmateque          #+#    #+#             */
/*   Updated: 2025/01/20 11:29:01 by hmateque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/home.h"

// Função para imprimir o menu
void    print_menu(void)
{
    printf("\033[35m\n=== SIMULAÇÃO FÁBRICA DE SUMOS ===\033[0m\n");
    printf("\033[35m1. Inserir pacote na fila\033[0m\n");
    printf("\033[35m2. Encher\033[0m\n");
    printf("\033[35m3. Validar produto\033[0m\n");
    printf("\033[35m4. Encaminhar\033[0m\n");
    printf("\033[35m5. Embalar & Empilhar\033[0m\n");
    printf("\033[35m6. Imprimir\033[0m\n");
    printf("\033[35m7. Terminar simulação\033[0m\n");
    printf("\033[35m8. Sair\033[0m\n");
    printf("\033[35mEscolha uma opção: \033[0m");
}

// Função para imprimir relatório de validação
void imprimir_relatorio_validacao(const EstatisticasValidacao* stats, const char* tipo)
{
    printf("\n\033[34m=== Relatório de Validação - Tipo %s ===\033[0m\n", tipo);
    printf("Total de produtos validados: %d\n", stats->total_validados);
    printf("Total de produtos removidos: %d\n", stats->total_removidos);
    printf("Prejuízo total: KZ %.2f\n", stats->prejuizo_total);
    printf("\033[34m=====================================\033[0m\n\n");
}

// Função para mostrar status das pilhas
void mostrar_status_pilhas(GerenciadorPilhas* gerenciador)
{
    printf("\n\033[34m=== Status das Pilhas - Tipo %s ===\033[0m\n", gerenciador->tipo);
    for (int i = 0; i < gerenciador->numero_pilhas; i++) {
        printf("Pilha #%d: %d/%d embalagens\n",
               i + 1,
               gerenciador->pilhas[i].quantidade_embalagens,
               gerenciador->pilhas[i].capacidade_maxima);
    }
    printf("\033[34m================================\033[0m\n\n");
}
// ----------------------------------------------------------------------------------------//

// Função para imprimir uma fila específica
void imprimir_fila(Fila* fila, const char* nome_fila, const char* tipo)
{
    printf("\033[34m=== Fila de %s - Tipo %s ===\033[0m\n", nome_fila, tipo);
    
    if (!fila || !fila->inicio) {
        printf("Fila vazia\n");
        printf("\033[34m============================\033[0m\n\n");
        return;
    }

    Pacote* atual = fila->inicio;
    int posicao = 1;
    
    printf("Total de pacotes: %d\n", fila->quantidade);
    printf("\nPacotes na fila:\n");
    
    while (atual != NULL) {
        printf("  %d. Tipo: %s | Peso: %.2f ml\n", 
               posicao++, atual->tipo, atual->peso);
        atual = atual->prox;
    }
    
    printf("\033[34m============================\033[0m\n\n");
}

// Função para imprimir status de uma máquina
void imprimir_status_maquina(Maquina* maquina)
{
    printf("\033[34m=== Status da Máquina %s ===\033[0m\n", maquina->nome);
    printf("Tipo: %s\n", maquina->tipo);
    printf("Pacotes na máquina: %d\n", maquina->pacotes_na_maquina);
    printf("Total de unidades processadas: %d\n", maquina->unidades_processadas);
    printf("\033[34m============================\033[0m\n\n");
}

// Função para imprimir status detalhado das pilhas
void imprimir_status_detalhado_pilhas(GerenciadorPilhas* gerenciador)
{
    printf("\033[34m=== Status das Pilhas - Tipo %s ===\033[0m\n", gerenciador->tipo);
    printf("Número total de pilhas: %d\n", gerenciador->numero_pilhas);
    
    for (int i = 0; i < gerenciador->numero_pilhas; i++) {
        printf("\nPilha #%d:\n", i + 1);
        printf("  Embalagens: %d/%d\n", 
               gerenciador->pilhas[i].quantidade_embalagens,
               gerenciador->pilhas[i].capacidade_maxima);
        
        // Visualização gráfica da pilha
        printf("  Status: ");
        for (int j = 0; j < gerenciador->pilhas[i].capacidade_maxima; j++) {
            if (j < gerenciador->pilhas[i].quantidade_embalagens)
                printf("█"); // Bloco cheio
            else
                printf("░"); // Bloco vazio
        }
        printf("\n");
    }
    printf("\033[34m============================\033[0m\n\n");
}

