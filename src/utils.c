/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aascedu <aascedu@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 08:36:06 by aascedu           #+#    #+#             */
/*   Updated: 2023/01/26 12:52:59 by aascedu          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	free_tab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

void	init_data(t_pipex *data, int argc, char **argv, char **envp)
{
	data->ac = argc;
	data->av = argv;
	data->envp = envp;
	data->stdin_fd = dup(0);
	data->stdout_fd = dup(1);
}

void	restore_std(t_pipex *data)
{
	close(STDIN_FILENO);
	close(STDOUT_FILENO);
	dup2(data->stdin_fd, STDIN_FILENO);
	dup2(data->stdout_fd, STDOUT_FILENO);
}

void	my_open(t_pipex *data, char *rule)
{
	if (ft_strncmp(rule, "OPEN", 4) == 0)
	{
		data->fd_entry = open(data->av[1], O_RDONLY);
		data->i = 1;
		if (data->fd_entry < 0)
			open_error(data->av[1]);
	}
	else if (ft_strncmp(rule, "CLOSE", 5) == 0)
	{
		data->fd_exit = open(data->av[data->ac - 1], \
		O_RDWR | O_TRUNC | O_CREAT, 0644);
		if (data->fd_exit < 0)
			open_error(data->av[data->ac - 1]);
	}
}
