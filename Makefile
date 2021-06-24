# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rmartins <rmartins@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/05/13 16:35:42 by rmartins          #+#    #+#              #
#    Updated: 2021/06/24 13:29:49 by rmartins         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo

CC = gcc
CFLAGS = -Wall -Wextra -Werror -g -pthread
OBJ_DIR = obj
SRC_DIR = src
OBJ = $(SRC:%.c=$(OBJ_DIR)/%.o)

HEADER = ft_ansi.h \
	philosophers.h \
	utils.h

SRC = main.c \
	print_error_message.c \
	validate_arguments.c \
	routine.c \
	create_destroy_philosophers.c \
	utils/ft_atoi.c \
	utils/ft_atol.c \
	utils/ft_isdigit.c \
	utils/ft_isnumber.c \
	utils/ft_strlen.c \
	utils/ft_putchar.c \
	utils/ft_putstr.c

all: $(NAME)

$(NAME): $(OBJ)
	@echo $(ANSI_B_BGREEN) "compile executable" $(ANSI_RESET)$(ANSI_F_BBLACK)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)
	@echo $(ANSI_RESET) ""

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(addprefix inc/,$(HEADER))
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -Iinc -c $< -o $@

clean:
	@echo $(ANSI_B_RED) "clean" $(ANSI_RESET)$(ANSI_F_BRED)
	rm -rf $(OBJ_DIR)
	@echo $(ANSI_RESET) ""

fclean: clean
	@echo $(ANSI_B_RED) "fclean" $(ANSI_RESET)$(ANSI_F_BRED)
	rm -f $(NAME)
	rm -f $(NAME_S)
	@echo $(ANSI_RESET) ""

re: fclean all

.PHONY: all clean fclean

# colors
ANSI_RESET = "\033[0m"
ANSI_B_RED = "\033[41m"
ANSI_B_BGREEN = "\033[42;1m"
ANSI_F_BRED = "\033[31;1m"
ANSI_F_BBLACK = "\033[30;1m"


norm:
	@echo $(ANSI_B_RED) "norminette v3" $(ANSI_RESET)
	@norminette $(addprefix inc/,$(HEADER)) \
		$(addprefix src/,$(SRC))

TEST_PARAMETERS = 10000 5 5 5

run: all
	@echo $(ANSI_B_RED) "Running for debbuger without sanitize" $(ANSI_RESET)
	./$(NAME) $(TEST_PARAMETERS)

runv: all
	@echo $(ANSI_B_RED) "Valgrind RESULT" $(ANSI_RESET)
	# valgrind -q --leak-check=full --track-origins=yes --show-leak-kinds=all ./$(NAME)
	# valgrind --leak-check=full --show-leak-kinds=all -s ./$(NAME)
	# valgrind --leak-check=full -s ./$(NAME) 50 5 8 6
	valgrind ./$(NAME) $(TEST_PARAMETERS)

NAME_S = $(NAME)_sanitize
runs: all
	@echo $(ANSI_B_RED) "Running with sanitize" $(ANSI_RESET)
	gcc $(CFLAGS) -fsanitize=address $(OBJ) $(OBJ_COMMON) $(LIBFT) -o $(NAME_S)
	./$(NAME_S) $(TEST_PARAMETERS)