# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: arthur <arthur@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/23 14:36:37 by apigeon           #+#    #+#              #
#    Updated: 2022/05/23 10:20:19 by arthur           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

### COMPILATION ###
CC		= cc
CFLAG	= -Wall -Werror -Wextra
DFLAG	= -L$(LIBFT_DIR) -lft

### EXECUTABLE ###
NAME	= push_swap

### INCLUDES ###
SRC_DIR		= src
OBJ_DIR		= bin
HEADER		= incl
LIBFT_DIR	= libft
LIBFT		= $(LIBFT_DIR)/libft.a

### SOURCE FILES ###
SRCS	= 	main.c \
			parse.c \
			operations.c \
			operations_a.c \
			operations_b.c \
			operations_both.c \
			stack_operations.c \

### OBJECTS ###
OBJS	= $(addprefix $(OBJ_DIR)/, $(SRCS:.c=.o))

### COLORS ###
NOC		= \033[0m
BLACK	= \033[1;30m
RED		= \033[1;31m
GREEN	= \033[1;32m
YELLOW	= \033[1;33m
BLUE	= \033[1;34m
PURPLE	= \033[1;35m
CYAN	= \033[1;36m
WHITE	= \033[1;37m

### RULES ###
all:	$(NAME)

$(LIBFT):
	@make -C $(LIBFT_DIR)

$(NAME):	$(LIBFT) $(OBJ_DIR) $(OBJS)
	@$(CC) $(CFLAGS) $(DFLAGS) $(OBJS) -o $(NAME)
	@echo "$(BLUE)Creating program file -> $(WHITE)$@... $(GREEN)[Done]$(NOC)"
	@echo "$(GREEN)Project successfully compiled$(NOC)"

$(OBJ_DIR)/%.o : $(SRC_DIR)/%.c
	@$(CC) $(CFLAGS) -I$(HEADER) -I$(LIBFT_DIR) -c $< -o $@
	@echo "$(BLUE)Creating object file -> $(WHITE)$(notdir $@)... $(GREEN)[Done]$(NOC)"

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

clean:
	@echo "$(RED)Supressing object files$(NOC)"
	@rm -rf $(OBJ_DIR)

fclean:	clean
	@echo "$(RED)Supressing program files$(NOC)"
	@rm -f $(NAME)

re:		fclean all

.PHONY:	all clean fclean re
