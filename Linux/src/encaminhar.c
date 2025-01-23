/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   encaminhar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmateque <hmateque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 08:58:26 by hmateque          #+#    #+#             */
/*   Updated: 2025/01/20 09:06:18 by hmateque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/home.h"

// Função para verificar se a máquina atingiu o limite
int maquina_atingiu_limite(Maquina* maquina, const char* tipo)
{
    if (strcmp(tipo, "PA") == 0)
        return maquina->pacotes_na_maquina >= LIMITE_PA;
    else if (strcmp(tipo, "PB") == 0)
        return maquina->pacotes_na_maquina >= LIMITE_PB;
    return 1; // Retorna 1 para tipos inválidos
}

// Função para obter o limite de pacotes por tipo
int obter_limite_pacotes(const char* tipo)
{
    if (strcmp(tipo, "PA") == 0)
        return LIMITE_PA;
    else if (strcmp(tipo, "PB") == 0)
        return LIMITE_PB;
    return 0;
}

// Função para encaminhar pacote
void encaminharPacote(Fila* fila_embalamento, Maquina* maquina, const char* tipo)
{
    // Verificar se a fila está vazia
    if (!fila_embalamento || !fila_embalamento->inicio) {
        printf("\033[33mAviso: Não há pacotes na fila de embalamento %s.\033[0m\n", tipo);
        return;
    }

    // Verificar se a máquina atingiu o limite
    if (maquina_atingiu_limite(maquina, tipo)) {
        printf("\033[31mErro: Máquina de embalamento %s já atingiu o limite de %d pacotes.\033[0m\n", 
               tipo, obter_limite_pacotes(tipo));
        return;
    }

    // Remover pacote da fila de embalamento
    Pacote* pacote = removerPacote(fila_embalamento);
    if (!pacote) {
        printf("\033[31mErro: Não foi possível remover o pacote da fila.\033[0m\n");
        return;
    }

    // Verificar se o pacote é do tipo correto
    if (strcmp(pacote->tipo, tipo) != 0) {
        printf("\033[31mErro: Tipo de pacote incorreto. Esperado: %s, Recebido: %s\033[0m\n", 
               tipo, pacote->tipo);
        free(pacote);
        return;
    }

    // Simular tempo de processamento
    printf("\033[32mEncaminhando pacote do tipo %s para máquina de embalamento...\033[0m\n", tipo);
    sleep(maquina->tempo_processamento);

    // Atualizar contadores da máquina
    maquina->unidades_processadas++;
    maquina->pacotes_na_maquina++;

    // Mostrar status atual
    printf("\033[32mPacote encaminhado com sucesso!\033[0m\n");
    printf("Status da máquina %s:\n", maquina->nome);
    printf("- Pacotes na máquina: %d/%d\n", 
           maquina->pacotes_na_maquina, 
           obter_limite_pacotes(tipo));
    printf("- Total de unidades processadas: %d\n", maquina->unidades_processadas);

    free(pacote);
}

