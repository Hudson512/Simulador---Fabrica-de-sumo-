/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_menu.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmateque <hmateque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 23:22:42 by hmateque          #+#    #+#             */
/*   Updated: 2025/01/17 23:40:07 by hmateque         ###   ########.fr       */
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
