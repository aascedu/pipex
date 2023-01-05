# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aascedu <aascedu@student.42lyon.fr>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/04 13:02:47 by aascedu           #+#    #+#              #
#    Updated: 2023/01/05 13:29:23 by aascedu          ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

NAME = pipex

LIBFT_DIR = ./libft/
LIBFT = ./libft/libft.a

HEADER = pipex.h

SRCS_DIR = ./src/
SRCS = main.c utils.c

SRCS_FILES = $(addprefix $(SRCS_DIR), $(SRCS))

OBJS_DIR = ./objects/
OBJS = $(SRCS:.c=.o)
OBJS_FILES = $(addprefix $(OBJS_DIR), $(OBJS))

CC = cc
CFLAGS =  -I./include -Wall -Werror -Wextra #-fsanitize=address -g3
RM = rm -rf

all : $(OBJS_DIR) lib
	@echo "\nNow making : pipex\n"
	make $(NAME)

lib :
	make -j -C $(LIBFT_DIR)

$(OBJS_DIR) :
	mkdir $(OBJS_DIR)

$(OBJS_DIR)%.o : $(SRCS_DIR)%.c ./include/$(HEADER)
	$(CC) $(CFLAGS) -o $@ -c $<

$(NAME) : $(OBJS_FILES) $(LIBFT)
	$(CC) $(CFLAGS) $(LIBFT) $(OBJS_FILES) -o $(NAME)

clean :
	$(RM) $(OBJS_DIR)
	make clean -C $(LIBFT_DIR)

fclean : clean
	$(RM) $(NAME)
	make fclean -C $(LIBFT_DIR)

re : fclean
	make all

.PHONY : all lib clean fclean re
