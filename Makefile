# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: arthurascedu <arthurascedu@student.42ly    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/04 13:02:47 by aascedu           #+#    #+#              #
#    Updated: 2023/01/05 18:54:40 by arthurasced      ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

NAME = pipex

LIBFT_DIR = ./libft/
LIBFT = ./libft/libft.a

HEADER = pipex.h

HEADER_BONUS = pipex_bonus.h

SRCS_DIR = ./src/
SRCS = main.c utils.c

SRCS_BONUS_DIR = ./src_bonus/
SRCS_BONUS = main_bonus.c utils_bonus.c

SRCS_FILES = $(addprefix $(SRCS_DIR), $(SRCS))
SRCS_BONUS_FILES = $(addprefix $(SRCS_BONUS_DIR), $(SRCS_BONUS))

OBJS_DIR = ./objects/
OBJS = $(SRCS:.c=.o)
OBJS_FILES = $(addprefix $(OBJS_DIR), $(OBJS))

OBJS_BONUS_DIR = ./objects_bonus/
OBJS_BONUS = $(SRCS_BONUS:.c=.o)
OBJS_BONUS_FILES = $(addprefix $(OBJS_BONUS_DIR), $(OBJS_BONUS))

CC = cc
CFLAGS =  -I./include -Wall -Werror -Wextra -fsanitize=address -g3
RM = rm -rf

all : $(OBJS_DIR) lib
	make $(NAME)

bonus : $(OBJS_BONUS_DIR) $(OBJS_BONUS_FILES) lib
	$(CC) $(CFLAGS) $(LIBFT) $(OBJS_BONUS_FILES) -o $(NAME)

lib :
	make -j -C $(LIBFT_DIR)

$(OBJS_DIR) :
	mkdir $(OBJS_DIR)

$(OBJS_BONUS_DIR) :
	mkdir $(OBJS_BONUS_DIR)

$(OBJS_DIR)%.o : $(SRCS_DIR)%.c ./include/$(HEADER)
	$(CC) $(CFLAGS) -o $@ -c $<

$(OBJS_BONUS_DIR)%.o : $(SRCS_BONUS_DIR)%.c ./include/$(HEADER_BONUS)
	$(CC) $(CFLAGS) -o $@ -c $<

$(NAME) : $(OBJS_FILES) $(LIBFT)
	$(CC) $(CFLAGS) $(LIBFT) $(OBJS_FILES) -o $(NAME)

clean :
	$(RM) $(OBJS_DIR) $(OBJS_BONUS_DIR)
	make clean -C $(LIBFT_DIR)

fclean : clean
	$(RM) $(NAME)
	make fclean -C $(LIBFT_DIR)

re : fclean
	make all

.PHONY : all lib clean fclean bonus re
