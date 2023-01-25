/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aascedu <aascedu@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 10:20:30 by aascedu           #+#    #+#             */
/*   Updated: 2023/01/25 16:25:02 by aascedu          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	reset_pipe_here_doc(t_pipex *data)
{
	if (data->i % 2 != 0)
	{
		close(data->p_end1[0]);
		close(data->p_end1[1]);
		if (pipe(data->p_end1) == -1)
			exit(1);
	}
	else
	{
		close(data->p_end2[0]);
		close(data->p_end2[1]);
		if (pipe(data->p_end2) == -1)
			exit(1);
	}
}

void	set_pipe_here_doc(t_pipex *data)
{
	if (data->i == index_first_cmd(data))
	{
		dup2(data->fd_entry, STDIN_FILENO);
		dup2(data->p_end1[1], STDOUT_FILENO);
	}
	else if (data->i == data->ac - 2)
	{
		if (data->i % 2 == 0)
			dup2(data->p_end1[0], STDIN_FILENO);
		else
			dup2(data->p_end2[0], STDIN_FILENO);
		dup2(data->fd_exit, STDOUT_FILENO);
	}
	else if (data->i % 2 == 0)
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

void	here_doc_input(t_pipex *data)
{
	char	*str;

	data->fd_entry = open("here_doc", O_CREAT | O_TRUNC | O_WRONLY, 0644);
	if (data->fd_entry == -1)
		perror("open");
	while (1)
	{
		ft_putstr_fd("here_doc>", 1);
		str = get_next_line(STDIN_FILENO);
		if (!str)
			exit(1);
		if (ft_strncmp(str, data->av[2], ft_strlen(str) - 1) == 0)
			break ;
		write(data->p_end1[1], str, ft_strlen(str));
		free(str);
	}
	close(data->fd_entry);
	data->fd_entry = open("here_doc", O_RDONLY);
	if (data->fd_entry == -1)
		unlink("here_doc");
}

void	here_doc(t_pipex *data)
{
	pid_t	read_proc;

	read_proc = fork();
	if (read_proc == -1)
		exit(1);
	else if (!read_proc)
		here_doc_input(data);
	else
		wait(NULL);
}

void	pipex_here_doc(t_pipex *data)
{
	pid_t	pid;

	my_open(data, "DOC");
	init_pipes(data);
	here_doc(data);
	while (++data->i < data->ac - 1)
	{
		if (data->i >= 5)
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
