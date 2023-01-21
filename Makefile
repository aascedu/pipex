# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aascedu <aascedu@student.42lyon.fr>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/04 13:02:47 by aascedu           #+#    #+#              #
#    Updated: 2023/01/21 17:02:28 by aascedu          ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

NAME = pipex

LIBFT_DIR = ./libft/
LIBFT = ./libft/libft.a

HEADER = pipex.h pipex_bonus.h

SRCS = src/main.c src/utils.c src/cmd.c
SRCS_BONUS = src_bonus/cmd_bonus.c \
			src_bonus/main_bonus.c \
			src_bonus/utils_bonus.c \

OBJS = $(SRCS:.c=.o)
OBJS_BONUS = $(SRCS_BONUS:.c=.o)

CC = cc
CFLAGS =  -I./include -Wall -Werror -Wextra -fsanitize=address -g3
RM = rm -rf

%.o : %.c ./include/$(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

all : lib
	make $(NAME)

$(NAME) : $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(LIBFT) $(OBJS) -o $(NAME)

bonus : lib $(OBJS_BONUS)
	$(CC) $(CFLAGS) $(LIBFT) $(OBJS_BONUS) -o $(NAME)

lib :
	make -C $(LIBFT_DIR)

clean :
	$(RM)
	make clean -C $(LIBFT_DIR)

fclean : clean
	$(RM) $(NAME) $(OBJS) $(OBJS_BONUS)
	make fclean -C $(LIBFT_DIR)

re : fclean
	make all

.PHONY : all lib clean fclean bonus re
