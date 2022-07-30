# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: arthur <arthur@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/23 14:36:37 by apigeon           #+#    #+#              #
#    Updated: 2022/07/30 17:47:41 by apigeon          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

### COMPILATION ###
CC		= cc
CFLAGS	= #-Wall -Werror -Wextra -g3
LFLAGS	= -L$(LIBFT_DIR)
LINKS	= -lft

### EXECUTABLE ###
NAME	= push_swap
B_NAME	= checker_tmp
ARGS2	= 2 3 6 9 1 5 4 8 7
ARGS	= -2 1 2 3 4 5 6 7 8 9

### INCLUDES ###
SRC_DIR		= src
OBJ_DIR		= bin
HEADER		= incl
LIBFT_DIR	= libft
LIBFT		= $(LIBFT_DIR)/libft.a

### SOURCE FILES ###
SRCS	= 	main.c \
			parse.c \
			utils.c \
			operations.c \
			operations_a.c \
			operations_b.c \
			operations_both.c \
			stack_operations.c \

B_SRCS	=	checker.c \
			parse.c \
			utils.c \
			operations.c \
			operations_a.c \
			operations_b.c \
			operations_both.c \
			stack_operations.c \

### HEADER FILES ###
HEADERS		=	$(addprefix $(HEADER)/, push_swap.h)
B_HEADERS	=	$(addprefix $(HEADER)/, push_swap.h push_swap_bonus.h)

### OBJECTS ###
OBJS	= $(addprefix $(OBJ_DIR)/, $(SRCS:.c=.o))
B_OBJS	= $(addprefix $(OBJ_DIR)/, $(B_SRCS:.c=.o))

### COLORS ###
RESET	= \033[0m
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
	@echo "$(NAME): $(BLUE)Compiling libs$(RESET)"
	@make addon -C $(LIBFT_DIR)

$(NAME):	$(LIBFT) $(OBJ_DIR) $(OBJS)
	@$(CC) $(CFLAGS) $(LFLAGS) $(OBJS) $(LINKS) -o $(NAME)
	@echo "$(NAME): $(BLUE)Creating program file -> $(WHITE)$@... $(GREEN)[Done]$(RESET)"
	@echo "$(NAME): $(GREEN)Project successfully compiled$(RESET)"

bonus:		$(B_HEADERS) $(NAME) $(B_OBJS)
	@$(CC) $(CFLAGS) $(LFLAGS) $(B_OBJS) $(LINKS) -o $(B_NAME)
	@echo "$(NAME): $(BLUE)Creating program file -> $(WHITE)$(B_NAME)... $(GREEN)[Done]$(RESET)"
	@echo "$(NAME): $(GREEN)Checker successfully compiled$(RESET)"

$(OBJ_DIR)/%.o : $(SRC_DIR)/%.c $(HEADERS)
	@$(CC) $(CFLAGS) -I$(HEADER) -I$(LIBFT_DIR)/$(HEADER) -c $< -o $@
	@echo "$(NAME): $(BLUE)Creating object file -> $(WHITE)$(notdir $@)... $(GREEN)[Done]$(RESET)"

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

run: $(NAME)
	./$(NAME) $(ARGS)

val: $(NAME)
	valgrind ./$(NAME) $(ARGS)

clean:
	@make clean -C $(LIBFT_DIR)
	@echo "$(NAME): $(RED)Supressing object files$(RESET)"
	@rm -rf $(OBJ_DIR)

fclean:	clean
	@make fclean -C $(LIBFT_DIR)
	@echo "$(NAME): $(RED)Supressing program files$(RESET)"
	@rm -f $(NAME)

re:		fclean all

.PHONY:	all clean fclean re
