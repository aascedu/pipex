/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aascedu <aascedu@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 08:36:41 by aascedu           #+#    #+#             */
/*   Updated: 2023/01/23 16:34:05 by aascedu          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

static void	reset_pipe(t_pipex *pipex, int i)
{
		close(p_end[0]);
		close(pipex->pipe_1[1]);
}

void	pipex(t_pipex *data)
{
	int		p_end[2];
	pid_t	pid;

	if (pipe(p_end) == -1)
		exit(0);
	pid = fork();
	if (pid == -1)
		exit(0);
	if (!pid)
	{
		if (data->i == data->ac - 2)
			dup2(data->fd_exit, STDOUT_FILENO);
		else if (data->i != data->ac - 2)
		{
			dup2(p_end[1], STDOUT_FILENO);
			close(p_end[0]);
			close(p_end[1]);
		}
		do_cmd(data);
	}
	else if (pid && data->i != data->ac - 2)
	{
		dup2(p_end[0], STDIN_FILENO);
		close(p_end[1]);
		close(p_end[0]);
	}
}

int	main(int argc, char **argv, char **envp)
{
	t_pipex	data;

	init_data(&data, argc, argv, envp);
	if (data.ac < 5)
		wrong_arg("too_few");
	if (ft_strncmp(data.av[1], "here_doc", 8) == 0)
	{
		if (data.ac > 6)
			wrong_arg("too_many");
		my_open(&data, "DOC");
		here_doc(&data);
		data.i = 2;
	}
	else
	{
		my_open(&data, "OPEN");
		my_open(&data, "CLOSE");
		dup2(data.fd_entry, STDIN_FILENO);
	}
	while (++data.i < data.ac - 1)
		pipex(&data);
	while (data.i-- > 0)
		wait(NULL);
	return (restore_std(&data), 0);
}
