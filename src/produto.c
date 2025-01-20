/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   produto.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmateque <hmateque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 17:16:28 by hmateque          #+#    #+#             */
/*   Updated: 2025/01/20 10:01:19 by hmateque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/home.h"

// Função para calcular o prejuízo do pacote
float calcular_prejuizo(const char* tipo, float peso)
{
    // Valores fictícios para exemplo: PA = Kz10,00 por unidade, PB = Kz20,00 por unidade
    if (strcmp(tipo, "PA") == 0)
        return 1100.0;
    else if (strcmp(tipo, "PB") == 0)
        return 1700.0;
    return 0.0;
}

// Função para verificar se o peso está dentro do padrão
int peso_valido(const char* tipo, float peso)
{
    if (strcmp(tipo, "PA") == 0)
        return (peso >= 195 && peso <= 205);
    else if (strcmp(tipo, "PB") == 0)
        return (peso >= 995 && peso <= 1005);
    return 0;
}

// Função principal para validar produto
void validarProduto(Fila* f, char tipo[])
{
    // Verificar se a fila é válida
    if (!f || !f->inicio) {
        printf("\033[33mAviso: Fila vazia ou inválida. Nada a validar.\033[0m\n");
        return;
    }
    // Inicializar estatísticas
    EstatisticasValidacao stats = {0, 0, 0.0};
    Pacote* atual = f->inicio;
    Pacote* anterior = NULL;

    printf("\033[32mIniciando validação dos produtos tipo %s...\033[0m\n", tipo);

    while (atual != NULL) {
        int valido = 1;
        stats.total_validados++;

        // Validação do tipo
        if (strcmp(atual->tipo, tipo) != 0) {
            printf("\033[31mErro: Tipo incorreto. Encontrado %s, esperado %s\033[0m\n", 
                   atual->tipo, tipo);
            valido = 0;
        }
        // Validação do peso
        else if (!peso_valido(tipo, atual->peso)) {
            printf("\033[31mErro: Peso fora do padrão. Peso: %.2f\033[0m\n", atual->peso);
            valido = 0;
        }

        if (!valido) {
            // Calcular prejuízo antes de remover
            float prejuizo = calcular_prejuizo(atual->tipo, atual->peso);
            stats.prejuizo_total += prejuizo;
            stats.total_removidos++;
            stats.total_validados--;

            printf("\033[31mRemovendo pacote inválido: Tipo %s, Peso %.2f (Prejuízo: KZ %.2f)\033[0m\n", 
                   atual->tipo, atual->peso, prejuizo);

            // Remover pacote inválido
            Pacote* temp = atual;
            
            if (anterior == NULL) {
                // Remover do início da fila
                f->inicio = atual->prox;
                atual = f->inicio;
            } else {
                // Remover do meio ou final da fila
                anterior->prox = atual->prox;
                atual = anterior->prox;
            }
            
            free(temp);
            f->quantidade--;
        } else {
            printf("\033[32mPacote válido: Tipo %s, Peso %.2f\033[0m\n", 
                   atual->tipo, atual->peso);
            // Avançar para o próximo pacote
            anterior = atual;
            atual = atual->prox;
        }
    }

    // Imprimir relatório final
    imprimir_relatorio_validacao(&stats, tipo);
}

