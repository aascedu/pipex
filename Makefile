# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aascedu <aascedu@student.42lyon.fr>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/04 13:02:47 by aascedu           #+#    #+#              #
#    Updated: 2023/01/26 16:44:19 by aascedu          ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

# EFFECTS
BOLD = $'\x1b[1m
END=$'\x1b[0m
GREEN=$'\x1b[32m
CYAN=$'\x1b[36m
PURPLE=$'\x1b[35m

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

CC = @cc
CFLAGS =  -I./include -Wall -Werror -Wextra -fsanitize=address -g3
RM = @rm -rf

%.o : %.c $(HEADER) $(LIBFT_HDR)
	@echo "$(GREEN)$(BOLD)$<$(END) $(BOLD)compiled !$(END)"
	$(CC) $(CFLAGS) -c $< -o $@

all : lib
	@echo
	@echo "$(CYAN)$(BOLD)--------------------$(END)"
	@echo "$(CYAN)$(BOLD)|$(END) Now making $(CYAN)$(BOLD)pipex$(END) $(CYAN)$(BOLD)|$(END)"
	@echo "$(CYAN)$(BOLD)--------------------$(END)"
	@echo
	@make $(NAME)
	@echo
	@echo "$(BOLD)pipex$(END)$(BOLD)$(GREEN) created$(END) $(BOLD)!$(END) (./pipex infile cmd1 cmd2 outfile or ./pipex infile cmd1 ... cmdn outfile)"
	@echo

lib :
	@make -C $(LIBFT_DIR)

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
	@echo "$(PURPLE)$(BOLD)-----------------$(END)"
	@echo "$(PURPLE)$(BOLD)|$(END) Cleaned $(PURPLE)$(BOLD)pipex |$(END)"
	@echo "$(PURPLE)$(BOLD)-----------------$(END)"

fclean : clean
	$(RM) $(NAME) $(NAME_BONUS)
	@make fclean -C $(LIBFT_DIR)

re : fclean
	@make all

.PHONY : all lib clean fclean bonus re
