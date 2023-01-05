/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arthurascedu <arthurascedu@student.42ly    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 17:57:00 by arthurasced       #+#    #+#             */
/*   Updated: 2023/01/05 18:32:03 by arthurasced      ###   ########lyon.fr   */
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

char	*find_path(char **envp);
char	*get_path(char *cmd, char **envp);

void	child_process(char **argv, char **envp, int *p_end);
void	do_cmd(char *cmd, char **envp);
void	free_tab(char **tab);
void	parent_process(char **argv, char **envp, int *p_end);
void	wrong_arg(void);

#endif
