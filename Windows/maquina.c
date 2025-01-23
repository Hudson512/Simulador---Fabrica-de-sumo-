/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maquina.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmateque <hmateque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 17:06:24 by hmateque          #+#    #+#             */
/*   Updated: 2025/01/23 06:33:58 by hmateque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "home.h"

// Função para criar uma máquina
Maquina* criarMaquina(char nome[], char tipo[], int tempo)
{
    // Alocar memória para a máquina
    Maquina* m = (Maquina*)malloc(sizeof(Maquina));
    if (!m)
    {
        printf("\033[31mErro: Falha ao alocar memória para a máquina.\033[0m\n");
        return NULL;
    }

    // Inicializar nome
    m->nome = strdup(nome);
    if (!m->nome)
    {
        printf("\033[31mErro: Falha ao alocar memória para o nome da máquina.\033[0m\n");
        free(m);
        return NULL;
    }

    // Inicializar tipo
    m->tipo = strdup(tipo);
    if (!m->tipo)
    {
        printf("\033[31mErro: Falha ao alocar memória para o tipo da máquina.\033[0m\n");
        free(m->nome);
        free(m);
        return NULL;
    }

    // Inicializar atributos da máquina
    m->tempo_processamento = tempo;
    m->unidades_processadas = 0;
    m->pacotes_na_maquina = 0;
    m->pilhas_completas = 0;

    // Criar fila de entrada
    m->fila_entrada = criarFila();
    if (!m->fila_entrada)
    {
        printf("\033[31mErro: Falha ao criar a fila de entrada da máquina.\033[0m\n");
        free(m->tipo);
        free(m->nome);
        free(m);
        return NULL;
    }
    //printf("\033[32mMáquina '%s' do tipo '%s' criada com sucesso.\033[0m\n", nome, tipo);
    return (m);
}
