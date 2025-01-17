# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hmateque <hmateque@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/16 16:25:17 by hmateque          #+#    #+#              #
#    Updated: 2025/01/17 23:35:57 by hmateque         ###   ########.fr        #
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
		src/main_function_aux/print_menu.c \
		
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
