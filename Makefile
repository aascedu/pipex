# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aascedu <aascedu@student.42lyon.fr>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/04 13:02:47 by aascedu           #+#    #+#              #
#    Updated: 2023/01/26 15:22:11 by aascedu          ###   ########lyon.fr    #
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
LIBFT_HDR = ./libft/include/libft.h

HEADER = include/pipex.h include/pipex_bonus.h

SRCS = src/main.c src/utils.c src/utils2.c src/cmd.c src/error.c src/pipex.c

SRCS_BONUS = src_bonus/cmd_bonus.c \
			src_bonus/main_bonus.c \
			src_bonus/utils_bonus.c \
			src_bonus/utils2_bonus.c \
			src_bonus/error_bonus.c \
			src_bonus/pipex_bonus.c

OBJS = $(SRCS:.c=.o)
OBJS_BONUS = $(SRCS_BONUS:.c=.o)

CC = cc
CFLAGS =  -I./include -Wall -Werror -Wextra -fsanitize=address -g3
RM = rm -rf

%.o : %.c $(HEADER) $(LIBFT_HDR)
	$(CC) $(CFLAGS) -c $< -o $@

all : lib
	make $(NAME)

lib :
	make -C $(LIBFT_DIR)

bonus :
	@make BONUS_CHECK=1

ifeq ($(BONUS_CHECK), 0)
FILE = $(OBJS)
else
FILE = $(OBJS_BONUS)
endif

$(NAME) : $(FILE) $(LIBFT) $(HEADER) $(LIBFT_HDR)
	$(CC) $(CFLAGS) $(LIBFT) $(FILE) -o $(NAME)

clean :
	$(RM) $(OBJS) $(OBJS_BONUS)
	@make clean -C $(LIBFT_DIR)

fclean : clean
	$(RM) $(NAME) $(NAME_BONUS)
	@make fclean -C $(LIBFT_DIR)

re : fclean
	@make all

.PHONY : all lib clean fclean bonus re
