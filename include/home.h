/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   home.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmateque <hmateque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 16:20:40 by hmateque          #+#    #+#             */
/*   Updated: 2025/01/17 23:24:35 by hmateque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HOME_H
# define HOME_H

# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <time.h>
# include <unistd.h>

// Definição das constantes
# define MAX_NOME 50
# define PA_GRUPO 6 // Quantidade de pacotes PA por embalagem
# define PB_GRUPO 4 // Quantidade de pacotes PB por embalagem
# define PA_PILHA 4 // Limite de pilhas para PA
# define PB_PILHA 3 // Limite de pilhas para PB

// Estrutura para representar um pacote
typedef struct Pacote
{
	char tipo[3]; // PA ou PB
	float peso;   // peso em ml
	int valido;   // 1 se válido, 0 se inválido
	struct Pacote	*prox;
}					Pacote;

// Estrutura para representar uma fila
typedef struct
{
	Pacote			*inicio;
	Pacote			*fim;
	int				quantidade;
}					Fila;

// Estrutura para representar uma máquina
typedef struct
{
	Fila			*fila_entrada;
	char			*nome;
	char			*tipo;
	int				tempo_processamento;
	int				unidades_processadas;
	int				pacotes_na_maquina;
	int				pilhas_completas;
}					Maquina;

// Funções para manipulação da fila
Maquina* criarMaquina(char nome[], char tipo[], int tempo);

// Funções para manipulação da fila
Fila* criarFila(void);


// Função para enfileirar um pacote em uma fila específica
int enfileirar(Fila* fila, Pacote* pacote);

// Função para enfileirar um pacote de uma fila específica
void inserirPacote(Fila* f, char tipo[], float peso);

// Função para remover um pacote de uma fila específica
Pacote* removerPacote(Fila* f);

// Função para validar produto
void validarProduto(Fila* f, char tipo[]);

// Função para imprimir o menu
void    print_menu(void);

#endif