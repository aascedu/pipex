/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aascedu <aascedu@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 13:04:25 by aascedu           #+#    #+#             */
/*   Updated: 2023/01/25 16:51:14 by aascedu          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

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
	int		p_end1[2];
	int		p_end2[2];
	char	**av;
	char	**envp;
	int		stdout_fd;
	int		stdin_fd;
}		t_pipex;

// pipex.c functions
void	pipex(t_pipex *data);

// utils_bonus.c functions
void	free_tab(char **tab);
void	init_data(t_pipex *data, int argc, char **argv, char **envp);
void	restore_std(t_pipex *data);
void	my_open(t_pipex *data, char *rule);
void	set_pipe(t_pipex *data);

// utils2_bonus.c
int		index_first_cmd(t_pipex *data);
void	reset_pipe(t_pipex *data);
void	init_pipes(t_pipex *data);
void	set_pipe(t_pipex *data);
void	my_close(t_pipex *data);

// cmd_bonus.c functions
char	*find_path(char **envp);
char	*get_path(t_pipex *data, char *cmd);
void	do_cmd(t_pipex *data);

// error_bonus.c functions
void	wrong_arg(char *error);
void	open_error(char *str);

#endif
