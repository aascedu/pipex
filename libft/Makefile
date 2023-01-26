# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aascedu <aascedu@student.42lyon.fr>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/08 15:12:19 by aascedu           #+#    #+#              #
#    Updated: 2023/01/26 13:00:19 by aascedu          ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

# EFFECTS
BOLD = $'\x1b[1m
END=$'\x1b[0m
GREEN=$'\x1b[32m

SRC_DIR = ./src/

SRCS =  ft_strlen.c ft_bzero.c ft_strncmp.c ft_calloc.c ft_substr.c \
		ft_strjoin.c ft_split.c ft_putstr_fd.c ft_putendl_fd.c \
		get_next_line.c get_next_line_utils.c \

SRCS_PREFIX = $(addprefix $(SRC_DIR), $(SRCS))

HEADER = ./include/libft.h


OBJS = $(SRCS:.c=.o)
OBJS_DIR = objects/

CC = cc
RM = rm -rf
CFLAGS = -Wall -Werror -Wextra -I./include/
AR = ar
ARFLAGS = rcs

NAME = libft.a

all: $(OBJS_DIR)
	@make $(NAME)

$(OBJS_DIR) :
	@mkdir $(OBJS_DIR)

$(OBJS_DIR)%.o : $(SRC_DIR)%.c $(HEADER)
	$(CC) $(CFLAGS) -o $@ -c $<

$(NAME): $(addprefix $(OBJS_DIR), $(OBJS))
	$(AR) $(ARFLAGS) $(NAME) $(addprefix $(OBJS_DIR), $(OBJS))

clean:
	$(RM) $(OBJS_DIR)

fclean: clean
	$(RM) $(NAME)

re: fclean
	@make all

.PHONY: all clean fclean re
