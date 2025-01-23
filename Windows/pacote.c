/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pacote.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmateque <hmateque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 17:05:43 by hmateque          #+#    #+#             */
/*   Updated: 2025/01/23 06:34:03 by hmateque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "home.h"

int validacao_de_dados(Fila *f, char tipo[], float peso);

void inserirPacote(Fila* f, char tipo[], float peso) 
{
    // Verificar tipo válido
    if (!validacao_de_dados(f, tipo, peso))
    {
        return;
    }
    // Alocar memória para o novo pacote
    Pacote* novo = (Pacote*)malloc(sizeof(Pacote));
    if (!novo) {
        printf("Erro: Falha ao alocar memória para o novo pacote.\n");
        return;
    }

    // Inicializar atributos do pacote
    strcpy(novo->tipo, tipo);
    novo->peso = peso;
    novo->valido = 1;
    novo->prox = NULL;

    // Adicionar o pacote na fila
    if (f->fim == NULL)
    {
        f->inicio = f->fim = novo;
    }
    else
    {
        f->fim->prox = novo;
        f->fim = novo;
    }
    // Atualizar o contador da fila
    f->quantidade++;
    printf("\033[32mPacote do tipo %s com peso %.2f inserido na fila com sucesso.\033[0m\n", tipo, peso);
}


Pacote* removerPacote(Fila* f)
{
    // Verificar se a fila é nula ou está vazia
    if (!f || f->inicio == NULL)
    {
        printf("\033[33mAviso: Não há pacotes para remover, a fila está vazia.\033[0m\n");
        return NULL;
    }

    // Remover o primeiro pacote
    Pacote* temp = f->inicio;
    f->inicio = f->inicio->prox;

    // Atualizar o ponteiro do fim se a fila ficar vazia
    if (f->inicio == NULL)
        f->fim = NULL;
    
    // Atualizar a quantidade de elementos na fila
    f->quantidade--;

    // Desconectar o pacote da fila
    temp->prox = NULL;

    // Log de sucesso
    printf("\033[34mPacote do tipo %s com peso %.2f removido da fila.\033[0m\n", temp->tipo, temp->peso);
    return (temp);
}


int validacao_de_dados(Fila *f, char tipo[], float peso)
{
    if (strcmp(tipo, "PA") != 0 && strcmp(tipo, "PB") != 0)
    {
        printf("Erro: Tipo de pacote inválido (%s). Use 'PA' ou 'PB'.\n", tipo);
        return 0;
    }
    else if (peso <= 0)
    {
        printf("Erro: Peso inválido (%.2f). O peso deve ser maior que zero.\n", peso);
        return 0;
    }
    else if (f == NULL)
    {
        printf("Erro: A fila não foi inicializada.\n");
        return 0;
    }
    return 1;
}