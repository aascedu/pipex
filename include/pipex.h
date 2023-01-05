/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aascedu <aascedu@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 13:04:25 by aascedu           #+#    #+#             */
/*   Updated: 2023/01/05 15:22:46 by aascedu          ###   ########lyon.fr   */
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

char	*find_path(char **envp);
char	*get_path(char *cmd, char **envp);

void	child_process(char **argv, char **envp, int *p_end);
void	do_cmd(char *cmd, char **envp);
void	free_tab(char **tab);
void	parent_process(char **argv, char **envp, int *p_end);
#endif
