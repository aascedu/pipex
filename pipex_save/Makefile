# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aascedu <aascedu@student.42lyon.fr>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
<<<<<<< HEAD
#    Created: 2023/01/16 17:52:17 by arthurasced       #+#    #+#              #
#    Updated: 2023/01/16 17:53:02 by arthurasced      ###   ########lyon.fr    #
=======
#    Created: 2023/01/04 13:02:47 by aascedu           #+#    #+#              #
#    Updated: 2023/01/16 08:34:06 by aascedu          ###   ########lyon.fr    #
>>>>>>> 8373c004ed00b9e6e6633553cb0e35525418316b
#                                                                              #
# **************************************************************************** #

HEADER = pipex.h

SRCS_DIR = ./src/
SRCS = main.c utils.c
SRCS_FILES = $(addprefix $(SRCS_DIR), $(SRCS))

OBJS_DIR = ./objects/
OBJS = $(SRCS:.c=.o)
OBJS_FILES = $(addprefix $(OBJS_DIR), $(OBJS))

CC = cc
CFLAGS =  -I./include -Wall -Werror -Wextra -fsanitize=address -g3
RM = rm -rf

all : $(OBJS_DIR) lib
	make $(NAME)

lib :
	make -C $(LIBFT_DIR)

$(OBJS_DIR) :
	mkdir $(OBJS_DIR)

$(OBJS_BONUS_DIR) :
	mkdir $(OBJS_BONUS_DIR)

$(OBJS_DIR)%.o : $(SRCS_DIR)%.c ./include/$(HEADER)
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

<<<<<<< HEAD
.PHONY : all lib clean fclean bonus re
=======
.PHONY : all lib clean fclean re
>>>>>>> 8373c004ed00b9e6e6633553cb0e35525418316b
