# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hmateque <hmateque@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/16 16:25:17 by hmateque          #+#    #+#              #
#    Updated: 2025/01/20 10:28:49 by hmateque         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = simulador
CC = cc
CFLAGS =
SRC =	main.c \
		src/fila.c \
		src/maquina.c \
		src/pacote.c \
		src/produto.c \
		src/encaminhar.c \
		src/embalar.c \
		src/empilhar.c \
		src/main_function_aux/print_menu.c \
		src/main_function_aux/case_1.c \
		src/main_function_aux/case_2.c \
		src/main_function_aux/case_3.c \
		src/main_function_aux/case_4.c \
		src/main_function_aux/case_5.c \
		
OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
