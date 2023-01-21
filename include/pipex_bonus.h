/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aascedu <aascedu@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 17:57:00 by arthurasced       #+#    #+#             */
/*   Updated: 2023/01/21 16:59:35 by aascedu          ###   ########lyon.fr   */
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

typedef struct s_pipex
{
	int		i;
	int		fd_entry;
	int		fd_exit;
	int		ac;
	char	**av;
	char	**envp;
}		t_pipex;

// main_bonus.c functions
void	pipex(t_pipex *data);

// utils_bonus.c functions
void	wrong_arg(char *error);
void	free_tab(char **tab);
void	init_data(t_pipex *data, int argc, char **argv, char **envp);
int		my_open(t_pipex *data, char *rule);

// cmd_bonus.c functions
char	*find_path(char **envp);
char	*get_path(t_pipex *data, char *cmd);
void	do_cmd(t_pipex *data);

#endif
