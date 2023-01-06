/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aascedu <aascedu@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 17:57:00 by arthurasced       #+#    #+#             */
/*   Updated: 2023/01/06 16:00:49 by aascedu          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H

# include "../libft/include/libft.h"
# include <unistd.h>
# include <fcntl.h>
# include <sys/wait.h>
# include <stdlib.h>
# include <errno.h>
# include <string.h>

// utils_bonus.c functions
void	free_tab(char **tab);
void	wrong_arg(int error);
int		my_open(int argc, char **argv, int type);
char	*find_path(char **envp);
char	*get_path(char *cmd, char **envp);

// main_bonus.c functions
void	do_cmd(char *cmd, char **envp);
void	get_input(char **argv, int *p_fd);
void	here_doc(char **argv);
void	multiple_pipe(char *cmd, char **envp);

// error.c functions
void	error_display(void);

#endif
