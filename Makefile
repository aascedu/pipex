# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aascedu <aascedu@student.42lyon.fr>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/04 13:02:47 by aascedu           #+#    #+#              #
#    Updated: 2023/01/25 13:59:19 by aascedu          ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

# EFFECTS
BOLD = $'\x1b[1m
END=$'\x1b[0m
GREEN=$'\x1b[32m

NAME = pipex

BONUS_CHECK = 0

LIBFT_DIR = ./libft
LIBFT = ./libft/libft.a

HEADER = pipex.h pipex_bonus.h

SRCS = src/main.c src/utils.c src/cmd.c src/error.c
SRCS_BONUS = src_bonus/cmd_bonus.c \
			src_bonus/main_bonus.c \
			src_bonus/utils_bonus.c \
			src_bonus/utils2_bonus.c \
			src_bonus/here_doc_bonus.c \
			src_bonus/error_bonus.c \
			src_bonus/pipex_bonus.c

OBJS = $(SRCS:.c=.o)
OBJS_BONUS = $(SRCS_BONUS:.c=.o)

CC = cc
CFLAGS =  -I./include -Wall -Werror -Wextra -fsanitize=address -g3
RM = rm -rf


all : lib
	make $(NAME)

lib :
	make -C $(LIBFT_DIR)

%.o : %.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

bonus :
	@make BONUS_CHECK=1

$(NAME) :
	$(CC) $(CFLAGS) $(LIBFT) $^ -o $@

ifeq ($(BONUS_CHECK), 0)
$(NAME) : $(OBJS)
else
$(NAME) : $(OBJS_BONUS)
endif

clean :
	$(RM)
	@make clean -C $(LIBFT_DIR)

fclean : clean
	$(RM) $(NAME) $(NAME_BONUS) $(OBJS) $(OBJS_BONUS)
	@make fclean -C $(LIBFT_DIR)

re : fclean
	@make all

.PHONY : all lib clean fclean bonus re
