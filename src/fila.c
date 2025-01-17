/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fila.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmateque <hmateque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 17:04:22 by hmateque          #+#    #+#             */
/*   Updated: 2025/01/17 23:17:50 by hmateque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/home.h"

// Funções para manipulação da fila
Fila* criarFila(void)
{
    // Alocar memória para a nova fila
    Fila* f = (Fila*)malloc(sizeof(Fila));
    if (f == NULL)
    {
        printf("\033[31mErro: Falha ao alocar memória para a fila.\033[0m\n");
        return NULL;
    }

    // Inicializar os atributos da fila
    f->inicio = NULL;
    f->fim = NULL;
    f->quantidade = 0;

    //printf("\033[32mFila criada com sucesso.\033[0m\n");
    return f;
}

// Função para enfileirar um pacote em uma fila específica
int enfileirar(Fila* fila, Pacote* pacote)
{
    // Verifica se a fila e o pacote são válidos
    if (fila == NULL || pacote == NULL)
        return 0;

    // Cria um novo nó para o pacote
    Pacote* novo = (Pacote*)malloc(sizeof(Pacote));
    if (novo == NULL)
        return 0;

    // Copia os dados do pacote para o novo nó
    strcpy(novo->tipo, pacote->tipo);
    novo->peso = pacote->peso;
    novo->valido = pacote->valido;
    novo->prox = NULL;

    // Se a fila estiver vazia ou adicionar o novo pacote no fim da fila
    if (fila->fim == NULL)
    {
        fila->inicio = novo;
        fila->fim = novo;
    }
    else
    {
        fila->fim->prox = novo;
        fila->fim = novo;
    }
    // Incrementa a quantidade de elementos na fila
    fila->quantidade++;
    return (1);
}


