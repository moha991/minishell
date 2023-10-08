# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: smagniny <santi.mag777@student.42madrid    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/08 17:58:48 by smagniny          #+#    #+#              #
#    Updated: 2023/10/08 19:01:34 by smagniny         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#COMP
PROJECT = minishell
CC = gcc -Wall -Werror -Wextra #-fsanitize=address -g3
PATH_LIB = ./lib/libft
LIBFT = ./lib/libft/libft.a
EXT_LIBS = -lreadline
SRC = test.c

#carpeta donde se guardaran los objetos .o
OBJ_DIR = obj
OBJ = $(addprefix $(OBJ_DIR)/,$(SRC:%.c=%.o))

# Reset color
Color_Off=\033[0m       # Text Reset
# Regular Colors
Black=\033[0;30m
Red=\033[0;31m
Green=\033[0;32m
Yellow=\033[0;33m
Blue=\033[0;34m
Purple=\033[0;35m
Cyan=\033[0;36m
White=\033[0;37m

.PHONY: all lib clean fclean re

all: $(PROJECT)

$(PROJECT): lib $(OBJ)
	@$(CC) $(OBJ) -o $(PROJECT) $(LIBFT) $(EXT_LIBS)
	@echo "$(Yellow)\tCOMPILATION\n$(Green)$(CC) $(OBJ) -o $(PROJECT) $(LIBFT) $(EXT_LIBS)"

$(OBJ_DIR)/%.o: %.c
	@mkdir -p $(@D)
	@$(CC) -c $< -o $@
	@echo "$(Green)$< -> $@"

lib:
	@make -sC $(PATH_LIB)
	@echo  "$(Yellow)\tLIBFT COMPILED"

freelib:
	@make fclean -sC $(PATH_LIB)
	@echo  "$(Red)Libft Cleaned"

clean:
	@echo "$(Red)\tDeleting objects..."
	rm -rf $(OBJ_DIR)

fclean: clean freelib
	rm -f $(PROJECT)

re: fclean all