# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aascedu <aascedu@student.42lyon.fr>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/08 15:12:19 by aascedu           #+#    #+#              #
#    Updated: 2023/01/16 08:38:40 by aascedu          ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

# EFFECTS
BOLD = $'\x1b[1m
END=$'\x1b[0m
GREEN=$'\x1b[32m

SRC_DIR = ./src/

SRCS =  ft_strlen.c ft_bzero.c ft_strncmp.c ft_calloc.c ft_substr.c \
		ft_strjoin.c ft_split.c ft_putstr_fd.c ft_putendl_fd.c \

SRCS_PREFIX = $(addprefix $(SRC_DIR), $(SRCS))

HEADER = ./include/libft.h


OBJS = $(SRCS:.c=.o)
OBJS_DIR = objects/

CC = @cc
RM = @rm -rf
CFLAGS = -Wall -Werror -Wextra -I./include/
AR = @ar
ARFLAGS = rcs

NAME = libft.a

all: $(OBJS_DIR)
	@make $(NAME)

$(OBJS_DIR) :
	@mkdir $(OBJS_DIR)

$(OBJS_DIR)%.o : $(SRC_DIR)%.c $(HEADER)
	$(CC) $(CFLAGS) -o $@ -c $<
	@echo "$(BOLD)libft/$<$(END) $(GREEN)compiled !$(END)"

$(NAME): $(addprefix $(OBJS_DIR), $(OBJS))
	$(AR) $(ARFLAGS) $(NAME) $(addprefix $(OBJS_DIR), $(OBJS))
	@echo "$(BOLD)$(NAME)$(END) $(GREEN)has been created !$(END)"

clean:
	$(RM) $(OBJS_DIR)
	@echo "Every $(BOLD).o$(END) files and $(BOLD)objects$(END) folder have been $(GREEN)removed !$(END)"

fclean: clean
	$(RM) $(NAME)
	@echo "$(BOLD)libft.a$(END) has been $(GREEN)deleted !$(END)"

re: fclean
	@make all

.PHONY: all clean fclean re
