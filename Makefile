# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alejarod <alejarod@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/13 13:20:31 by alejarod          #+#    #+#              #
#    Updated: 2023/06/14 20:32:46 by alejarod         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Variables
NAME = pipex
CC = gcc
CFLAGS = -Wall -Werror -Wextra -g3 -fsanitize=address
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
SRCS = main.c utils.c free_error.c fork.c
HEADER = $(SRCS_PATH)/pipex.h

OBJS_PATH = ./objs
OBJS = $(addprefix $(OBJS_PATH)/, $(SRCS:.c=.o))




# rules
all: $(NAME)

#Object rule and move them to the object folder
$(OBJS_PATH)/%.o: $(SRCS_PATH)/%.c | $(OBJS_PATH)
	$(CC) $(CFLAGS) -c $^ -o $@

$(NAME): libft/libft.a $(OBJS)
	@echo $(GREEN)"compiling libft!"$(RESET_BLACK)
	make -C $(LIBFT_PATH)
	@echo $(GREEN)"libft compiled!"$(RESET_BLACK)
	$(CC) $(CFLAGS) $^ $(LIBFT_A) -o $@
	@echo $(GREEN)"pipex compiled !"$(RESET_BLACK)

#create the object directory
$(OBJS_PATH):
	mkdir $@
	
libft/libft.a:
	make -C $(LIBFT_PATH)

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

re: fclean all $(OBJS_PATH)

.PHONY: all sanitize clean fclean re