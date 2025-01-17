/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   produto.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmateque <hmateque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 17:16:28 by hmateque          #+#    #+#             */
/*   Updated: 2025/01/17 18:09:30 by hmateque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../include/home.h"

// Função para validar produto
void validarProduto(Fila* f, char tipo[])
{
    // Verificar se a fila é válida
    if (!f || !f->inicio) {
        printf("\033[33mAviso: Fila vazia ou inválida. Nada a validar.\033[0m\n");
        return;
    }

    Pacote* atual = f->inicio;
    Pacote* anterior = NULL;

    while (atual != NULL) {
        int valido = 1;

        // Validação do tipo e peso
        if (strcmp(atual->tipo, tipo) != 0)
            valido = 0;
        else if (strcmp(tipo, "PA") == 0 && (atual->peso < 195 || atual->peso > 205))
            valido = 0;
        else if (strcmp(tipo, "PB") == 0 && (atual->peso < 995 || atual->peso > 1005))
            valido = 0;

        if (!valido)
        {
            printf("\033[31mRemovendo pacote inválido: Tipo %s, Peso %.2f\033[0m\n", atual->tipo, atual->peso);

            // Remover pacote inválido
            if (anterior == NULL) {
                // Remover do início da fila
                f->inicio = atual->prox;
                free(atual);
                atual = f->inicio;
            } else {
                // Remover do meio ou final da fila
                anterior->prox = atual->prox;
                free(atual);
                atual = anterior->prox;
            }
            f->quantidade--;
        }
        else
        {
            // Avançar para o próximo pacote
            anterior = atual;
            atual = atual->prox;
        }
    }

    printf("\033[32mValidação concluída. Produtos restantes na fila: %d\033[0m\n", f->quantidade);
}
