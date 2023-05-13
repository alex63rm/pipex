# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alex <alex@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/13 13:20:31 by alejarod          #+#    #+#              #
#    Updated: 2023/05/13 21:56:40 by alex             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Variables
NAME = pipex
CC = gcc
CFLAGS = -Wall -Werror -Wextra
SANITIZE = -g3 -fsanitize=address
VALGRIND = -g
RM = rm
AR = ar rcs

# Colors (ANSI escape sequence)
GREEN = '\033[32m'
RED = '\033[31m'
RESET_BLACK = '\033[0m'

# External Paths and libraries
LIBFT_PATH = ./libft
LIBFT_A = $(LIBFT_PATH)/libft.a

# Project sources and objects
SRCS_PATH = ./srcs
SRCS = main.c utils.c free_error.c
HEADER = $(SRCS_PATH)/pipex.h

OBJS_PATH = ./objs
OBJS = $(addprefix $(OBJS_PATH)/, $(SRCS:.c=.o))

#Object rule and move them to the object folder
$(OBJS_PATH)/%.o: $(SRCS_PATH)/%.c | $(OBJS_PATH)
	$(CC) $(CFLAGS) -c $^ -o $@

# rules
all: $(NAME)

$(NAME): $(OBJS)
	@echo $(GREEN)"compiling libft!"$(RESET_BLACK)
	make -C $(LIBFT_PATH)
	@echo $(GREEN)"libft compiled!"$(RESET_BLACK)
	$(CC) $^ $(LIBFT_A) -o $@
	@echo $(GREEN)"pipex compiled !"$(RESET_BLACK)

#create the object directory
$(OBJS_PATH):
	mkdir $@

sanitize:

valgrind:

normi:
	norminette $(SRCS_PATH)/*.c $(HEADER)

# removes the .o files
clean:
	@$(RM) -rf $(OBJS_PATH)
	make -C $(LIBFT_PATH) clean
	@echo $(RED)"OBJS DELETED !"$(RESET_BLACK)

# removes .o files & push_swap executable
fclean: clean
	@$(RM) $(NAME)
	make -C $(LIBFT_PATH) fclean
	@echo $(RED)"pipex deleted !"$(RESET_BLACK)

re: fclean all

.PHONY: all sanitize clean fclean re