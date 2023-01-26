/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aascedu <aascedu@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 13:51:40 by aascedu           #+#    #+#             */
/*   Updated: 2023/01/26 14:59:48 by aascedu          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	pipex(t_pipex *data)
{
	pid_t	pid;

	my_open(data, "OPEN");
	my_open(data, "CLOSE");
	init_pipes(data);
	while (++data->i < data->ac - 1)
	{
		if (data->i >= 3)
			reset_pipe(data);
		pid = fork();
		if (pid == -1)
			exit(0);
		if (!pid)
		{
			if (data->i == 2 && data->fd_entry < 0)
				exit(1);
			if (data->i == data->ac - 2 && data->fd_exit < 0)
				exit(1);
			set_pipe(data);
			my_close(data);
			do_cmd(data);
		}
	}
}
