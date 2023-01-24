/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aascedu <aascedu@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 08:36:41 by aascedu           #+#    #+#             */
/*   Updated: 2023/01/24 15:56:00 by aascedu          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	init_pipes(t_pipex *data)
{
	if (pipe(data->p_end1) == -1)
		exit(1);
	if (pipe(data->p_end2) == -1)
		exit(1);
}

void	my_close(t_pipex *data)
{
	close(data->p_end1[0]);
	close(data->p_end1[1]);
	close(data->p_end2[0]);
	close(data->p_end2[1]);
	close(data->fd_entry);
	close(data->fd_exit);
}

void	set_pipe(t_pipex *data)
{
	if (data->i == index_first_cmd(data))
	{
		if (ft_strncmp(data->av[1], "here_doc", 9) != 0)
			dup2(data->fd_entry, STDIN_FILENO);
		dup2(data->p_end1[1], STDOUT_FILENO);
	}
	else if (data->i == data->ac - 2)
	{
		if (data->i % 2 != 0)
			dup2(data->p_end1[0], STDIN_FILENO);
		else
			dup2(data->p_end2[0], STDIN_FILENO);
		dup2(data->fd_exit, STDOUT_FILENO);
	}
	else if (data->i % 2 != 0)
	{
		dup2(data->p_end1[0], STDIN_FILENO);
		dup2(data->p_end2[1], STDOUT_FILENO);
	}
	else
	{
		dup2(data->p_end2[0], STDIN_FILENO);
		dup2(data->p_end1[1], STDOUT_FILENO);
	}
}

void	pipex(t_pipex *data)
{
	pid_t	pid;

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
			set_pipe(data);
			my_close(data);
			do_cmd(data);
		}
	}
}

int	main(int argc, char **argv, char **envp)
{
	t_pipex	data;

	init_data(&data, argc, argv, envp);
	if (data.ac < 5)
		wrong_arg("too_few");
	if (ft_strncmp(data.av[1], "here_doc", 9) == 0)
	{
		if (data.ac > 6)
			wrong_arg("too_many");
		my_open(&data, "DOC");
		here_doc(&data);
		pipex_here_doc(&data);
	}
	else
	{
		my_open(&data, "OPEN");
		my_open(&data, "CLOSE");
		pipex(&data);
	}
	my_close(&data);
	while (data.i-- > 0)
		wait(NULL);
	return (restore_std(&data), 0);
}
