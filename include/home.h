/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   home.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmateque <hmateque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 16:20:40 by hmateque          #+#    #+#             */
/*   Updated: 2025/01/20 11:32:48 by hmateque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HOME_H
# define HOME_H

# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <time.h>
# include <unistd.h>

// // Definição das constantes
# define LIMITE_PA 6 // Limite de pacotes para PA
# define LIMITE_PB 4 // Limite de pacotes para PB
# define MAX_PILHAS 10  // Máximo de pilhas permitidas
# define ALTURA_PILHA_PA 3  // Altura máxima da pilha para PA
# define ALTURA_PILHA_PB 2  // Altura máxima da pilha para PB


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

// Estrutura para armazenar estatísticas de validação
typedef struct 
{
    int				total_validados;
    int				total_removidos;
    float			prejuizo_total;
}					EstatisticasValidacao;

// Estrutura para representar uma pilha de embalagens
typedef struct
{
    int				quantidade_embalagens;
    int				capacidade_maxima;
}					Pilha;

// Estrutura para gerenciar múltiplas pilhas
typedef struct
{
    Pilha			pilhas[MAX_PILHAS];
    int				numero_pilhas;
    char			tipo[3];
}					GerenciadorPilhas;



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
int peso_valido(const char* tipo, float peso);
float calcular_prejuizo(const char* tipo, float peso);

// Função para encaminhar pacote
int maquina_atingiu_limite(Maquina* maquina, const char* tipo);
int obter_limite_pacotes(const char* tipo);
void encaminharPacote(Fila* fila_embalamento, Maquina* maquina, const char* tipo);


// Função para imprimir relatório de validação
void imprimir_relatorio_validacao(const EstatisticasValidacao* stats, const char* tipo);

// Função para imprimir o menu
void    print_menu(void);

// Função para printar status das pilhas
void mostrar_status_pilhas(GerenciadorPilhas* gerenciador);

// Funções auxiliares para o caso 1
void processar_modo_automatico(Fila *fila_enchimento_PA, Fila *fila_enchimento_PB);
void processar_modo_manual(Fila *fila_enchimento_PA, Fila *fila_enchimento_PB);
void processar_insercao_pacotes(Fila *fila_enchimento_PA, Fila *fila_enchimento_PB);

// Funções auxiliares para o caso 2
void	processar_enchimento(Maquina *maquina_enchimento_PA,
		Maquina *maquina_enchimento_PB, Fila *fila_enchimento_PA,
		Fila *fila_enchimento_PB, Fila *fila_embalamento_PA,
		Fila *fila_embalamento_PB);

// Funções auxiliares para o caso 3
void processar_validacao_produtos(Fila* fila_embalamento_PA, Fila* fila_embalamento_PB);

// Funções auxiliares para o caso 4
void	processar_encaminhamento(Fila *fila_embalamento_PA,
		Fila *fila_embalamento_PB, Maquina *maquina_embalamento_PA,
		Maquina *maquina_embalamento_PB);

// Função para processar embalamento e empilhamento
void	processar_embalamento(Maquina *maquina_embalamento_PA,
		Maquina *maquina_embalamento_PB, GerenciadorPilhas *gerenciador_PA,
		GerenciadorPilhas *gerenciador_PB);

// Função para embalar e empilhar pacotes
void embalarEEmpilhar(Maquina* maquina, GerenciadorPilhas* gerenciador);

// Função para criar nova pilha
void criar_nova_pilha(GerenciadorPilhas* gerenciador);

// Função para verificar se é possível criar nova pilha
int pode_criar_nova_pilha(GerenciadorPilhas* gerenciador);

// Função para obter a altura máxima da pilha por tipo
int obter_altura_maxima_pilha(const char* tipo);

// Função para criar novo gerenciador de pilhas
GerenciadorPilhas* criar_gerenciador_pilhas(const char* tipo);

// Função principal para imprimir todas as informações
void imprimir_informacoes(
    Fila* fila_enchimento_PA, Fila* fila_enchimento_PB,
    Fila* fila_embalamento_PA, Fila* fila_embalamento_PB,
    Maquina* maquina_enchimento_PA, Maquina* maquina_enchimento_PB,
    Maquina* maquina_embalamento_PA, Maquina* maquina_embalamento_PB,
    GerenciadorPilhas* gerenciador_PA, GerenciadorPilhas* gerenciador_PB
);

// Função para imprimir uma fila específica
void imprimir_fila(Fila* fila, const char* nome_fila, const char* tipo);

// Função para imprimir status de uma máquina
void imprimir_status_maquina(Maquina* maquina);

// Função para imprimir status detalhado das pilhas
void imprimir_status_detalhado_pilhas(GerenciadorPilhas* gerenciador);

#endif