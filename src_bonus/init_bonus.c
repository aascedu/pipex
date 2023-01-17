/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aascedu <aascedu@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 14:43:06 by aascedu           #+#    #+#             */
/*   Updated: 2023/01/17 15:12:18 by aascedu          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	init_data(t_pipex *data, int argc, char **argv, char **envp)
{
	data->ac = argc;
	data->av = argv;
	data->envp = envp;
}

void	init_pipes(t_pipex *data)
{
	int	i;

	i = 0;
	while (i < data->size)
	{
		if (pipe(data->p_fd[i]) == -1)
		{
			close_fd(data);
			free_fd(data->p_fd, data->size);
			exit(1);
		}
	}
}
