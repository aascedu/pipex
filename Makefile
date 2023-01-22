# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aascedu <aascedu@student.42lyon.fr>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/04 13:02:47 by aascedu           #+#    #+#              #
#    Updated: 2023/01/22 13:49:44 by aascedu          ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

# EFFECTS
BOLD = $'\x1b[1m
END=$'\x1b[0m
GREEN=$'\x1b[32m

NAME = pipex
NAME_BONUS = pipex_bonus

LIBFT_DIR = ./libft/
LIBFT = ./libft/libft.a

HEADER = pipex.h pipex_bonus.h

SRCS = src/main.c src/utils.c src/cmd.c
SRCS_BONUS = src_bonus/cmd_bonus.c \
			src_bonus/main_bonus.c \
			src_bonus/utils_bonus.c \
			src_bonus/here_doc_bonus.c \

OBJS = $(SRCS:.c=.o)
OBJS_BONUS = $(SRCS_BONUS:.c=.o)

CC = @cc
CFLAGS =  -I./include -Wall -Werror -Wextra -fsanitize=address -g3
RM = @rm -rf

%.o : %.c $(HEADER)
	@echo "$(BOLD)$<ddd$(END) $(GREEN)compiled !$(END)"
	$(CC) $(CFLAGS) -c $< -o $@

all : lib
	@make $(NAME)

bonus : lib
	@make $(NAME_BONUS)

$(NAME) : $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(LIBFT) $(OBJS) -o $(NAME)
	@echo "$(BOLD)$(NAME)$(END) $(GREEN)has been created !$(END)"

$(NAME_BONUS) : $(OBJS_BONUS) $(LIBFT)
	$(CC) $(CFLAGS) $(LIBFT) $(OBJS_BONUS) -o $(NAME_BONUS)
	@echo "$(BOLD)$(NAME_BONUS)$(END) $(GREEN)has been created !$(END)"

lib :
	@make -C $(LIBFT_DIR)

clean :
	$(RM)
	@make clean -C $(LIBFT_DIR)
	@echo "Every $(BOLD).o$(END) files and $(BOLD)objects$(END) folder have been $(GREEN)removed !$(END)"

fclean : clean
	$(RM) $(NAME) $(NAME_BONUS) $(OBJS) $(OBJS_BONUS)
	@make fclean -C $(LIBFT_DIR)
	@echo "$(BOLD)pipex & pipex_bonus$(END) has been $(GREEN)deleted !$(END)"

re : fclean
	@make all

.PHONY : all lib clean fclean bonus re
