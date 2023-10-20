# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mohafnh <mohafnh@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/13 10:25:10 by mohafnh           #+#    #+#              #
#    Updated: 2023/10/19 14:15:19 by mohafnh          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#COMP
NAME = minishell
CC = gcc -Wall -Werror -Wextra 
EXT_LIBS = -lreadline

SRC =  test3.c   main.c ./bultin/cd.c  ./bultin/echo.c path.c #test.c test2.c

OBJS = ${SRC:.c=.o}
## COLORS ##
END = \033[0m
RED = \033[1;31m
GREEN = \033[1;32m
YELLOW = \033[1;33m
BLUE = \033[1;34m
WHITE = \033[1;37m

## RULES ##
all: libft $(NAME)

libft:
	@echo "$(NAME): $(BLUE)Generating... Just a minute$(RESET)"
	@make -sC ./libft/srcs
	@echo "$(NAME): $(GREEN)Done!$(RESET)"

%.o : %.c 
	@echo "${BLUE} ◎ $(YELLOW)Compiling   ${RED}→   $(WHITE)$< $(END)"
	@$(CC) -c -o $@ $<

$(NAME) : libft $(OBJS)
	@make -sC ./libft/srcs
	@$(CC) -o $(NAME) $(OBJS) -lreadline
	clear
	@echo "$(GREEN)You Created $(NAME)$(END)"


## CLEANNING ##
clean:
	@$(RM) $(OBJS)
	@make clean -sC ./libft/srcs 
	@echo "$(GREEN)$(NAME): $(RED)→ $(BLUE) Cleaning... $(END)"
	@echo "$(GREEN)$(NAME): $(RED)→ $(YELLOW) the files(*.o) were deleted $(END)"

## REMOVING .O FILES AND .A FILES ##
fclean: clean
	$(RM) $(NAME) $(OBJS) $(libft)
	@make fclean -sC ./libft/srcs
	@echo "$(GREEN)$(NAME): $(RED) → $(BLUE)was deleted$(END)"

norm:
	-@norminette  $(SRCS_PATH)
	-@norminette  $(LIBS_PATH)

## REMOVING AND RUNNING ##
re: fclean all

.PHONY: all re clean fclean norm
