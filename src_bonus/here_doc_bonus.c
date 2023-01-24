/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aascedu <aascedu@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 10:20:30 by aascedu           #+#    #+#             */
/*   Updated: 2023/01/24 16:21:30 by aascedu          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	here_doc_input(t_pipex *data, int *p_end)
{
	char	*str;

	while (1)
	{
		ft_putstr_fd("here_doc>", 1);
		str = get_next_line(STDIN_FILENO);
		if (!str)
			exit(0);
		if (ft_strncmp(str, data->av[2], ft_strlen(str) - 1) == 0)
		{
			free(str);
			exit(0);
		}
		write(p_end[1], str, ft_strlen(str));
		free(str);
	}
}

void	here_doc(t_pipex *data)
{
	int		p_end[2];
	pid_t	read_proc;

	if (pipe(p_end) == -1)
		exit(1);
	read_proc = fork();
	if (read_proc == -1)
		exit(1);
	else if (!read_proc)
		here_doc_input(data, p_end);
	else
	{
		close(p_end[1]);
		dup2(p_end[0], STDIN_FILENO);
		wait(NULL);
	}
}

void	set_pipe_here_doc(t_pipex *data)
{
	if (data->i == index_first_cmd(data))
	{
		dup2(data->p_end2[0], STDIN_FILENO);
		dup2(data->p_end1[1], STDOUT_FILENO);
	}
	else if (data->i == data->ac - 2)
	{
		if (data->i % 2 == 0)
			dup2(data->p_end2[0], STDIN_FILENO);
		else
			dup2(data->p_end1[0], STDIN_FILENO);
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

void	pipex_here_doc(t_pipex *data)
{
	pid_t	pid;

	while (++data->i < data->ac - 1)
	{
		if (data->i >= 4)
			reset_pipe(data);
		pid = fork();
		if (pid == -1)
			exit(0);
		if (!pid)
		{
			set_pipe_here_doc(data);
			my_close(data);
			do_cmd(data);
		}
	}
}
