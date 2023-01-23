/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aascedu <aascedu@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 17:57:00 by arthurasced       #+#    #+#             */
/*   Updated: 2023/01/23 16:02:25 by aascedu          ###   ########lyon.fr   */
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
	int		stdout_fd;
	int		stdin_fd;
}		t_pipex;

// main_bonus.c functions
void	pipex(t_pipex *data);

// utils_bonus.c functions
void	free_tab(char **tab);
void	init_data(t_pipex *data, int argc, char **argv, char **envp);
void	restore_std(t_pipex *data);
void	my_open(t_pipex *data, char *rule);
void	set_pipe(t_pipex *data, int *p_end);

// utils2_bonus.c
int	index_first_cmd(t_pipex *data);

// cmd_bonus.c functions
char	*find_path(char **envp);
char	*get_path(t_pipex *data, char *cmd);
void	do_cmd(t_pipex *data);

// here_doc_bonus.c functions
void	here_doc(t_pipex *data);
void	here_doc_input(t_pipex *data, int *p_end);

// error_bonus.c functions
void	wrong_arg(char *error);
void	open_error(char *str);


#endif
